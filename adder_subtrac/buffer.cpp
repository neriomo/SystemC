#include "buffer.h"
#include <iostream>
Buffer::Buffer(sc_module_name nm):sc_module(nm)
{
		
	SC_METHOD(operation);
		sensitive<<b_in<<a_in; // sensible a las entradas
}

Buffer::~Buffer(){}

void Buffer::operation()
{
	

	if(b_in == 1) // XD  esto aqui es 1 o 0 dependiendo de si se quiere valida una suma o una resta
		{
			c_out.write(a_in.read());
		}
	else
		{
			c_out.write("ZZZZZZZZ");		
		}
}



