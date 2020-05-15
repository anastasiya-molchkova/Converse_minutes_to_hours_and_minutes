/* Написать программу пересчёта величины временного интервала, заданного в минутах, в величину, 
выраженную в часах и минутах. */

#include <iostream>
#include <clocale>  // для кириллицы

using std::cout; using std::cin; using std::endl;

// получаем от пользователя натуральное число
unsigned get_number()
{
	int answer;
	cin >> answer;
	while (cin.fail() || (answer < 0))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Вы ввели нечто некорректное, введите целое положительное число: ";
		cin >> answer;
	}
	return static_cast<unsigned>(answer);
}

const unsigned short minutes_in_one_hour = 60;

const unsigned hours_calculation(const unsigned time)
{
	return (time / minutes_in_one_hour);
}

const unsigned minutes_calculation(const unsigned time)
{
	return (time % minutes_in_one_hour);
}

int main()
{
	setlocale(LC_CTYPE, "rus"); // для вывода сообщений на кириллице

	while (true)
	{
		cout << "Введите временной интервал (в минутах): ";
		        unsigned time = get_number();
		cout << time << " минут = " << 
			    hours_calculation(time) << " ч. " << minutes_calculation(time) << " м." << endl << endl;
	}

	return 0;
}