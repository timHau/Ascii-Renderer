#include <iostream>
#include <termox/termox.hpp>
#include "engine/Terminal.h"

int main() {
    return ox::System{}.run<Terminal>(ox::FPS{60});
}