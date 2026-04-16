# Hermes_Temperature_Reader
Building a Custom Hermes project with a LM75AD_118, XIAO RP2040, and a 0.96” 128 X 64 OLED DISPLAY

# What?

So this project is about making something clean, cool, and something Im going to use for a long time.
It uses a PCB, a XIAO RP2040, a SSD1306 OLED Display, a LM75AD,118 Temperature sensor, 
One 0.1 µF Ceramic Capacitor, Two 4.7k ohm Resistors, and One 10k ohm Resistor.

# Why?

So I did the project so that I could learn how to build something using a Datasheet which I havn't done without help before,
cool, nice, and something I would actual use unlike the Blueprint Projects: Custom Hackpad and RP2040 DevBoard.
I also did this project because I was bored and waiting for my other project Pathfinder to get reviewed and approved.

# Pictures

3D Model:

<img width="790" height="788" alt="3D Viewer" src="https://github.com/user-attachments/assets/9f2c2aa5-985f-4801-bbda-4f6e0df4ff7f" />

PCB:

<img width="597" height="698" alt="PCB Viewer" src="https://github.com/user-attachments/assets/6dffe948-e2c0-40be-b319-f1b6c16abb95" />

Schematic: 

<img width="1432" height="724" alt="Schematic" src="https://github.com/user-attachments/assets/8498f8e6-6bf2-4b25-9dfc-ebd83be9553b" />

# BOM

| Name                                                                       | Purpose                                                                                                                                   | Quantity | Total Cost (USD) | Link                                                                                    | Distributor |
|----------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------|----------|------------------|-----------------------------------------------------------------------------------------|-------------|
| PCB                                                                        | To connect everything together                                                                                                            | 5        | 5.31             |                                                                                         | JLCPCB      |
| 10 kOhms ±5% 0.25W, 1/4W Through Hole Resistor Axial Carbon Film           | Used to dampen the Temperature Sensors data, again got 9 extra because it was cheaper                                                     | 10       | 0.31             | https://www.digikey.com/en/products/detail/stackpole-electronics-inc/CF14JT10K0/1741265 | Digikey     |
| 4.7 kOhms ±5% 0.5W, 1/2W Through Hole Resistor Axial Carbon Film           | To pull up the SDA and SCL, got 8 extra becausae it was cheaper                                                                           | 10       | 0.43             | https://www.digikey.com/en/products/detail/stackpole-electronics-inc/CF12JT4K70/1741152 | Digikey     |
| 0.1 µF ±10% 25V Ceramic Capacitor X7R 0603 (1608 Metric)                   | It's a Cermanic Capacitor for the Temperature Sensor. Got some extra because again I'm going to manually solder these by hand.            | 10       | 0.52             | https://www.digikey.com/en/products/detail/kemet/C0603C104K3RACTU/416044                | Digikey     |
| LM75AD,118 Temperature Sensor Digital, Local -55°C ~ 125°C 11 b 8-SO       | To get the temperature where ever it is powered, also got 1 extra because I'm going to be soldering this manually and not through JLCPCB. | 2        | 1.42             | https://www.digikey.com/en/products/detail/nxp-usa-inc/LM75AD-118/1692795               | Digikey     |
| RP2040 XIAO RP2040 - ARM® Cortex®-M0+ MCU 32-Bit Embedded Evaluation Board | This is used to power the board                                                                                                           | 1        | 5.15             | https://www.digikey.com/en/products/detail/seeed-technology-co-ltd/102010428/14672129   | Digikey     |
