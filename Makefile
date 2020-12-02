OBJS	= escalar.o estiramiento.o gris.o histograma.o icono.o imagen.o imagenES.o main.o umbralizacion.o
SOURCE	= escalar.cpp estiramiento.cpp gris.cpp histograma.cpp icono.cpp imagen.cpp imagenES.cpp main.cpp umbralizacion.cpp
HEADER	= imagen.h imagenES.h
OUT	= main
CC	 = g++
FLAGS	 = -g -c -O3 -Wall
LFLAGS	 = -lm

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

escalar.o: escalar.cpp
	$(CC) $(FLAGS) escalar.cpp 

estiramiento.o: estiramiento.cpp
	$(CC) $(FLAGS) estiramiento.cpp 

gris.o: gris.cpp
	$(CC) $(FLAGS) gris.cpp 

histograma.o: histograma.cpp
	$(CC) $(FLAGS) histograma.cpp 

icono.o: icono.cpp
	$(CC) $(FLAGS) icono.cpp 

imagen.o: imagen.cpp
	$(CC) $(FLAGS) imagen.cpp 

imagenES.o: imagenES.cpp
	$(CC) $(FLAGS) imagenES.cpp 

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

umbralizacion.o: umbralizacion.cpp
	$(CC) $(FLAGS) umbralizacion.cpp 

clean:
	rm -f $(OBJS) $(OUT)

#PORFAVOR USAR make doc PARA GENERAR LA DOCUMENTACION
doc:
	doxygen DoxygenConfig
