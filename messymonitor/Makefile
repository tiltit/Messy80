PRG = messymonitor

all: $(PRG).rom

$(PRG).rom: $(PRG).ass
	 zasm -vw2 $(PRG).ass
	 
program: $(PRG).rom
	minipro -p 'AT28C256' -w $(PRG).rom -s
#	../utils/meeprog/meeprog -p /dev/ttyUSB0 -i $(PRG).rom
#	../utils/eeprom_writer/eeprom_program -p /dev/ttyUSB0 -i $(PRG).rom

program_28c64: $(PRG).rom
	minipro -p 'AT28C64B' -w $(PRG).rom -s

clean:
	rm $(PRG).rom
	
