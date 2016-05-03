#include "union.h"

Union::Union()
{

}

void Union::push(CObject *object)
{
    CVector.push_back(object);
}

Color Union::rayTrace(CRay ray, int depth)
{
    if(depth>max_depth)  return Color::black();
    int size = (int)CVector.size();
    float distance = 100000.0f;
    CObject* primitive_near = NULL;
    bool visible = true;
    Color totalColor = Color::black();
    CObject* pLight;
    int num=0;
    for(int i=0;i<size;i++){
        CObject* primitive = CVector.at(i);
        IntersectResult result = primitive->isIntersected(ray);
        if(result.isHit){
            if(result.distance < distance){
                distance = result.distance;
                primitive_near = result.object;
                num = i;
            }
        }
    }
    if(primitive_near == NULL) {
        return Color::black();
    }
    else if(primitive_near->isLight()){
        return Color::white();
    }
    else{
        GVector3 point;
        point = ray.getPoint(distance);
        for(int i=0;i<size;i++){
            CObject* primitive = CVector.at(i);
            if(primitive->isLight()){
                pLight = primitive;
                GVector3 inDir = ((Lamp*) primitive)->getCenter() - point;
                inDir = inDir.normalize();
                CRay line(point+inDir*0.001,inDir);
                for(int j=0;j<size;j++){
                    CObject* ano_primitive = CVector.at(j);
                    if(!ano_primitive->isLight() && j!=num){
                        IntersectResult result = ano_primitive->isIntersected(line);
                        if(result.isHit && result.distance < inDir.getLength()){
                            visible = false;
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
    GVector3 point;
    point = ray.getPoint(distance);
    if(visible){
        GVector3 lig = ((Lamp*)pLight)->getCenter() - point;
        lig = lig.normalize();
        primitive_near->getMaterial()->setLightDir(lig);
        totalColor = totalColor.add( primitive_near->getMaterial()->sample(ray, point, primitive_near->getNormal(point)) );
    }
    float reflection = primitive_near->getMaterial()->getRef();
    if( (reflection>0.0f) && (depth<max_depth) ){
        GVector3 normal_point = primitive_near->getNormal(point);
        normal_point = normal_point.normalize();
        float s0 = ray.getDirection().dotMul(normal_point) * (-2.0f);
        CRay newRay;
        newRay.setDirection(normal_point * s0 + ray.getDirection());
        newRay.setOrigin(point);
        Color reflectionColor = rayTrace(newRay,depth+1);
        reflectionColor = reflectionColor.multiply(reflection);
        //reflectionColor = reflectionColor.moderate(primitive_near->getMaterial()->getColor());
        totalColor = totalColor.add(reflectionColor);
    }
    return totalColor;
}
