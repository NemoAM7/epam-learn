#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

// Struct for contact
struct Contact {
	char name[50];
	char phone[20];
};

// Returns 1 if number is a power of two
int isPowerOfTwo(int number) {
  return (((number - 1) & number) == 0);
}


// Dynamically adds a contact, uses dynamic array logic for optimized queries
struct Contact* addContact(struct Contact* contacts_array, int* current_size, const struct Contact* new_contact) {
	
	// If size is zero allocate memory for a single contact
	if (*current_size == 0) {
		struct Contact* temp = (struct Contact*)malloc(sizeof(struct Contact));
		
		// Handling null allocation
		if (temp == NULL) {
			return contacts_array;
		}
		contacts_array = temp;
	}


  // If array elements reaches a power of two, double the array size
	else if (isPowerOfTwo(*current_size)) {
	  
	  // new size
		int newSize = *current_size * 2;
		
		// reallocate memory for new elements
		struct Contact* temp = (struct Contact*)realloc(contacts_array, newSize * sizeof(struct Contact));
		
		// Handling null allocation
		if (temp == NULL) {
			return contacts_array;
		}
		contacts_array = temp;
	}
	
	// Add new contact
	contacts_array[*current_size] = *new_contact;
	
	// Update size
	(*current_size)++;

	return contacts_array;
}


// Print a specific contact
void printContact(struct Contact contact){
  printf("%s : %s\n", contact.name, contact.phone);
}


// Search for a contact by name
struct Contact* findContact(const struct Contact* contacts_array, int current_size, const char* search_name){
  for(int i = 0; i < current_size; i++){
    if(strcmp(contacts_array[i].name, search_name) == 0){
      return &contacts_array[i];
    }
  }
  
  return NULL;
}


// Print all contacts
void displayAllContacts(const struct Contact* contacts_array, int current_size){
  for(int i = 0; i < current_size; i++){
    printContact(contacts_array[i]);
  }
}


// Clean up contacts after use
void cleanupContacts(struct Contact** contacts_array, int* current_size){
  printf("Freed up space!");
  free(*contacts_array);
  *contacts_array = NULL;
  *current_size = 0;
}

int main() {
  
  // Max size for contacts
  const int MAX_SIZE = 4;
  
  // Dummy values
	char names[4][40] = { "A", "B", "C", "D"};
	char phones[4][40] = { "9", "8", "7", "6" };

  // Declare contact array and size
	struct Contact* contact_array = NULL;
	int size = 0;

  // Loop to populate contact array
	for (int i = 0; i < MAX_SIZE; i++) {
    struct Contact new_contact;
		strcpy(new_contact.name, names[i]);
		strcpy(new_contact.phone, phones[i]);
		contact_array = addContact(contact_array, &size, &new_contact);
	}
	
	// Displaying and verify results from contact array
	displayAllContacts(contact_array, size);
	
	// Search for specific contact_array
	struct Contact* searched = findContact(contact_array, size, "E");
	
	if(searched == NULL) {
	  printf("contact not found\n");
	} else {
	  printf("contact found\n");
	  printContact(*searched);
	}
	
	// Clean up contacts after use
	cleanupContacts(&contact_array, &size);
}