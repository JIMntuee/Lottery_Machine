# Lottery-Machine (Arduino project)
[TOC]
## About
- Usage：prize drawing during 2019 EE week
- Collaborator：高偉堯
- using easy codes and easy hardware techniques to implament a decent lottery machine

## Motivation
For last year's EE week, our seniors used a lottery machine made by carton and turned out the propability for each prize was too difficult to mantain balance.Therefore, I decided to make advantage of my skill on arduino and made one "electrical" lottery machine to make it looked fancy and easy to adjust chances of each prize.

## How it work
The lottery machine is been devided into 16 area. Press the button first and the LEDs will light up in turn, and press the button for the second time and the machine will end up with only one LED lighting up and flashing, the area with the LED up is the result.  

## Material
- Arduino Uno
- switch
- MDF(Medium Density Fiberboard)
- LEDs
- Dupont Lines

## Implamentation
### software
- arduino IDE
#### possibilities.h
Set the possibilities for each prize, it is in clockwise order.
#### spin.ino
Main function
### hardware

For convenience, when designing the structure and the enclosure, we use the design of EE camp's project. The final design is in the Enclosure folder. 
- Laser cutting machine
- MDF