#include <REGX52.H>
typedef enum 
{
	SETUP_HOUR = 0U,
	SETUP_ALHOUR,
	SETUP_MIN,
	SETUP_ALMIN,
	SETUP_SEC,
	NOT_SETUP
}SetUpTime;

unsigned char slave1 = 0x70;
unsigned char code segments7Led[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x08, 0x47};
signed char u8Hour = 0;
signed char u8Min = 0;
signed char u8ALHour = 1;
signed char u8ALMin = 1;
signed char u8Sec = 0;
unsigned int u8Count = 0, u8Mode = 0;

void Delay(int Value)
{
	while(Value > 0)
	{
		Value--;
	}
}
void showLed7sSeg(unsigned char no, unsigned int u8Number)
{
	unsigned int u8TempNumber = 0U;

	u8TempNumber = segments7Led[u8Number];
	
	if((u8TempNumber&0x01) == 0x01)
	{
		P2_0 = 1;
	}
	else
	{
		P2_0 = 0;
	}

	u8TempNumber = u8TempNumber>>1;

	if((u8TempNumber&0x01) == 0x01)
	{
		P2_1 = 1;
	}
	else
	{
		P2_1 = 0;
	}

	u8TempNumber = u8TempNumber>>1;

	if((u8TempNumber&0x01) == 0x01)
	{
		P2_2 = 1;
	}
	else
	{
		P2_2 = 0;
	}

	u8TempNumber = u8TempNumber>>1;

	if((u8TempNumber&0x01) == 0x01)
	{
		P2_3 = 1;
	}
	else
	{
		P2_3 = 0;
	}

	u8TempNumber = u8TempNumber>>1;

	if((u8TempNumber&0x01) == 0x01)
	{
		P2_4 = 1;
	}
	else
	{
		P2_4 = 0;
	}

	u8TempNumber = u8TempNumber>>1;

	if((u8TempNumber&0x01) == 0x01)
	{
		P2_5 = 1;
	}
	else
	{
		P2_5 = 0;
	}

	u8TempNumber = u8TempNumber>>1;

	if((u8TempNumber&0x01) == 0x01)
	{
		P2_6 = 1;
	}
	else
	{
		P2_6 = 0;
	}

	if(no == 1)
	{
		P2_7 = 1;
	}else if (no == 2)
	{
		P3_0 = 1;
	}else if (no == 3)
	{
		P3_1 = 1;
	}else if (no == 4)
	{
		P3_2 = 1;
	}else if (no == 5)
	{
		P3_3 = 1;
	}else if (no == 6)
	{
		P3_4 = 1;
	}
	else
	{
		P2_7 = 0;
		P3_0 = 0;
		P3_1 = 0;
		P3_2 = 0;
		P3_3 = 0;
		P3_4 = 0;	
	}
	Delay(1000);
}

