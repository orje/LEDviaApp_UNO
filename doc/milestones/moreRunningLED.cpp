#include "stdafx.h"
#include "stdint.h"

bool richtung = false;				// false = vorwärts, true = rückwärts
const uint16_t PIXELS = 4;			// Anzahl der Zellen					(PIXELS)
uint16_t tabelle[PIXELS] = { 0 };	// Tabelle erzeugen
uint16_t run_nr = 2;				// Anzahl der aktiven Gruppe			(run_nr)
int16_t led_x;						// Zellenzeiger							(led_x)
uint16_t led_index;					// Zellenindex							(led_index)
uint16_t run_nr_index;				// aktive Gruppe						(run_nr_index)
uint16_t m;							// Index für drucke
void drucke(void);					// printf debug

void main(void)
{
start:
	if (!richtung)
	{
		// exit action
		for (led_x = 0; led_x <= PIXELS - run_nr; led_x++)		// Überlaufbegrenzung
		{
			// entry action
			for (led_index = 0; led_index < PIXELS; led_index++)
			{
				if (led_index == led_x)
				{
					// Überlaufbegrenzung und "led_index" muss mitzählen
					for (run_nr_index = 0; run_nr_index < run_nr & led_index < PIXELS; run_nr_index++, led_index++)
					{
						tabelle[led_index] = 1;					// Zellenwert = 1
					}
					led_index--;								// Korrektur wg. 2*led_index++
				}
				else
				{
					tabelle[led_index] = 0;						// Zellenwert = 0
				}
			}
		}
		drucke();
		richtung = true;
	}
	if (richtung)
	{
		// exit action
		for (led_x = PIXELS; led_x >= run_nr; led_x--)
		{
			// entry action
			for (led_index = 0; led_index < PIXELS; led_index++)
			{
				if (led_index == led_x - run_nr)				// vorauslaufen beim Rückwärtslaufen
				{
					// "led_index" muss mitzählen
					for (run_nr_index = 0; run_nr_index < run_nr; run_nr_index++, led_index++)
					{
						tabelle[led_index] = 1;					// Zellenwert = 1
					}
					led_index--;								// Korrektur wg. 2*led_index++
				}
				else
				{
					tabelle[led_index] = 0;						// Zellenwert = 0
				}
			}
		}
		drucke();
		richtung = false;
	}
	goto start;
}

void drucke(void)
{
	printf("\nled_x:%d led_index:%d run_nr_index:%d\n", led_x, led_index, run_nr_index);
	for (m = 0; m < PIXELS; m++) {
		printf("%d", tabelle[m]);
	}
	printf("\n");
}