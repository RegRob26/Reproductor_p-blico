
#ifndef CIRCULAR_LISTA_H
#define CIRCULAR_LISTA_H

typedef struct node Node;

typedef struct dlinked_list Dlinked_list;

typedef char* Autor;
typedef char* Name_music;

struct node
{
    int data;
    Name_music name_music;
    Autor autor;
    int year;
    int contador;

    Node *next;
    Node *prev;
};

struct dlinked_list
{
    Node *head;
};



//hola
Dlinked_list *create_dlinked_list();
Node *create_node(int item,char autor[100], char cancion[100], int anio);
void destroy_dlinked_list(Node *dlinked_list);
void insert(Node **head, int item,char autor[100], char cancion[100], int anio);
int delete_node(Node **head, int item);
void display(Dlinked_list *dlinked_list);

#endif