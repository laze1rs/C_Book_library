#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Books {
    char name[50], autor[20];
    char status;
    int year; 

    struct Books* next;

} Books;

int main() {
    Books* head = NULL;
    char choose_status;

    while (1) {
        printf("Please, choose an option.\n1 - Add book to library.\n2 - Show my books.\n3 - Exit");
        scanf(" %c", &choose_status);
        if (choose_status == '1') {
            Books* new_book = malloc(sizeof(Books));
            if (new_book == NULL) {
                printf("Memory Error\n");
                continue;
            }
            printf("Enter name for book: ");
            getchar();
            fgets(new_book->name, sizeof(new_book->name), stdin);
            new_book->name[strcspn(new_book->name, "\n")] = 0;

            printf("Enter autor for new book: ");
            fgets(new_book->autor, sizeof(new_book->autor), stdin);
            new_book->autor[strcspn(new_book->autor, "\n")] = 0;

            new_book->next = head;
            head = new_book;
            printf("Book added successfully!\n");
        } else if (choose_status == '2') {
            Books* current = head;
            printf("Your books:\n");
            while (current != NULL) {
                printf("Name: %s, Author: %s\n", current->name, current->autor);
                current = current->next;
            }
        } else if (choose_status == '3'){
            Books* current = head;
            while (current != NULL) {
                Books* tmp = current;
                current = current->next;
                free(tmp);
            }
            printf("Exiting programm...\n");
            break;
        } else {
            printf("Unknown choise!\n");
        }
    }
    return 0;
}





