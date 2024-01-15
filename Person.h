// 1

#include "includes.cpp"

class Person {
protected:
    std::string name;
    int age;

public:
    Person() = default;
    Person(const std::string &name, int age);

    std::string getName() const;
    int getAge() const;

    void setName(const std::string &name);
    void setAge(int age);

    virtual void print() const = 0;

    virtual ~Person() = default;
};