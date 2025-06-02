#include "./StackModule.h"
#include <assert.h>
#include <stdio.h>

void testStack() {
  Stack *tope = InicializarPila();

  // Test Push
  int i;
  for (i = 1; i <= 99999; ++i) {
    Push(tope, i);
    assert(Top(tope) == i); // Último elemento debe ser 20
  }

  // Test Pop
  int valor;
  for (i = 99999; i >= 1; --i) {
    Pop(tope, &valor);
    printf("%s%d\n", "Se ejecutó la vuelta", i);
    assert(valor == i);
  }

  // printf("testStackEstatico paso exitosamente\n");
}
//
// void testStackDinamico() {
//  Stack *stack = NULL;
//  int valor;
//
//  // Test Push
//  Push(stack, 30);
//  Push(stack, 40);
//  assert(Top(stack) == 40); // Último elemento debe ser 40
//
//  // Test Pop
//  Pop(stack, &valor);
//  assert(valor == 40);
//  Pop(stack, &valor);
//  assert(valor == 30);
//
//  printf("testStackDinamico paso exitosamente\n");
//}
//
//// Test del comportamiento de ambas pilas juntas
// void testAmbasStack() {
//   Stack *tope = InicializarPila();
//   Stack *stack = NULL;
//   int valor;
//
//   // Pila estática
//   Push(tope, 50);
//   Push(tope, 60);
//   assert(Top(tope) == 60);
//
//   Pop(tope, &valor);
//   assert(valor == 60);
//
//   // Pila dinámica
//   Push(stack, 70);
//   Push(stack, 80);
//   assert(Top(stack) == 80);
//
//   Pop(stack, &valor);
//   assert(valor == 80);
//
//   printf("testAmbosStack aprobados\n");
// }

int main() {
  testStack();
  // testStackDinamico();
  // testAmbasStack();
  printf("Todos los tests pasaron exitosamente!\n");
  return 0;
}
