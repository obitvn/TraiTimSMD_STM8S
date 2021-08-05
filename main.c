/**
  ******************************************************************************
  * @file    Project/main.c 
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    30-September-2014
  * @brief   Main program body
   ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 


/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
volatile uint32_t time_keeper=0;
volatile uint32_t f_cpu;

/* Private defines -----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void clk_config_16MHz_hsi(void) 
{
	CLK_DeInit();
	CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);
	CLK_SYSCLKConfig(CLK_PRESCALER_HSIDIV1);
	CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSI, DISABLE, CLK_CURRENTCLOCKSTATE_DISABLE);
}



void delay_using_timer4_init(void)
{
	TIM4_TimeBaseInit(TIM4_PRESCALER_128,16);//1ms if fMaster=2Mhz
	TIM4_ClearFlag(TIM4_FLAG_UPDATE);
	TIM4_ITConfig(TIM4_IT_UPDATE,ENABLE);

	enableInterrupts();
	TIM4_Cmd(DISABLE);
}

void delay_isr(void)
{
	if(TIM4_GetITStatus(TIM4_IT_UPDATE)==SET)
	{
		if(time_keeper!=0)
		{
			time_keeper--;
		}
		else
		{
			/* Disable Timer to reduce power consumption */
			TIM4->CR1 &= (uint8_t)(~TIM4_CR1_CEN);
		}
		TIM4_ClearITPendingBit(TIM4_IT_UPDATE);
	}
}


void delay_ms(uint32_t time)
{
	time_keeper=time;

	/* Reset Counter Register value */
	TIM4->CNTR = (uint8_t)(0);

	/* Enable Timer */
	TIM4->CR1 |= TIM4_CR1_CEN;

	while(time_keeper);
}

void sang_tat_ca()
    {
      GPIO_WriteLow(GPIOD, GPIO_PIN_4); 
      GPIO_WriteLow(GPIOD, GPIO_PIN_5);
      GPIO_WriteLow(GPIOD, GPIO_PIN_6);
      GPIO_WriteLow(GPIOA, GPIO_PIN_2); 
      GPIO_WriteLow(GPIOA, GPIO_PIN_3);
      GPIO_WriteLow(GPIOB, GPIO_PIN_4);
      GPIO_WriteLow(GPIOB, GPIO_PIN_5); 
      GPIO_WriteLow(GPIOC, GPIO_PIN_3);
      GPIO_WriteLow(GPIOC, GPIO_PIN_4);
      GPIO_WriteLow(GPIOC, GPIO_PIN_5); 
      GPIO_WriteLow(GPIOC, GPIO_PIN_6);
      GPIO_WriteLow(GPIOC, GPIO_PIN_7);
      GPIO_WriteLow(GPIOD, GPIO_PIN_1); 
      GPIO_WriteLow(GPIOD, GPIO_PIN_2);
      GPIO_WriteLow(GPIOD, GPIO_PIN_3);     
    }
