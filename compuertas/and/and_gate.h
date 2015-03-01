#ifndef AND_GATE
#define AND_GATE
#include <systemc.h>

class And_Gate : public sc_module{	//Declaracion del modulo "class And_Gate" y heredamos 
																		//las funciones de sc_module
	public:
		sc_in<bool> a_in;		//puerto de entrada del modulo padre sc_in<T>
		sc_in<bool> b_in;		//puerta de entrada del modulo padre
		sc_out<bool> c_out;	//puerto de salida sc_out<T>

					//And_Gate();
		SC_CTOR(And_Gate);	//Constructor SystemC
		~And_Gate();				//Destructor
	private:
		void operation();	// este es el proceso (no recibe ni retorna nada
											// es sencible a una lista de sensibilidad
};										// se activa cuando cualquiera de los parametros cambia
											//esta funcion se declara en el .cpp

#endif


/* Para declarar modulos podemos usar

class NombreDelModulo : public sc_module{
	
	public:
		puertos
		constructor
		destructor

	private:

	


}
*/

