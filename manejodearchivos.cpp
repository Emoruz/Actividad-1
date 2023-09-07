#include <iostream>
#include <string.h>
#include <windows.h>
#include <fstream>
using namespace std;
void menu();void guardar();void eliminar();void consultar();void buscar();void modificar();void salir();	// void es parecido a switch en la manera de funcionar pero void permite al usuario elegir una opcion antes de entra a un menu especifico como tal como lo haria switch.
char nombre[30],grupo[10];
char mensaje[] = {'Prueba codigo'};
int semestre,edad,auxclave,clave;
bool encontrado;
main()
{
	menu();//	system("PAUSE");    \t\t\t\t\t\t\t\t\t\t\t\t\t
}
void menu()
{
	int opcion;
	do
	{
		cout<<"\n \t\t\t\t\t Manejo de archivos en c++ \n"<<endl;	// /t sirve para tabular o separar el texto del la linea de inicio.
		cout<<"\t\t\t\t\t 1.Guardar"<<endl;
		cout<<"\t\t\t\t\t 2.Eliminar"<<endl;
		cout<<"\t\t\t\t\t 3.Consultar Registros"<<endl;
		cout<<"\t\t\t\t\t 4.Buscar Registros"<<endl;
		cout<<"\t\t\t\t\t 5.Modificar"<<endl;
		cout<<"\t\t\t\t\t 6.Salir"<<endl;
		cout<<"\n \t\t\t\t\t Seleccione una de las Opciones"<<endl;
		cin>>opcion;
		switch(opcion)
			{
			case 1: guardar();	break;
			case 2: eliminar();	break;
			case 3: consultar();break;
			case 4: buscar();	break;
			case 5: modificar();break;
			case 6: salir();	break;
			default: cout<<"La Opcion que Elegiste no hace parte del Menu";	break;	// en C++ default es el sino de Lpp.
			}
	}
	while(opcion!=6);	// en este while se usa el signo "!" como diceferenciador, es decir, en este caso el "!" esta haciendo alucion que al ingresar un numero que sea diferente de 6, que es el total de opciones del menu, se repita el menu para que se pueda seleccionar una opcion que este en dentro de las 6 opciones y no ootro que no este dentro de este menu, el programa solo continuara hasta que se seleccione una respuesta valida
}

void guardar()
{
	ofstream escritura;		// open file
	ifstream consulta;		// input file
	bool repetido=false; 	// aca el boolean al funcionar con verdadero y falso, se iguala la variable que en este caso es "repetido" con false que lo que hace es que el programa busque si el archivo esta repetido, si lo esta, le pedira que ingrese un dato distinto, si no, lo dejara continuar ccomun y corriente.
	
	escritura.open("aprendiz.txt", ios::out|ios::app);	
	consulta.open("aprendiz.txt", ios::in);
	
	if(escritura.is_open() && consulta.is_open())
		{
			system("cls");
			cout<<"ingresa la clave del aprendiz:";
			cin>>auxclave;
			consulta>>clave;
			while(!consulta.eof())
				{
					consulta>>nombre>>semestre>>grupo>>edad;
					if(clave==auxclave)
						{
							cout<<"Ya existe el registro con esa clave"<<endl;
							repetido=true;
							break;
						}
					consulta>>clave;
				}
				if(repetido==false)
					{
						cout<<"Ingresa el Nombre del Aprendiz: ";	cin>>nombre;
						cout<<"Ingresa el Semestre del Aprendiz: " ;cin>>semestre;
						cout<<"Ingresa el Grupo del Aprendiz: ";	cin>>grupo;
						cout<<"Ingresa la Edad del Aprendiz: ";	cin>>edad;
						escritura<<auxclave<<" "<<nombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl;
						cout<<"Registro agregado con exito!"<<endl;system("PAUSE");
					}
		}
		else
		{
			cout<<"Error, el registro no se pudo abrir o no ha sido creado"<<endl;
		}
	escritura.close();consulta.close();
	}
void eliminar()
{
	ofstream aux; ifstream leer;encontrado=false; int auxclave;
	aux.open("auxiliar.txt", ios::out);	leer.open("aprendiz.txt", ios::in);
	
	if(aux.is_open() && leer.is_open())
		{	
			system("cls");
			cout<<"Ingresa la clave del aprendiz que deseas Eliminar"<<endl;
			cin>>auxclave;
			leer>>clave;
			while(!leer.eof())
				{
					leer>>nombre>>semestre>>grupo>>edad;
					if(auxclave==clave)
						{
							encontrado=true;
							cout<<"Registro Eliminado"<<endl;system("PAUSE");
						}
					else
						{
							aux<<clave<<" "<<nombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl;
						}
					leer>>clave;
				}	
		}
	else
		{
			cout<<"Error, el registro no se pudo abrir o no ha sido credo"<<endl;
		}
	if(encontrado==false)
		{
			cout<<"Error, Reviza tu clave pues esa no esta dentro de mi archivo"<<auxclave<<endl;
		}
	leer.close();
	aux.close();
	remove("aprendiz.txt");
	rename("auxiliar.txt","aprendiz.txt");	
	}
