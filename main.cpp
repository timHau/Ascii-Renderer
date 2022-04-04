#include <iostream>
#include <termox/termox.hpp>
#include "src/Terminal.h"

int main() {
    return ox::System{}.run<Terminal>(ox::FPS{60});
}