#include "device_driver.h"

int Key_Value = 0;

void EXTI9_5_IRQHandler(void)
{
  Key_Value = Macro_Extract_Area(EXTI->PR, 0x3, 6);

  EXTI->PR = 0x3<<6;
  NVIC_ClearPendingIRQ((IRQn_Type)23);
}
