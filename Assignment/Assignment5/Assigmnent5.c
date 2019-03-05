#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *previous;
} Node;


Node* create_dll_from_array(int array[], int size);
void print_dll(Node* head);
void insert_after(Node* head, int valueToInsertAfter, int valueToBeInserted);
void delete_element(Node* head, int valueToBeDeleted);


int main(){
    int array[5] = {11, 2, 7, 22, 4};
    Node* head;
    /* Question 1 */
    head = create_dll_from_array(array, 5); //size of array is 5
    /* Question 2 */
    print_dll(head);
    /* Question 3 */
    // To insert 13 after the first occurence of 7
    insert_after(head, 7, 13);
    // To insert 29 after the first occurence of 21
    insert_after(head, 21, 29);
    print_dll(head);
    /* Question 4 */
    delete_element(head, 22);
    print_dll(head);
    delete_element(head, 11);
    print_dll(head);
    return 0;
}

Node* create_dll_from_array(int array[], int size){
    int i;
    Node *head;
    Node *current;
    Node *temp;

    head = malloc(sizeof(Node));
    head->next = NULL;
    head->previous = NULL;
    current = head;

    for ( i = 0; i < size; i++){
        temp = current;
        current->next = malloc(sizeof(Node));
        current = current->next;
        current->data = array[i];
        current->previous = temp;

        if (i == 0) {
            head = current;
        }
    }
    current = head;
    return head;
}

void print_dll(Node* head){
    Node* current = head;
    // printf("%d\n", current->next->data);
    while (current != NULL) {

        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}

void insert_after(Node* head, int valueToInsertAfter, int valueToBeInserted){
    // Create a New Node

    Node *new_Node;
    Node *current;
    new_Node = malloc(sizeof(Node));
    current = malloc(sizeof(Node));

    new_Node->data = valueToBeInserted;
    new_Node->next = NULL;
    new_Node->previous = NULL;
    current = head;

    while (current != NULL){
        if (current->data == valueToInsertAfter) {

            new_Node->next = current->next;
            new_Node->previous = current->next->previous;
            current->next->previous = new_Node;
            current->next = new_Node;
            return;
        }
        current = current->next;
    }
    free(new_Node);
    free(current);
    printf("insert case\n");
}

void delete_element(Node* head, int valueToBeDeleted){
    Node *current = malloc(sizeof(Node));
    current = head;
        while (current != NULL){
            // First element edge case
            if (head->data == valueToBeDeleted){
                
                printf("First Case\n");

                head->data = head->next->data;
                head->next = head->next->next;
                current = head->next->next;
                current->previous = head;
                // free(current);
                
                return;
            }

            // Not first nor last element
            if (current->data == valueToBeDeleted && current->next != NULL && current->previous !=NULL){
                printf("second Case\n");

                current->next->previous = current->previous;
                current->previous->next = current->next;
                free(current);
                return;
            }

            // Last element edge case
            if (current->data == valueToBeDeleted){

                printf("Third case\n");
                current->previous->next = NULL;

                free(current);
                return;
            }
    current = current->next;
    }
}