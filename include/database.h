#pragma once
#include <vector>
#include <string>

class Database {
public:
    Database(const std::string& filename);
    ~Database();

    void add(int value);
    void removeAll(int value);
    std::vector<int> getAll() const;

private:
    std::vector<int> numbers;
    std::string filename;

    void load();
    void save() const;
};
