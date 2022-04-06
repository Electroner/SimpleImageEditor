#include "imagenES.h"
#include "pattern.h"
#include "PatternList.h"
#include <iostream>
#include <stdio.h>
#include <utility>
/** \mainpage IMAGEN
 *
 * Esta Clase es para la practica de ED 2º Curso de Ing. Informatica
 * 
 *  Permite usar varias funciones para imagenes a color y en blanco/negro del tipo .ppm y .pgm.
 *  Ademas usa funiones de la libreria ImagenES.h par poder cargar imagnenes mas facilmente.
 * 
 * \image html clases.png
 * 
 * CLASE IMAGEN : Image
 */ 

/**
 * @file imagen.h
 * @author Carlos Lopez Martinez (clm2001@correo.ugr.es)
 * @brief  IMAGEN.H
 * @version 1.0
 * @date 2020-10-29
 * 
 * @copyright Copyright (c) 2020
 * 
 *  Permite usar varias funciones para imagenes a color y en blanco/negro del tipo .ppm y .pgm.
 *  Ademas usa funiones de la libreria ImagenES.h par poder cargar imagnenes mas facilmente.
 * 
 */
#ifndef IMAGEN_H 
#define IMAGEN_H

class Image{
private:
    long int npixels;       /*!< Cantidad de pixeles que tiene la imagen*/
    int cols;               /*!< Cantidad de columnas que tiene la imagen*/
    int fils;               /*!< Cantidad de filas que tiene la imagen */
    bool imagewb;           /*!< PGM : TRUE , PPM : FALSE*/
    unsigned char *vector;  /*!< Imagen*/
    
public:
    /**
     * @brief Constructor de la clase Imagen con 4 argumentos (Columnas,filas,Imagen,tipo)
     * 
     * @param _cols Cantidad de Columnas de la imagen
     * @param _fils Cantidad de Filas de la imagen
     * @param _vector Puntero a Imagen (Reserva dinamica)
     * @param _type Tipo de Imagen PGM : TRUE PPM : FALSE
     */
    Image(int _cols,int _fils,const unsigned char *_vector,bool _type);

    /**
     * @brief Constructor de la clase Imagen con el nombre del archivo (origen)
     * 
     * @param origen nombre del archivo (origen)
     */
    Image(char* origen);

    /**
     * @brief Destroy the Image object
     * 
     */
    ~Image();

    /**
     * @brief Devuelve el valor del pixel
     * 
     * @param num Valor para el acceso al pixel
     * @return Devuleve el valor de un pixel indicado en la imagen
     * @see Image
     */
    unsigned char getValue(long int num);

    /**
     * @brief Establece el valor de un pixel individual
     * 
     * @param num Valor para el acceso al pixel
     * @param value Valor que se va a insertar en la imagen
     * @see Image
     */
    void setValue(long int num, unsigned char value);

    /**
     * @brief Cambia la imagen guardada en memoria por una nueva pasado por referencia
     * 
     * @param _cols Cantidad de Columnas de la nueva imagen
     * @param _fils Cantidad de Filas de la nueva imagen
     * @param _vector Puntero a la nueva imagen de @a _fils x @a _cols pixeles
     * @param _type El tipo de la imagen para reservar el espacio (TRUE / FALSE)
     * @see Image
     * @see imagewb
     */
    void ReplaceImage(int _cols,int _fils,const unsigned char *_vector,bool _type);

    /**
     * @brief Devuelve la cantidad de filas de la imagen
     * 
     * @return La cantidad de filas de la imagen
     * @see Image
     */
    int getFils();

    /**
     * @brief Devuelve la cantidad de columnas de la imagen
     * 
     * @return La cantidad de columnas de la imagen
     * @see Image
     */
    int getCols();

    /**
     * @brief Devuelve la cantidad de pixeles de la imagen
     * 
     * @return Cantidad de pixeles de la imagen
     * @see Image
     */
    long int getnpixels();

    /**
     * @brief La imagen
     * 
     * @return Devuelve el puntero a la imagen
     * @see Image
     */
    unsigned char *getImage();

    /**
     * @brief Guarda la imagen en un destino
     * 
     * @param destino Cadena de caracteres del destino de la imagen
     */
    void Guardar(char* destino);

    /**
     * @brief Transforma una imagen a color a escala de Grises 
     * 
     * @warning Solo funciona con imagenes a color
     * @details Usa la media aritmetica de cada pixel (R,G,B)/3 para dar como resultado un pixel
     */
    void Gris();

    /**
     * @brief Saca por consola los porcentajes de color de la imagen
     * 
     * @warning Solo funciona con imagenes a color
     * @details Suma todos los valores de cada pixel multiplicados por su posicion para obtener un valor 
     */
    void Histograma();

    /**
     * @brief Aumenta de tamaño una imagen con un valor entero N
     * 
     * @param multi Factor N de aumento de la imagen
     * @details Para calcular la media de los puntos nuevos usaremos:  \image html Formula_Escalar.png
     */
    void Escalar(int multi);

    /**
     * @brief Crea el efecto de umbralizacion
     * 
     * @param puntomedio El punto de inflexion valor de 0 a 255 
     * @warning Solo para imagenes en blanco y negro
     * @details Lleva un punto al minimo o al maximo dependiendo si el valor del pixel esta por encima o por debajo del valor dado
     */
    void Umbralizacion(int puntomedio);

    /**
     * @brief Estira los pixeles para el rango dinamico de la imagen sea completo de 0 a 255
     * 
     * @warning Solo para imagenes en blanco y negro
     * @details Coloca el pixel mas pequeño de la imagen en el 0 y el mayor en 255 y el resto los reparte de manera regular de 0 a 255
     */
    void Estiramiento();

    /**
     * @brief Decrementa el tamaño de la imagen por factor N
     * 
     * @param multi Factor N
     * @details Para calcular la media de los N puntos por seccion usaremos:  \image html Formula_Icono.png
     */
    void Icono(int multi);

    void Display();

    void clear();

    int toVector(int _x, int _y,int _channel);

    std::vector<std::pair<int,int>> SeachPattern(Pattern _pattern);

    void SeachNPattern(std::vector<Pattern> _patterns, Image &_image);
};

#endif
