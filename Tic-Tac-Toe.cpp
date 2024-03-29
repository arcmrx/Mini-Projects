#include <iostream>
#include <vector>

void print_array(std::vector<std::vector<char>> Field)
{
    std::cout << "\x1B[2J\x1B[H";
    std::cout << "╔═════════════════╗\n";
    std::cout << "║ Крестики-нолики ║\n";
    std::cout << "╚╦═══╦═══╦═══╦═══╦╝\n";
    std::cout << " ║ 0 ║ 1 ║ 2 ║ 3 ║\n";
    std::cout << " ╠═══╬═══╬═══╬═══╣\n";
    std::cout << " ║ 1 ║ " << Field[0][0] << " ║ " << Field[0][1] << " ║ " << Field[0][2] << " ║\n";
    std::cout << " ╠═══╬═══╬═══╬═══╣\n";
    std::cout << " ║ 2 ║ " << Field[1][0] << " ║ " << Field[1][1] << " ║ " << Field[1][2] << " ║\n";
    std::cout << " ╠═══╬═══╬═══╬═══╣\n";
    std::cout << " ║ 3 ║ " << Field[2][0] << " ║ " << Field[2][1] << " ║ " << Field[2][2] << " ║\n";
    std::cout << " ╚═══╩═══╩═══╩═══╝\n";
}

bool isValidMove(int x, int y, std::vector<std::vector<char>> Field)
{
    if (x - 1 >= 0 && x - 1 <= 2 && y - 1 >= 0 && y - 1 <= 2 && Field[x - 1][y - 1] == '_')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void moveX(std::vector<std::vector<char>> &Field)
{
    std::cout << "Ход X! Введите координаты:\n";
    int x, y;
    while (!(std::cin >> x >> y) || !isValidMove(x, y, Field))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\x1B[2J\x1B[H";
        print_array(Field);
        std::cout << "\x1b[31mОшибка! Введите корректные координаты.\x1b[0m\n";
        std::cout << "Ход X! Введите координаты:\n";
    }

    Field[x - 1][y - 1] = 'X';
}

void moveO(std::vector<std::vector<char>> &Field)
{
    std::cout << "Ход 0! Введите координаты:\n";
    int x, y;
    while (!(std::cin >> x >> y) || !isValidMove(x, y, Field))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\x1B[2J\x1B[H";
        print_array(Field);
        std::cout << "\x1b[31mОшибка! Введите корректные координаты.\x1b[0m\n";
        std::cout << "Ход 0! Введите координаты:\n";
    }

    Field[x - 1][y - 1] = '0';
}

bool checkWin(std::vector<std::vector<char>> &Field)
{
    for (size_t i = 0; i < Field.size(); ++i)
    {
        if ((Field[i][0] == 'X' && Field[i][0] == Field[i][1] && Field[i][1] == Field[i][2]) ||
            (Field[0][i] == 'X' && Field[0][i] == Field[1][i] && Field[1][i] == Field[2][i]))
        {
            print_array(Field);
            std::cout << "\n\x1b[1;32m╔══════════════════╗\n║ Игрок X выиграл! ║\n╚══════════════════╝\n\x1b[0m\n";
            return false;
        }
        else if ((Field[i][0] == '0' && Field[i][0] == Field[i][1] && Field[i][1] == Field[i][2]) ||
                 (Field[0][i] == '0' && Field[0][i] == Field[1][i] && Field[1][i] == Field[2][i]))
        {
            print_array(Field);
            std::cout << "\n\x1b[1;32m╔══════════════════╗\n║ Игрок 0 выиграл! ║\n╚══════════════════╝\n\x1b[0m\n";
            return false;
        }
    }

    if ((Field[0][0] == 'X' && Field[1][1] == 'X' && Field[2][2] == 'X') ||
        (Field[2][0] == 'X' && Field[1][1] == 'X' && Field[0][2] == 'X'))
    {
        print_array(Field);
        std::cout << "\n\x1b[1;32m╔══════════════════╗\n║ Игрок X выиграл! ║\n╚══════════════════╝\n\x1b[0m\n";
        return false;
    }
    else if ((Field[0][0] == '0' && Field[1][1] == '0' && Field[2][2] == '0') ||
             (Field[2][0] == '0' && Field[1][1] == '0' && Field[0][2] == '0'))
    {
        print_array(Field);
        std::cout << "\n\x1b[1;32m╔══════════════════╗\n║ Игрок 0 выиграл! ║\n╚══════════════════╝\n\x1b[0m\n";
        return false;
    }

    bool isDraw = true;
    for (size_t i = 0; i < Field.size(); ++i)
    {
        for (size_t j = 0; j < Field[i].size(); ++j)
        {
            if (Field[i][j] == '_')
            {
                isDraw = false;
                break;
            }
        }
        if (!isDraw)
        {
            break;
        }
    }
    if (isDraw)
    {
        print_array(Field);
        std::cout << "\n\x1b[1;33m╔════════╗\n║ Ничья! ║\n╚════════╝\x1b[0m\n";
        return false;
    }

    return true;
}

int main()
{
    setlocale(LC_ALL, "");
    std::vector<std::vector<char>> Field(3, std::vector<char>(3));
    for (int i = 0; i != 3; i++)
    {
        for (int j = 0; j != 3; j++)
        {
            Field[i][j] = '_';
        }
    }

    print_array(Field);

    while (checkWin(Field))
    {
        moveX(Field);
        std::cout << "\x1B[2J\x1B[H";
        if (!checkWin(Field))
        {
            break;
        }
        print_array(Field);
        moveO(Field);
        std::cout << "\x1B[2J\x1B[H";
        if (!checkWin(Field))
        {
            break;
        }
        print_array(Field);
    }

    return 0;
}