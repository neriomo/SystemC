#include "testbenchComplement.h"
#include <iostream>

Testbench::Testbench(sc_module_name nm):sc_module(nm)
{
		SC_THREAD(test);
		sensitive<<clk_in.pos();
		
}	

Testbench::~Testbench(){}

void Testbench::test()
{
	cout<<" entrada de 8 bits    c(acarreo entrada)  salida de 8 bits"<<endl;

	B_out.write("0b11111111"); //para pasar una cadena de caracteres tiene que estar entre comillas dobles y somo prefijo "ob" ejmplo: <---
	c_out.write(1);

	

	wait();

	cout<< B_out.read()<<"                           "<<c_out.read()<<"                        "<<BC_in.read()<<endl;

	sc_stop();
}
	




