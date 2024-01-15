#include "Gym.h"

void GymDatabase::addMember() {
    Member member;
    std::cin >> member;
    members.push_back(member);
    std::cout << "Member added successfully!\n";
}

void GymDatabase::addTrainer() {
    unique_ptr<Trainer> trainer = make_unique <Trainer>();
    std::cin >> *trainer;
    trainers.push_back(trainer);
    std::cout << "Trainer added successfully!\n";
}

void GymDatabase::displayMembers() const {
    std::cout << "Member Overview:\n";
    for (const Member &member : members) {
        member.print();
        std::cout << "\n";
    }
}

void GymDatabase::displayTrainers() const {
    std::cout << "Trainer Overview:\n";
    for (const Trainer &trainer : trainers) {
        trainer.print();
        std::cout << "\n";
    }
}

void GymDatabase::saveToFile() const {
    std::ofstream file("gym_data.txt");
    if (file.is_open()) {
        for (const Member &member : members) {
            file << "Member " << member.getName() << " " << member.getAge() << " "
                 << member.getId() << " " << member.getRegistration() << " "
                 << member.getExpiration() << " " << member.getTrainer().getName() << "\n";
        }
        for (const Trainer &trainer : trainers) {
            file << "Trainer " << trainer.getName() << " " << trainer.getAge() << " "
                 << Trainer::specToString(trainer.getSpecialization()) << "\n";
        }
        std::cout << "Data saved to gym_data.txt\n";
        file.close();
    } else {
        std::cerr << "Unable to open file for writing.\n";
    }
}

void GymDatabase::loadFromFile() {
    members.clear();
    trainers.clear();

    std::ifstream file("gym_data.txt");
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string type;
            iss >> type;

            if (type == "Member") {
                std::string name;
                int age, id;
                Date registration, expiration;
                Trainer trainer;

                iss >> name >> age >> id >> registration >> expiration >> trainer;

                Member member(name, age, id, registration, expiration, trainer);
                members.push_back(member);
            } else if (type == "Trainer") {
                std::string name;
                int age;
                std::string specializationStr;

                iss >> name >> age >> specializationStr;

                Trainer trainer(name, age, specializationStr);
                trainers.push_back(trainer);
            }
        }

        file.close();
        std::cout << "Data loaded from gym_data.txt\n";
    } else {
        std::cerr << "Unable to open file for reading. Creating a new file.\n";
    }
}

void GymDatabase::mainMenu() {
    int choice;
    do {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Add Member\n";
        std::cout << "2. Display Members\n";
        std::cout << "3. Add Trainer\n";
        std::cout << "4. Display Trainers\n";
        std::cout << "5. Save to File\n";
        std::cout << "6. Load from File\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addMember();
                break;
            case 2:
                displayMembers();
                break;
            case 3:
                addTrainer();
                break;
            case 4:
                displayTrainers();
                break;
            case 5:
                saveToFile();
                break;
            case 6:
                loadFromFile();
                break;
            case 0:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

// 10