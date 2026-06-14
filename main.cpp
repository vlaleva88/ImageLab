#include<iostream>

#include "ImageFactory.hpp"
#include "PBMImage.h"
#include "PGMImage.h"
#include "PPMImage.h"

int main() {
    // try {
    //     auto image = ImageFactory::create("test.pgm");
    // }catch (const std::exception& e) {
    //     std::cout << e.what() << std::endl;
    // }

    String myString("banana.joe");
    std::cout << myString.endsWith(".oe");
    return 0;
}