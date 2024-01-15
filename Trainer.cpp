#include "Trainer.h"

Trainer::Trainer(const std::string &name, int age, const std::string &specializationStr)
    : name(name), age(age), specialization(stringToSpec(specializationStr)) {}

std::string Trainer::getName() const {
    return name;
}

int Trainer::getAge() const {
    return age;
}

Specialization Trainer::getSpecialization() const {
    return specialization;
}

std::istream &operator>>(std::istream &in, Trainer &trainer) {
    in >> trainer.name >> trainer.age;
    std::string specializationStr;
    in >> specializationStr;
    trainer.specialization = Trainer::stringToSpec(specializationStr);
    return in;
}

void Trainer::print() const {
    std::cout << "Name: " << getName() << "\n";
    std::cout << "Age: " << getAge() << "\n";
    std::cout << "Specialization: " << specToString(getSpecialization()) << "\n";
}

std::string Trainer::specToString(Specialization specialization) {
    switch (specialization) {
    case fitness:
        return "Fitness";
    case bodybuilding:
        return "Bodybuilding";
    case cardio:
        return "Cardio";
    case yoga:
        return "Yoga";
    case pilates:
        return "Pilates";
    case crossfit:
        return "Crossfit";
    case kickboxing:
        return "Kickboxing";
    case calisthenics:
        return "Calisthenics";
    default:
        return "Invalid specialization";
    }
}

Specialization Trainer::stringToSpec(const std::string &specializationStr) {
    if (specializationStr == "Fitness") {
        return fitness;
    } else if (specializationStr == "Bodybuilding") {
        return bodybuilding;
    } else if (specializationStr == "Cardio") {
        return cardio;
    } else if (specializationStr == "Yoga") {
        return yoga;
    } else if (specializationStr == "Pilates") {
        return pilates;
    } else if (specializationStr == "Crossfit") {
        return crossfit;
    } else if (specializationStr == "Kickboxing") {
        return kickboxing;
    } else if (specializationStr == "Calisthenics") {
        return calisthenics;
    } else {
        return static_cast<Specialization>(-1); // Invalid specialization
    }
}

// 4