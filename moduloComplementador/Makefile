#-----------------------------------------------------------------------------------------
# Modelo de Makefile para compilaciï¿½n de diseï¿½os realizados con la librerï¿½a SystemC
#----------------------------------------------------------------------------------------

# Especificar los archivos .cpp en SRCS y los archivos .h en SRCH
SRCS = and.cpp  main.cpp xor.cpp complementador.cpp testbenchComplement.cpp
# Nombre del ejecutable
TARGET = complementador

# Variable que apunta a la carpeta de SystemC
SYSTEMC = /usr/local/systemc-2.3.1
INCDIR = -I. -I.. -I$(SYSTEMC)/include
LIBDIR = -L. -L.. -L$(SYSTEMC)/lib-linux/
LIBS   = -lsystemc -lm

CC     = g++
CFLAGS = -g -Wno-deprecated -Wall
OBJS   = $(SRCS:.cpp=.o)

#En caso de trabajar con windows colocar la extensiï¿½n .exe
EXE    = $(TARGET)

.SUFFIXES: .cpp .o  

$(EXE): $(OBJS) $(SRCH)  
	$(CC) $(CFLAGS) $(INCDIR) $(LIBDIR) -o $@ $(OBJS) $(LIBS) 2>&1 | c++filt

all: $(EXE) exp
 
	
.cpp.o:
	$(CC) $(DEBUG) $(CFLAGS) $(INCDIR) -c $<

clean:
	rm -f $(OBJS) *~ $(EXE) *.bak $(TARGET).stackdump *.vcd
   
exp:
    export LD_LIBRARY_PATH=/usr/local/systemc-2.3.1/lib-linux
