#include "imagen.h"
#include <iostream>

void Image::Estiramiento(){
    if(imagewb){
        int min=255;
        int max=0;
        for(int i=0;i<fils*cols;i++){
            if(vector[i]<=min){
                min=vector[i];
            }
            if(vector[i]>=max){
                max=vector[i];
            }
        }
        for(int i=0;i<fils*cols;i++){
            if(vector[i] == min){
                vector[i]=0;
            }else if(vector[i] > min && vector[i] < max){
                vector[i]=(int)((255*(vector[i]-min))/(max-min));
            }else{
                vector[i]=255;
            }
        }
    }else{
        std::cout<<"La funcion no es aplicable a Imagenes a color o"<<std::endl;
        exit(1);
    }
}