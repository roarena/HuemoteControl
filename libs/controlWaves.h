/* ##########################################################################################################
 * # Create by Rodrigo Câmara - 26/08/2017																	#
 * # Using:																									#
 * # 	- IR-SLINGER -> https://github.com/bschwind/ir-slinger												#
 * #	- LibPiGPIO -> https://github.com/joan2937/pigpio.git												#
 * #	- Samsung TV Raw Codes -> http://arduinostuff.blogspot.com.br/2011/06/samsung-remote-ir-codes.html	#
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

/* Button 3 - Turn Light OFF */
int BT_3[68]={4600,4350,700,1500,700,1550,650,1600,650,400,700,450,700,400,700,400,700,400,700,1550,650,1550,700,1500,700,400,700,450,700,400,700,400,700,400,700,400,700,1550,700,1500,700,450,650,450,700,400,700,400,700,400,700,1550,700,400,700,400,700,1550,650,1550,700,1500,700,1550,700,1500,700};
/* Button Volume UP - Turn Light ON in Random Color */
int BT_vup[68]={4600,4350,650,1550,700,1500,700,1550,700,400,700,400,700,450,650,450,700,400,700,1500,700,1550,650,1550,700,400,700,400,700,450,650,450,700,400,700,1500,700,1550,650,1550,700,400,700,450,700,400,700,400,700,400,700,450,650,450,650,450,650,1550,700,1500,700,1550,700,1500,700,1550,650};
/* Button Volume DOWN - Turn Light ON */
int BT_vdown[68]={4600,4350,700,1550,650,1550,700,1500,700,450,650,450,700,400,700,400,700,400,700,1550,700,1500,700,1550,700,400,700,400,700,400,700,450,650,450,650,1550,700,1500,700,450,650,1550,700,400,700,400,700,450,700,400,700,400,700,400,700,1550,700,400,700,1500,700,1500,700,1550,700,1500,700};

/* The wave selected via Command Line*/
int selectedWave[68]={};

void setWave(char * command){
   switch(command[0]) {
      case '1' :
         printf("Turn Light OFF!\n" );
         memcpy(selectedWave, BT_3, sizeof(BT_3));
         break;
      case '2' :
         printf("Turn Light RANDOM!\n" );
         memcpy(selectedWave, BT_vup, sizeof(BT_vup));
         break;
      case '3' :
         printf("Turn Light ON!\n" );
         memcpy(selectedWave, BT_vdown, sizeof(BT_vdown));
         break;
      default :
         printf("Invalid Wave\n" );
   }	
}
