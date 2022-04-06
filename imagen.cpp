#include "imagen.h"

Image::Image(int _cols, int _fils, const unsigned char *_vector, bool _type)
{
	if (_type)
	{
		imagewb = true;
		cols = _cols;
		fils = _fils;
		npixels = cols * fils;
		vector = new unsigned char[npixels];
		for (int i = 0; i < npixels; i++)
		{
			vector[i] = _vector[i];
		}
	}
	else
	{
		imagewb = false;
		cols = _cols;
		fils = _fils;
		npixels = cols * fils * 3;
		vector = new unsigned char[npixels];
		for (int i = 0; i < npixels; i++)
		{
			vector[i] = _vector[i];
		}
	}
}

Image::Image(char *origen)
{
	int size = sizeof(origen);
	if (origen[size + 1] == 'g')
	{
		vector = LeerImagenPGM(origen, fils, cols);
		if (!vector)
		{
			std::cerr << "Error: No pudo leerse la imagen." << std::endl;
			std::cerr << "Terminando la ejecucion del programa." << std::endl;
			exit(1);
		}
		imagewb = true;
		this->npixels = cols * fils;
	}
	else
	{
		vector = LeerImagenPPM(origen, fils, cols);
		if (!vector)
		{
			std::cerr << "Error: No pudo leerse la imagen." << std::endl;
			std::cerr << "Terminando la ejecucion del programa." << std::endl;
			exit(1);
		}
		imagewb = false;
	}
	std::cout << std::endl;
	std::cout << "Fichero origen: " << origen << std::endl;
	std::cout << std::endl;
	std::cout << "Dimensiones de " << origen << ":" << std::endl;
	std::cout << "Imagen = " << fils << " filas x " << cols << " columnas " << std::endl;
	}

void Image::Guardar(char *destino)
{
	if (imagewb)
	{
		if (EscribirImagenPGM(destino, vector, fils, cols))
			std::cout << std::endl
					  << "La imagen se guardo en " << destino << std::endl;
		else
		{
			std::cerr << "Error: No pudo guardarse la imagen." << std::endl;
			std::cerr << "Terminando la ejecucion del programa." << std::endl;
			exit(2);
		}
	}
	else
	{
		if (EscribirImagenPPM(destino, vector, fils, cols))
			std::cout << std::endl
					  << "La imagen se guardo en " << destino << std::endl;
		else
		{
			std::cerr << "Error: No pudo guardarse la imagen." << std::endl;
			std::cerr << "Terminando la ejecucion del programa." << std::endl;
			exit(2);
		}
	}
}

Image::~Image()
{
	delete[] vector;
}

unsigned char Image::getValue(long int num)
{
	return vector[num];
}

void Image::ReplaceImage(int _cols, int _fils, const unsigned char *_vector, bool _type)
{
	delete[] vector;
	if (_type)
	{
		imagewb = true;
		cols = _cols;
		fils = _fils;
		npixels = cols * fils;
		vector = new unsigned char[npixels];
		for (int i = 0; i < npixels; i++)
		{
			vector[i] = _vector[i];
		}
	}
	else
	{
		imagewb = false;
		cols = _cols;
		fils = _fils;
		npixels = cols * fils * 3;
		vector = new unsigned char[npixels];
		for (int i = 0; i < npixels; i++)
		{
			vector[i] = _vector[i];
		}
	}
}

int Image::getFils()
{
	return fils;
}
int Image::getCols()
{
	return cols;
}
long int Image::getnpixels()
{
	return npixels;
}
unsigned char *Image::getImage()
{
	return vector;
}

void Image::Display()
{
	if (imagewb)
	{
		for (int i = 0; i < fils; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				std::cout << (int)vector[i * cols + j] << " ";
			}
			std::cout << std::endl;
		}
	}
	else
	{
		// Chanel R
		for (int i = 0; i < fils; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				std::cout << (int)vector[i * cols * 3 + j * 3] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		std::cout << std::endl;
		// Chanel G
		for (int i = 0; i < fils; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				std::cout << (int)vector[i * cols * 3 + j * 3 + 1] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		std::cout << std::endl;
		// Chanel B
		for (int i = 0; i < fils; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				std::cout << (int)vector[i * cols * 3 + j * 3 + 2] << " ";
			}
			std::cout << std::endl;
		}
	}
}

