#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "menu.h"



void menu(sEmployee employeeList[], int len)
{
    int answer;
    int flag;
    int flagAdd;
    int flagModify;
    int flagRemove;
    int flagPrint;

    do
    {
        system("cls");
        answer = printMenu();

        switch(answer)
        {
        case 1:
            flagAdd = addAllEmployees(employeeList, len);
            if(flagAdd == 0)
            {
                printf("\nNo hay mas lugar en el sistema.\n");
                system("pause");
            }
            break;

        case 2:
            flag = searchEmployee(employeeList, len);
            if(flag == 1)
            {
                printEmployees(employeeList, len);
                modifyEmployee(employeeList, len);
            }
            else
            {
                printf("\nSin datos para modificar.\n");
                system("pause");
            }
            break;

        case 3:
            flag = searchEmployee(employeeList, len);
            if(flag == 1)
            {
                printEmployees(employeeList, len);
                flagRemove = removeEmployee(employeeList, len);
                if(flagRemove == 1)
                {
                    printf("\nEmpleado removido.\n");
                    system("pause");
                }
                else
                {
                    printf("\nOperacion cancelada.\n");
                    system("pause");
                }
            }
            else
            {
                printf("\nNo hay empleados para remover.\n");
                system("pause");
            }
            break;

        case 4:
            flag = searchEmployee(employeeList, len);
            if(flag == 1)
            {
                flagPrint = printEmployees(employeeList, len);
                if(flagPrint == 1)
                {
                    system("pause");
                    showMenu(employeeList, len);
                }
            }
            else
            {
                printf("\nNo hay empleados que mostrar.\n");
                system("pause");
            }
            break;

        case 5:
            printf("Hasta luego.\n");
            break;

        default:
            printf("\nError, por favor use numeros para seleecionar la opcion.\n");
            system("pause");
            break;
        }
    }
    while(answer != 5);
}
