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
    virtual IntersectResult isIntersected(CRay ray);
    virtual ~CObject();
    virtual bool isLight();
    virtual Material* getMaterial(){
        return NULL;
    }
    virtual GVector3 getNormal(GVector3 point);
    virtual bool isSphere(){
        return false;
    }
    int code;
};

#endif // COBJECT_H