void Image::clear()
{
	for (int i = 0; i < cols*fils*3; i++)
	{
		this->vector[i] = 255;
	}
}

int Image::toVector(int x, int y, int chanel)
{
	return (x * cols * 3 + y * 3 + chanel);
}

std::vector<std::pair<int,int>> Image::SeachPattern(Pattern _pattern)
{
	std::vector<std::pair<int,int>> result;
	for (int x = 0; x < fils - _pattern.getX(); x++)
	{
		for (int y = 0; y < cols - _pattern.getY(); y++)
		{
			bool found = true;
			unsigned char R = vector[toVector(x + _pattern.getCharacteristicdigitx(), y + _pattern.getCharacteristicdigity(), 0)];
			unsigned char G = vector[toVector(x + _pattern.getCharacteristicdigitx(), y + _pattern.getCharacteristicdigity(), 1)];
			unsigned char B = vector[toVector(x + _pattern.getCharacteristicdigitx(), y + _pattern.getCharacteristicdigity(), 2)];
			for (int i = 0; i < _pattern.getX(); i++)
			{
				for (int j = 0; j < _pattern.getY(); j++)
				{
					if (_pattern.getData(i, j) == 1)
					{
						if (vector[toVector(x + i, y + j, 0)] == R && vector[toVector(x + i, y + j, 1)] == G && vector[toVector(x + i, y + j, 2)] == B && found)
						{
							found = true;
						}
						else
						{
							found = false;
						}
					}
					else
					{
						if (vector[toVector(x + i, y + j, 0)] == R && vector[toVector(x + i, y + j, 1)] == G && vector[toVector(x + i, y + j, 2)] == B)
						{
							found = false;
						}
					}
				}
			}
			if (found)
			{
				std::pair<int, int> temp;
				temp.first = x;
				temp.second = y;
				result.push_back(temp);
			}
		}
	}
	return result;
}

void Image::SeachNPattern(std::vector<Pattern> _patterns, Image &_image){
	std::vector<std::pair<int,int>> temp;
	std::vector<std::pair<int,int>> result;
	for(long unsigned int i = 0; i < _patterns.size(); i++){
		temp = SeachPattern(_patterns[i]);
		for(long unsigned int j = 0; j < temp.size(); j++){
			result.push_back(temp[j]);
		}

		//Copy the pattern to the image
		for(long unsigned int j = 0; j < temp.size(); j++){
			for(int k = 0; k < _patterns[i].getX(); k++){
				for(int l = 0; l < _patterns[i].getY(); l++){
					if(_patterns[i].getData(k,l) == 1){
						if(	vector[toVector(temp[j].first + k, temp[j].second + l, 0)] == 255 && vector[toVector(temp[j].first + k, temp[j].second + l, 1)] == 255 && vector[toVector(temp[j].first + k, temp[j].second + l, 2)] == 255){
							_image.vector[toVector(temp[j].first + k, temp[j].second + l, 0)] = 255;
							_image.vector[toVector(temp[j].first + k, temp[j].second + l, 1)] = 255;
							_image.vector[toVector(temp[j].first + k, temp[j].second + l, 2)] = 255;
						}else{
							_image.vector[toVector(temp[j].first + k, temp[j].second + l, 0)] = vector[toVector(temp[j].first + k, temp[j].second + l, 0)];
							_image.vector[toVector(temp[j].first + k, temp[j].second + l, 1)] = vector[toVector(temp[j].first + k, temp[j].second + l, 1)];
							_image.vector[toVector(temp[j].first + k, temp[j].second + l, 2)] = vector[toVector(temp[j].first + k, temp[j].second + l, 2)];
						}
					}
				}
			}
		}
		temp.clear();
	}
	std::cout << "Found " << result.size() << " patterns." << std::endl;
}