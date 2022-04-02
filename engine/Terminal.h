#ifndef HELLO_WIDGET_H
#define HELLO_WIDGET_H

#include <termox/termox.hpp>
#include "Ray.h"

class Terminal : public ox::Widget
{
public:
    explicit Terminal(ox::FPS fps) : fps_{fps}
    {
        *this | ox::pipe::strong_focus();
    }

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
                auto c = ray.color(time_);
                p.put(c, ox::Point{i, j});
            }
        }

        return Widget::paint_event(p);
    }

protected:
    auto timer_event() -> bool override
    {
        time_ += 1.0;
        this->update();
        return Widget::timer_event();
    }

    auto enable_event() -> bool override
    {
        this->enable_animation(fps_);
        return Widget::enable_event();
    }

    auto disable_event() -> bool override
    {
        this->disable_animation();
        return Widget::disable_event();
    }

private:
    ox::FPS fps_;
    float time_ = 0;

};

#endif