#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include<iostream>
using namespace std;
const int TAM = 10;

class Alumno
{
private:
    string nombre, carrera;
    int materias;
    float promedio;
public:
    Alumno();
    Alumno(string n, string nC, int mA, float pG);
    Alumno& operator=(const Alumno& x);
    void operator=(Alumno& x);
    friend ostream& operator<<( ostream&, Alumno&);
    friend istream& operator>>( istream&, Alumno&);
    bool operator==(const Alumno& p) const
    {
        return p.nombre == nombre && p.carrera == carrera && p.materias == materias && p.promedio == promedio;
    }
    bool operator<(const Alumno& otro) const;
};

class Cola
{
private:
    Alumno datos[TAM];
    int ult;
public:
     Cola() : ult(-1) {}
    friend ostream& operator<<(ostream& o, Cola& L);
    bool vacia()const,llena()const,elimina(int pos);
    int ultimo()const,inserta(Alumno& elem, int pos);
    void enqueue(Alumno& elem);
    void dequeue();
    int busquedaLineal(Alumno& elem), busquedaBinaria(Alumno& elem);
    void quicksort(Alumno& elem,int inicio,int final);

};

#endif // COLA_H_INCLUDED
