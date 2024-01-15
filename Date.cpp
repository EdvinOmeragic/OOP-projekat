#include "Date.h"

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

std::istream &operator>>(std::istream &in, Date &date) {
    int d, m, y;
    here:
    std::cout << "Enter month : "<< std::endl;
    in>>m;
    std::cout << "Enter day : "<< std::endl;
    in>>d;
    std::cout << "Enter year : "<< std::endl;
    in>>y;

    try{
        if(m == 2 && d > 28)
        {
            throw 101;
        }
        else if(m > 12){
            throw 100;
        }
        else if(d > 31)
        {
            throw 102;
        }
        else{
            date.month = m;
            date.day = d;
            date.year = y;
        }
    }

    catch(int e)
    {
        std::cout << "Caught error "<<e<<"! Please reenter month day year signature!"<<std::endl;
        goto here;
    }

    return in;
}

std::ostream &operator<<(std::ostream &out, const Date &date) {
    out << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
    return out;
}

// 6