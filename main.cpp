#include<iostream>

#include "CommandFactory.hpp"
#include "ImageFactory.hpp"
#include "ImageManager.h"
#include "PBMImage.h"
#include "PGMImage.h"
#include "PPMImage.h"

int main() {
    std::cout << "Welcome to ImageLab!\n";

    std::cout << "Available commands:\n";
    std::cout << "* load\n";

    ImageManager manager;
    bool running = true;
    std::string line;

    while (running) {
        std::cout << "> ";
        std::getline(std::cin, line);

        try {
            std::unique_ptr<ICommand> command =
                    CommandFactory::create(line, running);

            command->execute(manager);
        } catch (const std::exception &e) {
            std::cout << "Error: " << e.what() << '\n';
        }
    }

    return 0;
}