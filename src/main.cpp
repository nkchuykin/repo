#include "app.h"
#include <iostream>

int main() {
    App app;
    bool running = true;
    while (running) {
        app.menu();
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                app.addNumber();
                break;
            case 2:
                app.sumNumbers();
                break;
            case 3:
                app.removeNumber();
                break;
            case 4:
                app.findGreater();
                break;
            case 5:
                running = false;
                break;
            default:
                std::cout << "Incorrect input.\n";
        }
    }
    return 0;
}
