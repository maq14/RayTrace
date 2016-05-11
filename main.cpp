#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cvaux.hpp>
#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/ml.h>
#include <fstream>
#include "camera.h"
#include "cray.h"
#include "plane.h"
#include "intersectresult.h"
#include "cobject.h"
#include "gvector3.h"
#include "checkermaterial.h"
#include "material.h"
#include "csphere.h"
#include "phongmaterial.h"
#include "lamp.h"
#include "union.h"
#include "cmodel.h"

using namespace std;
using namespace cv;

int WINDOW_WIDTH = 1000;
int WINDOW_HEIGHT = 1000;
Mat m(WINDOW_WIDTH,WINDOW_HEIGHT,CV_8UC3,Scalar(0,0,0));

#define BYTE unsigned char

void drawpixel(Mat& mm,int x,int y,Color color)
{
    mm.at<Vec3b>(x,y)[0] = color.r*255;
    mm.at<Vec3b>(x,y)[1] = color.g*255;
    mm.at<Vec3b>(x,y)[2] = color.b*255;
}
void initScene(){
    //char ss[30] = ":/raytracing/obj/dragon.obj";
    Camera camera( GVector3(0, 0, 3),GVector3(1,0,0).normalize(),GVector3(0, 0, 1), 90);
    Plane plane1(GVector3(0, 0, 1),1.0);
    Plane plane2(GVector3(-1,0,0),50.0);
    Plane plane3(GVector3(0,1,0),20.0);
    Plane plane4(GVector3(0,-1,0),20.0);
    Plane plane5(GVector3(0,0,-1),20.0);
    plane1.setMaterial(new phongMaterial(Color::white(),Color::white(),16,0.6,0.2,0.2));
    //plane1.setMaterial(new checkerMaterial(0.0f,0.1f));
    plane2.setMaterial(new phongMaterial(Color::white(),Color::white(),16,0.6,0.1,0.0));
    plane3.setMaterial(new phongMaterial(Color::blue(),Color::white(),16,0.6,0.1,0.0));
    plane4.setMaterial(new phongMaterial(Color::red(),Color::white(),16,0.6,0.1,0.0));
    plane5.setMaterial(new phongMaterial(Color::white(),Color::white(),16,0.6,0.1,0.0));
    CSphere sphere(GVector3(16,0,3),3.9);
    CSphere sphere2(GVector3(13,8,2),2.9);
    CSphere sphere3(GVector3(13,-8,2),2.9);
    sphere2.setMaterial(new phongMaterial(Color::green(),Color::white(),16,0.0,0.0,0.0,1.5));
    sphere3.setMaterial(new phongMaterial(Color::green(),Color::white(),16,0.0,0.0,0.0,1.5));
    //CModel model(ss);
    //model.load();
    //model.setMaterial(new phongMaterial(Color::yellow(),Color::white(),16,0.8,0.3,0.0));
    //cout<<sphere.getCenter().getX()<<" "<<sphere.getCenter().getY()<<" "<<sphere.getCenter().getZ()<<" "<<sphere.getRadius()<<endl;
    sphere.setMaterial(new phongMaterial(Color::white(),Color::white(),16,0.0,1.0,1.0,0.0));
    Lamp light(GVector3(0,0,19.0),1.0,GVector3(0,0,-1));
    plane1.code=0;plane2.code=1;plane3.code=2;plane4.code=3;plane5.code=4;
    sphere.code=5;sphere2.code = 6;sphere3.code = 7;light.code = 8;
    Union unions;
    unions.push(&plane1);unions.push(&plane2);unions.push(&plane3);unions.push(&plane4);unions.push(&plane5);
    unions.push(&sphere);//unions.push(&model);
    unions.push(&light);
    unions.push(&sphere2);
    unions.push(&sphere3);

    long maxDepth=20;
    float dx=1.0f/WINDOW_WIDTH;
    float dy=1.0f/WINDOW_HEIGHT;
    float dD=255.0f/maxDepth;
    int num = 0;
    CObject *lastPrim=NULL,*nowPrim=NULL;IntersectResult* no_fic = NULL;
    for(int y=0;y<WINDOW_HEIGHT;y++){
        float sy = dy*y;
        for(int x=0;x<WINDOW_WIDTH;x++){
            float sx = dx*x;
            float r=0.0f,g=0.0f,b=0.0f;
            CRay newray = camera.generateRay(sx,sy);
            Color color = unions.rayTrace(newray,0,nowPrim,no_fic);
            if((nowPrim==NULL && lastPrim!=NULL) || (nowPrim!=NULL && lastPrim==NULL) || (nowPrim && lastPrim && nowPrim->code!=lastPrim->code)){
                for(int m_x=0;m_x<2;m_x++){
                    for(int m_y=0;m_y<2;m_y++){
                        float r_x = m_x / (float)WINDOW_WIDTH;
                        float r_y = m_y / (float)WINDOW_HEIGHT;

                        CRay newray = camera.generateRay(sx+r_x,sy+r_y);
                        Color color = unions.rayTrace(newray,0,nowPrim,no_fic);
                        r += color.r;
                        g += color.g;
                        b += color.b;
                    }
                }
                color.r = r/4.0f;
                color.g = g/4.0f;
                color.b = b/4.0f;
            }

            lastPrim = nowPrim;
            /*IntersectResult result = sphere.isIntersected(newray);
            if(result.isHit){

                //double t = MIN(result.distance*dD,255.0);
                //double depth = 255.0-t;
                //Color color(depth/255.0,depth/255.0,depth/255.0);
                Color color = sphere.getMaterial()->sample(newray,result.position,result.normal);
                color.saturate();
                drawpixel(m,y,x,color);
            }*/
            color.saturate();
            drawpixel(m,y,x,color);
        }
    }
}
int main()
{
    initScene();
    imshow("canvas",m);
    IplImage img = m;
    cvSaveImage("picture.jpg",&img);
    waitKey();
    return 0;
}
