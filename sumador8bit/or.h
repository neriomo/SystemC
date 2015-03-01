#ifndef OR
#define OR
#include <systemc.h>

class Or : public sc_module{
	
	public:
		sc_in<bool> a_in;	//bit1
		sc_in<bool> b_in;	//bit2
		sc_out<bool> c_out;	//acarreo

		//XOR();
		SC_CTOR(Or);//Constructor SystemC
		~Or();//Destructor
	private:
		void operation();

};

#endif



