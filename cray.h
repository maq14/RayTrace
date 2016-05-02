#ifndef CRAY_H
#define CRAY_H
#include "gvector3.h"


class CRay
{
    public:
        CRay();
        CRay(GVector3 _origin,GVector3 _direction);
        void setOrigin(GVector3 o);
        void setDirection(GVector3 d);
        GVector3 getOrigin();
        GVector3 getDirection();
        GVector3 getPoint(float t);
        ~CRay();
   private:
        GVector3 origin;
        GVector3 direction;
};

#endif // CRAY_H
