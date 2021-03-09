//
// Created by admin on 09.03.2021.
//

#ifndef SDIZO_1_USEFULENUMS_H
#define SDIZO_1_USEFULENUMS_H


enum class Side : bool
{
    RIGHT,
    LEFT
};

Side operator!(Side side)
{
    if(side == Side::RIGHT)
    {
        return Side::LEFT;
    }
    else
    {
        return Side::RIGHT;
    }
}

enum class Color : bool
{
    RED,
    BLACK
};

#endif //SDIZO_1_USEFULENUMS_H
