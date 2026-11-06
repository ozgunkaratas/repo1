#include <iostream>
#include "repo1/temperature.hpp"

int main() {
    using namespace repo1;
    for (CentiCelsius t : {150, 512, 905, -5}) {
        std::cout << format(t) << " -> " << to_string(classify(t, 200, 800)) << '\n';
    }
}