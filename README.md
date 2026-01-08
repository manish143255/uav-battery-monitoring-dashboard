# UAV Battery Monitoring Dashboard

A web-based real-time monitoring system for Li-ion (18650) battery discharge experiments using Arduino and DHT11/DHT22 sensors.

##  Features
- Real-time voltage, humidity, and temperature monitoring
- Adaptive voltage logging (0.01 V resolution)
- Raw data logging every 2 seconds
- Fixed humidity axis for stable visualization
- Automatic battery cutoff alarm at 3.0 V
- CSV export (RAW, Adaptive, Full Session)
- High-quality PNG graph export
- Web Serial API (no external software required)

##  Hardware Required
- Arduino Uno / Nano
- DHT11 or DHT22 Sensor
- Li-ion 18650 Battery
- Voltage divider (R1 ≈ 10kΩ, R2 ≈ 10kΩ)
- Breadboard & wires

##  Software Required
- Google Chrome (Web Serial API supported)
- Arduino IDE

##  How to Run

### 1. Arduino Setup
- Open Arduino IDE
- Upload the provided Arduino sketch
- Connect DHT sensor and voltage divider properly

### 2. Web Dashboard
- Open `index.html` in **Google Chrome**
- Click **Connect**
- Select Arduino COM port
- Start logging using Low RH / High RH buttons

## Preview
![UAV Battery Monitoring Dashboard](docs/dashboard.png)

##  Safety
- Automatic alarm triggers below 3.0 V
- Logging stops to prevent deep discharge

##  Data Output
- Adaptive CSV (filtered voltage points)
- RAW CSV (2-second interval)
- Full session CSV
- PNG graph export

##  License
MIT License

##  Author
Manish Kumar
