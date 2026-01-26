# **SP3 — A Futuristic Mono-Wheel Electric Vehicle (Major Engineering Project)**

*“Because the EV market was getting boring, so we decided to build something mildly insane.”*

---

## 📌 **Overview**

**SP3** is a **full-scale, single-wheel electric vehicle prototype** inspired by futuristic mobility concepts seen in *Alita: Battle Angel*, *Ryno Motors*, and sci-fi games.

Unlike hobby monowheels or toy Onewheel boards, SP3 is being built as a **serious engineering exploration** into what it takes to design, fabricate, wire, and control a **high-power mono-wheel EV from scratch**.

This project is **not a kit build**.
Every subsystem — mechanical, electrical, battery, and control — is being designed, tested, broken, and rebuilt by hand.

SP3 is developed entirely by a **team of four AI/ML engineering students** who decided that theory alone wasn’t enough — and chose sparks, smoke, and stress instead.

---

## 🎯 **Project Goals**

* Design and build a **unique mono-wheel EV platform**
* Learn **real-world mechanical fabrication** (welding, chassis design)
* Design and assemble a **high-voltage Li-ion battery pack**
* Understand **BLDC motor control and EV electronics**
* Implement **IMU-based control logic**
* Bridge the gap between **AI/ML coursework and physical systems**
* Document everything honestly — mistakes included

This project prioritizes **learning and engineering depth** over polish.

---

## 🛠 **Key Features (Current & Planned)**

### ✅ Implemented / Tested

* **2000W BLDC hub motor** (17-inch)
* **72V (20s5p) custom Li-ion battery pack**
* **DAC-based throttle control** (true analog voltage)
* **IMU-based tilt input (MPU6500)**
* Arduino-based control logic
* High-power EV wiring and testing
* Stainless-steel chassis fabrication (MIG welded)

### 🚧 In Progress / Planned

* True **self-balancing (PID torque control)**
* Controller upgrade (VESC-class)
* Raspberry Pi-based UI & telemetry
* Digital instrument cluster
* Bluetooth diagnostics
* Water-resistant electronics enclosure
* Improved safety systems (tilt-cutoff, redundancy)

---

## 🧠 **System Architecture (Current Stage)**

```
           ┌──────────────────┐
           │   IMU (MPU6500)  │
           └───────┬──────────┘
                   │  Tilt / Accel data
                   ▼
            ┌────────────────┐
            │  Arduino UNO   │
            │  (Logic +     │
            │  filtering)   │
            └───────┬────────┘
                    │  Analog Voltage
                    │  (via DAC)
                    ▼
           ┌──────────────────────┐
           │  Motor Controller    │
           │  (Speed-based)       │
           └───────┬──────────────┘
                   │  3-Phase Output
                   ▼
           ┌───────────────────┐
           │  2000W Hub Motor  │
           └───────────────────┘
```

> ⚠️ **Important:**
> At the current stage, SP3 uses **speed-based control**, not torque-based balancing.
> This means it is **tilt-controlled**, not self-balancing (yet).

---

## ⚙️ **Mechanical Design**

* **Wheel:** 17-inch 2000W BLDC hub motor
* **Tyre:** 100/80-17
* **Chassis Material:** 1-inch stainless-steel tubing
* **Fabrication:** MIG welding
* **Suspension:** Not implemented (future work)
* **Estimated Total Mass:** ~200 kg (vehicle + rider)
* **CAD Tools:** Fusion360, Tinkercad

The chassis was designed with:

* Battery centralization
* Low CG
* Structural rigidity
* Future enclosure mounting points

📁 *Placeholder:* `images/mechanical_render.png`

---

## 🔋 **Electrical System**

### 🔋 Battery Pack

* **Configuration:** 20s5p
* **Nominal Voltage:** 72V
* **Max Voltage:** 84V
* **Chemistry:** Li-ion (3.7V, ~2800 mAh cells)
* **Energy:** ~1000 Wh
* **BMS:** 20s standard BMS
* **Charging:** 84V charger
* **Construction:** Custom spot-welded nickel strips
* **Enclosure:** Planned IP65 sealed box

