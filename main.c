#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "tabla_kezelo.h"
#include "timer.h"
#include "econio.h"


int main(void)
{
    srand(time(0));
    int x, y, a, i, j;
    printf("Hany sora es oszlopa legyen a tablanak, es mennyi akna legyen rajta?");
    scanf("%d %d %d", &x, &y, &a);
    mezo** tomb;
    tomb=malloc(x*sizeof(mezo*));
    for(i=0; i<x; i++)
    {
        tomb[i]=malloc(y*sizeof(mezo));
    }

    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            tomb[i][j].akna = false;
            tomb[i][j].zaszlo = false;
            tomb[i][j].latott = false;
            tomb[i][j].sz = 0;
        }
    }

    int dbakna=0;
    while(dbakna<a)
    {
        int v=rand()%x;
        int f=rand()%y;
        if(tomb[v][f].akna==false)
        {
            tomb[v][f].akna=true;
            dbakna++;
        }
    }

    for(i=0; i<x; i++)
        for(j=0; j<y; j++)
        {
            if(tomb[i][j].akna==true)
            {
                szamol(i-1, j-1, tomb, x, y);
                szamol(i-1, j, tomb, x, y);
                szamol(i-1, j+1, tomb, x, y);
                szamol(i, j-1, tomb, x, y);
                szamol(i, j+1, tomb, x, y);
                szamol(i+1, j-1, tomb, x, y);
                szamol(i+1, j, tomb, x, y);
                szamol(i+1, j+1, tomb, x, y);
            }
        }
    kiir(x, y, tomb);

    int choosex, choosey, zszl;
    int exit=0;
    bool start=false;
    while(exit==0)
    {
        scanf("%d %d %d", &choosex, &choosey, &zszl);
        if(start==false){
                start=true;
                ora_indul();
        }
        felderit(choosex, choosey, tomb, zszl, x, y);
        exit=kilep(tomb, x, y, a);
        clrscr();
        kiir(x, y, tomb);
    }
    ora_leall();
    if(exit==-1)
    {
        printf("\nVesztettel!");
    }
    else
    {
        printf("\nNyertel!");
    }
    printf("\nJatek ido: %ld masodperc", stopper());
    free(tomb);
    return 0;
}
