#ifndef CAMERA_H
#define CAMERA_H
#include "gvector3.h"
#include "cray.h"

class Camera
{
    public:
        Camera();
        Camera(GVector3 eye,GVector3 front,GVector3 refUp,float fov);
        ~Camera();
        CRay generateRay(float x,float y);
    private:
        GVector3 eye;
        GVector3 front;
        GVector3 refUp;
        GVector3 up;
        GVector3 right;
        float fov;
        float fovScale;
};

#endif // CAMERA_H