void Display_7seg(unsigned char Hour, unsigned char Min, unsigned char Sec, SetUpTime ModeSetup)
{
	unsigned int u8Digit;
   	
	if(ModeSetup == SETUP_HOUR)
	{
		P2_7 = 0;
		P3_0 = 0;
		P3_1 = 0;
		P3_2 = 0;
		P3_3 = 0;
		P3_4 = 0;
	
		u8Digit = Hour/10;
		showLed7sSeg(1,u8Digit);
	
		P2_7 = 0;
		P3_0 = 0;
		P3_1 = 0;
		P3_2 = 0;
		P3_3 = 0;
		P3_4 = 0;
	
		u8Digit = Hour%10;
		showLed7sSeg(2,u8Digit);
			
	}else if(ModeSetup == SETUP_ALHOUR)
	{
		P2_7 = 0;
		P3_0 = 0;
		P3_1 = 0;
		P3_2 = 0;
		P3_3 = 0;
		P3_4 = 0;
	
		u8Digit = Hour/10;
		showLed7sSeg(1,u8Digit);
	
		P2_7 = 0;
		P3_0 = 0;
		P3_1 = 0;
		P3_2 = 0;
		P3_3 = 0;
		P3_4 = 0;
	
		u8Digit = Hour%10;
		showLed7sSeg(2,u8Digit);

		P2_7 = 0;
		P3_0 = 0;
		P3_1 = 0;
		P3_2 = 0;
		P3_3 = 0;
		P3_4 = 0;
	
		showLed7sSeg(5,10);
	
		P2_7 = 0;
		P3_0 = 0;
		P3_1 = 0;
		P3_2 = 0;
		P3_3 = 0;
		P3_4 = 0;
	
		showLed7sSeg(6,11);
	}else if(ModeSetup == SETUP_ALMIN)
	{
		P2_7 = 0;
		P3_0 = 0;
		P3_1 = 0;
		P3_2 = 0;
		P3_3 = 0;
		P3_4 = 0;
	
		u8Digit = Min/10;
		showLed7sSeg(3,u8Digit);
	
		P2_7 = 0;
		P3_0 = 0;
		P3_1 = 0;
		P3_2 = 0;
		P3_3 = 0;
		P3_4 = 0;
	
		u8Digit = Min%10;
		showLed7sSeg(4,u8Digit);

		P2_7 = 0;
		P3_0 = 0;
		P3_1 = 0;
		P3_2 = 0;
		P3_3 = 0;
		P3_4 = 0;
	
		showLed7sSeg(5,10);
	
		P2_7 = 0;
		P3_0 = 0;
		P3_1 = 0;
		P3_2 = 0;
		P3_3 = 0;
		P3_4 = 0;
	
		showLed7sSeg(6,11);
	}
	else if(ModeSetup == SETUP_MIN)
	{
		P2_7 = 0;
		P3_0 = 0;
		P3_1 = 0;
		P3_2 = 0;
		P3_3 = 0;
		P3_4 = 0;
	
		u8Digit = Min/10;
		showLed7sSeg(3,u8Digit);
	
		P2_7 = 0;
		P3_0 = 0;
		P3_1 = 0;
		P3_2 = 0;
		P3_3 = 0;
		P3_4 = 0;
	
		u8Digit = Min%10;
		showLed7sSeg(4,u8Digit);
			
	}else if(ModeSetup == SETUP_SEC)
	{
		P2_7 = 0;
		P3_0 = 0;
		P3_1 = 0;
		P3_2 = 0;
		P3_3 = 0;
		P3_4 = 0;
	
		u8Digit = Sec/10;
		showLed7sSeg(5,u8Digit);
	
		P2_7 = 0;
		P3_0 = 0;
		P3_1 = 0;
		P3_2 = 0;
		P3_3 = 0;
		P3_4 = 0;
	
		u8Digit = Sec%10;
		showLed7sSeg(6,u8Digit);
			
	}else
	{
		P2_7 = 0;
		P3_0 = 0;
		P3_1 = 0;
		P3_2 = 0;
		P3_3 = 0;
		P3_4 = 0;
	
		u8Digit = Hour/10;
		showLed7sSeg(1,u8Digit);
	
		P2_7 = 0;
		P3_0 = 0;
		P3_1 = 0;
		P3_2 = 0;
		P3_3 = 0;
		P3_4 = 0;
	
		u8Digit = Hour%10;
		showLed7sSeg(2,u8Digit);
	
		P2_7 = 0;
		P3_0 = 0;
		P3_1 = 0;
		P3_2 = 0;
		P3_3 = 0;
		P3_4 = 0;
	
		u8Digit = Min/10;
		showLed7sSeg(3,u8Digit);
	
		P2_7 = 0;
		P3_0 = 0;
		P3_1 = 0;
		P3_2 = 0;
		P3_3 = 0;
		P3_4 = 0;
	
		u8Digit = Min%10;
		showLed7sSeg(4,u8Digit);
	
		P2_7 = 0;
		P3_0 = 0;
		P3_1 = 0;
		P3_2 = 0;
		P3_3 = 0;
		P3_4 = 0;
	
		u8Digit = Sec/10;
		showLed7sSeg(5,u8Digit);
	
		P2_7 = 0;
		P3_0 = 0;
		P3_1 = 0;
		P3_2 = 0;
		P3_3 = 0;
		P3_4 = 0;
	
		u8Digit = Sec%10;
		showLed7sSeg(6,u8Digit);
	}
}

void Interrupt_Timer0()
{
		//16 bits timer/counter
		TMOD = 0x01;

		//setup 1ms for overflow
		TH0 = 0xFC;
		TL0 = 0x18;
		//Enable Interrupt
		ET0 = 1;
		EA = 1;//enable ngat tong
		//Enable timer 0 
		TR0 = 1;
}

