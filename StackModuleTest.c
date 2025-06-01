#include <stdio.h>
#include <assert.h>
#include "stackEstatico.c" 
#include "stackDinamico.c" 

void testStackEstatico() {
    int pila[MAX_ELEMENTOS + 1];
    int *tope = pila;
    int valor;

    // Test Push
    Push(&tope, 10);
    Push(&tope, 20);
    assert(*(tope - 1) == 20); // Último elemento debe ser 20

    // Test Pop
    Pop(&tope, &valor);
    assert(valor == 20);
    Pop(&tope, &valor);
    assert(valor == 10);

    printf("testStackEstatico paso exitosamente\n");
}

void testStackDinamico() {
    tPila stack = NULL;
    int valor;

    // Test Push
    Push(&stack, 30);
    Push(&stack, 40);
    assert(stack->info == 40); // Último elemento debe ser 40

    // Test Pop
    Pop(&stack, &valor);
    assert(valor == 40);
    Pop(&stack, &valor);
    assert(valor == 30);
    
    printf("testStackDinamico paso exitosamente\n");
}

// Test del comportamiento de ambas pilas juntas
void testAmbasStack() {
    int pila[MAX_ELEMENTOS + 1];
    int *tope = pila;
    tPila stack = NULL;
    int valor;

    // Pila estática
    Push(&tope, 50);
    Push(&tope, 60);
    assert(*(tope - 1) == 60);

    Pop(&tope, &valor);
    assert(valor == 60);

    // Pila dinámica
    Push(&stack, 70);
    Push(&stack, 80);
    assert(stack->info == 80);

    Pop(&stack, &valor);
    assert(valor == 80);

    printf("testAmbosStack aprobados\n");
}

int main() {
    testStackEstatico();
    testStackDinamico();
    testAmbasStack();
    printf("Todos los tests pasaron exitosamente!\n");
    return 0;
}