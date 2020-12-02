#include <iostream>
#include "imagenES.h"
#include "imagen.h"

using namespace std;

typedef unsigned char byte;

int main(int argc, char *argv[]){
    char *origen, *destino;

    if(argc != 3){
        cout<<"El programa minimo tiene que tener dos argumentos <IMAGEN ENTRADA> <IMAGEN SALIDA>"<<endl;
        exit(1);
    }

    origen = argv[1];
    destino = argv[2];

    Image IMAGEN(origen);
    cout<<"RECOMENDADO: ALHAMBRA"<<endl;

    cout<<endl<<"Las Opciones Disponibles para Imagenes a COLOR son:"<<endl;
    cout<<"\t(1) Aumentar.          Aumentar una imagen de Tamaño por un factor n"<<endl;
    cout<<"\t(2) Disminuir.         Disminuir el tamaño de una imagen por un factor n"<<endl;
    cout<<"\t(3) Escala de Grises.  "<<endl;
    cout<<"\t(4) Histograma.        Histograma \% de Colores"<<endl;

    cout<<endl<<"Las Opciones Disponibles para Imagenes en escala de GRIS son:"<<endl;
    cout<<"\t(1) Aumentar.          Aumentar una imagen de Tamaño por un factor n"<<endl;
    cout<<"\t(2) Disminuir.         Disminuir el tamaño de una imagen por un factor n"<<endl;
    cout<<"\t(5) Umbralizacion.     Punto medio de Umbralizacion con un factor n"<<endl;
    cout<<"\t(6) Estiramiento."<<endl;
    
    int n;
    int a;

    cout<<endl<<"QUE DESEAS HACER: ";
    cin>>n;

    switch (n){
        case 1:
            cout<<endl<<endl<<"Introduce el factor n: ";
            cin>>a;
            IMAGEN.Escalar(a);
        break;
    
        case 2:
            cout<<endl<<"Introduce el factor n: ";
            cin>>a;
            IMAGEN.Icono(a);
        break;

        case 3:
            IMAGEN.Gris();
        break;

        case 4:
            IMAGEN.Histograma();
        break;

        case 5:
            cout<<endl<<"Introduce el factor de estiramiento: ";
            cin>>a;
            IMAGEN.Umbralizacion(a);
        break;

        case 6:
            IMAGEN.Estiramiento();
        break;

        default:
        break;
    }

    IMAGEN.Guardar(destino);

    return 0;
}
