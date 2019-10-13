#include "../includes_usr/fileIO.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;
/* clears, then loads books from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries in books
 * 			SUCCESS if all data is loaded
 * */
int loadBooks(std::vector<book> &books, const char *filename) {
	books.clear();
	ifstream file;
	file.open(filename, ios::in);
	if (!file.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}

	string line;
	string token;
//	Data myData;
//	while (getline(file, line)) {
//		//TODO how to parse through line??
//	}
//
//	return SUCCESS;
	while (!filename.eof()) {

	}
}

/* serializes books to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries books (do not create file)
 * 			SUCCESS if all data is saved
 * */
int saveBooks(std::vector<book> &books, const char *filename) {
	if (books.empty()) {
		return NO_BOOKS_IN_LIBRARY;
	}

	ofstream file;
	file.open(filename, ios::out);
	if (!file.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}

	string bookData = "";

	for (int i = 0; i < books.size(); i++) {
		bookData = to_string(books[i].book_id) + "," + books[i].title + "," + books[i].author + "," + to_string(books[i].state) + "," + to_string(books[i].loaned_to_patron_id);
		file << bookData << endl;
	}

	if (file.is_open()) {
		file.close();
	}

	return SUCCESS;
}

/* clears, then loads patrons from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons
 * 			SUCCESS if all data is loaded
 * */
int loadPatrons(std::vector<patron> &patrons, const char *filename) {
	return SUCCESS;
}

/* serializes patrons to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons  (do not create file)
 * 			SUCCESS if all data is saved
 * */
int savePatrons(std::vector<patron> &patrons, const char *filename) {
	if (patrons.empty()) {
			return NO_PATRONS_IN_LIBRARY;
		}

		ofstream file;
		file.open(filename, ios::out);
		if (!file.is_open()) {
			return COULD_NOT_OPEN_FILE;
		}


	return SUCCESS;
}
