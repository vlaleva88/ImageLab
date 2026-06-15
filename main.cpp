#include<iostream>

#include "CommandFactory.hpp"
#include "ImageFactory.hpp"
#include "ImageManager.h"
#include "PBMImage.h"
#include "PGMImage.h"
#include "PPMImage.h"

void allCommands() {
    std::cout << "* load <path>\n";
    std::cout << "* add-filter <image> <filter>\n";
    std::cout << "* remove-filter <image> <filter-index>\n";
    std::cout << "* show-filters <image>\n";
    std::cout << "* show-all-filters\n";
    std::cout << "* run <image>\n";
    std::cout << "* run-all\n";
    std::cout << "* save <image> [output-name]\n";
    std::cout << "* quit\n";
}

void allFilters() {
    std::cout << "* greyscale\n";
    std::cout << "* blur\n";
    std::cout << "* sobel\n";
    std::cout << "* threshold\n";
    std::cout << "* negative\n";
    std::cout << "* sharpen\n";
}

int main() {
    std::cout << "Welcome to ImageLab!\n\n";

    std::cout << "Introduction:\n";
    std::cout << "Available commands:\n";
    allCommands();
    std::cout << "================================\n";
    std::cout << "Available filters:\n";
    allFilters();

    std::cout << "\n";
    std::cout << "========= LET'S START =========\n";

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