#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

// bool taskstatus = true;
std::string pending = "(pending)";
std::string completed = "(completed)";

class taskmanager
{
private:
    vector<bool> status;
    vector<string> task;
    int pos;

public:
    taskmanager(vector<string> &x, vector<bool> &complete) : task(x), status(complete), pos(1) {}

    void addtask(const std::string &taskdescription)
    {

        if (pos >= 0 && pos < 50)
        {
            task[pos] = taskdescription;
            status[pos] = true;
            pos++;
            std::cout << "Task added successfully." << std::endl;
        }
        else
        {
            std::cout << "Task limit reached. Cannot add more tasks." << std::endl;
        }
    }

    void viewtaskstatus(int index)
    {
        if (index >= 0 && index < 50)
        {
            if (task[index].empty())
            {
                std::cout << "No task has been assigned at index " << index << "." << std::endl;
            }
            else if (status[index])
            {
                std::cout << "Task at index " << index << ": " << task[index] << pending << std::endl;
            }
            else
            {
                std::cout << "Task at index " << index << ": " << task[index] << completed << std::endl;
            }
        }
        else
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Please enter valid index " << std::endl;
        }
    }
    void updatestatus(int index)
    {
        if (index >= 0 && index < 50)
        {
            if (task[index].empty())
            {
                std::cout << "No task has been assigned at index " << index << "." << std::endl;
            }
            else if (status[index])
            {
                status[index] = false;
                std::cout << "task status updated successfully!" << std::endl;
            }
            else
            {
                std::cout << "Task already updated" << std::endl;
            }
        }
        else
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Please enter valid index " << std::endl;
        }
    }

    void removetask(int index)
    {
        if (index >= 0 && index < 50)
        {
            if (task[index].empty())
            {
                std::cout << "No task has been assigned at the specific index " << std::endl;
            }
            else
            {
                task[index] = "This task has been removed and it is ";

                std::cout << "Task removed successfully!" << std::endl;
            }
        }
        else
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Please enter valid index " << std::endl;
        }
    }
};

int main()
{
    vector<string> mytask(50);
    vector<bool> status(50);
    taskmanager task(mytask, status);
    int choice, removeindex;
    std::string taskdescription;
    int index, updateindex;

    do
    {

        // system("cls");
        std::cout << "TASK MANAGER" << std::endl;
        std::cout << "1.Add New Task" << std::endl;
        std::cout << "2.View Task status" << std::endl;
        std::cout << "3.Update task completion status" << std::endl;
        std::cout << "4.Remove tasks" << std::endl;
        std::cout << "5.Exit task manager" << std::endl;
        std::cout << "Enter Your choice:";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Enter the task:";
            std::cin.ignore();
            std::getline(std::cin, taskdescription);
            task.addtask(taskdescription);
            std::cout << "=======================================" << std::endl;
            break;
        case 2:
            std::cout << "Enter the index of the task to view the status:";
            std::cin >> index;

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Please enter valid index" << std::endl;
            }
            else
            {
                task.viewtaskstatus(index);
            }
            std::cout << "=======================================" << std::endl;
            break;
        case 3:
            std::cout << "Enter the index of the task to update status:";
            std::cin >> updateindex;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Please enter valid index" << std::endl;
            }
            else
            {
                task.updatestatus(updateindex);
            }
            std::cout << "=======================================" << std::endl;
            break;
        case 4:
            std::cout << "Enter the index of the task to remove:";
            std::cin >> removeindex;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Please enter valid index" << std::endl;
            }
            else
            {
                task.removetask(removeindex);
            }
            std::cout << "=======================================" << std::endl;
            break;
        case 5:
            std::cout << "Thank You for working with us" << std::endl;
            break;

        default:
            std::cout << "Invalid input" << std::endl;
            std::cout << "Please enter valid input" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            std::cout << "=======================================" << std::endl;

            break;
        }
    } while (choice != 5);

    return 0;
}
