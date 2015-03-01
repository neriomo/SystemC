#include "and.h"
#include "xor.h"
#include "or.h"
#include "FullAdder.h"
#include "testbench.h"

int sc_main(int argv, char* argc[]){
	sc_time PERIOD(10,SC_NS);//SC_PS SC_SEC . . .	
	sc_time DELAY(10,SC_NS);	
	sc_clock clock("clock",PERIOD,0.5,DELAY,true);

	Full_Adder ag1("ag1");
	Testbench tb("tb");

	sc_signal<bool> a_sg,b_sg,c_sg, s_sg,d_sg;	// señales que van de la salida del testbench a la 
							//entrada del full adder
	ag1.a_in(a_sg);										
	ag1.b_in(b_sg);
	ag1.c_in(c_sg);
	
	ag1.s_out(s_sg);
	tb.s_in(s_sg);

	ag1.c_out(d_sg);
	tb.c_in(d_sg);


	tb.clk_in(clock);
	tb.a_out(a_sg);
	tb.b_out(b_sg);
	tb.c_out(c_sg);

	sc_start();

 return 0;
}
