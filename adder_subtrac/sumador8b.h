#ifndef SUMADOR8B
#define SUMADOR8B
#include <systemc.h>
#include "FullAdder.h"
#include <systemc.h>
using namespace std;

	class Sumador8b: public sc_module{

	public:
			sc_in<sc_uint<8> > x_in, y_in;	//tipo de dato de 8 bits de las entradas de dos sumas
			sc_out<sc_uint<8> > s_out;			//tipo de dato de 8 bits de la suma 
			sc_in<bool> c_in;								//acarreo de entrada	
			sc_out<bool> c_out;							//acarreo de salida
			SC_CTOR(Sumador8b);							
		 ~Sumador8b();
	private:
	void split();
	void join();
	sc_signal<bool> x_sg[8],y_sg[8],z_sg[8],c_sg[7];
	Full_Adder *fulladder[8];
};
#endif
