#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const char *nombre_archivo = "archivo.dat";
const char *nombre2 = "temporal.dat";

struct Empleado{

	int codigo;

	char nombres[50];

	char apellidos[50];

	char puesto[50];
	
	float sueldo;
	
	int bonificacion = 250;
	
	float total;

};

void ingresar();
void menu();
void abrir();
void buscar_id();
void buscar_codigo();
void eliminar();
void ver();
void modificar_empleado();

main(){
    system("title Steven Arrecis");
	menu();
}

void menu(){
    system("cls");
    int opc;
    do{
        cout<<"\n\t\t.:BIENVENIDO:.\n\n"<<endl;
        cout<<"\n1. Ingresar."<<endl;
        cout<<"2. Ver Registros."<<endl;
        cout<<"3. Buscar Codigo."<<endl;
        cout<<"4. Eliminar."<<endl;
        cout<<"5. Editar Dato."<<endl;
        cout<<"6. Salir."<<endl;
        cout<<"Digite una opcion: ";
        cin>>opc;

        switch(opc){
            case 1: ingresar(); break;
            case 2: abrir(); break;
            case 3: buscar_codigo(); break;
            case 4: eliminar(); break;
            case 5: modificar_empleado(); break;
            case 6: exit(1); break;
        }

    }while(opc !=5);

}

void abrir(){

	system("cls");

    cout<<"\n\t\t\t.:REGISTROS:.\n\n"<<endl;

	FILE* archivo = fopen(nombre_archivo,"rb");

	if (!archivo){

		archivo = fopen(nombre_archivo,"w+b");

	}

	Empleado empleado;

	int id= 0;

	fread(&empleado,sizeof(Empleado),1,archivo);

	cout<<"id |"<<"Codigo |"<<"Nombres   |"<<"Apellidos   |"<<"Puesto       |"<<"Sueldo   |"<<"Sueldo Total   |"<<endl;

	do{

	cout<<id<<" |"<<empleado.codigo<<" |"<<empleado.nombres<<"  |"<<empleado.apellidos<<"  |"<<empleado.puesto<<"  |"<<empleado.sueldo<<"  |"<<empleado.total<<endl;

	fread(&empleado,sizeof(Empleado),1,archivo);

		id+=1;

	} while(feof(archivo) ==0);

	fclose(archivo);

    cout<<"\n\n";
    system("pause");
    menu();

}



void ingresar(){
    system("cls");
	char continuar;
    cout<<"\n\t\t\t.:Agregando Datos\n\n"<<endl;

	FILE* archivo = fopen(nombre_archivo,"ab");

	Empleado empleado;

	string nombre,apellido,puesto;
	

	do{

		fflush(stdin);

		cout<<"Ingrese el Codigo: ";

		cin>>empleado.codigo;

		cin.ignore();

		

		cout<<"Ingrese Los Nombres: ";

		getline(cin,nombre);

		strcpy(empleado.nombres,nombre.c_str());

		cout<<"Ingrese Los Apellidos: ";

		getline(cin,apellido);

		strcpy(empleado.apellidos,apellido.c_str());

		cout<<"Ingrese el Puesto: ";

		getline(cin,puesto);
		strcpy(empleado.puesto,puesto.c_str());

		cout<<"Ingrese el Sueldo: ";
		cin>>empleado.sueldo;
	

		empleado.total = empleado.sueldo + empleado.bonificacion;
		fwrite(&empleado,sizeof(Empleado),1,archivo);

		cout<<"Desea ingresar otro dato (s/n):";

		cin>>continuar;

	} while (continuar=='s' || continuar=='S');

	fclose(archivo);

	cout<<"\n\n\t\t\tDATOS AGREGADOS...\n\n";
    system("pause");
    menu();

}



/*
void buscar_id(){

	FILE* archivo = fopen(nombre_archivo,"rb");	

	int id;

	cout<<"Ingrese el ID que desea ver: ";

	cin>>id;

	fseek(archivo,id*sizeof(Empleado),SEEK_SET);

	Empleado empleado;

	fread(&empleado,sizeof(Empleado),1,archivo);

	cout<<"Codigo: "<<empleado.codigo<<endl;

	cout<<"Nombres: "<<empleado.nombres<<endl;

	cout<<"Apellidos: "<<empleado.apellidos<<endl;

	cout<<"Puesto: "<<empleado.puesto<<endl;

	fclose(archivo);

}*/




