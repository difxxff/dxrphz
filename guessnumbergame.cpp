#include <iostream>
#include <cstdlib> 
#include <ctime>  


void guessNumberGame() {

    std::srand(static_cast<unsigned int>(std::time(0)));

    const int secretNumber = std::rand() % 101;

    int guess = -1; 

    
    std::cout << "Угадай число от 0 до 100!\n";

    
    do {
        
        std::cout << "Твоя попытка: ";
        
        if (!(std::cin >> guess)) {
            std::cout << "Некорректный ввод! Пожалуйста, введи число.\n";
            std::cin.clear(); 
            std::cin.ignore(10000, '\n'); 
            continue; 
        }

        
        if (guess < secretNumber) {
            std::cout << guess << "\nНадо больше\n";
        }
        else if (guess > secretNumber) {
            std::cout << guess << "\nНадо меньше\n";
        }

    } while (guess != secretNumber);

    
    std::cout << guess << "\nУгадал!\n";
}


int main() {
    int choice;

    do {
        std::cout << "\n=== Меню программы ===\n";
        std::cout << "1. Начать игру \"Угадай число\"\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите опцию: ";

        if (!(std::cin >> choice)) {
         
            std::cout << "Некорректный ввод. Введите 1 или 0.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            choice = -1; 
            continue;
        }

        switch (choice) {
        case 1:
            guessNumberGame();
            break;
        case 0:
            std::cout << "Спасибо за игру! До свидания.\n";
            break;
        default:
            std::cout << "Неизвестная опция. Попробуйте еще раз.\n";
            break;
        }

    } while (choice != 0);

    return 0;
}