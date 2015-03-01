#include "and.h"
#include "or.h"
#include "xor.h"
#include "FullAdder.h"
#include "testbench8b.h"
#include "sumador8b.h"

int sc_main(int argv, char* argc[]){
	sc_time PERIOD(10,SC_NS);//SC_PS SC_SEC . . .	
	sc_time DELAY(10,SC_NS);	
	sc_clock clock("clock",PERIOD,0.5,DELAY,true);

	Sumador8b sum8("sum8");
	Testbench8b tb("tb");

	sc_signal<bool> c_sg,d_sg; // señales de los acarreos
	sc_signal<sc_uint<8> > a_sg, b_sg, e_sg; // señales de las entrdas y las salidas de 8 bits 

	sum8.x_in(a_sg);
	sum8.y_in(b_sg);
	sum8.c_in(c_sg);
	sum8.c_out(d_sg);
	sum8.s_out(e_sg);

	tb.clk_in(clock);
	tb.x_out(a_sg);
	tb.y_out(b_sg);
	tb.c_out(c_sg);
	tb.c_in(d_sg);
	tb.s_in(e_sg);

	sc_start();

	return 0;
}
