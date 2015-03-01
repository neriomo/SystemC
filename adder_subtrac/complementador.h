#ifndef COMPLEMENTADOR_h
#define COMPLEMENTADOR_h
#include <systemc.h>
#include <iostream>
#include "xor.h"
class Complemento : public sc_module
{
	public:
	
		sc_in<sc_uint<8> > B_in; // la entrada del complementador 
		sc_out<sc_uint<8> > BC_out;	// la salida del complementador
		sc_in<bool> c_in;					// acarreo de entrada
		SC_CTOR(Complemento);
		~Complemento();
	private:
		Xor * xores[8];
		sc_signal<bool> B_sg[8], BC_sg[8]; 
		void join();
		void split();

};

#endif
