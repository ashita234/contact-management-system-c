#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[30], phone[15];
    struct node* next;
} Node;

Node* head = NULL;

void add() {
    Node* new = malloc(sizeof(Node));
    printf("Name: ");
    scanf("%s", new->name);

    printf("Phone: ");
    scanf("%s", new->phone);

    new->next = head;
    head = new;

    printf("Contact Added!\n");
}

void del() {
    char n[30];
    printf("Enter name to delete: ");
    scanf("%s", n);

    Node *cur = head, *prev = NULL;

    while (cur != NULL && strcmp(cur->name, n) != 0) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Contact not found!\n");
        return;
    }

    if (prev == NULL)
        head = cur->next;
    else
        prev->next = cur->next;

    free(cur);
    printf("Contact Deleted!\n");
}

void find() {
    char n[30];
    printf("Enter name to search: ");
    scanf("%s", n);

    Node* cur = head;

    while (cur != NULL && strcmp(cur->name, n) != 0) {
        cur = cur->next;
    }

    if (cur != NULL)
        printf("Found: %s - %s\n", cur->name, cur->phone);
    else
        printf("Contact not found!\n");
}

void list() {
    Node* cur = head;
    int i = 1;

    printf("\nContact List:\n");

    while (cur != NULL) {
        printf("%d. %s - %s\n", i, cur->name, cur->phone);
        cur = cur->next;
        i++;
    }
}

int main() {
    int ch;

    while (1) {
        printf("\n1.Add 2.Delete 3.Search 4.Display 0.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) add();
        else if (ch == 2) del();
        else if (ch == 3) find();
        else if (ch == 4) list();
        else if (ch == 0) break;
        else printf("Invalid choice!\n");
    }

    return 0;
}