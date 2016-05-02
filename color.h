#ifndef COLOR_H
#define COLOR_H


class Color
{
public:
    float r,g,b;
    Color();
    Color(float _r,float _g,float _b);
    Color add(Color s);
    Color multiply(float s);
    Color moderate(Color r);
    void saturate();
    virtual ~Color();
    static inline Color black(){return Color(0.0,0.0,0.0);}
    static inline Color white(){ return Color(1.0,1.0,1.0); }
    static inline Color red()  { return Color(0.0,0.0,1.0); }
    static inline Color green(){ return Color(0.0,1.0,0.0); }
    static inline Color blue() { return Color(1.0,0.0,0.0); }
    static inline Color yellow(){ return Color(1.0,1.0,0.0); }
};

#endif // COLOR_H
