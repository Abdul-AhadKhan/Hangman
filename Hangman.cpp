#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	int totalLetters = 0;
	ifstream fin;
	srand(time(0));
	int word_no = 1;
	char hidden_word[30] = {};
	int count = 1;
	fin.open("Hangman.txt");
	while (!fin.eof())
	{
		fin >> hidden_word;
		totalLetters++;
	}
	fin.close();
	fin.open("Hangman.txt");
	word_no = (rand() % totalLetters) + 1;
	while (count <= word_no)
	{
		fin >> hidden_word;
		count++;
	}
	char* user_word;
	int length1 = 0;
	int mistakes = 6;
	bool win = false;
	char letter;
	length1 = strlen(hidden_word);
	user_word = new char[length1 + 1];
	for (int i = 0; i < length1; i++)
	{
		user_word[i] = '*';
		cout << user_word[i] << " ";
	}
	cout << endl;
	user_word[length1] = '\0';
	while (!win && mistakes >= 0)
	{
		cout << "Enter a letter ";
		cin >> letter;
		if (letter >= 65 && letter <= 90)
		{
			letter += 32;
		}
		count = 0;
		for (int i = 0; hidden_word[i] != '\0'; i++)
		{
			if (hidden_word[i] == letter)
			{
				user_word[i] = letter;
				count++;
			}
		}
		for (int i = 0; hidden_word[i] != '\0'; i++)
		{
			if (hidden_word[i] == user_word[i])
			{
				win = true;
			}
			else
			{
				win = false;
				break;
			}
		}
		if (win)
		{
			cout << "YOU HAVE WON" << endl;
			cout << "YOU GUESSED THE WORD CORRECTLY" << endl;
			for (int i = 0; i < length1; i++)
			{
				cout << user_word[i] << " ";
			}
			cout << " was the correct word" << endl;
			break;
		}
		for (int i = 0; i < length1; i++)
		{
			cout << user_word[i] << " ";
		}
		cout << endl;
		if (count == 0)
		{
			mistakes--;
		}
		if(!win)
			cout << "Mistakes = " << mistakes << endl;

	}
	if (mistakes == -1 && !win)
	{
		cout << "YOU LOST !!!" << endl;
		cout << "The original word is " << hidden_word << endl;
	}
	fin.close();
	system("pause");
	return 0;
}