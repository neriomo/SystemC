# ifndef TESTBENCH_H
# define TESTBENCH_H

# include <systemc.h>

class TestBench: public sc_module{
	public:
		
		sc_in_clk clk_in;
		sc_out<bool> en_out;
		sc_out< bool > data0_out;
		sc_in< bool > data0_in;


		SC_CTOR(TestBench){
			SC_THREAD(test)
				sensitive<<clk_in.pos();
				dont_initialize();
		}


	private:
		void test();
		void print();


};

#endif
