#ifndef PHONGMATERIAL_H
#define PHONGMATERIAL_H
#include "material.h"
#include "cray.h"
#include "gvector3.h"
#include "color.h"

static Color lightColor = Color::white();

class phongMaterial:public Material
{
public:
    phongMaterial();
    phongMaterial(Color _diffuse,Color _specular,float _shinness,float diffuse_matter,float specular_matter,float _reflectiveness=0.1);
    Color sample(CRay ray,GVector3 position,GVector3 normal);
    void setLightDir(GVector3 lightDir);
    ~phongMaterial();
    Color getColor(){
        return diffuse;
    }
    GVector3 getLightDir(){
        return lightDir;
    }

private:
    Color diffuse;
    Color specular;
    float shinness;
    GVector3 lightDir;
    float diffuse_matter;
    float specular_matter;
};
#endif // PHONGMATERIAL_H
