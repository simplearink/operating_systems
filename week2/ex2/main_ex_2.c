#include <stdio.h>
#include <string.h>
#define buffer_size 1024

char * reversed(char string[]) {
	int length = strlen(string);
	static char reverse_string[buffer_size];
	for (int i = 0; i <= length - 1; i++) {
		reverse_string[length - 1 - i] = string[i];
	}

	return reverse_string;
}

int main() {
	char str[buffer_size];
	printf("Print the string:\n");
	scanf("%s", str);

	printf("%s\n", reversed(str));

	return 0;
}
