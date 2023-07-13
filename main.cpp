#include <iostream>
#include <fstream>
#include <cstdint>
#include "nbo.h"

int main(){
    std::ifstream f1("thousand.bin", std::ios::binary);
    std::ifstream f2("five-hundred.bin", std::ios::binary);

    if(!f1.is_open() || !f2.is_open()){
        std::cerr << "Failed\n";
        return -1;
    }

    uint8_t buf1[4];
    uint8_t buf2[4];

    f1.read(reinterpret_cast<char*>(buf1), 4);
    f2.read(reinterpret_cast<char*>(buf2), 4);

    uint32_t num1 = nbo_to_host(reinterpret_cast<uint32_t*>(buf1));
    uint32_t num2 = nbo_to_host(reinterpret_cast<uint32_t*>(buf2));
    uint32_t sum = num1 + num2;

    std::cout << num1 << "(0x" << std::hex << num1 << ") + " 
              << num2 << "(0x" << std::hex << num2 << ") = " 
              << sum << "(0x" << std::hex << sum << ")\n";

    return 0;
}

