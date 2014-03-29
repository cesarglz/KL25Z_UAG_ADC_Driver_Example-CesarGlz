#include "derivative.h" /* include peripheral declarations */
#include "ADC.h"

int x;
int y;
int z;

int main(void)
{
	ADC_Init();
	
	for(;;) 
	{
		x = Read_ADC(0);
		y = Read_ADC(4);
		z = Read_ADC(3);
	}

	return 0;
}
