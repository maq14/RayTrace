#ifndef PLANE_H
#define PLANE_H
#include "gvector3.h"
#include "cobject.h"
#include "material.h"

class Plane: public CObject
{
public:
    Plane();
    Plane(GVector3 normal,float _d);
    ~Plane();
    IntersectResult isIntersected(CRay ray);
    void setMaterial(Material* material);
    Material* getMaterial();
    bool isLight();
    GVector3 getNormal(GVector3 point){
        return normal;
    }

private:
    GVector3 normal;
    float d;
    Material* material;
};
#endif // PLANE_H
