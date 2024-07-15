#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LONGITUD_PALABRA 100
#define MAX_INTENTOS 6

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
            printf("\n     _______\n    |       |\n    |       0\n    |      /|\\\n    |\n    |\n    |\n ----------");
            break;
        case 5:
            printf("\n     _______\n    |       |\n    |       0\n    |      /|\\\n    |      /\n    |\n    |\n ----------");
            break;
        case 6:
            printf("\n     _______\n    |       |\n    |       0\n    |      /|\\\n    |      / \\\n    |\n    |\n ----------");
            break;
    }
}

void inicializarJuego(char palabra[], char palabraAdivinada[], int longitudPalabra) {
    for (int i = 0; i < longitudPalabra; i++) {
        palabraAdivinada[i] = '_';
    }
    palabraAdivinada[longitudPalabra] = '\0';
}

void mostrarEstadoJuego(char palabraAdivinada[], int intentosRestantes) {
    printf("Palabra: %s\n", palabraAdivinada);
    printf("Intentos restantes: %d\n", intentosRestantes);
    dibujo(MAX_INTENTOS - intentosRestantes);
}

int esPalabraAdivinada(char palabra[], char palabraAdivinada[]) {
    return strcmp(palabra, palabraAdivinada) == 0;
}

int main() {
    printf("Bienvenido al juego de adivinar palabras\n");
    char palabras[][MAX_LONGITUD_PALABRA] = {
        "programacion", "matriz", "computadora", "juego", "ciencia", "presidente", "ingeniero", "github", "samsung", "corrector", "lapiz", "electricidad", "manzana", 
        "naranja", "lapicero", "mundo", "soporte", "estrella", "platino", "mouse", "teclado", "celular"
    };
    
    int numeroDePalabras = sizeof(palabras) / sizeof(palabras[0]);
    
    // Inicializar el generador de números aleatorios
    srand(time(NULL));
    
    // Seleccionar una palabra al azar
    int indiceAleatorio = rand() % numeroDePalabras;
    char palabra[MAX_LONGITUD_PALABRA];
    strcpy(palabra, palabras[indiceAleatorio]);
    
    int longitudPalabra = strlen(palabra);
    char palabraAdivinada[MAX_LONGITUD_PALABRA];
    inicializarJuego(palabra, palabraAdivinada, longitudPalabra);
    
    int intentosRestantes = MAX_INTENTOS;
    char letrasAdivinadas[MAX_LONGITUD_PALABRA] = {0};
    int conteoLetrasAdivinadas = 0;
    
    while (intentosRestantes > 0 && !esPalabraAdivinada(palabra, palabraAdivinada)) {
        mostrarEstadoJuego(palabraAdivinada, intentosRestantes);
        
        char letra;
        printf("\nIntroduce una letra: ");
        scanf(" %c", &letra);
        
        int adivinacionCorrecta = 0;
        for (int i = 0; i < longitudPalabra; i++) {
            if (palabra[i] == letra && palabraAdivinada[i] != letra) {
                palabraAdivinada[i] = letra;
                adivinacionCorrecta = 1;
            }
        }
        
        if (!adivinacionCorrecta) {
            intentosRestantes--;
        }
        
        letrasAdivinadas[conteoLetrasAdivinadas++] = letra;
        letrasAdivinadas[conteoLetrasAdivinadas] = '\0';
        
        printf("Letras adivinadas: %s\n", letrasAdivinadas);
    }
    
    if (esPalabraAdivinada(palabra, palabraAdivinada)) {
        printf("¡Felicidades! Adivinaste la palabra: %s\n", palabra);
    } else {
        printf("Lo siento, has perdido. La palabra era: %s\n", palabra);
        dibujo(MAX_INTENTOS);
    }
    
    return 0;
}
