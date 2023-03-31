#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 20

int main() {
    int i;
    double vt[N], *Pvt;
    Pvt = vt;

    srand(time(NULL));

    for(i = 0; i < N; i++) {
        *Pvt = 1 + rand() % 100;
        printf("%f  ", *Pvt);
        Pvt++;
    }
}
