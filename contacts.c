#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "contacts.txt"

typedef struct {
    int id;
    char name[30];
    char phone[20];
    int age;
} Contact;

// Prototypes
int loadContacts(Contact **contacts, int *capacity);
void saveContacts(Contact *contacts, int total);
void addContact(Contact **contacts, int *total, int *capacity, int *nextId);
void listContacts(Contact *contacts, int total);
void searchContact(Contact *contacts, int total);
void clearBuffer();
int containsSubstring(const char *text, const char *pattern);

int main() {
    Contact *contacts = NULL;
    int total = 0;
    int capacity = 0;
    int nextId = 1;
    int option = 0;

    // 1. Load from file. If file does not exist, start empty without failing
    total = loadContacts(&contacts, &capacity);

    // Calculate next id
    for (int i = 0; i < total; i++) {
        if (contacts[i].id >= nextId) {
            nextId = contacts[i].id + 1;
        }
    }

    do {
        printf("\n--- CONTACT LIST ---\n");
        printf("1. Add contact\n");
        printf("2. List contacts\n");
        printf("3. Search by name\n");
        printf("4. Save and exit\n");
        printf("Choose: ");
        if (scanf("%d", &option) != 1) {
            printf("Invalid input.\n");
            clearBuffer();
            option = 0;
            continue;
        }
        clearBuffer();

        switch (option) {
            case 1:
                addContact(&contacts, &total, &capacity, &nextId);
                break;
            case 2:
                listContacts(contacts, total);
                break;
            case 3:
                searchContact(contacts, total);
                break;
            case 4:
                saveContacts(contacts, total);
                printf("Saved. Bye!\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != 4);

    // 2. Free dynamic memory
    free(contacts);
    contacts = NULL;

    return 0;
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Custom strstr replacement - no string.h needed
// Returns 1 if pattern is inside text, 0 if not
int containsSubstring(const char *text, const char *pattern) {
    // Empty pattern matches everything
    if (pattern[0] == '\0') {
        return 1;
    }

    for (int i = 0; text[i] != '\0'; i++) {
        int j = 0;
        while (pattern[j] != '\0' && text[i + j] != '\0' && text[i + j] == pattern[j]) {
            j++;
        }
        if (pattern[j] == '\0') {
            return 1;
        }
    }
    return 0;
}

// Load from contacts.txt
int loadContacts(Contact **contacts, int *capacity) {
    FILE *f = fopen(FILE_NAME, "r");
    if (f == NULL) {
        // File does not exist, not an error. Start empty.
        printf("File %s not found, starting with empty list.\n", FILE_NAME);
        *capacity = 2;
        *contacts = malloc(*capacity * sizeof(Contact));
        if (*contacts == NULL) {
            printf("Error: could not allocate memory.\n");
            exit(1);
        }
        return 0;
    }

    int total = 0;
    *capacity = 2;
    *contacts = malloc(*capacity * sizeof(Contact));
    if (*contacts == NULL) {
        printf("Error: could not allocate memory.\n");
        fclose(f);
        exit(1);
    }

    Contact temp;
    // Validate fscanf return: must read 4 fields
    // %29s and %19s prevent overflow: leave 1 space for '\0'
    while (fscanf(f, "%d %29s %19s %d", &temp.id, temp.name, temp.phone, &temp.age) == 4) {
        // If full, grow with realloc
        if (total >= *capacity) {
            *capacity *= 2;
            Contact *newPtr = realloc(*contacts, *capacity * sizeof(Contact));
            if (newPtr == NULL) {
                printf("Error: could not reallocate memory.\n");
                fclose(f);
                free(*contacts);
                exit(1);
            }
            *contacts = newPtr;
        }
        (*contacts)[total] = temp;
        total++;
    }

    fclose(f);
    printf("Loaded %d contacts.\n", total);
    return total;
}

void saveContacts(Contact *contacts, int total) {
    FILE *f = fopen(FILE_NAME, "w");
    if (f == NULL) {
        printf("Error: could not open %s for writing.\n", FILE_NAME);
        return;
    }

    for (int i = 0; i < total; i++) {
        fprintf(f, "%d %s %s %d\n", contacts[i].id, contacts[i].name, contacts[i].phone, contacts[i].age);
    }

    fclose(f);
}

void addContact(Contact **contacts, int *total, int *capacity, int *nextId) {
    if (*total >= *capacity) {
        *capacity *= 2;
        Contact *newPtr = realloc(*contacts, *capacity * sizeof(Contact));
        if (newPtr == NULL) {
            printf("Error: could not reallocate memory.\n");
            return;
        }
        *contacts = newPtr;
    }

    Contact *newContact = &(*contacts)[*total];
    newContact->id = *nextId;

    printf("Name (no spaces, max 29): ");
    if (scanf("%29s", newContact->name) != 1) {
        printf("Error reading name.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    printf("Phone (max 19): ");
    if (scanf("%19s", newContact->phone) != 1) {
        printf("Error reading phone.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    printf("Age: ");
    if (scanf("%d", &newContact->age) != 1) {
        printf("Invalid age.\n");
        clearBuffer();
        return;
    }
    clearBuffer();

    (*total)++;
    (*nextId)++;
    printf("Contact added with id %d\n", newContact->id);
}

void listContacts(Contact *contacts, int total) {
    if (total == 0) {
        printf("No contacts.\n");
        return;
    }
    for (int i = 0; i < total; i++) {
        printf("%d | %s | %s | %d\n", contacts[i].id, contacts[i].name, contacts[i].phone, contacts[i].age);
    }
}

void searchContact(Contact *contacts, int total) {
    char search[30];
    printf("Name to search: ");
    if (scanf("%29s", search) != 1) {
        clearBuffer();
        return;
    }
    clearBuffer();

    int found = 0;
    for (int i = 0; i < total; i++) {
        // Custom contains: "Jos" finds "Josue"
        if (containsSubstring(contacts[i].name, search)) {
            printf("%d | %s | %s | %d\n", contacts[i].id, contacts[i].name, contacts[i].phone, contacts[i].age);
            found = 1;
        }
    }
    if (!found) {
        printf("No contact found with '%s'.\n", search);
    }
}