/*Algoritmo que que proporciona la cantidad de centros numericos que hay entre 1 y n*/
/*Hecho por Simon Londonno Escobar para su segundo taller de Estructuras de Datos*/
/*Universidad Tecnológica de Pereira // 5 de marzo de 2024*/

/*Desarollado en Visual Studio Code y ejecutado por ele editor web de hackerRank*/


#include <stdio.h>
#include <math.h>

int binarySearch(int A[], int i, int j, int k) {
    int r = -1, m;
    while (i <= j) {
        m = (i + j) >> 1;
        if (k == A[m]) {
            r = m;
            break;
        } else if (k > A[m]) {
            i = m + 1;
        } else {
            j = m - 1;
        }
    }
    if (r == -1) {
        return (-1 * i) - 1;
    } else {
        return r;
    }
}

int main() {
    /*Lo mas dificil seria encontrar los numeros centricos, lo hice con un codigo aparte que los buscaba de la forma 
    lenta, con bubles, tardaba como 15 segundos en encontrarlos todos, pero pues solo nececitaba esos 8 para luego 
    elevarlos al cuadrado y aplicarles una formula cuadratica (que viene de la suma de gauss) para obtener el numero 
    de elementos del conjunto el cual centra ese numero, por asi decirlo, que es lo que me pide el sistema que haye*/
    int limites[7] = {8, 49, 288, 1681, 9800, 57121, 332928}, n, resultado;

    //el resto es solo una busqueda binaria, obviamente hay que arreglar el caso negatico y el caso >7
    while (scanf("%d", &n) != EOF && n != 0) {
        resultado = binarySearch(limites, 0, 7, n);
        if (resultado < 0) {
            resultado = -1 * resultado - 1;
        } else {
            resultado++;
        }
        if (resultado > 7)
        {
            resultado = 7;
        }
        printf("%d\n", resultado);
    }

    return 0;
}
