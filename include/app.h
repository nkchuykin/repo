#pragma once
#include "database.h"
#include <memory>

class App {
public:
    App();

    explicit App(IDatabase* ptr); //For tests

    void menu();
    void addNumber();
    void sumNumbers();
    void removeNumber();
    void findGreater();

private:
    std::unique_ptr<IDatabase> owned_db;
    IDatabase* db;
};
