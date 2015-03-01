#include "sumador8b.h"

Sumador8b::Sumador8b(sc_module_name nm):sc_module(nm)
{
	
	SC_METHOD(split);
		sensitive<<x_in<<y_in;
		fulladder[0]=new Full_Adder("fulladder0");	//sumadores de un bit 
		fulladder[1]=new Full_Adder("fulladder1");
		fulladder[2]=new Full_Adder("fulladder2");
		fulladder[3]=new Full_Adder("fulladder3");
		fulladder[4]=new Full_Adder("fulladder4");
		fulladder[5]=new Full_Adder("fulladder5");
		fulladder[6]=new Full_Adder("fulladder6");
		fulladder[7]=new Full_Adder("fulladder7");

		
		for(int i=0;i<8;++i)
			{
				
				fulladder[i]->a_in(x_sg[i]);	//se conectan los sumadores de un bit a las señales de  entrada del sumador8b
				fulladder[i]->b_in(y_sg[i]);
				fulladder[i]->s_out(z_sg[i]);	//

			}

	SC_METHOD(join);

		for(int i=0;i<8;++i)
			{
				sensitive<<z_sg[i];	//sensible a la señal z_sg
			}


			//conectamos los FullAdder mediante los acarreos 
			fulladder[0]->c_in(c_in); //no necesita señal es el puerto madre
			for(int i=0;i<7;++i)
				{
					fulladder[i+1]->c_in(c_sg[i]);
					fulladder[i]->c_out(c_sg[i]);
				}
			fulladder[7]->c_out(c_out);// Puerto madre
		
}
	

void Sumador8b::split()
{
		//8 bit sc_uint<8>
		for(int i=0;i<8; i++)
			{
			x_sg[i].write(x_in.read().range(i,i)); //La funcion range(i,i) envia en 00 el bit menos significativo y en 01 el segundo menos significativo...
			y_sg[i].write(y_in.read().range(i,i));
		//x_sg[0].write(x_in.read()[0]);}
			}
}
void Sumador8b::join()
{
	
	sc_uint<8> s_aux;
	for(int i=0;i<8; i++)
	{
		
	s_aux[i] = z_sg[i].read();

  }
	s_out.write(s_aux);

}

Sumador8b::~Sumador8b()
{
	for(int i=0; i < 8 ; i++)
		{
			delete fulladder[i];


		}
	

}
