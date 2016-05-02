#ifndef MATERIAL_H
#define MATERIAL_H
#include "cray.h"
#include "gvector3.h"
#include "color.h"

class Material
{
public:
    Material();
    Material(float _reflectiveness);
    void setRef(float _reflectiveness);
    float getRef();
    virtual Color sample(CRay ray,GVector3 position,GVector3 normal)=0;
    virtual ~Material();
    virtual void setLightDir(GVector3 lightDir){

    }

    virtual GVector3 getLightDir(){
        return GVector3(0,0,0);
    }

    virtual Color getColor(){
        return Color::black();
    }

protected:
    float reflectiveness;
};

#endif // MATERIAL_H
