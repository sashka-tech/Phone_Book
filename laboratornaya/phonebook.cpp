#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <Windows.h>

using namespace std;

enum PhoneBook {
	exit1, // 0
	add, // 1
	edit, // 2
	del, // 3
	look, // 4
	look_all // 5
};

struct Phone_Book {
	string surname;
	string name;
	string patronymic;
	int phonenumber;
	string country;
	int birthday;
	string organization;
	string position;
	string notes;
};

void add_1(vector<Phone_Book> &phone) {

	Phone_Book books;

	cout << "Ââåäèòå ñâîþ ôàìèëèþ: ";
	cin >> books.name;
	Beep(500, 100);
	cout << "Ââåäèòå ñâîå èìÿ: ";
	cin >> books.surname;
	Beep(500, 100);
	cout << "Ââåäèòå ñâîå îò÷åñòâî: ";
	cin >> books.patronymic;
	Beep(500, 100);
	cout << "Ââåäèòå ñâîé ïåðñîíàëüíûé íîìåð (Òîëüêî Öèôðû): ";
	cin >> books.phonenumber;
	Beep(500, 100);
	cout << "Ââåäèòå ñòðàíó: ";
	cin >> books.country;
	Beep(500, 100);
	cout << "Ââåäèòå äàòó ðîæäåíèÿ (mm/dd/yy, òîëüêî öèôðû): ";
	cin >> books.birthday;
	Beep(500, 100);
	cout << "Ââåäèòå Îðãàíèçàöèþ: ";
	cin >> books.organization;
	Beep(500, 100);
	cout << "Ââåäèòå Äîëæíîñòü: ";
	cin >> books.position;
	Beep(500, 100);
	cout << "Ââåäèòå Ïðî÷èå çàìåòêè: ";
	cin >> books.notes;
	Beep(500, 100);

	phone.push_back(books);

	cout << "\nÇàïèñü óñïåøíî äîáàâëåíà !" << endl;
}

void edit_1(vector<Phone_Book> &phone)
{
	Phone_Book books;

	int num;
	string surname;
	int choose;

	cout << "1. Èçìåíèòü íîìåð \n2. Èçìåíèòü ôàìèëèþ " << endl;
	cin >> choose;
	switch (choose)
	{
	case 1:
		cout << "\t\t\t[Òåëåôîííûå íîìåðà çàïèñåé] ";

		for (int i = 0; i < phone.size(); i++) {
			cout << "\nÏîëüçîâàòåëü #" << i + 1
				<< "\nÍîìåð Òåëåôîíà: " << phone[i].phonenumber << endl;
		}

		cout << "Ââåäèòå òåëåôîííûé íîìåð äëÿ åãî ðåäàêòèðîâàíèÿ: ";
		cin >> num;

		for (int i = 0; i < phone.size(); i++)
		{
			cout << "Ââåäèòå íîâûé òåëåôîííûé íîìåð: ";
			cin >> phone[i].phonenumber;

			cout << "\nÂàø òåëåôîííûé íîìåð óñïåøíî èçìåíåí ! ";

			cout << "\nÔàìèëèÿ: " << phone[i].surname
				<< "\nÈìÿ: " << phone[i].name
				<< "\nÎò÷åñòâî: " << phone[i].patronymic
				<< "\nÒåëåôîííûé íîìåð: " << phone[i].phonenumber
				<< "\nÑòðàíà: " << phone[i].country
				<< "\nÄàòà ðîæäåíèÿ: " << phone[i].birthday
				<< "\nÎðãàíèçàöèÿ: " << phone[i].organization
				<< "\nÄîëæíîñòü: " << phone[i].position
				<< "\nÏðî÷èå çàìåòêè: " << phone[i].notes << endl;
			break;
		}
		break;

	case 2:
		cout << "\t\t\t[Ôàìèëèè çàïèñåé] ";

		for (int i = 0; i < phone.size(); i++) {
			cout << "\nÏîëüçîâàòåëü #" << i + 1
				<< "\nÔàìèëèè Çàïèñè: " << phone[i].surname << endl;
		}
		cout << "Ââåäèòå ôàìèëèþ çàïèñè äëÿ åãî ðåäàêòèðîâàíèÿ: ";
		cin >> surname;

		for (int i = 0; i < phone.size(); i++)
		{
			cout << "Ââåäèòå íîâóþ ôàìèëèþ äëÿ çàïèñè: ";
			cin >> phone[i].surname;

			cout << "\nÔàìèëèÿ çàïèñè óñïåøíî áûëà èçìåíåíà ! ";

			cout << "\nÔàìèëèÿ: " << phone[i].surname
				<< "\nÈìÿ: " << phone[i].name
				<< "\nÎò÷åñòâî: " << phone[i].patronymic
				<< "\nÒåëåôîííûé íîìåð: " << phone[i].phonenumber
				<< "\nÑòðàíà: " << phone[i].country
				<< "\nÄàòà ðîæäåíèÿ: " << phone[i].birthday
				<< "\nÎðãàíèçàöèÿ: " << phone[i].organization
				<< "\nÄîëæíîñòü: " << phone[i].position
				<< "\nÏðî÷èå çàìåòêè: " << phone[i].notes << endl;
			break;
		}
		break;
	}
}