void ISR_TIMER0() interrupt 1
{	
	if(ET0 == 1)
	{	
		u8Count++;

		if(1000 == u8Count)
		{
			u8Sec++;
			u8Count = 0;
			if(u8Sec == 60)
			{
				u8Min++;
				u8Sec = 0;
				if(u8Min == 60)
				{
					u8Hour++;
					u8Min = 0;
					if(u8Hour == 24)
					{
						u8Hour = 0;
					}
				}
			}

		}
		//setup 1ms for overflow
		TH0 = 0xFC;
		TL0 = 0x18;
	}
}

void main()
{	
	Interrupt_Timer0();
	while(1)
	{	
		if(P3_5 == 0)
		{
			Delay(500);
			while(P3_5 == 0);
			u8Mode++;
		}
		if(u8Mode == 0)
		{
			Display_7seg(u8Hour, u8Min, u8Sec, NOT_SETUP);	
		}else if(u8Mode == 1)
		{
			if(P3_6 == 0)
			{
				Delay(500);
				while(P3_6 == 0);
				u8Hour++;
				
				if(u8Hour == 24)
				{
					u8Hour = 0;
				}
			}
	
			if(P3_7 == 0)
			{
				Delay(500);
				while(P3_7 == 0);
				u8Hour--;
				
				if(u8Hour == 0)
				{
					u8Hour = 23;
				}
			}
			Display_7seg(u8Hour, u8Min, u8Sec, SETUP_HOUR);	
		}else if(u8Mode == 2)
		{
			if(P3_6 == 0)
			{
				Delay(500);
				while(P3_6 == 0);
				u8Min++;
				
				if(u8Min == 60)
				{
					u8Min = 0;
				}
			}
	
			if(P3_7 == 0)
			{
				Delay(500);
				while(P3_7 == 0);
				u8Min--;
				
				if(u8Min == 0)
				{
					u8Min = 59;
				}
			}
			Display_7seg(u8Hour, u8Min, u8Sec, SETUP_MIN);	
		}else if(u8Mode == 3)
		{
			if(P3_6 == 0)
			{
				Delay(500);
				while(P3_6 == 0);
				u8Sec++;
				
				if(u8Sec == 60)
				{
					u8Sec = 0;
				}
			}
	
			if(P3_7 == 0)
			{
				Delay(500);
				while(P3_7 == 0);
				u8Sec--;
				
				if(u8Sec == 0)
				{
					u8Sec = 59;
				}
			}
			Display_7seg(u8Hour, u8Min, u8Sec, SETUP_SEC);	
		}else if(u8Mode == 4)
		{
			Display_7seg(u8ALHour, u8ALMin, u8Sec,SETUP_ALHOUR);
			
			if(P3_6 == 0)
			{
				Delay(500);
				while(P3_6 == 0);
				u8ALHour++;
				
				if(u8ALHour == 24)
				{
					u8ALHour = 0;
				}
			}
	
			if(P3_7 == 0)
			{
				Delay(500);
				while(P3_7 == 0);
				u8ALHour--;
				
				if(u8ALHour == 0)
				{
					u8ALHour = 23;
				}		
			}
		}
		else if(u8Mode == 5)
		{
			Display_7seg(u8ALHour, u8ALMin, u8Sec, SETUP_ALMIN);
			
			if(P3_6 == 0)
			{
				Delay(500);
				while(P3_6 == 0);
				u8ALMin++;
				
				if(u8ALMin == 60)
				{
					u8ALMin = 0;
				}
			}
	
			if(P3_7 == 0)
			{
				Delay(500);
				while(P3_7 == 0);
				u8ALMin--;
				
				if(u8ALMin == 0)
				{
					u8ALMin = 59;
				}
			}		
		}
		else
		{
			u8Mode = 0;
		}
		if((u8ALHour == u8Hour) && (u8ALMin == u8Min))
		{
			P1_3 = 1;	
		}else
		{
			P1_3 = 0;
		}

		if(P1_2 == 0)
		{	
			u8ALMin += 1;
			P1_3 = 0;	
		}
	}
}				 	