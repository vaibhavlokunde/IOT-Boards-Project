# ♻️ Smart Dustbin using IoT and Machine Learning
##Contributor
Vaibhav Lokunde(22BCT0270),Gyanvi Agarwal(22BCT0380),Satvik Khurana(22BCT0088),Shambhavi Thakur(22BCT0332),Rajni Patel(22BCT0197),Dilshad Sukheswala(22BCT0021)

## 🚀 Overview
The **Smart Dustbin** project integrates **IoT sensors**, **cloud monitoring**, and a **Machine Learning model (ResNet50)** to create an intelligent waste management system.  
It automatically **classifies waste** into categories (e.g., biodegradable, recyclable, non-recyclable) using a **waste segregation ML model**, while **monitoring environmental parameters** such as temperature and humidity inside the bin to track moisture and hygiene levels.

This project demonstrates how **AI + IoT + Cloud** can work together to promote **sustainable waste disposal** and smarter city infrastructure.

---

## 🧠 Key Features
- 🔍 **Waste Segregation using ML (ResNet50)**  
  - Trained on a custom dataset of different waste types.  
  - Automatically classifies captured images into relevant categories.  
  - Built with TensorFlow/Keras and fine-tuned using transfer learning on ResNet50.

- 🌡️ **Environmental Monitoring using IoT**  
  - **ESP32 + DHT22 Sensor** to monitor **temperature and humidity** inside the bin.  
  - Data sent to **Blynk** and **ThingSpeak** dashboards for real-time visualization.  
  - Helps detect **moisture buildup**, which can indicate organic waste decomposition or odor risk.

- 🧾 **LCD Display (Local Feedback System)**  
  - Displays live temperature readings inside the bin.  
  - Two versions implemented:
    1. **Arduino + ThingSpeak + LCD**
    2. **ESP32 + LCD + Blynk/Wokwi Simulation**

- ☁️ **Cloud Integration**
  - IoT data (temperature and humidity) is uploaded to **ThingSpeak Cloud** for live graphing.  
  - **Blynk App** used for real-time monitoring and alerts.

---

## 🧩 System Architecture
```text
        +---------------------------+
        |     Camera / Image Feed   |
        +-------------+-------------+
                      |
               [ML Model - ResNet50]
                      |
              +-------+-------+
              | Waste Category|
              +---------------+
                      |
        +-------------+-------------+
        |                           |
   IoT Sensor Unit           Cloud Dashboard
 (ESP32 + DHT22 + LCD)   (Blynk / ThingSpeak)



⚙️ Hardware Components
Component	Description
ESP32	Microcontroller used for IoT sensing and Wi-Fi connectivity
DHT22 Sensor	Measures temperature and humidity inside the bin
Arduino UNO	Alternate controller for LCD & ThingSpeak integration
16x2 LCD Display	Displays temperature and humidity data locally
Wi-Fi / Blynk App	Sends data to mobile dashboard
Power Supply	5V DC regulated supply
Prototype Circuit (Wokwi)	Used for virtual simulation and testing
🧠 Machine Learning Model Details

Model Used: ResNet50 (pre-trained on ImageNet, fine-tuned for waste classification)

Framework: TensorFlow / Keras

Input: Waste image captured via camera or dataset

Output: Waste category label (e.g., Plastic, Paper, Organic, Metal)

Training Techniques:

Transfer Learning with frozen lower layers

Data Augmentation (rotation, zoom, flip)

Adam optimizer with categorical cross-entropy loss

Accuracy Achieved: ~95% on validation dataset

🌐 IoT & Cloud Integration
🔹 Blynk Dashboard

Displays live temperature and humidity readings.

Visualizes sensor data trends.

Can trigger alerts if humidity exceeds threshold (indicating wet waste).

🔹 ThingSpeak Dashboard

Real-time cloud-based visualization for temperature and humidity.

Graphs and analytics available via public/private API keys.

🔹 Wokwi Simulation

Both ESP32 and Arduino circuits simulated using Wokwi for testing before deployment.

Useful for verifying wiring, sensor readings, and LCD output.


🧰 Software & Tools

Python (TensorFlow/Keras) – for ML model development

Arduino IDE – for ESP32/Arduino programming

Blynk Cloud – for real-time IoT monitoring

ThingSpeak Cloud – for cloud visualization

Wokwi Simulator – for testing circuit designs

MATLAB IoT Analytics (optional) – for ThingSpeak analytics

🧪 Results
Parameter	Description
Waste Classification Accuracy	99%
Temperature Range	25°C – 40°C
Humidity Range	30% – 90% RH
IoT Data Update Interval	10s
Cloud Visualization	Real-time plots and alerts
🧭 Future Scope

Integration of ultrasonic sensors to detect bin fill level.

Add automated lid mechanism using servo motors.

Deploy Edge AI for real-time waste classification on ESP32-CAM.

Improve dataset diversity for better classification accuracy.