void nhay_xen_ke(uint16_t time)
    {
      GPIO_WriteLow(GPIOD, GPIO_PIN_4); 
      GPIO_WriteHigh(GPIOD, GPIO_PIN_5);
      GPIO_WriteLow(GPIOD, GPIO_PIN_6);
      GPIO_WriteHigh(GPIOA, GPIO_PIN_2); 
      GPIO_WriteLow(GPIOA, GPIO_PIN_3);
      GPIO_WriteHigh(GPIOB, GPIO_PIN_4);
      GPIO_WriteLow(GPIOB, GPIO_PIN_5); 
      GPIO_WriteHigh(GPIOC, GPIO_PIN_3);
      GPIO_WriteLow(GPIOC, GPIO_PIN_4);
      GPIO_WriteHigh(GPIOC, GPIO_PIN_5); 
      GPIO_WriteLow(GPIOC, GPIO_PIN_6);
      GPIO_WriteHigh(GPIOC, GPIO_PIN_7);
      GPIO_WriteLow(GPIOD, GPIO_PIN_1); 
      GPIO_WriteHigh(GPIOD, GPIO_PIN_1);
      GPIO_WriteLow(GPIOD, GPIO_PIN_3);
      delay_ms(time);
      GPIO_WriteHigh(GPIOD, GPIO_PIN_4); 
      GPIO_WriteLow(GPIOD, GPIO_PIN_5);
      GPIO_WriteHigh(GPIOD, GPIO_PIN_6);
      GPIO_WriteLow(GPIOA, GPIO_PIN_2); 
      GPIO_WriteHigh(GPIOA, GPIO_PIN_3);
      GPIO_WriteLow(GPIOB, GPIO_PIN_4);
      GPIO_WriteHigh(GPIOB, GPIO_PIN_5); 
      GPIO_WriteLow(GPIOC, GPIO_PIN_3);
      GPIO_WriteHigh(GPIOC, GPIO_PIN_4);
      GPIO_WriteLow(GPIOC, GPIO_PIN_5); 
      GPIO_WriteHigh(GPIOC, GPIO_PIN_6);
      GPIO_WriteLow(GPIOC, GPIO_PIN_7);
      GPIO_WriteHigh(GPIOD, GPIO_PIN_1); 
      GPIO_WriteLow(GPIOD, GPIO_PIN_1);
      GPIO_WriteHigh(GPIOD, GPIO_PIN_3);   
      delay_ms(time);
    }


void tat_het()
     {
      GPIO_WriteHigh(GPIOD, GPIO_PIN_4); 
      GPIO_WriteHigh(GPIOD, GPIO_PIN_5);
      GPIO_WriteHigh(GPIOD, GPIO_PIN_6);
      GPIO_WriteHigh(GPIOA, GPIO_PIN_2); 
      GPIO_WriteHigh(GPIOA, GPIO_PIN_3);
      GPIO_WriteHigh(GPIOB, GPIO_PIN_4);
      GPIO_WriteHigh(GPIOB, GPIO_PIN_5); 
      GPIO_WriteHigh(GPIOC, GPIO_PIN_3);
      GPIO_WriteHigh(GPIOC, GPIO_PIN_4);
      GPIO_WriteHigh(GPIOC, GPIO_PIN_5); 
      GPIO_WriteHigh(GPIOC, GPIO_PIN_6);
      GPIO_WriteHigh(GPIOC, GPIO_PIN_7);
      GPIO_WriteHigh(GPIOD, GPIO_PIN_1); 
      GPIO_WriteHigh(GPIOD, GPIO_PIN_2);
      GPIO_WriteHigh(GPIOD, GPIO_PIN_3); 
     }
void sang_len(uint16_t time)
    {
      tat_het();   
      GPIO_WriteLow(GPIOC, GPIO_PIN_3);
      delay_ms(time);
      GPIO_WriteLow(GPIOB, GPIO_PIN_5);      
      GPIO_WriteLow(GPIOC, GPIO_PIN_4);      
      delay_ms(time);
      GPIO_WriteLow(GPIOB, GPIO_PIN_4);
      GPIO_WriteLow(GPIOC, GPIO_PIN_5);       
      delay_ms(time);
      GPIO_WriteLow(GPIOA, GPIO_PIN_3);
      GPIO_WriteLow(GPIOC, GPIO_PIN_6);
      delay_ms(time);
      GPIO_WriteLow(GPIOA, GPIO_PIN_2); 
      GPIO_WriteLow(GPIOC, GPIO_PIN_7);
      delay_ms(time);
      GPIO_WriteLow(GPIOD, GPIO_PIN_6);
      GPIO_WriteLow(GPIOD, GPIO_PIN_1);      
      delay_ms(time);
      GPIO_WriteLow(GPIOD, GPIO_PIN_5);
      GPIO_WriteLow(GPIOD, GPIO_PIN_2);
      delay_ms(time);
      GPIO_WriteLow(GPIOD, GPIO_PIN_4); 
      GPIO_WriteLow(GPIOD, GPIO_PIN_3);   
      sang_tat_ca();
      delay_ms(time);
    }

