#include <stdlib.h>

int main(void) {
	for (int i = 0; i < 1000; i++) (void)malloc(1);
}
