# High Powered Rocket Level-1 (HPR Lvl-1):


### Classifying a Rockets according to their total impulse:
- Rockets that goes to moon/mars, or to an earth orbit are called orbital class rockets;
- Those going below 100-250Km are called sounding rockets;
- Below 100Km are called high powered rockets, but they are sub-classified:<br>
  - As per NAR(National Associatoin of Rocketry):
![image](https://github.com/yup-VARUN/L1Rocket/assets/110617721/90c8edc8-8cfb-430f-9047-7eff27ad1070)

<u>__High Powered Rocketry in the USA:__</u><br>
FAA governs the US air space and have defined some guidelines:<br>
[Amateur Rocketry Guidelines](https://www.faa.gov/air_traffic/publications/atpubs/pham_html/chap31_section_1.html#:~:text=Class%202%20%2D%20a%20high%20power,pound%2Dseconds)


# Software Organization:
__Algorithms:__
- Noise Filtering:
  - Low pass filter
  - Butterworth filter
- Sensor Fusion:
  - State Estimators
  - Kalman filter

to be completed ...

# Design Overview:
to be written ...

# Avionics Overview:
  Here is a general overview of the different sensor and library files this repository includes. Firstly, what is a library file? A library/header file is a layer where you directly communicate with a given object of some given library class. Each Library has respected high-level functions that communicate with corresponding registers that carry meaningful data that the sensor populates into its memory. 

  The Communication protocol: Each sensor has a specific communication protocol associated with its header pins, ports that take in/put out some information. Among the three communication protocols, two are mostly used: SPI Serial Peripheral Interface, I2C Inter-Integrated Circuit, and UART Universal Asynchronous Receiver/Transmitter. Each of these has standard header pins to which you can connect wires from your microcontroller. 
  
  For SPI each sensor requires a MISO: {Master in Slave out(Data flowing out of the sensor to your parent microcontroller, ex: write2_BMP_regX())}, MOSI: {Master Out Slave In(Data coming out: getData_fromRegisterX)}, a clock pin which matches the signal message rate{baud rate} with the parent microcontroller and a CS {Identifier pin}.

  The name Inter-Integrated Circuit comes from the simplicity and pre overhead organization that is done on these communication lines: the I2C automatically has respected MOSI/MISO command specifiers within each byte of information which leads to the need for one communication header pin: SDA and one clock pin-SCL to match the baud rates of the parent and child sensor.

  UART uses Wires: 2 — TX (transmit), RX (receive) with no clock due to the asynchronous behavior of these sensors.

  Ok, so we went over the different communication protocols of the sensors we will be using, each has it's unique wiring to lead to proper data transmission. Our sensor stack includes a 10DOF IMU {Inertial Measuring Unit} which uses a I2C comm. protocol. these 10DOF are acceleration_x,acceleration_y. acceleration_z. a related magnetic field vector per our sensor frame: Mx, My,Mz. the omega vector {rate of change of our angle}: Omega_x, Omega_y, and Omega_z. and a Pressure sensor which we can read pressure or a converted altitude. 

  In addition to our IMU we have a GPS that communicates with the Global Navigation Satellite System which gives us a position vector of Px, Py, Pz.
  

# Future Experimental Functionalities/Payloads(not relevant to the HPR certifications):
- Custom Radio Communication module
- Reaction Wheel for stabilization of the Roll Axis
- Fin Control/Thrust Vector Control


<!-- ## Depricated Gameplan:
Step 1: Shortlist all of the sensors, actuators, microcontrollers, and other hardware components that would be the perfect fit for the given problem statement.<br>
Step 2: Come up with a schematic.<br>
Step 3: Write the program for each individual component.<br>
Step 4: Test all those individual parts of codes with the microcontroller on the breadboard or in the Proteus Software.<br>
Step 5: Integrate all those components together.<br>
Step 6: Perform tests.<br>
Step 7: Design a nice board, and route all the copper traces onto a PCB of the right size and shape.<br>
Step 8: Get the PCB manufactured, or manufacture it yourself.<br>
Step 9: Solder everything together.<br>

## Avionics Goals to be accomplished:
- Sensor Calibration,
- Test and initiate the telemetry and share the data through telemetry,
- Final Health checkup & report over telemetry("say ready for launch if everything is responding as it should"),
- Ignition Sequence: <br>
  - Check if the rocket is upright.<br>
  - Start logging the raw data from all sensors in the Flash memory chip.<br>
  - Buzzer n Light flash for Launch Alert. <br>
  - Update the IMU reference. <br>
  - Start the Camera Recording. <br>
  - Listen for the final confirmation signal over the Telemetry. <br>
  - Set the ignition charges to "HIGH" for 4 seconds.
- Determine the Altitude of the rocket in real time using: <br>
  - IMU(accelerometer + gyroscope) Data | Medium Low Pass Filter<br> 
  - Pressure Sensor Data | Aggressive Low Pass Filter<br>
  - GPS Z axis Data | Medium Low Pass Filter<br>
  - Convert all of the cleaned signals into Height<br>
  - Convert all of those heights into a single height using the Kalman Filter Algorithm for fusing multiple different sensors.
- Detect the apogee with the variation in height,
- Eject the parachute,
- Data logging(save the sensor locally on the flight computer),
- Location sensing,
- Landing detection,
- Stop the Camera Recording after 5 seconds,
- Send the location through the LoRa module,
- Write all of the data from flash chips to SD Card,
- Activate the buzzer after some delay. 

## Components Specifications:
__Rocket Motor:__
- Class I Rocket Motor

__Sensors:__
- Pressure Sensor: ~~BMP280 (deprecated)~~ [BMP390](https://www.adafruit.com/product/4816) | For altitude
- Accelerometer & Gyroscope: MPU6050 | For Navigation (inertial measurement unit)
- GPS Module: NEO-6M | For location sensing
- Magnetometer: GY-273 | For orientation sensing
- Camera Module: Raspberry Pi Camera Module 3 - 12MP 120 Degree | For capturing the video footage

__Signal Receiver & Transmitters:__
- nRF24
- LoRa Module


__Pyro Channels:__
- MOSFETs
- 900mAh LiPo Battery by Apogee (Model:09204)

__Microcontroller:__
- ATmega328P (deprecated)
- [ATmega328PB](https://www.microchip.com/en-us/product/atmega328pb)

__Memory:__
- Flash memory chip: FLASH - NOR Memory IC 256Mbit SPI - Quad I/O 133 MHz 16-SOIC | Storing the data reliably(soldered connections), quickly(133 MHz)
- SD card, for easier data recovery & redundancy. -->