void tat_dan(uint16_t time)
    {
      sang_tat_ca();
      delay_ms(time);
      GPIO_WriteHigh(GPIOD, GPIO_PIN_4); 
      GPIO_WriteHigh(GPIOD, GPIO_PIN_3);
      delay_ms(time);
      GPIO_WriteHigh(GPIOD, GPIO_PIN_5);
      GPIO_WriteHigh(GPIOD, GPIO_PIN_2);
      delay_ms(time);
      GPIO_WriteHigh(GPIOD, GPIO_PIN_6);
      GPIO_WriteHigh(GPIOD, GPIO_PIN_1);      
      delay_ms(time);
      GPIO_WriteHigh(GPIOA, GPIO_PIN_2); 
      GPIO_WriteHigh(GPIOC, GPIO_PIN_7);
      delay_ms(time);
      GPIO_WriteHigh(GPIOA, GPIO_PIN_3);
      GPIO_WriteHigh(GPIOC, GPIO_PIN_6);
      delay_ms(time);
      GPIO_WriteHigh(GPIOB, GPIO_PIN_4);
      GPIO_WriteHigh(GPIOC, GPIO_PIN_5);       
      delay_ms(time);
      GPIO_WriteHigh(GPIOB, GPIO_PIN_5);      
      GPIO_WriteHigh(GPIOC, GPIO_PIN_4);      
      delay_ms(time);
      GPIO_WriteHigh(GPIOC, GPIO_PIN_3);
      delay_ms(time);
    }
void sang_tung_led(uint16_t time)
    {
      tat_het();
      GPIO_WriteLow(GPIOD, GPIO_PIN_4); 
      delay_ms(time);
      tat_het();
      GPIO_WriteLow(GPIOD, GPIO_PIN_5);
      delay_ms(time);
      tat_het();
      GPIO_WriteLow(GPIOD, GPIO_PIN_6);
      delay_ms(time);
      tat_het();
      GPIO_WriteLow(GPIOA, GPIO_PIN_2);
      delay_ms(time);
      tat_het();
      GPIO_WriteLow(GPIOA, GPIO_PIN_3);
      delay_ms(time);
      tat_het();
      GPIO_WriteLow(GPIOB, GPIO_PIN_4);
      delay_ms(time);
      tat_het();
      GPIO_WriteLow(GPIOB, GPIO_PIN_5); 
      delay_ms(time);
      tat_het();
      GPIO_WriteLow(GPIOC, GPIO_PIN_3);
      delay_ms(time);
      tat_het();
      GPIO_WriteLow(GPIOC, GPIO_PIN_4);
      delay_ms(time);
      tat_het();
      GPIO_WriteLow(GPIOC, GPIO_PIN_5); 
      delay_ms(time);
      tat_het();
      GPIO_WriteLow(GPIOC, GPIO_PIN_6);
      delay_ms(time);
      tat_het();
      GPIO_WriteLow(GPIOC, GPIO_PIN_7);
      delay_ms(time);
      tat_het();
      GPIO_WriteLow(GPIOD, GPIO_PIN_1); 
      delay_ms(time);
      tat_het();
      GPIO_WriteLow(GPIOD, GPIO_PIN_2);
      delay_ms(time);
      tat_het();
      GPIO_WriteLow(GPIOD, GPIO_PIN_3);
      delay_ms(time);      
    }

