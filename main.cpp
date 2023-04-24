#include <iostream>
#include <filesystem>

#include "stockprices.h"

int main(int argc, char* argv[]) {
    if(argc <= 1){
        std::cout << "not enough arguments: path to file must be given" << '\n';
        return 1;
    }
    double asz = sizeof(argv) / sizeof(*argv);
    if(asz > 1){
        std::cout << "too many arguments given" << '\n';
        return 1;
    }
    bool exists = std::filesystem::exists(argv[1]);
    if(!exists){
        std::cout << "the file " << argv[1] << " does not exist" << '\n';
        return 1;
    }
    calculate_prices(argv[1]);
    return 0;
}