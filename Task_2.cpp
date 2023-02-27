#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

struct data_happy {
    std::string name = " ";
    double diff = 0;
};


int main() {
    std::vector<data_happy> d_h  ;
    std::string name;
    std::time_t happy_birthday = std::time(nullptr);
    std::tm* local = std::localtime(&happy_birthday);
    std::time_t present_time = std::time(nullptr);

    std::cout << "Enter your friend's name and date of birth:\n";
    std::cout << "Name: ";
    std::cin >> name;
    for( int i = 0; name != "end"; i++) {
        d_h.resize(i);
        d_h.push_back(data_happy());

        std::cout << "Date: ";
        std::cin >> std::get_time(local, "%Y/%m/%d");

        d_h[i].name = name;
        d_h[i].diff = std::difftime(std::mktime(local), present_time);

        std::cout << "Enter your friend's name and date of birth:\n";
        std::cin >> name;
    }

    for (int l = 0; l < d_h.size(); l++) {
        std::cout << d_h[l].name << " " << d_h[l].diff << "\n";

    }

    return 0;
}
///ESSSOLVENT