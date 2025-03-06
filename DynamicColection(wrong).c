/*No cumple con todos los test, ya te toca verificar*/

/*Algoritmo que hace consultas sobre un array
hecho por simon londonno escobar para su segundo tercer de estructuras de datos
Universidad Tecnologica de pereira, 12/03/2024*/
#include <stdio.h>

#define myInfinite 2147483647

void MyMerge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1, n2 = r - q, i, j, k;
    int L[n1 + 2], R[n2 + 2];

    for(i=1 ; i<=n1 ; i++)
    {
        L[i] = A[p + i - 1];
    }

    for(j=1 ; j<=n2 ; j++)
    {
        R[j] = A[q + j];
    }

    L[n1 + 1] = myInfinite;
    R[n2 + 1] = myInfinite;
    i = 1;
    j = 1;

    for(k=p ; k<=r ; k++)
    {
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void MergeSort(int A[], int p, int r)
{
    int q;
    if(p < r)
    {
        q = (p + r) >> 1; // (p + r) >> 1;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        MyMerge(A, p, q, r);
    }
}

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            // Encontramos el elemento, ahora buscamos la primera ocurrencia
            while (mid > 0 && arr[mid - 1] == target) {
                mid--;
            }
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // El elemento no se encontr0 en el array, devuelve ocurrencia mas cercana 
    return -1 * low;
}

 //para buscar los numeros entre los limites de a y b se tienen que hacer para el caso de buscar tanto
 //en la primera como ultima ocurrencia
int binarySearchLast(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            // Encontramos el elemento, ahora buscamos la uultima ocurrencia
            while (mid < high && arr[mid + 1] == target) {
                mid++;
            }
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // El elemento no se encontr0 en el array
    // Devolver la posici0n donde deber1a estar
    return high;
}

    //Bueno teniendo en cuenta el tema de que modificar el arreglo para annadirle elementos es
    //complicado y pesado, es mejor hacer el array del tamanno maximo posible y de ahi, siempre mostrar 
    //o consultar hasta el tamanno simulado, como si fuera la cueva de platon

int main(){

    //Como el numero de elementos del array original es de 10^6 y el numero de consultas posibles tambien es
    //10^6, el array completo debe de ser de 20^6, pero el tamanno para las consultas debe de ser de n
    int coleccion[2000000];

    int collectionTAM, querys;
    scanf("%d %d", &collectionTAM, &querys);

    //Llenamos el arreglo
    for (int i = 0; i < collectionTAM; i++)
    {
        scanf("%d", &coleccion[i]);
    }
    MergeSort(coleccion, 0, collectionTAM - 1);
    
    // Hasta ahora el array se crea y se ordena correctamente...
    //pasaremos a hacer los distintos casos de las querys
    int querytype, k, a, b;

    int comp, comp2, entreayb;

    for (int i = 0; i < querys; i++)
    {//ahora vamos a disennarlo para que soporte los 2 casos
    
    scanf("%d", &querytype);
        if (querytype == 1)
        {
            scanf("%d", &k);
            comp = binarySearch(coleccion, 0, collectionTAM - 1, k);
            if (comp < 0)
            {
                comp *= -1;
                if (comp <= collectionTAM - 1)
                {
                    coleccion[comp] = k;
                }
                else if (comp == collectionTAM)
                {
                    coleccion[collectionTAM] = k;
                    collectionTAM++;
                }                
            }
        }
        else if (querytype == 2)
        {
            scanf("%d %d", &a, &b);
            comp  = binarySearch(coleccion, 0, collectionTAM - 1, a);
            comp2 = binarySearchLast(coleccion, 0, collectionTAM - 1, b);

            if (a == b)
            {
                if (comp < 0)
                {
                    entreayb = 0;
                }
                else
                {
                    entreayb = comp2 - comp + 1;
                }                
            }
            else
            {
                //como da un poco igual si comp1 esta o no esta, la dejamos positiva
                if (comp < 0)
                {
                    comp *= -1;
                }
                //lo importante es comp2
                if (comp2 < 0)
                {
                    comp2 *= -1;
                    entreayb = comp2 - comp; 
                }
                else if (comp2 >= 0)
                {
                    entreayb = comp2 - comp + 1;
                }
            }
            printf("%d\n", entreayb); 
        }        
    }
    return 0;
}