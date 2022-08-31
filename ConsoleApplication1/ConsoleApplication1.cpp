


#include <iostream>
#include <string>
using namespace std;

//Описание живности находящийся внутри области
class Cretures
{
public:
	int time_of_live;
	string name_of_eat;
	string name_of_classification;
	int creature_size;

};

//Описание хищника
class Predator : Cretures
{
	Cretures predator;
	// В Функцию будут педаваться категорию по номеру
	void classification_of_predator(int SoP)
	{
		if (SoP == 1)
		{
			predator.time_of_live = 5;
			predator.name_of_eat = "Meat";
			predator.name_of_classification = "Small";
			predator.creature_size = 1;
		}

		if (SoP == 2)

		{
			predator.time_of_live = 7;
			predator.name_of_eat = "Meat";
			predator.name_of_classification = "Medium";
			predator.creature_size = 2;
		}

		if (SoP == 2)
		{
			predator.time_of_live = 9;
			predator.name_of_eat = "Meat";
			predator.name_of_classification = "Large";
			predator.creature_size = 3;
		}
	}

};

//Логика жизненого цикла
class Live_cycle
{

};

//Описание Травоядных
class Herbivores
{

};

//Наполение области 
class Region
{

protected:
	int x;
	int y;
	int s;
	int** region_place;

public:

	void set_XY()
	{
		int choice1 = 0;
		int value_X, value_Y, value_entity; 
		while (choice1 != 9)
		{
			cout << "You choose function of filling the playing field: " << endl;
			cout << "1) Start generation" << endl;
			cout << "9) Close menu" << endl;
			cout << "Enter your choice: " << endl;
			cin >> choice1;
			if (choice1 == 1)
			{
				cout << "Generation is progress" << endl;
				cout << "Enter value of x: " << endl;
				cin >> value_X;

				cout << "Enter value of y: " << endl;
				cin >> value_Y;

				cout << "Enter number of your animal or herbivores: " << endl;
				//cout << "You have the next type: " << endl; // Расписать легенду карты(Какой символ, каким животным является)

				cin >> value_entity;

				region_place[value_X][value_Y] = value_entity;
				//Запись координат поля

				for (int i = 0; i < x; i++)
				{
					cout << endl;
					for (int j = 0; j < y; j++)
					{
						cout << region_place[i][j] << " ";
					}
					cout << endl;
				};
				cout << endl;
				cout << "======================================================" << endl;

			}



			if (choice1 == 9)
			{
				choice1 = 9;
				break;
			}

			else
			{
				cout << "=========================================================" << endl;
				cout << "You enter wrong choise " << endl;
				cout << "=========================================================" << endl;
			}
		}
	};
	// Функция которая выводит игровое поле
	void show_the_region()
	{
		for (int i = 0; i < x; i++)
		{
			cout << endl;
			for (int j = 0; j < y; j++)
			{
				cout << region_place[i][j] << " ";
			}
			cout << endl;
		}
	};
	//Функция заполнения игрового поля сущностями
	int** region_fill(int x, int y)
	{
		this->x = x;
		this->y = y;

		region_place = new int* [x];

		for (int i = 0; i < x; i++)
		{
			region_place[i] = new int[y];
		}

		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				region_place[i][j] = 0;
			}
		}

		return region_place;

	}

	~Region()
	{
		for (int i = 0; i < x; i++)
		{
			delete[] region_place[i];

		}
		delete[] region_place;
	}

};

//Передвижение по полю
class Position : Region
{

private:
	int** region_place1;
	int entity;

public:

	Position() 
	{

	}

	//Передача дин.массива с одного класса в другой
	Position(int** massiv, int x_size, int y_size)
	{
		region_place1 = massiv;
		x = x_size;
		y = y_size;

	}
	//Функция передвежения
	void rotate()
	{
		int n, m;
		int choice = 1;
		cout << "========================================================" << endl;
		cout << "You choose movement function" << endl;
		cout << "1) Rotate" << endl;
		cout << "9) Close" << endl;
		//Пользователь выбирает существо за которое хочет играть
		cout << "========================================================" << endl;
		cout << "Before start the game, choose your entity. You can choose the foolowing types: " << endl
			<< "Any types from 1-9" << endl;
		cout << "Enter your entity: " << endl;
		cin >> entity;


		while (choice != 9)
		{

			cout << "Enter your choice: " << endl;
			cin >> choice;
			if (choice == 1)
			{

				//запись координат
				cout << "Enter coordinate x: ";
				cin >> n;
				cout << endl;
				cout << "Enter coordinate y: ";
				cin >> m;
				cout << endl;

				cout << n << endl;

				cout << m << endl;

				region_place1[n][m] = entity;

				cout << region_place1[2][4] << endl;

				// Отображение поля после записи координат
				for (int i = 0; i < x; i++)
				{
					cout << endl;
					for (int j = 0; j < y; j++)
					{
						cout << region_place1[i][j] << " ";
					}
					cout << endl;
				}

				//Удаление предыдущего местоположения
				region_place1[n][m] = 0;
			}

			if (choice == 9)
			{
				break;
			}
			else
			{
				cout << "==============================================" << endl;
				cout << "You enter wrong choise " << endl;
				cout << "==============================================" << endl;
			}
		}
	};
};


//Описание растений
class Plants
{
	string name_of_plants;
	int scale_of_plants;

};
//Проверка возраста существа
class Age
{
	//Принцип как в классе хищники
	int how_old(int old_range)
	{
		switch (old_range)
		{
		case 1:
			old_range = 1;
			cout << "Young";
		case 2:
			old_range = 2;
			cout << "Grown";
		case 3:
			old_range = 3;
			cout << "Old";
		}

		return old_range;
	};
};

//Описание голода
class Hunger
{
	//Принцип как в классе хищники
	int how_hunger(int hunger_range)
	{
		switch (hunger_range)
		{
		case 1:
			hunger_range = 1;
			cout << "Not hunger";
		case 2:
			hunger_range = 2;
			cout << "Hunger";
		case 3:
			hunger_range = 3;
			cout << "Very hunger";
		}

		return hunger_range;
	};
};


int main()
{
	Region a;
	int** mass1 =  a.region_fill(20, 20); // Задается поле игры
	a.set_XY(); // Пользователь заполняет поле самостоятельно(Планирую сделать случайную генерацию)

	Position b = Position(mass1,20,20); // Передача поля в класс передвижения
	b.rotate(); //Пользователь передвигается по полю

}