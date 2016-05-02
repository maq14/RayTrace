#include "gvector3.h"
float MAX(float x,float y){
    if(x>y) return x;
    return y;
}
float MIN(float x,float y){
    if(x>y) return y;
    return x;
}
GVector3::GVector3()
{

}

GVector3::~GVector3()
{

}

GVector3::GVector3(float x, float y, float z)
{
    this->x =x;this->y =y;this->z =z;
}

void GVector3::getInfo()
{
    printf("%f,%f,%f\n",x,y,z);
}

GVector3 GVector3::operator+(GVector3 v)
{
    return GVector3(this->x+v.getX(),this->y+v.getY(),this->z+v.getZ());
}

GVector3 GVector3::operator-(GVector3 v)
{
    return GVector3(this->x-v.getX(),this->y-v.getY(),this->z-v.getZ());
}

GVector3 GVector3::operator*(float n)
{
    return GVector3(x*n,y*n,z*n);
}

GVector3 GVector3::operator/(float n)
{
    return GVector3(x/n,y/n,z/n);
}

float GVector3::dotMul(GVector3 v2)
{
    float mul = x*v2.getX()+y*v2.getY()+z*v2.getZ();
    return mul;
}

GVector3 GVector3::crossMul(GVector3 v2)
{
    float xx = y*v2.getZ()-z*v2.getY();
    float yy = z*v2.getX()-x*v2.getZ();
    float zz = x*v2.getY()-y*v2.getX();
    return GVector3(xx,yy,zz);
}

GVector3 GVector3::abs()
{
    float xx,yy,zz;
    if(x<0) xx=(-1)*x;
    if(y<0) yy=(-1)*y;
    if(z<0) zz=(-1)*z;
    return GVector3(xx,yy,zz);
}

float GVector3::max()
{
    float tmp = MAX(x,y);
    return MAX(tmp,z);
}

float GVector3::min()
{
    float tmp = MIN(x,y);
    return MIN(tmp,z);
}

float GVector3::getLength()
{
    return (float)sqrt(x*x+y*y+z*z);
}

GVector3 GVector3::normalize()
{
    float length = getLength();
    float xx = x/length;
    float yy = y/length;
    float zz = z/length;
    return GVector3(xx,yy,zz);
}

float GVector3::getDist(GVector3 v2)
{
    float dismul = (x-v2.getX())*(x-v2.getX())+(y-v2.getY())*(y-v2.getY())+(z-v2.getZ())*(z-v2.getZ());
    return sqrt(dismul);
}
