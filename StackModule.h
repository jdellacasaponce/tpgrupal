#ifndef STACKMODULE_H
#define STACKMODULE_H
#define MAX_ELEMENTOS 100000

typedef int StackItem;
typedef struct Stack Stack;

Stack *InicializarPila();
/*
IsEmpty
Especificaciones: Corrobora que la pila se encuentra vacia
Pre condiciones: Que la pila este inicializada
Post condiciones: devuelve True si la pila esta vacia o False en caso contrario
*/
int IsEmpty(Stack pila);
/*
IsFull
Especificaciones: Corrobora que la pila se encuentre completa
Pre condiciones: que la pila este inicializada
Post condiciones: devuelve True si la pila esta llena o False en caso contrario
*/
int IsFull(Stack pila);
/*
Push
Especificaciones: Pone un valor en la cima de la pila
Pre condiciones: Que la pila este inicializada y que no se encuentre llena
Post condiciones: El elemento ingresado se posiciona en la cima de la pila
*/
void Push(Stack *pila, StackItem valor);
/*
Pop
Especificaciones: Retira el valor en la cima de la pila y se lo asigna a un
valor Pre condiciones: Que la pila este inicializada y que no se encuentre vacia
Post condiciones: Elimina el valor del tope de la pila y devuelve el valor
*/
int Pop(Stack *pila, StackItem *valor);

StackItem Top(Stack *stack);

#endif
