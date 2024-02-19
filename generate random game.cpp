#include <iostream>
#include <cstdlib>
#include <ctime>

int game(int x)
{
    int guess;
    std::srand(std::time(nullptr));
    double random = std::rand() % x + 1;
    if (x == 100)
    {
        std::cout << "Guess the number between 1-100!" << std::endl;
        std::cout << "You've got 10 chances.." << std::endl;
        int count = 0;
        int maxcount = 10;

        while (count < maxcount)
        {
            std::cout << "Chance " << count + 1 << " :";
            std::cin >> guess;

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "please enter a valid choice" << std::endl;
                continue;
            }
            if (guess == random)
            {
                std::cout << "Congratulation! you won.." << std::endl;
                break;
            }
            else if (guess > random)
            {
                std::cout << "Your guess is too high!" << std::endl;
            }
            else
            {
                std::cout << "Your guess is too low!" << std::endl;
            }

            count++;
        }
        if (count == maxcount)
        {
            std::cout << "Your chances are over! Better luck next time.." << std::endl;
            std::cout << "The correct number is " << random << std::endl;
        }
    }
    else
    {
        std::cout << "Guess the number between 1-10!" << std::endl;
        std::cout << "You've got 5 chances.." << std::endl;

        int count = 0;
        int maxcount = 5;

        while (count < maxcount)
        {
            std::cout << "Chance " << count + 1 << " :";
            std::cin >> guess;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "please enter a valid choice" << std::endl;
                continue;
            }
            if (guess == random)
            {
                std::cout << "Congratulation! you won.." << std::endl;
                break;
            }
            else if (guess > random)
            {
                std::cout << "Your guess is too high!" << std::endl;
            }
            else
            {
                std::cout << "Your guess is too low!" << std::endl;
            }

            count++;
        }
        if (count == maxcount)
        {
            std::cout << "Your chances are over! Better luck next time.." << std::endl;
            std::cout << "The correct number is " << random << std::endl;
        }
    }
}
int main()
{
    int number, level;
    char choice;

    do
    {
        std::cout<<std::endl;
        std::cout << "==================WELCOME TO THE GUESSING GAME:==================" << std::endl;
        std::cout<<std::endl;
        std::cout << "Select your mode" << std::endl;
        std::cout<<std::endl;
        std::cout << "1.Easy" << std::endl;
        std::cout << "If you select easy , you'll get 5 chances to guess the correct number " << std::endl;
        std::cout << "The range of numbers will be from 1-10" << std::endl<< std::endl<< std::endl;
        std::cout << "2.hard" << std::endl;
        std::cout << "If you select hard , you'll get 10 chances to guess the correct number " << std::endl;
        std::cout << "The range of numbers will be from 1-100" << std::endl<< std::endl << std::endl;
        std::cout << "3.Exit Game" << std::endl;
        std::cout<<"Enter you choice:";
        std::cin >> number;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Please enter a valid choice" << std::endl;
            continue;
        }

        switch (number)
        {

        case 1:
            level = 10;
            game(level);
            break;
        case 2:
            level = 100;
            game(level);
            break;
        case 3:
            std::cout << "Thank you !";
            break;

        default:
            std::cout << "invalid input" << std::endl;
            break;
        }
        std::cout << "Do you want to continue? (y/n)" << std::endl;
        std::cin >> choice;
        if (choice != 'y')
        {
            return 0;
        }

    } while (number != 3);
    return 0;
}