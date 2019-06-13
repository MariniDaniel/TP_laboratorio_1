#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Employee.h"
#include "menu.h"
#define RET_OK 1
#define RET_ERR 0

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int respuesta = RET_ERR;
    FILE* pFile = fopen(path, "r");

    if(pFile == NULL)
    {
        printf("\nEl archivo no existe.\n");
    }
    else
    {
        respuesta = ll_clear(pArrayListEmployee);
        respuesta = parser_EmployeeFromText(pFile, pArrayListEmployee);
    }

    return respuesta;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int respuesta = RET_ERR;
    FILE* pFile = fopen(path, "rb");

    if(pFile == NULL)
    {
        printf("\nEl archivo no existe.\n");
    }
    else
    {
        respuesta = ll_clear(pArrayListEmployee);
        respuesta = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    }

    return respuesta;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* e = employee_new();
    int id;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;
    int respuesta = RET_ERR;

    if(pArrayListEmployee == NULL)
    {
        printf("No hay datos en la lista.\n");
    }
    else
    {
        printf("Ingrese un ID:  ");
        scanf("%d", &id);
        respuesta = employee_setId(e,id);

        printf("\nIngrese un Nombre: ");
        scanf("%s", nombre);
        respuesta = employee_setNombre(e,nombre);

        printf("\nIngrese Horas Trabajadas: ");
        scanf("%d", &horasTrabajadas);
        respuesta = employee_setHorasTrabajadas(e, horasTrabajadas);

        printf("\nIngrese un Sueldo: ");
        scanf("%d", &sueldo);
        respuesta = employee_setSueldo(e, sueldo);

        respuesta = ll_add(pArrayListEmployee, e);
    }

    return respuesta;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int respuesta = RET_ERR;
    int idEmployee = 0;
    int idEmployeeEdit = 0;
    void* aux = employee_new();
    char name[20];
    int horasTrabajadas = 0;
    int sueldo = 0;

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese un ID\n");
        scanf("%d", &idEmployeeEdit);

        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            aux = ll_get(pArrayListEmployee, i);

            respuesta = employee_getId((Employee*) aux, &idEmployee);

            if(respuesta == RET_OK)
            {
                if(idEmployee == idEmployeeEdit)
                {
                    switch(mostrarMenuEdit())
                    {
                    case 1:

                        printf("Ingrese un nombre.\n");
                        scanf("%s", name);
                        respuesta = employee_setNombre((Employee*)aux, name);
                        break;
                    case 2:

                        do
                        {
                            printf("Ingrese Horas Trabajadas\n");
                            scanf("%d", &horasTrabajadas);
                            respuesta = employee_setHorasTrabajadas((Employee*) aux, horasTrabajadas);
                        }
                        while(horasTrabajadas < 0);
                        break;
                    case 3:

                        do
                        {
                            printf("Ingrese Sueldo\n");
                            scanf("%d", &sueldo);
                            respuesta = employee_setSueldo((Employee*) aux, sueldo);
                        }
                        while(sueldo < 0);
                        break;
                    default:
                        break;
                    }

                    if(respuesta == RET_ERR)
                    {
                        printf("\nProblemas pata modificar el campo.\n");
                    }

                    respuesta = ll_set(pArrayListEmployee, i, aux);
                    break;
                }
            }
        }
    }
    else
    {
        printf("No hay datos en la lista.\n");
    }

    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int respuesta = RET_ERR;
    int idEmployee;
    int idEmployeeRemove;
    Employee* aux = employee_new();

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese un ID\n");
        scanf("%d", &idEmployeeRemove);

        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            aux = (Employee*) ll_get(pArrayListEmployee, i);

            respuesta = employee_getId(aux, &idEmployee);

            if(respuesta == RET_OK)
            {
                if(idEmployee == idEmployeeRemove)
                {
                    respuesta = ll_remove(pArrayListEmployee, i);
                    break;
                }
            }
        }
    }
    else
    {
        printf("No hay datos en la lista.\n");
    }

    return respuesta;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int respuesta = RET_ERR;
    Employee* emp = employee_new();
    int l = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL)
    {
        printf("ID          Nombre        Hs T.  Sueldo\n");
        for(int i = 0; i < l; i++)
        {
            emp = (Employee*) ll_get(pArrayListEmployee, i);
            employee_show(emp);
        }
    }
    else
    {
        printf("No hay datos en la lista.\n");
    }
    return respuesta;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int order;
    int respuesta;

    if(pArrayListEmployee == NULL)
    {
        printf("No hay datos en la lista.\n");
    }
    else
    {
        opcion = menuSort();
        order = menuAscDesc();

        switch(opcion)
        {
        case 1:

            respuesta = ll_sort(pArrayListEmployee, employee_sortById, order);
            break;

        case 2:
            respuesta = ll_sort(pArrayListEmployee, employee_sortByName, order);
            break;

        case 3:
            respuesta = ll_sort(pArrayListEmployee, employee_sortByWorkHours, order);
            break;

        case 4:
            respuesta = ll_sort(pArrayListEmployee, employee_sortBySalary, order);
            break;
        }
    }

    return respuesta;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int respuesta = RET_ERR;
    int longitud;

    if(ll_len(pArrayListEmployee) == 0)
    {
        printf("No hay datos en la lista.\n");
    }
    else
    {
        FILE *pFile = fopen(path,"w");
        Employee* pEmployee = employee_new();
        if(pFile==NULL)
        {
            printf("Archivo inexistente\n");
        }
        else
        {
            longitud = ll_len(pArrayListEmployee);
            for(int i = 0; i < longitud; i++)
            {
                pEmployee = (Employee*) ll_get(pArrayListEmployee, i);

                fprintf(pFile, "%d, %s, %d, %d\n", pEmployee->id, pEmployee->nombre, pEmployee->horasTrabajadas, pEmployee->sueldo);    //Se escribe al archivo

            }
            respuesta = RET_OK;
            fclose(pFile);
        }
    }

    return respuesta;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int respuesta = RET_ERR;
    int cantidad = 0;
    int longitud;

    if(ll_len(pArrayListEmployee) == 0)
    {
        printf("No hay datos en la lista.\n");
    }
    else
    {
        FILE *pFile = fopen(path,"wb");
        Employee* pEmployee = employee_new();
        if(pFile==NULL)
        {
            printf("Archivo inexistente\n");
        }
        else
        {
            longitud = ll_len(pArrayListEmployee);

            for(int i = 0; i < longitud; i++)
            {
                pEmployee = (Employee*) ll_get(pArrayListEmployee, i);

                cantidad = fwrite(pEmployee, sizeof(Employee), 1, pFile );    //Se escribe al archivo

                if(cantidad != 1)
                {
                    printf("\nError al escribir el archivo");
                }
            }
            respuesta = RET_OK;
            fclose(pFile);
        }
    }

    return respuesta;
}

