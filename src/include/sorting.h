#pragma once
#ifndef SORTING_MODULE
#define SORTING_MODULE

#include "./songs.h"
#include <iostream>

using namespace std;

void sortSongs();
bool sortByYear(Song, Song);
bool sortByArtist(Song, Song);
bool sortByGenre(Song, Song);
bool sortBySongName(Song, Song);

#endif
