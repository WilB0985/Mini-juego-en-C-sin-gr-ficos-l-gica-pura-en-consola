#include "funciones.h"

void ImprimirMapa(char mapa[][22], int* _objetos)
{
  *_objetos = 0;

  for(int y = 0; y < 24 ; y++)
  {
    for(int x = 0; x < 22 ;x++)
    {
      if(mapa[y][x] == '0') printf(AZUL "%c " RESET, mapa[y][x]);
      else if(mapa[y][x] == '+')
      {
        printf(AMARILLO "%c " RESET, mapa[y][x]);
        (*_objetos)++; 
      }
      else if(mapa[y][x] == 'W') printf(MORADO "%c " RESET, mapa[y][x]);
      else printf("%c ", mapa[y][x]);
    }
    printf("\n");
  }
  printf("\n OBJETOS POR RECOLECTAR %d", *_objetos);
}

void TomarObjeto(int objetos)
{
  system("cls");
  printf(VERDE "\033[10;5H HAS RECOGIDO UN OBJETO \033[11;6H objetos restantes: %d" RESET, objetos); 
}

void Movimiento(char mapa[][22], int* _objetos, char *_tecla)
{
 for(int y = 0; y < 24 ;y++)
 {
   for(int x = 0; x < 22 ;x++)
   {
     if(mapa[y][x] == '0')
     {
       int MovX = x, MovY = y;
     
       if(*_tecla == 'w') MovY--;
       else if(*_tecla == 's') MovY++;
       else if(*_tecla == 'a') MovX--;
       else if(*_tecla == 'd') MovX++;

       if(MovX >= 0 && MovX < 22 && MovY >= 0 && MovY < 24)
       {
         if(mapa[MovY][MovX] == ' ' || mapa[MovY][MovX] == '+')
         { 
           if(mapa[MovY][MovX] == '+')
           {
             (*_objetos)--;
             TomarObjeto(*_objetos);
             *_tecla = getch();
           }
           mapa[y][x] = ' ';
           mapa[MovY][MovX] = '0';
         }
         else if(mapa[MovY][MovX] == 'W')
         {
           if(*_objetos > 0)
           {
             system("cls");
             printf(ROJO "\033[10;0H RECOGE TODOS LOS OBJETOS PARA CONTINUAR" RESET); 
             *_tecla = getch();
           }
           else if(*_objetos == 0)
           {
             system("cls");
             printf(AZUL "\033[10;0HJUEGO COMPLETADO!\033[11;0Hgracias por jugar!" RESET);
             *_tecla = getch();
             *_tecla = 'q';
           }
         }
       }
       return;
     }
   }
 } 
}