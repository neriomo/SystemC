#Nombre del programa
MODULE = test.sm

#compilador usado
CC= g++
#Archivos que se compilaran
SRCS =sc_main.cpp TestBench.cpp
#Direccion de systemc
SYSTEMC = /usr/local/systemc-2.3.1


include ./Makefile.defs

run:$(EXE)
	@./$(EXE)

view: tf.vcd
	@gtkwave -f tf.vcd -cpu=4
