#include"Cola.h"
#include<iostream>
#include<string.h>

using namespace std;

Alumno::Alumno() : nombre("juanito"), carrera("inco"), materias(0), promedio(0.0) {}
Alumno::Alumno(string n, string nC, int mA, float pG) : nombre(n), carrera(nC), materias(mA), promedio(pG) {}
void Alumno::operator=(Alumno& x)
{
    nombre=x.nombre;
    carrera=x.carrera;
    materias=x.materias;
    promedio=x.promedio;
}
ostream& operator<<(ostream& cout, Alumno& dato)
{
    cout<<"Constancia de Alumno\n\nNombre: "<<dato.nombre<<"\t\tCarrera: "<<dato.carrera<<endl<<"Materias:"<<dato.materias<<"\t\t Promedio: "<<dato.promedio;
    return cout;
}
ostream& operator<<(ostream& cout, Cola& L)
{
    int i = 0;
    cout << "\n";
    while (i <= L.ultimo())
    {
        cout << L.datos[i];
        i++;
    }
    return cout;
}
istream& operator>>(istream& cin, Alumno& dato)
{
    cout<<"\n Nombre: ";
    cin.ignore();
    getline(cin, dato.nombre);
    cout<<"\n Carrera: ";
    getline(cin, dato.carrera);
    cout<<"\n Materias: ";
    cin>>dato.materias;
    cout<<"\n Promedio: ";
    cin>>dato.promedio;
    return cin;
}

bool Alumno::operator<(const Alumno& otro) const
{
    return nombre < otro.nombre;
}

bool Cola::vacia()const
{
    if(ult==-1)
    {
        return true;
    }else
    {
        return false;
    }
}
bool Cola::llena()const
{
    if(ult==TAM-1)
    {
        return true;
    }else
    {
        return false;
    }
}

int Cola::ultimo()const
{
    return ult;
}

void Cola::enqueue(Alumno& elem)
{
    Cola::inserta(elem,ult+1);
}

void Cola::dequeue()
{
    if(vacia()){
        cout<<"\n No hay solicitudes pendientes"<<endl;
    }
    else{
        Cola::elimina(0);
    }
}

bool Cola::elimina(int pos)
{
    if(vacia() || pos<0 || pos>ult)
    {
        cout<<"\n Error de eliminacion";
        return true;
    }
    cout <<datos[pos];
    int i=pos;
    while(i<ult)
    {
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return false;
}
int Cola::inserta(Alumno& elem, int pos)
{
    if(llena()|| pos<0 || pos>ult+1)
    {
        cout<<"\n Error de insercion";
        return 0;
    }
    int i=ult+1;
    while(i>pos)
    {
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return 1;
}
int Cola::busquedaLineal(Alumno& elem)
{
      int constanciasAntes = 0;

      if (vacia())
    {
        return -1;
    }


    for (int i = 0; i <= ult; i++)
    {
        if (elem == datos[i])
        {
            return constanciasAntes;
        }
        constanciasAntes++;
    }

    return -1;
}

int Cola::busquedaBinaria(Alumno& elem)
{
    if (vacia())
    {
        return -1;
    }

    int inicio = 0, fin = ultimo();

    while (inicio <= fin)
    {
        int medio = (inicio + fin) / 2;
        if (elem < datos[medio])
        {
            fin = medio - 1;
        }
        else if (datos[medio] < elem)
        {
            inicio = medio + 1;
        }
        else
        {
            return medio;
        }
    }

    return -1;
}
