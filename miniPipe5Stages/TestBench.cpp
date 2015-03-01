# include "TestBench.h"

void TestBench::test(){
	//imprimir una linea de cabecera
	cout<<"time\ten_out\tdata_out\tdata_in"<<endl;
	
	//prueba 1
	en_out.write(true);
	data0_out.write(true);
	wait();
	print();

	//prueba 2
	en_out.write(true);
	data0_out.write(true);
	wait();
	print();

	//prueba 3
	wait();
	print();

	//prueba 4
	wait();
	print();

	//prueba 5
	wait();
	print();

	//prueba 6
	wait();
	print();



	//fin de la simulacion
	sc_stop();
}


void TestBench::print(){
	cout<<sc_time_stamp()<<"\t"<<en_out.read()<<"\t"<<data0_out.read()<<"\t\t"<<data0_in.read();
	cout<<endl;
}









