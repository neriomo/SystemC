# SystemC
SystemC es un lenguaje para modelar Hardware, son ejemplos sencillos realizados en el Curso de Arquictectura Del Computador con el profesor Gerard Páez Monzon. Para poder ejecutar y probar cada modulo se necesita instalar la Libreria de SystemC la cual pueden
descargar en "http://www.accellera.org/downloads/standards/systemc" buscar el archivo INSTALL y seguir instrucciones.  
 
#wikipedia:
SystemC es frecuentemente descrito como un lenguaje de descripción de hardware como son VHDL y Verilog, pero es más adecuado describirlo como un lenguaje de descripción de sistemas, puesto que es realmente útil cuando se usa para modelar sistemas a nivel de comportamiento.

#Descripcion:
SystemC es un conjunto de bibliotecas y macros implementadas en C++ que hacen posible una simulación de procesos concurrentes con la sintaxis del lenguaje C++ ordinario. Así los objetos descritos pueden comunicarse durante una simulación de tiempo real usando señales de cualquier tipo ofrecido por C++, además algunas otras ofrecidas por las librerías de SystemC y también otras definidas por el usuario.

La metodología de diseño es comenzar con un modelo de alto nivel escrito en C++ y aplicar un proceso iterativo consistente en transformar el código para usar sólo los elementos que tengan su equivalente en un lenguaje de descripción de hardware.

#Módulos
Los módulos (module) son los bloques básicos en el diseño de una jerarquía en SystemC. Un modelo SystemC consta habitualmente de varios módulos que se comunican a través de los puertos.

#Puertos
Los puertos (port) permiten la comunicación de un módulo con el exterior, normalmente con otros módulos.

#Procesos
Los procesos (processes) son los principales elementos de computación. Son concurrentes.

#Canales
Los canales son elementos de comunicación de SystemC. Pueden ser simples cables o complejos mecanismos como sistemas FIFO o buses. Los canales básicos son:

signal (  el mas usado en clase)
buffer
FIFO
mutex
semaphore
Interfaces
Los puertos usan las interfaces para comunicarse con los canales.

#Eventos
Los eventos (events) permiten la sincronización entre procesos.

#Tipos de datos
SystemC introduce varios tipos de datos para dar soporte al modelado de hardware.

#Tipos extendidos
sc_int<> entero con signo de 64 bits
sc_uint<> entero sin signo de 64 bits
sc_bigint<> entero con signo de precisión arbitraria
sc_biguint<> entero sin signo de precisión arbitraria

#Tipos lógicos
sc_bit un bit con dos únicos valores posibles2-valued single bit
sc_logic un bit en el que se pueden dar 4 valores
sc_bv<> vector de sc_bit
sc_lv<> vector de sc_logic
sc_lv<> normalmente se expresa en números decimales

#Tipos de punto fijo
sc_fixed<> templated signed fixed point
sc_ufixed<> templated unsigned fixed point
sc_fix untemplated signed fixed point
sc_ufix untemplated unsigned fixed point



