#include <iostream>
#include <string>
#include <vector>
using namespace std;
class User
{
    string username, password;

public:
    User(string name, string pass)
    {
        username = name;
        password = pass;
    }
    string getUsername()
    {
        return username;
    }
    string getPassword()
    {
        return password;
    }
};
class userManager
{
    vector<User> users; // create object of vector
public:
    void registerUser()
    {
        string username, password;
        cout << "Enter User Name : ";
        cin >> username;
        cout << "Enter Password : ";
        cin >> password;

        User newUser(username, password);
        users.push_back(newUser);

        cout << "\t\t User Register Successfully....." << endl;
    }
    bool LoginUser(string name, string pass)
    {
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getUsername() == name && users[i].getPassword() == pass)
            {
                cout << "\t\tLogin Successfully...." << endl;
                return true;
            }
        }
        cout << "\t\tInvalid Username or Password.." << endl;
        return false;
    }
    void showUser()
    {
        cout << "\t\t---Users List---" << endl;
        for (int i = 0; i < users.size(); i++)
        {
            cout << "\t\t" << users[i].getUsername() << endl;
        }
    }
    void searchUser(string username)
    {
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getUsername() == username)
            {
                cout << "\t\t User Found" << endl;
            }
        }
    }
    void deleteUser(string username)
    {
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getUsername() == username)
            {
                users.erase(users.begin() + i);
                cout << "\t\tUser Remove Successfully..." << endl;
            }
        }
    }
};
int main()
{
    userManager um;
    int opt;
    char choice;
    do
    {
        system("cls");
        cout << "\n\n\t\t1. Register User " << endl;
        cout << "\t\t2. Login " << endl;
        cout << "\t\t3. Show User List " << endl;
        cout << "\t\t4. Search User " << endl;
        cout << "\t\t5. Delete User " << endl;
        cout << "\t\t6. Exit" << endl;
        cout << "\t\tEnter Your Choice : ";
        cin >> opt;
        switch (opt)
        {
        case 1:
        {
            um.registerUser();
            break;
        }

        case 2:
        {
            string username, password;
            cout << "\t\tEnter User : ";
            cin >> username;
            cout << "\t\tEnter Password : ";
            cin >> password;
            um.LoginUser(username, password);
            break;
        }

        case 3:
        {
            um.showUser();
            break;
        }
        case 4:
        {
            string username;
            cout << "\t\tEnter User Name : ";
            cin >> username;
            um.searchUser(username);
            break;
        }
        case 5:
        {
            string username;
            cout << "\t\tEnter Username : ";
            cin >> username;
            um.deleteUser(username);
            break;
        }
        case 6:
        {
            exit(1);
        }
        }
        cout << "Do You Want To Continue [yes/no] ? :";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}