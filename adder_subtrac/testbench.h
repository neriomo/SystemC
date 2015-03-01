/* testbench para el sumador restador*/
#ifndef TESTBENCH8b_H
#define TESTBENCH8b_H
#include <systemc.h>
#include <iostream>
using namespace std;
class Testbench : public sc_module{

	public:	
		sc_in<bool> clk_in;		
		sc_in<sc_lv<8> > s_in;			// salida del adderSub entrada del testbench				
		sc_out<sc_uint<8> > a_out;		// entradas del adderSub salida del testbench
		sc_out<sc_uint<8> > b_out;	
		sc_out<bool> c_out;

		SC_CTOR(Testbench);
		~Testbench();
	private:
		void test();
};

#endif
