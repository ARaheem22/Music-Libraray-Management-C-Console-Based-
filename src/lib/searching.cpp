#include "../include/searching.h"
#include "../include/display.h"
#include "../include/songs.h"
#include "../include/users.h"
#include <iomanip>
#include <iostream>
#include <regex>

using namespace std;

void searchSongs() {
    cout << "\n>> SEARCHING" << endl;
    cout << "=============" << endl;
    cout << "Select a searching mode: " << endl;
    cout << "1. Regular search" << endl;
    cout << "2. Refined search" << endl;
    int choice = getUserChoice();

    switch (choice) {
    case 1:
        regularSearch();
        break;
    case 2:
        refinedSearch();
        break;
    default:
        printErrorMessage("Invalid option");
        break;
    }
}

void regularSearch() {
    cout << "\n>> REGULAR SEARCH" << endl;
    cout << "==================" << endl;
    string song_name;

    cout << "Enter a song name: ";
    cin.ignore();
    getline(cin, song_name);

    // Creates a regex(pattern) using song_name variable
    regex pattern(song_name, regex_constants::icase);

    // Search
    cout << "\nShowing songs for: " << song_name << endl;
    cout << "===================================" << endl;

    for (int i = 0; i < songsArray.size(); i++) {
        string song = songsArray[i].title;
        if (regex_search(song, pattern)) {
            string artist = songsArray[i].artist;
            string genre = songsArray[i].genre;
            int year = songsArray[i].year;

            cout << song << " | " << artist << setw(8) << "|" << genre
                 << setw(8) << "| " << year << endl;
        }
    }
}

void refinedSearch() {
    cout << "\n>> REFINED SEARCH" << endl;
    cout << "==================" << endl;
    string song_name, artist, genre;

    cout << "Enter song name: ";
    cin.ignore();
    getline(cin, song_name);

    cout << "Enter artist name: ";
    cin.ignore();
    getline(cin, artist);

    cout << "Enter genre: ";
    cin.ignore();
    getline(cin, genre);

    regex artistRegex(artist, regex_constants::icase);
    regex songRegex(song_name, regex_constants::icase);
    regex genreRegex(genre, regex_constants::icase);

    cout << "\nShowing songs for: " << song_name << endl;
    cout << "===================================" << endl;

    for (int i = 0; i < songsArray.size(); i++) {
        string song = songsArray[i].title;
        string artist = songsArray[i].artist;
        string genre = songsArray[i].genre;
        int year = songsArray[i].year;

        if (regex_search(song, songRegex) &&
            regex_search(artist, artistRegex) &&
            regex_search(genre, genreRegex)) {
            // TODO(fawad): fix this display
            cout << song << setw(8) << artist << setw(8) << genre << setw(8)
                 << year << endl;
        }
    }
}
