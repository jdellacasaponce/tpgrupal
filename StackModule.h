#ifndef STACKMODULE_H
#define STACKMODULE_H

#include <stdbool.h>

typedef int StackItem;
typedef struct StackNodo* tPila;

/*
inicializarPila
Especificaciones: inicializa la pila
Pre condiciones: que exista la pila
Post condiciones: deja la pila inicializada
*/
void inicializarPila(tPila* pila);
/*
IsEmpty
Especificaciones: Corrobora que la pila se encuentra vacia
Pre condiciones: Que la pila este inicializada
Post condiciones: devuelve True si la pila esta vacia o False en caso contrario
*/
bool IsEmpty(tPila* pila);
/*
isFull
Especificaciones: Corrobora que la pila se encuentre completa
Pre condiciones: que la pila este inicializada 
Post condiciones: devuelve True si la pila esta llena o False en caso contrario
*/
bool IsFull(tPila* pila);
/*
push
Especificaciones: Pone un valor en la cima de la pila
Pre condiciones: Que la pila este inicializada y que no se encuentre llena
Post condiciones: El elemento ingresado se posiciona en la cima de la pila
*/
void Push(tPila* pila, StackItem valor);
/*
pop
Especificaciones: Retira el valor en la cima de la pila y se lo asigna a un valor
Pre condiciones: Que la pila este inicializada y que no se encuentre vacia
Post condiciones: Elimina el valor del tope de la pila y devuelve el valor
*/
int Pop(tPila* pila, StackItem* valor);

#endif
