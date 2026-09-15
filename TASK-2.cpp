#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Helper function to check if a username already exists in the database file
bool isUsernameTaken(const string& username) {
    ifstream file("users.txt");
    string line, storedUser, storedPass;
    
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, storedUser, ','); // Assuming format: username,password
        if (storedUser == username) {
            return true;
        }
    }
    return false;
}

// Registration function
void registerUser() {
    string username, password;
    
    cout << "\n--- Registration ---" << endl;
    cout << "Enter username: ";
    cin >> username;
    
    // Input validation: check if empty
    if (username.empty()) {
        cout << "Error: Username cannot be empty!" << endl;
        return;
    }
    
    // Check for duplicate usernames
    if (isUsernameTaken(username)) {
        cout << "Error: Username already exists! Please choose a different username." << endl;
        return;
    }
    
    cout << "Enter password: ";
    cin >> password;
    
    if (password.empty()) {
        cout << "Error: Password cannot be empty!" << endl;
        return;
    }
    
    // Store credentials securely in a file (users.txt)
    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << username << "," << password << endl;
        cout << "Success: Registration successful!" << endl;
    } else {
        cout << "Error: Unable to open file for saving credentials." << endl;
    }
}

// Login function
void loginUser() {
    string username, password;
    
    cout << "\n--- Login ---" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    
    ifstream file("users.txt");
    string line, storedUser, storedPass;
    bool loginSuccess = false;
    
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, storedUser, ',');
        getline(ss, storedPass);
        
        // Verify user identity
        if (storedUser == username && storedPass == password) {
            loginSuccess = true;
            break;
        }
    }
    
    if (loginSuccess) {
        cout << "Success: Login successful! Welcome back, " << username << "!" << endl;
    } else {
        cout << "Error: Invalid username or password." << endl;
    }
}

// Main menu to run the system
int main() {
    int choice;
    do {
        cout << "\n===============================" << endl;
        cout << "   LOGIN & REGISTRATION SYSTEM" << endl;
        cout << "===============================" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Error: Invalid choice! Please enter 1, 2, or 3." << endl;
        }
    } while (choice != 3);
    
    return 0;
}