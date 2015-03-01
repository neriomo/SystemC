#include "stateMachine.h"


StateMachine::StateMachine(sc_module_name nm) : sc_module(nm){

  SC_METHOD(cambiar_estado);
        sensitive<<clk_in.pos();
      	dont_initialize();

    this->estado = 0; //case 1,2,3

}
StateMachine::~StateMachine(){}

void StateMachine::cambiar_estado(){
	//cout<<"estado="<<estado;
  //this->permitir_out =0;   // pilas con inicalizar puertos en constructores
    switch(estado){
        case 0:				// cuando mi estado inicial es cero 				00
            if(s_in.read() == 0)
							{
                this->estado=0;
								this->permitir_out = 0;
								cout<< "--> el estado es"<<estado<<endl;
							}
            else
							{
                estado=3;
								this->permitir_out =1;
							cout<< "--> el estado es"<<estado<<endl;
							}
        break;
	
        case 1:				//cuando mi estado unicial es uno						01
            if(s_in.read()==0)
							{
                estado = 2;
								this->permitir_out = 1;
								cout<< "--> el estado es"<<estado<<endl;
							}							
            else
							{
                estado=3;
								this->permitir_out = 1;
								cout<< "--> el estado es"<<estado<<endl;
							}
        break;

        case 2:				//cuando mi estado inicial es dos   				10
            if(s_in.read()==0)
							{
                estado=0;
								this->permitir_out = 0;
								cout<< "--> el estado es"<<estado<<endl;
							}
            else
							{
                estado=0;
								this->permitir_out = 0;
								cout<< "--> el estado es"<<estado<<endl;
							}
        break;

        case 3:				//cuando mi estado inicial es tres  				11
            if(s_in.read()==0)
							{
                estado=0;
								this->permitir_out = 0;
								cout<< "--> el estado es"<<estado<<endl;
							}
            else
							{
                estado=1;
								this->permitir_out = 0;
								cout<< "--> el estado es"<<estado<<endl;
							}
        break;

    }
     
}














