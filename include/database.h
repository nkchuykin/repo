#pragma once
#include <vector>
#include <string>

class IDatabase {
public:
    virtual ~IDatabase() = default;

    virtual void add(int value) = 0;
    virtual void removeAll(int value) = 0;
    virtual std::vector<int> getAll() const = 0;
};

class Database : public IDatabase {
public:
    Database(const std::string& filename);
    ~Database();

    void add(int value) override;
    void removeAll(int value) override;
    std::vector<int> getAll() const override;

private:
    std::vector<int> numbers;
    std::string filename;

    void load();
    void save() const;
};
