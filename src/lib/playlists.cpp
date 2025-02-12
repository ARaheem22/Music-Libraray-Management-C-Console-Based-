#include "../include/playlists.h"
#include "../include/display.h"
#include "../include/users.h"
#include <iostream>
#include <vector>

using namespace std;

// Searches a playlist with its id
bool findPlaylist() {
    bool isFound = false;
    return isFound;
}

// Display the playists of the user
void displayPlaylists(vector<Playlist> playlists) {
    cout << "\n>> LIST MY PLAYLISTS" << endl;
    cout << "=====================" << endl;
    // Checks if the user have created some playlists
    if (playlists.size() < 1) {
        printErrorMessage("You don't have any playlists currently");
        return;
    }
    // Prints the playlist id, name and total number of songs
    for (int i = 0; i < playlists.size(); i++) {
        Playlist current = playlists[i];
        cout << current.id << "\t";
        cout << current.name << "\t\t";
        cout << current.songs.size() << endl;
    }
}

// Creates a new playlist
vector<Playlist> createPlaylist(string name, vector<Playlist> playlists) {
    // Create a new playlist object
    int playlistID = playlists.size() + 1;
    Playlist newPlaylist = {playlistID, name, {}};
    // Add the new playlist in the playlists array
    playlists.push_back(newPlaylist);
    printSuccessMessage("Playlist has been created successfully");
    return playlists;
}

// Check if playlist exists or not
bool findPlaylist(int playlistId, vector<Playlist> userPlaylists) {
    bool isFound = false;

    for (int i = 0; i < userPlaylists.size(); i++) {
        Playlist currentPlaylist = userPlaylists[i];
        if (currentPlaylist.id == playlistId) {
            isFound = true;
            break;
        }
    }
    return isFound;
}

// Open playlist to update it
void openPlaylist(vector<Playlist> userPlaylists) {
    cout << "\n>> OPEN A PLAYLIST" << endl;
    cout << "==================" << endl;

    int id;
    cout << "Enter playlist ID: ";
    cin >> id;

    // Check if playlist exists
    bool isPlaylist = findPlaylist(id, userPlaylists);
    if (!isPlaylist) {
        printErrorMessage("Playlist not found");
        return;
    }

    Playlist playlist;
    for (int i = 0; i < userPlaylists.size(); i++) {
        Playlist currentPlaylist = userPlaylists[i];
        if (currentPlaylist.id == id) {
            playlist = currentPlaylist;
        }
    }

    cout << "Playlist Name: " << playlist.name << endl;
    cout << "Total songs: " << playlist.songs.size() << endl << endl;
    for (int i = 0; i < playlist.songs.size(); i++) {
        Song currentSong = playlist.songs[i];
        cout << currentSong.id << "\t" << currentSong.title << "\t"
             << currentSong.year << endl;
    }
}
