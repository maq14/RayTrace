#ifndef COBJECT_H
#define COBJECT_H
#include "intersectresult.h"
#include "cray.h"
#include "material.h"
#include "gvector3.h"

class IntersectResult;
class CObject
{
public:
    CObject();
    virtual IntersectResult isIntersected(CRay ray)=0;
    virtual ~CObject();
    virtual bool isLight()=0;
    virtual Material* getMaterial(){
        return NULL;
    }
    virtual GVector3 getNormal(GVector3 point)=0;
};

#endif // COBJECT_H
