PRG=ctest

ALL: $(PRG).txt

crt0messy.rel: crt0messy.s
	sdasz80 -o crt0messy.s

$(PRG).ihx: $(PRG).c crt0messy.rel
	sdcc --code-loc 0x8480 --data-loc 0x8800 -mz80 --no-std-crt0 crt0messy.rel $(PRG).c

$(PRG).bin: $(PRG).ihx
	objcopy -Iihex -Obinary $(PRG).ihx $(PRG).bin

$(PRG).txt: $(PRG).bin
	../../utils/ram_prg/ram_prg -i $(PRG).bin -s 8400 > $(PRG).txt
	ls "`pwd`/$(PRG).txt"

clean:
	rm -f crt0messy.rel $(PRG).ihx $(PRG).bin $(PRG).txt
