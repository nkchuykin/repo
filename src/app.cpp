#include "app.h"
#include "utils.h"
#include <iostream>

App::App() :
    db(std::make_unique<Database>("numbers.txt"))
{}

void App::menu() {
    std::cout << "\n====== Comands ======\n";
    std::cout << "1. Add number\n";
    std::cout << "2. Get sum of all numbers\n";
    std::cout << "3. Delete number\n";
    std::cout << "4. Output numbers greater than giveb\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose option: ";
}

void App::addNumber() {
    int n;
    std::cout << "Input number: ";
    std::cin >> n;
    db->add(n);
}

void App::sumNumbers() {
    auto nums = db->getAll();
    std::cout << "Sum = " << sum(nums) << "\n";
}

void App::removeNumber() {
    int n;
    std::cout << "Input number for deleting: ";
    std::cin >> n;
    db->removeAll(n);
}

void App::findGreater() {
    int n;
    std::cout << "Input number: ";
    std::cin >> n;

    auto nums = db->getAll();
    auto result = findGreaterThan(nums, n);

    std::cout << "Numbers greater " << n << ": ";
    for (int x : result) std::cout << x << " ";
    std::cout << "\n";
}
