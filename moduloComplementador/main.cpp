#include "and.h"
#include "or.h"
#include "xor.h"
#include "testbenchComplement.h"
#include "complementador.h"

int sc_main(int argv, char* argc[]){
	sc_time PERIOD(10,SC_NS);//SC_PS SC_SEC . . .	
	sc_time DELAY(10,SC_NS);	
	sc_clock clock("clock",PERIOD,0.5,DELAY,true);

	Complemento complement("complement");
	Testbench tb("tb");

	
	sc_signal<bool> c_sg; // señales de acarreo
	sc_signal< sc_uint<8> > B_sg, BC_sg; // señales de las entrdas y las salidas de 8 bits 

	complement.B_in(B_sg);
	complement.c_in(c_sg);
	complement.BC_out(BC_sg);

	tb.clk_in(clock);
	tb.BC_in(BC_sg);
	tb.B_out(B_sg);
	tb.c_out(c_sg);



	sc_start();
	
	return 0;

	}


