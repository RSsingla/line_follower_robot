// Project name : BLACK_LINE_FOLLOWER
// Designed By 		: Entrench Electronics
// Designed for		: Entrench Electronics
//                	  http://entrench.in
/* Program for "BLACK_LINE_FOLLOWER/Follows black path using 2 IR Sensors connected on PC0 and PC3" 
___________________________________________________________________________________________________

Connection Settings of the Kit

LEDs---@------------->PB1
LEDs---@------------->PB2
LEDs---@------------->PB3
LEDs---@------------->PB4
Left Sensor---------->PC3
Right Sensor--------->PC0
SOUND SENSOR--------->PB0
RIGHT MOTOR(+)------->PB1
RIGHT MOTOR(-)------->PB2
LEFT MOTOR(-)-------->PB3
LEFT MOTOR(+)-------->PB4
BOOTLoader Condition Check----->PC5(If 0 bootloader section else program execution
							    section of Flash memory)
RESET-------------------------->PC6
Crystal Ossilator-------------->PB6 and PB7
VB=Battery Supply
VCC=regulated 5V+
Gnd=Ground(0V)
*/


#include<avr/io.h>

void main()
{
	
	DDRC=0b0000000;   // set PORTC as input port
	DDRB=0b00011110;  // PB1, PB2, PB3, PB4 as output port
    int ls=0, rs=0, a=1;   // define & initialize ls, rs integer as 0 to 
					       // acquire the left sensor status in ls and right sensor
					       // status in rs 
	
	while(1)          // create infinite loop
	{
	
	rs=(PINC&0b0000001);    // acquire only left sensor status connected at PC0
	ls=(PINC&0b0001000);    // acquire only right sensor status connected at PC3
	

		if((rs==0b0000000)&(ls==0b0000000)) // check sensor status for both sensor OFF 
		{

			PORTB=0b00011110;  // stop
			
			ls=0;              // set sensor status off
			rs=0;              // set sensor status off
		
		}

		if((rs==0b0000001)&(ls==0b0000000))  // check sensor status for left sensor=ON and
		                                     // right sensor=OFF
		{
			
			PORTB=0b00010000;    // turn right
			
			ls=0;                // set sensor status off
			rs=0; 				 // set sensor status off
				            
		}
	
	
		if((rs==0b0000000)&(ls==0b0001000))  //check sensor status for left sensor=OFF and
		                                     // right sensor=ON
		{
			 
			PORTB=0b00000010;     //turn left
			
			ls=0;                 // set sensor status off
			rs=0; 				  // set sensor status off
			 
		}
	
		

        if((rs==0b0000001)&&(ls==0b0001000) ) // check sensor status for both sensor ON 
		{

			PORTB=0b00010010;    //move forward
			     
			ls=0;               //set sensor status off
			rs=0;               //set sensor status off
	
		}
		
		
	}

}
