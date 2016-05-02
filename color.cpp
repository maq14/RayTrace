#include "color.h"

Color::Color()
{

}

Color::Color(float _r, float _g, float _b)
{
    this->r = _r;this->g = _g;this->b = _b;
}

Color Color::add(Color s)
{
    return Color(this->r+s.r,this->g+s.g,this->b+s.b);
}

Color Color::multiply(float s)
{
    return Color(r*s,g*s,b*s);
}

Color Color::moderate(Color s)
{
    return Color(this->r*s.r,this->g*s.g,this->b*s.b);
}

void Color::saturate()
{
    r=r>1.0?1.0:r;
    g=g>1.0?1.0:g;
    b=b>1.0?1.0:b;
}

Color::~Color()
{

}


