/* ##########################################################################################################
 * # Create by Rodrigo Câmara - 26/08/2017																	#
 * # Using:																									#
 * # 	- IR-SLINGER -> https://github.com/bschwind/ir-slinger												#
 * #	- LibPiGPIO -> https://github.com/joan2937/pigpio.git												#
 * #	- Samsung TV Raw Codes -> http://arduinostuff.blogspot.com.br/2011/06/samsung-remote-ir-codes.html	#
 * # Make sure you have both Libs + IR Raw Codes for your device.											#
 * ##########################################################################################################
 * # In my project I used those Samsung raw codes to control a LED light bulb from China.					#
 * # Basically I've mapped which control functions from the TV Remove corresponds to the light commands,	#
 * # then I can just call the function from anywhere outside/inside the house and the IR LED will emmit the #
 * # corresponding waves to control the Light. =)															#
 * # This is just for study pourpouse, but you can share your opinion about it, oh btw I SUCK at C, so don't#
 * # mind any mistakes here xD																				#
 * ##########################################################################################################
 * */

#include <stdio.h>
#include "libs/irslinger.h"
#include "libs/controlWaves.h"

int main(int argc, char *argv[])
{
	setWave(argv[1]);
	
	uint32_t outPin = 21; // Change if you need it =)
	int frequency = 38000;
	double dutyCycle = 0.5;

	int result = irSlingRaw(
		outPin,
		frequency,
		dutyCycle,
		selectedWave, /* This comes from controlWaves.h*/
		sizeof(selectedWave) / sizeof(int));

    return 0;
}
