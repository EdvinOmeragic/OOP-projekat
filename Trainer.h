#include "Person.cpp"

enum Specialization {
    fitness,
    bodybuilding,
    cardio,
    yoga,
    pilates,
    crossfit,
    kickboxing,
    calisthenics,
};

class Trainer {
private:
    std::string name;
    int age;
    Specialization specialization;

public:
    Trainer() = default;
    Trainer(const std::string &name, int age, const std::string &specializationStr);

    std::string getName() const;
    int getAge() const;
    Specialization getSpecialization() const;

    friend std::istream &operator>>(std::istream &in, Trainer &trainer);
    void print() const;

    static std::string specToString(Specialization specialization);
    static Specialization stringToSpec(const std::string &specializationStr);
};

// 3