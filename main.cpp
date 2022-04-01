#include <iostream>
#include <termox/termox.hpp>
#include "engine/renderer/Terminal.h"

int main() {
    return ox::System{}.run<Terminal>();
}