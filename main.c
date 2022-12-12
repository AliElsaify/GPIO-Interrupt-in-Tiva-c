#include <IntCtrl.h>

int main ( void )
{
	Interrupt_Init()                                  ;
	GPIOInterruptProcess()                            ; 
	return 0                                          ;
	
}
