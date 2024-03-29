#include <iostream>
#include <chrono>
#include <string>
#include <ctime>
#include <thread>

void calculateAge(int birthYear, int birthMonth, int birthDay)
{
    std::chrono::system_clock::time_point today = std::chrono::system_clock::now();
    time_t tt = std::chrono::system_clock::to_time_t(today);
    tm utc_tm = *gmtime(&tt);
    tm birth_tm = {0};
    birth_tm.tm_year = birthYear - 1900;
    birth_tm.tm_mon = birthMonth - 1;
    birth_tm.tm_mday = birthDay;
    time_t birthTime = mktime(&birth_tm);
    time_t currentTime = mktime(&utc_tm);
    double difference = difftime(currentTime, birthTime);
    tm age_tm = {0};
    age_tm.tm_year = (int)(difference / (365.25 * 24 * 3600));
    age_tm.tm_mon = (int)((difference / (30.44 * 24 * 3600))) % 12;
    age_tm.tm_mday = (int)((difference / (24 * 3600))) % 30;
    age_tm.tm_hour = (int)((difference / 3600)) % 24;
    age_tm.tm_min = (int)((difference / 60)) % 60;
    age_tm.tm_sec = (int)difference % 60;
    std::cout << "Your age is: " << age_tm.tm_year << " years, " << age_tm.tm_mon << " months, "
              << age_tm.tm_mday << " days, " << age_tm.tm_hour << " hours, " << age_tm.tm_min << " minutes, "
              << age_tm.tm_sec << " seconds.\n";
}

int main()
{
    int birthYear, birthMonth, birthDay;
    std::string date;
    std::cout << "Enter your birthday date(dd.mm.yyyy):\n";
    std::getline(std::cin, date);
    birthDay = stoi(date.substr(0, 2));
    birthMonth = stoi(date.substr(3, 5));
    birthYear = stoi(date.substr(6, 10));
    while (true)
    {
        std::cout << "\x1B[2J\x1B[H";
        calculateAge(birthYear, birthMonth, birthDay);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}