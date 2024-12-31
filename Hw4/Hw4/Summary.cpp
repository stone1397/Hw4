#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std; // namespace std ���

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {
    }
};

class BorrowManager {
private:
    unordered_map<string, int> stock;

public:
    void initializeStock(string input)
    {
        stock[input] = 3;
    }

    void borrowBook(string input) {
        if (stock[input] > 0) {
            stock[input]--;
            cout << "�뿩 ������ å�� " << stock[input] << "�� ���ҽ��ϴ�." << endl;
        }
        else {
            cout << "�뿩 ������ å�� �����ϴ�." << endl;
        }
    }

    void returnBook(string input) {
        stock[input]++;
        cout << "�ݳ� �Ϸ�Ǿ����ϴ�. ���� �뿩 ������ å�� " << stock[input] << "�� �Դϴ�." << endl;
    }

    void displayStock() {
        for (auto it = stock.begin(); it != stock.end(); it++) {
            cout << "Book: " << it->first << ", Stock: " << it->second << endl;
        }
    }
};



class BookManager {
private:
    vector<Book> books; // å ��� ����

public:
    // Getter �Լ�: books�� �������� ���� ����
    vector<Book> getter() const {
        return books;
    }
    
    // å �˻� �޼���
    Book* findBookByTitle(string title)
    {
        bool is_exist = false;
        for (int i = 0; i < books.size(); i++) {
            if (books[i].title == title) {
                return &books[i];
                break;
            }
        }
        if (is_exist == false) {
            
            return nullptr;
        }
    }
    Book* findBookByAuthor(string author)
    {
        bool is_exist = false;
        for (int i = 0; i < books.size(); i++) {
            if (books[i].author == author) {
                return &books[i];
            }
        }
        if (is_exist == false) {
           
            return nullptr;
        }
    }

    
    // å �߰� �޼���
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back ���
        cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
    }

    // ��� å ��� �޼���
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }

        cout << "���� ���� ���:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }
};

int main() {
    BookManager manager;
    BorrowManager borrowmanager;

    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl; // å ������ �Է¹޾� å ��Ͽ� �߰�
        cout << "2. ��� å ���" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "3. å �˻�" << endl; // ���� �Ǵ� �۰��� �̸��� �Է��ؼ� å�� �˻�
        cout << "4. å �뿩" << endl;
        cout << "5. å �ݳ�" << endl;
        cout << "0. ����" << endl; // ���α׷� ����
        cout << "����: ";

        int choice; // ������� �޴� ������ ����
        cin >> choice;

        if (choice == 1) {
            // 1�� ����: å �߰�
            // ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
            string title, author;
            cout << "å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է� (���� ����)
            cout << "å ����: ";
            getline(cin, author); // ���ڸ� �Է� (���� ����)
            manager.addBook(title, author); // �Է¹��� å ������ �߰�
            borrowmanager.initializeStock(title);
        }
        else if (choice == 2) {
            // 2�� ����: ��� å ���
            // ���� BookManager�� ����� å ����� ����մϴ�.
            manager.displayAllBooks();
        }
        else if (choice == 3) {

            while (true) {
                // 3�� ����: �˻�, �������� ã�� �� �۰��� ã�� �� ����
                cout << "1. �������� ã��" << endl;
                cout << "2. �۰� �̸����� ã��" << endl;
                cout << "0. ���� �޴�" << endl;
                cin >> choice;
                string title, author;


                if (choice == 1) {
                    // 1�� ����: �������� å�� ã��
                    cout << "å ����: ";
                    cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
                    getline(cin, title); // ���� �Է� (���� ����)
                    Book* book = manager.findBookByTitle(title); // ã�� ���� ȣ��
                    if (book != nullptr) {
                        cout << "�˻��Ͻ� å�� �������� �ֽ��ϴ�." << endl;
                        cout << book->title << " by " << book->author << endl;
                    }
                    else {
                        cout << "�˻��Ͻ� å�� �������� �����ϴ�." << endl;
                    }
                }
                else if (choice == 2) {
                    // 2�� ����: ���ڷ� å�� ã��
                    cout << "å ����: ";
                    cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
                    getline(cin, author); // ���� �Է� (���� ����)
                    Book* book = manager.findBookByAuthor(author); // ã�� �Լ� ȣ�� 
                    if (book != nullptr) {
                        cout << "�˻��Ͻ� å�� �������� �ֽ��ϴ�." << endl;
                        cout << book->title << " by " << book->author << endl;
                    }
                    else {
                        cout << "�˻��Ͻ� å�� �������� �����ϴ�." << endl;
                    }
                }
                else if (choice == 0) {
                    // 3�� ���� ���� �޴�
                    break;
                }
                else {
                    // �߸��� �Է� ó��
                    // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
                    cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
                }
            }
        }
        
        else if (choice == 4) {
            string input;
            cout << "å ���� �Ǵ� ���ڸ� �Է��ϼ���: ";
            cin.ignore(); // ���� ����
            getline(cin, input); // ���� �Ǵ� ���� �Է¹ޱ�

            bool found = false; // ��ġ ���� Ȯ��
            
            
            for (const auto& book : manager.getter()) {
                if (book.title == input || book.author == input) {
                    found = true;
                    borrowmanager.borrowBook(book.title); // ������ �������� �뿩
                    borrowmanager.displayStock();
                    break; // ��ġ�ϴ� å�� ã���� ���� ����
                }
                else {
                    cout << "��ġ�ϴ� å�� �����ϴ�." << endl;
                }
            }
        }

        else if (choice == 5) {
            string input;
            cout << "å ���� �Ǵ� ���ڸ� �Է��ϼ���: ";
            cin.ignore(); // ���� ����
            getline(cin, input); // ���� �Ǵ� ���� �Է¹ޱ�

            bool found = false; // ��ġ ���� Ȯ��


            for (const auto& book : manager.getter()) {
                if (book.title == input || book.author == input) {
                    found = true;
                    borrowmanager.returnBook(book.title); // ������ �������� �뿩
                    borrowmanager.displayStock();
                    break; // ��ġ�ϴ� å�� ã���� ���� ����
                }
                else {
                    cout << "��ġ�ϴ� å�� �����ϴ�." << endl;
                }
            }
        }

        else if (choice == 0) {
            // 3�� ����: ����
            // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
            cout << "���α׷��� �����մϴ�." << endl;
            break; // while ���� ����
        }
        else {
            // �߸��� �Է� ó��
            // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0; // ���α׷� ���� ����
}
