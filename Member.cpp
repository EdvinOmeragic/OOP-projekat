#include "Member.h"

Member::Member(const std::string &name, int age, int id, const Date &registration, const Date &expiration, const Trainer &trainer) : Person(name, age), id(id), registration(registration), expiration(expiration), trainer(trainer) {}

int Member::getId() const {
    return id;
}

Date Member::getRegistration() const {
    return registration;
}

Date Member::getExpiration() const {
    return expiration;
}

Trainer Member::getTrainer() const {
    return trainer;
}

void Member::setId(int id) {
    this->id = id;
}

void Member::setRegistration(const Date &registration) {
    this->registration = registration;
}

void Member::setExpiration(const Date &expiration) {
    this->expiration = expiration;
}

void Member::setTrainer(const Trainer &trainer) {
    this->trainer = trainer;
}

void Member::print() const {
    std::cout << "Name: " << getName() << "\n";
    std::cout << "Age: " << getAge() << "\n";
    std::cout << "ID: " << getId() << "\n";
    std::cout << "Registration: " << getRegistration() << "\n";
    std::cout << "Expiration: " << getExpiration() << "\n";
    std::cout << "Trainer: " << getTrainer().getName() << "\n";
}

std::istream &operator>>(std::istream &in, Member &member) {
    std::string name;
    int age, id;
    Date registration, expiration;
    Trainer trainer;

    std::cout << "Enter name: ";
    in >> name;
    std::cout << "Enter age: ";
    in >> age;
    std::cout << "Enter ID: ";
    in >> id;
    std::cout << "Enter registration date (day month year): ";
    in >> registration;
    std::cout << "Enter expiration date (day month year): ";
    in >> expiration;
    std::cout << "Enter trainer details:\n";
    in >> trainer;

    member = Member(name, age, id, registration, expiration, trainer);

    return in;
}

// 8