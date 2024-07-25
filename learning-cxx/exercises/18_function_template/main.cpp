#include <cmath> 
#include "../exercise.h"
template <typename T>
T plus(T a, T b) {
    return a + b;
}
int main(int argc, char **argv) {
    ASSERT(plus(1, 2) == 3, "Plus two int");
    ASSERT(plus(1u, 2u) == 3u, "Plus two unsigned int");
    ASSERT(plus(1.25f, 2.5f) == 3.75f, "Plus two float");
    ASSERT(plus(1.25, 2.5) == 3.75, "Plus two double");    
    double tolerance = 1e-9;
    ASSERT(std::abs(plus(0.1, 0.2) - 0.3) < tolerance, "Plus two double with tolerance");

    return 0;
}
