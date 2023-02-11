#include <iostream>
#include <string>
#include <map>
#include <iomanip>

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
    std::time_t sec_start = std::mktime(&local);
    int different = difftime(sec_start, std::mktime(&happy_birthday.begin() -> second));
    std::string min_diff_name = "";
    for (std::map<std::string, std::tm> :: iterator it = happy_birthday.begin(); it != happy_birthday.end(); it++) {
            std::time_t sec_hp = std::mktime(&it -> second);
            if (different < difftime(sec_start, sec_hp)) {
                min_diff_name += it -> first;
            }
    }
        return 0;
}
    /*std::map<std::string, std::tm> :: iterator it = happy_birthday.find(name);
            std::cout << it -> first << " \n";
            std::cout << std::put_time(&it -> second, "%Y/%m/%d");void diff_time (int& different, std::time_t a, std::time_t b) {
        different = difftime(a, b);
    }
     */