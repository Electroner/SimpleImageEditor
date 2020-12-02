#include "imagen.h"
#include <math.h>

unsigned char *redimensionarp(int _cols,int _fils,int _porcentaje,const unsigned char *_image){
    int nff= (int)(_fils/_porcentaje);
    int ncf= (int)(_cols/_porcentaje);
    int npixelesfinal = ncf*nff;
    unsigned char *vectorf;
    vectorf = new unsigned char[npixelesfinal];
    int temp;

    for(int i=0;i<nff;i++){
        for(int j=0;j<ncf;j++){
            temp = 0;
            for(int x=0;x<_porcentaje*_porcentaje;x++){
                temp+=_image[(j*_porcentaje+i*_cols*_porcentaje)+(x%_porcentaje)+((int)floor(x/_porcentaje)*_cols)];
            }
            temp=(int)(temp/(_porcentaje*_porcentaje));
            vectorf[j+i*ncf]=temp;
        }
    }
    return vectorf;
}

void Image::Icono(int porcentaje){
    if(imagewb){
        unsigned char *ifinal;
        
        ifinal = redimensionarp(cols,fils,porcentaje,vector);
        ReplaceImage((int)(cols/porcentaje),(int)(fils/porcentaje),ifinal,true);
        delete [] ifinal;
    }else{
        unsigned char R[fils*cols];
        unsigned char G[fils*cols];
        unsigned char B[fils*cols];
        unsigned char *RF;
        unsigned char *GF;
        unsigned char *BF;
        unsigned char *ifinal = new unsigned char[(int)(cols/porcentaje)*(int)(fils/porcentaje)*3];

        int temp=0;
        for(int i=0;i<fils*cols;i++){
            R[i]=vector[temp];
            G[i]=vector[temp+1];
            B[i]=vector[temp+2];
            temp=temp+3;
        }

        RF = redimensionarp(cols,fils,porcentaje,R);
        GF = redimensionarp(cols,fils,porcentaje,G);
        BF = redimensionarp(cols,fils,porcentaje,B);

        temp = 0;
        for(int i=0;i<((int)(cols/porcentaje)*(int)(fils/porcentaje));i++){
            ifinal[temp]  =RF[i];
            ifinal[temp+1]=GF[i];
            ifinal[temp+2]=BF[i];
            temp=temp+3;
        }

        ReplaceImage((int)(cols/porcentaje),(int)(fils/porcentaje),ifinal,false);
        delete [] RF;
        delete [] GF;
        delete [] BF;
        delete [] ifinal;
    }
}