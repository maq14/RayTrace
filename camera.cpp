#include "camera.h"

Camera::Camera()
{

}

Camera::Camera(GVector3 eye, GVector3 front, GVector3 refUp, float fov)
{
    float PI = 3.1415926;
    this->eye = eye;
    this->front = front;
    this->refUp = refUp;
    this->fov = fov;
    this->right = front.crossMul(refUp);this->right.normalize();
    this->up = front.crossMul(right);this->up.normalize();
    this->fovScale = tan(this->fov* (PI  * 0.5f / 180)) * 2;
}

Camera::~Camera()
{

}

CRay Camera::generateRay(float x, float y)
{
    GVector3 r = right*((x - 0.5f) * fovScale);
    GVector3 u = up*((y - 0.5f) * fovScale);
    GVector3 tmp=front+r+u;
    tmp.normalize();
    return CRay(eye,tmp);
}