void buscar_codigo(){

    system("cls");
    cout<<"\n\t\t\t.: Buscar Empleado:.\n\n"<<endl;

	FILE* archivo = fopen(nombre_archivo,"rb");	

	int codigo;

	cout<<"Ingrese el Codigo: ";

	cin>>codigo;

	

	Empleado empleado;

	fread(&empleado,sizeof(Empleado),1,archivo);

	do{

		if(empleado.codigo == codigo){

			cout<<"______________________"<<endl;

			cout<<"Codigo: "<<empleado.codigo<<endl;

			cout<<"Nombres: "<<empleado.nombres<<endl;

			cout<<"Apellidos: "<<empleado.apellidos<<endl;

			cout<<"Puesto: "<<empleado.puesto<<endl;

			cout<<"Sueldo: "<<empleado.sueldo<<endl;

			cout<<"Sueldo Total (+ bonificacion): "<<empleado.total<<endl;

		}

		fread(&empleado,sizeof(Empleado),1,archivo);

	} while (feof(archivo)==0);

	

	

	fclose(archivo);

    cout<<"\n\n";
    system("pause");
    menu();

}

void ver(){
	cout<<"\n\t\t\t.:REGISTROS:.\n\n"<<endl;

	FILE* archivo = fopen(nombre_archivo,"rb");

	if (!archivo){

		archivo = fopen(nombre_archivo,"w+b");

	}

	Empleado empleado;

	int id= 0;

	fread(&empleado,sizeof(Empleado),1,archivo);

	cout<<"id |"<<"Codigo |"<<"Nombres   |"<<"Apellidos   |"<<"Puesto       |"<<"Sueldo   |"<<"Sueldo Total   |"<<endl;

	do{

	cout<<id<<" |"<<empleado.codigo<<" |"<<empleado.nombres<<"  |"<<empleado.apellidos<<"  |"<<empleado.puesto<<"  |"<<empleado.sueldo<<"  |"<<empleado.total<<endl;

	fread(&empleado,sizeof(Empleado),1,archivo);

		id+=1;

	} while(feof(archivo) ==0);

	fclose(archivo);

    cout<<"\n\n";
}

void modificar_empleado(){
	
	FILE* archivo = fopen(nombre_archivo, "r+b");
		ver();
		int id;
		string nombre,apellido,puesto;	
    	Empleado empleado;
        
    
		cout <<"\n\nIngrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Empleado), SEEK_SET );  // esto es lo que permite modificar en la pocision
	
		cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(empleado.nombres, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(empleado.apellidos, apellido.c_str()); 
		
		cout<<"Ingrese el Puesto:";
		getline(cin,puesto);
		strcpy(empleado.puesto,puesto.c_str()); 

		cout<<"Ingrese el Sueldo: ";
		cin>>empleado.sueldo;
		
		empleado.total = empleado.sueldo + empleado.bonificacion;
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
	fclose(archivo);
		system("PAUSE");
}


void eliminar(){
    system("cls");
    cout<<"\n\t\t.:Eliminar Registro:.\n"<<endl;
	FILE* archivo = fopen(nombre_archivo,"rb");
    FILE* archivo2 = fopen(nombre2,"w+b");
	if (!archivo){

		archivo = fopen(nombre_archivo,"w+b");

	}

	int id= 0, codigo;
    string nombre,apellido;

	cout<<"Ingrese el Codigo para eliminar: ";

	cin>>codigo;

	Empleado empleado;

	fread(&empleado,sizeof(Empleado),1,archivo);

	do{
        
		if(empleado.codigo == codigo){
            cout<<"Datos eliminados..\n\n"<<endl;
            system("pause");
            fread(&empleado,sizeof(Empleado),1,archivo);
        }

        else{
            
            fwrite(&empleado,sizeof(Empleado),1,archivo2);
            fread(&empleado,sizeof(Empleado),1,archivo);
            id+=1;
        }

	} while (feof(archivo)==0);

	fclose(archivo);
    fclose(archivo2);
    remove("archivo.dat");
    rename("temporal.dat","archivo.dat");

    cout<<"\n\n";
    system("pause");
    menu();
    

}
