#!/bin/bash
N=1000
TOTAL=0
echo "Ejecutando pruebas de tiempo de ejecucion..."
for ((i = 0; i < "$N"; ++i)); do
  TIME=$({ /usr/bin/time -f "%e" ./test_dinamico >/dev/null; } 2>&1)
  TOTAL=$(echo "$TOTAL + $TIME" | bc)
done
PROMEDIO=$(echo "scale=4; $TOTAL / $N" | bc)

echo "Promedio de tiempo en la implementación dinamica: $PROMEDIO segundos"
echo "El tiempo total de las mil ejecuciones sumados es: $TOTAL segundos"
LINEA="| Enlazada Dinámica      | $PROMEDIO | $TOTAL |"
sed -i "/^| Enlazada Dinámica      |/c$LINEA" Readme.md

TOTAL=0

for ((i = 0; i < "$N"; ++i)); do
  TIME=$({ /usr/bin/time -f "%e" ./test_estatico >/dev/null; } 2>&1)
  TOTAL=$(echo "$TOTAL + $TIME" | bc)
done

PROMEDIO=$(echo "scale=4; $TOTAL / $N" | bc)
echo "Promedio de tiempo en la implementacion estatica: $PROMEDIO segundos"
echo "El tiempo total de las mil ejecuciones sumados es: $TOTAL segundos"
LINEA="| Contigua Estática      | $PROMEDIO | $TOTAL |"
sed -i "/^| Contigua Estática      |/c$LINEA" Readme.md
