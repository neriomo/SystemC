#include "testbench8b.h"
#include <iostream>
Testbench8b::Testbench8b(sc_module_name nm):sc_module(nm)
{
		SC_THREAD(test);
		sensitive<<clk_in.pos();
		
}	

Testbench8b::~Testbench8b(){}

void Testbench8b::test()
{
	cout<<"x        y       s(suma)       c(acarreo entrada)       c(acarreo de salida)"<<endl;

	x_out.write("0b00000001"); //para pasar una cadena de caracteres tiene que estar entre comillas dobles y somo prefijo "ob" ejmplo: <---
	y_out.write("0b00000001");
	c_out.write(0);	//el acarreo de salida del testbench es el acarreo de entrada de el sumador8b
	

	wait();

	cout<< x_out.read()<<"        "<<y_out.read()<<"          "<<s_in.read()<<"                   "<<c_out.read()<<"                      "<<c_in.read()<<"     "<<endl;

	sc_stop();
}
	































