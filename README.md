- [1. Introduction](#1-introduction)
  - [1.1 Plan](#11-plan)
  - [1.2 Goals](#12-goals)
    - [1.2.1. ESP32](#121-esp32)
    - [1.2.2. Embedded Linux](#122-embedded-linux)
  - [1.3 Methods Low-end](#13-methods-low-end)
    - [1.3.1.1 FreeRTOS OTA](#1311-freertos-ota)
    - [1.3.1.2 Azure RTOS OTA](#1312-azure-rtos-ota)
    - [1.3.1.3  Web Updater Arduino IDE](#1313--web-updater-arduino-ide)
  - [1.3.2 Methods Embedded Linux](#132-methods-embedded-linux)
    - [1.3.2.1 Mender](#1321-mender)
    - [1.3.2.2 SWUpdate](#1322-swupdate)
    - [1.3.2.3 AWS IoT Greengrass OTA](#1323-aws-iot-greengrass-ota)
  - [1.5 Comparison](#15-comparison)
    - [1.5.1 Low-end](#151-low-end)
    - [1.5.2 Embedded Linux](#152-embedded-linux)
  - [1.6 Conclusion](#16-conclusion)
  - [1.7 Refs](#17-refs)
  - [1.8 Footnote](#18-footnote)

# 1. Introduction

The goal of the project is to find a way to "easily" update ioT devices over the air.
These methods should be as platform independent as possible and reusable whenever possible.
I will be looking for already existing methods to do so.
Writing pieces of software whenever needed.

---

## 1.1 Plan

  - Look within Verhaert for implementations already in use.
  - Scour the internet for existing solutions
  - Get a solution to work in a prototype
  - Compare the solutions to one another
  - Refine the prototype to a complete demonstration
  - Document the entire process (Will be done throughout the entire project)

---
  
## 1.2 Goals

### 1.2.1. ESP32

  - [x] Finding OTA Solutions
  - [x] Getting OTA to work
  - [x] Working demonstrations
  - [x] Finished paperwork
  
### 1.2.2. Embedded Linux

  - [x] Finding OTA Solutions
  - [x] Getting OTA to work
  - [x] Working demonstrations
  - [x] Finished paperwork
  
---

## 1.3 Methods Low-end

---

###  1.3.1.1 [FreeRTOS OTA](https://www.freertos.org/2022/01/delta-over-the-air-updates.html)
<details>
  <summary></summary>

  - Easy to use with the [AWS IoT AWS library](https://github.com/aws/ota-for-aws-iot-embedded-sdk) but other OTA mechanism are also possible
  - Overview:
    - FreeRTOS is an open source real-time operating system. It is one of if not the most popular RTOS for embedded systems. Recently it also works together with Amazon Webservices, mostly focussed on IoT. This way it is also possible to do over-the-air updates from the AWS cloud.
  - Process:
    - FreeRTOS OTA works in 5 steps:
      - The microcontroller subscribes itself to the server to receive a notification if new information is available; Or it checks the server for new updates on an interval.
      - The device receives an update request with the important information about the update.
      - The update data gets downloaded and compared with the update request.
      - The received data gets tested to see if it is functional.
      - The microcontroller carries out the update.
    - AWS offers this data in a bucket,  this ensures the safety of the update.
  - In practice:
  - Advantages:
    - **Safe**: FreeRTOS OTA works over the HTTPS protocol, this ensures no open internet ports when not in use; But also that the data is from a trustworthy source. AWS works with tokens, certificates and policies with which you configure which devices can access what data.
    - **Scalable**: Via AWS IoT is is it possible to manage and update many devices at the same time.You can divide everything in groups and then update them per group or per device.
    - **AWS Cloud**: You are already connected with the AWS Cloud. On which you can host your updates, but you can also use it for your IoT applications, cloud storage, cloud computing etc.
    - **Not AWS dependable**: The FreeRTOS OTA libraries provide polling, downloading and the installation of the updates from a server. There is support from AWS to carry out the updates from the AWS cloud, but you can also host the updates on another server.
    - **Price**: FreeRTOS is free and open source software.
    (Only applies if AWS servers are used:) You only pay for the data and functions you use.
    - **Multiplatform**: Works on all devices FreeRTOS runs on. So you don't have to search different solutions for different microcontrollers. FreeRTOSworks on almost all microcontrollers on which OTA deems necessary.
  - Disadvantages:
    - **Price**: (Only applies if AWS servers are used:) Because you don't pay a fixed cost, but pay for used data you don't have perfect insight on the cost. You might use data without being aware of. Costs could mount above the budget if you don't pay attention to it.
    - **Complex and time intensive**: The building of the FreeRTOS code with OTA library is, depending on the device and tools you use, already quite a big task. If you also want to include the AWS libraries into the compilation it will take even longer langer, and could guarantee you some debugging nightmares. Also the configuration of all the AWS options (policies, certificates, tokens …) takes quite some time.
  - Conclusion:
    - A solutions that takes some time to get it working like you want it to. With the big advantage that as long as FreeRTOS OTA is supported for the platform, you only have to recompile the code for that platform. The back-end and configuration is easily portable, across many different platforms. As a long term solution for low-end microcontrollers is this likely the best method. For sure if you already use AWS function or are planning to use those in the future.
  - [Demo](esp32/FreeRTOS-OTA/demo/README.md)
</details>

### 1.3.1.2 [Azure RTOS OTA](https://docs.microsoft.com/en-us/azure/iot-hub-device-update/understand-device-update)
<details>
  <summary></summary>

  - Overview:
    - Azure RTOS is a realtime operating system by Microsoft Azure that focusses on IoT applications. Azure RTOS has its own OTA with which you can update your device via the Azure cloud.
  - Process:
    - Azure RTOS has multiple components, for the OTA requirements the focus lis on two parts:
      - ThreadX: With ThreadX is possible to run multiple threads “at the same time". This makes it possible to for example run a server in the background while still running other code int he foreground. If a task is waiting for something, like the processing of data, it will switch to another thread.
      - NetX: NetX ensures the connection to a network. It contains a lot of network protocols.
    - These two are necessary because you want to grab your updates from the network and would like to do this in the background. This way you can check for updates without disturbing the main workflow.
    - When Azure RTOS notices that new updates are available it will download and install them.
  - Advantages:
    - **Safe**: Azure RTOS OTA works over the HTTPS protocol, this ensures no open internet ports when not in use; But also that the data is from a trustworthy source. AWS works with tokens, certificates and policies with which you configure which devices can access what data.
    - **Scalable**: Via Azure IoT is is it possible to manage and update many devices at the same time.You can divide everything in groups and then update them per group or per device.
    - **Azure Cloud**: You are already connected with the Azure Cloud. On which you can host your updates, but you can also use it for your IoT applications, cloud storage, cloud computing etc.
    - **Price**: You only pay for the data and services that you use.
    - **Multiplatform**: Works on all devices Azure RTOS runs on. So you don't have to search different solutions for different microcontrollers. 
  - Disadvantages: 
    - **Availability**: Azure RTOS only offers support to a couple of microcontroller brands. It might take some time before it supports all popular platforms.
    - **Price**: (Only applies if AWS servers are used:) Because you don't pay a fixed cost, but pay for used data you don't have perfect insight on the cost. You might use data without being aware of. Costs could mount above the budget if you don't pay attention to it.
    - **Azure account required**: To use Azure RTOS OTA you need an Azure account to host the updates.
  - Conclusion:
    - A great solution if you already make use of Azure services or are planning to make use of them; If this isn't the case it will take some time setting everything up. The price is a double-edged sword; On one side you only pay for the functionality you use, on the other side unexpected costs can stack up. You need to pay attention to which services you use and how much they cost, this takes some effort compared to paying a monthly cost. The biggest problem with Azure RTOS is that it is far away from supporting al popular microcontrollers. So its best to first make sure the platform you're going to use supports Azure RTOS.
  - [Demo](esp32/Azure-OTA/demo/README.md)
</details>

### 1.3.1.3  [Web Updater Arduino IDE](https://randomnerdtutorials.com/esp32-over-the-air-ota-programming/)
<details>
  <summary></summary>

  - Overview:
    - The Arduino framework offers it own solution for over-the-air updates. With it you can upload a new sketch to the device via a webinterface.
  - Process:
    - The Arduino devices runs its own webserver with a webinterface. When this receives new data it will download and install it. When that's done the device will reboot.
  - Advantages:
    - **Simple**: To get this to work you don't have to do more than download some sample code and configure it to your liking, or to integrate it in the rest of your code. The only thing that actually has to be changed are the wifi credentials.
  - Disadvantages:
    - **Not robust**: If you forget to include the OTA code in your new code you won't be able to do OTA updates in the future. If this happens you need to flash the device again with the OTA code included. There's also no back-up to go back to a previous version if something goes wrong.  
    - **Low to no scalability**: You need to update your devices one by one. it is possible to write code for this, but with that effort it's probably better to choose for a better, existing solution.
    - **Arduino framework**: A easy to use framework for hobbyists with relatively low knowledge of embedded software. With a lot of pre-made solutions and online information it's easy to get something to work; But for a team or company its not really the most recommended approach.
  - Conclusion:
    - While easy to implement, the limitations of the Arduino framework and IDE make this more suited for hobbyist use, rather than an enterprise solution. 
  - [Demo](esp32/Web-Updater-Arduino-IDE/demo/README.md)
</details>


## 1.3.2 Methods Embedded Linux

---

### 1.3.2.1 [Mender](https://mender.io/)
<details>
  <summary></summary>
  
  - Overview:
    - Mender is an open source solution for managing and updating remote software. This can vary from updating a single device to an entire fleet of hundreds or thousands of devices. It can be used on its own or integrated with Azure IoT.
  - Process:
    - Mender consists of two parts; A server and a client.
    The server stores the data for the update and manages its deployment. Mender provides both a web interface and an API for managing, monitoring, configuring and updating devices; You can integrate this API into your desired work environment.
    The client runs in the background of the devices you want to update. This will occasionally check whether there are updates available on the server; If updates are available, the client will download and install them.

    There are several types of updates (e.g. applications, containers, kernels). These are divided into two parts; System level updates (e.g. installing a new version of Windows or Linux) and partial updates (e.g. installing or updating a program).
    For system level updates Mender uses an A/B partition layout. One active the device is booted into and one passive. If an update is ready, Mender will install it in the passive partition.

    When the installation is complete, the system will reboot and boot with the passive partition. In case something went wrong during the update, it can still boot with the active partition, in other words the previous version. This guarantees that the device will not "hang".

    If the update is successful, the active and passive partitions will switch, the new version will now be permanently active until the next update.
    Downloading and installing updates happens in the background without interfering with the normal operation of the device. The only downtime is when the system reboots boots into the passive partition. This often takes no longer than a couple minutes.

    For partial updates, the A/B partition method is not necessary, nor does the system have to reboot on updates.

    Mender uses the HTTPS protocol and offers a secure option. It is also possible to sign code so that you are sure that you have downloaded updates from a reliable source.

  - Advantages:
    - **Relatively simple and time-saving**: Quick set-up with instructions that can be followed on the Mender site.

    - **Low Downtime**: The only downtime is when the system reboots with the new version. There is a little more stress on the system while downloading and installing new software, but this shouldn't be a major problem.

    - **Robust**: Due to the use of A/B partition system, if something goes wrong the system will continue to run on the previous version.

    - **Partial updates**: If no new firmware is required, it is possible to install only .deb packages or containers. After this, depending on the package installed, a restart is not always required. It is also faster than downloading and installing a full file system.

    - **Secure**: Mender works over the HTTPS protocol, meaning no open ports when not in use; But also that data can only come from a reliable source. It is also possible to "sign" your software, so you can be sure that it is the desired software that you download.

    - **Scalable**: With Mender it is possible to manage and update many devices at the same time. You can divide everything into groups and then perform an update per group or even per device.

    - **Price**: A fixed monthly cost makes it very easy to calculate whether or not Mender fits within the budget. And you avoid the risk of having large unplanned costs.
  - Disadvantages:
    - **Storage**: Using an A/B partition saves the rootfs and kernel twice even though only one is used at a time.

    - **Price**: Depending on how many devices you want to manage and which functions are needed, AWS and Azure often come out cheaper.

  - Conclusion:
    - Mender is a fantastic tool for companies to manage and update remote software. Thanks to the integration with Azure, it is possible to manage an existing Azure configuration with Mender or vice versa. Thanks to its low downtime and robustness, there is little that can actually go wrong. With a fixed monthly price you always come out safely and you save on unforeseen costs. But if you already have software running on AWS or Azure, these often come out cheaper.
  - [Demo](embedded-linux/Mender/demo/README.md)
</details>

### 1.3.2.2 [SWUpdate](https://swupdate.org)
<details>
  <summary></summary>
  
  - Overview:
    - SWUpdate is free and open source software that helps update devices from various media. A major use case of this is updating over the network, but you can also update from external media, such as a USB stick or SD card. SWUpdate is also more of an extensible framework than a standalone program. It is extensible with different protocols (handlers) to update software in various ways.
  - Process:
    - SWUpdate works on the principle of delivering one large image. This consists of the separate single images together with a sw description with meta information about the images or files. This can be delivered over various media: network, USB stick, SD card, UART ... As long as a handler is available to receive and process the data. Received data is stored in a temporary folder until all data is available. From then on, the update will be performed. If there is not enough RAM available to temporarily store everything, it is possible to work with zero-copy mode and everything will be installed immediately when received. 
  - Advantages:
    - **Configurable**: SWUpdate can be built in different ways via make menuconfig. For example, authentication can be turned on and off, a SHA-256 hash can be added for extra security, you can run it as a web server and more…

    - **Simple**: SWUpdate is quickly installed, easily configured and makes it easy to upload images.

    - **Price**: SWUpdate is free software.

  - Disadvantages: 
    - **Low scalability**: You have to update device by device. It is possible to pull images from a back-end server with SWUpdate, but then you have to use Hawkbit to automate it, or you have to look for a solution yourself. In this case it is still difficult to create a group system.

    - **No robustness**: SWUpdate gets an image and installs it, that's it. If something goes wrong, you have to solve it in another way, there are no backups (unless you integrate a solution for this yourself). SWUpdate does wait to install until all images have been received correctly, when the transfer is complete the installation will begin. There are no checks whether the images are functional or not.
  - Conclusion:
    - SWUpdate is the solution for small-scale projects. It's perfect for updating a handful of devices on an infrequent basis. Prototyping is a good example for when this can be very useful. For updating and managing many devices and/or performing updates on a frequent basis, it is better to look at a cloud solution such as AWS or Azure.
  - [Docs](https://sbabic.github.io/swupdate/swupdate.html)
  - [Demo](embedded-linux/SWUpdate/demo/README.md)
</details>


### 1.3.2.3 [AWS IoT Greengrass OTA](https://docs.aws.amazon.com/greengrass/v1/developerguide/core-ota-update.html)
<details>
  <summary></summary>
  
  - Overview: 
    - Greengrass is the IoT part of Amazon Web Services (AWS). It allows you to run, manage, and update software across many devices. You can choose what is run/stored locally and what works over the cloud. Greengrass also offers an OTA solution, which is the focus here.
  - Process:
    - Greengrass OTA consists of two parts, a server and a client. The server is the AWS cloud; Through here you can manage devices, deploy software, retrieve data, etc. The client is the AWS IoT Greengrass Core, which is a daemon (software that runs in the background) that runs on your device. This ensures the connection to the cloud, the transfer of data, the installation of new software ...
  - Advantages:
    - **Robust**: AWS Greengrass OTA is tested software used by many people. If something goes wrong during the updates, it will roll back to a previous working version.

    - **AWS Cloud**: Since the Greengrass OTA is part of AWS IoT, you can also use the other functionalities that AWS offers, especially AWS IoT. Such as an MQTT service or cloud storage and computing.

    - **Secure**: To connect the device to AWS Cloud you need a personal access key and secret key. You can only get hold of the secret key by downloading it the moment it is created. As long as you don't pass on this file or the key, no one else can have it or get it. Greengrass also uses the https protocol, which ensures a secure connection between device and server. If this is not enough, you can pay for the AWS IoT Device Defender.

    - **Scalable**: AWS offers the option to connect virtually infinite devices to the cloud. You can group devices together and update several at the same time; Or you can update a single device.
    Price: You only pay for the data and features you use.

  - Disadvantages:
    - **Price**: Because it is not a fixed cost, but paying for use, you have no insight into the effective costs. You may be using data without realizing it. Bills can go over budget if you don't watch what you're doing.

    - **Complex**: Managing the keys, certificates and policies takes quite some time. You quickly lose your focus because of the many options offered by AWS.

  - Conclusion:
    - A great solution if you are already using AWS services or looking to use them later; If this is not the case, you will lose a lot of time setting up keys, certificates and policies. The method of payment has advantages and disadvantages; On the one hand, you only pay for the functionality you use, on the other hand, costs can unexpectedly increase. You have to spend time checking what you do or don't use, this is more work than paying a fixed cost.
  - [Demo](embedded-linux/AWS-IoT-Greengass/README.md)
</details>


---

## 1.5 Comparison

### 1.5.1 Low-end

|             | Complexity | Robustness              | Safety | use-case   | Price                                   |
|-------------|------------|-------------------------|--------|------------|-----------------------------------------|
| FreeRTOS    | Medium     | Check for  correct data | Safe   | Enterprise | Per data                                |
| Azure RTOS  | Difficult  | Check for  correct data | Safe   | Enterprise | Free*                                   |
| Arduino OTA | Easy       | Nothing                 | Unsafe | Hobby      | Free                                    |
|             |            |                         |        |            | *Pay for data when  used with AWS cloud |

### 1.5.2 Embedded Linux

|                | Complexity | Robustness           | Safety        | use-case    | Price                      |
|----------------|------------|----------------------|---------------|-------------|----------------------------|
| Mender         | Medium     | Very Robust          | Safe          | Enterprise  | Monthly                    |
| AWS Greengrass | Difficult  | Very Robust          | Very Safe     | Enterprise  | Per data                   |
| SWUpdate       | Medium     | No back-up*          | Safe*         | Prototyping | Free*                      |
|                |            | *Unless own solution | *Configurable |             | *No server  costs included |

---

## 1.6 Conclusion

All investigated OTA methods have their use case; But for Verhaert's objective to find a reusable and platform-independent solution for companies, it is best to opt for an AWS or Azure solution. When only considering Embedded Linux, Mender is the perfect tool. If we look at extensions to also be able to update low-end devices remotely, the best supported platform is AWS with FreeRTOS OTA for the low-end microcontrollers and AWS Greengrass for the Embedded Linux side.

---

## 1.7 Refs

Mender Website  
https://mender.io/  

Mender How It Works  
https://mender.io/how-it-works  

AWS Greengrass IoT  
https://aws.amazon.com/greengrass/  

AWS Greengrass IoT OTA  
https://docs.aws.amazon.com/greengrass/v1/developerguide/core-ota-update.html  

SWUpdate  
https://sbabic.github.io/swupdate/swupdate.html  

Azure RTOS  
https://azure.microsoft.com/nl-nl/services/rtos/  

STM32 Azure RTOS  
https://www.st.com/content/st_com/en/campaigns/x-cube-azrtos-azure-rtos-stm32.html  

FreeRTOS  
https://www.freertos.org/  

FreeRTOS OTA  
https://www.freertos.org/ota/index.html  

FreeRTOS OTA Demo  
https://www.freertos.org/ota/ota-http-demo.html  

Arduino OTA Tutorial  
https://lastminuteengineers.com/esp32-ota-updates-arduino-ide/  


---

## 1.8 Footnote

---
