#include "FullAdder.h"

Full_Adder::Full_Adder(sc_module_name nm): sc_module(nm){

		//declaramos las compuertas 
		and0 = new And("and0");
		and1 = new And("and1");
		xor0 = new Xor("xor0");
		xor1 = new Xor("xor1");
		or0  = new Or("or0");
		//debemos conectar las compuertas

		and0->a_in(c_in);
		and0->b_in(sg_1);	//sale del primer xor y entra al and0
		and0->c_out(sg_2);	//sg_2 es la primera que entra al or
		
		and1->a_in(b_in);
		and1->b_in(a_in);
		and1->c_out(sg_3);	//sg_3 es la segunda que entra al or
		
		xor0->c_out(sg_1);
		xor0->a_in(a_in);
		xor0->b_in(b_in);
		

		xor1->a_in(sg_1);
		xor1->b_in(c_in);
		xor1->c_out(s_out);

		or0->a_in(sg_2);
		or0->b_in(sg_3);
		or0->c_out(c_out);
}
Full_Adder::~Full_Adder(){

delete and0;
delete and1;
delete or0;
delete xor0;
delete xor1;

}
