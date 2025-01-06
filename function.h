#include"datatype.h"
//Nguyen mau ham
void inputBook(int *n, Book books[]);
void printBook(int n, Book books[]);
void addBook(int *n, Book books[]);
void updateBook(int n, Book books[]);
void deleteBook(int *n, Book books[]);
void saveOfFile(int n, Book books[]);
void searchBook(int n, Book books[]);
void arrangeBooks(int n, Book books[]);
void loadBooksFromFile(int *n, Book books[]);
int checkDuplicateIdAndTitle(Book books[], int n, int id, const char* title);
int isDuplicate(Book books[], int n, Book newBook);
void printMenu();




