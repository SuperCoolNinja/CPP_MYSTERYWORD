#include <iostream>//Used for the console.
#include <string> //Used for use string.
#include <ctime> //Used for time (Get Random Number).
#include <stdio.h> //Used for time (Get Random Number).
#include <windows.h> //Used for clean the console.

//CLEAN THE CONSOLE :
void pos(short C, short R)
{
	COORD xy;
	xy.X = C;
	xy.Y = R;
	SetConsoleCursorPosition(
	GetStdHandle(STD_OUTPUT_HANDLE), xy);
}
void cls()
{
	pos(0, 0);
	for (int j = 0; j < 100; j++)
	std::cout << std::string(100, ' ');
	pos(0, 0);
}

//Random Letter:
std::string RandomLetter(std::string letter)
{
	std::string wordMix;
	int position(0);
	
	while (letter.size() != 0)
	{
		position = rand() % letter.size();
		wordMix += letter[position];
		letter.erase(position, 1);
	}

	return wordMix;
}


int main()
{
	//Init Random number : 
	srand(time(0));

	//Some variable :
	std::string mysteryWord, getUtilWord;

	char response(0);

	//Ask the player to find the correct word with 3 luck :
	do {
		//Ask the user to enter a word :
		std::cout << "Please enter a word to find : ";
		std::cin >> mysteryWord;

		//Randomise our mysteryWord :
		std::string newWord = RandomLetter(mysteryWord);

		cls();

		//3 Luck to find the correct word :
		for (int i = 3; i >= 1; i--)
		{
			std::cout << "What is this word -> " << newWord << " ["<< i <<" Luck Remaining] : ";
			std::cin >> getUtilWord;

			//Show to the player when he lose :
			

			if (getUtilWord == mysteryWord)
			{
				std::cout << "Bravo ! You find it.\n";
				break;
			}
		}
		
		//If he past his 3 luck we ask the player if he want play again :
		if (getUtilWord != mysteryWord)
		{
			std::cout << "You lose ! \n";
		}
		std::cout << "Do you wanna play again ? o/n : ";
		std::cin >> response;
		cls();
	} while (response == 'o');

	return 0;
}