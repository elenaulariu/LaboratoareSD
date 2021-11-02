#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

typedef int T;

typedef struct ListNode {
    struct ListNode *next; // pointer catre nodul urmator
    struct ListNode *prev; // pointer catre nodul precedent
    T value;
} ListNode;

typedef struct List {
    ListNode *head; // pointer catre primul nod din lista
    ListNode *tail; // pointer catre ultimul nod din lista
} List;

// Initializeaza o lista dublu inlantuita. (0.5 puncte)
List *init_list();

// Returneaza 1 daca lista este goala, 0 in caz contrar. (0.5 puncte)
int is_empty(List *list);

// Returneaza 1 daca elementul se afla in lista, sau 0 in caz contrar. (1 punct)
int contains(List *list, T value);

// Returneaza lungimea listei (1 punct)
int get_length(List *list);

// Insereaza un nou element la finalul listei. (1 punct)
void insert(List *list, T value);

// Insereaza un nou element astfel incat lista sa ramana in continuare sortata. (2 puncte)
void insert_in_order(List *list, T value);

// Sterge si dezaloca din memorie prima aparitie a unui element din lista. (1 punct)
void delete(List *list, T value);

// Sterge si dezaloca din memorie toate elementele din lista. (1 punct)
void destroy_list(List *list);

// Primeste o lista sortata si afiseaza toate perechile de numere a caror suma 
// este egala cu valoare data. Lista va avea toate elementele distincte. (2 puncte)
void find_pairs_given_sum(List *list, T x);

// Afiseaza elementele din lista.
void print_list(List *list);

// Afiseaza elementele din lista in ordine inversa. 
void print_list_reversed(List *list);

#endif
