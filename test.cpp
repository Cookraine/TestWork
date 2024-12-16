#include <iostream>
#include <string>
#include <list>
using namespace std;

class Book
{
    private:
        string name;
        string author;
        bool availability;

    public:

        string getName()
        {
            return name;
        }

        void setName(string newName)
        {
            name = newName;
        }

        void setAuthor(string newAuthor)
        {
            author = newAuthor;
        }

        void updateAvailability(bool newAvailability)
        {
             availability = newAvailability;
        }

        bool isAvailable()
        {
            return availability;
        }

};

class Cart
{
    private:
        list<Book*> items;
    
    public:

        list<Book*>& getItems() 
        {
            return items;
        }
        void addItem(Book* book_item) 
        {
            items.push_back(book_item);
        }
};

class Person
{
    protected:
        int age;
        string name;
    
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
        Cart personal_cart;
    
    public:
        
        Cart& getCart()
        {
            return personal_cart;
        }
        void addBookToCart(Book* item)
        {
            personal_cart.addItem(item);
        }
    
};

class Librarian : public Person
{
    private:

        Book book_item;

    public:

        void addBookToLibrary(Book& book_item, string name, string author)
        {
            book_item.setName(name);
            book_item.setAuthor(author);
            book_item.updateAvailability(1);
        }

        void removeBookFromLibrary(Book book_item)
        {
            book_item.updateAvailability(0);
        }

        void checkReaderRequest(Reader& client)
        {
            Cart& cart = client.getCart();
            list<Book*>& items = cart.getItems();

            for (Book* book : items)
            {
                if (book->isAvailable())
                {
                cout << "Reader " << client.getName() << " can borrow the book titled '"
                     << book->getName() << "' successfully!\n";
                book->updateAvailability(0);
                }
                else
                {
                    cout << "Reader " << client.getName() << " cannot borrow the book titled '"
                         << book->getName() << "' as it is unavailable.\n";
                }
            }
        }
};


int main()
{
    Librarian worker;
    worker.setName("Olena Savchenko");
    worker.setAge(51);

    Book item1;
    worker.addBookToLibrary(item1, "Cult", "Lyubko Deresh");

    Book item2;
    worker.addBookToLibrary(item2, "Voroshylovhrad", "Serhiy Zhadan");

    Reader client1;
    client1.setName("Petro Ivanenko");
    client1.setAge(19);

    client1.addBookToCart(&item1);
    worker.checkReaderRequest(client1);

    Reader client2;
    client2.setName("Olha Hryhorchuk");
    client2.setAge(33);

    cout<<endl;

    client2.addBookToCart(&item2);
    client2.addBookToCart(&item1);
    worker.checkReaderRequest(client2);

    return 0;
}