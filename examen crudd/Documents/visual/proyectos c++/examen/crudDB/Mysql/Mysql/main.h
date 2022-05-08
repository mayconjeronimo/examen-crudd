#pragma once
#include <iostream>
#include <mysql.h>
using namespace std;
class main {
	//atributos
protected: string carnet, nombres, apellidos, direccion, genero, email, fecha_nacimiento;
	string telefono;


		 //constructor
protected:
	main() {

	}
	main(string car, string n,string ape,string dire,string tel,string gen, string em,string fn) {
		carnet = car;
		nombres = n;
		apellidos = ape;
		direccion = dire;
		telefono = tel;
		genero = gen;
		email = em;
		fecha_nacimiento= fn;

	}


};

