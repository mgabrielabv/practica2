#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Persona
{
    int id_del_registro;
    char nombre[40];
    float cedula;
    int edad;
    float peso;
    float altura;
    char genero;
};
int main ()
{
    int registro_x;
    cout << "Registro  a leer:  ";
    cin >> registro_x;
    ifstream archivo ("personas.dat", ios::binary);
    if (!archivo){
        cerr << "no se pudo abrir el archivo.\n";
        return 1;
    }
    archivo.seekg((registro_x -1)*sizeof(Persona));
    Persona persona;
    archivo.read (reinterpret_cast<char*>(&persona), sizeof(Persona));
    archivo.close();

    cout<< "Datos del registro /"<< registro_x<< ": \n";
    cout<< "ID del registro :" << persona.id_del_registro  <<  "\n";
    cout<< "Nombre :"<< persona.nombre << "\n";
    cout<< "cedula :"<< persona.cedula << "\n";
    cout<< "Edad :" << persona.edad << "\n";
    cout<< "Peso :"<< persona.peso << "\n";
    cout<< "Altura :"<< persona.altura << "\n";
    cout<< "Genero (M/ F): " << persona.genero<< "\n";

   return 0;



}
