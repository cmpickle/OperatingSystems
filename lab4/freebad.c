#include <stdlib.h>

int main() {
	int *ptr = malloc(sizeof(int) * 100);
	free(ptr+50);
	return 0;
}
