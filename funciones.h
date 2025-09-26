#ifndef FUNCIONES_H
#define FUNCIONES_H

 #include <stdio.h>
 #include <conio.h>
 #include <stdlib.h>

 #define BLANCO "\033[38;5;15m"
 #define AZUL "\033[38;5;19m"
 #define AMARILLO "\033[38;5;11m"
 #define MORADO "\033[38;5;56m"
 #define VERDE "\033[38;5;118m"
 #define ROJO "\033[38;5;9m"
 #define RESET "\033[0m"

 void ImprimirMapa(char mapa[][22], int*);
 void Movimiento(char mapa[][22], int*, char*);
 void TomarObjeto(int);
 
#endif