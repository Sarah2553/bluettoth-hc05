# Distance Measurement with HC-SR04 and STM32F401RE

This project measures the distance between the **HC-SR04 ultrasonic sensor** and an object using the **STM32F401RE Nucleo** board.
The measured distance is displayed on a **16x2 LCD with I2C interface**.

# How the HC-SR04 Works

The **HC-SR04** ultrasonic sensor measures distance by emitting an ultrasonic pulse and measuring the time it takes for the pulse to return after reflecting off an object. This process uses the **time-of-flight** principle.

1. The sensor sends out a short ultrasonic pulse via its **TRIG** pin.
2. The pulse travels through the air and reflects off an object, then returns to the sensor.
3. The **ECHO** pin receives the reflected signal, and the time taken for the pulse to return is recorded.

# Components Used

- STM32F401RE Nucleo board  
- HC-SR04 Ultrasonic Sensor  
- 16x2 I2C LCD Display  
- Jumper Wires  
- Breadboard (optional)

# Features

- Real-time distance measurement using the HC-SR04 sensor  
- Distance displayed on an I2C LCD  
- Uses a Timer to measure the duration of the echo signal  
- Displays a clean message if no object is detected

# Project by Jmai Sarra  
FST – STM32 Project – 2025

