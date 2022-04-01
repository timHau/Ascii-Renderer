#ifndef HELLO_WIDGET_H
#define HELLO_WIDGET_H

#include <termox/termox.hpp>
#include "Renderer.h"

class Terminal : public ox::Widget
{
public:
    auto paint_event(ox::Painter &p) -> bool override
    {
        auto area = ox::Terminal::area();
        p.fill(Renderer::shot_ray(), ox::Point{0, 0}, area);
        return Widget::paint_event(p);
    }
};

#endif