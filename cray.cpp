#include "cray.h"

CRay::CRay()
{

}


CRay::CRay(GVector3 _origin, GVector3 _direction)
{
    origin = _origin;
    direction = _direction;
}



void CRay::setOrigin(GVector3 o)
{
    origin = o;
}

void CRay::setDirection(GVector3 d)
{
    direction = d;
}

GVector3 CRay::getOrigin()
{
    return origin;
}

GVector3 CRay::getDirection()
{
    return direction;
}

GVector3 CRay::getPoint(float t)
{
    return origin+direction*t;
}

CRay::~CRay()
{

}
