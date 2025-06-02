#include "./StackModule.h"
#include <assert.h>
#include <stdio.h>

void testStack() {
  Stack *tope = InicializarPila();

  // Test Push
  int i;
  for (i = 1; i <= MAX_ELEMENTOS; ++i) {
    Push(tope, i);
    assert(Top(tope) == i); // Último elemento debe ser 20
  }

  // Test Pop
  int valor;
  for (i = MAX_ELEMENTOS; i >= 1; --i) {
    Pop(tope, &valor);
    assert(valor == i);
  }
}

int main() {
  testStack();
  // testStackDinamico();
  // testAmbasStack();
  printf("Todos los tests pasaron exitosamente!\n");
  return 0;
}
