#include "database.h"
#include <fstream>
#include <algorithm>

Database::Database(const std::string& file) : filename(file) {
    load();
}

Database::~Database() {
    save();
}

void Database::load() {
    std::ifstream in(filename);
    numbers.clear();

    int x;
    while (in >> x) {
        numbers.push_back(x);
    }
}

void Database::save() const {
    std::ofstream out(filename, std::ios::trunc);
    for (int x : numbers) {
        out << x << "\n";
    }
}

void Database::add(int value) {
    numbers.push_back(value);
}

void Database::removeAll(int value) {
    numbers.erase(
        std::remove(numbers.begin(), numbers.end(), value),
        numbers.end()
    );
}

std::vector<int> Database::getAll() const {
    return numbers;
}
