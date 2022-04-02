#ifndef HELLO_WIDGET_H
#define HELLO_WIDGET_H

#include <termox/termox.hpp>
#include "Ray.h"

class Terminal : public ox::Widget
{
public:
    auto paint_event(ox::Painter &p) -> bool override
    {
        auto area = ox::Terminal::area();

        auto ray_origin = Vec3(0.0f, 1.0f, 0.0f);
        for (int i = 0; i < area.width; i++)
        {
            for (int j = 0; j < area.height; j++)
            {
                float u = (float(i) - 0.5 * float(area.width)) / (float(area.width) - 1.0);
                float v = (float(j) - 0.5 * float(area.height)) / (float(area.height) - 1.0);
                Vec3 ray_direction = Vec3(u, -v, 1.0f).normalize();
                Ray ray(ray_origin, ray_direction);
                auto c = ray.color();
                p.put(c, ox::Point{i, j});
            }
        }

        return Widget::paint_event(p);
    }
};

#endif