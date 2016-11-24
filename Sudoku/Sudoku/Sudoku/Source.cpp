#include <iostream>
#include <string>

int main()
{
	std::string coords;
	bool checkv = false;
	bool decision = true;
	int check = 0;
	int value = 0;
	int sudoku[9][9];
	std::string letter = "A";
	for (int i = 0; i < 9; i++)
	{
		if (i == 0) {
			std::cout << "   1 2 3 4 5 6 7 8 9" << std::endl;
		}
		std::cout << letter << "  ";
		letter = letter[0] + 1;
		for (int j = 0; j < 9; j++)
		{
			sudoku[i][j] = 0;
			std::cout << sudoku[i][j] << " ";
		}
		std::cout << std::endl;
	}

	do {
		do {
			check = 0;
			std::cout << std::endl << "Podaj litere i numer komorki" << std::endl;
			std::cin >> coords;
			if (coords[0] >= 'A' && coords[0] <= 'I') {
				check++;
			}
			else {
				std::cout << "Wpisz poprawnie nazwe komorki, ktora zaczyna sie od duzej litery od A do I" << std::endl;
			}
			if (coords[1] >= '1' && coords[1] <= '9') {
				check++;
			}
			else {
				std::cout << "Wpisz poprawnie nazwe komorki, ktora konczy sie cyfra od 1 do 9" << std::endl;
			}
		} while (check != 2);
		do {
			checkv = false;
			std::cout << "Wpisz wartosc komorki" << std::endl;
			std::cin >> value;
			if (value >= 1 && value <= 9) {
				checkv = true;
			}
			else {
				std::cout << "Wpisz wartosc od 1 do 9" << std::endl;
			}
		} while (checkv == false);
		sudoku[coords[0] - 'A'][coords[1] - '1'] = value;
		std::cout << "Czy chcesz wpisac koleja wartosc?" << std::endl << "Jesli tak wpisz 1, jesli nie wpisz 0" << std::endl;
		std::cin >> decision;
	} while (decision == true);

	letter = "A";
	for (int i = 0; i < 9; i++)
	{
		if (i == 0) {
			std::cout << "   1 2 3 4 5 6 7 8 9" << std::endl;
		}
		std::cout << letter << "  ";
		letter = letter[0] + 1;
		for (int j = 0; j < 9; j++)
		{
			std::cout << sudoku[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}