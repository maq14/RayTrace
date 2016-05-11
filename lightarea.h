#ifndef LIGHTAREA_H
#define LIGHTAREA_H
#include "cobject.h"


class LightArea : public CObject
{
public:
    LightArea();
private:
    GVector3 dx;
    GVector3 dy;
    GVector3 center;
};

#endif // LIGHTAREA_H
