#include "SPI.h"
#include "STD_MESSAGES.h"
#include "DIO.h"
#include "LED.h"
#include "ADC_driver.h"
#include "timer_driver.h"
#include "APP_slave_Macros.h"
#include "SERVOM_interface.h"

volatile uint16 required_temperature=30; // the required temperature which sent from Master with initial value 24
volatile uint16 temp_sensor_reading=0; // the temperature of the room 
volatile uint8 counter=0; // the counter which determine the periodic time of implementing ISR
volatile uint8 last_air_conditioning_value=AIR_CONDTIONING_OFF; // last air conditioning value which will help in hysteresis

int main(void)
{
	ADC_vinit();//initialize the ADC of the micro controller
	timer0_initializeCTC();//Initialize the timer zero of the micro controller
	SPI_vInitSlave();//initialize the SPI as a slave
	SERVOM_vInit();//init Servo
	
	/* initialization of output pins of connected leds or devices */
	LED_vInit(AIR_COND_PORT,AIR_COND_PIN);
	LED_vInit(TV_PORT,TV_PIN);
	LED_vInit(ROOM1_PORT,ROOM1_PIN);
	LED_vInit(ROOM2_PORT,ROOM2_PIN);
	LED_vInit(ROOM3_PORT,ROOM3_PIN);
	LED_vInit(ROOM4_PORT,ROOM4_PIN);
	
	uint8 request = DEFAULT_ACK;//the value that is received from the master
	uint8 response = DEFAULT_ACK;//the values that is sent back to the master
	
	while(1)
	{
		request = SPI_ui8TransmitRecive(DEFAULT_ACK);//wait for the master to start the transmitting
		//ALL Messages are defined in STD_messages.h
		switch (request)
		{
			/*********************************   STATUS COMMANDS ********************************/
			//commands related to send the current status back to the master
			case ROOM1_STATUS:
			if (LED_u8ReadStatus(ROOM1_PORT,ROOM1_PIN)==0)//if the led is turned off
			{
				response = OFF_STATUS;//set the response as off status
			}
			else if (LED_u8ReadStatus(ROOM1_PORT,ROOM1_PIN)==1)//if the led is turned on
			{
				response = ON_STATUS;//set the response as on status
			}
			else
			{
			}
			SPI_ui8TransmitRecive(response);//response to the transmitter with the status
			break;//break the switch case
			case ROOM2_STATUS:
			if (LED_u8ReadStatus(ROOM2_PORT,ROOM2_PIN)==0)//if the led is turned off
			{
				response = OFF_STATUS;//set the response as off status
			}
			else if (LED_u8ReadStatus(ROOM2_PORT,ROOM2_PIN)==1)//if the led is turned on
			{
				response = ON_STATUS;//set the response as on status
			}
			else
			{
			}
			SPI_ui8TransmitRecive(response);//response to the transmitter with the status
			break;//break the switch case
			case ROOM3_STATUS:
			if (LED_u8ReadStatus(ROOM3_PORT,ROOM3_PIN)==0)//if the led is turned off
			{
				response = OFF_STATUS;//set the response as off status
			}
			else if (LED_u8ReadStatus(ROOM3_PORT,ROOM3_PIN)==1)//if the led is turned on
			{
				response = ON_STATUS;//set the response as on status
			}
			else
			{
			}
			SPI_ui8TransmitRecive(response);//response to the transmitter with the status
			break;//break the switch case
			case ROOM4_STATUS:
			if (LED_u8ReadStatus(ROOM4_PORT,ROOM4_PIN)==0)//if the led is turned off
			{
				response = OFF_STATUS;//set the response as off status
			}
			else if (LED_u8ReadStatus(ROOM4_PORT,ROOM4_PIN)==1)//if the led is turned on
			{
				response = ON_STATUS;//set the response as on status
			}
			else
			{
			}
			SPI_ui8TransmitRecive(response);//response to the transmitter with the status
			break;//break the switch case
			case AIR_COND_STATUS:
			if (LED_u8ReadStatus(AIR_COND_PORT,AIR_COND_PIN)==0)//if the led is turned off
			{
				response = OFF_STATUS;//set the response as off status
			}
			else if (LED_u8ReadStatus(AIR_COND_PORT,AIR_COND_PIN)==1)//if the led is turned on
			{
				response = ON_STATUS;//set the response as on status
			}
			else
			{
			}
			SPI_ui8TransmitRecive(response);//response to the transmitter with the status
			break;
			case TV_STATUS:
			if (LED_u8ReadStatus(TV_PORT,TV_PIN)==0)//if the led is turned off
			{
				response = OFF_STATUS;//set the response as off status
			}
			else if (LED_u8ReadStatus(TV_PORT,TV_PIN)==1)//if the led is turned on
			{
				response = ON_STATUS;//set the response as on status
			}
			else
			{
			}
			SPI_ui8TransmitRecive(response);//response to the transmitter with the status
			break;//break the switch case
			
			/*********************************   TURN ON COMMANDS ********************************/
			case ROOM1_TURN_ON:
			LED_vTurnOn(ROOM1_PORT,ROOM1_PIN);//turn on the led of room 1
			break;//break the switch case
			case ROOM2_TURN_ON:
			LED_vTurnOn(ROOM1_PORT,ROOM2_PIN);//turn on the led of room 2
			break;//break the switch case
			case ROOM3_TURN_ON:
			LED_vTurnOn(ROOM3_PORT,ROOM3_PIN);//turn on the led of room 3
			break;//break the switch case
			case ROOM4_TURN_ON:
			LED_vTurnOn(ROOM4_PORT,ROOM4_PIN);//turn on the led of room 4
			break;//break the switch case
			case AIR_COND_TURN_ON:
			timer0_initializeCTC();
			LED_vTurnOn(AIR_COND_PORT,AIR_COND_PIN);//turn on the led of air conditioning
			break;//break the switch case
			case TV_TURN_ON:
			LED_vTurnOn(TV_PORT,TV_PIN);//turn on the led of the TV
			break;//break the switch case
			case DOOR_OPEN:
				TMR1_start();
				SERVOM_vStart(90);
				SERVOM_vStop();
				TMR1_stop();

				break;//break the switch case
			
			/*********************************   TURN OFF COMMANDS ********************************/
			case ROOM1_TURN_OFF:
			LED_vTurnOff(ROOM1_PORT,ROOM1_PIN);//turn off the led of room 1
			break;//break the switch case
			case ROOM2_TURN_OFF:
			LED_vTurnOff(ROOM2_PORT,ROOM2_PIN);//turn off the led of room 2
			break;//break the switch case
			case ROOM3_TURN_OFF:
			LED_vTurnOff(ROOM3_PORT,ROOM3_PIN);//turn off the led of room 3
			break;//break the switch case
			case ROOM4_TURN_OFF:
			LED_vTurnOff(ROOM4_PORT,ROOM4_PIN);//turn off the led of room 4
			break;//break the switch case
			case AIR_COND_TURN_OFF:
			timer0_stop();
			LED_vTurnOff(AIR_COND_PORT,AIR_COND_PIN);//turn off the led of air conditioning
			break;//break the switch case
			case TV_TURN_OFF:
			LED_vTurnOff(TV_PORT,TV_PIN);//turn off the led of the TV
			break;//break the switch case
			
			/*********************************   Set temperature   ********************************/
			case SET_TEMPERATURE:
			required_temperature = SPI_ui8TransmitRecive(DEFAULT_ACK);//get the temperature from the master and store the temperature in required temperature 
			break;//break the switch case
		}
	}
}

