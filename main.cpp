#include "string_algorithms/include/suffix_array.h"
#include <iostream>

int main() {
    namespace sa = string_algos;
    std::string text = "lexicography";
    std::vector<size_t> suffixArray = sa::build_suffix_array(text);

    std::cout << "Suffix Array for '" << text << "':\n";
    for (size_t i = 0; i < suffixArray.size(); ++i) {
        std::cout << suffixArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
