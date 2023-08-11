# ELECTRIC-STOVE
## Description
Design and implement firmware for induction stove control system.
## Power on and off.
The device must provide an on/off button. When the device is turned off, 
pressing the button causes the button to be turned on. Conversely, when the device is on, the 
pressing the same button for at least 1 second will cause it to be turned off. An LED shall show 
the user the status of the device.
Turning off can occur at any time if the user presses the appropriate button.
## Power control
The device can operate with four power levels (300W, 500W, 1000W, 1500W). Once the 
turned on the device, the user should be able to increase and decrease the power via two buttons 
dedicated.
As soon as the device is turned on, it starts from zero power (0W) and the stove is considered inactive. Once 
once the desired power is selected, the stove is activated if within 5 seconds this is not 
varied further.
The user can vary the power of the stove while it is already active, but the new power will be 
applied if within 5 seconds this is not varied further.
The power increase/decrease keys must be pressed for at least 1 second for the 
command takes effect.
Power display
An LED indicates the activation of the stove. The led operates in the following way according to the power output:<br />
  ● 0W off<br />
  ● 300W blinks with period of 2s<br />
  ● 500W flashes with period of 1s<br />
  ● 1000W flashes with period of 500ms<br />
  ● 1500W flashes with period of 250ms<br />
## Presence control 
The device should ensure that the stove is activated only in the event that a pot is present on the stove top. 
In addition, should this be removed while the stove is active, the device will signal for 10 seconds 
the anomaly via an LED, if the pan is not repositioned within this time the device will 
deactivates the stove (0W power).
## Input and Output
Therefore, the device is equipped with the following inputs and outputs:
1. On/off button
2. Button to increase power
3. Button to reduce power
4. Sensor to detect the presence of the pot
5. Device power led (indicates whether the stove is on, remains on as long as 
it is on)
6. Error led lights up in case of error
7. Stove activation led (indicates the power delivered by the stove according to the requirements
described above)
----
# CODE ORGANIZATION
The code is organized in 3 folders:
1. StateFlowModels folder contains the models of the system in the Simulink environment using Stateflow.
2. Test folder contains tests of significant use cases made up with the test environment in Simulink Test.
3. SourceCode folder contains the source code with the generated firmware from the Matlab environment.
