#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

struct data_happy {
    std::string name = " ";
    int diff = 0;
};


int main() {
    std::vector<data_happy> d_h;
    std::string name;
    std::time_t happy_birthday = std::time(nullptr);
    std::tm local = *std::localtime(&happy_birthday);
    std::time_t present_time = std::time(nullptr);
    int i = -1;
    do {
    std::cout << "Enter your friend's name and date of birth:\n";
    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Date:";
    std::cin >> std::get_time(&local, "Y%/m%/d%");


    i++;
    d_h.resize(i);
    d_h.push_back(data_happy());
    d_h[i].name = name;
    d_h[i].diff = std::difftime(std::mktime(&local), present_time);

    }while (name != "end");

    for (int l = 0; l < d_h.size(); l++) {
        std::cout << d_h[l].name << " " << d_h[l].diff << "\n";
    }
        return 0;
}
