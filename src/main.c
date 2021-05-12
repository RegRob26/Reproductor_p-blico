/*
 * File: main.c
 * Ubication: src
 * Author: Emmanuel Guadalupe Robles Robles (rore021226@gs.utm.mx)
 * -----
 * Project name: Reproductor musical
 * -----
 * Modified By: Emmanuel Guadalupe Robles Robles (rore021226@gs.utm.mx>)
 * -----
 * Copyright 2021, Emmanuel Guadalupe Robles Robles, Universidad Tecnológica de la Mixteca
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#include "circular_lista.h"

int menu_principal();
int menu_editar();
int menu_reproducir();
int case_principal(int, Dlinked_list *dlinked_list, int);
int case_reproducir(int);
int case_editar(int, Dlinked_list *dlinked_list, int *);

int main()
{
    Dlinked_list *dlinked_list = create_dlinked_list();
    int opcion;
    int contador = 1;
    do
    {
        opcion = menu_principal();
        case_principal(opcion, dlinked_list, contador);

    } while (opcion != 3);
}

int menu_principal()
{
    int option;
    printf("\n\n\nMenú principal del reproductor\n");
    printf("\n1.Editar lista de reproducción");
    printf("\n2.Reproducir música");
    printf("\n3.Salir");
    printf("\nIngrear una opción:");
    scanf("%d", &option);
    return option;
}

int case_principal(int opcion, Dlinked_list *dlinked_list, int contador)
{
    int bandera_salida, exit;
    switch (opcion)
    {
    case 1:
        do
        {
            bandera_salida = menu_editar();
            exit = case_editar(bandera_salida, dlinked_list, &contador);
        } while (exit != 4);

        break;
    case 2:
        do
        {
            bandera_salida = menu_reproducir();
            exit = case_reproducir(bandera_salida);

        } while (exit != 4);

        break;
    case 3:
        break;
    default:
        printf("Reiniciando reproductor...\n");
        break;
    }
}

int menu_editar()
{
    int option;
    printf("\n\n\nMenú de Edición\n");
    printf("\n1.Insertar una canción");
    printf("\n2.Eliminar una canción");
    printf("\n3.Mostrar lista");
    printf("\n4.-Salir");
    printf("\nIngrear una opción:");
    scanf("%d", &option);
    return option;
}

int case_editar(int opcion, Dlinked_list *dlinked_list, int *contador)
{
    char cancion[100];
    char autor[100];
    char cancion2[100];
    char autor2[100];
    int anio;
    int item;
    fflush(stdin);

    item = (*contador);

    printf("%d\n", item);

    switch (opcion)
    {
    case 1:
        printf("Ingrese el nombre del autor: ");
        fflush(stdin);
        getchar();
        // fgets(autor, 100, stdin);
        gets(autor);
        strcpy(autor2, autor);

        printf("Ingrese el nombre de la canción: ");
        fflush(stdin);
        // fgets(cancion, 100, stdin);
        gets(cancion);
        strcpy(cancion2, cancion);

        printf("Ingrese el año de la canción: ");
        fflush(stdin);
        scanf("%d", &anio);

        insert(&dlinked_list->head, item, autor2, cancion2, anio);
        (*contador)++;
        break;
    case 2:
        printf("Ingrese el nùmero de la canciòn a eliminar: ");
        scanf("%d", &item);
        int del_node = delete_node(&dlinked_list->head, item);
        if (del_node == INT_MIN)
        {
            printf("Lista vacía (underflow)...");
        }
        else
        {
            if (del_node == INT_MAX)
            {
                printf("Elemento no fue encontrado...\n");
            }
            else
            {
                printf("Elemento eliminado correctamente...\n");
            }
        }
        break;
    case 3:
        display(dlinked_list);
        break;
    case 4:
        return 4;
        break;
    default:
        printf("Reiniciando menú de edición...\n");
        break;
    }
}

int menu_reproducir()
{
    int option;
    printf("\n\n\nMenú de reproducción\n");
    printf("\n1.-Play");
    printf("\n2.-Siguiente");
    printf("\n3.Anterior");
    printf("\n4.-Salir");
    printf("\nIngrear una opción:");
    scanf("%d", &option);
    return option;
}

int case_reproducir(int opcion)
{
    switch (opcion)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        return 4;
        break;
    default:
        printf("Reiniciando menú de reproducción...\n");
        break;
    }
}