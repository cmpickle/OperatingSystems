#include <stdio.h>
#include <stdlib.h>

int main() {
	int *ptr = malloc(sizeof(int) *100);
	free(ptr);
	printf("%d\n", ptr[50]);
	return 0;
}
