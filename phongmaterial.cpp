#include "phongmaterial.h"

phongMaterial::phongMaterial()
{

}

phongMaterial::phongMaterial(Color _diffuse, Color _specular, float _shinness, float diffuse_matter, float specular_matter, float _reflectiveness,float _refraction)
{
    diffuse = _diffuse;
    specular = _specular;
    shinness = _shinness;
    reflectiveness = _reflectiveness;
    this->diffuse_matter = diffuse_matter;
    this->specular_matter = specular_matter;
    this->refraction = _refraction;
}

Color phongMaterial::sample(CRay ray, GVector3 position, GVector3 normal)
{
    float NdotL = normal.dotMul(lightDir);
    float dp = lightDir.dotMul(normal)*2;
    GVector3 R = normal*dp - lightDir;
    R = R.normalize();
    float RDotV = (-1.0)*R.dotMul(ray.getDirection().normalize());
    Color diffuseTerm = this->diffuse.multiply(std::max(NdotL, (float)0));
    diffuseTerm = diffuseTerm.multiply(diffuse_matter);
    Color specularTerm = this->specular.multiply(pow(std::max(RDotV, (float)0), this->shinness));
    specularTerm = specularTerm.multiply(specular_matter);
    return lightColor.moderate(diffuseTerm.add(specularTerm));
}

void phongMaterial::setLightDir(GVector3 lightDir)
{
    this->lightDir = lightDir;
}

phongMaterial::~phongMaterial()
{

}
