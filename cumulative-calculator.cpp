#include <iostream>
#include <iomanip>

int main()
{
    setlocale(LC_ALL, "");
    std::cout << ("\e[1;1H\e[2J");

    long double pig, plus, mounth, proc, rpig, ch = 0;
    std::cout << "Введите сколько денег есть сейчас:\n";
    std::cin >> pig;
    std::cout << "Введите ежемесечное пополнение:\n";
    std::cin >> plus;
    std::cout << "Введите годовой процент:\n";
    std::cin >> proc;
    std::cout << "Введите кол-во месяцев:\n";
    std::cin >> mounth;
    while (mounth > 0)
    {
        pig += ((pig * 1.0) * ((proc * 0.01) / 12.0)) + (plus * 1.0);
        mounth--;
    }
    rpig = pig;
    while (round(rpig) != 0)
    {
        rpig /= 10;
        ch++;
    }
    std::cout << "Итого: " << std::setprecision(ch + 2) << ((pig * 100) / 100.0) << "\n";
}
