#include <stdio.h> // Biblioteca estándar de entrada/salida
#include <string.h> //Biblioteca de manejo de cadenas de caracteres
#include <stdlib.h> //Biblioteca de utilidades generales
#include <time.h> // Biblioteca de funciones relacionadas con el tiempo

#define MAX_LONGITUD_PALABRA 100 //Constante para longitud de la palabra
#define MAX_INTENTOS 6 //Constante para numero de intentos

//Funcion para dibujo de ahorcado
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
    for (int i = 0; i < longitudPalabra; i++) { // Recorre la longitud de la palabra
        palabraAdivinada[i] = '_'; //Llena la posciòn con un guiòn
    }
    palabraAdivinada[longitudPalabra] = '\0'; //Caracter nulo
}

void mostrarEstadoJuego(char palabraAdivinada[], int intentosRestantes) {
    printf("Palabra: %s\n", palabraAdivinada); //Palabra actualizada
    printf("Intentos restantes: %d\n", intentosRestantes);
    dibujo(MAX_INTENTOS - intentosRestantes); //Muestra el dibujo
}


// Función para verificar si la palabra ha sido adivinada completamente
int esPalabraAdivinada(char palabra[], char palabraAdivinada[]) {
    return strcmp(palabra, palabraAdivinada) == 0; // Compara la palabra original con la adivinada
}

int main() {
    printf("Bienvenido al juego de adivinar palabras\n");
    char palabras[][MAX_LONGITUD_PALABRA] = {
        "programacion", "matriz", "computadora", "juego", "ciencia", "presidente", "ingeniero", "github", "samsung", "corrector", "lapiz", "electricidad", "manzana", 
        "naranja", "lapicero", "mundo", "soporte", "estrella", "platino", "mouse", "teclado", "celular"
    };
    
    int numeroDePalabras = sizeof(palabras) / sizeof(palabras[0]); // Calcula el número de palabras en la lista
    
    // Inicializar el generador de números aleatorios
    srand(time(NULL));
    
    // Seleccionar una palabra al azar
    int indiceAleatorio = rand() % numeroDePalabras;
    char palabra[MAX_LONGITUD_PALABRA];
    strcpy(palabra, palabras[indiceAleatorio]); // Copia la palabra seleccionada al azar en la variable 'palabra'
    
    int longitudPalabra = strlen(palabra); //Obtener longitud de la palabra
    char palabraAdivinada[MAX_LONGITUD_PALABRA];
    inicializarJuego(palabra, palabraAdivinada, longitudPalabra);
    
    int intentosRestantes = MAX_INTENTOS;
    char letrasAdivinadas[MAX_LONGITUD_PALABRA] = {0};
    int conteoLetrasAdivinadas = 0;
    
    while (intentosRestantes > 0 && !esPalabraAdivinada(palabra, palabraAdivinada)) {
        mostrarEstadoJuego(palabraAdivinada, intentosRestantes); //Estado actual del juego
        
        char letra;
        printf("\nIntroduce una letra: ");
        scanf(" %c", &letra); // Lee una letra del usuario

        //Verificar si la letra ingresada es correcta
        int adivinacionCorrecta = 0;
        for (int i = 0; i < longitudPalabra; i++) { //Recorre la longitud de la palabra
            if (palabra[i] == letra && palabraAdivinada[i] != letra) {
                palabraAdivinada[i] = letra; //Actualiza la palabra adivinada
                adivinacionCorrecta = 1; //Devuelve 1 si es correcto
            }
        }
        
        if (!adivinacionCorrecta) {
            intentosRestantes--; //Decrementa intentos
        }
        
        letrasAdivinadas[conteoLetrasAdivinadas++] = letra; //Añade las letras adivinadas 
        letrasAdivinadas[conteoLetrasAdivinadas] = '\0';
        
        printf("Letras adivinadas: %s\n", letrasAdivinadas);//Letras adivinadas hasta el momento
    }

    // Verifica si la palabra fue adivinada o si se agotaron los intentos
    if (esPalabraAdivinada(palabra, palabraAdivinada)) {
        printf("¡Felicidades! Adivinaste la palabra: %s\n", palabra);
    } else {
        printf("Lo siento, has perdido. La palabra era: %s\n", palabra);
        dibujo(MAX_INTENTOS);
    }
    
    return 0;
}
