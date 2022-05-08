#pragma once
#pragma once
#include "main.h"
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>
using namespace std;

class Estudiantes : public main {
	//atributos


	   //constructor
public:
	Estudiantes() {
	}

	Estudiantes(string car, string n, string ape, string dire, string tel, string gen, string em, string fn) : main(car,n,ape,dire,tel,gen,em,fn) {

		
	}

	//metodos
	//set (modificar)
	void setcarnet(string car) { carnet = car; }
	void setnombres(string n) { nombres = n; }
	void setapellidos(string ape){ apellidos= ape; }
	void setDireccion(string dire) { direccion = dire; }
	void setTelefono(string tel) { telefono = tel; }
	void setgenero(string gen) { genero = gen; }
	void setemail(string em) { email = em; }
	void setfecha_nacimiento(string fn) { fecha_nacimiento = fn; }

	//get (mostrar)
	string getcarnet() { return carnet; }
	string getnombres() { return nombres; }
	string getapellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	string getTelefono() { return telefono; }
	string getgenero() { return direccion; }
	string getemail() { return email; }
	string getfecha_nacimiento() { return fecha_nacimiento; }


	void Crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
//			string t = to_string(telefono);
			string insert = "INSERT INTO estudiantes(carnet,nombres,apellidos, direccion,telefono,genero,email,fecha_nacimiento)VALUES('" +carnet + "','" + nombres + "','" + apellidos + "','" + direccion + "','" + telefono +"','" + genero + "','" + email + "','" + fecha_nacimiento + "'); ";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso...." << endl;

			}

			else {
				cout << "Error en El ingreso ..." << endl;
			}
		}
		else {
			cout << "Error en la Conexion ..." << endl;
		}
		cn.cerrar_conex();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string consulta = "select * from estudiantes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "------------------estudiantes---------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "-" << fila[1] << "-" << fila[2] << "-" << fila[3] << "-" << fila[4] << "-" << fila[5] <<"-" << fila[6] << "-" << fila[7] <<"-" << fila[8] << endl;
				}

			}

			else {
				cout << "Error en El ingreso ..." << endl;
			}
		}
		else {
			cout << "Error en la Conexion ..." << endl;
		}
		cn.cerrar_conex();
	}


	void actualizar() {
	int q_estado;
	
		if (cn.getConectar()) {
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {

			cout << "ACTUALIZAR";
			string iupdate = "Update estudiantes set" + str_column + " = '" + str_new + "' where id_estudiante = " + str_id;
			const char* i = insert.c_str();
		
			if (!q_estado) {
				cout << "Ingreso Exitoso...." << endl;

			}

			else {
				cout << "Error en El ingreso ..." << endl;
			}
		}
		else {
			cout << "Error en la Conexion ..." << endl;
		}
		cn.cerrar_conex();
	}
		}

	void eliminar() {
		int q_estado;
		string elidat, elid;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			string consulta = "delete from estudiantes where id_estudiante=" + elid;
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "Ingrese el ID para eliminar: ";
				cin >> elid;
				cout << "-----------------estudiantes---------------" << endl;

			}

			else {
				cout << "Error en El ingreso ..." << endl;
			}
		}
		else {
			cout << "Error en la Conexion ..." << endl;
		}
		cn.cerrar_conex();
	}
};
