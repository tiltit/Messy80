PRG = messymonitor

all: $(PRG).rom

$(PRG).rom: $(PRG).ass
	 zasm -vw2 $(PRG).ass
	 
program: $(PRG).rom
	../utils/meeprog/meeprog -p /dev/ttyUSB0 -i $(PRG).rom
#	../utils/eeprom_writer/eeprom_program -p /dev/ttyUSB0 -i $(PRG).rom


clean:
	rm $(PRG).rom
	