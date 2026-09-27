@echo off
echo Compilando os 22 exercicios de OpenMP...
echo.

for /d %%d in ("Exercicio *") do (
    for %%f in ("%%d\*.c") do (
        echo Compilando %%f...
        gcc -fopenmp -O2 "%%f" -o "%%~nf.exe" -lm
    )
)

echo.
echo Processo concluido! Para executar qualquer exercicio:
echo set OMP_NUM_THREADS=4
echo .\exercicio01.exe
pause
