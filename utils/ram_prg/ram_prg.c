/**
 * ram_prg
 *
 * Spits out a list of commands for the Messy80 to write data
 * into memory.
 * Args:
 * -s : Start address in hex
 * -i : Input file
 * usage ex: ram_ prg -i input.rom -s 8200
 * compile: gcc -o ram_prg ram_prg.c
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>
#include <getopt.h>
#include <time.h> 

int main(int argc,char** argv)
{
	unsigned char s[1024];
	int size, i;
	int c;
	char *str_start_address = NULL;

	uint16_t start_address;

	char *input_filename = NULL;
	FILE *input_file;
	uint64_t file_length;
	uint8_t *input_file_buffer;
	int test_nbr_args = 0;

	while ((c = getopt (argc, argv, "i:s:")) != -1) {
		switch (c)
		{
			case 'i':					// input file arg
				input_filename = optarg;
				test_nbr_args++;
			break;
			case 's':					// Start address arg
				//start_address = optarg;
				start_address = (uint16_t)strtol(optarg, NULL, 16);
				test_nbr_args++;
			break;
			case '?':
				if ( (optopt == 'i') || (optopt == 'p'))
					fprintf (stderr, "Option -%c requires an argument.\n", optopt);
				else if (isprint (optopt))
					fprintf (stderr, "Unknown option `-%c'.\n", optopt);
				else
					fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
					return 1;
			default:
				abort ();
		}
	}

	if(test_nbr_args != 2) {
		printf("Usage: ram_upload -i inputfile.bin -s 8200\n");
		return 1;
	}

	input_file = fopen(input_filename,"rb");
	if (!input_file)
	{
		printf("Unable to open file %s", input_filename);
		return 1;
	}
	
	//Get file length
	fseek(input_file, 0, SEEK_END);
	file_length=ftell(input_file);
	fseek(input_file, 0, SEEK_SET);
	input_file_buffer=(uint8_t *)malloc(file_length+1);

	fread(input_file_buffer, file_length, 1, input_file);
	fclose( input_file );

	for(i=0;i!=file_length;i++) {
		printf("wa %04X,%02X\r\n", start_address, input_file_buffer[i]);
		start_address++;
	}

	return EXIT_SUCCESS;
}
