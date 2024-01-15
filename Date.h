#include "Trainer.cpp"

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() = default;
    Date(int day, int month, int year);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    friend std::istream &operator>>(std::istream &in, Date &date);
    friend std::ostream &operator<<(std::ostream &out, const Date &date);
};

// 5