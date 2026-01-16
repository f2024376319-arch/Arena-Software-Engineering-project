#include <iostream>
#include <vector>
#include <string>
using namespace std;

// --- User Structure (from Sprint 1) ---
struct User {
    string username;
    string role;
};

// --- League Structure ---
struct League {
    string name;
    string type;        // e.g., Football, Cricket
    int maxPlayers;
    string owner;
};

// --- Global variables ---
vector<User> users;     // Pre-registered users
vector<League> leagues; // All leagues

// --- Functions ---
void createLeague() {
    string name, type, owner;
    int maxPlayers;

    cout << "Enter League Name: ";
    cin.ignore(); // clear input buffer
    getline(cin, name);
    cout << "Enter League Type (e.g., Football, Cricket): ";
    getline(cin, type);
    cout << "Enter Max Players: ";
    cin >> maxPlayers;
    cin.ignore();
    cout << "Enter Owner Username: ";
    getline(cin, owner);

    // Check if owner exists
    bool found = false;
    for (auto &u : users) {
        if (u.username == owner && u.role == "LeagueOwner") {
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Owner does not exist or is not a LeagueOwner!\n";
        return;
    }

    leagues.push_back({name, type, maxPlayers, owner});
    cout << "✅ League created successfully!\n";
}

void viewLeagues() {
    if (leagues.empty()) {
        cout << "No leagues created yet.\n";
        return;
    }

    cout << "\n--- All Leagues ---\n";
    for (auto &l : leagues) {
        cout << "Name: " << l.name 
             << ", Type: " << l.type
             << ", Max Players: " << l.maxPlayers
             << ", Owner: " << l.owner << "\n";
    }
}

// --- Demo users for testing ---
void demoUsers() {
    users.push_back({"Alice", "Player"});
    users.push_back({"Bob", "LeagueOwner"});
    users.push_back({"Carol", "Advertiser"});
}

// --- Main Menu ---
int main() {
    demoUsers(); // add demo users
    int choice;

    while (true) {
        cout << "\n===== League Management =====\n";
        cout << "1. Create League\n2. View Leagues\n3. Exit\nChoose: ";
        cin >> choice;

        if (choice == 1) createLeague();
        else if (choice == 2) viewLeagues();
        else if (choice == 3) break;
        else cout << "Invalid choice!\n";
    }
    return 0;
}
