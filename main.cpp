#include <iostream>
#include "imagenES.h"
#include "imagen.h"
#include "pattern.h"
#include "PatternList.h"

using namespace std;

typedef unsigned char byte;

int main(int argc, char *argv[]){
    char *origen;
    char *destino;
    if(argc != 3){
        cout<<"El programa minimo tiene que tener dos argumentos <IMAGEN ENTRADA>"<<endl;
        exit(1);
    }
    origen = argv[1];
    destino = argv[2];

    Pattern first(5,4,0,1,Pattern1,20);

    //display pattern1 
    for(int i=0;i<20;i++){
        std::cout << Pattern1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    first.Display();

    Image IMAGEN(origen);
    IMAGEN.SeachPattern(first);
    IMAGEN.Guardar(destino);

    return 0;
}
