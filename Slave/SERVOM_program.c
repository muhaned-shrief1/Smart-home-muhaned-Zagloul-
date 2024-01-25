#include "STD_Types.h"
#include "std_macros.h"

#include "DIO.h"
#include "TMR1_interface.h"
#include "APP_slave_Macros.h"

#include "SERVOM_interface.h"
#include "SERVOM_private.h"
#include "SERVOM_config.h"

void SERVOM_vInit()
{
	DIO_vsetPINDir(APP_SERVOM_PORT, APP_SERVOM_PIN, 1);
	TMR1_init();
}


void SERVOM_vStart(uint8 Copy_u8Angle)
{
	uint16 mappedValue = (Copy_u8Angle/0.18F) + 1000;
	TMR1_setCompareMatchValueA(mappedValue);
}

void SERVOM_vStop(void)
{
	TMR1_setCompareMatchValueA( 1000);
}


