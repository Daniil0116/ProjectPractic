#include <iostream>
#include <locale>
#include <string>
#include <windows.h>

void showMenu() {
    std::cout << "Выберите операцию:" << std::endl;
    std::cout << "1. Вставить (insert)" << std::endl;
    std::cout << "2. Удалить (erase)" << std::endl;
    std::cout << "3. Заменить (replace)" << std::endl;
    std::cout << "4. Найти (find)" << std::endl;
    std::cout << "0. Выход" << std::endl;
}


int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //1
    /*std::string userStr;
    std::cout << "Введите строку: ";
    std::getline(std::cin, userStr);
    std::cout << "front = " << userStr.front() << std::endl;
    std::cout << "back = " << userStr.back() << std::endl;*/
    
    //3
    /*std::string firstUserStr, secondUserStr;
    std::cout << "Введите первую строку: ";
    std::getline(std::cin, firstUserStr);
    std::cout << "Введите вторую строку: ";
    std::getline(std::cin, secondUserStr);
    int result = firstUserStr.compare(secondUserStr);
    if (result < 0) 
    {
        std::cout << "Первая строка меньше второй." << std::endl;
    }
    else if (result > 0) 
    {
        std::cout << "Первая строка больше второй." << std::endl;
    }
    else 
    {
        std::cout << "Строки равны." << std::endl;
    }*/


    //2
    std::string userStr;
    std::cout << "Введите исходную строку: ";
    std::getline(std::cin, userStr);

    int choice;
    do {
        showMenu();
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) 
        {
        case 1: 
        { // insert
            int position;
            std::string toInsert;
            std::cout << "Введите позицию для вставки: ";
            std::cin >> position;
            std::cin.ignore(); // игнорируем оставшийся символ новой строки
            std::cout << "Введите строку для вставки: ";
            std::getline(std::cin, toInsert);

            if (position < 0 || position > userStr.length()) 
            {
                std::cout << "Некорректная позиция." << std::endl;
            }
            else 
            {
                userStr.insert(position, toInsert);
                std::cout << "Результат вставки: " << userStr << std::endl;
            }
            break;
        }
        case 2: 
        { // erase
            int position, length;
            std::cout << "Введите позицию для удаления: ";
            std::cin >> position;
            std::cout << "Введите длину удаляемой части: ";
            std::cin >> length;

            if (position < 0 || position >= userStr.length() || length < 0 || position + length > userStr.length()) 
            {
                std::cout << "Некорректные параметры." << std::endl;
            }
            else 
            {
                userStr.erase(position, length);
                std::cout << "Результат удаления: " << userStr << std::endl;
            }
            break;
        }
        case 3: 
        { // replace
            int position;
            std::string toReplace;
            std::cout << "Введите позицию для замены: ";
            std::cin >> position;
            std::cin.ignore();
            std::cout << "Введите новую строку: ";
            std::getline(std::cin, toReplace);

            if (position < 0 || position >= userStr.length()) 
            {
                std::cout << "Некорректная позиция." << std::endl;
            }
            else 
            {
                userStr.replace(position, toReplace.length(), toReplace);
                std::cout << "Результат замены: " << userStr << std::endl;
            }
            break;
        }
        case 4: 
        { // find
            std::string toFind;
            std::cout << "Введите строку для поиска: ";
            std::cin.ignore(); // игнорируем оставшийся символ новой строки
            std::getline(std::cin, toFind);

            size_t found = userStr.find(toFind);
            if (found != std::string::npos) 
            {
                std::cout << "Строка найдена на позиции: " << found << std::endl;
            }
            else 
            {
                std::cout << "Строка не найдена." << std::endl;
            }
            break;
        }
        case 0:
            std::cout << "Выход..." << std::endl;
            break;
        default:
            std::cout << "Некорректный выбор. Попробуйте снова." << std::endl;
        }
    } while (choice != 0);


    return 0;
}

