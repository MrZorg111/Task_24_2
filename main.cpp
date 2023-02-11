#include <iostream>
#include <string>
#include <map>
#include <iomanip>

int main() {
    std::string name;
    std::time_t t = std::time(nullptr);
    std::tm local = *std::localtime(&t);
    std::tm present_time = *std::localtime(&t);

    ///Сбор данных.
    do {
        std::cout << "Enter a name:";
        std::cin >> name;
        if (name != "end") {
            std::cout << "Enter the year/month/day:";
            std::cin >> std::get_time(&local, "%Y/%m/%d");
            std::map<std::string, std::tm> happy_birthday;
            happy_birthday.insert(std::pair<std::string, std::tm> (name, local));

        }
    }while (name != "end");

    ///Обработка данных.

        return 0;
}
    /*std::map<std::string, std::tm> :: iterator it = happy_birthday.find(name);
            std::cout << it -> first << " \n";
            std::cout << std::put_time(&it -> second, "%Y/%m/%d");*/