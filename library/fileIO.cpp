#include "../includes_usr/fileIO.h"
#include "../includes_usr/datastructures.h"
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
	file.open(filename, ios::in);				//didn't have to do c_str????
	if (!file.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}

	string line;
	string tempId;
	string tempState;
	string tempPatron;
	book myBook;	//creating the book from datastructures.h to put into array
	stringstream ss;

	string stuff = "";
	while (getline(file, stuff)) {
		ss.str(stuff);

		getline(ss, tempId, ',');
		myBook.book_id = stoi(tempId);

		getline(ss, myBook.title, ',');

		getline(ss, myBook.author, ',');

		getline(ss, tempState, ',');
		myBook.state = static_cast<book_checkout_state>(stoi(tempState));

		getline(ss, tempPatron, ',');
		myBook.loaned_to_patron_id = stoi(tempPatron);

		books.push_back(myBook);

		ss.clear();
	}

	if (books.empty()) {
		return NO_BOOKS_IN_LIBRARY;
	}

	return SUCCESS;
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
		bookData = to_string(books[i].book_id) + "," + books[i].title + ","
				+ books[i].author + "," + to_string(books[i].state) + ","
				+ to_string(books[i].loaned_to_patron_id);
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
	patrons.clear();

	ifstream file;
	file.open(filename, ios::in);
	if (!file.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}

	string line;
	string tempId;
	string tempBook;
	patron myPatron;	//creating the book from datastructures.h to put into array
	stringstream ss;

	string stuff = "";
	while (getline(file, stuff)) {
		ss.str(stuff);

		getline(ss, tempId, ',');
		myPatron.patron_id = stoi(tempId);

		getline(ss, myPatron.name, ',');

		getline(ss, tempBook, ',');
		myPatron.number_books_checked_out = stoi(tempBook);

		patrons.push_back(myPatron);

		ss.clear();
	}

	if (patrons.empty()) {
		return NO_PATRONS_IN_LIBRARY;
	}

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

	string patronData = "";

	for (int i = 0; i < patrons.size(); i++) {
		patronData = to_string(patrons[i].patron_id) + "," + patrons[i].name
		+ "," + to_string(patrons[i].number_books_checked_out);
		file << patronData << endl;
	}

	if (file.is_open()) {
		file.close();
	}

	return SUCCESS;
}
