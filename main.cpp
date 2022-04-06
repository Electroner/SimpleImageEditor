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

    Pattern p1(5,4,0,1,Pattern1,20);
    Pattern p2(5,4,0,1,Pattern2,20);
    Pattern p3(5,4,0,1,Pattern3,20);
    Pattern p4(4,4,0,1,Pattern4,16);
    Pattern p5(4,4,0,1,Pattern5,16);
    Pattern p6(5,4,0,1,Pattern6,20);
    Pattern p7(5,4,0,1,Pattern7,20);
    Pattern p8(5,4,0,1,Pattern8,20);
    Pattern p9(4,4,0,1,Pattern9,16);
    Pattern p10(4,4,0,1,Pattern10,16);
    Pattern p11(4,5,0,1,Pattern11,20);
    Pattern p12(4,5,0,1,Pattern12,20);
    Pattern p13(4,5,0,1,Pattern13,20);
    Pattern p14(4,4,0,1,Pattern14,16);
    Pattern p15(4,4,0,1,Pattern15,16);
    Pattern p16(4,5,0,0,Pattern16,20);
    Pattern p17(4,5,0,0,Pattern17,20);
    Pattern p18(4,5,0,0,Pattern18,20);
    Pattern p19(4,4,0,0,Pattern19,16);
    Pattern p20(4,4,0,0,Pattern20,16);
    Pattern p21(5,4,0,1,Pattern21,20);
    Pattern p22(5,4,0,1,Pattern22,20);
    Pattern p23(5,4,0,1,Pattern23,20);
    Pattern p24(4,4,0,1,Pattern24,16);
    Pattern p25(4,4,0,1,Pattern25,16);
    Pattern p26(5,4,0,0,Pattern26,20);
    Pattern p27(5,4,0,0,Pattern27,20);
    Pattern p28(5,4,0,0,Pattern28,20);
    Pattern p29(4,4,0,0,Pattern29,16);
    Pattern p30(4,4,0,0,Pattern30,16);
    Pattern np1(5,4,0,1,NPattern1,20);
    Pattern np2(5,4,0,1,NPattern2,20);
    Pattern np3(5,4,0,1,NPattern3,20);
    Pattern np4(4,4,0,1,NPattern4,16);
    Pattern np5(4,4,0,1,NPattern5,16);
    Pattern np6(5,4,0,1,NPattern6,20);
    Pattern np7(5,4,0,1,NPattern7,20);
    Pattern np8(5,4,0,1,NPattern8,20);
    Pattern np9(4,4,0,1,NPattern9,16);
    Pattern np10(4,4,0,1,NPattern10,16);
    Pattern np11(4,5,0,1,NPattern11,20);
    Pattern np12(4,5,0,1,NPattern12,20);
    Pattern np13(4,5,0,1,NPattern13,20);
    Pattern np14(4,4,0,1,NPattern14,16);
    Pattern np15(4,4,0,1,NPattern15,16);
    Pattern np16(4,5,0,0,NPattern16,20);
    Pattern np17(4,5,0,0,NPattern17,20);
    Pattern np18(4,5,0,0,NPattern18,20);
    Pattern np19(4,4,0,0,NPattern19,16);
    Pattern np20(4,4,0,0,NPattern20,16);
    Pattern np21(5,4,0,1,NPattern21,20);
    Pattern np22(5,4,0,1,NPattern22,20);
    Pattern np23(5,4,0,1,NPattern23,20);
    Pattern np24(4,4,0,1,NPattern24,16);
    Pattern np25(4,4,0,1,NPattern25,16);
    Pattern np26(5,4,0,0,NPattern26,20);
    Pattern np27(5,4,0,0,NPattern27,20);
    Pattern np28(5,4,0,0,NPattern28,20);
    Pattern np29(4,4,0,0,NPattern29,16);
    Pattern np30(4,4,0,0,NPattern30,16);

    std::vector<Pattern> patterns;
    
    patterns.push_back(p1);
    patterns.push_back(p2);
    patterns.push_back(p3);
    patterns.push_back(p4);
    patterns.push_back(p5);
    patterns.push_back(p6);
    patterns.push_back(p7);
    patterns.push_back(p8);
    patterns.push_back(p9);
    patterns.push_back(p10);
    patterns.push_back(p11);
    patterns.push_back(p12);
    patterns.push_back(p13);
    patterns.push_back(p14);
    patterns.push_back(p15);
    patterns.push_back(p16);
    patterns.push_back(p17);
    patterns.push_back(p18);
    patterns.push_back(p19);
    patterns.push_back(p20);
    patterns.push_back(p21);
    patterns.push_back(p22);
    patterns.push_back(p23);
    patterns.push_back(p24);
    patterns.push_back(p25);
    patterns.push_back(p26);
    patterns.push_back(p27);
    patterns.push_back(p28);
    patterns.push_back(p29);
    patterns.push_back(p30);
    patterns.push_back(p1);
    patterns.push_back(np2);
    patterns.push_back(np3);
    patterns.push_back(np4);
    patterns.push_back(np5);
    patterns.push_back(np6);
    patterns.push_back(np7);
    patterns.push_back(np8);
    patterns.push_back(np9);
    patterns.push_back(np10);
    patterns.push_back(np11);
    patterns.push_back(np12);
    patterns.push_back(np13);
    patterns.push_back(np14);
    patterns.push_back(np15);
    patterns.push_back(np16);
    patterns.push_back(np17);
    patterns.push_back(np18);
    patterns.push_back(np19);
    patterns.push_back(np20);
    patterns.push_back(np21);
    patterns.push_back(np22);
    patterns.push_back(np23);
    patterns.push_back(np24);
    patterns.push_back(np25);
    patterns.push_back(np26);
    patterns.push_back(np27);
    patterns.push_back(np28);
    patterns.push_back(np29);
    patterns.push_back(np30);

    Image IMAGEN(origen);
    Image SALIDA(origen);

    SALIDA.clear();

    IMAGEN.SeachNPattern(patterns, SALIDA);
    SALIDA.Guardar(destino);

    return 0;
}
