#ifndef TABLA_KEZELO_H_INCLUDED
#define TABLA_KEZELO_H_INCLUDED
#include <stdbool.h>

typedef struct mezo
{
    int sz;
    bool zaszlo, akna, latott;
} mezo;

void kiir(int maxi, int maxj, mezo** tomb);
void szamol(int i, int j, mezo** tomb, int x, int y);
void felderit(int choosex, int choosey, mezo** tomb, int zszl, int x, int y);
int kilep(mezo** tomb, int x, int y, int a);

#endif // TABLA_KEZELO_H_INCLUDED
