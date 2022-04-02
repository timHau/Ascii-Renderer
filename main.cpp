#include <iostream>
#include <termox/termox.hpp>
#include "engine/Terminal.h"

int main() {
    Terminal terminal;
    return ox::System{}.run<Terminal>();
}