void del_1(vector<Phone_Book> &phone)
{
	Phone_Book books;

	int number;

	for (int i = 0; i < phone.size(); i++)
	{
		cout << "Çàïèñü #" << i + 1 << endl;
		cout << "Òåëåôîííûé íîìåð çàïèñè: " << phone[i].phonenumber << endl;
	}

	cout << "Ââåäèòå òåëåôîííûé íîìåð äëÿ óäàëåíèÿ çàïèñè: ";
	cin >> number;

	for (int i = 0; i < phone.size(); i++)
	{
		if (number == phone[i].phonenumber)
		{
			phone.erase(phone.begin() + i);
		}
	}
}

void look_1(vector<Phone_Book> phone)
{
	cout << "\t\t\t[Êðàòêàÿ èíôîðìàöèÿ çàïèñåé] ";

	for (int i = 0; i < phone.size(); i++) {
		cout << "\nÏîëüçîâàòåëü #" << i + 1
			<< "\nÔàìèëèÿ: " << phone[i].surname
			<< "\nÈìÿ: " << phone[i].name
			<< "\nÍîìåð Òåëåôîíà: " << phone[i].phonenumber << endl;
	}
}

void look_all_1(vector<Phone_Book> phone) {

	cout << "\t\t\t[Ïîëíàÿ èíôîðìàöèÿ çàïèñåé] ";

	for (int i = 0; i < phone.size(); i++) {
		cout << "\nÏîëüçîâàòåëü #" << i + 1
			<< "\nÔàìèëèÿ: " << phone[i].surname
			<< "\nÈìÿ: " << phone[i].name
			<< "\nÎò÷åñòâî: " << phone[i].patronymic
			<< "\nÒåëåôîííûé íîìåð: " << phone[i].phonenumber
			<< "\nÑòðàíà: " << phone[i].country
			<< "\nÄàòà ðîæäåíèÿ: " << phone[i].birthday
			<< "\nÎðãàíèçàöèÿ: " << phone[i].organization
			<< "\nÄîëæíîñòü: " << phone[i].position
			<< "\nÏðî÷èå çàìåòêè: " << phone[i].notes << endl;
	}
}

int main()
{
	Phone_Book books;
	setlocale(LC_ALL, "rus");

	vector<Phone_Book> phone;

	int menu;
	int ret_urn;

	do {
		cout << "------------------------------ÒÅËÅÔÎÍÍÀß ÊÍÈÃÀ------------------------------" << endl;
		cout << "[PH] 0. Âûõîä "
			<< "\n[PH] 1. Ñîçäàòü çàïèñü"
			<< "\n[PH] 2. Ðåäàêòèðîâàòü òåëåôîííûé íîìåð çàïèñè "
			<< "\n[PH] 3. Óäàëèòü çàïèñü ïî íîìåðó òåëåôîíà"
			<< "\n[PH] 4. Ïîñìîòðåòü êðàòêóþ èíôîðìàöèþ î çàïèñè"
			<< "\n[PH] 5. Ïîñìîòðåòü ïîëíóþ èíôîðìàöèþ î çàïèñè" << endl;
		cout << "Âûáåðèòå äåéñòâèå - ";
		cin >> menu;

		switch (menu)
		{
		case exit1:
			exit(0);
			break;

		case add:
			add_1(phone);
			break;

		case edit:
			edit_1(phone);
			break;

		case del:
			del_1(phone);
			break;

		case look:
			look_1(phone);
			break;

		case look_all:
			look_all_1(phone);
			break;
		}

		cout << "\nÕîòèòå âåðíóòüñÿ? [1 - Äà, 0 - Íåò.]" << endl;
		cin >> ret_urn;
		system("cls");

	} while (ret_urn != 0);
}
