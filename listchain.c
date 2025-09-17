#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;


Node* create_node(int value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}



Node* create_list(int n) {
    if (n <= 0) return NULL;

    Node* head = create_node(1);
    Node* current = head;

    for (int i = 2; i <= n; i++) {
        current->next = create_node(i);
        current = current->next;
    }

    return head;
}


void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}


void free_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* tmp = current;
        current = current->next;
        free(tmp);
    }
}
//fonction qui ne marche pas
int list_length(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    int n = 10;
    Node* list = create_list(n);
    print_list(list);
    printf("%d",list_length(list));
    free_list(list);
    printf("%d",list_length(list));
    return 0;
}
