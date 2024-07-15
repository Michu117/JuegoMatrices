#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

// Prototipos de las funciones
void categorias();
void ingresoCategoria(int op);
void empezarJuego(char palabras[][15], char nombre[]);
void dibujo(int intentos);

// Función principal main
int main() {
    system("mode con cols=80 lines=25");
    categorias();
    system("pause");
    return 0;
}

// Función categorias, imprime en pantalla las categorías y permite elegir una
void categorias() {
    int op;
    do {
        system("cls");
        printf("\n\t\t\t\tJUEGO EL AHORCADO\n\n");
        printf(" CATEGORIAS\n\n");
        printf(" 1. Frutas\n");
        printf(" 2. Animales\n");
        printf(" 3. Paises\n");
        printf(" 4. Objetos\n\n");
        printf(" Ingresa una opcion: ");
        scanf("%i", &op);
    } while (op < 1 || op > 4);

    ingresoCategoria(op);
}

// Esta función recibe un valor, y dependiendo del valor recibido llama a otra función para empezar el juego
void ingresoCategoria(int op) {
    char nombrecat[4][15] = {"Frutas", "Animales", "Paises", "Objetos"};
    char frutas[10][15] = {"MELON", "PAPAYA", "SANDIA", "MANZANA", "PERA", "NARANJA", "UVA", "CEREZA", "CIRUELA", "KIWI"};
    char animales[10][15] = {"PERRO", "GATO", "CABALLO", "GALLINA", "JIRAFA", "MONO", "VACA", "CONEJO", "TORTUGA", "LOBO"};
    char paises[10][15] = {"PERU", "COLOMBIA", "ARGENTINA", "NICARAGUA", "ITALIA", "MEXICO", "CANADA", "VENEZUELA", "ECUADOR", "BRASIL"};
    char objetos[10][15] = {"MOCHILA", "RELOJ", "ZAPATILLA", "MUEBLE", "CUADERNO", "SILLA", "MESA", "CELULAR", "PUERTA", "AURICULARES"};
    
    switch(op) {
        case 1:
            empezarJuego(frutas, nombrecat[op - 1]);
            break;
        case 2:
            empezarJuego(animales, nombrecat[op - 1]);
            break;
        case 3:
            empezarJuego(paises, nombrecat[op - 1]);
            break;
        case 4:
            empezarJuego(objetos, nombrecat[op - 1]);
            break;    
    }    
}

// Función que contiene el algoritmo del juego
void empezarJuego(char palabras[][15], char nombre[]) {
    int opcion, i, j, k, longitud, espacios, puntos = 1200;
    char letra;
    int aciertos = 0;
    int intentos = 0;
    srand(time(NULL));
    
    opcion = rand() % 10; // Se genera un numero aleatorio comprendido entre 0 y 9
    longitud = strlen(palabras[opcion]); // Se almacena la longitud de la palabra 
    char frase[longitud + 1]; // +1 para el carácter nulo
    
    // Se colocan guiones bajos en el array de caracteres frase
    for(i = 0; i < longitud; i++) {
        frase[i] = '_';
    }
    frase[longitud] = '\0'; // Carácter nulo al final de la cadena
    
    do {
        aciertos = 0;
        system("cls");
        printf("\n\t\t\t\tJUEGO EL AHORCADO\n\n");
        printf(" CATEGORIA: %s\n\n", nombre);
        printf(" Intentos Disponibles: %i\t\t\t\tPuntuacion: %i\n\n", 6 - intentos, puntos);
        dibujo(intentos);
        
        // Imprime el array de caracteres frase
        printf("\n\n\n");
        for(i = 0; i < longitud; i++) {
            printf(" %c ", frase[i]);
        }

        if (intentos == 6) {
            printf("\n\n PERDISTE!!\n");
            printf(" LA SOLUCION ERA: %s\n\n", palabras[opcion]);
            printf(" Presiona una tecla para volver a jugar..");
            getch();
            categorias();    
        }
        
        // Proceso que comprueba si se ha adivinado la palabra
        espacios = 0;
        for (i = 0; i < longitud; i++) {
            if (frase[i] == '_')
                espacios++;
        }
        
        if (espacios == 0) {
            printf("\n\n FELICIDADES.. GANASTE!!\n\n");
            printf(" Presiona una tecla para volver a jugar..");
            getch();
            categorias();        
        }
        
        printf("\n\n Digite una letra: ");
        scanf(" %c", &letra);
        
        // Proceso que verifica si la letra ingresada existe en la palabra, si esto es verdadero, se reemplaza el caracter guion bajo por la letra ingresada 
        for (j = 0; j < longitud; j++) {
            if (letra == palabras[opcion][j]) {
                frase[j] = letra;
                aciertos++;
            }    
        }
        
        if (aciertos == 0) {
            intentos++;    
            puntos -= 200;
        }
        
    } while(intentos != 7);
    
    printf("\n\n");        
}

// Función que realiza el dibujo de el ahorcado, recibe el número de intentos y con ese dato realiza el dibujo
void dibujo(int intentos) {
    switch(intentos) {
        case 0:
            printf("\n     _______\n    |       |\n    |\n    |\n    |\n    |\n    |\n ----------");
            break;
        case 1:
            printf("\n     _______\n    |       |\n    |       0\n    |\n    |\n    |\n    |\n ----------");
            break;
        case 2:
            printf("\n     _______\n    |       |\n    |       0\n    |       |\n    |\n    |\n    |\n ----------");
            break;
        case 3:
            printf("\n     _______\n    |       |\n    |       0\n    |      /|\n    |\n    |\n    |\n ----------");
            break;
        case 4:
            printf("\n     _______\n    |       |\n    |       0\n    |      /|");
            printf("\\");
            printf("\n");
            printf("    |\n    |\n    |\n ----------");
            break;
        case 5:
            printf("\n     _______\n    |       |\n    |       0\n    |      /|");
            printf("\\");
            printf("\n");
            printf("    |      /\n    |\n    |\n ----------");
            break;
        case 6:
            printf("\n     _______\n    |       |\n    |       0\n    |      /|");
            printf("\\");
            printf("\n");
            printf("    |      / ");
            printf("\\");
            printf("\n");
            printf("    |\n    |\n ----------");
            break;
    }
}
