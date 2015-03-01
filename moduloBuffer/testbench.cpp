#include "testbench.h"
Testbench::Testbench(sc_module_name nm):sc_module(nm){

	SC_THREAD(test);	//proceso
		//sensitive<<clk_in;
		sensitive<<clk_in.pos();
		//sensitive<<clk_in.neg();
	
}

Testbench::~Testbench(){}

void Testbench::test(){	// cuerpo del proceso
	cout<<"Buffer "<<endl;
	cout<<"entrada8 acarreo salida "<<endl; //si la salida es 199 es falsa;

	a_out.write("0b00000011");	
	b_out.write(0);

	wait();
	
	cout<< a_out.read()<<"    "\
		 <<b_out.read()<<"    "\
         <<c_in.read()<<endl;

	a_out.write("00000001");	
	b_out.write(1);

	wait();
	
	cout<< a_out.read()<<"    "\
		 <<b_out.read()<<"    "\
          <<c_in.read()<<endl;

	
	sc_stop();
}












