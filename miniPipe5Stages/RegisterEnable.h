/**
@file register.h Plantilla de la clase RegisterEnable
@brief La clase RegisterEnable tiene un entrada de reloj,una entrada de datos,una salida de datos, y una entrada para habilitar o deshabilitar la escritura.
@author Ronald Sulbaran
@date November 2013
@mail ronalanto03@hotmail.com
*/


# ifndef REGISTER_H
# define REGISTER_H

# include <systemc.h>
/**
@class RegisterEnable
@brief Registro parametrico con entrada para habilitar/deshabilitar la escritura.
La lectura se hace en flanco de subida, la escritura en flaco de bajada.
Para la escritura(clk_in=0):
	Cuando en_in=0 el registro mantiene el valor y cuando en_in=1 data cambia a data_in.

@author Ronald Sulbaran
@mail ronalanto03@gmail.com
@date December 2013
*/


///DataType es el tipo de dato que almacenara el registro
template <typename DataType>

class RegisterEnable:public sc_module{
	public:

		///Puerto de reloj 
		sc_in_clk clk_in;
		///Puerto para habilitar escritura
		sc_in<bool> en_in;
		///Puerto de entrada de dato
		sc_in< DataType > data_in;
		///Puerto de salida de dato
		sc_out< DataType > data_out;
		
		///Constructor
		SC_CTOR(RegisterEnable){
			data=0;

			SC_METHOD(readOperation)
				sensitive<<clk_in.pos();

			SC_METHOD(writeOperation)
				sensitive<<clk_in.neg()<<en_in<<data_in;

		}


		///provee informacion para reporte de errores
		virtual const char* kind() const{
			return "RegisterEnable";
		}

	private:
		///keep the state of the latch
		DataType data;

		///SC_METHOD that read when clock input equal to 1.
		void readOperation(){
				data_out.write(data);
		}

		///SC_METHOD that write when clock input equal to 0.
		void writeOperation(){
			if(clk_in.read()== 0 and en_in.read()){
				data=data_in.read();
			}
		}




};
//end class RegisterEnable

# endif
