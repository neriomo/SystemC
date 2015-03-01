#include "testBench.h"
#include <iostream>
using namespace std;

TestBench::TestBench(sc_module_name nm) : sc_module(nm){

    SC_THREAD(test);
        sensitive<<clk_in.pos();
        dont_initialize();

}
TestBench::~TestBench(){
}

void TestBench::test(){
		
    for (int i=0; i<20;i++){
    	cout<<i<<endl;
        s_out.write(i%2);				
								

        wait();
        cout << "permitir: "<<permitir_in.read()<< "     ";
        cout << "Signal:"<<s_out.read();

    }
        sc_stop();
}













