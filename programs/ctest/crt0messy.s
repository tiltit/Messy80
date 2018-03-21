;	Modified from the original file original file found at: 
;	https://www.msx.org/forum/msx-talk/development/sdcc-crt0s-for-floppy-bload
.globl	_main

.area	_HEADER (ABS)
.org	0x8400

.dw 	init
.dw		_end
.dw 	init

init:
	jp	_main

.area   _CODE	
.area	_GSFINIAL
_end:
	ret
	halt
