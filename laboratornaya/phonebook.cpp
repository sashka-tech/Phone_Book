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

	cout << "Введите свою фамилию: ";
	cin >> books.name;
	Beep(500, 100);
	cout << "Введите свое имя: ";
	cin >> books.surname;
	Beep(500, 100);
	cout << "Введите свое отчество: ";
	cin >> books.patronymic;
	Beep(500, 100);
	cout << "Введите свой персональный номер (Только Цифры): ";
	cin >> books.phonenumber;
	Beep(500, 100);
	cout << "Введите страну: ";
	cin >> books.country;
	Beep(500, 100);
	cout << "Введите дату рождения (mm/dd/yy, только цифры): ";
	cin >> books.birthday;
	Beep(500, 100);
	cout << "Введите Организацию: ";
	cin >> books.organization;
	Beep(500, 100);
	cout << "Введите Должность: ";
	cin >> books.position;
	Beep(500, 100);
	cout << "Введите Прочие заметки: ";
	cin >> books.notes;
	Beep(500, 100);

	phone.push_back(books);

	cout << "\nЗапись успешно добавлена !" << endl;
}

void edit_1(vector<Phone_Book> &phone)
{
	Phone_Book books;

	int num;
	string surname;
	int choose;

	cout << "1. Изменить номер \n2. Изменить фамилию " << endl;
	cin >> choose;
	switch (choose)
	{
	case 1:
		cout << "\t\t\t[Телефонные номера записей] ";

		for (int i = 0; i < phone.size(); i++) {
			cout << "\nПользователь #" << i + 1
				<< "\nНомер Телефона: " << phone[i].phonenumber << endl;
		}

		cout << "Введите телефонный номер для его редактирования: ";
		cin >> num;

		for (int i = 0; i < phone.size(); i++)
		{
			cout << "Введите новый телефонный номер и подтвердите изменение 2 раза: ";
			cin >> phone[i].phonenumber;

			cout << "\nВаш телефонный номер успешно изменен ! ";

			cout << "\nФамилия: " << phone[i].surname
				<< "\nИмя: " << phone[i].name
				<< "\nОтчество: " << phone[i].patronymic
				<< "\nТелефонный номер: " << phone[i].phonenumber
				<< "\nСтрана: " << phone[i].country
				<< "\nДата рождения: " << phone[i].birthday
				<< "\nОрганизация: " << phone[i].organization
				<< "\nДолжность: " << phone[i].position
				<< "\nПрочие заметки: " << phone[i].notes << endl;
		}
		break;

	case 2:
		cout << "\t\t\t[Фамилии записей] ";

		for (int i = 0; i < phone.size(); i++) {
			cout << "\nПользователь #" << i + 1
				<< "\nФамилии Записи: " << phone[i].surname << endl;
		}
		cout << "Введите фамилию записи для его редактирования: ";
		cin >> surname;

		for (int i = 0; i < phone.size(); i++)
		{
			cout << "Введите новую фамилию для записи и подтвердите изменение 2 раза: ";
			cin >> phone[i].surname;

			cout << "\nФамилия записи успешно была изменена ! ";

			cout << "\nФамилия: " << phone[i].surname
				<< "\nИмя: " << phone[i].name
				<< "\nОтчество: " << phone[i].patronymic
				<< "\nТелефонный номер: " << phone[i].phonenumber
				<< "\nСтрана: " << phone[i].country
				<< "\nДата рождения: " << phone[i].birthday
				<< "\nОрганизация: " << phone[i].organization
				<< "\nДолжность: " << phone[i].position
				<< "\nПрочие заметки: " << phone[i].notes << endl;
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
		cout << "Запись #" << i + 1 << endl;
		cout << "Телефонный номер записи: " << phone[i].phonenumber << endl;
	}

	cout << "Введите телефонный номер для удаления записи: ";
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
	cout << "\t\t\t[Краткая информация записей] ";

	for (int i = 0; i < phone.size(); i++) {
		cout << "\nПользователь #" << i + 1
			<< "\nФамилия: " << phone[i].surname
			<< "\nИмя: " << phone[i].name
			<< "\nНомер Телефона: " << phone[i].phonenumber << endl;
	}
}

void look_all_1(vector<Phone_Book> phone) {

	cout << "\t\t\t[Полная информация записей] ";

	for (int i = 0; i < phone.size(); i++) {
		cout << "\nПользователь #" << i + 1
			<< "\nФамилия: " << phone[i].surname
			<< "\nИмя: " << phone[i].name
			<< "\nОтчество: " << phone[i].patronymic
			<< "\nТелефонный номер: " << phone[i].phonenumber
			<< "\nСтрана: " << phone[i].country
			<< "\nДата рождения: " << phone[i].birthday
			<< "\nОрганизация: " << phone[i].organization
			<< "\nДолжность: " << phone[i].position
			<< "\nПрочие заметки: " << phone[i].notes << endl;
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
		cout << "------------------------------ТЕЛЕФОННАЯ КНИГА------------------------------" << endl;
		cout << "[PH] 0. Выход "
			<< "\n[PH] 1. Создать запись"
			<< "\n[PH] 2. Редактировать телефонный номер записи "
			<< "\n[PH] 3. Удалить запись по номеру телефона"
			<< "\n[PH] 4. Посмотреть краткую информацию о записи"
			<< "\n[PH] 5. Посмотреть полную информацию о записи" << endl;
		cout << "Выберите действие - ";
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

		cout << "\nХотите вернуться? [1 - Да, 0 - Нет.]" << endl;
		cin >> ret_urn;
		system("cls");

	} while (ret_urn != 0);
}