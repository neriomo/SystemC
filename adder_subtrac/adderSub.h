#ifndef ADDER_SUBSTRACCION_H
#define ADDER_SUBSTRACCION_H

#include <systemc.h>

#include<iostream>
#include "complementador.h"
#include "buffer.h"
#include "sumador8b.h"
using namespace std;

class AdderSub: public sc_module
{
	public:
		
		sc_in<sc_uint<8> > a_in, b_in;
		sc_in<bool> c_in;
		sc_out< sc_lv<8> > s_out;
		SC_CTOR(AdderSub);
		~AdderSub();

	private:
	sc_signal< sc_uint <8> > BC_sg, SR_sg;	// señal BC_sg es la salida del complemento a el sumador8b y SR_sg es la salida del sumador8b a el buffer
	sc_signal< bool> b_sg; //buffer   y esto es el valor que entra al buffer que es la salida del sumador8b
	Complemento * complementador;
	Sumador8b * sumador8b;
	Buffer * buffer;
	void operation();
		



};
#endif
