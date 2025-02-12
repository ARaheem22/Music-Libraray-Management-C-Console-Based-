#pragma once
#ifndef PLAYLISTS_MODULE
#define PLAYLISTS_MODULE

#include "./songs.h"
#include "./users.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void displayPlaylists(vector<Playlist>);
void displayPlaylistData(int, vector<Playlist>);
vector<Playlist> createPlaylist(string, vector<Playlist>);
void openPlaylist(vector<Playlist>);
void displayPlaylistMenu(Playlist);
bool findPlaylist(int, vector<Playlist>);

#endif
