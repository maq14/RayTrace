#include "material.h"

Material::Material()
{

}

Material::Material(float _reflectiveness)
{
    this->reflectiveness = _reflectiveness;
}

void Material::setRef(float _reflectiveness)
{
    this->reflectiveness = _reflectiveness;
}

float Material::getRef()
{
    return this->reflectiveness;
}

Material::~Material()
{

}
