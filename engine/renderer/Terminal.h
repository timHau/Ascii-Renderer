#ifndef HELLO_WIDGET_H
#define HELLO_WIDGET_H

#include <termox/termox.hpp>
#include "Renderer.h"
#include "Camera.h"
#include "../math_utils/Ray.h"
#include <iostream>

class Terminal : public ox::Widget
{
public:
    auto paint_event(ox::Painter &p) -> bool override
    {
        auto area = ox::Terminal::area();

        auto camera = Camera(area.width / area.height);

        for (int i = 0; i < area.width; i++)
        {
            for (int j = 0; j < area.height; j++)
            {
                float u = float(i) / (float(area.width) - 1.0);
                float v = float(j) / (float(area.height) - 1.0);

                Ray r(camera.origin, camera.lower_left_corner + camera.horizontal * u + camera.vertical * v - camera.origin);
                auto c = r.color();

                p.put(c, ox::Point{i, j});
            }
        }

        return Widget::paint_event(p);
    }
};

#endif