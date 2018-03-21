// -s -l8 /home/oliver/workspace/z80/messy80/programs/c_test/ctest.txt
#include <stdio.h>
#define UART_LINE_STATUS   			0x05
#define UART_LINE_STATUS_THRE		0x05
#define UART_TX_BUFF				0x00


/**
putchar (char c)
Nedded for printf
*/
void putchar (char c)
{
__asm

_wait_tx_ready:			// Wait util uart ready to send
	IN A,(UART_LINE_STATUS)
	bit UART_LINE_STATUS_THRE,A
	jr Z,_wait_tx_ready


	// Get the parameter c from the stack
	// There must be a better way to do this
	// This is insane :[
	pop DE
	dec sp				// Looks like SDCC saves some space by using inc and dec
						// when pushing 8bit values onto the stack
	pop AF
	// Put everything back the way it was.
	push AF
	inc sp
	push DE


	out (UART_TX_BUFF),A 	// At long last, send the byte

__endasm;
}



void main(void)
{
	putchar(':');
	putchar(')');
	putchar('\r');
	putchar('\n');
	printf("Hello world!\r\n");
}

