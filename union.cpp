#include "union.h"

Union::Union()
{

}

void Union::push(CObject *object)
{
    CVector.push_back(object);
}

Color Union::rayTrace(CRay ray, int depth, CObject* &_object,IntersectResult*& res)
{
    if(depth>max_depth)  return Color::white();
    int size = (int)CVector.size();
    float distance = 100000000.0f;
    CObject* primitive_near = NULL;
    bool visible = true;
    Color totalColor = Color::black();
    CObject* pLight;
    int num=0;
    IntersectResult s = IntersectResult::noHit();
    for(int i=0;i<size;i++){
        CObject* primitive = CVector.at(i);
        IntersectResult result = primitive->isIntersected(ray);
        if(result.isHit){
            if(result.distance < distance){
                s = result;
                distance = result.distance;
                primitive_near = result.object;
                num = i;
            }
        }
    }
    _object = primitive_near;
    res = &s;
    if(primitive_near == NULL) {

        return Color::black();
    }
    else if(primitive_near->isLight()){

        return Color::white();
    }
    else if(!s.front){
        cout<<depth<<" "<<s.object->code<<endl;
        GVector3 v = ray.getDirection();
        v = v.normalize();
        GVector3 normal = s.normal.normalize();
        double cosA = v.dotMul(normal);
        double sinA = sqrt(1-cosA*cosA);
        double n = 1.000 / 1.500;
        //cout<<sinA<<endl;
        if(sinA >= n){
            //cout<<"zhixingle"<<endl;
            CRay newray;
            newray.setDirection(normal*(-cosA) + (ray.getDirection() - normal*cosA).normalize()*sinA);
            newray.setOrigin(s.position + ray.getDirection()*1e-3);
            CObject* no_use = NULL;
            IntersectResult* n0=NULL;
            Color refraction_second = rayTrace(newray,depth+1,no_use,n0);
            //cout<<refraction_second.r<<" "<<refraction_second.g<<" "<<refraction_second.b<<endl;
            Color absorbance(0,0,0);
            if(n0){
                Color absorbance = primitive_near->getMaterial()->getColor().multiply(0.15f * ((-1)*n0->distance));
            }
            Color transparancy = Color(exp(absorbance.r),exp(absorbance.g),exp(absorbance.b));
            return refraction_second.moderate(transparancy);
        }
        else{

            double sinB = sinA / n;

            double cosB = sqrt(1 - sinB*sinB);

            CRay newray;
            newray.setDirection(normal*cosB + (v-normal*cosA).normalize()*sinB);
            newray.setOrigin(s.position + newray.getDirection()*1e-3);
            //cout<<"Origin:"<<newray.getOrigin().getX()<<" "<<newray.getOrigin().getY()<<" "<<newray.getOrigin().getZ()<<endl;
            //cout<<"Direction:"<<newray.getDirection().getX()<<" "<<newray.getDirection().getY()<<" "<<newray.getDirection().getZ()<<endl;
            CObject* no_use = NULL;
            IntersectResult* n0=NULL;
            Color refraction_second = rayTrace(newray,depth+1,no_use,n0);
            //cout<<refraction_second.r<<" "<<refraction_second.g<<" "<<refraction_second.b<<endl;
            Color absorbance(0,0,0);
            if(n0){
                Color absorbance = primitive_near->getMaterial()->getColor().multiply(0.15f * ((-1)*n0->distance));
            }
            Color transparancy = Color(exp(absorbance.r),exp(absorbance.g),exp(absorbance.b));
            return refraction_second.moderate(transparancy);
        }
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
        newRay.setOrigin(point + newRay.getDirection()*1e-3);
        CObject* no_use = NULL;
        IntersectResult* n0=NULL;
        Color reflectionColor = rayTrace(newRay,depth+1,no_use,n0);
        reflectionColor = reflectionColor.multiply(reflection);
        //reflectionColor = reflectionColor.moderate(primitive_near->getMaterial()->getColor());
        totalColor = totalColor.add(reflectionColor.moderate(primitive_near->getMaterial()->getColor()));
    }
    float refraction = primitive_near->getMaterial()->getRefr();
    //cout<<refraction<<endl;
    if((refraction>0.0f) && (depth<max_depth)){

        GVector3 normal_point = primitive_near->getNormal(point);
        GVector3 Direction = ray.getDirection().normalize();
        normal_point = normal_point.normalize();
        float cosA = -Direction.dotMul(normal_point);
        float sinA = sqrt(1-cosA*cosA);
        float sinB = sinA / 1.5;
        float cosB = sqrt(1 - sinB*sinB);
        //cout<<sinA<<" "<<cosA<<" "<<sinB<<" "<<cosB<<endl;
        CRay newray;
        newray.setDirection(normal_point*(-cosB) + (Direction + normal_point*cosA).normalize()*sinB);
        newray.setOrigin(point + newray.getDirection() * 1e-3);
        CObject* no_use = NULL;
        IntersectResult* n0=NULL;
        Color refractionColor = rayTrace(newray,depth+1,no_use,n0);
        refractionColor = refractionColor.multiply(refraction);
        //refractionColor = refractionColor.moderate(primitive_near->getMaterial()->getColor());
        totalColor = totalColor.add(refractionColor);
    }
    return totalColor;
}
