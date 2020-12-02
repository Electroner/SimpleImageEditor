#include "imagen.h"
#include <math.h>
#include <iostream>

unsigned char *redimensionar(int _cols,int _fils,int _porcentaje,const unsigned char *_image){
    int nff= _fils*_porcentaje;
    int ncf= _cols*_porcentaje;
    int npixelesfinal = ncf*nff;
    unsigned char *vectorf = new unsigned char[npixelesfinal];
    
    for(int i=0;i<_fils;i++){
        for(int j=0;j<_cols;j++){
            vectorf[j*_porcentaje+i*ncf*_porcentaje]=_image[j+i*_cols];
            for(int x=1;x<_porcentaje*_porcentaje;x++){
                vectorf[(j*_porcentaje+i*ncf*_porcentaje)+(x%_porcentaje)+((int)floor(x/_porcentaje)*ncf)]=
                    (int)((_image[(j+i*_cols)]+_image[((j+i*_cols)+1)]+_image[(j+i*_cols+_cols)]+_image[((j+i*_cols+_cols)+1)])/4);
                    /*
                        PUNTOS: (IMAGEN PENQUEÑA (SOBRE image[])
                        (j+i*cols)
                        ((j+i*cols)+1)
                        (j+i*cols+cols)
                        ((j+i*cols+cols)+1)
                    */
            }
        }
    }
    return vectorf;
}

void Image::Escalar(int porcentaje){
    if(imagewb){
        unsigned char *ifinal;

        ifinal = redimensionar(cols,fils,porcentaje,vector);
        ReplaceImage((cols*porcentaje),(fils*porcentaje),ifinal,true);
        delete [] ifinal;
    }else{
        unsigned char R[fils*cols];
        unsigned char G[fils*cols];
        unsigned char B[fils*cols];
        unsigned char *RF;
        unsigned char *GF;
        unsigned char *BF;
        unsigned char *ifinal = new unsigned char[cols*fils*porcentaje*porcentaje*3];

        int temp=0;
        for(int i=0;i<fils*cols;i++){
            R[i]=vector[temp];
            G[i]=vector[temp+1];
            B[i]=vector[temp+2];
            temp=temp+3;
        }

        RF = redimensionar(cols,fils,porcentaje,R);
        GF = redimensionar(cols,fils,porcentaje,G);
        BF = redimensionar(cols,fils,porcentaje,B);

        temp = 0;
        for(int i=0;i<cols*fils*porcentaje*porcentaje;i++){
            ifinal[temp]  =RF[i];
            ifinal[temp+1]=GF[i];
            ifinal[temp+2]=BF[i];
            temp=temp+3;
        }

        ReplaceImage((cols*porcentaje),(fils*porcentaje),ifinal,false);
        delete [] RF;
        delete [] GF;
        delete [] BF;
        delete [] ifinal;
    }
}
