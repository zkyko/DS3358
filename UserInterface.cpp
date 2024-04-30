#include "UserInterface.h"
#include <iostream>

void UserInterface::displayMessage(const std::string& message) {
    std::cout << message << std::endl;
}

std::string UserInterface::getUserInput() {
    std::cout << "> ";
    std::string input;
    std::getline(std::cin, input);
    return input;
}
