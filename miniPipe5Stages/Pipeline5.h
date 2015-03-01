/**
@file Pipeline5.h Pipeline de 5 etapas(solo transferencia de registros)
@author Ronald Sulbaran
@date September 2014
@mail ronalanto03@hotmail.com
*/


# ifndef PIPELINE5_H
# define PIPELINE5_H

# include "PipeRegisters.h"
/**
@class Pipeline5
@author Ronald Sulbaran
@mail ronalanto03@gmail.com
@date September 2014
*/


class Pipeline5:public sc_module{
	public:

		///Puerto de reloj 
		sc_in_clk clk_in;
		///Puerto en los registros del pipe
		sc_in<bool> en_in;
		///Puerto de entrada de dato0 (en la etapa 1)
		sc_in< bool > data0_in;
		///Puerto de salida de dato0 (en la etapa 5)
		sc_out< bool > data0_out;
		
		///Constructor
		SC_CTOR(Pipeline5){

			pipe0=new PipeRegisters("pipe0");
			pipe1=new PipeRegisters("pipe1");
			pipe2=new PipeRegisters("pipe2");
			pipe3=new PipeRegisters("pipe3");

			pipe0->en_in(this->en_in);
			pipe1->en_in(this->en_in);
			pipe2->en_in(this->en_in);
			pipe3->en_in(this->en_in);

			pipe0->clk_in(this->clk_in);
			pipe1->clk_in(this->clk_in);
			pipe2->clk_in(this->clk_in);
			pipe3->clk_in(this->clk_in);

			pipe0->data0_in(this->data0_in);
			pipe0->data0_out(s1_sg);
			
			pipe1->data0_in(s1_sg);
			pipe1->data0_out(s2_sg);
			
			pipe2->data0_in(s2_sg);
			pipe2->data0_out(s3_sg);
			
			pipe3->data0_in(s3_sg);
			pipe3->data0_out(this->data0_out);
		}


		///provee informacion para reporte de errores
		virtual const char* kind() const{
			return "Pipeline5";
		}

	private:
		///puntero a un registro
		PipeRegisters * pipe0,*pipe1,*pipe2,*pipe3;
		sc_signal<bool> s1_sg,s2_sg,s3_sg;



};
//end class PipeRegisters

# endif
