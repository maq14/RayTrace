#include "csphere.h"

CSphere::CSphere()
{

}

CSphere::CSphere(GVector3 center, double radius)
{
    this->center = center;
    this->radius = radius;
}

CSphere::CSphere(CSphere &s)
{
    this->center = s.getCenter();
    this->radius = s.getRadius();
}

void CSphere::setCenter(GVector3 center)
{
    this->center = center;
}

void CSphere::setRadius(double radius)
{
    this->radius = radius;
}

GVector3 CSphere::getCenter()
{
    return this->center;
}

double CSphere::getRadius()
{
    return this->radius;
}

GVector3 CSphere::getNormal(GVector3 point)
{
    return (point-center).normalize();
}

IntersectResult CSphere::isIntersected(CRay ray)
{
    IntersectResult result = IntersectResult::noHit();
    GVector3 v = ray.getOrigin() - this->getCenter();
    float DdotV = ray.getDirection().dotMul(v);
    float a0 = v.dotMul(v)-radius*radius;
    float a1 = ray.getDirection().dotMul(ray.getDirection());
    //if(DdotV<0){
        float discr = DdotV*DdotV-a0*a1;
        if(discr>0){
            float distance1 = ((-1)*DdotV-sqrt(discr))/a1;
            if(distance1>0) result.distance = distance1;
            else result.distance = ((-1)*DdotV+sqrt(discr))/a1;
            result.isHit = 1;
            result.object = this;
            result.position = ray.getPoint(result.distance);
            result.normal = result.position-center;
            result.normal.normalize();
            result.front = (result.normal.dotMul(ray.getDirection()) <= 0)? true : false;
        }
        if(result.distance < 0) return IntersectResult::noHit();
    //}
    return result;
}

CSphere::~CSphere()
{

}

bool CSphere::isLight()
{
    return false;
}

bool CSphere::isSphere()
{
    return true;
}
