#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "circular_lista.h"

/**
 * Crear la lista ligada doble, head = NULL
 * */
Dlinked_list *create_dlinked_list()
{
    Dlinked_list *dlinked_list = (Dlinked_list *)malloc(sizeof(Dlinked_list));
    dlinked_list->head = NULL;
    return dlinked_list;
}

/**
 * Crear un nodo para ser agregado a la lista
 * */
Node *create_node(int item, Autor autor, Name_music cancion, int anio)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = item;
    new_node->autor = autor;

    new_node->next = new_node;
    // modificacion de Null a new node
    new_node->prev = new_node;
    return new_node;
}

void insert(Node **head, int item, Autor autor, Name_music cancion, int anio)
{
    Node *new_node = create_node(item, autor, cancion, anio);
    Node *aux = *head;
    // Caso 1. Si lista esta vacía
    if (*head == NULL)
    {
        //new_node->next = new_node; en crear
        *head = new_node;
    }
    else
    {
        // Caso 2. si el valor es menor al head
        printf("bug principal\n");
        if (new_node->data <= (*head)->data)
        {
            printf("Dato menor \n");
            new_node->next = *head;
            printf("bug -2\n");
            (*head)->prev = new_node;
            printf("bug -1\n");

            if ((*head)->next == *head)
            {
                (*head)->next = new_node;
                new_node->prev = *head;
            }
            else
            {
                while (aux->next != *head)
                {
                    printf("bug\n");
                    aux = aux->next;
                }
                 aux->next = new_node;
                  new_node->prev = aux;
            }
            printf("bug 0\n");
            *head = new_node;
        }
        else
        {
            // Caso 3. colocar el nuevo nodo al final de la lista
            while ((aux->next != *head) && (aux->next->data < new_node->data))
            {
                aux = aux->next;
            }
            new_node->next = aux->next;
            aux->next = new_node;
            new_node->prev = aux;
            if (new_node->next != *head)
                new_node->next->prev = new_node;
            else
                (*head)->prev = new_node;

        }
    }
}

int delete_node(Node **head, int item)
{
    Node *aux;
    int data = INT_MIN;
    // verficar que la lista no esta vacia
    if (*head == NULL)
    {
        data = INT_MIN;
    }
    else
    {
        //caso 1 se desea eliminar el nodo que esta en head
        if ((*head)->data == item)
        {
            // vericar si head esta apuntado hacia NULL
            if ((*head)->next == *head)
            {
                data = (*head)->data;
                free(*head);
                *head = NULL;
            }
            else
            {
                // Donde hay más un nodo
                aux = *head;
                *head = (*head)->next;
                (*head)->prev = aux->prev;
                (*head)->next = aux->next;
                aux->next = NULL;
                data = aux->data;
                free(aux);
            }
        }
        else
        {
            //caso 2 y 3se desea eliminiar el último nodo o un nodo intermedio
            Node *prev = *head;
            while ((prev->next != *head) && (prev->next->data != item))
            {
                prev = prev->next;
            }
            if (prev->next->data == item)
            {
                Node *ax = prev->next;
                prev->next = ax->next;

                if (prev->next == *head)
                {
                    (*head)->prev = ax->prev;
                }
                else
                    ax->next->prev = prev;

                data = ax->data;
                free(ax);
            }
            else
            {
                data = INT_MAX;
            }
        }
    }
    return data;
}

void display(Dlinked_list *dlinked_list)
{
    Node *temp;

    if (dlinked_list->head != NULL)
    {
        temp = dlinked_list->head;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != dlinked_list->head);
    }
}

void reproducir(Dlinked_list *dlinked_list){
    
    printf("Canción: %s", dlinked_list->head->name_music);
}