#include <iostream>
#include <string>


int main()
{
	std::string coords;
	bool checkv = false;
	std::string decision;
	int check = 0;
	int value = 0;
	int sudoku[9][9];
	std::string letter = "A";
	bool duplicate = false;
	std::cout << "Witamy w programie rozwiazujacym sudoku" << std::endl << "Nacisnij enter aby kontynuowac" << std::endl;
	std::getchar();
	system("CLS");
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
			sudoku[i][j] = 0;
			std::cout << sudoku[i][j] << " ";
			if (j == 2 || j == 5) std::cout << " ";
		}
		std::cout << std::endl;
	}

	do {
		do {
			check = 0;
			std::cout << std::endl << "Podaj duza litere i numer komorki, zatwierdz, klikajac enter" << std::endl;
			std::cin >> coords;
			if (coords[0] >= 'A' && coords[0] <= 'I') {
				check++;
			}
			else {
				system("CLS");
				std::cout << "Wpisz poprawnie nazwe komorki, ktora zaczyna sie od duzej litery od A do I" << std::endl;
			}
			if (coords[1] >= '0' && coords[1] <= '9') {
				check++;
			}
			else {
				system("CLS");
				std::cout << "Wpisz poprawnie nazwe komorki, ktora konczy sie cyfra od 1 do 9" << std::endl;
			}
		} while (check != 2);
		do {
			duplicate = false;
			checkv = false;
			std::cout << "Wpisz wartosc komorki, lub wpisz 0 jesli chcesz wykasowac zawartosc komorki, zatwierdz, kikajac enter" << std::endl;
			std::cin >> value;
			if (value >= 0 && value <= 9) {
				checkv = true;
			}
			else {
				std::cout << "Wpisz wartosc od 1 do 9, lub 0 jesli chcesz wykasowac wartosc" << std::endl;
			}
			for (int h = 0; h < 9; h++) {
							if (sudoku[h][coords[1] - '1'] == value) duplicate = true;				//KOLUMNA
						}
						for (int h = 0; h < 9; h++) {
							if (sudoku[coords[0] - 'A'][h] ==value) duplicate = true;				//WIERSZ
						}
						if (coords[0] - 'A' < 3 && coords[1] - '1' < 3) {												//1 KWADRACIK
							for (int n = 0; n < 3; n++) {
								for (int m = 0; m < 3; m++) {
									if (sudoku[n][m] == value) duplicate = true;
								}
							}
						}
						if (coords[0] - 'A' < 3 && coords[1] - '1' < 6 && coords[1] - '1'>2) {												//2 KWADRACIK
							for (int n = 0; n < 3; n++) {
								for (int m = 3; m < 6; m++) {
									if (sudoku[n][m] == value) duplicate = true;
								}
							}
						}
						if (coords[0] - 'A' < 3 && coords[1] - '1' < 9 && coords[1] - '1'>5) {												//3 KWADRACIK
							for (int n = 0; n < 3; n++) {
								for (int m = 6; m < 9; m++) {
									if (sudoku[n][m] == value) duplicate = true;
								}
							}
						}
						if (coords[0] - 'A' < 6 && coords[0] - 'A'>2 &&  coords[1] - '1'< 3) {												//4 KWADRACIK
							for (int n = 3; n < 6; n++) {
								for (int m = 0; m < 3; m++) {
									if (sudoku[n][m] == value) duplicate = true;
								}
							}
						}
						if (coords[0] - 'A' < 6 && coords[0] - 'A'>2 && coords[1] - '1' < 6 && coords[1] - '1'>2) {												//5 KWADRACIK
							for (int n = 3; n < 6; n++) {
								for (int m = 3; m < 6; m++) {
									if (sudoku[n][m] == value) duplicate = true;
								}
							}
						}
						if (coords[0] - 'A' < 6 && coords[0] - 'A'>2 && coords[1] - '1' < 9 && coords[1] - '1'>5) {												//6 KWADRACIK
							for (int n = 3; n < 6; n++) {
								for (int m = 6; m < 9; m++) {
									if (sudoku[n][m] == value) duplicate = true;
								}
							}
						}
						if (coords[0] - 'A' < 9 && coords[0] - 'A'>5 && coords[1] - '1' < 3) {												//7 KWADRACIK
							for (int n = 6; n < 9; n++) {
								for (int m = 0; m < 3; m++) {
									if (sudoku[n][m] == value) duplicate = true;
								}
							}
						}
						if (coords[0] - 'A' < 9 && coords[0] - 'A'>5 && coords[1] - '1' < 6 && coords[1] - '1'>2) {												//8 KWADRACIK
							for (int n = 6; n < 9; n++) {
								for (int m = 3; m < 6; m++) {
									if (sudoku[n][m] == value) duplicate = true;
								}
							}
						}if (coords[0] - 'A' < 9 && coords[0] - 'A'>5 && coords[1] - '1' < 9 && coords[1] - '1'>5) {												//9 KWADRACIK
							for (int n = 6; n < 9; n++) {
								for (int m = 6; m < 9; m++) {
									if (sudoku[n][m] == value) duplicate = true;
								}
							}
						}
						if (duplicate == true) std::cout << "Wpisana wartosc zostala juz wpisana w innym miejscu i koliduje z wczesniej wpisana" << std::endl << "Prosze wybrac inna wartosc" << std::endl;
		} while (checkv == false || duplicate==true);
		system("CLS");
		sudoku[coords[0] - 'A'][coords[1] - '1'] = value;
		do {
			letter = 'A';
			for (int i = 0; i < 9; i++)
			{

				if (i == 0) {
					std::cout << "   1 2 3  4 5 6  7 8 9" << std::endl<< std::endl;
				}
				if (i == 3 || i == 6)std::cout << std::endl;
				std::cout << letter << "  ";
				letter = letter[0] + 1;
				for (int j = 0; j < 9; j++)
				{
					std::cout << sudoku[i][j]<<" ";
					if (j == 2 || j == 5) std::cout << " ";
				}
				std::cout << std::endl;
			}
			std::cout << "Czy chcesz wpisac koleja wartosc?" << std::endl << "Jesli tak wpisz 1, jesli nie wpisz 0, zatwierdz klikajac enter" << std::endl;
			std::cin >> decision;
			if (decision[0] != '1' && decision[0] != '0') {
				system("CLS");
				std::cout << "Wybierz opcje sposrod podanych (1-wpisz nastepna liczbe 0-zakoncz wpisywanie liczb)" << std::endl;
			}
		} while (decision[0] != '1' && decision[0] != '0');
	} while (decision[0] == '1');
	system("CLS");
	letter = "A";
	std::cout << "Zadane sudoku wyglada nastepujaco" << std::endl;
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
			std::cout << sudoku[i][j] << " ";
			if (j == 2 || j == 5) std::cout << " ";
		}
		std::cout << std::endl;
	}
	////////////////////////////////////////////////////////////
	///////////////////2czesc programu//////////////////////////
	////////////////////////////////////////////////////////////
	int workingspace[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			workingspace[i][j] = sudoku[i][j];
		}
	}
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
						for (int h = 0; h < 9; h++) {
							if (workingspace[h][j] == testvalue) change = true;				//KOLUMNA
						}
						for (int h = 0; h < 9; h++) {
							if (workingspace[i][h] == testvalue) change = true;				//WIERSZ
						}
						if (i < 3 && j < 3) {												//1 KWADRACIK
							for (int n = 0; n < 3; n++) {
								for (int m = 0; m < 3; m++) {
									if (workingspace[n][m] == testvalue) change = true;
								}
							}
						}
						if (i < 3 && j < 6 && j>2) {												//2 KWADRACIK
							for (int n = 0; n < 3; n++) {
								for (int m = 3; m < 6; m++) {
									if (workingspace[n][m] == testvalue) change = true;
								}
							}
						}
						if (i < 3 && j < 9 && j>5) {												//3 KWADRACIK
							for (int n = 0; n < 3; n++) {
								for (int m = 6; m < 9; m++) {
									if (workingspace[n][m] == testvalue) change = true;
								}
							}
						}
						if (i < 6 && i>2 && j < 3) {												//4 KWADRACIK
							for (int n = 3; n < 6; n++) {
								for (int m = 0; m < 3; m++) {
									if (workingspace[n][m] == testvalue) change = true;
								}
							}
						}
						if (i < 6 && i>2 && j < 6 && j>2) {												//5 KWADRACIK
							for (int n = 3; n < 6; n++) {
								for (int m = 3; m < 6; m++) {
									if (workingspace[n][m] == testvalue) change = true;
								}
							}
						}
						if (i < 6 && i>2 && j < 9 && j>5) {												//6 KWADRACIK
							for (int n = 3; n < 6; n++) {
								for (int m = 6; m < 9; m++) {
									if (workingspace[n][m] == testvalue) change = true;
								}
							}
						}
						if (i < 9 && i>5 && j < 3) {												//7 KWADRACIK
							for (int n = 6; n < 9; n++) {
								for (int m = 0; m < 3; m++) {
									if (workingspace[n][m] == testvalue) change = true;
								}
							}
						}
						if (i < 9 && i>5 && j < 6 && j>2) {												//8 KWADRACIK
							for (int n = 6; n < 9; n++) {
								for (int m = 3; m < 6; m++) {
									if (workingspace[n][m] == testvalue) change = true;
								}
							}
						}if (i < 9 && i>5 && j < 9 && j>5) {												//9 KWADRACIK
							for (int n = 6; n < 9; n++) {
								for (int m = 6; m < 9; m++) {
									if (workingspace[n][m] == testvalue) change = true;
								}
							}
						}
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
	std::cout << std::endl << std::endl<<"Rozwiazaniem zadanego sudoku jest:"<<std::endl;
	letter = 'A';
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
			std::cout << workingspace[i][j] << " ";
			if (j == 2 || j == 5) std::cout << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << "Nacisnij enter aby kontynuowac" << std::endl;
	std::getchar();
	std::getchar();
	return 0;
}