#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include <vector>

bool check_date (std::tm a, std::tm b) {
    if (a.tm_mon < b.tm_mon) {
        return false;
    }
    if (a.tm_year <= b.tm_year && a.tm_mon <= b.tm_mon && a.tm_mday < b.tm_mday) {
        return false;
    }
    return true;
}

int main() {
    std::map<std::time_t, std::vector<std::string>> data_birthday;
    std::vector<std::string> name_happy;
    std::string name;
    std::time_t tempo;
    std::time_t happy= std::time(nullptr);
    std::tm happy_tm = *localtime(&happy);
    std::tm local = *localtime(&happy);
    std::cout << "Enter your friend's name and date of birth:";
    do {
    std::cout << "\nName ";
    std::cin >> name;

    if (name == "end") break;

    std::cout << "Date ";
    std::cin >> std::get_time(&local, "%Y/%m/%d");
    if (!check_date(local, happy_tm)) {
        std::cout << "Your friend's birthday has already passed!\n";
        continue;
    }
    local.tm_year = happy_tm.tm_year;
    tempo = std::mktime(&local);
    tempo = (std::time_t)std::difftime(tempo, happy);

    if(tempo < 0) {
        continue;
    }
    else {
        if (data_birthday.count(tempo)) {
            data_birthday.find(tempo)->second.push_back(name);
        } else {
            name_happy.clear();
            name_happy.push_back(name);
            data_birthday.insert(std::pair<double, std::vector<std::string>>(tempo, name_happy));
        }
    }
    } while(true);
    if (!data_birthday.empty()) {
        if (data_birthday.begin()->first == 0) {
            std::cout << "Don't forget to congratulate today: ";
            for (int i = 0; i < data_birthday.begin()->second.size(); i++) {
                std::cout << data_birthday.begin()->second[i] << " ";
            }

        } else {
            std::cout << "Upcoming birthdays for: ";
            for (int i = 0; i < data_birthday.begin()->second.size(); i++) {
                std::cout << data_birthday.begin()->second[i] << " ";
            }
            tempo = data_birthday.begin()->first + happy;
            std::tm t = *localtime(&tempo);
            std::cout << std::put_time(&t, "%m/%d");
        }
    }
    return 0;
}
