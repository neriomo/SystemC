#ifndef AND
#define AND
#include <systemc.h>

class And : public sc_module{
	
	public:
		sc_in<bool> a_in;	//bit1
		sc_in<bool> b_in;	//bit2
		sc_out<bool> c_out;	//acarreo

		//AND();
		SC_CTOR(And);//Constructor SystemC
		~And();//Destructor
	private:
		void operation();

};

#endif



