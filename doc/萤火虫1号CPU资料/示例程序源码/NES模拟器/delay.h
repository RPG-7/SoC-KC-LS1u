/* —” ± */
#define Delay(count) \
	delay_count = (count); \
	while (delay_count--);

extern unsigned long delay_count;
