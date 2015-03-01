#ifndef FULLADDER_H
#define FULLADDER_H
#include "and.h"
#include "or.h"
#include "xor.h"

class Full_Adder: public sc_module{

	public:
		sc_in<bool> a_in;
		sc_in<bool> b_in;
		sc_in<bool> c_in;
		sc_out<bool> c_out;
		sc_out<bool> s_out;

		SC_CTOR(Full_Adder);
		~Full_Adder();

	private:
		And *and0,*and1;
		Or *or0;
		Xor *xor0, *xor1;

		sc_signal<bool> sg_1,sg_2,sg_3;




};
#endif
