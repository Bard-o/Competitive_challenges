/*Algoritmo que dice el par de piezas necesarias para llenar una apertura
hecho por simon londonno escobar para su segundo taller de estructuras de datos
Universidad Tecnologica de pereira, 12/03/2024*/
/*Doy credito a este ejercicio en su mayoria a que pude encontrar las funciones de 
BB y OM adaptadas a cadenas, y tambien por el consejo de hacer el diccionario una extructura
porque ya habia intentado el ejercicio por mi cuenta y siempre salia algo maL, pero la mayoria
del trabajo logico es mio, lo cual no es mucho porque es lo mismo que el ejercicio pasado*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>
//defino un infinito para el mergesort
#define myInfinite "zzzzzzzzzzzzzz"
#define MAXV 1000001

//voy a definir las cadenas como una estructura que funcione como un array de maximo 15 caracteres
typedef struct {
    char numero [15];

} street;

//siendo sinceros, busque en internet este mergesort de cadenas, no son mi punto fuerte
//lo bueno es que es casi identico al que ya usaba asi que no es muy dificil entenderlo
void myMerge (street A[], int p, int q, int r) {
    int i, j, k, n1 = q - p + 1, n2 = r - q; 
    street L[n1 + 2], R[n2 + 2];

    for (i = 1; i <= n1; i++) 
        L[i] = A[p + i - 1];

    for (j = 1; j <= n2; j++)
        R[j] = A[q + j];


    strcpy (L[n1 + 1].numero, myInfinite);
    strcpy (R[n2 + 1].numero, myInfinite);

    i = 1; 
    j = 1;

    for (k = p; k <= r; k++) {
        if (strcmp (L[i].numero, R[j].numero) <= 0) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort (street A[], int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        mergeSort (A, p, q);
        mergeSort (A, q + 1, r);
        myMerge (A, p, q, r);
    }
}

//usando la misma analogia del merge, pude adaptar la busqueda binaria
int binarySearch (street A[], int i, int j, char k[]) {

    int m;
    if (i > j) {
        return -1*i - 1;
    }
    else {
        m = (i + j)/2;
        if (strcmp (A[m].numero, k) == 0) {
            return m;
        }
        else {
            if (strcmp (A[m].numero, k) < 0)
                return binarySearch (A, m + 1, j, k);
            else
                return binarySearch (A, i, m - 1, k);
        }
    }
}


int main () {
    //Esto es basicamente el caso 2 del ejercicio de conjuntos mutables pero con cadenas
    int palabrasTotal, querys, Limizquierdo, Limderecho, numeroPalabras;

    char aux[15], inferior[15], superior[15];
    street diccionario[MAXV];

    //ingreso la primera linea
    scanf ("%d %d", &palabrasTotal, &querys);

    //lleno el diccionario con las palabras que va a tener
    for (int i = 1; i <= palabrasTotal; i++) {
        scanf ("%s", aux);
        strcpy (diccionario[i].numero, aux);
    }

    //las ordeno
    mergeSort (diccionario, 1, palabrasTotal);

    //por cada query hago (hace poco vi que se podia hacer un while con esta condicion)
    while (querys--) {
        //escaneo las palabras con las que voy a buscar
        scanf ("%s %s", inferior, superior);

        //resivo los resultados de las busquedas, esto nos dice las palabras que hay en medio de las anteriores
        Limizquierdo = binarySearch (diccionario, 1, palabrasTotal, inferior);
        Limderecho = binarySearch (diccionario, 1, palabrasTotal, superior);

        //corrijo si la palabra del limite izquierdo no esta
        if (Limizquierdo < 0) 
            Limizquierdo = Limizquierdo*-1 - 1;
        
        //como el limite derecho en caso de no estar se va a hacia la proxima posicion donde deveria estar
        //eso no nos intereza, asi que corregimos
        if (Limderecho < 0) 
            Limderecho = Limderecho*-1 - 2;
        
        //hago la diferencia entre los limites ya corregidos y la retorno
        numeroPalabras = Limderecho - Limizquierdo + 1;
        printf ("%d\n", numeroPalabras);
    }
    return 0;
}