#include "../include/display.h"
#include <iostream>

using namespace std;

void displayLogo() {
    cout << "                                                                  "
            "                                      "
         << endl;
    cout << "          __                                                      "
            "                                    "
         << endl;
    cout << "        ,'  , `.                                               "
            ",--,                                      "
         << endl;
    cout << "     ,-+-,.' _ |                            ,--,             "
            ",--.'|                               ,---, "
         << endl;
    cout << "  ,-+-. ;   , ||         ,--,             ,--.'|             |  | "
            ":     ,---.           ,--,    ,---.'| "
         << endl;
    cout << " ,--.'|'   |  ;|       ,'_ /|   .--.--.   |  |,              :  : "
            "'    '   ,\\        ,'_ /|    |   | : "
         << endl;
    cout << "|   |  ,', |  ':  .--. |  | :  /  /    '  `--'_       ,---.  |  ' "
            "|   /   /   |  .--. |  | :    |   | | "
         << endl;
    cout << "|   | /  | |  ||,'_ /| :  . | |  :  /`.\\  ,' ,'|     /     \\ '  "
            "| |  .   ; ,. :,\'_ /| :  . |  ,--.__| | "
         << endl;
    cout << "'   | :  | :  |,|  ' | |  . . |  :  ;_    '  | |    /    / ' |  | "
            ":  '   | |: :|  ' | |  . . /   ,'   | "
         << endl;
    cout << ";   . |  ; |--' |  | ' |  | |  \\  \\    `. |  | :   .    ' /  '  "
            ": |__'   | .; :|  | ' |  | |.   '  /  | "
         << endl;
    cout << "|   : |  | ,    :  | : ;  ; |   `----.   \\ '  : |_ '   ; :_ |  | "
            "'.'|   :    |:  | : ;  ; |'   ; |:  | "
         << endl;
    cout << "|   | '  |/     '  :  `--'   \\ /  /`--'  /|  | '.'|'   | '.'|;  "
            ":    ;\\   \\  / '  :  `--'   \\   | '/  ' "
         << endl;
    cout << ";   | |`-'      :  ,      .-./'--'.     / ;  :    ;|   :    :|  , "
            "  /  `----'  :  ,      .-./   :    :| "
         << endl;
    cout << "|   ;/           `--`----'      `--'---'  |  ,   /  \\   \\  /  "
            "---`-'            `--`----'    \\   \\  /   "
         << endl;
    cout << "'---'                                      ---`-'    `----'       "
            "                            `----'    "
         << endl;
}
void printErrorMessage(string text) {
    text = "\nx " + text + " x\n";
    cout << text;
}
void printSuccessMessage(string text) {
    text = "\n*** " + text + " ***\n";
    cout << text;
}
void printYellowText(string text) {
    text = text + "\n";
    cout << text;
}

// FOR DEVCP, USE THE CODE BELOW & COMMENT OUT THE CODE ABOVE

// #include "../include/display.h"
// #include <iostream>
// #include <windows.h>
//
// using namespace std;
//
// void displayLogo() {
// 	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
// 	SetConsoleTextAttribute(consoleHandle, 5);
//     cout << " "
//             "                                      "
//          << endl;
//     cout << "          __ "
//             "                                    "
//          << endl;
//     cout << "        ,'  , `.                                               "
//             ",--,                                      "
//          << endl;
//     cout << "     ,-+-,.' _ |                            ,--,             "
//             ",--.'|                               ,---, "
//          << endl;
//     cout << "  ,-+-. ;   , ||         ,--,             ,--.'|             |
//     | "
//             ":     ,---.           ,--,    ,---.'| "
//          << endl;
//     cout << " ,--.'|'   |  ;|       ,'_ /|   .--.--.   |  |,              :
//     : "
//             "'    '   ,\\        ,'_ /|    |   | : "
//          << endl;
//     cout << "|   |  ,', |  ':  .--. |  | :  /  /    '  `--'_       ,---.  |
//     ' "
//             "|   /   /   |  .--. |  | :    |   | | "
//          << endl;
//     cout << "|   | /  | |  ||,'_ /| :  . | |  :  /`.\\  ,' ,'|     /     \\ '
//     "
//             "| |  .   ; ,. :,\'_ /| :  . |  ,--.__| | "
//          << endl;
//     cout << "'   | :  | :  |,|  ' | |  . . |  :  ;_    '  | |    /    / ' |
//     | "
//             ":  '   | |: :|  ' | |  . . /   ,'   | "
//          << endl;
//     cout << ";   . |  ; |--' |  | ' |  | |  \\  \\    `. |  | :   .    ' /  '
//     "
//             ": |__'   | .; :|  | ' |  | |.   '  /  | "
//          << endl;
//     cout << "|   : |  | ,    :  | : ;  ; |   `----.   \\ '  : |_ '   ; :_ |
//     | "
//             "'.'|   :    |:  | : ;  ; |'   ; |:  | "
//          << endl;
//     cout << "|   | '  |/     '  :  `--'   \\ /  /`--'  /|  | '.'|'   | '.'|;
//     "
//             ":    ;\\   \\  / '  :  `--'   \\   | '/  ' "
//          << endl;
//     cout << ";   | |`-'      :  ,      .-./'--'.     / ;  :    ;|   :    :|
//     , "
//             "  /  `----'  :  ,      .-./   :    :| "
//          << endl;
//     cout << "|   ;/           `--`----'      `--'---'  |  ,   /  \\   \\  / "
//             "---`-'            `--`----'    \\   \\  /   "
//          << endl;
//     cout << "'---'                                      ---`-'    `----' "
//             "                            `----'    "
//          << endl;
// 	SetConsoleTextAttribute(consoleHandle, 7);
// }
// void printErrorMessage(string text) {
// 	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
// 	SetConsoleTextAttribute(consoleHandle, 4);
//     text = "\nx " + text + " x\n";
//     cout << text;
//     SetConsoleTextAttribute(consoleHandle, 7);
// }
// void printSuccessMessage(string text) {
// 	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
// 	SetConsoleTextAttribute(consoleHandle, 2);
//     text = "\n*** " + text + " ***\n";
//     cout << text;
//     SetConsoleTextAttribute(consoleHandle, 7);
// }
// void printYellowText(string text) {
//     text = text + "\n";
//     cout << text;
// }
