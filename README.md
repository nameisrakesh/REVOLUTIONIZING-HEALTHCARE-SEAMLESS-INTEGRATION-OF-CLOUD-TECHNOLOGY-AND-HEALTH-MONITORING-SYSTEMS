# REVOLUTIONIZING-HEALTHCARE-SEAMLESS-INTEGRATION-OF-CLOUD-TECHNOLOGY-AND-HEALTH-MONITORING-SYSTEMS

Cloud Integrated Health Monitoring System using Raspberry Pi Pico W



## Overview

This project implements an IoT-based healthcare monitoring system that continuously tracks vital health parameters and uploads them to the ThingSpeak cloud platform for remote access and analysis.

The system is built around Raspberry Pi Pico W and integrates multiple biomedical and environmental sensors to monitor body temperature, heart rate, room temperature, humidity, and ambient light. Live readings are displayed locally on an OLED screen while simultaneously being pushed to the cloud for real-time monitoring.

The goal is to provide a low-cost, scalable, and reliable solution for continuous patient monitoring and early anomaly detection.



## Features

- Real-time health monitoring  
- Heart rate measurement using Pulse Sensor  
- Body temperature sensing  
- Room temperature and humidity monitoring  
- Ambient light detection using LDR  
- OLED display for live readings  
- Cloud data upload via ThingSpeak  
- Wi-Fi connectivity using Raspberry Pi Pico W  
- Buzzer alert for abnormal conditions  



## System Components

### Hardware

- Raspberry Pi Pico W (RP2040)
- Pulse Sensor (Heart Rate)
- MAX30205 Body Temperature Sensor
- LM35 Temperature Sensor
- Humidity Sensor
- LDR (Light Dependent Resistor)
- OLED Display (128x64)
- Buzzer
- Power Supply

### Software & Cloud

- Arduino IDE
- Embedded C
- ThingSpeak Cloud Platform
- Wi-Fi Communication



## How It Works

### Health Monitoring
Sensors continuously collect physiological and environmental data. The Pico W processes this data and displays real-time values on the OLED.

### Cloud Integration
Collected data is transmitted over Wi-Fi to ThingSpeak, allowing doctors or caregivers to access patient metrics remotely.

### Alerts
A buzzer is triggered when sensor values cross predefined thresholds, providing immediate local alerts.

### Visualization
ThingSpeak dashboards visualize live and historical health data for analysis and tracking.







## Applications

- Remote patient monitoring
- Smart healthcare systems
- Elderly care
- Wearable medical devices
- IoT-based hospital automation



## Conclusion

This project demonstrates how IoT and cloud computing can revolutionize healthcare by enabling continuous, remote health monitoring. By combining Raspberry Pi Pico W with biomedical sensors and ThingSpeak cloud integration, the system delivers a cost-effective and scalable solution for modern healthcare environments.


## Documentation
[Project Report](https://drive.google.com/file/d/1yS4HCeTizdQp1D22qH9pB-jg3NK8ecMz/view?usp=sharing)



## Contact

Email: bhanavathrakesh12345@gmail.com



