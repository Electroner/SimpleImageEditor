#include "imagen.h"
#include <iostream>

void Image::Umbralizacion(int puntomedio){
    if(imagewb && (puntomedio < 256 && puntomedio > 0)){
        for(int i=0;i<fils*cols;i++){
            if(vector[i]<=puntomedio){
                vector[i]=0;
            }else{
                vector[i]=255;
            }
        }
    }else{
        std::cout<<"La funcion no es aplicable a Imagenes a color o el Parametro no es el correcto"<<std::endl;
        exit(1);
    }
}