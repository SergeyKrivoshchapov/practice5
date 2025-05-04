#include "WIFI.h"

int main()
{
	const char* filename = "file.bin";
	WIFI router1;
	
	if (init_userdata(&router1) == 1) return 1;
	if (write_tofile(filename, &router1) == 1) return 1;

	WIFI router2;
	if (read_fromfile(filename, &router2) == 1) return 1;

	print_struct(&router2);

	return 0;
}
