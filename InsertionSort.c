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


/* Insert a new node in a list. */ 
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

void Insertion_Sort(intlist** head_of_list){

    /* Begin a "sorted_list" from a NULL list, which will then be filled up with */
    /* elements from the input list in a sorted fashion */

    intlist* sorted_list = NULL;

    /* Keep track of the current node */

    intlist* current_node = *head_of_list;

    while(current_node != NULL){

        /* Store the pointer to the node after the current node */
        intlist* next_node = current_node->next;

        /* Insert a node to a linked list in a sorted fashion */
        Insert_sorted(&sorted_list, current_node);

        /* Change current to the node after current at the end of iteration */
        current_node = next_node;

    }

    /* At the end of this while loop a new linked list called "sorted_list" */
    /* will have all of its element sorted in an ascending order */
    /* The final step will be to point the head of the input list to "sorted_list." */

    *head_of_list = sorted_list;

}

int main() 
{ 
    intlist* a = cons(30, cons(6, cons(200, cons(9, cons(5, NULL))))); 
  
    printf("Linked List before sorting\n"); 
    print_list(a); 
  
    Insertion_Sort(&a); 
  
    printf("\nLinked List after sorting (in-place)\n"); 
    print_list(a);

    free_list(a); 
  
    return 0; 
} 



