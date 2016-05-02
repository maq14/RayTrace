#ifndef GVECTOR3_H
#define GVECTOR3_H
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>


class GVector3{
    public:
        GVector3();
        ~GVector3();
        GVector3(float x,float y,float z);
        void getInfo();
        GVector3 operator+(GVector3 v);
        GVector3 operator-(GVector3 v);
        GVector3 operator*(float n);
        GVector3 operator/(float n);
        float dotMul(GVector3 v2);
        GVector3 crossMul(GVector3 v2);
        GVector3 abs();
        float max();
        float min();
        float getLength();
        GVector3 normalize();
        float getDist(GVector3 v2);
        static inline GVector3 zero(){
            return GVector3(0,0,0);
        }
        float getX(){return x;}
        float getY(){return y;}
        float getZ(){return z;}
        void setX(float xx){
            this->x = xx;
        }
        void setY(float yy){
            this->y = yy;
        }

        void setZ(float zz){
            this->z = zz;
        }
    private:
        float x,y,z;
};
#endif // GVECTOR3_H
