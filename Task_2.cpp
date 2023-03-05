#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include <vector>


int main() {
    std::map<std::time_t, std::vector<std::string>> data_birthday;
    std::vector<std::string> name_happy;
    std::string name;
    std::time_t tempo;
    std::time_t happy= std::time(nullptr);
    std::tm local = *localtime(&happy);
    std::cout << "Enter your friend's name and date of birth:";
    do {
    std::cout << "\nName ";
    std::cin >> name;

    if (name == "end") break;

    std::cout << "Date ";
    std::cin >> std::get_time(&local, "%Y/%m/%d");
    tempo = std::mktime(&local);
    tempo = tempo - happy;
    if(tempo < 0) {
        continue;
    }
    else {
        if (data_birthday.count(tempo)) {
            data_birthday.find(tempo)->second.push_back(name);
        } else {
            name_happy.clear();
            name_happy.push_back(name);
            data_birthday.insert(std::pair<std::time_t, std::vector<std::string>>(tempo, name_happy));
        }
    }
    } while(true);

    if (data_birthday.begin() -> first == 0) {
        std::cout << "Don't forget to congratulate today: ";
        for (int i = 0; i < data_birthday.begin() -> second.size(); i++) {
            std::cout << data_birthday.begin() -> second[i] << " ";
        }

    }
    else {
        std::cout << "Upcoming birthdays for: ";
        for (int i = 0; i < data_birthday.begin() -> second.size(); i++) {
            std::cout << data_birthday.begin() -> second[i] << " ";
        }
    }
    return 0;
}
