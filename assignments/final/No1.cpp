#include <iostream>
using namespace std;

class MyString {
private:
    const char* m_str;
public:
    MyString(const char* str)
        : m_str{"empty"} {}
    friend MyString operator+(MyString& str1, MyString& str2);
    friend std::ostream& operator<<(std::ostream& out, const MyString& str)
};

friend MyString operator+(MyString& str1, MyString& str2) {
        return MyString{ str1.m_str + str2.m_str};
    }
friend std::ostream& operator<<(std::ostream& out, const MyString& str) {
        out << str.m_str << endl;
}


int main() {
    MyString str1 = "I like ";
    MyString str2 = "MyString class";
    MyString str3 = str1 + str2;
    MyString str4{ str3 };
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    cout << "str4: " << str4 << endl;

    str1 += str2;
    if (str1 == str3)
        cout << "The two strings are identical." << endl;
    else
        cout << "The two strings are different." << endl;

    cout << "Enter a string: ";
    cin >> str4;
    cout << "You entered: " << str4 << endl;

    return 0;
}
