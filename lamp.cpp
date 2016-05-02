#include "lamp.h"

Lamp::Lamp()
{

}

Lamp::Lamp(GVector3 center, float radius, GVector3 normal)
{
    this->center = center;
    this->radius = radius;
    this->normal = normal;
}

IntersectResult Lamp::isIntersected(CRay ray)
{
    IntersectResult result = IntersectResult::noHit();
    float a = ray.getDirection().dotMul(normal);
    if(a<0){
        float b = normal.dotMul(center - ray.getOrigin());
        float distance = b/a;
        GVector3 point = ray.getPoint(distance);
        if(isCircled(point)){
            result.isHit = 1;
            result.distance = distance;
            result.normal = normal;
            result.object = this;
            result.position = point;
        }
    }
    return result;
}

bool Lamp::isCircled(GVector3 point)
{
    float dx = point.getX() - center.getX();
    float dy = point.getY() - center.getY();
    float dz = point.getZ() - center.getZ();
    float distance = dx*dx+dy*dy+dz*dz;
    distance = sqrt(distance);
    if(distance<=radius) return true;
    else return false;
}

Lamp::~Lamp()
{

}

bool Lamp::isLight()
{
    return true;
}
