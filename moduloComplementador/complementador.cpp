#include "complementador.h"

Complemento::Complemento(sc_module_name nm):sc_module(nm)
{
	SC_METHOD(split);
		sensitive<<B_in; // la entrada B del complementador

		xores[0]=new Xor("xores0");	 
		xores[1]=new Xor("xores1");	
		xores[2]=new Xor("xores2");	 
		xores[3]=new Xor("xores3");	
		xores[4]=new Xor("xores4");
		xores[5]=new Xor("xores5"); 
		xores[6]=new Xor("xores6");	 
		xores[7]=new Xor("xores7");

		for(int i = 0; i < 8; ++i)
		{
			xores[i]->a_in(B_sg[i]);
			xores[i]->b_in(c_in);
			xores[i]->c_out(BC_sg[i]);
		}	 
		
		SC_METHOD(join);

		for(int i=0;i<8;++i)
			{
				sensitive<<BC_sg[i];	//sensible a la señal BC_sg es decir a la la salida de los xores
			}

			
		
}

void Complemento::split()
{
		//8 bit sc_uint<8>
		for(int i=0;i<8; i++)
			{
			B_sg[i].write(B_in.read().range(i,i)); //La funcion range(i,i) envia en 00 el bit menos significativo y en 01 el segundo menos significativo...
			
			}
}
void Complemento::join()
{
	
	sc_uint<8> s_aux;
	for(int i=0;i<8; i++)
	{
		
	s_aux[i] = BC_sg[i].read();

  }
	BC_out.write(s_aux);

}

Complemento::~Complemento()
{
	for(int i=0; i < 8 ; i++)
		{
			delete xores[i];


		}
	

}

