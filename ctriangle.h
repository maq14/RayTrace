#ifndef CTRIANGLE_H
#define CTRIANGLE_H
#include "cray.h"
#include "cobject.h"
#include "gvector3.h"
#include "intersectresult.h"
#include "cdet.h"
#include "material.h"

class CTriangle:public CObject
{
public:
    CTriangle();
    CTriangle(GVector3 a,GVector3 b,GVector3 c);
    IntersectResult isIntersected(CRay ray);
    virtual ~CTriangle();
    bool isLight();
    Material* getMaterial();
    GVector3 getNormal(GVector3 point);
    void setMaterial(Material* material);
    bool isOk(float x);
private:
    GVector3 a,b,c;
    GVector3 normal;
    Material* material;
};

#endif // CTRIANGLE_H
