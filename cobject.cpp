#include "cobject.h"

CObject::CObject()
{

}

IntersectResult CObject::isIntersected(CRay ray)
{
    return IntersectResult::noHit();
}

CObject::~CObject()
{

}

bool CObject::isLight()
{
    return false;
}

GVector3 CObject::getNormal(GVector3 point)
{
    return GVector3(0,0,1);
}
