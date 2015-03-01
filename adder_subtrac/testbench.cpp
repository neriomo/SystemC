#include "testbench.h"
#include <iostream>
Testbench::Testbench(sc_module_name nm):sc_module(nm)
{
		SC_THREAD(test);
		sensitive<<clk_in.pos();
		
}	

Testbench::~Testbench(){}

void Testbench::test()
{
	cout<<"x       y      acarreo de entrada       s(resta o suma)  "<<endl;

	a_out.write("0b11111111"); //para pasar una cadena de caracteres tiene que estar entre comillas dobles y somo prefijo "ob" ejmplo: <---
	b_out.write("0b00000001");
	c_out.write(1);	//0 para sumar 1 para restar, el 1 complementa la entra b del sumador-restador

	wait();

	cout<< a_out.read()<<"       "<<b_out.read()<<"           "<<c_out.read()<<"                    "<<s_in.read()<<"       "<<endl;

	sc_stop();
}
	































