/**
@file PipeRegisters.h Registros de Pipe
@author Ronald Sulbaran
@date September 2014
@mail ronalanto03@hotmail.com
*/


# ifndef PIPEREGISTERS_H
# define PIPEREGISTERS_H

# include "RegisterEnable.h"
/**
@class PipeRegisters
@author Ronald Sulbaran
@mail ronalanto03@gmail.com
@date September 2014
*/


class PipeRegisters:public sc_module{
	public:

		///Puerto de reloj 
		sc_in_clk clk_in;
		///Puerto en los registros del pipe
		sc_in<bool> en_in;
		///Puerto de entrada de dato0
		sc_in< bool > data0_in;
		///Puerto de salida de dato0
		sc_out< bool > data0_out;
		
		///Constructor
		SC_CTOR(PipeRegisters){

			//se reserva memoria para reg0
			reg0=new RegisterEnable<bool>("reg0");

			//se hacen las conexiones
			reg0->en_in(this->en_in);
			reg0->clk_in(this->clk_in);
			reg0->data_in(this->data0_in);
			reg0->data_out(data0_out);
		}


		///provee informacion para reporte de errores
		virtual const char* kind() const{
			return "PipeRegisters";
		}

	private:
		///puntero a un registro
		RegisterEnable<bool> * reg0;



};
//end class PipeRegisters

# endif
