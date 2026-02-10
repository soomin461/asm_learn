#define RCC_APB2ENR   (*(volatile unsigned long*)0x40021018)
#define GPIOB_CRH     (*(volatile unsigned long*)0x40010C04)
#define GPIOB_ODR     (*(volatile unsigned long*)0x40010C0C)

void Main(void)
{
  RCC_APB2ENR |= (1<<3);
  GPIOB_CRH = 0x66 << 0;
  GPIOB_ODR = 0x01 << 8;
  volatile int i;
  for (;;)
  {
  for(i=0;i<100000;i++)
  {
      GPIOB_ODR = 0x01 << 8;
  };
  for(i=0;i<100000;i++)
  {
      GPIOB_ODR = 0x03 << 8;
  };
  for(i=0;i<100000;i++)
  {
      GPIOB_ODR = 0x00 << 8;
  };
}
}
