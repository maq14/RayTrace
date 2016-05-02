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
