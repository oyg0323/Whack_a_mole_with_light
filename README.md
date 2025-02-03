# Whack-a-Mole with Light Game - Arduino Project


An interactive Arduino-based game where players use a **light-emitting model gun** to "whack" virtual moles represented by LEDs and light sensors. Built with an LCD scoreboard, sound effects, and dynamic difficulty!

## Project Overview
- **Objective**: Hit light-activated targets (CDS sensors) when their corresponding LEDs light up.
- **Game Duration**: 60 seconds (speed increases at 40 seconds).
- **Scoring System**: 
  - Normal targets: +1 point
  - Golden target (LED 7): +3 points
- **Features**: Real-time LCD display, sound feedback, and MP3 background effects.

---

## Features
- **7 Interactive Targets** with LEDs and light sensors
- Dynamic countdown timer with difficulty scaling
- Sound effects for actions (hit success, timer alerts)
- I2C LCD display for score and time
- Simulated "light gun" gameplay mechanics

---

## Components
| Component | Quantity | Notes |
|-----------|----------|-------|
| Arduino Mega | 1 | Compatible with multiple I/O pins |
| CDS Light Sensors | 7 | Analog input (A2-A8) |
| LEDs | 7 | Digital pins 2-8 |
| I2C LCD (16x2) | 1 | Address: 0x27 |
| DFPlayer Mini | 1 | For MP3 playback |
| Speaker | 1 | Connected to digital pin 10 |
| Resistors | 7 | 10KΩ for CDS sensors |
| Push Button | 1 | Game start trigger |
| SD Card | 1 | Contains sound files |

---


**Key Connections**:
- LEDs: Digital Pins 2-8
- CDS Sensors: Analog Pins A2-A8
- DFPlayer Mini: RX=A10, TX=A11
- Speaker: Digital Pin 10
- I2C LCD: SDA=A4, SCL=A5

---

## Installation
1. **Required Libraries**:
   ```bash
   LiquidCrystal_I2C by Frank de Brabander
   SoftwareSerial by Arduino
   DFRobotDFPlayerMini by DFRobot
   ```

2. **SD Card Setup**:
   - Format SD card as FAT32
   - Add MP3 files in root folder:
   

3. **Upload Code**:
   
---

## How to Play
1. Press start button to begin
2. When an LED lights up:
   - Quickly aim your light gun at the corresponding CDS sensor
   - Successful hit = LED turns off + score increases
3. Special golden target (LED 7) gives 3x points
4. Game ends after 60 seconds

**Pro Tip**: Targets appear faster after 40 seconds!

---

## Code Structure
```python
main.ino
├── Initialize Components
├── Game Start Sequence
│   ├── 3-2-1 Countdown
│   └── MP3 Start Sound
├── Main Game Loop
│   ├── Random LED Activation
│   ├── Light Sensor Monitoring
│   ├── Score Calculation
│   └── Difficulty Scaling
└── Game End Sequence
    ├── Final Score Display
    └── Game Over Sound
```

---

## Technical Specifications
| Parameter | Value | 
|-----------|-------|
| Light Threshold | 700+ (analog read) |
| Base Response Time | 2 sec/target |
| Speed Mode Response | 1 sec/target |
| MP3 Volume Level | 20/30 |


---

## License
MIT License - Free for educational and personal use

---


