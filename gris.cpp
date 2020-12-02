#include "imagen.h"
#include <iostream>

void Image::Gris(){
    if(!imagewb){
        int temp;
        for(int i=0;i<fils*cols*3;i=i+3){
            temp = (vector[i]+vector[i+1]+vector[i+2])/3;
            vector[i]=temp;
            vector[i+1]=temp;
            vector[i+2]=temp;
        }
    }else{
        std::cout<<"La funcion solo es compatible con imagenes a color"<<std::endl;
        exit(1);
    }
}