#include "adderSub.h"

AdderSub::AdderSub(sc_module_name nm):sc_module(nm)
{
	
	SC_METHOD(operation);
	sensitive<<a_in<<b_in<<c_in;

	buffer = new Buffer("buffer");
	complementador = new Complemento("complementador");
	sumador8b = new Sumador8b("sumador8b");

	complementador->B_in(b_in);	//conectamos la entrada del complementador con la entrada b de del sumador restador
	complementador->c_in(c_in);		//conectamos la entrada de acarreo de el sumador restador con el acarreo de entrada del modulo complementador( 1 resta(complementa), 0 suma (no complementa))
	complementador->BC_out(BC_sg);

	sumador8b->x_in(a_in);
	sumador8b->y_in(BC_sg);
	sumador8b->c_in(c_in);

	sumador8b->s_out(SR_sg);
	sumador8b->c_out(b_sg);

	buffer->a_in(SR_sg);
	buffer->b_in(b_sg);	

	buffer->c_out(s_out);

}

void AdderSub:: operation(){}  //relajao jhenifer dice que es para hacerlo "sensible"

AdderSub::~AdderSub()
{
	delete complementador;
	delete sumador8b;
	delete buffer;	

}
	
	


	
