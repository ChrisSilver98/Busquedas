#include <iostream>
#include "Cola.h"
#include <stdlib.h>
#include<conio.h>

int main()
{
    Cola MiCola;
    Alumno x;
    int opcion;

    do
    {
        system("cls");
        cout << "\nControl Escolar\nMenu" << endl;
        cout << "1) Dar de alta la solicitud de un alumno" << endl;
        cout << "2) Elaborar una constancia" << endl;
        cout << "3) Buscar una solicitud" << endl;
        cout << "4) Salir" << endl;
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            system("cls");
            cout << "\nIngrese los datos del alumno\n";
            cout << "----------------------------";
            cin >> x;
            MiCola.enqueue(x);
            getch();
            break;

        case 2:
            system("cls");
            if (!MiCola.vacia())
            {
                cout << "\nSe ha elaborado una constancia para el alumno\n";
                cout << "------------------------------------------------------------------------------------\n";
                MiCola.dequeue();
            }
            else
            {
                cout << "\nNo hay solicitudes pendientes, debe dar de alta una solicitud primero.\n" << endl;
            }
            getch();
            break;

        case 3:
            system("cls");
            if (!MiCola.vacia())
            {
                cout << "\nIngrese los datos del alumno a buscar: \n";
                cin >> x ;
                cout << "-------------------------------------";
                int posicion = MiCola.busquedaLineal(x);
                if (posicion == -1)
                {
                    cout << "El alumno no ha generado una constancia." << endl;
                }
                else
                {
                    int constanciasAntes = posicion;
                    cout << "\nEl alumno tiene la posicion: " << posicion+1 << endl;
                    cout << "\nConstancias que deben elaborarse antes del alumno: " << constanciasAntes << endl;
                }
            }
            else
            {
                cout << "\nNo hay pendientes, debe dar de alta una solicitud primero.\n" << endl;
            }
            getch();
            break;

        case 4:
            cout << "\nSaliendo del programa...\n" << endl;
            getch();
            break;

        default:
            cout << "Opcion no valida. Por favor, seleccione una opcion valida." << endl;
            getch();
        }
    }
    while (opcion != 4);

    return 0;
}
