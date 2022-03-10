- [1. Introduction](#1-introduction)
  - [1.1. Plan](#11-plan)
  - [1.2. Goals](#12-goals)
    - [1.2.1. ESP32](#121-esp32)
    - [1.2.2. Embedded Linux](#122-embedded-linux)
  - [1.3. Methods Discovered](#13-methods-discovered)
    - [1.3.1. ESP32](#131-esp32)
    - [1.3.1.1. FreeRTOS Delta OTA](#1311-freertos-delta-ota)
    - [1.3.1.2 Espressif OTA](#1312-espressif-ota)
    - [1.3.1.3 Azure RTOS OTA](#1313-azure-rtos-ota)
    - [1.3.1.4  Web Updater Arduino IDE](#1314--web-updater-arduino-ide)
    - [1.3.2. Embedded Linux](#132-embedded-linux)
    - [1.3.2.1 Mender](#1321-mender)
    - [1.3.2.2 SWUpdate](#1322-swupdate)
    - [1.3.2.3 JFrog](#1323-jfrog)
  - [1.4. Conclusion](#14-conclusion)
  - [1.5. Refs](#15-refs)
  - [1.6. Footnote](#16-footnote)

# 1. Introduction

The goal of the project is to find a way to "easily" update ioT devices over the air.
These methods should be as platform independent as possible and reusable whenever possible.
I will be looking for already existing methods to do so.
Writing pieces of software whenever needed.

---

## 1.1. Plan

  - Look within Verhaert for implementations already in use.
  - Scour the internet for existing solutions
  - Get a solution to work in a prototype
  - Compare the solutions to one another
  - Refine the prototype to a complete demonstration
  - Document the entire process (Will be done throughout the entire project)

---
  
## 1.2. Goals

### 1.2.1. ESP32

  - [ ] Finding OTA Solutions
  - [ ] Getting OTA to work
  - [ ] Working demonstrations
  - [ ] Finished paperwork
  
### 1.2.2. Embedded Linux

  - [ ] Finding OTA Solutions
  - [ ] Getting OTA to work
  - [ ] Working demonstrations
  - [ ] Finished paperwork
  
---

## 1.3. Methods Discovered

### 1.3.1. ESP32

---

###  1.3.1.1. [FreeRTOS Delta OTA](https://www.freertos.org/2022/01/delta-over-the-air-updates.html)
<details>
  <summary></summary>

  - Uses [AWS IoT AWS library](https://github.com/aws/ota-for-aws-iot-embedded-sdk)
  - Overview: 
  - Process:  
    ![Firmware update process](assets/imgs/firmware-update-process.png)
  - Advantages:
  - Disadvantages:
  - Conclusion:
  - [Demo](esp32/FreeRTOS/demo/README.md)
</details>

  
### 1.3.1.2 [Espressif OTA](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/ota.html)
<details>
  <summary></summary>

  - Overview 
  - Advantages:
    - Python CLI exists
    - Can be used as library to develop an app
    - Relatively safe (works with OTA slots)
  - Disadvantages:
    - Device and framework specific (only works on ESP32 with espressif framework)
  - Conclusion:
  - [Demo]()
</details>

### 1.3.1.3 [Azure RTOS OTA](https://docs.microsoft.com/en-us/azure/iot-hub-device-update/understand-device-update)
<details>
  <summary></summary>

  - Overview 
  - Advantages:
    - Well organized
    - Azure back-end can be used for many client frameworks
    - Easy to implement
    - Not a black box, the C-code is available
  - Disadvantages:
    - Not implemented for ESP32 yet
  - Conclusion:
  - [Demo]()
</details>

### 1.3.1.4  [Web Updater Arduino IDE](https://randomnerdtutorials.com/esp32-over-the-air-ota-programming/)
<details>
  <summary></summary>

  - Overview:
    - Arduino's IDE built in OTA updater.
  - Advantages:
    - Very simple
  - Disadvantages:
    - You need to include the OTA code with the program each time.  
    - If OTA code is forgotten you can't update over the air anymore.
    - Require's the use of the arduino IDE
    - Requires the use of the arduino framework.
    - Hard to impossible to automate
  - Conclusion:
    - While easy to implement, the limitations of the Arduino framework and IDE make this more suited for hobbyist use, rather than an enterprise solution. 
  - [Demo]()
</details>


### 1.3.2. Embedded Linux

---

### 1.3.2.1 [Mender](https://mender.io/)
<details>
  <summary></summary>
  
  - Overview:
  - Advantages:
  - Disadvantages:
  - Conclusion
  - [Demo]()
</details>

### 1.3.2.2 [SWUpdate](https://swupdate.org)
<details>
  <summary></summary>
  
  - Overview:
  - Advantages:
  - Disadvantages: 
  - [Docs](https://sbabic.github.io/swupdate/swupdate.html)
  - [Demo]()
</details>

### 1.3.2.3 [JFrog](https://jfrog.com/)
<details>
  <summary></summary>
  
  - Overview:
  - Advantages:
  - Disadvantages: 
  - [Demo]()
</details>

---

## 1.4. Conclusion

---

## 1.5. Refs

---

## 1.6. Footnote

---
