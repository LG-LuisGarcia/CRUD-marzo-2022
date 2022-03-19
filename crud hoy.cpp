#include <iostream>
#include <string.h>
#include<stdio.h>

using namespace std;
const char *nombre_archivo = "archivo.dat";
struct Estudiante{
int codigo;
char nombres[50];
char apellidos[50];
char direccion[50];
int telefono;
};
void crear();
void leer();
void actualizar();
void eliminar ();
main(){
leer();
crear();
actualizar();
eliminar ();
}
void leer(){

FILE* archivo = fopen(nombre_archivo,"rb");
if (!archivo){
archivo = fopen(nombre_archivo,"w+b");
}
Estudiante estudiante;
int id=0;
fread(&estudiante,sizeof(Estudiante),1,archivo);
cout<<"____________________________________________"<<endl;
cout<<"id"<<"|"<<"Codigo"<<"|"<<"Nombres"<<"|"<<"Apellidos"<<"|"<<"Direccion"<<"|"<<"Telefono"<<endl;
do{
cout<<"____________________________________________"<<endl;
cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.direccion<<"|"<<estudiante.telefono<<endl;
fread(&estudiante,sizeof(Estudiante),1,archivo);
id+=1;
}while(feof(archivo)==0);
fclose(archivo);
cout<<endl;
}
void actualizar(){
FILE* archivo = fopen(nombre_archivo,"r+b");
int id;
Estudiante estudiante;
string nombre,apellido,direccion;
cout<<"Ingres el ID que desa Modificar:";
cin>>id;
fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
cout<<"Ingrese el Codigo:";
cin>>estudiante.codigo;
cin.ignore();
cout<<"Ingrese los Nombres:";
getline(cin,nombre);
strcpy(estudiante.nombres,nombre.c_str());
cout<<"Ingrese los Apellidos:";
getline(cin,apellido);
strcpy(estudiante.apellidos,apellido.c_str());
cout<<"Ingrese la direccion:";
getline(cin,direccion); 
strcpy(estudiante.direccion,direccion.c_str());
cout<<"Ingrese el Telefono:";
cin>>estudiante.telefono;
cin.ignore();

fwrite(&estudiante,sizeof(Estudiante),1,archivo);
fclose(archivo);
leer();
}
void crear(){
char continuar;
FILE* archivo = fopen(nombre_archivo,"ab");
Estudiante estudiante;
string nombre,apellido,direccion;
do{
fflush(stdin);
cout<<"Ingrese el Codigo:";
cin>>estudiante.codigo;
cin.ignore();
cout<<"Ingrese los Nombres:";
getline(cin,nombre);
strcpy(estudiante.nombres,nombre.c_str());
cout<<"Ingrese los Apellidos:";
getline(cin,apellido);
strcpy(estudiante.apellidos,apellido.c_str());
cout<<"Ingrese la direccion:";
getline(cin,direccion);
strcpy(estudiante.direccion,direccion.c_str());
cout<<"Ingrese el Telefono:";
cin>>estudiante.telefono;
cin.ignore();
fwrite(&estudiante,sizeof(Estudiante),1,archivo);
cout<<"Desea Agregar otro Estudiante (s/n):";
cin>>continuar;
} while ( (continuar=='s') || (continuar=='S') );
fclose(archivo);
leer();
}
void eliminar (){

FILE* archivo = fopen(nombre_archivo,"r+b");
int id;
Estudiante estudiante;
string nombre,apellido,direccion;
cout<<"Ingrese el Id del registro que desee a Eliminar:";
cin>>id;
fseek(archivo,id *sizeof(Estudiante),SEEK_SET);

estudiante.codigo=0;
estudiante.nombres[50]=0;
estudiante.apellidos[50]=0;
estudiante.direccion[50]=0; 
estudiante.telefono=0;

cout << "\nEstudiante eliminado correctamente" << endl;

fwrite(&estudiante,sizeof(Estudiante),1,archivo);
fclose(archivo);
           
  }

