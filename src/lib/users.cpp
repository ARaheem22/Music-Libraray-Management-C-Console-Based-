#include "../include/users.h"
#include <vector>

vector<User> usersArray = {
    {"Fawad Imran", "fwdadmin", "fawad12345", "admin", {}},
    {"Guest User", "guestaccount", "guestUser123", "user", {}},
};

User fetchUser(string username) {
    User user;
    for (int i = 0; i < usersArray.size(); i++) {
        if (usersArray[i].username == username) {
            user = usersArray[i];
            break;
        }
    }

    return user;
}
