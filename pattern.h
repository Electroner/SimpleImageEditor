#include <vector>
#include <iostream>

#ifndef PATTERN_H
#define PATTERN_H

class Pattern
{
private:
    int x;
    int y;
    int characteristicdigitx;
    int characteristicdigity;
    std::vector<bool> Matrix;

public:
    Pattern(int _x, int _y, int _characteristicdigitx, int _characteristicdigity, bool *_Matrix, int _sizeMatrix)
    {
        this->x = _x;
        this->y = _y;
        this->characteristicdigitx = _characteristicdigitx;
        this->characteristicdigity = _characteristicdigity;
        for (int i = 0; i < _sizeMatrix; i++)
        {
            this->Matrix.push_back(_Matrix[i]);
        }
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    int getCharacteristicdigitx()
    {
        return characteristicdigitx;
    }

    int getCharacteristicdigity()
    {
        return characteristicdigity;
    }

    std::vector<bool> getMatrix()
    {
        return Matrix;
    }

    void setX(int _x)
    {
        this->x = x;
    }

    void setY(int _y)
    {
        this->y = y;
    }

    void setCharacteristicdigitx(int characteristicdigitx)
    {
        this->characteristicdigitx = characteristicdigitx;
    }

    void setCharacteristicdigity(int characteristicdigity)
    {
        this->characteristicdigity = characteristicdigity;
    }

    void setMatrix(std::vector<bool> _Matrix)
    {
        this->Matrix = _Matrix;
    }

    int toVector(int _x, int _y)
    {
        return (_x * this->y + _y);
    }

    bool getData(int _x, int _y)
    {
        return Matrix[toVector(_x, _y)];
    }

    void Display()
    {
        for (int i = 0; i < this->x; i++)
        {
            for (int j = 0; j < this->y; j++)
            {
                std::cout << getData(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif