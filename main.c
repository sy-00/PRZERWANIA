#include "led.h"
#include "timer_interrupts.h"
#include "keyboard.h"

void Automat()
{
	enum LedState {RIGHT_DIRECTION, LEFT_DIRECTION, STOP};
	static enum LedState eLedState = STOP;
	switch(eLedState)
			{
				case STOP:
					if(eKeyboardRead() == BUTTON_0)
					{
						eLedState = LEFT_DIRECTION;
					}
					else if(eKeyboardRead() == BUTTON_2)
					{
						eLedState = RIGHT_DIRECTION;
					}
					break;
				case RIGHT_DIRECTION:
					if(eKeyboardRead() == RELASED)
					{
						LedStepRight();
					}
					else if(eKeyboardRead() == BUTTON_1)
					{
						eLedState = STOP;
					}
					break;
					case LEFT_DIRECTION:
					if(eKeyboardRead() == RELASED)
					{
						LedStepLeft();
					}
					if(eKeyboardRead() == BUTTON_1)
					{
						eLedState = STOP;
					}
					break;
				
			}
}

/**********************************************/
int main (){
	unsigned int iMainLoopCtr;
	LedInit();
	Timer0Interrupts_Init(20000, &Automat);

	while(1){
	 	iMainLoopCtr++;
	}
}

