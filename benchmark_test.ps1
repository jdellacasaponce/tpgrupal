$N = 10
$totalDinamico = 0
$totalEstatico = 0

Write-Host "Ejecutando pruebas de tiempo de ejecucion..."

# Función para medir tiempo de ejecución de un programa
function Medir-Tiempo($programa) {
    $tiempos = @()
    for ($i = 0; $i -lt $N; $i++) {
        $stopwatch = [System.Diagnostics.Stopwatch]::StartNew()
        & .\$programa > $null
        $stopwatch.Stop()
        $tiempos += $stopwatch.Elapsed.TotalSeconds
    }
    return ($tiempos | Measure-Object -Average).Average
}

# Medir tiempo para test_dinamico.exe
$promedioDinamico = Medir-Tiempo "test_dinamico.exe"
$totalDinamico = [math]::Round($promedioDinamico * $N, 4)

Write-Host "Promedio de tiempo en la implementación dinámica: $promedioDinamico segundos"
Write-Host "Tiempo total: $totalDinamico segundos"

# Medir tiempo para test_estatico.exe
$promedioEstatico = Medir-Tiempo "test_estatico.exe"
$totalEstatico = [math]::Round($promedioEstatico * $N, 4)

Write-Host "Promedio de tiempo en la implementación estática: $promedioEstatico segundos"
Write-Host "Tiempo total: $totalEstatico segundos"

# Actualizar README.md
(Get-Content README.md) -replace '(\| Enlazada Dinámica\s+\| )\d+(\.\d+)?(\s+\| )\d+(\.\d+)?', "`$1$([math]::Round($promedioDinamico,4))$3$totalDinamico" `
                     -replace '(\| Contigua Estática\s+\| )\d+(\.\d+)?(\s+\| )\d+(\.\d+)?', "`$1$([math]::Round($promedioEstatico,4))$3$totalEstatico" | Set-Content README.md