> Battery design and testing were done manually, including:
>
> * Cell matching
> * BMS validation
> * Load testing
> * Safety checks

---

### ⚡ Motor Controller

* Local EV controller
* Rated **~1000W (tested beyond rating)**
* Supports **60V / 72V / 84V**
* **Analog throttle input**
* Built-in reverse support
* No UART / CAN telemetry

⚠️ This controller **cannot perform torque control** or balancing.

---

## 🧩 **Control System**

### Sensors

* **MPU6500** (6-axis IMU)

### Control Strategy (Current)

* Tilt-based input
* Complementary / low-pass filtering
* DAC-generated throttle voltage
* Deadzones, speed limits, safety caps

### Control Strategy (Planned)

* Sensor fusion (Madgwick / Kalman)
* PID-based **balance control**
* Torque control using VESC
* High-frequency control loops (500–1000 Hz)

---

## 📦 **Software Stack**

* **Language:** Embedded C / Arduino
* **IDE:** Arduino IDE
* **Control Loop Rate:** ~50–200 Hz (current)
* **Planned Upgrade:**

  * ESP32 / STM32 / Teensy
  * Raspberry Pi for UI & telemetry
  * Bluetooth communication
  * Data logging

---

## 📈 **Project Status**

### ✅ Completed

* Hub motor testing
* Battery pack fabrication & testing
* DAC-based throttle integration
* IMU integration & filtering
* Tilt-controlled drive tests
* Chassis design & welding
* High-power wiring & debugging
* Safety testing (many failures, many lessons)

### 🚧 Ongoing / Next

* Controller upgrade (VESC)
* True self-balancing control
* PID tuning (real balancing, not speed mapping)
* Reverse integration (low-speed maneuvering)
* Electronics enclosure
* Instrument cluster
* Weather resistance

---

## 😵 **Challenges & Hard Lessons**

Being honest, because this matters:

* EV systems **do not forgive mistakes**
* One wrong ground = smoked electronics
* PWM ≠ true analog control (DAC fixed this)
* Low-speed motor control is *hard*
* Documentation for DIY monowheels is nearly nonexistent
* PID tuning near a 2000W motor is terrifying
* Real hardware behaves nothing like simulations
* Debugging happens with your heart rate at 120 bpm

---

## 🧑‍🤝‍🧑 **Team**

SP3 is built by **four AI/ML engineering students**, each working hands-on across all domains:

* Mechanical design & welding
* Battery engineering
* Embedded systems
* Control logic
* Testing & documentation

### Team Members

* **KADARLA SHANMUKHA SIVA RAJA CHARI** — [https://github.com/yedhava](https://github.com/yedhava)
* **PRATHEEK B K** — [https://github.com/Prathikgowda33](https://github.com/Prathikgowda33)
* **PRATHEEK S Y** — [https://github.com/PratheekShetty007](https://github.com/PratheekShetty007)
* **V Pruthviraj Gowda** — [https://github.com/Pruthviii23](https://github.com/Pruthviii23)

---

## 🧰 **Tech Stack**

### Hardware

* 2000W BLDC hub motor
* Custom 20s5p Li-ion battery
* Arduino UNO R3
* MPU6500 IMU
* MCP4725 DAC
* Buck converters (12V → 5V)
* High-current EV controller

### Software & Tools

* Arduino IDE
* Fusion360
* Tinkercad
* Multimeter, patience, fear

---

## ⚠️ **Disclaimer**

> **Attempt this project only if you are ready to:**
>
> * Lose money
> * Blow components
> * Learn safety the hard way
> * Question your life choices
> * And still keep building

But also if you want to **learn more than any classroom can teach**.

---

## 🙏 **Acknowledgements**

* **Ryno Motors** — proof that mono-wheel EVs can exist
* Open-source EV & VESC communities
* Every YouTuber who broke things publicly
* And yes — **LLMs** (ChatGPT, Gemini) for being the silent lab partner at 2 AM