ISR(TIMER0_COMP_vect)
{
	counter++;//count the ticks of the timer zero
	if(counter>=10)//do that code every 10 ticks 
	{
		counter=0;//clear the counter of ticks
		temp_sensor_reading=(0.25*ADC_u16Read());//read the temperature from the temperature sensor connected to the ADC of the micro controller
		if (temp_sensor_reading>=(required_temperature+1))//do that code if the read temperature if greater than required temperature by one or more
		{
			LED_vTurnOn(AIR_COND_PORT,AIR_COND_PIN);//turn on the led of the air conditioning
			last_air_conditioning_value=AIR_CONDTIONING_ON;//save the value of the state of the air conditioning
		}
		else if (temp_sensor_reading<=(required_temperature-1))//do that code if the read temperature if lesser than required temperature by one or more
		{
			LED_vTurnOff(AIR_COND_PORT,AIR_COND_PIN);//turn off the led of the air conditioning
			last_air_conditioning_value=AIR_CONDTIONING_OFF;//save the value of the state of the air conditioning
		}
		else if (required_temperature==temp_sensor_reading)//do that code if the read temperature is equal to the required temperature
		{
			if (last_air_conditioning_value==AIR_CONDTIONING_ON)//in the case of the last saved status of the air conditioning was on 
			{
				LED_vTurnOn(AIR_COND_PORT,AIR_COND_PIN);//turn on the led of the air conditioning
			}
			else if (last_air_conditioning_value==AIR_CONDTIONING_OFF)//in the case of the last saved status of the air conditioning was off 
			{
				LED_vTurnOff(AIR_COND_PORT,AIR_COND_PIN);//turn off the led of the air conditioning
			}
		}
	}
}
