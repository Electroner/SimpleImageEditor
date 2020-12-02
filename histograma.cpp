#include "imagen.h"
#include <iostream>

using namespace std;

struct RGBHIS{
    int R[255]={0};
    int G[255]={0};
    int B[255]={0};
};

void Image::Histograma(){
    if(!imagewb){
        RGBHIS himage;
        double rvalue=0,gvalue=0,bvalue=0;
        double rpercent=0,gpercent=0,bpercent=0;
        for(int i=0;i<fils*cols*3;i=i+3){
            himage.R[vector[i]]++;
            himage.G[vector[i+1]]++;
            himage.B[vector[i+2]]++;
        }
        for(int i=0;i<255;i++){
            rvalue += himage.R[i]*i;
            gvalue += himage.G[i]*i;
            bvalue += himage.B[i]*i;
        }
        rpercent = rvalue / (rvalue+gvalue+bvalue);
        gpercent = gvalue / (rvalue+gvalue+bvalue);
        bpercent = bvalue / (rvalue+gvalue+bvalue);

        cout<<"Rojo  (%):"<<100*rpercent<<endl;
        cout<<"Verde (%):"<<100*gpercent<<endl;
        cout<<"Azul  (%):"<<100*bpercent<<endl;
    }else{
        cout<<"El histograma solo esta disponible para imagenes a color"<<endl;
        exit(1);
    }
}

