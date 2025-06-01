#ifndef STACKMODULE_H
#define STACKMODULE_H

#include <stdbool.h>

typedef int StackItem;
typedef struct StackNodo* tPila;

/*
isEmpty
Especificaciones: Corrobora que la pila se encuentra vacia
Pre condiciones: Que la pila este inicializada
Post condiciones: devuelve True si la pila esta vacia o False en caso contrario
*/
bool isEmpty(tPila* pila);
/*
isFull
Especificaciones: Corrobora que la pila se encuentre completa
Pre condiciones: que la pila este inicializada 
Post condiciones: devuelve True si la pila esta llena o False en caso contrario
*/
bool isFull(tPila* pila);
/*
push
Especificaciones: Pone un valor en la cima de la pila
Pre condiciones: Que la pila este inicializada y que no se encuentre llena
Post condiciones: El elemento ingresado se posiciona en la cima de la pila
*/
void push(tPila* pila, StackItem valor);
/*
pop
Especificaciones: Retira el valor en la cima de la pila y se lo asigna a un valor
Pre condiciones: Que la pila este inicializada y que no se encuentre vacia
Post condiciones: Elimina el valor del tope de la pila y devuelve el valor
*/
int pop(tPila* pila, StackItem* valor);
/*
clear
Especificaciones: Vacia completamente la pila
Pre condiciones: Que la pila este inicializada
Post condiciones: Queda liberado todo el espacio de la pila
*/
void clear(tPila* pila);

#endif
