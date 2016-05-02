#ifndef CHECKERMATERIAL_H
#define CHECKERMATERIAL_H
#include "material.h"
#include "gvector3.h"
#include "cray.h"
#include "color.h"

class checkerMaterial:public Material
{
public:
    checkerMaterial();
    checkerMaterial(float _reflectiveness,float scale);
    Color sample(CRay ray,GVector3 position,GVector3 normal);
    virtual ~checkerMaterial();
private:
    float scale;
};

#endif // CHECKERMATERIAL_H
