#ifndef TESTBENCHCOMPLEMENT_h
#define TESTBENCHCOMPLEMENT_h

#include <systemc.h>
#include<iostream>

using namespace std;

class Testbench: public sc_module
{
	public:
		
		sc_in<bool> clk_in;				//reloj
		sc_out< sc_uint<8> > B_out;		// entrada del modulo complementador
		sc_out<bool> c_out;	//acarreo del modulo complementador
		sc_in< sc_uint<8> > BC_in; //salida del modulo complementador

		SC_CTOR(Testbench);
		~Testbench();

	private:
		void test();
		



};
#endif
