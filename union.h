#ifndef UNION_H
#define UNION_H
#include <vector>
#include "cobject.h"
#include "cray.h"
#include "intersectresult.h"
#include "color.h"
#include "lamp.h"
#include "material.h"

static int max_depth = 20;

class Union
{
public:
    Union();
    void push(CObject* object);
    Color rayTrace(CRay ray,int depth,CObject* &_object,IntersectResult*& res);
private:
    vector<CObject*> CVector;
};
#endif // UNION_H
