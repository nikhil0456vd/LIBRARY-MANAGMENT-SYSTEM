#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

const int MAX_ITEMS = 10;

// Abstract Base Class
class LibraryItem
{
private:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t, string a, string d)
    {
        title = t;
        author = a;
        dueDate = d;
    }

    virtual ~LibraryItem() {}

    // Getters
    string getTitle() const
    {
        return title;
    }

    string getAuthor() const
    {
        return author;
    }

    string getDueDate() const
    {
        return dueDate;
    }

    // Setters
    void setTitle(string newTitle)
    {
        title = newTitle;
    }

    void setAuthor(string newAuthor)
    {
        author = newAuthor;
    }

    void setDueDate(string newDueDate)
    {
        dueDate = newDueDate;
    }

    // Pure Virtual Functions
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;
};

// Book Class
class Book : public LibraryItem
{
private:
    string isbn;

public:
    Book(string t, string a, string d, string i)
        : LibraryItem(t, a, d)
    {
        if (i.length() != 13)
        {
            throw invalid_argument("ISBN must contain 13 digits.");
        }

        isbn = i;
    }

    void checkOut() override
    {
        cout << "Book checked out successfully.\n";
    }

    void returnItem() override
    {
        cout << "Book returned successfully.\n";
    }

    void displayDetails() const override
    {
        cout << "\n----- BOOK -----\n";
        cout << "Title : " << getTitle() << endl;
        cout << "Author : " << getAuthor() << endl;
        cout << "Due Date : " << getDueDate() << endl;
        cout << "ISBN : " << isbn << endl;
    }
};

// DVD Class
class DVD : public LibraryItem
{
private:
    int duration;

public:
    DVD(string t, string a, string d, int dur)
        : LibraryItem(t, a, d)
    {
        if (dur <= 0)
        {
            throw invalid_argument("Duration must be positive.");
        }

        duration = dur;
    }

    void checkOut() override
    {
        cout << "DVD checked out successfully.\n";
    }

    void returnItem() override
    {
        cout << "DVD returned successfully.\n";
    }

    void displayDetails() const override
    {
        cout << "\n----- DVD -----\n";
        cout << "Title : " << getTitle() << endl;
        cout << "Author : " << getAuthor() << endl;
        cout << "Due Date : " << getDueDate() << endl;
        cout << "Duration : " << duration << " minutes\n";
    }
};

// Magazine Class
class Magazine : public LibraryItem
{
private:
    int issueNumber;

public:
    Magazine(string t, string a, string d, int issue)
        : LibraryItem(t, a, d)
    {
        if (issue <= 0)
        {
            throw invalid_argument("Issue number must be positive.");
        }

        issueNumber = issue;
    }

    void checkOut() override
    {
        cout << "Magazine checked out successfully.\n";
    }

    void returnItem() override
    {
        cout << "Magazine returned successfully.\n";
    }

    void displayDetails() const override
    {
        cout << "\n----- MAGAZINE -----\n";
        cout << "Title : " << getTitle() << endl;
        cout << "Author : " << getAuthor() << endl;
        cout << "Due Date : " << getDueDate() << endl;
        cout << "Issue Number : " << issueNumber << endl;
    }
};

int main()
{
    LibraryItem* libraryItems[MAX_ITEMS];
    int count = 0;

    try
    {
        libraryItems[count++] =
            new Book("C++ Programming", "Bjarne Stroustrup",
                     "10-07-2026", "1234567890123");

        libraryItems[count++] =
            new DVD("Avengers", "Marvel Studios",
                    "15-07-2026", 180);

        libraryItems[count++] =
            new Magazine("Tech Monthly", "Editorial Team",
                         "20-07-2026", 45);

        cout << "\n=== LIBRARY ITEMS ===\n";

        for (int i = 0; i < count; i++)
        {
            libraryItems[i]->displayDetails();
            libraryItems[i]->checkOut();
            libraryItems[i]->returnItem();
        }
    }
    catch (exception &e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    // Free Memory
    for (int i = 0; i < count; i++)
    {
        delete libraryItems[i];
    }

    return 0;
}