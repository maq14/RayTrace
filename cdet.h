#ifndef CDET_H
#define CDET_H
#include "gvector3.h"


class CDet
{
public:
    CDet();
    CDet(GVector3 a,GVector3 b,GVector3 c);
    float getValue();
private:
    GVector3 a,b,c;
};

#endif // CDET_H
