#include "./StackModule.h"
#include <stdio.h>
#include <stdlib.h>

struct Stack {
  int arr[MAX_ELEMENTOS];
  int cantElem;
};

Stack *InicializarPila() {

  Stack *stack = (Stack *)malloc(sizeof(Stack));
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
  if (stack.cantElem == 0)
    return 1;
  else
    return 0;
}

void Push(Stack *stack, int valor) {
  if (IsFull(*stack)) {
    printf("La pila está llena\n");
  } else {
    stack->arr[stack->cantElem] = valor;
    stack->cantElem++;
  }
}
int Pop(Stack *stack, int *valor) {

  if (IsEmpty(*stack)) {
    printf("La pila está vacía\n");
  } else {
    stack->cantElem--; // mover el puntero hacia el último valor válido
    *valor = stack->arr[stack->cantElem]; // leerlo
    stack->arr[stack->cantElem] = 0;
  }

  return 0;
}

StackItem Top(Stack *stack) {
  if (IsEmpty(*stack)) {
    printf("La pila está vacía\n");
    exit(EXIT_FAILURE); // o assert(0);
  }
  return stack->arr[stack->cantElem - 1];
}
