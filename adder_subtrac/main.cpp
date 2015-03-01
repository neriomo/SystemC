#include <iostream>
#include <systemc.h>
#include "adderSub.h"
#include "buffer.h"
#include "complementador.h"
#include "sumador8b.h"
#include "and.h"
#include "or.h"
#include "xor.h"
#include "testbench.h"

using namespace std;

int sc_main(int argv, char* argc[])
{
	
	sc_time PERIOD(10,SC_NS);//SC_PS SC_SEC . . .	
	sc_time DELAY(10,SC_NS);	
	sc_clock clock("clock",PERIOD,0.5,DELAY,true);
	
	sc_signal<bool> c_sg; // señales de los acarreos
	sc_signal<sc_uint<8> > a_sg, b_sg; // señales de las entrdas y las salidas de 8 bits 
	sc_signal<sc_lv<8> > s_sg;

	AdderSub addsub("addsub");
	Testbench tb("tb");


	addsub.a_in(a_sg);
	addsub.b_in(b_sg);
	addsub.c_in(c_sg);
	addsub.s_out(s_sg);

	tb.clk_in(clock);

	tb.a_out(a_sg);
	tb.b_out(b_sg);
	tb.c_out(c_sg);
	tb.s_in(s_sg);

	sc_start();

	return 0;
}

	





