# Gesture-Controlled Smart Home Automation  
*Using Arduino UNO and APDS-9960 Optical Sensor*

## Overview
This project enables **contactless control** of home appliances (like a bulb and a fan) using **hand gestures**. Utilizing an **APDS-9960** optical sensor connected to an **Arduino Uno**, the system detects gestures and activates corresponding relays to switch appliances ON or OFF.  
This solution enhances **home automation** with intuitive, touch-free interaction.

## Hardware Components
- **Arduino UNO R3**  
- **APDS-9960** Gesture Sensor  
- **16x2 LCD Display**  
- **Relay Driver Module (ULN2003)**  
- **Relay Module (2-channel)**  
- **Fan**  
- **Bulb**  
- **Speaker (Optional)**  
- **9V Batteries** (for external power)  
- **Breadboard & Jumper Wires**

## System Hardware Specifications
- **Arduino Uno**: ATmega328P, 16MHz, 5V logic, 14 Digital I/O pins, 6 Analog inputs.  
- **APDS-9960 Sensor**: Detects proximity and directional gestures.  
- **Relay Driver Board**: Controls high-voltage appliances through low-voltage Arduino signals.  
- **16x2 LCD**: Displays available appliance options to the user.  

## Pin Connections
| S.No | Pin Name | Arduino Connection | Usage |
|:---:|:--------|:------------------|:-----|
| 1 | SDA | A5 | APDS-9960 Communication |
| 2 | SCL | A4 | APDS-9960 Communication |
| 3 | VCC1 | 3.3V | Power for APDS-9960 |
| 4 | VCC2 | 5V | Power for Relay |
| 5 | GND | GND | Common Ground |
| 6 | GPIO8 | Pin 8 | Relay INP1 (Fan) |
| 7 | GPIO9 | Pin 9 | Relay INP2 (Bulb) |

## System Architecture
- **Gesture detected** by APDS-9960 ➔ Signal sent to **Arduino UNO**  
- Arduino interprets gestures ➔ Triggers specific **relay channels**  
- **Relays** switch connected devices (Fan, Bulb) ON or OFF accordingly  
- **LCD Display** shows appliance status  

## How It Works
- A **proximity reading** above 150 switches control between the fan and bulb.
- A **gesture** with proximity between 30-100 toggles ON/OFF the selected device.
- Relay modules control actual switching of appliances safely.
- Aurdino UNO controles the whole process

## Requirements
- Arduino IDE
- SparkFun APDS9960 Library (`Sketch` > `Include Library` > `Manage Libraries` > Search: *SparkFun APDS9960*)

---
