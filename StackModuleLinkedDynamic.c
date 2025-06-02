#include "StackModule.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct StackNodo *pNodo; // alias para puntero al tipo StackNodo

// defino la estructura de un nodo con su información y el puntero al nodo que
// lo precede
struct StackNodo {
  int info;
  pNodo anterior;
};

struct Stack {
  pNodo raizPila;
  int cantElem;
};

Stack *InicializarPila() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->raizPila = NULL;
  stack->cantElem = 0;
  return stack;
}

int IsFull(Stack stack) {
  if (stack.cantElem == MAX_ELEMENTOS)
    return 1;
  else
    return 0;
}

int IsEmpty(Stack stack) {
  if (stack.raizPila == NULL)
    return 1;
  else
    return 0;
}

// Push tiene que recibir el puntero a la pila (raíz) por referencia y el valor
// a agregar por valor
void Push(Stack *stack, int valor) {
  if (IsFull(*stack))
    printf("La pila está llena\n");
  else {
    pNodo nodo = NULL;
    nodo = (pNodo)malloc(sizeof(struct StackNodo));
    nodo->info = valor;
    nodo->anterior = stack->raizPila;
    stack->raizPila = nodo;
    stack->cantElem++;
  }
}
// Creo un puntero al nuevo nodo.
// Luego reservo memoria en el Heap.
// Le asigno el valor y le paso el contenido de lo que apunta el puntero a raíz
// (otro puntero) Finalmente, el contenido de Raíz pasa a apuntar al nuevo nodo

// Pop recibe el puntero raíz por referencia y el valor a sacar por referencia
int Pop(Stack *stack, int *valor) {
  if (IsEmpty(*stack))
    printf("La pila está vacía\n");
  else {
    pNodo pElim = NULL;
    pElim = stack->raizPila;
    *valor = pElim->info;
    stack->raizPila = pElim->anterior;
    stack->cantElem--;
    free(pElim);
    // printf("POP: %d\n", *valor);
  }

  return 0;
}
// Creo un puntero para el nodo a eliminar
// Lo hago apuntar a lo mismo que raíz
// el cotenido del puntero a valor pasa a ser la info de lo que apunta pElim
// Raíz pasa a apuntar al anterior nodo
// libero a pElim
// printeo el valor que sale

StackItem Top(Stack *stack) {
  if (IsEmpty(*stack)) {
    printf("La pila está vacía\n");
    exit(EXIT_FAILURE); // o assert(0);
  }
  return stack->raizPila->info;
}
