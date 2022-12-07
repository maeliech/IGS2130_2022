#include <iostream>
using namespace std;

int i = 0;

class Secure {
private:
    const char* m_msg;
    const char* m_psw;
    int m_maxtry;
public:
    Secure(const char* msg, const char* psw, int maxtry)
        : m_msg{msg}, m_psw{psw}, m_maxtry{maxtry} {}
    const char* read(const char* psw);
    void updateMessage(const char* msg, const char* psw);
    void changePassword(const char* oldpsw, const char* newpsw);
};

const char* Secure::read(const char* psw) {
    if ((m_maxtry > 0) && (m_psw == psw)) {
        m_maxtry = m_maxtry + i;
        i = 0;
        return m_msg;
    }
    if (m_psw != psw) {
        m_maxtry= m_maxtry - 1;
        i++;
        if (m_maxtry <= 0) {
            cout << "Can't try anymore. Message and password have been reset" << endl;
            changePassword(psw, "new_ps");
            return "";
        }
        cout << "Password does not match. You have " << m_maxtry << " more time(s) to try." << endl;
    }
    return "";
}

void Secure::updateMessage(const char* msg, const char* psw) {
    if (m_psw == psw) {
        m_msg = msg;
    }
}

void Secure::changePassword(const char* oldpsw, const char* newpsw) {
    if (m_psw == oldpsw) {
        m_psw = newpsw;
    }
}

int main() {
    int i;
    // Secure{message, password, maximum # of attempts}
    //   message: "Welcome Inha University"
    //   password: "2022Fall"
    //   maximum # of attempts: 3 
    //    <- the stored message and password will be destroyed if wrong password used 3 times
    Secure secuMessage{ "Welcome Inha University", "2022Fall", 3 };

    for (i = 0; i < 2; ++i) {
        // Secure::read(password) <- function to read the stored message
        // return the stored message if the password matched, otherwise return ""
        cout << secuMessage.read("2022Spring"); // wrong password
    }
    // The maximum # of attempts(3) will be recovered if the password is correct
    cout << secuMessage.read("2022Fall") << endl; // correct password
    // Secure::updateMessage(newMessage, password) <- function to change the message
    // the 'newMessage' will be stored if the password matched
    secuMessage.updateMessage("Welcome Incheon Korea", "2022Fall"); // correct password
    cout << secuMessage.read("2022Fall") << endl; // correct password
    // Secure::changePassword(old_password, new_password) <- function to change the password
    // The old password will be replaced with the 'new_password' if the password matched 
    secuMessage.changePassword("2022Fall", "EasyPass");
    cout << secuMessage.read("EasyPass") << endl; // correct password

    for (i = 0; i < 3; ++i) {
        cout << secuMessage.read("2022Fall"); // wrong password
    }
    cout << "After the password and message are reset..." << endl;
    cout << secuMessage.read("EasyPass"); // password reset, old password(==wrong password)
    cout << "End of the program";

    return 0;
}