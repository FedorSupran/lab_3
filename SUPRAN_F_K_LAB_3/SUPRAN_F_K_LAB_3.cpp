#include <iostream>
#include <string>
#include <vector>
#include <functional>
/*
* Третья лабораторная работа
* Автор: Супран Федор Константинович
* Группа: ПИ2-2
*/

/*
* Исключение из массива всех отрицательных чисел.
*/
void deleteElementFromArray(int*& arr, int& size, int index) // Удаление элемента из динамического массива
{
	int* newArr = new int[size - 1];
	for (size_t i = 0; i < size; i++)
	{
		if (i < index)
			newArr[i] = arr[i];
		else if (i > index)
			newArr[i - 1] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	size--;
}
void func1()
{
	system("cls");
	int size;
	std::cout << "Введите размер массива: ";
	std::cin >> size;
	int* arr = new int[size];
	std::cout << "Введите элементы массива: ";
	for (size_t i = 0; i < size; i++) // Ввод массива
		std::cin >> arr[i];
	for (size_t i = 0; i < size;) // Удаление отрицательных элементов
	{
		if (arr[i] < 0)
			deleteElementFromArray(arr, size, i);
		else
			i++;
	}
	for (size_t i = 0; i < size; i++) // Вывод массива
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	std::cout << "Для возврата в меню нажмите любую клавишу...";
	std::cin.ignore();
	std::cin.get();
}
/*
* Нахождение всех гласных в строке и вывод их на экран.
* Примечание:
* 1) Поиск происходит по английским гласным
*/
void func2()
{
	system("cls");
	const int VOWEL_ENG_SIZE = 6, VOWEL_RUS_SIZE = 10;
	char vowelEng[VOWEL_ENG_SIZE] = { 'a', 'e', 'i', 'o', 'u', 'y' };
	std::string str;
	std::cout << "Введите строку: ";
	std::cin.ignore();
	std::getline(std::cin, str);
	std::cout << "Гласные в строке: ";
	for (size_t i = 0; i < str.length(); i++)
	{
		for (size_t j = 0; j < VOWEL_ENG_SIZE; j++)
		{
			if (str[i] == vowelEng[j])
			{
				std::cout << str[i] << " ";
				break;
			}
		}
	}
	std::cout << std::endl;

	std::cout << "Для возврата в меню нажмите любую клавишу...";
	std::cin.get();
}
/*
* Меню для выбора функций
*/
void showMenu(std::vector<std::string> titleVector, std::vector<std::function<void()>> fVector)
{
	while (true)
	{
		system("cls");
		int choice = 0;
		std::cout << "============================\n";
		std::cout << "============Меню============\n";
		std::cout << "============================\n";
		for (size_t i = 0; i < titleVector.size(); i++)
			std::cout << i + 1 << ") " << titleVector[i] << std::endl;
		std::cout << "Введите номер выбранной задачи: ";
		std::cin >> choice;
		if (choice - 1 < 0 || choice - 1 >= titleVector.size())
			break;
		else
			fVector[choice - 1]();
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	std::vector<std::string> titleVector =
	{
		"Исключение из массива всех отрицательных чисел.",
		"Нахождение всех гласных в строке и вывод их на экран."
	};
	std::vector<std::function<void()>> fVector = { func1, func2 };
	showMenu(titleVector, fVector);
	return 0;
}