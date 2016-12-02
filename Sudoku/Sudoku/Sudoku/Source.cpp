#include <iostream>
#include <string>

int checking_values(int size, int table[][9], bool &duplicate, int value, int letter, int number);
int preparing_table(int size, int table[][9]) {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			table[i][j] = 0;
		}
	}
	return 0;
}
int present_sudoku(int size, int table[][9]) {
	std::string letter = "A";
	for (int i = 0; i < 9; i++)
	{
		if (i == 0) {
			std::cout << "   1 2 3  4 5 6  7 8 9" << std::endl << std::endl;
		}
		if (i == 3 || i == 6)std::cout << std::endl;
		std::cout << letter << "  ";
		letter = letter[0] + 1;
		for (int j = 0; j < 9; j++)
		{
			std::cout << table[i][j] << " ";
			if (j == 2 || j == 5) std::cout << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
int getting_data(int size, int sudoku[][9]) {
	bool duplicate = false;
	std::string coords;
	bool check_value = false;
	std::string decision;
	int check_coords = 0;
	int value=0;
	std::string gotten_value;
	int letter;
	int number;
	do {
		do {
			check_coords = 0;
			std::cout << std::endl << "Podaj duza litere i numer komorki, zatwierdz, klikajac enter" << std::endl;
			std::cin >> coords;
			if (coords[0] >= 'A' && coords[0] <= 'I') {
				check_coords++;
			}
			else {
				system("CLS");
				present_sudoku(9, sudoku);
				std::cout << "Wpisz poprawnie nazwe komorki, ktora zaczyna sie od duzej litery od A do I" << std::endl;
			}
			if (coords[1] >= '0' && coords[1] <= '9') {
				check_coords++;
			}
			else {
				system("CLS");
				present_sudoku(9, sudoku);
				std::cout << "Wpisz poprawnie nazwe komorki, ktora konczy sie cyfra od 1 do 9" << std::endl;
			}
		} while (check_coords != 2);
		letter = (coords[0] - 'A');
		number = (coords[1] - '1');
		do {
			duplicate = false;
			check_value = false;
			std::cout << "Wpisz wartosc komorki, lub wpisz 0 jesli chcesz wykasowac zawartosc komorki, zatwierdz, kikajac enter" << std::endl;
			std::cin >> gotten_value;
			if (gotten_value[0] >= '0' && gotten_value[0] <= '9') {
				check_value = true;
				value = gotten_value[0] - '0';
			}
			else {
				std::cout << "Wpisz wartosc od 1 do 9, lub 0 jesli chcesz wykasowac wartosc" << std::endl;
			}
			checking_values(9, sudoku, duplicate, value, letter, number);
			if (duplicate == true) std::cout << "Wpisana wartosc zostala juz wpisana w innym miejscu i koliduje z wczesniej wpisana" << std::endl << "Prosze wybrac inna wartosc" << std::endl;
		} while (check_value == false || duplicate == true);
		system("CLS");
		sudoku[letter][number] = value;
		do {
			present_sudoku(9, sudoku);
			std::cout << "Czy chcesz wpisac koleja wartosc?" << std::endl << "Jesli tak wpisz 1, jesli nie wpisz 0, zatwierdz klikajac enter" << std::endl;
			std::cin >> decision;
			if (decision[0] != '1' && decision[0] != '0') {
				system("CLS");
				std::cout << "Wybierz opcje sposrod podanych (1-wpisz nastepna liczbe 0-zakoncz wpisywanie liczb)" << std::endl;
			}
		} while (decision[0] != '1' && decision[0] != '0');
	} while (decision[0] == '1');
	return 0;
}
int checking_values(int size, int table[][9], bool &duplicate, int value, int letter, int number) {
	for (int h = 0; h < 9; h++) {
		if (table[h][number] == value) duplicate = true;								//KOLUMNA
	}
	for (int h = 0; h < 9; h++) {
		if (table[letter][h] == value) duplicate = true;								//WIERSZ
	}
	if (letter < 3 && number < 3) {														//1 KWADRACIK
		for (int n = 0; n < 3; n++) {
			for (int m = 0; m < 3; m++) {
				if (table[n][m] == value) duplicate = true;
			}
		}
	}
	if (letter< 3 && number < 6 && number>2) {											//2 KWADRACIK
		for (int n = 0; n < 3; n++) {
			for (int m = 3; m < 6; m++) {
				if (table[n][m] == value) duplicate = true;
			}
		}
	}
	if (letter< 3 && number < 9 && number>5) {											//3 KWADRACIK
		for (int n = 0; n < 3; n++) {
			for (int m = 6; m < 9; m++) {
				if (table[n][m] == value) duplicate = true;
			}
		}
	}
	if (letter< 6 && letter>2 && number< 3) {											//4 KWADRACIK
		for (int n = 3; n < 6; n++) {
			for (int m = 0; m < 3; m++) {
				if (table[n][m] == value) duplicate = true;
			}
		}
	}
	if (letter< 6 && letter>2 && number< 6 && number>2) {								//5 KWADRACIK
		for (int n = 3; n < 6; n++) {
			for (int m = 3; m < 6; m++) {
				if (table[n][m] == value) duplicate = true;
			}
		}
	}
	if (letter< 6 && letter>2 && number < 9 && number>5) {								//6 KWADRACIK
		for (int n = 3; n < 6; n++) {
			for (int m = 6; m < 9; m++) {
				if (table[n][m] == value) duplicate = true;
			}
		}
	}
	if (letter< 9 && letter>5 && number < 3) {											//7 KWADRACIK
		for (int n = 6; n < 9; n++) {
			for (int m = 0; m < 3; m++) {
				if (table[n][m] == value) duplicate = true;
			}
		}
	}
	if (letter< 9 && letter>5 && number < 6 && number>2) {								//8 KWADRACIK
		for (int n = 6; n < 9; n++) {
			for (int m = 3; m < 6; m++) {
				if (table[n][m] == value) duplicate = true;
			}
		}
	}if (letter< 9 && letter>5 && number< 9 && number>5) {								//9 KWADRACIK
		for (int n = 6; n < 9; n++) {
			for (int m = 6; m < 9; m++) {
				if (table[n][m] == value) duplicate = true;
			}
		}
	}
	return 0;
}
int transfer_data_from_tab_to_tab(int size, int tab1[][9], int tab2[][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			tab1[i][j] = tab2[i][j];
		}
	}
	return 0;
}
int solving_sudoku(int size, int sudoku[][9]) {
	
	int workingspace[9][9];
	transfer_data_from_tab_to_tab(9, workingspace, sudoku);
	bool gettingback = false;
	bool change = false;
	int testvalue = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			testvalue = 1;
			do {
				change = false;
				if (gettingback == true) {
					j = j - 1;
					if (j == -1) {
						i = i - 1;
						j = 8;
					}
					if (i == -1) {
						std::cout << std::endl << "Nie da siê rozwi¹zaæ tego sudoku" << std::endl;
						std::cout << std::endl << "Nacisnij enter aby kontynuowac" << std::endl;
						std::getchar();
						std::getchar();
						return 0;
					}
					if (sudoku[i][j] != 0) {
						gettingback = true;
						change = true;
					}
					else {
						testvalue = workingspace[i][j] + 1;
						workingspace[i][j] = 0;
						gettingback = false;
						if (testvalue == 10) {
							gettingback = true;
							change = true;
						}
					}
				}
				if (workingspace[i][j] == 0 && gettingback == false) {
					checking_values(9, workingspace, change, testvalue, i, j);
					if (change == false)
					{
						workingspace[i][j] = testvalue;

					}
					testvalue++;
					if (testvalue == 10 && workingspace[i][j] != 9) gettingback = true;
				}
			} while (change == true);
		}
	}
	transfer_data_from_tab_to_tab(9, sudoku, workingspace);
	return 0;
}
int main()
{
	int sudoku[9][9];
	std::cout << "Witamy w programie rozwiazujacym sudoku" << std::endl << "Nacisnij enter aby kontynuowac" << std::endl;
	std::getchar();
	system("CLS");
	preparing_table(9, sudoku);
	present_sudoku(9, sudoku);
	getting_data(9, sudoku);
	system("CLS");
	std::cout << "Zadane sudoku wyglada nastepujaco" << std::endl;
	present_sudoku(9, sudoku);
	////////////////////////////////////////////////////////////
	///////////////////2czesc programu//////////////////////////
	////////////////////////////////////////////////////////////
	solving_sudoku(9, sudoku);
	std::cout << std::endl << std::endl<<"Rozwiazaniem zadanego sudoku jest:"<<std::endl;
	present_sudoku(9, sudoku);
	std::cout << std::endl << "Nacisnij enter aby zakonczyc" << std::endl;
	std::getchar();
	std::getchar();
	return 0;
}