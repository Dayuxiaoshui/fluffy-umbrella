#include "../exercise.h"
#include <numeric>
#include <cstddef> // for std::size_t

int main(int argc, char **argv) {
    using DataType = float;
    int shape[]{1, 3, 224, 224};
    
    // Calculate the total number of elements in the tensor
    int num_elements = std::accumulate(std::begin(shape), std::end(shape), 1, std::multiplies<int>());
    
    // Calculate the total size in bytes
    int size = num_elements * sizeof(DataType);

    ASSERT(size == 602112, "4x1x3x224x224 = 602112");
    return 0;
}
