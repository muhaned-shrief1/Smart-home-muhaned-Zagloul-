
#include <avr/io.h>
#include "std_macros.h"
#include "STD_Types.h"
void ADC_vinit(void)
{
	/*configure VREF to the internal voltage(2.56 V)*/
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	/*************************************/
	SET_BIT(ADCSRA,ADEN); // ENable ADC
	
	/* adjust ADC clock by select the division factor----->64*/
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
	/***********************************/
}
uint16 ADC_u16Read(void)
{
	uint16 read_val; // which contain the converted value which will be returned
	SET_BIT(ADCSRA,ADSC); // start the ADC conversion
	while(IS_BIT_CLR(ADCSRA,ADIF));//stay in your position till ADIF become 1 when conversion complete
	SET_BIT(ADCSRA,ADIF); // clear ADIF
	read_val=(ADCL); //reas the ADCL register
	read_val|=(ADCH<<8);//read the whole register
	return read_val ; // return the converted value
}
