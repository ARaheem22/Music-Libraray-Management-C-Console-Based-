// #include <SFML/Audio.hpp>
// #include <SFML/Audio/Sound.hpp>
// #include <SFML/Audio/SoundBuffer.hpp>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
// Custom header files
#include "./include/auth.h"
#include "./include/display.h"
#include "./include/playlists.h"
#include "./include/searching.h"
#include "./include/songs.h"
#include "./include/sorting.h"
#include "./include/users.h"

using namespace std;

// sf::SoundBuffer buffer;
// sf::Sound sound;

void playSongInBackground();

// Main handling functions
void handleAdmin(User);
void handleUser(User);

// PROGRAM STARTS HERE
int main() {
    // Plays a song in background while the program is running
    // playSongInBackground();
    displayLogo();

    // It is used to break the while loop (see case 3 of switch)
    bool run = true;
    while (run) {
        cout << "\n1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        int choice = getUserChoice();

        switch (choice) {
        // LOGIN CASE
        case 1: {
            printYellowText(" \n>> LOGIN TO YOUR ACCOUNT");
            printYellowText("=========================");
            string username, password;
            cout << "USERNAME: ";
            cin.ignore();
            getline(cin, username);

            cout << "PASSWORD: ";
            getline(cin, password);

            // loginUser returns a "string" response
            string response = loginUser(username, password);
            if (response != "Login successful") {
                printErrorMessage(response);
                continue;
            }
            printSuccessMessage(response);
            // Get user data
            User user = fetchUser(username);
            if (user.role == "admin") {
                handleAdmin(user);
            } else {
                handleUser(user);
            }
            continue;
        }

        // REGISTER CASE
        case 2: {
            printYellowText("\n>> CREATE NEW ACCOUNT");
            printYellowText("====================");

            string fullname, username, password, confirmPassword;

            cout << "Fullname: ";
            // NOTE: ask chatgpt or google for the difference between
            //       getline and cin (IMPORTANT!!!)
            cin.ignore();
            getline(cin, fullname);

            cout << "Username: ";
            getline(cin, username);

            cout << "Password: ";
            getline(cin, password);

            cout << "Confirm Password: ";
            getline(cin, confirmPassword);

            string response =
                registerUser(fullname, username, password, confirmPassword);
            if (response != "Registration successful") {
                printErrorMessage(response);
            } else {
                printSuccessMessage(response);
            }
            continue;
        }

        // Exits the program
        case 3:
            run = false;
            continue;

        default:
            printErrorMessage("Invalid choice");
            break;
        }
    }
    return 0;
}

// FUNCTIONS DEFINITIONS

