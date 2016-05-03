#ifndef CMODEL_H
#define CMODEL_H
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include "gvector3.h"
#include "cobject.h"
#include "cray.h"
#include "intersectresult.h"
#include "ctriangle.h"
#include "material.h"
#include "phongmaterial.h"
#include <fstream>


class CModel:public CObject
{
public:
    CModel();
    CModel(char* objfile);
    void load();
    IntersectResult isIntersected(CRay ray);
    virtual ~CModel();
    bool isLight();
    Material* getMaterial();
    GVector3 getNormal(GVector3 point);
    void setMaterial(Material* material);
private:
    char* filename;
    vector<CTriangle> triangles;
    int index;
    int number;
    Material* material;
};

#endif // CMODEL_H
