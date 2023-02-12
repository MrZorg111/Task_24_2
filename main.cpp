#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

int diff_check (int& a, double b) {
    if (a > b) {
        return 1;
    }
    if (a < b) {
        return 2;
    }
    if (a == b) {
        return 3;
    }
}

int main() {
    std::string name;
    std::time_t t = std::time(nullptr);
    std::tm local = *std::localtime(&t);
   /// std::tm present_time = *std::localtime(&t);
    std::map<std::string, std::tm> happy_birthday;
    ///Сбор данных.
    do {
        std::cout << "Enter a name:";
        std::cin >> name;
        if (name != "end") {
            std::cout << "Enter the year/month/day:";
            std::cin >> std::get_time(&local, "%Y/%m/%d");
            happy_birthday.insert(std::pair<std::string, std::tm> (name, local));

        }
    }while (name != "end");

    ///Обработка данных.
    std::vector<std::string> name_birthdayboy;
    std::time_t sec_start = std::mktime(&local);
    int different = difftime(sec_start, std::mktime(&happy_birthday.begin() -> second));
    std::string min_diff_name = "";
    for (std::map<std::string, std::tm> :: iterator it = happy_birthday.begin()++; it != happy_birthday.end(); it++) {
            std::time_t sec_hp = std::mktime(&it -> second);
            switch (diff_check(different, std::difftime(sec_start, sec_hp))) {
                case 1: {
                    min_diff_name = it -> first;
                    different = std::difftime(sec_start, sec_hp);
                }
                case 2: {
                    name_birthdayboy.push_back(it -> first);
                }
            }
    }

    /// Вывод результата
        if (!name_birthdayboy.empty()) {
            std::cout << "Today is the birthday of: ";
            for (int i = 0; i < name_birthdayboy.size(); i++) {
                std::cout << name_birthdayboy[i] << " ";
            }
        }
        else {
            std::cout << "The nearest birthday to: " << min_diff_name;
        }
        return 0;
}
