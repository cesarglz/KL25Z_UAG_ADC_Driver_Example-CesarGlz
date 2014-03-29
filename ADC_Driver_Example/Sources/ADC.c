/*
 * ADC.c
 *
 *  Created on: Mar 5, 2014
 *      Author: Cesar
 */
#include "derivative.h"

void ADC_Init(void)
{
	SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;
	
	PORTE_PCR20 = PORT_PCR_MUX(0); //ADC0 channel 0
	PORTE_PCR21 = PORT_PCR_MUX(0);//ADC0 channel 4a
	PORTE_PCR22 = PORT_PCR_MUX(0);//ADC0 channel 3
	
	ADC0_CFG1 = 0x00;
	ADC0_CFG2 = 0x00;
	ADC0_SC3 = 0x0D;
}

int Read_ADC(int channel)
{
	int result=0;
	
	ADC0_SC1A |= channel;
	while((ADC0_SC1A & ADC_SC1_COCO_MASK) == 0);
	result = ADC0_RA;
	
	return result;
}
