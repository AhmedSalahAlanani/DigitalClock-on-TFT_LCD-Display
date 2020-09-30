/******************************************************************/
/* Author	: Ahmed Salah										  */
/* Date		: 13 Sep 2020										  */
/* Version	: V01												  */
/******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Timer2_5_interface.h"
#include "Timer2_5_private.h"
#include "Timer2_5_config.h"


/*
*********************************************************************************************************
*                                           FUNCTION DEFINITIONS
*********************************************************************************************************
*/
void MTimer2_voidInit (void)
{
	#if (TIMER2_ENABLE == 1)
	
		#if	 (TIM2_DIRECTION == TIM2_5_DIRECTION_UP)
			TIM2->CR1 = (0x0);		//DIR = 0
		#elif(TIM2_DIRECTION == TIM2_5_DIRECTION_DOWN)
			TIM2->CR1 = (0x10);		//DIR = 1
		#endif
	
		TIM2->PSC =  TIM2_PRESCALER;	
		
	#endif
}
//***************************************************************************************************************
void MTimer2_voidSetBusyWait(u16 Copy_u16Ticks)
{
	#if (TIMER2_ENABLE == 1)
		(TIM2->CR1) &= ~(0x2);			//UDIS = 0
		(TIM2->CR1) &= ~(0x80);			//ARPE = 0 ;

		#if	 (TIM2_DIRECTION == TIM2_5_DIRECTION_UP)
			(TIM2->CNT)  =  0 - Copy_u16Ticks;
		#elif(TIM2_DIRECTION == TIM2_5_DIRECTION_DOWN)
			(TIM2->CNT)  =  Copy_u16Ticks;
		#endif

		(TIM2->SR)   =  (0x0);
		(TIM2->CR1) |=  (0x1);			//CEN = 1

		while(!((TIM2->SR)&(0x1))); 	//POLL UIF

		(TIM2->CR1) &= ~(0x1);			//CEN = 0
		(TIM2->SR)   =  (0x0);
	#endif
}
//***************************************************************************************************************
void MTimer3_voidInit (void)
{
	#if (TIMER3_ENABLE == 1)
	
		#if	 (TIM3_DIRECTION == TIM2_5_DIRECTION_UP)
			TIM3->CR1 = (0x0);		//DIR = 0
		#elif(TIM3_DIRECTION == TIM2_5_DIRECTION_DOWN)
			TIM3->CR1 = (0x10);		//DIR = 1
		#endif
	
		TIM3->PSC =  TIM3_PRESCALER;	
		
	#endif
}
//***************************************************************************************************************
void MTimer3_voidSetBusyWait(u16 Copy_u16Ticks)
{
	#if (TIMER3_ENABLE == 1)
		(TIM3->CR1) &= ~(0x2);			//UDIS = 0
		(TIM3->CR1) &= ~(0x80);			//ARPE = 0 ;

		#if	 (TIM3_DIRECTION == TIM2_5_DIRECTION_UP)
			(TIM3->CNT)  =  0 - Copy_u16Ticks;
		#elif(TIM3_DIRECTION == TIM2_5_DIRECTION_DOWN)
			(TIM3->CNT)  =  Copy_u16Ticks;
		#endif

		(TIM3->SR)   =  (0x0);
		(TIM3->CR1) |=  (0x1);			//CEN = 1
	
		while(!((TIM3->SR)&(0x1))); 	//POLL UIF
	
		(TIM3->CR1) &= ~(0x1);			//CEN = 0
		(TIM3->SR)   =  (0x0);
	#endif
}
//***************************************************************************************************************
void MTimer3_voidSetIntervalPeriodic (u16 Copy_u16Ticks, void (*Copy_ptr)(void))
{
	#if (TIMER3_ENABLE == 1)
		TIMER3_Callback = Copy_ptr;		//Set Callback

		(TIM3->CR1)   =  (0x84);		//UDIS = 0, URS = 1, ARPE = 1
		(TIM3->DIER)  =  (0x1);			//UIE = 1

		#if	 (TIM3_DIRECTION == TIM2_5_DIRECTION_UP)
			(TIM3->CNT)  =  0 ;
			(TIM3->ARR)  =  Copy_u16Ticks;
		#elif(TIM3_DIRECTION == TIM2_5_DIRECTION_DOWN)
			(TIM3->ARR)  =  0 - Copy_u16Ticks;
		#endif

		(TIM3->SR)   =  (0x0);
		(TIM3->CR1) |=  (0x1);			//CEN = 1

		//while(!((TIM3->SR)&(0x1))); 	//POLL UIF

		//(TIM3->CR1) &= ~(0x1);			//CEN = 0
		//(TIM3->SR)   =  (0x0);
	#endif
}
//***************************************************************************************************************
void MTimer4_voidInit (void)
{
	#if (TIMER4_ENABLE == 1)
	
		#if	 (TIM4_DIRECTION == TIM2_5_DIRECTION_UP)
			TIM4->CR1 = (0x0);		//DIR = 0
		#elif(TIM4_DIRECTION == TIM2_5_DIRECTION_DOWN)
			TIM4->CR1 = (0x10);		//DIR = 1
		#endif
	
		TIM4->PSC =  TIM4_PRESCALER;	
		
	#endif
}
//***************************************************************************************************************
void MTimer4_voidSetBusyWait(u16 Copy_u16Ticks)
{
	#if (TIMER4_ENABLE == 1)
		(TIM4->CR1) &= ~(0x2);			//UDIS = 0
		(TIM4->CR1) &= ~(0x80);			//ARPE = 0 ;

		#if	 (TIM4_DIRECTION == TIM2_5_DIRECTION_UP)
			(TIM4->CNT)  =  0 - Copy_u16Ticks;
		#elif(TIM4_DIRECTION == TIM2_5_DIRECTION_DOWN)
			(TIM4->CNT)  =  Copy_u16Ticks;
		#endif

		(TIM4->SR)   =  (0x0);
		(TIM4->CR1) |=  (0x1);			//CEN = 1
	
		while(!((TIM4->SR)&(0x1))); 	//POLL UIF
	
		(TIM4->CR1) &= ~(0x1);			//CEN = 0
		(TIM4->SR)   =  (0x0);
	#endif
}
//***************************************************************************************************************
void MTimer5_voidInit (void)
{
	#if (TIMER5_ENABLE == 1)
	
		#if	 (TIM5_DIRECTION == TIM2_5_DIRECTION_UP)
			TIM5->CR1 = (0x0);		//DIR = 0
		#elif(TIM5_DIRECTION == TIM2_5_DIRECTION_DOWN)
			TIM5->CR1 = (0x10);		//DIR = 1
		#endif
	
		TIM5->PSC =  TIM5_PRESCALER;	
		
	#endif
}
//***************************************************************************************************************
void MTimer5_voidSetBusyWait(u16 Copy_u16Ticks)
{
	#if (TIMER5_ENABLE == 1)
		(TIM5->CR1) &= ~(0x2);			//UDIS = 0
		(TIM5->CR1) &= ~(0x80);			//ARPE = 0 ;

		#if	 (TIM5_DIRECTION == TIM2_5_DIRECTION_UP)
			(TIM5->CNT)  =  0 - Copy_u16Ticks;
		#elif(TIM5_DIRECTION == TIM2_5_DIRECTION_DOWN)
			(TIM5->CNT)  =  Copy_u16Ticks;
		#endif

		(TIM5->SR)   =  (0x0);
		(TIM5->CR1) |=  (0x1);			//CEN = 1
	
		while(!((TIM5->SR)&(0x1))); 	//POLL UIF
	
		(TIM5->CR1) &= ~(0x1);			//CEN = 0
		(TIM5->SR)   =  (0x0);
	#endif
}
/*
*********************************************************************************************************
*                                           	ISR'S
*********************************************************************************************************
*/
void TIM3_IRQHandler(void)
{
	/*CLEAR INTERRUPT FLAG*/
	(TIM3->SR)   =  (0x0);

	if(TIMER3_Callback)
	{
		TIMER3_Callback();
	}
}
//***************************************************************************************************************
