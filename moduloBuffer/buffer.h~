#ifndef BUFFER_H
#define BUFFER_H
#include <systemc.h>	//libreria systemc
#include <iostream>
class Buffer: public sc_module{
	
//este es el buffer que permite validar(fulladder y complemento)
	public:
			sc_in< sc_uint<8> > a_in;
			sc_in<bool> b_in;
			sc_out< sc_lv <8> > c_out;
			SC_CTOR(Buffer);	
			~Buffer();
		
	private:
		void operation();			
	

};

#endif
