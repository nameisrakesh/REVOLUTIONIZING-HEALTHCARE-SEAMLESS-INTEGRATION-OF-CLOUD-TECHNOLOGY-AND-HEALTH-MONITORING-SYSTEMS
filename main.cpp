#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include "ThingSpeak.h"

// ---------------- PINS ----------------
#define PULSE_PIN 26
#define BUZZER 16
#define LED 12
#define LDR 34        // MUST be analog pin
#define DHTPIN 22

// ---------------- CONSTANTS ----------------
#define DHTTYPE DHT11
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
DHT dht(DHTPIN, DHTTYPE);

// ---------------- WIFI / THINGSPEAK ----------------
const char* ssid = "Project57";
const char* password = "123456789";

WiFiClient client;
unsigned long channel = 2973031;
const char* apiKey = "RPRTN707E1Z2JL1E";

// ---------------- VARIABLES ----------------
unsigned long lastBeat = 0;
int BPM = 0;
float bodyTemp, roomTemp, humidity;
int lightValue;

// -------------------------------------------------

void setup() {
  Serial.begin(115200);

  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);

  mlx.begin();
  dht.begin();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);

  ThingSpeak.begin(client);
}

// -------------------------------------------------

void loop() {

  // -------- HEART RATE (simple peak timing) --------
  int pulse = analogRead(PULSE_PIN);

  if (pulse > 850 && millis() - lastBeat > 500) {
    BPM = 60000 / (millis() - lastBeat);
    lastBeat = millis();
  }

  // -------- TEMPERATURE --------
  roomTemp = mlx.readAmbientTempC();
  bodyTemp = mlx.readObjectTempC();

  // -------- DHT --------
  humidity = dht.readHumidity();

  if (isnan(humidity)) humidity = 0;

  // -------- LDR --------
  lightValue = analogRead(LDR);

  // -------- OLED DISPLAY --------
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.print("BPM: "); display.println(BPM);
  display.print("Body: "); display.print(bodyTemp); display.println(" C");
  display.print("Room: "); display.print(roomTemp); display.println(" C");
  display.print("Hum : "); display.print(humidity); display.println(" %");
  display.print("Light: "); display.println(lightValue);

  display.display();

  // -------- ALERTS --------
  if (bodyTemp > 38 || BPM > 120 || humidity > 70)
    digitalWrite(BUZZER, HIGH);
  else
    digitalWrite(BUZZER, LOW);

  // -------- THINGSPEAK (single upload) --------
  ThingSpeak.setField(1, BPM);
  ThingSpeak.setField(2, bodyTemp);
  ThingSpeak.setField(3, roomTemp);
  ThingSpeak.setField(4, humidity);
  ThingSpeak.setField(5, lightValue);

  ThingSpeak.writeFields(channel, apiKey);

  delay(15000);   // REQUIRED by ThingSpeak
}
