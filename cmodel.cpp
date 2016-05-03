#include "cmodel.h"

CModel::CModel()
{

}

CModel::CModel(char *objfile)
{
    filename = objfile;
}

void CModel::load()
{
    cout<<"调用了load函数"<<endl;
    ifstream fin;
    fin.open("./dragon.txt");
    if(fin) cout<<"if(fin)"<<endl;
    if(fin.is_open()) cout<<"fin.is_open()"<<endl;
    vector<GVector3> points;
    string buf;
    number = 0;
    points.clear();
    int i,num_1,num_2,num_3;
    char ks1[30];char ks2[30];char ks3[30];
    float x,y,z;
    int index1,index2,index3;
    while(getline(fin,buf)){
        switch(buf[0]){
        case '#' : break;
        case 'v' :
            i = 2;num_1=0,num_2=0,num_3=0;
            while(buf[i]!=' '){
                ks1[num_1++] = buf[i++];
            }
            ks1[num_1]='\0';i+=1;
            while(buf[i]!=' '){
                ks2[num_2++] = buf[i++];
            }
            ks2[num_2] = '\0';i+=1;
            while(buf[i]!='\0'){
                ks3[num_3++] = buf[i++];
            }
            ks3[num_3] = '\0';
            x = atof(ks1);y = atof(ks2);z = atof(ks3);
            cout<<x<<" "<<y<<" "<<z<<endl;
            points.push_back(GVector3(x,y,z));
            break;
        case 'f':
            i = 2;num_1=0,num_2=0,num_3=0;
            while(buf[i]!=' '){
                ks1[num_1++] = buf[i++];
            }
            ks1[num_1]='\0';i+=1;
            while(buf[i]!=' '){
                ks2[num_2++] = buf[i++];
            }
            ks2[num_2] = '\0';i+=1;
            while(buf[i]!='\0'){
                ks3[num_3++] = buf[i++];
            }
            ks3[num_3] = '\0';
            index1 = atoi(ks1);
            index2 = atoi(ks2);
            index3 = atoi(ks3);
            cout<<index1<<" "<<index2<<" "<<index3<<endl;
            triangles.push_back(CTriangle(points.at(index1),points.at(index2),points.at(index3)));
            number++;
            break;
        default:
            break;
        }
    }
}

IntersectResult CModel::isIntersected(CRay ray)
{
    IntersectResult result = IntersectResult::noHit();float distance = 10000.00f;
    for(int i=0;i<triangles.size();i++){
        CTriangle c = triangles.at(i);
        IntersectResult temp_result = c.isIntersected(ray);
        if(temp_result.isHit == 0) continue;
        else{
            if(temp_result.distance < distance){
                distance = temp_result.distance;
                result = temp_result;index=i;
            }
        }
    }
    if(result.isHit != 0){
        result.object = this;
    }
    return result;
}

CModel::~CModel()
{

}

bool CModel::isLight()
{
    return false;
}

Material *CModel::getMaterial()
{
    return material;
}

GVector3 CModel::getNormal(GVector3 point)
{
    CTriangle triangle = triangles.at(index);
    return triangle.getNormal(point);
}

void CModel::setMaterial(Material* material)
{
    this->material = material;
}
