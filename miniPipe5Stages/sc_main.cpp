# include "Pipeline5.h"
# include "TestBench.h"
int sc_main(int argc,char *argv[]){

	sc_time delay(0,SC_NS);
	sc_time period(20,SC_NS);
	sc_clock clk("clock",period,0.5,delay,true);

	Pipeline5 pipeline5("pipeline5");
	
	sc_signal< bool > x_sg;
	sc_signal< bool > z_sg;
	sc_signal< bool > en_sg;

	TestBench ts("TestBench");

	ts.clk_in(clk);
	pipeline5.clk_in(clk);

	pipeline5.data0_in(x_sg);
	ts.data0_out(x_sg);

	pipeline5.data0_out(z_sg);
	ts.data0_in(z_sg);

	pipeline5.en_in(en_sg);
	ts.en_out(en_sg);

	//inicia la simulacion
	sc_start();
	return 0;
}
