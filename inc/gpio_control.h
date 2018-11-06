#define USE_STDPERIPH_DRIVER
#define USE_FULL_ASSERT

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{
/* Infinite loop /
/ Use GDB to find out why we're here */
while (1);
}
#endif
