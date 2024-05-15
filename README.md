# DLL-Hijacking
We will perform DLL hijacking on some applications and also detect it using Volatility.

We will be using the following services:
  1. VirtualBox
  2. Metasploit
  3. Volatility
  4. Modex and Intermodex Plugin

# Step-1 : Understanding how a DLL is loaded
We start off by creating a basic application and a DLL that displays a custom message box when loaded. These files will be listed in the repository.
We then place both of them in the same directory on a windows VM (Make sure to turn off your Windows defender).

Now we execute the application and see the results. This is how a DLL is loaded:

![Screenshot_8](https://github.com/dicedealer/DLL-Hijacking/assets/74645710/1dff3e98-60fa-4763-85f0-3f7623ce1670)

Learn more about DLL search order in windows: https://learn.microsoft.com/en-us/windows/win32/dlls/dynamic-link-library-search-order

# Step-2 Performing Our test on a Legitimate Application

We can launch process monitor and after applying necessary filters to see how DLLs are being loaded, we can observe which applications are loading which DLLs. This is how we observed that explorer.exe was loading "cscapi.dll" from a wrong path.

![Explorer Filters](https://github.com/dicedealer/DLL-Hijacking/assets/74645710/c2428a87-d7c1-45b6-b402-03a6ecd140bb)


We will place our DLL in this path and name it "cscapi.dll". Then we will kill "explorer.exe" and restart it. Now we see our DLL is being loaded and the message box is displayed

![Explorer Hijacked](https://github.com/dicedealer/DLL-Hijacking/assets/74645710/6aa44493-3395-4fa1-b315-8a31f8853326)

# Step-3 Loading Burpsuite with a malicious payload

After performing the previous steps, we can similarly identify which DLLs an application in loading incorrectly. We will identify the same for BurpSuite and instead of a beningn DLL, this time we will load it with a payload generate by Metasploit and open a reverse tcp connection to gain access to the windows Machine from our Kali Machine.

We Identified a DLL after using the same filters in Process Monitor as before. The DLL is named "USERENV.DLL". We will generate our malicious DLL with metasploit as follows: 

![payload generation metasploit](https://github.com/dicedealer/DLL-Hijacking/assets/74645710/ce85189f-ab50-4449-a922-6d2443b4db07)

We will now place this malicious "USERENV.dll" in the respective directory and launch burpsuite. Doing so will open a connection for us on our Kali Machine and we can establish a MeterPreter session gaining remote access to the Windows machine. 

![Meterpreter Access](https://github.com/dicedealer/DLL-Hijacking/assets/74645710/fa1c251c-4905-42f0-80ac-6ca11279f6be)

Now we can clearly understand the power of this vulnerability. BurpSuite is just one example of thousands. There are a huge amount of applications that load DLLs from the wrong paths, they also load DLLs which either do not exist or they dont need which makes these applications vulnerable to DLL hijacking. I have put some of these in a seperate file "Vulnerable applications" in this repository.

# Step-4 Detecting DLL hijacking with Volatility

This step is a bit advanced and requires some knowledge about memory forensics and Volatility to understand. A few short youtube videos will help you understand, I Have made a "Credits and Resources" file in this Repository for the same. We make use of the "Modex" volatility plugin. First we take a memory dump of the Windows Machine using FTK imager.
This will now be analysed using Modex and we will receive the following detection information: 

First, the "cscapi.dll" detection:

![Explorer Detection](https://github.com/dicedealer/DLL-Hijacking/assets/74645710/bebbf5d1-e445-47e4-8458-e75a2063dc49)

Second, the BurpSuite "USERENV.dll"

![cscapi detection](https://github.com/dicedealer/DLL-Hijacking/assets/74645710/1c935132-ad04-4f92-9358-4fa030bbbf55)

# Summary

The purpose of this project was to learn, understand and compile everything about DLL hijacking by performing research to the best of my capability. This project paints a holistic picture about the vulnerability "DLL hijacking" and will help in authors and researchers to understand the vulnerablity and how to detect the same. Note that I have done my best to showcase this in the most uncomplicated manner possible but to perform the same that I have done will take time and more comprehension on the subject and other realted subjects like Metasploit, setting up virtual machines and basic networking knowledge. These can be learned by the "Credits and Resources" Section provided in the Repository.

Thanks for Stopping by !!









