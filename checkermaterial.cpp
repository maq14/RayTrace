#include "checkermaterial.h"

checkerMaterial::checkerMaterial()
{

}

checkerMaterial::checkerMaterial(float _reflectiveness, float scale)
{
    this->reflectiveness = _reflectiveness;
    this->scale = scale;
}

Color checkerMaterial::sample(CRay ray, GVector3 position, GVector3 normal)
{
    float d = abs(floor(position.getX()*scale) + floor(position.getY()*scale));
    d = fmod(d,2);
    return d<1?Color::black():Color::white();
}

checkerMaterial::~checkerMaterial()
{

}
