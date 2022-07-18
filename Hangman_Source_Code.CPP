#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>

int check_word(char, char[], char[]);
void hide_word(char[], char[]);
void hangman(int);

void main()
{
clrscr();
const int max_tries=7;
char unknown [40],guess,word[40],choice='y';
int num_of_wrong_guesses=0;
char words[][40] =
{
	"india","nepal","singapore","japan", "australia","china",
	"ethiopia","oman","indonesia","france","germany","mexico",
	"italy","spain"
};
// Welcome the user
cout<<"\n\n------------------------------------------------------------------------------";
cout<<"\n\n\t\t\t----------WELCOME TO HANGMAN---------";
cout<<"\n\n------------------------------------------------------------------------------";
cout<<"\n\n\tHOW TO PLAY: ";
cout<<"\n\n\t1.Guess a country Name";
cout<<"\n\n\t2.Each letter is represented by a star.";
cout<<"\n\n\t3.You have to type only one letter in one try";
cout<<"\n\n\t4.You have " <<max_tries<< " tries to try and guess the word.";
cout<<"\n--------------------------------------------------------------------------------";

while(choice=='y'||choice=='Y')
{
 //choose and copy a word from array of words randomly
 randomize();
 int n=random(14);
 strcpy(word,words[n]);

 // Initialize the secret word with the * character.
 hide_word(word, unknown);

 // Loop until the guesses are used up
 while (num_of_wrong_guesses < max_tries)
 {
   cout<<"\n\n\t\t" << unknown;
   cout<<"\n\n\t\tGuess a letter: ";
   cin>>guess;
   guess=tolower(guess);

   /*Fill secret word with letter if the guess is correct,
     otherwise increment the number of wrong guesses.*/
   if(check_word(guess, word, unknown)==0)
    {
      cout<<"\n\t\tOOPS!! Its a wrong guess.";
      cout<<"\n\t\tThat letter isn't there!"<<endl;
      num_of_wrong_guesses++;
      hangman(num_of_wrong_guesses);
    }
   else
    {
      cout <<"\n\t\tWOW!! You have found a letter!\n";
    }

   //Tell user how many guesses has left.
   cout<<"\t\tYou have "<<max_tries-num_of_wrong_guesses<<" guesses left\n";
   cout<<"\n---------------------------------------------------------------\n";

   // Check if the word has been guessed.
   if(strcmp(word, unknown) == 0)
   {
      cout <<"\n\t\tThe word is " <<word<<endl;
      cout <<"\t\tYeah! Its amazing!! You got it right.";
      break;
   }
}
if(num_of_wrong_guesses==max_tries)
 {
   cout<<"\n\t\tSorry, you lose...\n";
   cout<<"\t\tYou have been hanged."<<endl;
   cout<<"\t\tThe word was : "<<word<<endl;
 }

cout<<"\n\t\tDo you want play again: ";
cin>>choice;
}

cout<<"\n\n---------------------------THANK YOU FOR PLAYING----------------------\n\n";
getch();
}

/* Checks if the letter taken is present in word or not and
   returns the no of letters matched.Returns zero if letter
   has been already matched   */

int check_word(char letter, char secretword[], char guessword[])
{
  int i;
  int char_matched=0;
  for(i=0;i<strlen(secretword);i++)
   {
    //Is the character already guessed
	if (letter==guessword[i])
	   return 0;
   // Is the guess in the secret word?
	if (letter== secretword[i])
	 {
	    guessword[i] = letter;
	    char_matched++;
	 }
   }
 return char_matched;
}

// Initialize the unknown word with stars

void hide_word(char word_1[], char unknown_1[])
{
  int i;
  for(i=0;i<strlen(word_1);i++)
	unknown_1[i]='*';
  unknown_1[i]='\0';
}

void hangman(int wrong_guess)
 {
	if(wrong_guess== 0)
	{
	  cout <<"\t\t     ______                     \n"
		 "\t\t    |      |                    \n"
		 "\t\t    |      :                    \n"
		 "\t\t    |                           \n"
		 "\t\t    |                           \n"
		 "\t\t    |                           \n"
		 "\t\t ___|___                        \n\n\n";
	}
	else if (wrong_guess== 1)
	 {
	  cout <<"\t\t     ______                     \n"
		 "\t\t    |      |                    \n"
		 "\t\t    |      :                    \n"
		 "\t\t    |      O                    \n"
		 "\t\t    |                           \n"
		 "\t\t    |                           \n"
		 "\t\t ___|___                        \n\n\n";
	}
	else if (wrong_guess== 2)
	 {
	cout << "\t\t     ______                     \n"
		"\t\t    |      |                    \n"
		"\t\t    |      :                    \n"
		"\t\t    |      O                    \n"
		"\t\t    |      |                    \n"
		"\t\t    |                           \n"
		"\t\t ___|___                        \n\n\n";
	}
	else if (wrong_guess== 3)
	{
	  cout<<"\t\t     ______                     \n"
		"\t\t    |      |                    \n"
		"\t\t    |      :                    \n"
		"\t\t    |      O                    \n"
		"\t\t    |      |\\                   \n"
		"\t\t    |                           \n"
		"\t\t ___|___                        \n\n\n";
	}
	else if (wrong_guess==4)
	{
	  cout<<"\t\t     ______                     \n"
		"\t\t    |      |                    \n"
		"\t\t    |      :                    \n"
		"\t\t    |      O                    \n"
		"\t\t    |     /|\\                   \n"
		"\t\t    |                           \n"
		"\t\t ___|___                        \n\n\n";
	}
	else if (wrong_guess==5)
	 {
	  cout<<"\t\t     ______                     \n"
		"\t\t    |      |                    \n"
		"\t\t    |      :                    \n"
		"\t\t    |      O                    \n"
		"\t\t    |     /|\\                   \n"
		"\t\t    |     /                     \n"
		"\t\t ___|___                        \n\n\n";
	}
	else if (wrong_guess== 6)
	{
	  cout<<"\t\t     ______                     \n"
		"\t\t    |      |                    \n"
		"\t\t    |      :                    \n"
		"\t\t    |      O                    \n"
		"\t\t    |     /|\\                   \n"
		"\t\t    |     / \\                  \n"
		"\t\t ___|___                        \n\n\n";

	}
	else if (wrong_guess==7)
	 {
	  cout<<"\t\t     ______                     \n"
		"\t\t    |      |                    \n"
		"\t\t    |      :                    \n"
		"\t\t    |      O                    \n"
		"\t\t    |     ---                   \n"
		"\t\t    |     /|\\                   \n"
		"\t\t    |     / \\                   \n"
		"\t\t ___|___                        \n\n\n";
	 }

  }