void consultar()
{
	ifstream leer;	
	leer.open("aprendiz.txt", ios::out|ios::in);
		
	if(leer.is_open())
		{
			system("cls");
			cout<<"						Registros del archivo aprendiz.txt"<<endl;
			cout<<"						----------------------------------"<<endl;
			leer>>clave;
			while(!leer.eof())
			{
				leer>>nombre>>semestre>>grupo>>edad;
				cout<<"					Clave:"   <<clave<<endl;
				cout<<"					Nombre:"  <<nombre<<endl;
				cout<<"					Semestre:"<<semestre<<endl;
				cout<<"					Grupo:"   <<grupo<<endl;
				cout<<"					Edad:"    <<edad<<endl;
				leer>>clave;
				cout<<"					----------------------------------"<<endl;system("PAUSE");
			}
		}
		else
		{
			cout<<"Error, el Archivo no se pudo abrir o no ha sido creado"<<endl;system("PAUSE");
		}
	leer.close();
}
void buscar()
{
	cout<<"La Opcion que Elegiste Fue buscar";
	ifstream leer;	
	leer.open("aprendiz.txt", ios::out|ios::in);
	encontrado=false;	
	if(leer.is_open())
		{
			system("cls");
			cout<<"Ingresa la clave del aprendiz que deseas buscar: ";
			cin>>auxclave;
			leer>>clave;
			while(!leer.eof())
			{
				leer>>nombre>>semestre>>grupo>>edad;//leyendo campos del registro
				if(auxclave==clave)//comparacion para verificar si el registro es encontrado
					{
						cout<<"					----------------------------------"<<endl;
						cout<<"					Clave:"   <<clave<<endl;
						cout<<"					Nombre:"  <<nombre<<endl;
						cout<<"					Semestre:"<<semestre<<endl;
						cout<<"					Grupo:"   <<grupo<<endl;
						cout<<"					Edad:"    <<edad<<endl;
						cout<<"					----------------------------------"<<endl;
						encontrado=true;system("PAUSE");
					}
					leer>>clave;
			}
			if(encontrado==false)
				{
					cout<<"no se encontraron registros con esa clave"<<auxclave<<endl;system("PAUSE");
				}
		}
		else
		{
			cout<<"No se pudo abrir el archivo o aun no ha sido creado"<<endl;system("PAUSE");
		}
	leer.close();//cerrar archivo
}
void modificar()
{
	ofstream aux;
	ifstream leer;
	encontrado=false;
	int auxclave;
	char auxnombre[20];
	aux.open("auxiliar.txt",ios::out);
	leer.open("aprendiz.txt",ios::in);
	if(aux.is_open() && leer.is_open())
	{
		system("cls");
		cout<<"Ingresa la clave del aprendiz que deseas modificar "<<endl;
		cin>>auxclave;
		leer>>clave;
		while(!leer.eof())
		{
		leer>>nombre>>semestre>>grupo>>edad;
		if(auxclave==clave)
			{		
			encontrado=true;
			cout<<"					----------------------------------"<<endl;
			cout<<"					Clave:"   <<clave<<endl;
			cout<<"					Nombre:"  <<nombre<<endl;
			cout<<"					Semestre:"<<semestre<<endl;
			cout<<"					Grupo:"   <<grupo<<endl;
			cout<<"					Edad:"    <<edad<<endl;
			cout<<"					----------------------------------"<<endl;
			cout<<"	        Ingresa el nuevo nombre del aprendiz con clave:"<<clave<<endl;
			cin>>auxnombre;
			aux<<clave<<" "<<auxnombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl;
			cout<<"El registro fue modificado con exito! "<<endl;system("PAUSE");
			}
		else
			{
				aux<<clave<<" "<<nombre<<" "<<semestre<<" "<<grupo<<" "<<edad<<endl;
			}
		leer>>clave;
		}
		if(encontrado==false)
			{
				cout<<"no se encontraron registros con la clave: "<<auxclave<<endl;system("PAUSE");
			}	
	}
	else
	{
		cout<<"No se pudo abrir el archivo o aun no ha sido creado"<<endl;system("PAUSE");
	}
	leer.close();
	aux.close();
	remove("aprendiz.txt");
	rename("auxiliar.txt","aprendiz.txt");	
}
void salir()
{
	system("cls");
	cout<<endl<<endl<<endl<<"\t\t\t\t\t\t";
	for(int i=0;i<=23;i++)
		{
			cout<<mensaje[i];
			Sleep(80);
		}
		cout<<endl<<endl<<"\t\t\t\t\t       Adios..programa finalizado";
}







