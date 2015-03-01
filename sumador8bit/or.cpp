#include "or.h"
//And_Gate g1("g1");
Or::Or(sc_module_name nm):sc_module(nm){
	
	SC_METHOD(operation);
		sensitive<<a_in<<b_in;
}
Or::~Or(){}
void Or::operation(){
		//.write() escribe valores sobrelos puertos de
		//salida o entrada-salida
		//.read() lee valores de cualquier puerto
		c_out.write( a_in.read() or b_in.read() );
}






