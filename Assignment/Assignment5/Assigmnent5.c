
  
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// A program that creates a linked List from an array 
// and adds, deletes and sorts the linked list

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *previous;
} Node;

// Headers
Node* create_dll_from_array(int array[], int size);
void print_dll(Node* head);
void insert_after(Node* head, int valueToInsertAfter, int valueToBeInserted);
void delete_element(Node* head, int valueToBeDeleted);
void sort_dll(Node* head);
void swap(Node* prev, Node* current);
void memoryLeak(Node* head);


int main()
{
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
 /* Question 5 */
 sort_dll(head);
 print_dll(head);
 /* Question 6 */
 // add the call to your function here
 memoryLeak(head);
 return 0;
}

// Create the List from the array
Node* create_dll_from_array(int array[], int size){
    int i;
    Node *head;
    Node *current;
    Node *temp;


    head = malloc(sizeof(Node));
    head->next = NULL;
    head->previous = NULL;
    current = head;

    if (size == 0){  
        return head;
    }
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

// Print the linked List
void print_dll(Node* head){
    Node* current = head;
    while (current != NULL) {

        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}

// Insert an element after the desired one
void insert_after(Node* head, int valueToInsertAfter, int valueToBeInserted){

    Node *new_Node;
    Node *current;
    new_Node = malloc(sizeof(Node));
    current = malloc(sizeof(Node));

    new_Node->data = valueToBeInserted;
    new_Node->next = NULL;
    new_Node->previous = NULL;
    current = head;

    while (current != NULL){
        if (current->data == valueToInsertAfter && current->next !=NULL) {
            new_Node->next = current->next;
            new_Node->previous = current->next->previous;
            current->next->previous = new_Node;
            current->next = new_Node;
            return;

        }
        if (current->data == valueToBeInserted && current->next == NULL){
            current->next = new_Node;
            new_Node->previous = current;
            new_Node->next = NULL;
        }
        if (current->data != valueToBeInserted && current->next == NULL){
            current->next = new_Node;
            new_Node->previous = current;
            new_Node->next = NULL;
            return;
        }
    current = current->next;
    }
    free(new_Node);
    free(current);
}

void delete_element(Node* head, int valueToBeDeleted){
    Node *current;
    current = head;
    // First element edge case
    if (head->data == valueToBeDeleted){
        current = head->next;
        head->data = current->data;
        head->next = current->next;
        current->next->previous = head;
        return;
    }
        while (current != NULL){
            // Not first nor last element
            if (current->data == valueToBeDeleted && current->next != NULL && current->previous !=NULL){

                current->next->previous = current->previous;
                current->previous->next = current->next;
                return;
            }
            // Last element edge case
            if (current->data == valueToBeDeleted && current->next == NULL){

                current->previous->next = NULL;
                current->previous = NULL;
                return;
            }
            if (current->data == valueToBeDeleted && head->next == NULL && head->previous == NULL) {
                free(current);
                return;
            }
    current = current->next;
    }
}

// Bubble sorting code
void sort_dll(Node* head){
    Node* current;
    Node* pointer;
    pointer = head;
    while (pointer != NULL){
        current = head;
        while (current->next != NULL){
            if (current->data > current->next->data){
                swap(current, current->next);
            }
            current = current->next;
        }
        pointer = pointer->next;
    }
}

void swap(Node* prev, Node* current){
    int temp;
    temp = current->data;
    current->data = prev->data;
    prev->data = temp;   
}

void memoryLeak(Node* head){
    /* Memory leak occurs when the program creates a memory and doesnt
     delete that memory to free it for other cases. So to prevent that,
     must free all the instance of malloc created (head node)*/
    Node *temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}