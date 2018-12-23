
#include <cstdio>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <utility>
#include <map>

// ���������� ��������� ������������ � �������� ������������ ��� ����������� ���� � �����
#if defined(_WIN16) | defined(_WIN32) | defined(_WIN64)
#define SEPERATOR "\\"
#else
#define SEPERATOR "/"
#endif

// ����������� �������� ��� ������� ������������ � �������
const char
COMMAND_PRINT[] = "print",
COMMAND_ADD[] = "add",
COMMAND_DELETE[] = "delete",
COMMAND_SAVE[] = "save",
COMMAND_LOAD[] = "load",
COMMAND_HELP[] = "help",
COMMAND_SORT[] = "sort",
COMMAND_EXIT[] = "exit",
COMMAND_ENDL[] = "\n";

// DEFAULT_PATH_TO_FILE ��������� �������� ���� ��� ������������/������������ ����� �� ���������
const std::string DEFAULT_PATH_TO_FILE = "C:\\Users\\Public\\card.txt";
// SORT_ASC ���������� � ������� ��������
const std::string SORT_ASC = "ASC";
// SORT_DESC ����������� � ������� �����������
const std::string SORT_DESC = "DESC";

// Card ��������� ������� ���������
struct Card {
	// bookVector �������� ������ ���� (�������� BOOK)
	std::vector<BOOK> bookVector;

	// sortMap �������� ������ ��� ���������� map[�������� ����]isDesc
	std::map<std::string, bool> sortMap;
	// sortVector ������ ����� ������� � ������� ������� ������� ����������� ����������
	std::vector<std::string> sortVector;

	// Card �����������, ������������� ��� ������������� ���������� �����
	Card() {
		// ���������� ����� �� ���������
		BOOK newBook;
		newBook.authorFirstName.append("����");
		newBook.authorLastName.append("���������");
		newBook.bookTitle.append("��� �������� ������ �� �++ �� 14 ����?");
		newBook.bookYear = 1999;
		newBook.bookPrice = 28;
		newBook.bookCategory = BOOK_CATEGORY_TRAVEL;
		this->bookVector.push_back(newBook);
	}

	// print �������� ���������� ��������� � �������
	void print();
	// print �������� ���������� ����� ��� ���������� � �������
	void printSortMap();
	// print �������� ���������� ������� ��� ���������� � �������
	void printSortVector();
	// add ��������� ����� ����� � ���������
	void add();
	// deleteCards ������� ���� ��� ��������� ���� �� ���������
	void deleteCards();
	// saveToFile ��������� ������ � ����
	void saveToFile();
	// readFromFile ��������� ������ �� �����
	void readFromFile();
	// sort ��������� ����� � ��������� � ������������ ������������������
	void initSort();
	/*
		parseSortString ����������� ������(std:cin) � ������ ����������� ��� ����������,
		��������� ���� sortMap � sortVector, ���������� false � ������ ������
	 */
	bool parseSortString(std::string str);
	// sortBook ��������� ��������� � ��������� �����
	void sortBook();
	/*
		cmpBookRecursive ���������� �������� �� sortVector �������� ����� �� �������� ������
		1 ���� firstVectorIndex > secondVectorIndex
		0 ���� firstVectorIndex == secondVectorIndex
		-1 ���� firstVectorIndex < secondVectorIndex
	*/
	std::pair<int, bool> cmpBookRecursive(
		const size_t firstVectorIndex, 
		const size_t secondVectorIndex, 
		const size_t sortIndex);
};

// run ��������� ����� ������
void run();
// strSpaceWrap ��������� ������ � ������ � ����� ������
std::string strSpaceWrap(std::string str);
// alignCenter �������� ���������� ������ ������ �� ������
std::string alignCenter(const std::string s, const int w);
// alignCenter �������� ���������� ������ ������ �� ������� ����
std::string alignRight(const std::string s, const int w);
// alignCenter �������� ���������� ������ ������ � ������ ����
std::string alignLeft(const std::string s, const int w);
// split ��������� ������ �� �����������
std::vector<std::string> split(const std::string& s, const char sep);
