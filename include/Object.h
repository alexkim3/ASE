#pragma once
#include "ngl/Vec3.h"
struct Object
{
public:
    ngl::Vec3 position;
    float size;
    int subdivision;


    Object() : position(0,0,0),
               size(1.f),
               subdivision(20)
    {;}

    ~Object() = default;
};
