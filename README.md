# PasswordManager
Password Manager (C++)
A console-based password manager written in C++ as part of a data structures course. Built to practice linked list implementation, dynamic memory management, and file I/O in C++.

What It Does

Add, display, and delete saved passwords via a simple text menu
Passwords are stored locally and persist between sessions via a text file
Passwords are obfuscated when displayed on screen
Entries are kept in alphabetical order using an insertion sort on the linked list


Concepts Demonstrated

Singly linked list (manual implementation, no STL)
Dynamic memory allocation and deallocation (new / delete)
File I/O (ifstream / ofstream)
String encoding/decoding
Modular design with separate functions for each operation


How to Run
Online (easiest)
Paste main.cpp into onlinegdb.com, set language to C++, and hit Run.
Local (requires g++)
bashg++ -o password_manager main.cpp
./password_manager

Usage
***MENU***
A  Add a password
E  Erase a password
L  List all passwords
Q  Quit
On first run, a passwords.txt file will be created in the same directory. This file stores your entries and is loaded automatically on the next run.

Notes

This is a course project focused on data structures — not intended for storing real passwords
Storage is plain text and obfuscation is minimal by design
Built and tested with g++ (MinGW) on Windows
