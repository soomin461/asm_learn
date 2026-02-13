#include "device_driver.h"

void Main(void)
{
	/* crt0.s에서 SCB 레지스터 설정을 가능하도록 하기 위하여 Thread를 특권 모드로 설정하였음 */
	/* NMI exception (emulation) */

#if 0

	{
		extern void NMI_Gen(void);
		Uart1_Printf("NMI Test\n");
		NMI_Gen();
	}

#endif

	/* SysTick exception */

#if 0

	{
		extern volatile int SysTick_Flag;
		volatile int i;

		Uart1_Printf("SysTick Exception test\n");
		SysTick_OS_Tick(1000);

		for(;;)
		{
			if(SysTick_Flag)
			{
				SysTick_Flag = 0;
				Uart1_Printf(".");
				for(i=0; i<0x200000; i++);
			}
		}
	}

#endif

/* PendSV exception */

#if 0

	{
		extern void PendSV_Gen(void);
		Uart1_Printf("PendSV Test\n");
		PendSV_Gen();
	}

#endif

	/* SVCall exception */

#if 1

	{
		extern void PRT(void);
		extern int SQR(int);
		extern double ADD_DBL(double, double);

		Uart1_Printf("SVC Test\n");

		PRT();
		Uart1_Printf("SVC0 Returned\n");
		Uart1_Printf("SQR = %d [%d]\n", SQR(3), 3 * 3);
		Uart1_Printf("SVC1 Returned\n");
		Uart1_Printf("ADD_DBL = %f [%f]\n", ADD_DBL(3.14, 5.12), 3.14 + 5.12);
		Uart1_Printf("SVC2 Returned\n");
	}

#endif

	Uart1_Printf("Returned!\n");
}
