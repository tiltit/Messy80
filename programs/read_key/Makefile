PRG = read_key

all: $(PRG).txt

.PHONY: labels.ass

$(PRG).rom: $(PRG).ass labels.ass
	 zasm -vw2 $(PRG).ass
	 
$(PRG).txt: $(PRG).rom
	../../utils/ram_prg/ram_prg -s 8400 -i $(PRG).rom > $(PRG).txt

labels.ass:
	../../utils/messy80_get_labels/messy80_get_labels -i ../../messymonitor/messymonitor.log > labels.ass
