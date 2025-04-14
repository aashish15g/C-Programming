//----------------------------------------------------
// Author: Aashish Ganeshkumar
// Purpose: Test program for Dictionary Class
//----------------------------------------------------
#include <iostream>
#include "Dictionary.h"
using namespace std;   

//---------------------------------------------------------------------------
// Name: MainMenu
// Parameters: none
// Returns: none
// Purpose: This function prints the main menu 
//---------------------------------------------------------------------------
void MainMenu() 
{
   cout << endl;
   cout << "Welcome to the English-Spanish Translation Dictionary";
   cout << endl << "Choose one of the following:" << endl;

   cout << "      0 Load the dictionary by reading from a file\n"
        << "      1 Translate a word from English to Spanish\n"
        << "      2 Translate a word from Spanish to English\n"
        << "      3 Add an English-Spanish pair to the dictionary\n"
        << "      4 Remove an English-Spanish pair from the dictionary\n"
        << "      5 Print the contents of the dictionary\n"
        << "      6 Quit the program\n";
   cout << endl;
}


//---------------------------------------------
// Name:  GetChoice
// Purpose:  Collect a number between 0 and 6 from the user
//           Do error checking to reject invalid values
// Parameters:  None
// Returns: int, a valid value entered by the user
//---------------------------------------------
int GetChoice() 
{
   char choice;  
   int intChoice;

   // read into a character for safety
   cout << "Enter choice: ";   
   cin >> choice;   
 
   while (choice < '0' || choice > '6')
   {
      cout << "Sorry, that was not a valid valid. Try again: ";   
      cin >> choice;   
   }

   // Convert character to integer
   intChoice = choice - '0';
   return (intChoice);
}

// UNCOMMENT TO TEST PROGRAM
//----------------------------------------------------
// Purpose: Add English-Spanish pair from dictionary
// Argument: A Dictionary object (pass by reference)
// Returns: none
//----------------------------------------------------
void addPair(Dictionary &dict)
{
   string English;
   string Spanish;

   cout << "Enter an English word: ";
   cin >> English;

   cout << "Enter a Spanish translation of the English word above: ";
   cin >> Spanish;

   if (dict.addPair(English, Spanish))
      cout << "The English-Spanish pair was added to the dictionary!" << endl;
   else
      cout << "Error. The pair could not be added to the dictionary." << endl;
}

//----------------------------------------------------
// Purpose: Remove English-Spanish pair from dictionary
// Argument: A Dictionary object (pass by reference)
// Returns: none
//----------------------------------------------------
void removePair(Dictionary &dict)
{
   int position;

   cout << "Enter the index of the pair to remove: ";
   cin >> position;
   if (dict.removePair(position))
      cout << "The English-Spanish pair was removed from the dictionary!" << endl;
   else
      cout << "Error. The information could not be removed from the dictionary." << endl;
}

int main()
{
   Dictionary dict;
   string Query;
   string English, Spanish;

   //print main menu here
   //While the user does not wish to exit the program
   MainMenu();
   char choice = GetChoice();
   while (choice != 6)
   {
      switch (choice)
      {
         case 0: // LOAD DICTIONARY FROM THE FILE
            if (dict.readDictionary())
               cout << "The dictionary was successfully loaded." << endl;
            else
               cout << " The dictionary failed to load." << endl;
            break;
         case 1: // TRANSLATE FROM ENGLISH TO SPANISH
            cout << "Enter an English word for translation: ";
            cin >> English;
            if (!dict.getSpanish(English, Spanish))
               cout << English << " is not in our dictionary.\n";
            else 
               cout << "The English word \"" << English << "\" is \"" << Spanish <<  "\" in Spanish.\n";
            break;
         case 2: // TRANSLATE FROM SPANISH TO ENGLISH
            cout << "Enter an Spanish word for translation: ";
            cin >> Spanish;

            if (!dict.getEnglish(Spanish, English))
               cout << Spanish << " is not in our dictionary.\n";
            else 
               cout << "The Spanish word \"" << Spanish << "\" is \"" << English <<  "\" in English.\n";
            break;
         case 3: // ADD ENGLISH-SPANISH WORD PAIR TO DICTIONARY
            addPair(dict);
            break;
         case 4: // REMOVE ENGLISH-SPANISH WORD PAIR FROM DICTIONARY
            removePair(dict);
            break;
         case 5: // PRINT CONTENTS OF DICTIONARY TO CONSOLE
            dict.Print();
            break;
      } // end switch
   
      // get next choice
      MainMenu();
      choice = GetChoice();
   } 

   // TEST THE COPY CONSTRUCTOR FUNCTIONALITY
   Dictionary dict2(dict);
   cout << "Copy of the translation dictionary at time of exit:\n";
   dict2.Print();
   return 0;
}
