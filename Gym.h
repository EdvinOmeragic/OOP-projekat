#include "Member.cpp"

class GymDatabase {
private:
    std::vector<Member> members;
    std::vector<Trainer> trainers;

public:
    void addMember();
    void addTrainer();
    void displayMembers() const;
    void displayTrainers() const;
    void saveToFile() const;
    void loadFromFile();
    void mainMenu();
};

// 9