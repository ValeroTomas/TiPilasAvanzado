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

    printf(" ||==================================================================|| \n");
    printf(" ||(100)================|BANCO CENTRAL ARGENTINA|===============(100)|| \n");
    printf(" ||\\$//        ~         '-------========--------'               \\$//|| \n");
    printf(" ||<< /        /$\              // ____ \\                          \ >>|| \n");
    printf(" ||>>|        //E\\            // ///..) \\              2023       |<<|| \n");
    printf(" ||<<|        \\A//           || <||  >\  ||                        |>>|| \n");
    printf(" ||>>|         \$/            ||  $$ --/  ||            EL JOTA    |<<|| \n");
    printf(" ||<<|       TP PILAS         *\\  |\_/  //*                        |>>|| \n");
    printf(" ||>>|                         *\\/___\_//*                         |<<|| \n");
    printf(" ||<<\       AVANZADO     _____/ J PERALES \________    DOBLE T     />>|| \n");
    printf(" ||//$\                 ~|    REPUBLICA ARGENTINA    |~            /$\\|| \n");
    printf(" ||(100)==================     CIEN MIL PESITOS   ==============(100)|| \n");
    printf(" ||==================================================================|| \n");
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

    case 5:
        //Insertar un elemento en una pila ordenada de menor (tope) a mayor (base) de forma tal que se conserve el orden. (sin variables enteras, solo pilas)
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
            else
            {
                apilar(&aux1, desapilar(&a));
            }
        }

        while(!pilavacia(&aux1))
        {
            apilar(&dada, desapilar(&aux1));
        }

        mostrar(&dada);

        break;

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

    case 7:

        break;

    case 8:

        break;

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

    case 10:

        break;

    case 11:

        break;

    case 12:

        break;

    case 13:

        break;

    default:
        ;



    }








}
