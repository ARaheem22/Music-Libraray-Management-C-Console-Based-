#pragma once
#ifndef SONGS_MODULE
#define SONGS_MODULE

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Song {
    int id;
    int year;
    string artist;
    string title;
    string genre;
    string mood;
};

void displaySongs(string);
int generateId();
void addNewSong();
void editSong();
void deleteSong(int songID);

extern vector<Song> songsArray;

#endif
