#ifndef CSPHERE_H
#define CSPHERE_H
#include "cray.h"
#include "gvector3.h"
#include "intersectresult.h"
#include "cobject.h"
#include "material.h"
#include <cmath>

class CSphere:public CObject
{
public:
    CSphere();
    CSphere(GVector3 center, double radius);
    CSphere(CSphere& s);
    void setCenter(GVector3 center);
    void setRadius(double radius);
    GVector3 getCenter();
    double getRadius();
    virtual GVector3 getNormal(GVector3 point);
    virtual IntersectResult isIntersected(CRay ray);
    virtual ~CSphere();
    void setMaterial(Material* material){
        this->material = material;
    }

    Material* getMaterial(){
        return material;
    }

    bool isLight();
    bool isSphere();

private:
    GVector3 center;
    double radius;
    Material* material;
};
#endif // CSPHERE_H
