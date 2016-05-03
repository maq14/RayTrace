#include "cdet.h"

CDet::CDet()
{

}

CDet::CDet(GVector3 a, GVector3 b, GVector3 c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

float CDet::getValue()
{
    float positive = a.getX()*b.getY()*c.getZ() + b.getX()*c.getY()*a.getZ() + c.getX()*a.getY()*b.getZ();
    float negative = c.getX()*b.getY()*a.getZ() + c.getY()*b.getZ()*a.getX() + c.getZ()*b.getX()*a.getY();
    float value = positive - negative;
    return value;
}
