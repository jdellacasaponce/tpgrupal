#include <stdlib.h>
#include <stdio.h>

#define MAX_ELEMENTOS 100

typedef struct
{
    int arr[MAX_ELEMENTOS];
    int cantElem;
}Stack;




Stack* InicializarPila(){
    
    Stack* stack =(Stack*)malloc(sizeof(Stack));
    for (int i = 0; i < MAX_ELEMENTOS; i++)
    {
        stack->arr[i]=0;
    }
    stack->cantElem=0;
    return stack;
    
}

int IsFull(Stack stack){
    if (stack.cantElem == MAX_ELEMENTOS)
        return 1;
    else
        return 0;
    
}

int IsEmpty(Stack stack){
    if (stack.cantElem == 0)
        return 1;
    else
        return 0;
}

void Push(Stack* stack, int valor){
    if (IsFull(*stack)){
        printf("La pila está llena\n");
    }else{
        stack->arr[stack->cantElem] = valor;
        printf("%d\n",stack->arr[stack->cantElem]);
        stack->cantElem++;
    }
    
}
int Pop(Stack* stack, int* valor) {
    
    if (IsEmpty(*stack)){
        printf("La pila está vacía\n");
    }else{
        stack->cantElem--;            // mover el puntero hacia el último valor válido
        *valor = stack->arr[stack->cantElem];      // leerlo
        stack->arr[stack->cantElem]=0;
        printf("POP: %d\n", *valor);
    }
    
    return 0;
}


