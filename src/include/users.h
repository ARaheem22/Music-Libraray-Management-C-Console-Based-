#pragma once
#ifndef USERS_MODULE
#define USERS_MODULE

#include "./songs.h"
#include <iostream>
#include <vector>

using namespace std;

struct Playlist {
    int id;
    string name;
    vector<Song> songs;
};

struct User {
    string fullname;
    string username;
    string password;
    string role;
    vector<Playlist> playlists;
};

extern vector<User> usersArray;

User fetchUser(string username);
int getUserChoice();

#endif
