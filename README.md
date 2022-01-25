# SimpleImageEditor [![Generic badge](https://img.shields.io/badge/Build-Stable-green.svg)](https://shields.io/) [![Generic badge](https://img.shields.io/badge/Version-1.0-green.svg)](https://shields.io/) ![](https://tokei.rs/b1/github/Electroner/SimpleImageEditor)
Simple project that let you apply some filters to images, black and white, resizing by constant and thresholding.

[Requirements]

  The images will have an uncompressed format: .ppm y .pgm
  Both the source images have to be in the program folder, and destination image will be generated there as well.
  
 [Usage]
 
  There is a makefile for compilation, the makefile has command "doc" for generating the doxygen documentation.
 
  The main program will receive two parameters, image source and destination image (both files name ex:"car.pgm")
  
  Once the program is executed, a main menu will appear in the console asking you for the filter edit of the image. Depending in which option did you choose it will ask u again for some parameters.
  
 [Limitation]
 
  The program can handle every size of image, being limited by the physical memory limit.
  
