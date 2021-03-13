#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Define Linked List node */

typedef struct intlist_t{
    int data;
    struct intlist_t* next;
} intlist;

/* How to add a node */

intlist* cons(int h, intlist* t){
    intlist* res;
    res = malloc(sizeof(intlist));

    res->data = h;
    res->next = t;

    return res;
}

/* Free a linked list */

void free_list(intlist* t){

    intlist* temp;
    while (t != NULL){
        temp = t;
        t = t->next;
        free(temp);
    } 
}

/* Print a linked list */

void print_list(intlist* t){

    intlist* temp = t;
    printf("[ ");
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

/* Calculate the length of the list recursively */
int list_length(intlist* t){

    if(t == NULL){
        return 0;
    }
    else{
        return 1 + list_length(t->next);
    }
    
}

/* function to insert a new_node in a list. */ 
/* Note that this function expects a pointer */
/* to the head of the linked list as this can */
/* modify the head of the input linked list */

void Insert_sorted(intlist** head_node, intlist* new_node){

    intlist* current;

    /* if the linked list is empty then make the new node as the head node */
    /* if the new node data is smaller than the head node data */
    /* then insert the new node before the head node and make it the head */ 

    if (*head_node == NULL || (*head_node)->data >= new_node->data){

        new_node->next = *head_node;
        *head_node = new_node;

    }
    else{

        current = *head_node;
        
        /* Loop through the entire linked list to find the appropriate node */

        while(current->next != NULL && new_node->data >= current->next->data){

            current = current->next;

        }

        /* Now insert the new node at the appropriate location */
        /* The new node is pointing to the next node */
        /* The current node is pointing to the new node */
        new_node->next = current->next;
        current->next = new_node;

    }

}                                 


int main(){

    intlist* a = NULL;
    intlist* b = cons(5, NULL);

    Insert_sorted(&a, b);

    printf("\nNow we add the first element\n");
    print_list(a);

    intlist* c = cons(10,NULL);

    Insert_sorted(&a, c);

    printf("\nNow we add 10 to the list\n");
    print_list(a);

    intlist* d = cons(1, NULL);

    Insert_sorted(&a, d);

    printf("\nNow we add 1 to the list\n");
    print_list(a);

    intlist* e = cons(100, NULL);

    Insert_sorted(&a, e);

    printf("\nNow we add 100 to the list\n");
    print_list(a);

    intlist* f = cons(20, NULL);

    Insert_sorted(&a, f);

    printf("\nNow we add 20 to the list\n");
    print_list(a);

    printf("\nIt can be seen that the elements are added to list in a sorted way\n");
 
    free_list(a);

    return 0;

}