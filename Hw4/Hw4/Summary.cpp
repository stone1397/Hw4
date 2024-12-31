#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std; // namespace std 사용

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
            cout << "대여 가능한 책이 " << stock[input] << "권 남았습니다." << endl;
        }
        else {
            cout << "대여 가능한 책이 없습니다." << endl;
        }
    }

    void returnBook(string input) {
        stock[input]++;
        cout << "반납 완료되었습니다. 현재 대여 가능한 책은 " << stock[input] << "권 입니다." << endl;
    }

    void displayStock() {
        for (auto it = stock.begin(); it != stock.end(); it++) {
            cout << "Book: " << it->first << ", Stock: " << it->second << endl;
        }
    }
};



class BookManager {
private:
    vector<Book> books; // 책 목록 저장

public:
    // Getter 함수: books를 가져오기 위해 정의
    vector<Book> getter() const {
        return books;
    }
    
    // 책 검색 메서드
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

    
    // 책 추가 메서드
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back 사용
        cout << "책이 추가되었습니다: " << title << " by " << author << endl;
    }

    // 모든 책 출력 메서드
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }

        cout << "현재 도서 목록:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }
};

int main() {
    BookManager manager;
    BorrowManager borrowmanager;

    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while (true) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
        cout << "3. 책 검색" << endl; // 제목 또는 작가의 이름을 입력해서 책을 검색
        cout << "4. 책 대여" << endl;
        cout << "5. 책 반납" << endl;
        cout << "0. 종료" << endl; // 프로그램 종료
        cout << "선택: ";

        int choice; // 사용자의 메뉴 선택을 저장
        cin >> choice;

        if (choice == 1) {
            // 1번 선택: 책 추가
            // 사용자로부터 책 제목과 저자명을 입력받아 BookManager에 추가합니다.
            string title, author;
            cout << "책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력 (공백 포함)
            cout << "책 저자: ";
            getline(cin, author); // 저자명 입력 (공백 포함)
            manager.addBook(title, author); // 입력받은 책 정보를 추가
            borrowmanager.initializeStock(title);
        }
        else if (choice == 2) {
            // 2번 선택: 모든 책 출력
            // 현재 BookManager에 저장된 책 목록을 출력합니다.
            manager.displayAllBooks();
        }
        else if (choice == 3) {

            while (true) {
                // 3번 선택: 검색, 제목으로 찾을 지 작가로 찾을 지 선택
                cout << "1. 제목으로 찾기" << endl;
                cout << "2. 작가 이름으로 찾기" << endl;
                cout << "0. 이전 메뉴" << endl;
                cin >> choice;
                string title, author;


                if (choice == 1) {
                    // 1번 선택: 제목으로 책을 찾기
                    cout << "책 제목: ";
                    cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
                    getline(cin, title); // 제목 입력 (공백 포함)
                    Book* book = manager.findBookByTitle(title); // 찾기 참수 호출
                    if (book != nullptr) {
                        cout << "검색하신 책이 도서관에 있습니다." << endl;
                        cout << book->title << " by " << book->author << endl;
                    }
                    else {
                        cout << "검색하신 책은 도서관에 없습니다." << endl;
                    }
                }
                else if (choice == 2) {
                    // 2번 선택: 저자로 책을 찾기
                    cout << "책 저자: ";
                    cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
                    getline(cin, author); // 저자 입력 (공백 포함)
                    Book* book = manager.findBookByAuthor(author); // 찾기 함수 호출 
                    if (book != nullptr) {
                        cout << "검색하신 책이 도서관에 있습니다." << endl;
                        cout << book->title << " by " << book->author << endl;
                    }
                    else {
                        cout << "검색하신 책은 도서관에 없습니다." << endl;
                    }
                }
                else if (choice == 0) {
                    // 3번 선택 이전 메뉴
                    break;
                }
                else {
                    // 잘못된 입력 처리
                    // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
                    cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
                }
            }
        }
        
        else if (choice == 4) {
            string input;
            cout << "책 제목 또는 저자를 입력하세요: ";
            cin.ignore(); // 버퍼 비우기
            getline(cin, input); // 제목 또는 저자 입력받기

            bool found = false; // 일치 여부 확인
            
            
            for (const auto& book : manager.getter()) {
                if (book.title == input || book.author == input) {
                    found = true;
                    borrowmanager.borrowBook(book.title); // 제목을 기준으로 대여
                    borrowmanager.displayStock();
                    break; // 일치하는 책을 찾으면 루프 종료
                }
                else {
                    cout << "일치하는 책이 없습니다." << endl;
                }
            }
        }

        else if (choice == 5) {
            string input;
            cout << "책 제목 또는 저자를 입력하세요: ";
            cin.ignore(); // 버퍼 비우기
            getline(cin, input); // 제목 또는 저자 입력받기

            bool found = false; // 일치 여부 확인


            for (const auto& book : manager.getter()) {
                if (book.title == input || book.author == input) {
                    found = true;
                    borrowmanager.returnBook(book.title); // 제목을 기준으로 대여
                    borrowmanager.displayStock();
                    break; // 일치하는 책을 찾으면 루프 종료
                }
                else {
                    cout << "일치하는 책이 없습니다." << endl;
                }
            }
        }

        else if (choice == 0) {
            // 3번 선택: 종료
            // 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
            cout << "프로그램을 종료합니다." << endl;
            break; // while 루프 종료
        }
        else {
            // 잘못된 입력 처리
            // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0; // 프로그램 정상 종료
}
