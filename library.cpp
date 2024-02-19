#include <iostream>
#include <vector>
#include <istream>
#include <string>

class Library
{
private:
    std::string title, author, ISBN;
    bool checkingout;

public:
    Library(std::string t, std::string a, std::string isbn) : title(t), author(a), ISBN(isbn), checkingout(true) {}

    void display() const
    {
        std::cout << "Title of the book: " << title << std::endl;
        std::cout << "Author of the book: " << author << std::endl;
        std::cout << "ISBN number of the book: " << ISBN << std::endl;
        std::cout << "Status: " << (checkingout ? "available" : "checked out") << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }

    int search(const std::string &searchbook) const
    {
        if (searchbook == title || searchbook == author || searchbook == ISBN)
        {
            display();
            return 0;
        }
        else
        {
            return 1;
        }
    }

    void checkout(const std::string &isbn)
    {
        if (checkingout)
        {
            if (isbn == ISBN)
            {
                int weeks;
                std::cout << "Book found" << std::endl;
                display();
                std::cout << "Enter the due period for the return of the book (in weeks): ";
                std::cin >> weeks;
                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Please enter a valid time period (number of weeks)" << std::endl;
                }
                else
                {
                    if (weeks > 16)
                    {
                        std::cout << "Sorry! You can't borrow the book for more than 4 months" << std::endl;
                    }
                    else
                    {
                        checkingout = false;
                        std::cout << "Please ensure the safety of the book. Thank you!" << std::endl;
                    }
                }
            }
        }
        else if (!checkingout)
        {
            std::cout << "The book is already checked out or not available " << std::endl;
        }
        else
        {
            std::cout << "Book not found" << std::endl;
        }
    }
    int returnBook(const std::string &isbn)
    {
        if (isbn == ISBN)
        {
            if (!checkingout)
            {
                checkingout = true;
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    std::vector<Library> books;

    books.emplace_back("RICH DAD POOR DAD", "Robert Kiyosaki", "123456");
    books.emplace_back("ATTITUDE IS THE EVERYTHING", "Jeff Keller", "789012");

    std::string searchInput, checkoutISBN, returnISBN, newTitle, newAuthor, newISBN;
    bool searchstatus = true;

    while (true)
    {
        std::cout << "\n ========Library Management System========" << std::endl;
        std::cout << "1. Display Books" << std::endl;
        std::cout << "2. Search for a Book" << std::endl;
        std::cout << "3. Checkout Book" << std::endl;
        std::cout << "4. Return Book" << std::endl;
        std::cout << "5. Add New book to the library" << std::endl;
        std::cout << "6. Exit" << std::endl;
        char choice;
        std::cout<<"Enter you choice:";
        std::cin >> choice;
        if (std::cin.fail())
        {
            std::cin.ignore();
            std::cin.clear();
        }

        switch (choice)
        {
        case '1':
            for (const auto &book : books)
            {
                book.display();
            }
            break;

        case '2':
            std::cin.ignore();
            std::cout << "Enter book title, author, or ISBN to search: ";
            std::getline(std::cin, searchInput);
            for (const auto &book : books)
            {
                if (book.search(searchInput) == 0)
                {
                    searchstatus = false;
                    break;
                }
            }
            if (searchstatus)
            {
                std::cout << "Book not found!" << std::endl;
            }
            searchstatus=true;

            break;

        case '3':
            std::cout << "Enter the ISBN number to checkout: ";
            std::cin >> checkoutISBN;
            for (auto &book : books)
            {
                book.checkout(checkoutISBN);
            }
            break;

        case '4':
            std::cout << "Enter the ISBN number to return: ";
            std::cin >> returnISBN;
            for (auto &book : books)
            {
                if (book.returnBook(returnISBN) == 0)
                {
                    std::cout << "The book has been returned successfully" << std::endl;
                }
                else if (book.returnBook(returnISBN) == 1)
                {
                    std::cout << "The book has not been checked out" << std::endl;
                }
            }
            break;
        case '5':
            std::cin.ignore();
            std::cout << "Enter the title of the book:";
            std::getline(std::cin, newTitle);
            std::cout << "Enter the name of the author:";
            std::getline(std::cin, newAuthor);
            std::cout << "Enter the ISBN of the book:";
            std::getline(std::cin, newISBN);
            books.emplace_back(newTitle, newAuthor, newISBN);
            std::cout << "New details added successfully" << std::endl;
            break;

        case '6':
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            return 0;

        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }

    return 0;
}
