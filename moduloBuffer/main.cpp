#include "buffer.h"
#include "testbench.h"

int sc_main(int argv, char* argc[]){
	sc_time PERIOD(10,SC_NS);//SC_PS SC_SEC . . .	
	sc_time DELAY(10,SC_NS);	
	sc_clock clock("clock",PERIOD,0.5,DELAY,true);

	Buffer bf1("bf1");
	Testbench tb("tb");

	sc_signal<sc_uint<8> > a_sg; // esta es la señal uint 
	sc_signal<sc_lv<8> > c_sg; //los cables
	sc_signal<bool> b_sg;

	bf1.a_in(a_sg);
	bf1.b_in(b_sg);
	bf1.c_out(c_sg);

	tb.clk_in(clock);  //las conecciones
	tb.a_out(a_sg);
	tb.b_out(b_sg);
	tb.c_in(c_sg);

	sc_start();

	return 0;
}
