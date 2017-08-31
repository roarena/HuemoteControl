# HuemoteControl

### About
In my project I used those Samsung raw codes to control a LED light bulb from China.
Basically I've mapped which control functions from the TV Remove corresponds to the light commands,
then I can just call the function from anywhere outside/inside the house and the IR LED will emmit the 
corresponding waves to control the Light. =)
This is just for study pourpouse, but you can share your opinion about it, oh btw I SUCK at C, so don't
mind any mistakes here xD

## Libs Used:
* [IR-SLINGER](https://github.com/bschwind/ir-slinger)
* [LibPiGPIO](https://github.com/joan2937/pigpio.git)

## Usage:
````
gcc main.c -lm -lpigpio -pthread -lrt -o huemoteController
./huemoteController <command_wave>
//Example
./huemoteController 3 //Don't forget to configure your waves in controlWaves.h.