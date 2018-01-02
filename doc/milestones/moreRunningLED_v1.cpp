/*
run_nr < PIXELS - 3, sonst klappt's nicht.
*/

#include "stdafx.h"
#include "stdint.h"

bool run_bwd = false;			// false = vorwärts, true = rückwärts
const uint16_t PIXELS = 4;		// Anzahl der Zellen			(PIXELS)
uint16_t n[PIXELS] = { 0 };		// Tabelle erzeugen
uint16_t run_nr = 1;			// Anzahl der aktiven Gruppe	(run_nr)
uint16_t led_x;					// Zellenzeiger					(led_x)
uint16_t led_index;				// Zellenindex					(led_index)
uint16_t run_nr_index;			// Index der aktiven Gruppe		(run_nr_index)
uint16_t m;						// Index für drucke
void drucke(void);				// printf debug
int dummy;

/*----------------------------------------------------------------------------*/

void main(void)
{
	printf("PIXELS = %d \t run_nr = %d \n \n", PIXELS, run_nr);
start:
	if (!run_bwd)
	{
		// exit action
		for (led_x = 0; led_x <= PIXELS - run_nr; led_x++)
		{
			printf("start led_x++ = %d \n", led_x);
			// entry action
			for (led_index = 0; led_index <= PIXELS - run_nr; led_index++)
			{
				printf("\t");
				printf("start led_index++ = %d \n", led_index);
				if (led_index == led_x)
				{
					printf("\t");
					printf("led_index = %d == led_x = %d \n", led_index, led_x);
					for (run_nr_index = 0; run_nr_index < run_nr; 
						run_nr_index++, led_index++)		// led_index muss mitzählen
					{
						printf("\t \t");
						printf("start run_nr_index++ = %d \n", run_nr_index);
						printf("\t \t \t");
						printf("write led_index [%d] = 1", led_index);
						printf("\n");
						n[led_index] = 1;					// Zellenwert = 1
					}
					led_index--;							// Korrektur wg. 2*led_index
					printf("\t \t");
					printf("end run_nr_index++ = %d \n", run_nr_index);
				}
				else
				{
					printf("\t");
					printf("led_index != led_x");
					printf("\n");
					printf("\t \t \t");
					printf("write led_index [%d] = 0", led_index);
					printf("\n");
					n[led_index] = 0;						// Zellenwert = 0
				}
				printf("\t");
				printf("end led_index++ = %d \n", led_index);
			}
			drucke();
			dummy = 0;
		}
		printf("**********");
		printf("\n");
		printf("end led_x++ = %d \n", led_x);
		printf("**********");
		printf("\n");
		printf("\n");
		run_bwd = true;
	}
	if (run_bwd)
	{
		// exit action
		for (led_x = PIXELS; led_x >= run_nr; led_x--)
		{
			printf("start led_x-- = %d \n", led_x);
			// entry action
			for (led_index = PIXELS; led_index >= run_nr; led_index--)
			{
				printf("\t");
				printf("start led_index-- = %d \n", led_index);
				if (led_index == led_x)
				{
					printf("\t");
					printf("led_index = %d == led_x = %d \n", led_index, led_x);
					for (run_nr_index = run_nr; run_nr_index > 0; 
						run_nr_index--, led_index--)		// led_index muss mitzählen
					{
						printf("\t \t");
						printf("start run_nr_index-- = %d \n", run_nr_index);
						printf("\t \t \t");
						printf("write led_index [%d] = 1", led_index);
						printf("\n");
						n[led_index - 1] = 1;				// Zellenwert = 1
					}
					led_index++;							// Korrektur wg. 2*led_index
					printf("\t \t");
					printf("end run_nr_index-- = %d \n", run_nr_index);
				}
				else
				{
					printf("\t");
					printf("led_index != led_x");
					printf("\n");
					printf("\t \t \t");
					printf("write led_index [%d] = 0", led_index);
					printf("\n");
					n[led_index - 1] = 0;					// Zellenwert = 0
				}
				printf("\t");
				printf("end led_index-- = %d \n", led_index);
			}
			drucke();
			dummy = 0;
		}
		printf("**********");
		printf("\n");
		printf("end led_x-- = %d \n", led_x);
		printf("**********");
		printf("\n");
		printf("\n");
		run_bwd = false;
	}
	goto start;
}

void drucke(void)
{
	printf("----------");
	printf("\n");
	printf("show = ");
	for (m = 0; m < PIXELS; m++) {
		printf("%d ", n[m]);
	}
	printf("\n");
	printf("----------");
	printf("\n \n");
}