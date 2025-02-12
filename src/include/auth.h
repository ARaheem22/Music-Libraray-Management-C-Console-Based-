#pragma once
#ifndef AUTH_MODULE
#define AUTH_MODULE

#include <iostream>

using namespace std;

string registerUser(string, string, string, string);
string loginUser(string, string);
string validateUserData(string, string, string, string);

#endif
