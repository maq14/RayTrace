#ifndef LAMP_H
#define LAMP_H
#include "cobject.h"
#include "intersectresult.h"
#include "gvector3.h"
#include <cmath>
#include "cray.h"

class Lamp:public CObject
{
public:
    Lamp();
    Lamp(GVector3 center,float radius,GVector3 normal);
    IntersectResult isIntersected(CRay ray);
    bool isCircled(GVector3 point);
    ~Lamp();
    bool isLight();
    GVector3 getCenter(){
        return center;
    }
    GVector3 getNormal(GVector3 point){
        return normal;
    }
private:
    GVector3 center;
    float radius;
    GVector3 normal;
};

#endif // LAMP_H
