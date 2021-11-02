#include "double_linked_list.h"

#include <stdio.h>
#include <stdlib.h>

// Initializeaza o lista dublu inlantuita. (0.5 puncte)
List *init_list() {
    List *list=malloc(sizeof(List));
    list->head=NULL;
    list->tail=NULL;
    return list;
    return NULL;
}

// Returneaza 1 daca lista este goala, 0 in caz contrar. (0.5 puncte)
int is_empty(List *list) {
    if(list->head==NULL && list->tail==NULL)
        return 1;
    return 0;
}

// Returneaza 1 daca elementul se afla in lista, sau 0 in caz contrar. (1 punct)
int contains(List *list, T value) {
    ListNode *temp=list->head;
    while(temp!=NULL) {
        if(temp->value==value)
            return 1;
        temp=temp->next;
    }
    return 0;
}

// Returneaza lungimea listei (1 punct)
int get_length(List *list) {
    int length=0;
    ListNode *current=list->head;
    while (current!=NULL) {
        length++;
        current=current->next;
    }
    if (length)
        return length;
    return 0;
}

// Insereaza un nou element la finalul listei. (1 punct)
void insert(List *list, T value) {
    ListNode *newNode = malloc (sizeof(ListNode));
    newNode->value=value;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(list->head==NULL && list->tail==NULL) {
        list->head=newNode;
        list->tail=newNode;
    }
    else {
        newNode->prev=list->tail;
        list->tail->next=newNode;
        list->tail=newNode;
    }

}

// Insereaza un nou element astfel incat lista sa ramana in continuare sortata. (2 puncte)
void insert_in_order(List *list, T value) {
    ListNode *newNode = malloc (sizeof(ListNode));
    newNode->value=value;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(list->head==NULL && list->tail==NULL) {
        list->head=newNode;
        list->tail=newNode;
    }
    else {
        if(list->head->value>newNode->value) {
            newNode->next=list->head;
            newNode->next->prev=newNode;
            list->head=newNode;
        }
        else if(list->tail->value<newNode->value) {
            newNode->prev=list->tail;
            newNode->prev->next=newNode;
            list->tail=newNode;
        }
            else {
                ListNode *current=list->head;
                while(current->next!=NULL && current->next->value<newNode->value)
                    current=current->next;
                newNode->next=current->next;
                newNode->next->prev=newNode;
                current->next=newNode;
                newNode->prev=current;
            }
    }
}

// Sterge si dezaloca din memorie prima aparitie a unui element din lista. (1 punct)
void delete(List *list, T value) {
    ListNode *temp;
    if(list->head->value==value) {
        temp=list->head;
        list->head=list->head->next;
        list->head->prev=NULL;
        free(temp);
    }
    else {
        ListNode *curent = list->head;
        while(curent->next!=NULL) {
            if(curent->next->value==value) {
                if(curent->next==list->tail) {
                    temp=list->tail;
                    list->tail->next=NULL;
                    curent->next=NULL;
                    list->tail=list->tail->prev;
                    free(temp);
                    break;
            }
            else {
                temp=curent->next;
                curent->next=curent->next->next;
                curent->next->prev=curent;
                free(temp);
                break; }
            }
            else curent=curent->next;
        }
    }
}

// Sterge si dezaloca din memorie toate elementele din lista. (1 punct)
void destroy_list(List *list) {
    ListNode *temp;
    while(list->head!=NULL) {
        if(list->head==list->tail) {
            temp=list->tail;
            list->tail=NULL;
            list->head=NULL;
            free(temp);
        }
        else{
            temp=list->head;
            list->head=list->head->next;
            free(temp); }
    }
}

// Primeste o lista sortata si afiseaza toate perechile de numere a caror suma 
// este egala cu valoare data. Lista va avea toate elementele distincte. (2 puncte)
void find_pairs_given_sum(List *list, T x) {
    ListNode *first=list->head, *last=list->tail;
    while(first->value<last->value) {
        if(first->value+last->value==x){
            printf("(%d, %d)", first->value, last->value);
            first=first->next;
            last=last->prev;
        }
        else if(first->value+last->value<x) {
            first=first->next;
        }
        else last=last->next;
    }
}

void print_list(List *list) {
    for (ListNode *it = list->head; it != NULL; it = it->next) {
        printf("%d->", it->value);
    }
    printf("NULL\n");
}

void print_list_reversed(List *list) {
    for (ListNode *it = list->tail; it != NULL; it = it->prev) {
        printf("%d->", it->value);
    }
    printf("NULL\n");
}

int main() {
    List *list = init_list();

    ///////////////// IS_EMPTY /////////////////
    printf("Test 1 (is_empty): %d\n", is_empty(list)); // Should be 1

    // ///////////////// INSERT /////////////////
    insert(list, 1);
    insert(list, 20);
    insert(list, 2);
    insert(list, 10);
    insert(list, 5);
    printf("Test 2 (is_empty): %d\n\n", is_empty(list)); // Should be 0

    printf("Test 3 (insert):");
    print_list(list); // 1->20->2->10->5->NULL

    printf("Test 4 (insert):");
    print_list_reversed(list); // 5->10->2->20->1->NULL 
    printf("\n");

    // ///////////////// CONTAINS /////////////////
    printf("Test 5 contains(list, 2): %d\n", contains(list, 2)); // Should be 1
    printf("Test 6 contains(list, 22): %d\n\n", contains(list, 22)); // Should be 0

    // ///////////////// GET_LENGTH /////////////////
    printf("Test 7 get_length(list): %d\n\n", get_length(list)); // Should be 5
    print_list_reversed(list);
    // ///////////////// DELETE /////////////////
    printf("Test 8 delete(list, 1):");
    delete(list, 1); 
    print_list(list); // 20->2->10->5->NULL
    printf("Test 9 delete(list, 2): ");
    delete(list, 2);
    print_list(list); // 20->10->5->NULL
    printf("Test 10 delete(list, 5):");
    delete(list, 5);
    print_list(list); // 20->10->NULL
    print_list_reversed(list); // 10->20->NULL
    printf("\n");

    // ///////////////// DELETE_ALL /////////////////
    printf("Test 11 destroy_list(list):");
    destroy_list(list);
    print_list(list); // NULL
    print_list_reversed(list); // NULL
    printf("\n");
    free(list);
    // ///////////////// INSERT_IN_ORDER /////////////////
    List *sorted_list = init_list();
    insert_in_order(sorted_list, 9);
    insert_in_order(sorted_list, 7);
    insert_in_order(sorted_list, 6);
    insert_in_order(sorted_list, 4);
    insert_in_order(sorted_list, 1);
    insert_in_order(sorted_list, 5);
    insert_in_order(sorted_list, 11);
    insert_in_order(sorted_list, 2);
    insert_in_order(sorted_list, 3);
    printf("Test 12 insert_in_order:");
    print_list(sorted_list); // 1->2->3->4->5->6->7->9->11->NULL
    print_list_reversed(sorted_list); // 11->9->7->6->5->4->3->2->1->NULL
    destroy_list(sorted_list);
    // ///////////////// FIND_PAIRS_GIVEN_SUM /////////////////
    printf("Test 13 find_pairs_given_sum(list, 14): ");
    //find_pairs_given_sum(sorted_list, 14); // (3, 11), (5, 9)

    return 0;
}
