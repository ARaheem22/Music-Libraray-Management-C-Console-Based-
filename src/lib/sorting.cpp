#include "../include/sorting.h"
#include "../include/display.h"
#include "../include/songs.h"
#include "../include/users.h"
#include <algorithm>
#include <iostream>

using namespace std;

bool sortByYear(Song song1, Song song2) { return (song1.year > song2.year); }
bool sortByArtist(Song song1, Song song2) {
    return (song1.artist < song2.artist);
}
bool sortByGenre(Song song1, Song song2) { return (song1.genre < song2.genre); }
bool sortBySongName(Song song1, Song song2) {
    return (song1.title < song2.title);
}
void sortSongs() {
    cout << endl << ">> SORTING" << endl;
    cout << "===========" << endl;
    cout << "Select how to sort the songs" << endl;
    cout << "1) Sort by Artist Name." << endl;
    cout << "2) Sort by Song Name." << endl;
    cout << "3) Sort by Genre." << endl;
    cout << "4) Sort by Year." << endl;
    int choice = getUserChoice();

    switch (choice) {
    case 1:
        sort(songsArray.begin(), songsArray.end(), sortByArtist);
        displaySongs("artist");
        break;

    case 2:
        sort(songsArray.begin(), songsArray.end(), sortBySongName);
        displaySongs("song_name");
        break;

    case 3:
        sort(songsArray.begin(), songsArray.end(), sortByGenre);
        displaySongs("genre");
        break;

    case 4:
        sort(songsArray.begin(), songsArray.end(), sortByYear);
        displaySongs("year");
        break;

    default:
        printErrorMessage("Invalid option");
        break;
    }
}
