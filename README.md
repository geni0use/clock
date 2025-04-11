# Arduino Clock with 4 Servo Motors & Python Serial Sync

This project demonstrates a real-time clock built using an **Arduino** and **4 servo motors**, where each motor represents a digit of the current time (HH:MM). The time is updated every minute using a **Python script** that sends the system time to the Arduino via **serial communication**.

## 🧠 Concept

Each servo motor represents one digit of the 24-hour time format:
- 1st Servo: Tens place of the hour (e.g., `0` in 09:45)
- 2nd Servo: Units place of the hour (e.g., `9` in 09:45)
- 3rd Servo: Tens place of the minute (e.g., `4` in 09:45)
- 4th Servo: Units place of the minute (e.g., `5` in 09:45)

The Python script fetches the system time and sends it over serial to the Arduino every minute. The Arduino then maps each digit to the appropriate servo position.

---

## 🛠️ Hardware Requirements

- 1 x Arduino board (e.g., Uno, Mega, Nano)
- 4 x Servo motors (e.g., SG90 or MG90S)
- External power supply for servos (recommended)
- Jumper wires
- Breadboard or mounting hardware

---

## 🧑‍💻 Software Requirements

- Python 3.x
- `pyserial` library (`pip install pyserial`)
- Arduino IDE

---
