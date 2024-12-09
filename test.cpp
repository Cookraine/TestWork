#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book
{
    private:
        int bookID;
        string name;
        string author;
        bool availability;
    public:

        void setName(string newName)
        {
            name = newName;
        }

        void setAuthor(string newAuthor)
        {
            author = newAuthor;
        }

        bool updateAvailability(bool availability)
        {
             return availability;
        }
};

class Cart
{
    private:
        int cartID;
        vector<Book> items;
    
    public:
        void addItem(Book item) 
        {
            items.push_back(item);
        }
};

class Person
{
    protected:
        int age;
        string name;
        bool document;
    
    public:

        string getName()
        {
            return name;
        }

        void setName(string newName)
        {
            name = newName;
        }

        void setAge(int newAge)
        {
            age = newAge;
        }
};

class Reader : public Person
{
    private:
        bool ticket;
        Cart personal_cart;
    
    public:
        void addBookToCart(Book item)
        {
            personal_cart.addItem(item);
        }
    
};

class Librarian : public Person
{
    private:
        string affiliation;
        bool education;
        int salary;

    public:
        void giveBookToReader()
        {
            cout<<"Reader can borrow this book succesfully!\n";
        }
        void declineReaderRequest()
        {
            cout<<"Reader cannot borrow this book.\n";
        }
};


int main()
{
    Reader client1;
    client1.setName("Petro Ivanenko");
    client1.setAge(19);

    Librarian worker;
    worker.setName("Olena Savchenko");
    worker.setAge(51);

    Book item1;
    item1.setAuthor("Lyubko Deresh");
    item1.setName("Cult");
    bool bookAvailability1 = item1.updateAvailability(1);

    client1.addBookToCart(item1);

    if (bookAvailability1 == 1)
        worker.giveBookToReader();
    else
        worker.declineReaderRequest();

    Reader client2;
    client2.setName("Olha Hryhorchuk");
    client2.setAge(33);

    cout<<endl;
    Book item2;
    item2.setAuthor("Serhiy Zhadan");
    item2.setName("Voroshylovhrad");
    bool bookAvailability2 = item2.updateAvailability(0);

    client2.addBookToCart(item2);

    if (bookAvailability2 == 1)
        worker.giveBookToReader();
    else
        worker.declineReaderRequest();

    return 0;
}