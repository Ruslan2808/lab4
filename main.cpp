#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;

class Animal {
protected:
	char* name;
	char* ms;
public:
	Animal(char*, char*);
	~Animal();
};

class Mammal :public Animal {
private:
	char* pt;
	int age;
public:
	Mammal(char*, char*, char*, int);
	~Mammal();
	void show();
};

class Fish :public Animal {
private:
	int kolplavn;
	int ves; 
public:
	Fish(char*, char*, int, int);
	~Fish();
	void show();
};

class Bird :public Animal {
private:
	int razmah;
	char* color;
public:
	Bird(char*, char*, int, char*);
	~Bird();
	void show();
};

int menu();
int getInt();

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char nam[80], mesto[80], tp[80], clr[80];
	int pr, kol, vib;
	double vs, rz;
	while (true) {
		vib = menu();
		if (vib == 0) {
			cout << "Название: ";
			cin.getline(nam, 80, '\n');
			cout << "Место обитания: ";
			cin.getline(mesto, 80, '\n');
			cout << "Введите тип питания: ";
			cin.getline(tp, 80, '\n');
			cout << "Продолжительность жизни(лет): ";
			pr = getInt();
			Mammal ml(nam, mesto, tp, pr);
			ml.show();
		}
		else if (vib == 1) {
			cout << "Название: ";
			cin.getline(nam, 80, '\n');
			cout << "Место обитания: ";
			cin.getline(mesto, 80, '\n');
			cout << "Количество плавников: ";
			kol = getInt();
			cout << "Вес(гр): ";
			vs = getInt();
			Fish rb(nam, mesto, kol, vs);
			rb.show();
		}
		else if (vib == 2) {
			cin.clear();
			cout << "Название: ";
			cin.getline(nam, 80, '\n');
			cout << "Место обитания: ";
			cin.getline(mesto, 80, '\n');
			cout << "Размах крыльев(см): ";
			rz = getInt();
			cout << "Цвет: ";
			cin.getline(clr, 80, '\n');
			Bird bd(nam, mesto, rz, clr);
			bd.show();
		}
		else break;
		system("pause");
	}
	return 0;
}

Animal::Animal(char* n, char* m) {
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
	ms = new char[strlen(m) + 1];
	strcpy_s(ms, strlen(m) + 1, m);
}

Animal::~Animal() {
	delete[] name;
	delete[] ms;
}

Mammal::Mammal(char* n, char* m, char* p, int a) :Animal(n, m) {
	pt = new char[strlen(p) + 1];
	strcpy_s(pt, strlen(p) + 1, p);
	age = a;
}

void Mammal::show() {
	cout << endl;
	system("cls");
	cout << "Млекопитающее\n" << "Название: " << name << endl
		<< "Место обитания: " << ms << endl
		<< "Тип питания: " << pt << endl
		<< "Продолжительность жизни: " << age << " лет" <<  endl;
}

Mammal::~Mammal() {
	delete[] pt;
}

Fish::Fish(char* n, char* m, int k, int v) :Animal(n, m) {
	kolplavn = k;
	ves = v;
}

void Fish::show() {
	cout << endl;
	system("cls");
	cout << "Рыба\n" << "Название: " << name << endl
		<< "Место обитания: " << ms << endl
		<< "Количество плавников: " << kolplavn << endl
		<< "Вес: " << ves << " гр" << endl;
}

Fish::~Fish() {

}

Bird::Bird(char* n, char* m, int r, char* c) :Animal(n, m) {
	razmah = r;
	color = new char[strlen(c) + 1];
	strcpy_s(color, strlen(c) + 1, c);
}

void Bird::show() {
	cout << endl;
	system("cls");
	cout << "Птица\n" << "Название: " << name << endl
		<< "Место обитания: " << ms << endl
		<< "Размах крыльев: " << razmah << " см" << endl
		<< "Цвет: " << color << endl;
}

Bird::~Bird() {
	delete[] color;
}

int menu()
{
	int choiceButton = 0, button = 0;
	system("cls");
	while (true)
	{
		choiceButton = (choiceButton + 4) % 4;

		if (choiceButton == 0) cout << "->Млекопитающие" << endl;
		else cout << "Млекопитающие" << endl;

		if (choiceButton == 1) cout << "->Рыбы" << endl;
		else cout << "Рыбы" << endl;

		if (choiceButton == 2) cout << "->Птицы" << endl;
		else cout << "Птицы" << endl;

		if (choiceButton == 3) cout << "->Выход" << endl;
		else cout << "Выход" << endl;

		button = _getch();
		if (button == 224)
		{
			button = _getch();
			if (button == 72) choiceButton--;
			if (button == 80) choiceButton++;
		}
		if (button == 13) {
			system("cls");
			return choiceButton;
		}

		system("cls");
	}
}

int getInt() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	cout << endl;
	return stoi(numbers);
}