void sang_dan_led(uint16_t time)
    {
      tat_het();
      delay_ms(time);
      GPIO_WriteLow(GPIOD, GPIO_PIN_4); 
      delay_ms(time);
      GPIO_WriteLow(GPIOD, GPIO_PIN_5);
      delay_ms(time);
      GPIO_WriteLow(GPIOD, GPIO_PIN_6);
      delay_ms(time);
      GPIO_WriteLow(GPIOA, GPIO_PIN_2);
      delay_ms(time);
      GPIO_WriteLow(GPIOA, GPIO_PIN_3);
      delay_ms(time);
      GPIO_WriteLow(GPIOB, GPIO_PIN_4);
      delay_ms(time);
      GPIO_WriteLow(GPIOB, GPIO_PIN_5); 
      delay_ms(time);
      GPIO_WriteLow(GPIOC, GPIO_PIN_3);
      delay_ms(time);
      GPIO_WriteLow(GPIOC, GPIO_PIN_4);
      delay_ms(time);
      GPIO_WriteLow(GPIOC, GPIO_PIN_5); 
      delay_ms(time);
      GPIO_WriteLow(GPIOC, GPIO_PIN_6);
      delay_ms(time);
      GPIO_WriteLow(GPIOC, GPIO_PIN_7);
      delay_ms(time);
      GPIO_WriteLow(GPIOD, GPIO_PIN_1); 
      delay_ms(time);
      GPIO_WriteLow(GPIOD, GPIO_PIN_2);
      delay_ms(time);
      GPIO_WriteLow(GPIOD, GPIO_PIN_3);
      delay_ms(time);
    } 

void tat_dan_led(uint16_t time)
   {
     sang_tat_ca();
     delay_ms(time);
     GPIO_WriteHigh(GPIOD, GPIO_PIN_3);
     delay_ms(time);
     GPIO_WriteHigh(GPIOD, GPIO_PIN_2);
     delay_ms(time);
     GPIO_WriteHigh(GPIOD, GPIO_PIN_1); 
     delay_ms(time);
     GPIO_WriteHigh(GPIOC, GPIO_PIN_7);
     delay_ms(time);
     GPIO_WriteHigh(GPIOC, GPIO_PIN_6);
     delay_ms(time);
     GPIO_WriteHigh(GPIOC, GPIO_PIN_5); 
     delay_ms(time);
     GPIO_WriteHigh(GPIOC, GPIO_PIN_4);
     delay_ms(time);
     GPIO_WriteHigh(GPIOC, GPIO_PIN_3);
     delay_ms(time);
     GPIO_WriteHigh(GPIOB, GPIO_PIN_5); 
     delay_ms(time);
     GPIO_WriteHigh(GPIOB, GPIO_PIN_4);
     delay_ms(time);
     GPIO_WriteHigh(GPIOA, GPIO_PIN_3);
     delay_ms(time);
     GPIO_WriteHigh(GPIOA, GPIO_PIN_2);
     delay_ms(time);
     GPIO_WriteHigh(GPIOD, GPIO_PIN_6);
     delay_ms(time);
     GPIO_WriteHigh(GPIOD, GPIO_PIN_5);
     delay_ms(time);
     GPIO_WriteHigh(GPIOD, GPIO_PIN_4); 
     delay_ms(time);
      
      
        
     
   }

void main(void)
{
   //clk_config_16MHz_hsi();
   f_cpu=CLK_GetClockFreq(); 
  /* Infinite loop */
  delay_using_timer4_init();
  enableInterrupts();
  GPIO_Init(GPIOD, GPIO_PIN_4, GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_Init(GPIOD, GPIO_PIN_5, GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_Init(GPIOD, GPIO_PIN_6, GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_Init(GPIOA, GPIO_PIN_2, GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_Init(GPIOA, GPIO_PIN_3, GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_Init(GPIOB, GPIO_PIN_4, GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_Init(GPIOC, GPIO_PIN_3, GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_Init(GPIOC, GPIO_PIN_4, GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_Init(GPIOC, GPIO_PIN_6, GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_Init(GPIOC, GPIO_PIN_7, GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_Init(GPIOD, GPIO_PIN_1, GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_Init(GPIOD, GPIO_PIN_2, GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_OUT_PP_HIGH_FAST);
  sang_tat_ca();
  delay_ms(500);
  
  
  while (1)
  {
    
    sang_len(200);
    tat_dan(200);  
    nhay_xen_ke(200);
    nhay_xen_ke(200);
    sang_len(200);
    tat_dan(200);
    tat_het();
    sang_tung_led(200);
    tat_dan_led(200);
    sang_dan_led(200);
    tat_dan_led(200);
    nhay_xen_ke(200);
    
  }
  
}

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the souGPIO_Init(GPIOA, GPIO_PIN_2, GPIO_MODE_OUT_PP_HIGH_FAST);rce file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
