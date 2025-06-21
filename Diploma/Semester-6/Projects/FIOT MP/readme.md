# 🚗 Arduino-Based RC Car Project Documentation

## 🔧 Project Overview
This project involves designing and implementing a remote-controlled car using an Arduino. The car supports:
- Motor control for movement
- Hazard light system
- Buzzer alerts
- Bluetooth-based remote operation

---

## 🧠 Key Concepts Implemented

### ✅ Simulated Multithreading
- Arduino doesn't support real threads.
- We simulate **concurrent tasks** by:
  - Avoiding `delay()`
  - Using `millis()` for non-blocking timing
  - Separating logic into independent functions
  - Maintaining state using flags

### 🕒 Non-Blocking Code
- `delay()` halts the CPU; instead we use `millis()` to allow continuous execution.
- Enables multiple tasks like blinking LEDs and driving motors **without interference**.

```cpp
if (millis() - prevTime >= interval) {
  ledState = !ledState;
  digitalWrite(ledPin, ledState);
  prevTime = millis();
}
````

### ⚙️ Modular Task Handling

* Each task (e.g., hazard lights, motor control) is written as a **separate function**:

```cpp
void loop() {
  handleHazardLights();
  handleMotor();
  handleBluetoothInput();
  handleBuzzer();
}
```

---

## 🔌 Hardware Components Used

| Component          | Description                             |
| ------------------ | --------------------------------------- |
| Arduino UNO        | Main controller                         |
| L298N Motor Driver | Controls four DC motors (2 to 1 setup*) |
| DC Motors          | For car movement                        |
| LEDs               | For hazard/blinker lights (4W, 2R, 4O)  |
| Buzzer             | Alert system                            |
| HC-05 Bluetooth    | Wireless control                        |
| Power Source       | 18650 Battery x2                        |

- W : White, R : Red, O : Orange
- The 2 to 1 setup I'm using ensures I can control speed of one speed at a time, which is done to implement smooth steering.
 How it works? I've connected 2 motors to one output, which therefore can be controlled using PWM-enabled pins, to set the speed, or output.

---

## 🔲 Pin Configuration

| Component                  | Arduino Pin | Description                                           |
|---------------------------|-------------|-------------------------------------------------------|
| **Motor Control (L298N)** |             |                                                       |
| Left Motor IN1            | A0          | Direction control                                     |
| Left Motor IN2            | A1          | Direction control                                     |
| Right Motor IN3           | A2          | Direction control                                     |
| Right Motor IN4           | A3          | Direction control                                     |
| Left Motor Speed (ENA)    | D6          | PWM for left motors                                   |
| Right Motor Speed (ENB)   | D5          | PWM for right motors                                  |
|                           |             |                                                       |
| **Buzzer**                | D13         | Audio signal (on reverse, alert, etc.)                |
|                           |             |                                                       |
| **Left Side Lights**      |             |                                                       |
| Front Left Light (White)  | D12         | Constant ON white headlight                           |
| Rear Left Light (Red)     | D11         | PWM for brightness control                            |
| Reverse Light Left (White)| D10         | Turns ON while reversing                              |
| Left Blinker (Yellow)     | A4          | ON only when turning left                             |
| Rear Left Blinker         | D4          | Rear side yellow indicator                            |
|                           |             |                                                       |
| **Right Side Lights**     |             |                                                       |
| Front Right Light (White) | D2          | Constant ON white headlight                           |
| Rear Right Light (Red)    | D3          | PWM for brightness control                            |
| Reverse Light Right       | D7          | Turns ON while reversing                              |
| Right Blinker (Yellow)    | D8          | ON only when turning right                            |
| Rear Right Blinker        | D9          | Rear side yellow indicator                            |

---

## 🧪 Example: Hazard Light Logic (Non-blocking)

```cpp
void handleHazardLights() {
  static unsigned long lastBlink = 0;
  static bool isOn = false;

  if (hazardMode && millis() - lastBlink > 500) {
    isOn = !isOn;
    digitalWrite(leftLED, isOn);
    digitalWrite(rightLED, isOn);
    lastBlink = millis();
  }
}
```

---


## 🔒 Limitations & Future Improvements

* Lacks real-time OS/threading (expected on Arduino)
* Can add:
  
  * Obstacle detection
  * Auto-braking using sensors
  * Line-following capability
  * Remote logging via IoT
