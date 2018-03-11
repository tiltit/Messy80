/**
 * messy80_get_labels
 * 
 */

// ; +++ defined symbols +++

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <stdint.h>
#include <getopt.h>
#include <ctype.h>


int main(int argc,char** argv)
{
	int c;
	char *input_filename = NULL;
	unsigned char s[1024];
	FILE *input_file;
	int test_nbr_args = 0;

	while ((c = getopt (argc, argv, "i:")) != -1) {
		switch (c)
		{
			case 'i':
				input_filename = optarg;
				test_nbr_args++;
			break;
			case '?':
				if ( (optopt == 'i') )
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

	if(test_nbr_args != 1) {
		printf("Usage: messy80_get_labels -i program.log\n");
		return 1;
	}

	input_file = fopen(input_filename,"r");
	if (!input_file)
	{
		printf("Unable to open file %s", input_filename);
		return 1;
	}


	//

	while (fgets(s, 1024, input_file) != NULL) {
        if(strstr(s, "; +++ defined symbols +++") != NULL) {
    		break;
		}
	}

	while (fgets(s, 1024, input_file) != NULL) {
		if(s[1] != '_') {
        	printf("%s", (s + 1));
		}
	}

    fclose(input_file);

	
	return EXIT_SUCCESS;
}
