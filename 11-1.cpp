#include<stdio.h>
#include<stdlib.h>

// Copy source string to a new string
char* StringCopy(const char* source) {

	// Initalize size with 0
	int size = 0;

	// If string is NULL safely exit
	if (source == NULL) return NULL;

	// Calculate size by iterating till we find null terminator
	while (source[size] != '\0') {
		size++;
	}
	
	// Allocate memory for a new string
	// Allocate size + 1 blocks for a null terminator
	// Multiplied with size of char to get allocate according to char block
	char* str = (char*) malloc((size + 1)*sizeof(char));


	// If memory allocation fails safely exit
	if (str == NULL) {
		printf("Cannot allocate the memory %d bytes", (size + 1) * sizeof(char));
		return NULL;
	}

	// Copy the contents of source string to the new string
	for (int i = 0; i < size; i++) {
		str[i] = source[i];
	}
	
	// Add a null terminator at the end of the string
	// Null terminator used to explicitly mark the end of the string
	str[size] = '\0';

	return str;
}

int main() {

	// Dummy string
	char str[] = "Ayaan";

	// Copy the string to a new string using the function
	char *new_str = StringCopy(str);

	// Display and verify results
	printf("Original : %s\n", str);
	printf("New : %s\n", new_str);

	// Dummy string
	char str2[] = "Mooli\0";

	// Copy the string to a new string using the function
	char* new_str2 = StringCopy(str2);


	// Display and verify results
	printf("Original : %s\n", str2);
	printf("New : %s\n", new_str2);

	// Dummy string
	char str3[] = "";

	// Copy the string to a new string using the function
	char* new_str3 = StringCopy(str3);


	// Display and verify results
	printf("Original : %s\n", str3);
	printf("New : %s\n", new_str3);

	// free the allocated memory after use
	free(new_str);
	free(new_str2);
	free(new_str3);

}