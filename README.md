
# RTOS-Lite Scheduler

A lightweight cooperative task scheduler for the STM32 NUCLEO-F446RE (ARM Cortex-M4).  
This project demonstrates a simple RTOS-like design using bare-metal C and SysTick-based task switching.

## 🎯 Features
- Round-robin cooperative task scheduling
- Millisecond-resolution task timing using SysTick
- Modular task registration structure
- Easy to extend with task priorities or delays

## 🛠️ Hardware
- **Board**: STM32 NUCLEO-F446RE
- **Core**: ARM Cortex-M4
- **Tools**: STM32CubeIDE or PlatformIO

## 📁 Project Structure
```
rtos-lite-scheduler/
├── src/
│   ├── main.c
│   ├── scheduler.c
│   ├── scheduler.h
│   └── tasks.c
├── README.md
└── .gitignore
```

## 🚀 Getting Started
1. Clone this repo to your local machine.
2. Open with STM32CubeIDE and configure SysTick to 1ms tick.
3. Add tasks in `tasks.c` and register them in the scheduler.
4. Flash to board and observe behavior over UART/LED toggles.

## 📌 Example Tasks
- Blink onboard LED
- Send message over UART
- Toggle GPIO every N ms

## 📬 Output Example
```
[1000 ms] Task1: Toggling LED
[2000 ms] Task2: UART message sent
```

## 📷 Screenshots / Diagrams
Add oscilloscope traces, architecture diagrams, or UART output here.

## 📝 License
MIT
