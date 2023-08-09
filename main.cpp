#include <stdio.h>
#include <conio.h>
#include <string.h>

#define ANSI_BACKGROUND_YELLOW "\x1b[43m"
#define ANSI_BACKGROUND_GREEN "\x1b[42m"
#define ANSI_BACKGROUND_BLUE "\x1b[44m"
#define ANSI_BACKGROUND_MAGENTA "\x1b[45m"
#define ANSI_BACKGROUND_CYAN "\x1b[46m"
#define ANSI_COLOR_RESET "\x1b[0m"

void gotoxy(int x, int y) {
    printf("\x1b[%d;%df", y, x);
}

void lineasV(int c, int f) {
    int i;
    for (i = 1; i < f; i++) {
        gotoxy(c, i);
        printf("%c", 186);
    }
}

void lineasH(int c, int f) {
    int i;
    for (i = 1; i < c; i++) {
        gotoxy(i, f);
        printf("%c", 205);
    }
}

void imprimirTextoEnRecuadro(int x, int y, const char *texto) {
    int i, len;
    len = strlen(texto);

    gotoxy(x, y);
    printf("%c", 201);

    for (i = 1; i <= len + 2; i++) {
        printf("%c", 205);
    }
    printf("%c", 187);

    gotoxy(x, y + 1);
    printf("%c", 186);

    gotoxy(x + len + 3, y + 1);
    printf("%c", 186);

    gotoxy(x, y + 2);
    printf("%c", 200);

    for (i = 1; i <= len + 2; i++) {
        printf("%c", 205);
    }
    printf("%c", 188);

    gotoxy(x + 2, y + 1);
    printf("%s", texto);
}


void imprimirCaratula() {
    printf(ANSI_BACKGROUND_BLUE);
    lineasV(1, 24);
    lineasV(86, 24);
    lineasH(86, 1);
    lineasH(86, 24);
    gotoxy(1,1);
    printf("%c",201);
    gotoxy(1,24);
    printf("%c",200);
    gotoxy(86,1);
    printf("%c",187);
    gotoxy(86,24);
    printf("%c",188);
    getch();

    printf(ANSI_BACKGROUND_GREEN);
    imprimirTextoEnRecuadro(29, 2, "Universidad De Las");
    imprimirTextoEnRecuadro(31, 4.6, "Fuerzas Armadas");
    imprimirTextoEnRecuadro(36.5, 6.6, "ESPE");

    printf(ANSI_BACKGROUND_CYAN );
    imprimirTextoEnRecuadro(14, 10, "Fecha: 02/08/2023");
    imprimirTextoEnRecuadro(44, 10, "Alumno: Noe Cahuatijo");


    printf(ANSI_BACKGROUND_MAGENTA);
    imprimirTextoEnRecuadro(14, 14, "NRC:9890");
    imprimirTextoEnRecuadro(44, 14, "Profesor: ING.Fernando Solis");

    printf(ANSI_BACKGROUND_YELLOW);
    imprimirTextoEnRecuadro(14, 18, "Tercer Parcial");
    imprimirTextoEnRecuadro(44, 18, "Periodo: Mayo2023-Septiembre2023");

    printf(ANSI_COLOR_RESET);


}

int main() {
    imprimirCaratula();
    printf("\n");
    printf("\n");

    return 0;
}


