// #define K2_DEBUG_VERBOSE
#define K2_DEBUG_WARN

#include <stddef.h>
#include <stdint.h>

#include "plat.h"
#include "utils.h"
#include "sched.h"

extern void test_ktimer();     // unittests.c
extern void test_fb_voffset(); // unittests.c
extern void donut();           // donut.c
extern void donut_simple();    // donut.c
extern void donut_text();      // donut.c
extern void putc(void* p, char c);// mini_uart.c

void uart_send_string(char* str);

struct cpu cpus[NCPU]; 

void kernel_main() {
	// Q4 quest
	uart_init();
	// Q4 quest
	init_printf(NULL, putc);
	printf("------ kernel boot ------  core %d\n\r", cpuid());
	printf("build time (kernel.c) %s %s\n", __DATE__, __TIME__); // simplicity
        
	sys_timer_init();                   // kernel timer: delay, timekeeping...
	enable_interrupt_controller(0);     // coreid
	// Q5 quest: sys_timer irq
	//donut_text();
	// Q11 test_ktimer();
	//test_fb_voffset();               // cycle through color quads
	test_ktimer();
	generic_timer_init();               // periodic ticks alive
	if (fb_init() != 0) BUG();          // will show the OS logo
        enable_irq();   //Put this above fb_init and get rid of the comment lines to see donut simple. 
        //If you just want to see the logo you can just get rid of the comment lines and put it bellow fb_init
        //donut_simple(); //get rid of comment lines and follow comments above to see donut_simple
	donut();
	while (1)
		asm volatile("wfi");            // what happen here?
}
