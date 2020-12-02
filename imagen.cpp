#include "imagen.h"
#include "imagenES.h"
#include <iostream>
#include <stdio.h>

Image::Image(int _cols,int _fils,const unsigned char *_vector,bool _type){
    if(_type){
        imagewb = true;
        cols = _cols;
        fils = _fils;
        npixels = cols*fils;
        vector = new unsigned char[npixels];
        for(int i=0;i<npixels;i++){
            vector[i] = _vector[i];
        }
    }else{
        imagewb = false;
        cols = _cols;
        fils = _fils;
        npixels = cols*fils*3;
        vector = new unsigned char[npixels];
        for(int i=0;i<npixels;i++){
            vector[i] = _vector[i];
        }
    }
}

Image::Image(char* origen){
    int size = sizeof(origen);
    if(origen[size+1] == 'g'){
        vector = LeerImagenPGM(origen, fils, cols);
        if (!vector){
            std::cerr << "Error: No pudo leerse la imagen." << std::endl;
            std::cerr << "Terminando la ejecucion del programa." << std::endl;
            exit (1);
        }
        imagewb = true;
    }else{
        vector = LeerImagenPPM(origen, fils, cols);
        if (!vector){
            std::cerr << "Error: No pudo leerse la imagen." << std::endl;
            std::cerr << "Terminando la ejecucion del programa." << std::endl;
            exit (1);
        }
        imagewb = false;
    }
    std::cout << std::endl;
    std::cout << "Fichero origen: " << origen << std::endl;
    std::cout << std::endl;
    std::cout << "Dimensiones de " << origen << ":" << std::endl;
    std::cout << "Imagen = " << fils  << " filas x " << cols << " columnas " << std::endl;
}

void Image::Guardar(char* destino){
    if(imagewb){
        if (EscribirImagenPGM (destino, vector, fils, cols))
            std::cout  << std::endl << "La imagen se guardo en " << destino << std::endl;
        else{
            std::cerr << "Error: No pudo guardarse la imagen." << std::endl;
            std::cerr << "Terminando la ejecucion del programa." << std::endl;
            exit (2);
        }
    }else{
        if (EscribirImagenPPM (destino, vector, fils, cols))
            std::cout  << std::endl << "La imagen se guardo en " << destino << std::endl;
        else{
            std::cerr << "Error: No pudo guardarse la imagen." << std::endl;
            std::cerr << "Terminando la ejecucion del programa." << std::endl;
            exit (2);
        }
    }
}

Image::~Image(){
    delete [] vector;
}

unsigned char Image::getValue(long int num){
    return vector[num];
}

void Image::ReplaceImage(int _cols,int _fils,const unsigned char *_vector,bool _type){
    delete [] vector;
    if(_type){
        imagewb = true;
        cols = _cols;
        fils = _fils;
        npixels = cols*fils;
        vector = new unsigned char[npixels];
        for(int i=0;i<npixels;i++){
            vector[i] = _vector[i];
        }
    }else{
        imagewb = false;
        cols = _cols;
        fils = _fils;
        npixels = cols*fils*3;
        vector = new unsigned char[npixels];
        for(int i=0;i<npixels;i++){
            vector[i] = _vector[i];
        }
    }
}

int Image::getFils() {
    return fils;
}
int Image::getCols() {
    return cols;
}
long int Image::getnpixels() {
    return npixels;
}
unsigned char* Image::getImage(){
    return vector;
}