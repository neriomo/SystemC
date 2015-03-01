#include "stateMachine.h"
#include "testBench.h"
#include <iostream>
#include <systemc.h>

int sc_main(int argc,char *argv[]){
	sc_time PERIOD(20,SC_NS);	
	sc_time DELAY(10,SC_NS);	
	sc_clock clock("clock",PERIOD,0.5,DELAY,true);

	StateMachine sm("sm");
	TestBench test("test");

    sc_signal <bool > s_sg, p_sg;
		
		//sm.clk_in(clock_sg);
		sm.s_in(s_sg);
		sm.permitir_out(p_sg);
		sm.clk_in(clock);  // pilas con el clock
		

		test.s_out(s_sg);
		test.permitir_in(p_sg);
	  test.clk_in(clock);
		






	sc_start();
	return 0;
}




