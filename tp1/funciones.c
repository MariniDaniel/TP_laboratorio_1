#include "funciones.h"
#include <stdio.h>
/** \brief sumar dos numeros
 * \param A variable float a sumar
 * \param B variable float a sumar
 * \return total de la suma
 *
 */

float suma(float A, float B)
{
    float total;
    total=A+B;
    return total;
}
/** \brief restar dos numeros
 * \param A variable float a restar
 * \param B variable float a restar
 * \return total de la resta
 *
 */

float resta(float A, float B)
{
    float total;
    total=A-B;
    return total;
}
/** \brief dividir dos numeros
 * \param A variable float dividendo
 * \param B variable float divisor
 * \return total de la division
 *
 */
float division(float A, float B)
{

       float total;
        total=A/B;
        return total;
}
/** \brief multiplicar dos numeros
 * \param A variable float a multiplicar
 * \param B variable float a multiplicar
 * \return total de la multiplicacion
 *
 */
float multiplicacion(float A, float B)
{
    float total;
    total=A*B;
    return total;
}
/** \brief sacar factorial de un numero
 * \param  variable int a factorizar
 * \return valor del factorial
 *
 */
int factorial (int A)
{
    int resultadoFactorial=1;
    int i;

    for(i=(int)A; i>=1; i--)
    {
        resultadoFactorial= resultadoFactorial*i;
    }

    return resultadoFactorial;
}
/** \brief  Ingresar numero por usuario
 * \param  numero a guardar
 * \return valor de numero guardado
 *
 */
void ingresarNumero(float* pNumero)
{
    printf("Ingrese un numero: ");
    fflush(stdin);
    scanf("%f", pNumero);
}

