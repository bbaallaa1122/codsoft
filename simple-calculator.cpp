#include <iostream>
#include <cmath>
#include <typeinfo>
template <typename T>

class calculator
{

private:
    T x, y;

public:
    calculator(T a, T b) : x(a), y(b){};

    T add()
    {
        T c = x + y;
        return c;
    }
    T subract()
    {
        T c = x - y;
        return c;
    }
    T multiply()
    {
        T c = x * y;
        return c;
    }
    T divide()
    {
        if (y != 0)
        {
            return x / y;
        }
        else
        {
            std::cout << "Error: division by Zero" << std::endl;
            return 0;
        }
    }
    void updateValues(T a, T b)
    {
        x = a;
        y = b;
    }
};

int main()
{
    auto first = 0.0, second = 0.0;
    auto x = 0.0, y = 0.0;
    int choice;
    std::cout << "SIMPLE CALCULATOR" << std::endl;
    std::cout << "This calculator allows you to work with any kind of data types" << std::endl;
    std::cout << "You can also change the input operands whenever necessary!" << std::endl;
    std::cout << "Enter the first number:";
    std::cin >> first;
    std::cout << "Enter the second number:";
    std::cin >> second;
    // calculator<type_info(first)> obj1
    calculator<decltype(first)> obj1(first, second);

    do
    {
        std::cout << "Choose an operation to perform" << std::endl;
        std::cout << "1.addition" << std::endl;
        std::cout << "2.subraction" << std::endl;
        std::cout << "3.multiplication" << std::endl;
        std::cout << "4.division" << std::endl;
        std::cout << "5.New Calculation" << std::endl;
        std::cout << "6.exit" << std::endl;
        std::cout<<"Enter your choice:";
        std::cin >> choice;
        // calculator<decltype(first)> obj1(first,second);
        switch (choice)
        {
        case 1:
            std::cout << "result after adding:" << obj1.add() << std::endl;
            std::cout << "---------------------------------" << std::endl;
            break;
        case 2:
            std::cout << "result after subraction:" << obj1.subract() << std::endl;
            std::cout << "---------------------------------" << std::endl;
            break;
        case 3:
            std::cout << "result after multiplcation:" << obj1.multiply() << std::endl;
            std::cout << "---------------------------------" << std::endl;
            break;
        case 4:
            std::cout << "result after dividing:" << obj1.divide() << std::endl;
            std::cout << "---------------------------------" << std::endl;
            break;
        case 5:
            std::cout << "enter the first number:";
            std::cin >> x;
            std::cout << "enter the second number:";
            std::cin >> y;
            obj1.updateValues(x, y);
            std::cout << "New values are set for calcualtion" << std::endl;

            break;

        case 6:
            std::cout << "Thank you for working with us" << std::endl;
            std::cout << "---------------------------------" << std::endl;
            break;
        default:
            std::cout << "Invalid input" << std::endl;
        }
    } while (choice != 6);

    return 0;
}