/*Algoritmo que calcula las posiciones donde caen los sapos*/
/*Hecho por Simon Londonno Escobar para su segundo taller de Estructuras de Datos*/
/*Universidad Tecnológica de Pereira // 5 de marzo de 2024*/

/*Desarollado en Visual Studio Code y ejecutado por ele editor web de hackerRank*/
/*Por desgracia, solo pasa con 23 de los 25 casos de prueva, pero bueno*/

/*seguí los consejos de la asesoria, hacer el array con los sapos y sus posiciones, y el otro array con las 
posiciones 
libres, se hace la busqueda binaria, se imprime el lugar del punto de intercección y posteriormente se intercambian 
posiciones entre los arrays*/
/*No tengo ni ideaque tendran el caso  17 y el caso  18, pero no hay nada que pueda hacer a estas horas, igual, fue 
el unico ejercicio que realizé al 100% por mi cuenta y eso es algo de lo que me puedo sentir orgulloso, igual*/
#include <stdio.h>

int binarySearch(int A[],int i,int j,int k ){
    int r= -1, m;
    while (i <= j)
    {   // OPERACIONES CON BITS CONSULTAR, dividir o potenciar por potendias de 2
        m = (i + j) >> 1;
        if (k == A[m])
        {
            r = m; 
            break;
        }else if (k > A[m])
        {
            i = m + 1;
        }
        else
        {
            j = m - 1;
        }
    }
    if (r == -1)
    {
        return (-1 * i) ;
    }else
    {
        return r;
    }      
}

int main(){
    int nsapos;
    
    scanf("%d", &nsapos);
    int nposlibres = 1000000 - nsapos;
    int saposlista[nsapos], poslibres[nposlibres];

    for (int i = 0; i < nsapos; i++) {
        scanf("%d", &saposlista[i]);
    }

    //quizas sea algo lento pero puedo llenar el array asi

    int aquiHaySapo = 0, aquiNoHaySapo = 0; 
    for (int i = 0; i < 1000000; i++)
    {
        if ((i + 1) == saposlista[aquiHaySapo])
        {
            aquiHaySapo ++;
        }else
        {
            poslibres[aquiNoHaySapo] = (i + 1);
            aquiNoHaySapo ++;
        }       
    } //el array de posiciones libres y el se sapos se crado con exito

    int saltosTotales, resultadoBusqueda, sapoQueSalta, auxiliar;
    scanf("%d", &saltosTotales);
    for (int i = 0; i < saltosTotales; i++)
    {
        scanf("%d", &sapoQueSalta);
        resultadoBusqueda = binarySearch(poslibres, 0, nposlibres , saposlista[sapoQueSalta - 1]) * -1;
        printf("%d\n", poslibres[resultadoBusqueda]);

        auxiliar = poslibres[resultadoBusqueda];
        poslibres[resultadoBusqueda] = saposlista[sapoQueSalta - 1];
        saposlista[sapoQueSalta - 1] = auxiliar; 
    }    
}