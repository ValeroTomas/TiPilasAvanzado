#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila aux1, aux2, capicua, mayor, menor, dada, a, b, c, ordenada1, ordenada2, ordenadafinal, origen, mazo, puntosJug1, puntosJug2;
    inicpila(&aux1);
    inicpila(&capicua);
    inicpila(&aux2);
    inicpila(&mayor);
    inicpila(&menor);
    inicpila(&dada);
    inicpila(&a);
    inicpila(&b);
    inicpila(&c);
    inicpila(&ordenada1);
    inicpila(&ordenada2);
    inicpila(&ordenadafinal);
    inicpila(&origen);
    inicpila(&mazo);
    inicpila(&puntosJug1);
    inicpila(&puntosJug2);
    char opc;
    int punto;
    int var;
    int contador;
    int flag;

    printf(" ||==================================================================||\n");
    printf(" ||=Punto-1                         |                       Punto-8 =||\n");
    printf(" ||=Punto-2                         |                       Punto-9 =||\n");
    printf(" ||=Punto-3                         |                       Punto-10=||\n");
    printf(" ||=Punto-4                         |                       Punto-11=||\n");
    printf(" ||=Punto-5                         |                       Punto-12=||\n");
    printf(" ||=Punto-6                         |                       Punto-13=||\n");
    printf(" ||=Punto-7                         |                               =||\n");
    printf(" ||==================================================================||\n");

    printf(" Ingresar punto: ");
    scanf("%i", &punto);

    switch(punto)
    {
    //EJERCICIO 1 *COMPLETO*
    case 1:
        //Sumar los elementos de una pila (usar variables enteras)
        var=0;

        //CICLO DE CARGA
        printf("INGRESE VALORES A SUMAR\n");
        do
        {
            leer(&a);
            printf("\nINGRESE ""s"" PARA SEGUIR CARGANDO VALORES\n");
            fflush(stdin);
            scanf ("%c", &opc);
        }
        while(opc == 's');

        while(!pilavacia(&a))
        {
            var = var + tope(&a);
            apilar(&aux1, desapilar(&a));
        }

        printf("\nLa suma es: %i",var);
        break;

    //EJERCICIO 2 *COMPLETO*
    case 2:
        //Contar los elementos de una pila (usar variables enteras)
        var=0;
        //CICLO DE CARGA
        printf("INGRESE VALORES\n");
        do
        {
            leer(&a);
            printf("\nINGRESE ""s"" PARA SEGUIR CARGANDO VALORES\n");
            fflush(stdin);
            scanf ("%c", &opc);
        }
        while(opc == 's');
        while(!pilavacia(&a))
        {
            var = var + 1;
            apilar(&aux1, desapilar(&a));
        }

        printf("\nLa pila tiene: %i elementos.",var);
        break;

    //EJERCICIO 3 *COMPLETO*
    case 3:
        //Calcular el promedio de los valores de una pila (usar variables)
        var=0;
        contador=0;

        //CICLO DE CARGA
        printf("INGRESE VALORES A SUMAR\n");
        do
        {
            leer(&a);
            printf("\nINGRESE ""s"" PARA SEGUIR CARGANDO VALORES\n");
            fflush(stdin);
            scanf ("%c", &opc);
        }
        while(opc == 's');

        while(!pilavacia(&a))
        {
            var = var + tope(&a);
            contador = contador + 1;
            apilar(&aux1, desapilar(&a));
        }

        printf("\nEl promedio es: %i",var/contador);

        break;

    //EJERCICIO 4 *COMPLETO*
    case 4:
        //Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables enteras, solo pilas)
        printf("INGRESE VALORES\n");
        do
        {
            leer(&a);
            printf("\nINGRESE ""s"" PARA SEGUIR CARGANDO VALORES\n");
            fflush(stdin);
            scanf ("%c", &opc);
        }
        while(opc == 's');
        while (!pilavacia (&a))
        {
            if (tope(&a)< tope(&menor))
            {
                apilar (&menor, desapilar(&a));
            }
            else
            {
                apilar (&aux1, desapilar (&a));
            }
        }
        while (!pilavacia(&aux1))
        {
            apilar (&a, desapilar (&aux1));
        }

        printf("VALOR MENOR\n");
        mostrar (&menor);
        printf("PILA ORIGINAL SIN EL MENOR\n");
        mostrar (&a);
        break;

    //EJERCICIO 5 *COMPLETO*
    case 5:
        //Insertar un elemento en una pila ordenada de menor (tope) a mayor (base) de forma tal que se conserve el orden.
        //(sin variables enteras, solo pilas)
        apilar (&dada, 9);
        apilar (&dada, 8);
        apilar (&dada, 6);
        apilar (&dada, 5);
        apilar (&dada, 4);
        apilar (&dada, 3);
        apilar (&dada, 2);
        apilar (&dada, 1);
        mostrar(&dada);

        printf("\n\nQue valor insertamos?\n");
        leer(&a);

        while(!pilavacia(&dada))
        {
            if(tope(&dada)<tope(&a))
            {
                apilar(&aux1, desapilar(&dada));
            }
            if(tope(&a) < tope(&dada))
            {
                apilar(&aux1, desapilar(&a));
            }

        }

        while(!pilavacia(&aux1))
        {
            apilar(&dada, desapilar(&aux1));
        }

        mostrar(&dada);
        mostrar(&aux1);
        mostrar(&a);


        break;

    //EJERCICIO 6 *COMPLETO*
    case 6:
        //Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra de forma tal que la
        //segunda pila quede ordenada de mayor (tope) a menor (base). Esto se llama método de
        //ordenación por selección.
        printf("INGRESE VALORES\n");
        do
        {
            leer(&dada);
            printf("\nINGRESE ""s"" PARA SEGUIR CARGANDO VALORES\n");
            fflush(stdin);
            scanf ("%c", &opc);
        }
        while(opc == 's');
        printf("\nPILA DADA:\n");
        mostrar(&dada);

        do
        {
            if(!pilavacia(&aux2))
            {
                while(!pilavacia(&aux2))
                {
                    apilar(&dada,desapilar(&aux2));
                }
            }

            apilar(&aux1, desapilar(&dada));

            while(!pilavacia(&dada))
            {
                if(tope(&dada)<tope(&aux1))
                {
                    apilar(&aux2, desapilar(&aux1));
                    apilar(&aux1, desapilar(&dada));
                }
                else
                {
                    apilar(&aux2, desapilar(&dada));
                }
            }
        }
        while(!pilavacia(&aux2));

        mostrar(&aux1);


        break;

    //EJERCICIO 7 *COMPLETO*
    case 7:
        //Determinar si un elemento buscado está dentro de una pila. Al encontrarlo, finalizar la búsqueda.

        apilar (&dada, 9);
        apilar (&dada, 8);
        apilar (&dada, 7);
        apilar (&dada, 6);
        apilar (&dada, 5);
        apilar (&dada, 4);
        apilar (&dada, 3);
        apilar (&dada, 2);
        apilar (&dada, 1);
        printf("\n\nQue valor buscamos?\n");
        leer(&a);

        mostrar(&dada);
        while(!pilavacia(&dada) && tope(&dada) != tope(&a))
        {
            apilar(&aux1, desapilar(&dada));
        }
        if(tope(&dada) == tope(&a))
        {
            printf("\n\nValor encontrado!\n");
            printf("\n\nTu valor:\n");
            mostrar(&a);
        }
        else
        {
            printf("Tu valor no estaba en la pila.");
            printf("\n\nTu valor:\n");
            mostrar(&a);
        }

        break;

    //EJERCICIO 8 *COMPLETO*
    case 8:
        //Eliminar un elemento de una pila. El eliminarlo, finalizar el recorrido y dejar el resto en el mismo orden.
        apilar (&dada, 9);
        apilar (&dada, 8);
        apilar (&dada, 7);
        apilar (&dada, 6);
        apilar (&dada, 5);
        apilar (&dada, 4);
        apilar (&dada, 3);
        apilar (&dada, 2);
        apilar (&dada, 1);
        flag = 0;

        printf("\n\nQue valor buscamos?\n");
        leer(&a);

        printf("\n\nPILA ORIGINAL");
        mostrar(&dada);

        while(!pilavacia(&dada))
        {
            apilar(&aux1, desapilar(&dada));
            if(tope(&dada)==tope(&a))
            {
                apilar(&aux2, desapilar(&dada));
                flag = 1;
            }
        }
        while(!pilavacia(&aux1))
        {
            apilar(&dada, desapilar(&aux1));
        }

        if (flag==1)
        {
            printf("\n\nTu valor estaba en la pila\n");
        }
        else
        {
            printf("\n\nTu valor NO estaba en la pila");
        }
        printf("\n\nPILA FINAL");
        mostrar(&dada);

        break;

    //EJERCICIO 9 *COMPLETO*
    case 9:
        //NO ENTRAR FUNCIONA JOYA POR FAVOR NO TOCAR *************
        //CICLO DE CARGA
        printf("INGRESE VALORES\n");
        do
        {
            leer(&dada);
            printf("\nINGRESE ""s"" PARA SEGUIR CARGANDO VALORES\n");
            fflush(stdin);
            scanf ("%c", &opc);
        }
        while(opc == 's');

        printf("\nTU PILA:\n");
        mostrar(&dada);

        do
        {
            apilar(&aux1, desapilar(&dada));
            while(!pilavacia(&dada))
            {
                apilar(&aux2, desapilar(&dada));
            }
            if(tope(&aux2) == tope(&aux1))
            {
                apilar(&capicua, desapilar(&aux1));
                apilar(&capicua, desapilar(&aux2));
                while(!pilavacia(&aux2))
                {
                    apilar(&dada, desapilar(&aux2));
                }
                if(pilavacia(&dada))
                {
                    printf("\n\nEs capicua");
                }
            }
            else if(pilavacia(&aux2))
            {
                apilar(&capicua, desapilar(&aux1));
                printf("\n\nEs capicua");
            }
            else
            {
                printf("\n\nNo es capicua");
            }
        }
        while(!pilavacia(&dada));

        break;

    //EJERCICIO 10 *FALTA*
    case 10:
        //Dadas dos pilas A y B que simulan conjuntos (cada conjunto no tiene elementos repetidos
        //sobre sí mismo), realizar un programa que calcule en la pila C la operación de unión.

        break;

    //EJERCICIO 11 *COMPLETO*
    case 11:
        //Intercalar dos pilas ordenadas en forma creciente (ORDENADA1 y ORDENADA2) dejando
        //el resultado en una pila también ordenada en forma creciente (ORDENADAFINAL).
        apilar(&ordenada1, 1);
        apilar(&ordenada1, 6);
        apilar(&ordenada1, 9);
        apilar(&ordenada2, 5);
        apilar(&ordenada2, 8);
        apilar(&ordenada2, 13);

        while(!pilavacia(&ordenada1) && !pilavacia(&ordenada2))
        {
            if(tope(&ordenada1) >= tope(&ordenada2))
            {
                apilar(&aux1, desapilar(&ordenada1));
            }
            else
            {
                apilar(&aux1, desapilar(&ordenada2));
            }
        }

        if(!pilavacia(&ordenada1))
        {
            while(!pilavacia(&ordenada1))
            {
                apilar(&aux1, desapilar(&ordenada1));
            }
        }
        else if(!pilavacia(&ordenada2))
        {
            while(!pilavacia(&ordenada2))
            {
                apilar(&aux1, desapilar(&ordenada2));
            }
        }


        while(!pilavacia(&aux1))
        {
            apilar(&ordenadafinal, desapilar(&aux1));
        }

        mostrar(&ordenadafinal);

        break;

    case 12:
        //Dada la pila ORIGEN ordenarla en forma ascendente por método de inserción dejando el
        //resultado en la pila ORIGEN. Para este ejercicio usar lo aprendido para el ejercicio 5.
        apilar(&origen, 5);
        apilar(&origen, 3);
        apilar(&origen, 1);
        apilar(&origen, 2);
        apilar(&origen, 4);

        while(!pilavacia(&origen))
        {
            apilar(&aux1, desapilar(&origen));
            if(!pilavacia(&origen))
            {
                while(!pilavacia(&origen))
                {
                    if(tope(&origen) > tope(&aux1))
                    {
                        apilar(&mayor, desapilar(&origen));
                    }
                    else
                    {
                        apilar(&menor, desapilar(&origen));
                    }

                }

                    if(!pilavacia(&mayor)){
                        apilar(&mayor, desapilar(&aux1));
                    }
                    else if(!pilavacia(&menor) && pilavacia(&mayor)){
                        apilar(&aux2, desapilar(&aux1));
                    }
                    else{
                        apilar(&menor, desapilar(&aux1));
                    }

                if(!pilavacia(&menor)){
                    while(!pilavacia(&menor)){
                        apilar(&origen, desapilar(&menor));
                    }
                }

                if(!pilavacia(&mayor)){
                    while(!pilavacia(&mayor)){
                        apilar(&origen, desapilar(&mayor));
                    }
                }

                }
            }

            if(!pilavacia(&aux1)){
                apilar(&aux2, desapilar(&aux1));
            }

        mostrar(&aux2);


        break;

    case 13:
        /*Suponer un juego de cartas en el que en cada mano se reparten dos cartas por jugador.
        Un jugador gana la mano cuando la suma de sus cartas es mayor que las del contrario y
        al hacerlo coloca todas las cartas (las de él y las de su rival) en su pila de puntos.
        En caso de empate (y para simplificar) siempre gana el jugador1. Simular la ejecución del
        juego de tal manera que dada una pila MAZO (con un número de elementos múltiplo de cuatro)
        distribuya las cartas en las pilas PUNTOSJUG1 y PUNTOSJUG2 como si estos hubieran jugado.
        Utilizar las pilas auxiliares que crea conveniente.*/

        break;

    default:
        ;



    }








}
