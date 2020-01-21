#include "tabla_kezelo.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



void kiir(int maxi, int maxj, mezo** tomb)
{
    int i, j;
    printf("     0");
    for(j=1; j<maxj; j++)
    {
        if(j<10)
            printf("   %d", j);
        else
            printf("  %d", j);
    }
    for(i=0; i<maxi; i++)
    {
        if(i<10)
            printf("\n%d   ", i);
        else
            printf("\n%d  ", i);
        for(j=0; j<maxj; j++)
        {
            if(tomb[i][j].zaszlo==true)
                printf("[f] ", tomb[i][j]);

            else if(tomb[i][j].latott==true)
            {
                if(tomb[i][j].akna==true)
                    printf("[*] ");
                else
                    printf("[%d] ", tomb[i][j].sz);
            }
            else
                printf("[ ] ");
        }
    }
}

void szamol(int i, int j, mezo** tomb, int x, int y)
{
    if(i>=0 && i<x && j>=0 && j<y)
        tomb[i][j].sz++;
}

void felderit(int choosex, int choosey, mezo** tomb, int zszl, int x, int y)
{
    if(tomb[choosex][choosey].latott==false)
    {
        if(zszl==1)
            tomb[choosex][choosey].zaszlo=!tomb[choosex][choosey].zaszlo;
        else if(tomb[choosex][choosey].zaszlo==false)
        {
            tomb[choosex][choosey].latott=true;
            if(tomb[choosex][choosey].sz==0)
            {
                if(choosex < 0 || choosex >= x || choosey < 0 || choosey >= y)
                    return;
                if(choosey>0)
                {
                    if(tomb[choosex][choosey-1].latott==false)
                        felderit(choosex, choosey-1, tomb, zszl, x, y);
                }
                if(choosey<(y-1))
                {
                    if(tomb[choosex][choosey+1].latott==false)
                        felderit(choosex, choosey+1, tomb, zszl, x, y);
                }
                if(choosex>0 && choosey<(y-1))
                {
                    if(tomb[choosex-1][choosey+1].latott==false)
                        felderit(choosex-1, choosey+1, tomb, zszl, x, y);
                }
                if(choosex>0)
                {
                    if(tomb[choosex-1][choosey].latott==false)
                        felderit(choosex-1, choosey, tomb, zszl, x, y);
                }
                if(choosex>0 && choosey>0)
                {
                    if(tomb[choosex-1][choosey-1].latott==false)
                        felderit(choosex-1, choosey-1, tomb, zszl, x, y);
                }
                if(choosex<(x-1) && choosey<(y-1))
                {
                    if(tomb[choosex+1][choosey+1].latott==false)
                        felderit(choosex+1, choosey+1, tomb, zszl, x, y);
                }
                if(choosex<(x-1))
                {
                    if(tomb[choosex+1][choosey].latott==false)
                        felderit(choosex+1, choosey, tomb, zszl, x, y);
                }
                if(choosex<(x-1) && choosey>0)
                {
                    if(tomb[choosex+1][choosey-1].latott==false)
                        felderit(choosex+1, choosey-1, tomb, zszl, x, y);
                }
            }
        }
    }
}

int kilep(mezo** tomb, int x, int y, int a)
{
    int i, j, db=0;
    for(i=0; i<x; i++)
        for(j=0; j<y; j++)
        {
            if(tomb[i][j].akna==true && tomb[i][j].latott==true)
                return -1;
            if(tomb[i][j].akna==false && tomb[i][j].latott==true)
                db++;
        }
    if(db==(x*y)-a)
        return 1;
    return 0;
}
