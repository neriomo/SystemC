#ifndef XOR
#define XOR
#include <systemc.h>

class Xor : public sc_module{
	
	public:
		sc_in<bool> a_in;	//bit1
		sc_in<bool> b_in;	//bit2
		sc_out<bool> c_out;	//acarreo

		//XOR();
		SC_CTOR(Xor);//Constructor SystemC
		~Xor();//Destructor
	private:
		void operation();

};

#endif



