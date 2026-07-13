#pragma once
#include <memory>
#include <sstream>

#include "../Commands/AddFilterCommand.h"
#include "FilterFactory.hpp"
#include "../Commands/ICommand.h"
#include "ImageManager.h"
#include "../Commands/LoadCommand.h"
#include "../Commands/QuitCommand.h"
#include "../Commands/RemoveFilterCommand.h"
#include "../Commands/RunAllCommand.h"
#include "../Commands/RunCommand.h"
#include "../Commands/SaveCommand.h"
#include "../Commands/ShowAllFiltersCommand.h"
#include "../Commands/ShowFiltersCommand.h"

class CommandFactory {
public:
    static std::unique_ptr<ICommand> create(const std::string& args, bool& running) {
        std::stringstream ss(args);
        std::string command;
        ss >> command;

        if (command == "load") {
            std::string filename;
            ss >> filename;
            return std::make_unique<LoadCommand>(filename.data());
        }
        if (command == "add-filter") {
            size_t imageIndex;
            std::string filterName;
            ss >> imageIndex >> filterName;

            auto filter = FilterFactory::create(filterName.data());
            return std::make_unique<AddFilterCommand>(imageIndex,std::move(filter));
        }
        if (command == "remove-filter") {
            size_t imageIndex;
            size_t filterIndex;
            ss >> imageIndex >> filterIndex;
            return std::make_unique<RemoveFilterCommand>(imageIndex,std::move(filterIndex));
        }
        if (command == "show-filters") {
            size_t imageIndex;
            ss >> imageIndex;
            return std::make_unique<ShowFiltersCommand>(imageIndex);
        }
        if (command == "show-all-filters") {
            return std::make_unique<ShowAllFiltersCommand>();
        }
        if (command == "run") {
            size_t imageIndex;
            ss >> imageIndex;
            return std::make_unique<RunCommand>(imageIndex);
        }
        if (command == "run-all") {
            return std::make_unique<RunAllCommand>();
        }
        if (command == "save") {
            size_t imageIndex;
            std::string outputName;
            ss >> imageIndex;
            if (ss >> outputName) {
                return std::make_unique<SaveCommand>(imageIndex,outputName.data());
            }
            return std::make_unique<SaveCommand>(imageIndex);
        }
        if (command == "quit") {
            return std::make_unique<QuitCommand>(running);
        }
        throw std::runtime_error("Unknown command");

    }
};
