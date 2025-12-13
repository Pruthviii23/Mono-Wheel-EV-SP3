# 🚀 **SP3 — A Futuristic Mono-Wheel Electric Vehicle (Major Engineering Project)**

*“Because the EV market was getting boring, so we decided to build something mildly insane.”*

---

## 📌 **Overview**

**SP3** is a **full-scale, single-wheel electric vehicle** inspired by futuristic mobility seen in *Alita: Battle Angel*, *Ryno Motors*, and sci-fi games.

Unlike hobby monowheels or toy Onewheel boards, SP3 aims to be a **true everyday commuter EV**, built around:

* A 2000W 17-inch hub motor
* A custom-built 72V Li-ion battery pack
* Self-balancing control using IMU-based PID
* A stainless-steel chassis built from the ground up

This project is ongoing, designed and built entirely by a **team of four AI/ML engineering students** who decided to touch grass and build actual hardware.

---

# 🎯 **Project Goals**

* Build a **unique EV platform** that stands out in the crowded Indian EV landscape
* Learn & apply **mechanical, electrical, embedded, and control systems engineering**
* Create a realistic, commute-ready monowheel EV
* Push ourselves *way* outside our comfort zone
* Suffer, learn, suffer again, and eventually build something awesome

---

# 🛠 **Key Features**

* **2000W BLDC hub motor** with 100/80–17 tyre
* **72V 20s5p Li-ion battery pack** (custom welded & BMS-managed)
* **Self-balancing control** using MPU6500 IMU
* **PID-based tilt control**
* **Arduino + Raspberry Pi control stack**
* Stainless-steel chassis (1-inch tubing)
* Future IP65-rated battery and electronics enclosure
* Planned full digital instrument cluster
* Bluetooth support (planned)

---

# 🧠 **System Architecture**

```
           ┌──────────────────┐
           │     IMU (MPU6500)│
           └───────┬──────────┘
                   │  Tilt Data
                   ▼
            ┌───────────────┐
            │   Arduino R3  │  PID Loop @ ~200Hz
            └───────┬───────┘
                    │ PWM Signal
                    ▼
           ┌──────────────────────┐
           │ Motor Controller     │ 60V/72V/84V
           └───────┬──────────────┘
                   │ 3-Phase Output
                   ▼
           ┌───────────────────┐
           │  2000W Hub Motor  │
           └───────────────────┘
```

*Raspberry Pi 3 planned for future features (UI, telemetry, OTA updates, cluster).*

---

# ⚙️ **Mechanical Design**

* **Wheel:** 17-inch 2000W BLDC hub motor
* **Tyre:** 100/80–17
* **Chassis Material:** 1-inch stainless steel
* **Fabrication:** MIG welding
* **Suspension:** Not yet (future addition)
* **Estimated Vehicle Weight:** ~200 kg
* **CAD:** Designed fully in Tinkercad & Fusion360

📁 **Placeholder:** `images/mechanical-render.png`

---

# 🔋 **Electrical System**

### **Battery Pack**

* **Configuration:** 20s5p
* **Voltage:** 72V nominal, 84V peak
* **Chemistry:** Li-ion (local 3.7V 2800mAh cells)
* **Capacity:** ~1000 Wh
* **BMS:** 20s standard BMS
* **Charger:** 84V 15A
* **Enclosure:** Planned IP65 sealed box with locking lid

### **Motor Controller**

* Local controller rated **1000W**, supports 60/72/84V
* Throttle interface via **DAC Module**
* No CAN/UART telemetry (yet)

📁 **Placeholder:** ``
📁 **Placeholder:** ``

---

# 🧩 **Control System**

### **Sensors**

* **MPU6500 gyro/accelerometer**

### **Algorithms**

* **PID** for tilt stabilization
* **Complementary filter** planned
* **Kalman filter** (future upgrade)

### **Safety Controls**

* Auto-shutoff if tilt angle exceeds safe range
* Planned emergency kill switch
* Planned tilt-back safety (like Onewheel)
* Planned over-temp monitoring

---

# 📦 **Software**

* **Language:** Embedded C / Arduino
* **IDE:** Arduino IDE
* Planned:

  * Custom Pi-based UX
  * Bluetooth interface
  * Real-time telemetry logging

📁 **Placeholder:** ``

---

# 📈 **Current Progress (as of project stage)**

### ✔ Completed

* Purchased and tested 2000W hub motor
* Designed full chassis + mechanical layout
* Fabricated custom 20s5p 72V battery
* BMS + pack testing completed
* IMU + Arduino basic balancing tests done
* Early control tests successful
* Began welding and main structure assembly
* Final chassis welding
* Electronics bay design
* Control tuning
* CAD refinements
* Wiring harness

📁 **Placeholder:** ``

### 🚧 Upcoming

* Full instrument cluster
* Updated control board with Pi
* Improved PID tuning
* Battery monitoring system
* Range improvement (>100 km)
* Full body panels / fairing
* Water-resistant housings

---

# 😵 **Challenges & Struggles**

A brutally honest section because engineers respect honesty:

* Near-zero online documentation for DIY monowheels
* No reliable sources for high-power components
* Tuning a balancing PID while standing next to a 2000W wheel that wants to kill you
* Balancing mechanical, electrical, and control requirements simultaneously
* Budget constraints (student-tier pain)
* Researching obscure tech with no mentors or guides
* The constant feeling of *“This might blow up. Or us.”*

Despite all this, SP3 keeps moving forward.

---

# 🧑‍🤝‍🧑 **Team**

SP3 is proudly built by a team of **4 engineering students**, each contributing equally across:

* Mechanical design
* Welding & fabrication
* Battery engineering
* Control systems
* Electrical integration
* Testing & documentation
  
**Team menbers:**
* **KADARLA SHANMUKHA SIVA RAJA CHARI -https://github.com/yedhava**
* **PRATHEEK B K - https://github.com/Prathikgowda33**
* **PRATHEEK S Y - https://github.com/PratheekShetty007**
* **V Pruthviraj Gowda - https://github.com/Pruthviii23**
  
📁 **Placeholder:** ``

---

# 📚 **Tech Stack**

**Hardware**

* 2000W BLDC hub motor
* 20s5p custom Li-ion battery
* Arduino Uno R3
* Raspberry Pi 3
* MPU6500 IMU
* 12v-5v Buck converter
* MCP4725 DAC Module

**Software Tools**

* Fusion360
* Tinkercad
* Arduino IDE

**Skills Demonstrated**

* CAD design
* Welding & fabrication
* Battery pack design + BMS management
* PID control
* IMU data filtering
* High-power EV system wiring
* Embedded development
* Real-world hardware testing

---

# ⚠️ **Disclaimer**

> **“Attempt this project only if you want to be broke, frustrated, emotionally unstable, physically tired, mentally done, and spiritually empty.”**
> But also if you want to learn more than any classroom could ever teach you.

---

# 🙏 **Acknowledgements**

* **Ryno Motors** — for proving that single-wheeled vehicles can be real
* Open-source EV communities
* Every YouTuber who built dangerous things so we could learn
* Last but not the least, our beloved LLMs. Shoutout to **ChatGPT and Gemini**, you guys were there for us when we needed you the most.
