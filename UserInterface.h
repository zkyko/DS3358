#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <string>

class UserInterface {
public:
    // Displays a message to the terminal.
    void displayMessage(const std::string& message);

    // Retrieves user input from the terminal.
    std::string getUserInput();
};

#endif // USERINTERFACE_H
