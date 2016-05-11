#ifndef INTERSECTRESULT_H
#define INTERSECTRESULT_H
#include "gvector3.h"
#include "cobject.h"

using namespace std;
class CObject;

class IntersectResult
{
public:
    IntersectResult();
    ~IntersectResult();
    float distance;//就是CRay类中的t
    bool isHit;
    bool front;
    GVector3 position;//光线与物体的交点
    GVector3 normal;//光线与物体交点表面的法线
    CObject *object;
    static inline IntersectResult noHit(){
        IntersectResult s;
        s.isHit = 0;
        return s;
    }
};

#endif // INTERSECTRESULT_H
