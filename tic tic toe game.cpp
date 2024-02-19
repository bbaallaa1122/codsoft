#include <iostream>

char boxes[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char player = 'X';
bool running = true;

int enterchoice()
{
    char position;
    std::cout << "Enter the position for " << player << ": ";
    std::cin >> position;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (boxes[i][j] == position)
            {
                boxes[i][j] = player;
                return 1;
            }
        }
    }

    // std::cout << "Invalid position or already filled. Please choose another position." << std::endl;
    return -1;
}

void entervalue()
{
    
    if (enterchoice() == 1 && running)
    {
        player = (player == 'X') ? 'O' : 'X';
    }
    else
    {
        std::cout << "Invalid position or already filled. Please choose another position." << std::endl;
    }
}

bool checkwinner()
{
    if (boxes[0][0] == boxes[0][1] && boxes[0][0] == boxes[0][2])
    {
        running = false;
        return false;
    }
    else if (boxes[1][0] == boxes[1][1] && boxes[1][0] == boxes[1][2])
    {
        running = false;
        return false;
    }
    else if (boxes[2][0] == boxes[2][1] && boxes[2][0] == boxes[2][2])
    {
        running = false;
        return false;
    }
    else if (boxes[0][0] == boxes[1][0] && boxes[0][0] == boxes[2][0])
    {
        running = false;
        return false;
    }
    else if (boxes[0][1] == boxes[1][1] && boxes[0][1] == boxes[2][1])
    {
        running = false;
        return false;
    }
    else if (boxes[0][2] == boxes[1][2] && boxes[0][2] == boxes[2][2])
    {
        running = false;
        return false;
    }
    else if (boxes[0][0] == boxes[1][1] && boxes[0][0] == boxes[2][2])
    {
        running = false;
        return false;
    }
    else if (boxes[0][2] == boxes[1][1] && boxes[0][2] == boxes[2][0])
    {
        running = false;
        return false;
    }
    else
    {
        running = true;
        return true;
    }
}

bool gameover()
{

    if (running)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (boxes[i][j] != 'X' && boxes[i][j] != 'O')
                {
                    return true;
                }
            }
        }
    }

    std::cout << "Game is a draw" << std::endl;
    running = false;
    // std::cout << "Game is a draw" << std::endl;

    return false;
}

void displayboard()
{
    system("cls");
    std::cout << "welcome to the tic tac toe stage !! \n"
              << std::endl;
    std::cout << " " << boxes[0][0] << " | " << boxes[0][1] << " | " << boxes[0][2] << std::endl;
    std::cout << "----------" << std::endl;
    std::cout << " " << boxes[1][0] << " | " << boxes[1][1] << " | " << boxes[1][2] << std::endl;
    std::cout << "----------" << std::endl;
    std::cout << " " << boxes[2][0] << " | " << boxes[2][1] << " | " << boxes[2][2] << std::endl;
    std::cout << std::endl;
}

int main()
{
    char choice = 'y';
    while (choice == 'y')
    {
        while (running)
        {
            displayboard();
            entervalue();
            checkwinner();
            gameover();
            displayboard();
        }

        if (!checkwinner())
        {
            std::cout << "Congratulation! " << ((player == 'X') ? 'O' : 'X') << " has won the game..." << std::endl;
        }
        else{
            std::cout<<"Game is a draw"<<std::endl;
        }
        std::cout<<"game over !!"<<std::endl;
        std::cout << "Do you wish to continue (y/n)?";
        std::cin >> choice;
        if (choice == 'y')
        {
            boxes[0][0] = '1';
            boxes[0][1] = '2';
            boxes[0][2] = '3';
            boxes[1][0] = '4';
            boxes[1][1] = '5';
            boxes[1][2] = '6';
            boxes[2][0] = '7';
            boxes[2][1] = '8';
            boxes[2][2] = '9';
            player = 'X';
            running = true;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
