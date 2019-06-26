#include <stdio.h>
#include <stdlib.h>

int main() {
	char ch, file_name[25];
	FILE *fptr;

	printf("Enter file name: \n");
	gets(file_name);

	fptr = fopen(file_name, "r");

	if(fptr == NULL) {
		printf("Error!");
		exit(1);
	}

	else {
		while((ch = fgetc(fptr)) != EOF)
			printf("%c", ch);
	}
	fclose(fptr);

	return 0;
}
