#ifndef TESTBENCH8b_H
#define TESTBENCH8b_H
#include <systemc.h>
#include <iostream>
using namespace std;
class Testbench8b : public sc_module{

	public:	
		sc_in<bool> clk_in;		
		sc_in<sc_uint<8> > s_in;
		sc_out<sc_uint<8> > x_out;
		sc_out<sc_uint<8> > y_out;
		sc_in<bool> c_in;								//acarreo de entrada	
		sc_out<bool> c_out;							//acarreo de salida

		SC_CTOR(Testbench8b);
		~Testbench8b();
	private:
		void test();
};

#endif
