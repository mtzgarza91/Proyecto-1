#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream ArchEntrada;
	ofstream ArchSalida;
	string nombreEntrada;
	string nombreSalida;
	string pName, author, date, fName1, desc, param, ret;
	
	string x, y;
	
	cout<<"ingrese el nombre del archivo de entrada sin extension"<<endl;
	cin>>nombreEntrada;
	
	nombreSalida = nombreEntrada;
	
	nombreEntrada+=".cpp";
	nombreSalida+=".html";
	
	ArchEntrada.open(nombreEntrada.c_str());
	ArchSalida.open(nombreSalida.c_str());
	
	// encabezado html
ArchSalida<<"<!DOCTYPE html><html><head><title>Documentacion HTML de un programa</title></head><body>"<<endl;
	
	//CSS
ArchSalida<<"<style>body {font-family: fantasy; background-color: black; color:teal;}"<<endl;  //fondo y fuente
ArchSalida<<"#POO{margin-bottom:5px;}"<<endl;					// Imagen POO
ArchSalida<<"#cp{float:right;  position:absolute; top:50%; right:45px; border:3px ridge white; }"<<endl;     //Imagen cp
ArchSalida<<"#titulo{float:right; float:top; position:absolute; width:40%; color:white; top:20px; right:50px;}"<<endl;				//titulo
ArchSalida<<"#name{color:white;}"<<endl;
ArchSalida<<"</style>"<<endl;
	
	//HTML

//imagen POO
ArchSalida<<"<body> <img id=\"POO\" src=\"https://yerotaro.files.wordpress.com/2008/09/dibujoooooo.jpg\" alt=\"programacion orientada a objetos\"</img>"<<endl;

ArchSalida<<"<h1 id=\"titulo\"> Proyecto #1 <br> Rodrigo A. Martinez Garza <br> ITC <br> A00806634</h1>"<<endl;//titulo

ArchSalida<<"<img id=\"cp\" src=\"http://www.globalblackhistory.com/wp-content/uploads/2014/07/computer-science-1.jpg\">"<<endl; //imagen cp
	
	while(!ArchEntrada.eof())
		{ArchEntrada>>x;
		getline(ArchEntrada,y);
			if (x=="@progName")                 		//Nombre del programa
			{ pName=y;
			ArchSalida<<" <h2 id=\"name\"> Nombre del programa:"<<pName<<"</h2><br>"; }
			
			if (x=="@author")							//Nombre del autor
			{ author=y;
			ArchSalida<<"<strong id=\"name\"> Autor: </strong>"<<author<<" <br>"<<endl; }
			
			if (x=="@date")								//fecha
			{ date=y;
			ArchSalida<<"<strong id=\"name\"> Fecha de elaboraci&oacute;n </strong>"<<date<<" <br>"<<endl;}
			
			//funciones
			if (x=="@funcName")
			{ fName1=y;
			ArchSalida<<"<h3 id=\"name\"> <ul> <li> Funci&oacute;n:"<<fName1<<"</h3><br></ul>"<<endl;}
			
	
			
			//descripciones
			if (x=="@desc")
			{ desc=y;
			ArchSalida<<"<strong id=\"name\"> Descripci&oacute;n: </strong>"<<desc<<"<br>"<<endl;}
			
		
			
			//parametros
			if (x=="@param")
			{ param=y;
			ArchSalida<<"<strong id=\"name\"> Parametro: </strong>"<<param<<" <br>"<<endl;}
		
		
			
			//returns
			if (x=="@return")
			{ ret=y;
			ArchSalida<<"<strong id=\"name\"> Valor de retorno: </strong>"<<ret<<" <br>"<<endl;}
			
		
}
			
	








	
	ArchEntrada.close();
	ArchSalida.close();
	
	return 0;
}
