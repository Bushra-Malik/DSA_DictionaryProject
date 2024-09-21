# Linked List-based Dictionary in C++

## Project Overview
This project implements a simple dictionary using a linked list data structure in C++. It allows users to manage words through various operations such as adding, updating, deleting, and searching for words. The dictionary can display words in alphabetical order and supports reading from a file to populate the list with words.

## Features
- **Insert Words**: Add new words to the dictionary in alphabetical order.
- **Display Words**: Show all words stored in the dictionary, sorted alphabetically.
- **Search Word**: Find and display the position of a word within the dictionary.
- **Update Word**: Replace an existing word with a new one.
- **Delete Word**: Remove a word from the dictionary.
- **Display by Alphabet**: Display words starting with a specific letter.
- **File Handling**: Automatically load words from a text file into the dictionary.

## How It Works
The dictionary is built using a linked list where each node stores a word and its starting alphabet. The program presents a menu to the user, allowing them to choose from the following options:
1. Insert words and alphabets from a text file.
2. Display all words in alphabetical order.
3. Display words starting with a user-specified letter.
4. Display the starting letter of each word in the dictionary.
5. Search for a word in the dictionary.
6. Insert a word provided by the user.
7. Delete a word from the dictionary.
8. Update a word with a new one.
9. Exit the program.

### Menu Options:
The program offers the following options:
- **Insert Words from File**: Read words from a text file (`Dictionary.txt`) and insert them into the linked list.
- **Sort and Display Words**: Display all words in alphabetical order, sorted by the first letter of each word.
- **Search**: Allows the user to search for a specific word and display its position in the list.
- **Update**: Replace an existing word with a new word.
- **Delete**: Remove a word from the dictionary.
- **File Handling**: Automatically read and insert words from a file.

## File Handling
The program reads from a file named `Dictionary.txt`. Each line of the file should contain one word. Words are inserted into the dictionary upon reading the file and are sorted alphabetically based on the first letter.


## Technologies Used
- **Programming Language**: C++
- **Data Structures**: Linked List
- **File Handling**: Reading words from text files for dynamic insertion into the dictionary


