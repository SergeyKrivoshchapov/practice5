#include "WIFI.h"

#define ARRAY_SIZE 5

int main()
{
	const char* filename = "file.bin";
	WIFI routers[ARRAY_SIZE];
	WIFI odd_routers[ARRAY_SIZE / 2 + 1];

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		printf("\nRouter %d\n", i + 1);
		if (init_userdata(&routers[i]) == 1) return 1;
	}

	if (write_arraytofile(filename, routers, ARRAY_SIZE) == 1) return 1;
	
	int odd_count = read_oddfromfile(filename, odd_routers, ARRAY_SIZE);
	if (odd_count < 0) return 1;

	printf("odd elements of array:\n");
	for (int i = 0; i < odd_count; i++) print_struct(&odd_routers[i]);

	return 0;
}
