#include "../include/auth.h"
#include "../include/users.h"
#include <iostream>
#include <regex>

using namespace std;

string validateUserData(string fullname, string username, string password,
                        string confirmPassword) {
    // Here, size() returns the total length of the string
    if (fullname.size() > 30) {
        return "Fullname cannot be longer than 30 characters";
    }
    if (username.size() < 5) {
        return "Username should be 5 characters long at least";
    }
    regex usernameRegex("^[a-z0-9]+$");
    if (!regex_match(username, usernameRegex)) {
        return "Username should only contain letters and numbers";
    }
    if (password.size() < 9) {
        return "Password should be 10 characters long";
    }
    if (password != confirmPassword) {
        return "Passwords do not match";
    }
    return "ok";
}

string registerUser(string fullname, string username, string password,
                    string confirmPassword) {
    // Validate data
    string message =
        validateUserData(fullname, username, password, confirmPassword);
    if (message != "ok") {
        return message;
    }

    // Check if user exists
    for (int i = 0; i < usersArray.size(); i++) {
        string existingUser = usersArray[i].username;
        if (username == existingUser) {
            return "Username is already taken";
        }
    }
    // Create a new user
    User user = {fullname, username, password, "user"};
    usersArray.push_back(user);
    return "Registration successful";
}

string loginUser(string username, string password) {
    // Check if user exists
    for (int i = 0; i < usersArray.size(); i++) {
        User existingUser = usersArray[i];
        if (username == existingUser.username) {
            if (password == existingUser.password) {
                return "Login successful";
            } else {
                return "Incorrect username or password";
            }
        }
    }
    return "No user found";
}
