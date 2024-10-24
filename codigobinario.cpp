#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Persona{
    int id_del_registro;
    char nombre[40];
    float cedula;
    int edad;
    float peso;
    float altura;
    char genero;
    

};

int main (){
    int m;
    cout<< "ingrese el numero de personas que desea registrar: \n";
    cin>> m;
    Persona* personas= new Persona[m];

    for (int i = 0; i< m; ++i) {
        cout<< "ingrese los datos de la persona"<< i+1<< ":\n";
        cout<< "Id de registro: ";
        cin>> personas[i].id_del_registro;
        cout<< "Nombre: ";
        cin.ignore( );
        cin.getline (personas[i].nombre,40);
        cout<< "cedula: "; 
        cin>> personas[i].cedula;
        cout<< "Peso:  ";
        cin>> personas[i].peso;
        cout<<  "Altura; ";
        cin>> personas[i].altura;
        cout<< "Genero (M/F):  ";
        cin>> personas[i].genero;
    }
    ofstream archivo("personas.dat", ios::binary);
    archivo.write (reinterpret_cast<char*>(personas), m* sizeof(Persona));
    archivo.close();

    delete[] personas;
    return 0;

}