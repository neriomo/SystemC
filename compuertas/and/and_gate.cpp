#include "and_gate.h"
//And_Gate g1("g1");
//metodos del modulo And_Gate

And_Gate::And_Gate(sc_module_name nm):sc_module(nm){		//que es esto? asi se declara el proceso? 
	
	SC_METHOD(operation);		//este es el proceso (operacion)
		sensitive<<a_in<<b_in; //lista de sensibilidad (siempre debajo el proceso)
}
And_Gate::~And_Gate(){}	//destructor vacio?


void And_Gate::operation(){ //declaracion de la operacion(proceso) privada de 
		//.write() escribe valores sobrelos puertos de
		//salida o entrada-salida
		//.read() lee valores de cualquier puerto
		c_out.write( a_in.read() and  b_in.read() ); // lee los valores de los puertos de entrada
																								//a_in y b_in identificadores
}






