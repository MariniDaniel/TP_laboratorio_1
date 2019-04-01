#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    float numUno;
    float numDos;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    int opcion;
    int factUno;
    int factDos;
    int flagSalida = 1;
    int flag3=0;
    int flag2=0;
    int flag1=0;


    do
    {
        printf("<----CALCULADORA UNT2019 1F---->\n\n");

        if(flag1==1)
        {
            printf("1- Ingresar 1er operando (A=%.2f)\n",numUno);

        }
        else
        {
            printf("1- Ingresar 1er operando (A=x)\n");
        }
        if(flag2==1)
        {
            printf("2- Ingresar 2do operando (B=%.2f)\n",numDos);

        }
        else
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        printf("3. Calcular.\n");
        printf("4. Informar.\n");
        printf("5. Salir.\n");
        printf("\nIngrese una opcion del menu:");
        fflush(stdin);
        scanf("%d", &opcion);

        if(opcion>5)
        {
            printf("Ingrese una opcion valida");
        }


        switch(opcion)
        {
        case 1:
            ingresarNumero(&numUno);
            flag1 = 1;
            break;
        case 2:
            ingresarNumero(&numDos);
            flag2 = 1;
            break;
        case 3:
            if(flag1==1&&flag2==1)
            {
                printf("\nCalculado...\n");
                resultadoSuma=suma(numUno,numDos);
                resultadoResta=resta(numUno,numDos);
                resultadoDivision=division(numUno,numDos);
                resultadoMultiplicacion=multiplicacion(numUno,numDos);
                factUno=factorial(numUno);
                factDos=factorial(numDos);
                flag3=1;

                break;
            }
            else
                printf("Debe ingresar los operandos\n");
            break;

        case 4:
            if(flag1==1&&flag2==1&&flag3==1)
            {
                printf("\n\nLa suma de los numeros es: %.2f\n",resultadoSuma);

                printf("La resta de los numeros es: %.2f\n",resultadoResta);

                if(numDos==0)
                {
                    printf("No es posible dividir por 0\n");

                }
                else
                {
                    printf("La division de los numeros es: %.2f\n",resultadoDivision);
                }

                printf("La multiplicacion de los numeros es: %.2f\n",resultadoMultiplicacion);


                if(numUno>0)
                {
                    printf("El factorial de A es:  %d\n", factUno);
                }
                else
                {
                    printf("ERROR, el factorial se calcula solo con numeros enteros positivos\n");
                }


                if(numDos>0)
                {
                    printf("El factorial de B es:  %d\n", factDos);
                }
                else
                {
                    printf("ERROR, el factorial se calcula solo con numeros enteros positivos.\n");

                }


            }
            else

                printf("ERROR,Debe calcular antes de mostrar resultado. \n");
            break;

        case 5:


            printf("Saliendo...");
            flagSalida = 0;
            break;

        default:
            break;
        }
        fflush(stdin);
        printf("\nIngrese ENTER para continuar...");
        system("pause");
        system("cls");

    }
    while(flagSalida != 0);


    return 0;

}
