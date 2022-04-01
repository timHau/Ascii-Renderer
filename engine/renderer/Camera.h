#ifndef CAMERA_H
#define CAMERA_H

#include "../math_utils/Vector3.h"

class Camera
{

public:
    Camera(float aspect_ratio);

public:
    float focal_length;
    Vector3 origin;
    Vector3 horizontal;
    Vector3 vertical;
    Vector3 lower_left_corner;
};

#endif