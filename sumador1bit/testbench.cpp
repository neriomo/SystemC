#include "testbench.h"
Testbench::Testbench(sc_module_name nm):sc_module(nm){

	SC_THREAD(test);
		//sensitive<<clk_in;
		sensitive<<clk_in.pos();
		//sensitive<<clk_in.neg();
	
}

Testbench::~Testbench(){}

void Testbench::test(){
	
	cout<<"a b c s c"<<endl;

	a_out.write(0);	
	b_out.write(0);
	c_out.write(0);

	wait();
	
	cout<< a_out.read()<<" "\
		 <<b_out.read()<<" "\
			<<c_out.read()<<" "\
         			<<s_in.read()<<" "\
					<<c_in.read()<<" "\	
						<<endl;

	a_out.write(0);	
	b_out.write(0);
	c_out.write(1);

	wait();
	
	cout<< a_out.read()<<" "\
		 <<b_out.read()<<" "\
			<<c_out.read()<<" "\
         			<<s_in.read()<<" "\
					<<c_in.read()<<" "\	
						<<endl;

	

	a_out.write(0);	
	b_out.write(1);
	c_out.write(0);

	wait();
	
	cout<< a_out.read()<<" "\
		 <<b_out.read()<<" "\
			<<c_out.read()<<" "\
         			<<s_in.read()<<" "\
					<<c_in.read()<<" "\	
						<<endl;

	a_out.write(0);	
	b_out.write(1);
	c_out.write(1);

	wait();
	
	cout<< a_out.read()<<" "\
		 <<b_out.read()<<" "\
			<<c_out.read()<<" "\
         			<<s_in.read()<<" "\
					<<c_in.read()<<" "\	
						<<endl;
	a_out.write(1);	
	b_out.write(0);
	c_out.write(0);

	wait();
	
	cout<< a_out.read()<<" "\
		 <<b_out.read()<<" "\
			<<c_out.read()<<" "\
         			<<s_in.read()<<" "\
					<<c_in.read()<<" "\	
						<<endl;
	a_out.write(1);	
	b_out.write(0);
	c_out.write(1);

	wait();
	
	cout<< a_out.read()<<" "\
		 <<b_out.read()<<" "\
			<<c_out.read()<<" "\
         			<<s_in.read()<<" "\
					<<c_in.read()<<" "\	
						<<endl;
	a_out.write(1);	
	b_out.write(1);
	c_out.write(0);

	wait();
	
	cout<< a_out.read()<<" "\
		 <<b_out.read()<<" "\
			<<c_out.read()<<" "\
         			<<s_in.read()<<" "\
					<<c_in.read()<<" "\	
						<<endl;
	a_out.write(1);	
	b_out.write(1);
	c_out.write(1);

	wait();
	
	cout<< a_out.read()<<" "\
		 <<b_out.read()<<" "\
			<<c_out.read()<<" "\
         			<<s_in.read()<<" "\
					<<c_in.read()<<" "\	
						<<endl;
	sc_stop();
}












