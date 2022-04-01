#include "Camera.h"

Camera::Camera(float aspect_ratio) 
{
    focal_length = 1.0f;

    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;

    origin = Vector3(0.0f, 0.0f, 0.0f);
    horizontal = Vector3(viewport_width, 0.0f, 0.0f);
    vertical = Vector3(0.0f, viewport_height, 0.0f);
    lower_left_corner = origin - horizontal / 2.0f - vertical / 2.0f - Vector3(0.0f, 0.0f, focal_length);
}