void handleUser(User user) {
    cout << "\nWelcome " << user.fullname;
    bool run = true;

    while (run) {
        cout << endl;
        cout << "\n1. List all songs" << endl;
        cout << "2. List my playlists" << endl;
        cout << "3. Create a new playlist" << endl;
        cout << "4. Add songs in playlist" << endl;
        cout << "5. Remove a playlist" << endl;
        cout << "6. Open a playlist" << endl;
        cout << "7. Search songs" << endl;
        cout << "8. Sort songs" << endl;
        cout << "9. Recommend a song" << endl;
        cout << "10. Logout" << endl;
        int choice = getUserChoice();

        switch (choice) {
        case 1:
            displaySongs("song_name");
            continue;

        case 2:
            displayPlaylists(user.playlists);
            continue;

        case 3: {
            cout << "\n>> CREATE NEW PLAYLIST" << endl;
            cout << "======================" << endl;

            string name;
            cout << "Enter a name for your playist: ";
            cin.ignore();
            getline(cin, name);

            vector<Playlist> newPlaylist = createPlaylist(name, user.playlists);
            user.playlists = newPlaylist;

            for (int k = 0; k < usersArray.size(); k++) {
                if (usersArray[k].username == user.username) {
                    usersArray[k].playlists = user.playlists;
                }
            }

            continue;
        }

        case 4: {
            // TODO(fawad): check if playlist and songs with those ids exists or
            // not
            cout << "\n>> ADD SONGS IN PLAYLIST" << endl;
            cout << "=======================" << endl;

            int playlistID, songID;
            cout << "Enter playlist ID: ";
            cin >> playlistID;
            cout << "Enter song ID: ";
            cin >> songID;

            // Check if playlist exists
            bool isPlaylist = findPlaylist(playlistID, user.playlists);
            if (!isPlaylist) {
                printErrorMessage("Playlist not found");
                continue;
            }
            // ######################

            // Check if song exists
            bool isSong = false;
            for (int j = 0; j < songsArray.size(); j++) {
                if (songsArray[j].id == songID) {
                    isSong = true;
                    break;
                }
            }
            if (!isSong) {
                printErrorMessage("Song not found");
                continue;
            }
            // ######################

            Playlist plst;
            for (int i = 0; i < user.playlists.size(); i++) {
                if (user.playlists[i].id == playlistID) {
                    plst = user.playlists[i];
                }
            }

            // Check for song duplication
            bool isSongAlreadyInPlaylist = false;
            for (int i = 0; i < plst.songs.size(); i++) {
                if (plst.songs[i].id == songID) {
                    isSongAlreadyInPlaylist = true;
                    break;
                }
            }
            if (isSongAlreadyInPlaylist) {
                printErrorMessage("Song already exists in playlist");
                continue;
            }

            // ######################

            Song song;
            for (int j = 0; j < songsArray.size(); j++) {
                if (songsArray[j].id == songID) {
                    song = songsArray[j];
                }
            }

            plst.songs.push_back(song);
            printSuccessMessage("Song added successfully");

            for (int i = 0; i < user.playlists.size(); i++) {
                if (user.playlists[i].id == playlistID) {
                    user.playlists[i] = plst;
                }
            }
            continue;
        }

        case 5: {
            cout << "\n>> REMOVE PLAYLIST" << endl;
            cout << "==================" << endl;

            int playlistID;
            cout << "Enter playlist ID: ";
            cin >> playlistID;

            // Check if playlist exists
            bool isPlaylist = findPlaylist(playlistID, user.playlists);
            if (!isPlaylist) {
                printErrorMessage("Playlist not found");
                continue;
            }

            vector<Playlist> userPlaylists = user.playlists;
            for (int i = 0; i < userPlaylists.size(); i++) {
                if (userPlaylists[i].id == playlistID) {
                    userPlaylists.erase(userPlaylists.begin() + playlistID - 1);
                    user.playlists = userPlaylists;
                    printSuccessMessage("Playlist deleted successfully");
                }
            }

            for (int k = 0; k < usersArray.size(); k++) {
                if (usersArray[k].username == user.username) {
                    usersArray[k].playlists = user.playlists;
                }
            }
            continue;
        }

        case 6:
            openPlaylist(user.playlists);
            continue;

        case 7:
            searchSongs();
            continue;

        case 8:
            sortSongs();
            continue;

        case 9: {
            cout << "\n>> RECOMMEND A SONG" << endl;
            cout << "====================" << endl;
            cout << "How Are You Feeling Right Now\n";
            cout << "1.Sad \n";
            cout << "2.Happy \n";
            cout << "3.Romantic \n";
            cout << "4.Party \n";
            int mood = getUserChoice();

            switch (mood) {
            case 1:
                for (int i = 0; i < songsArray.size(); i++) {
                    if (songsArray[i].mood == "sad") {
                        cout << songsArray[i].title << endl;
                    }
                }
                break;

            case 2:
                for (int i = 0; i < songsArray.size(); i++) {
                    if (songsArray[i].mood == "happy") {
                        cout << songsArray[i].title << endl;
                    }
                }
                break;

            case 3:
                for (int i = 0; i < songsArray.size(); i++) {
                    if (songsArray[i].mood == "romantic") {
                        cout << songsArray[i].title << endl;
                    }
                }
                break;

            case 4:
                for (int i = 0; i < songsArray.size(); i++) {
                    if (songsArray[i].mood == "party") {
                        cout << songsArray[i].title << endl;
                    }
                }
                break;

            default:
                printErrorMessage("Invalid option");
                break;
            }
            continue;
        }

        case 10:
            printSuccessMessage("You have been logged out of your account");
            run = false;
            continue;

        default:
            printErrorMessage("Invalid option");
            continue;
        }
    }
}

void handleAdmin(User user) {
    cout << "\nWelcome " << user.fullname;

    bool run = true;
    while (run) {
        cout << "\n1. Add a song" << endl;
        cout << "2. Edit a song" << endl;
        cout << "3. Delete a song" << endl;
        cout << "4. List all songs" << endl;
        cout << "5. Logout" << endl;
        int choice = getUserChoice();

        switch (choice) {
        case 1:
            addNewSong();
            continue;

        case 2:
            editSong();
            continue;

        case 3: {
            printYellowText("\n >> DELETE SONG");
            printYellowText("================");
            int id;
            cout << "Enter song id: ";
            cin >> id;
            deleteSong(id);
            continue;
        }

        case 4:
            displaySongs("song_name");
            continue;

        case 5:
            printSuccessMessage("You have been logged out of your account");
            run = false;
            break;

        default:
            printErrorMessage("Invalid option");
            break;
        }
    }
}

// Plays song in bg (copied :p)
// void playSongInBackground() {
// if (!buffer.loadFromFile("./got.wav")) {
//  cout << "Error while downloading media file" << endl;
// return;
// }
//  sound.setBuffer(buffer);
//    sound.setLoop(true);
//  sound.play();
//}

// ##### UTILITY FUNCTIONS #####
int getUserChoice() {
    int choice;
    cout << "\n[~] MUSICLOUD >> ";
    cin >> choice;

    return choice;
}
