#include "ctriangle.h"

CTriangle::CTriangle()
{

}

CTriangle::CTriangle(GVector3 a, GVector3 b, GVector3 c)
{
    this->a = a;
    this->b = b;
    this->c = c;
    GVector3 m = b-a;
    GVector3 n = c-a;
    normal = m.crossMul(n);
    normal = normal.normalize();
}

IntersectResult CTriangle::isIntersected(CRay ray)
{
    float beta,gama,t;
    CDet det_1(ray.getDirection(),a-b,a-c);
    CDet det_2(a-ray.getOrigin(),a-b,a-c);
    CDet det_3(ray.getDirection(),a-ray.getOrigin(),a-c);
    CDet det_4(ray.getDirection(),a-b,a-ray.getOrigin());
    float divider = det_1.getValue();
    t = det_2.getValue() / divider;
    beta = det_3.getValue() / divider;
    gama = det_4.getValue() / divider;
    IntersectResult result = IntersectResult::noHit();
    if(isOk(beta) && isOk(gama)){
        result.isHit = 1;
        result.distance = t;
        result.normal = getNormal(GVector3());
        result.object = this;
        result.position = ray.getPoint(t);
    }
    return result;
}

CTriangle::~CTriangle()
{

}

bool CTriangle::isLight()
{
    return false;
}

Material *CTriangle::getMaterial()
{
    return material;
}

GVector3 CTriangle::getNormal(GVector3 point)
{
    return normal;
}

void CTriangle::setMaterial(Material *material)
{
    this->material = material;
}

bool CTriangle::isOk(float x)
{
    if(x>=0.0 && x<=1.0) return true;
    else return false;
}
