#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct {
    int velocidad;
    int anio;
    int cantidad;
    char *tipo_cpu;
} typedef compu;

void mostrarListaPC(compu *listaPc);
void pcMasVieja(compu *listaPc);
void pcMasRapida(compu *listaPc);

int main() {
    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    compu *computadoras, compu1;

    srand(time(NULL));

    compu1.velocidad = 1 + rand() % 3;
    compu1.anio = 2015 + rand() % 9;
    compu1.cantidad = 1 + rand() % 8;
    compu1.tipo_cpu = malloc(10 * sizeof(char));
    strcpy(compu1.tipo_cpu, tipos[0 + rand() % 6]);

    computadoras = (compu *) malloc(5 * sizeof(compu));

    for (int i = 0; i < 5; i++) {
        printf("Ingrese los datos de la computadora %d\n", i + 1);
        printf("Velocidad: ");
        scanf("%d", &computadoras[i].velocidad);
        printf("Anio de fabricacion: ");
        scanf("%d", &computadoras[i].anio);
        printf("Cantidad de nucleos: ");
        scanf("%d", &computadoras[i].cantidad);
        fflush(stdin);
        computadoras[i].tipo_cpu = malloc(10 * sizeof(char));
        printf("Tipo de procesador: ");
        gets(computadoras[i].tipo_cpu);
    }

    mostrarListaPC(computadoras);
    pcMasVieja(computadoras);
    pcMasRapida(computadoras);
}

void mostrarListaPC(compu *listaPc) {
    printf("-----------LISTA DE PC-----------\n");
    for (int i = 0; i < 5; i++) {
        printf("Datos de la PC %d\n", i + 1);
        printf("Velocidad: %d\n", listaPc[i].velocidad);
        printf("Anio de fabricacion: %d\n", listaPc[i].anio);
        printf("Cantidad de nucleos: %d\n", listaPc[i].cantidad);
        printf("Tipo de procesador: %s\n", listaPc[i].tipo_cpu);
    }
}

void pcMasVieja(compu *listaPc) {
    int min = 2030, vel, cant;
    char *cpu;
    cpu = malloc(10 * sizeof(char));

    for (int i = 0; i < 5; i++) {
        if (listaPc[i].anio < min) {
            min = listaPc[i].anio;
            vel = listaPc[i].velocidad;
            cant = listaPc[i].cantidad;
            strcpy(cpu, listaPc[i].tipo_cpu);
        }
    }

    printf("-----------PC MAS VIEJA-----------\n");
    printf("Velocidad: %d\n", vel);
    printf("Anio de fabricacion: %d\n", min);
    printf("Cantidad de nucleos: %d\n", cant);
    printf("Tipo de procesador: %s\n", cpu);
}

void pcMasRapida(compu *listaPc) {
    int max = 0, year, cant;
    char *cpu;
    cpu = malloc(10 * sizeof(char));

    for (int i = 0; i < 5; i++) {
        if (listaPc[i].velocidad > max) {
            max = listaPc[i].velocidad;
            year = listaPc[i].anio;
            cant = listaPc[i].cantidad;
            strcpy(cpu, listaPc[i].tipo_cpu);
        }
    }

    printf("-----------PC MAS RAPIDA-----------\n");
    printf("Velocidad: %d\n", max);
    printf("Anio de fabricacion: %d\n", year);
    printf("Cantidad de nucleos: %d\n", cant);
    printf("Tipo de procesador: %s\n", cpu);
}