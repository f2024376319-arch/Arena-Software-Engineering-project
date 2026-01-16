#include <iostream>
#include <vector>
#include <string>
using namespace std;

// User structure
struct User {
    string username;
    string password;
    string role;
};

// Global user list
vector<User> users;

// Function to register a user
void registerUser() {
    string username, password, role;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    cout << "Enter role (Player / LeagueOwner / Advertiser): ";
    cin >> role;

    // Check if username already exists
    for (auto &u : users) {
        if (u.username == username) {
            cout << "Username already exists!\n";
            return;
        }
    }

    // Add user
    users.push_back({username, password, role});
    cout << "User registered successfully!\n";
}

// Function to login
void loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    for (auto &u : users) {
        if (u.username == username && u.password == password) {
            cout << "Login successful! Role: " << u.role << "\n";
            return;
        }
    }

    cout << "Login failed!\n";
}

// Function to show all users (Operator)
void showUsers() {
    if (users.empty()) {
        cout << "No users registered yet.\n";
        return;
    }

    cout << "\nAll Users (Operator View):\n";
    for (auto &u : users) {
        cout << "Username: " << u.username << ", Role: " << u.role << "\n";
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== User Management =====\n";
        cout << "1. Register\n2. Login\n3. Show All Users\n4. Exit\nChoose: ";
        cin >> choice;

        if (choice == 1) registerUser();
        else if (choice == 2) loginUser();
        else if (choice == 3) showUsers();
        else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        }
        else cout << "Invalid choice!\n";
    }

    return 0;
}