#include "plane.h"

Plane::Plane()
{

}

Plane::Plane(GVector3 normal, float _d)
{
    this->normal = normal;
    this->d = _d;
}

Plane::~Plane()
{

}

IntersectResult Plane::isIntersected(CRay ray)
{
    IntersectResult result = IntersectResult::noHit();
    float a = this->normal.dotMul(ray.getDirection());
    if(a<0){
        result.isHit=1;
        result.object = this;
        float b = this->normal.dotMul(normal*((-1)*d)-ray.getOrigin());
        result.distance = b/a;
        result.position = ray.getPoint(result.distance);
        result.normal = this->normal;
    }
    return result;
}

void Plane::setMaterial(Material* material)
{
    this->material = material;
}

Material* Plane::getMaterial()
{
    return this->material;
}

bool Plane::isLight()
{
    return false;
}
