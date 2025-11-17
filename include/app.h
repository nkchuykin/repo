#pragma once
#include "database.h"
#include <memory>

class App {
public:
    App();

    void menu();
    void addNumber();
    void sumNumbers();
    void removeNumber();
    void findGreater();

private:
    std::unique_ptr<Database> db;
};
