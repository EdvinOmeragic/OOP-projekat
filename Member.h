#include "Date.cpp"

class Member : public Person {
private:
    int id;
    Date registration;
    Date expiration;
    Trainer trainer;

public:
    Member() = default;
    Member(const std::string &name, int age, int id, const Date &registration,
           const Date &expiration, const Trainer &trainer);

    int getId() const;
    Date getRegistration() const;
    Date getExpiration() const;
    Trainer getTrainer() const;

    virtual void setId(int id);
    void setRegistration(const Date &registration);
    void setExpiration(const Date &expiration);
    void setTrainer(const Trainer &trainer);

    void print() const override;

    void extend();

    friend std::istream &operator>>(std::istream &in, Member &member);
};

// 7