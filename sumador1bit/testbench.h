#ifndef TESTBENCH_H
#define TESTBENCH_H
#include <systemc.h>
#include <iostream>
using namespace std;
class Testbench : public sc_module{

	public:	
		sc_in<bool> clk_in;		
		sc_in<bool> s_in;
		sc_in<bool> c_in;
		sc_out<bool> a_out;
		sc_out<bool> b_out;
		sc_out<bool> c_out;
		SC_CTOR(Testbench);
		~Testbench();
	private:
		void test();
};

#endif
