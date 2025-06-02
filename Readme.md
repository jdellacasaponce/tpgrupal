# StackModule

## Benchmark

Tiempo de 1000 ejecuciones de los test:

| Implementación         | Tiempo Promedio(s) | Tiempo Total(s)|
|------------------------|------------|-------------------|
| Contigua Estática      | 4.4110 | 44.11 |
| Enlazada Dinámica      | .0180 | .18 |

(*los tiempos pueden variar según el entorno.*)

## Preguntas y Respuestas

### a. ¿Cuál es la mejor implementación?

La implementación contigua es más rápida y usa menos memoria. La dinámica es
más flexible al no tener límite fijo.

### b. ¿Qué cambios haría para que no haya precondiciones?

Agregar manejo de precondiciones para cuando no se cumplen.

### c. ¿Qué cambios haría en el diseño para que el stack sea genérico?

Utilizar `void*` en lugar de `int`, y almacenar el tamaño de cada elemento.
Esto implica pérdida de tipo en tiempo de compilación y necesidad de casting.

### d. ¿Cómo hacer que el módulo permita múltiples stacks?

Definir un tipo `Stack` con su propia estructura y funciones que
operen sobre él. Ejemplo:

```c
typedef struct {
    StackItem* data;
    int top;
    int capacity;
} Stack;

void StackPush(Stack* s, StackItem item);
```
