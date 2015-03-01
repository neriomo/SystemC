#include "xor.h"
//And_Gate g1("g1");
Xor::Xor(sc_module_name nm):sc_module(nm){
	
	SC_METHOD(operation);
		sensitive<<a_in<<b_in;
}
Xor::~Xor(){}
void Xor::operation(){
		//.write() escribe valores sobrelos puertos de
		//salida o entrada-salida
		//.read() lee valores de cualquier puerto
		c_out.write( a_in.read() xor b_in.read() );
}






