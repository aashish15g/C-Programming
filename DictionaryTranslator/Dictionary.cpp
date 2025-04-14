//-----------------------------------------------------------
// Author:     Aashish Ganeshkumar
// Purpose:    Uses a Dictionary object to translate
//   between English and Spanish words.
//-----------------------------------------------------------
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Dictionary.h"
using namespace std;

//---------- Constructors and Destructors -------------------
//-----------------------------------------------------------
// Name:  Default Constructor
// Sets all the elements in the dictionary arrays to the empty
// string and sets the number of entries equal to 0.
//-----------------------------------------------------------
Dictionary::Dictionary()
{
    // init all strings to the empty string
    for (int k = 0; k < MAX_ENTRIES; k++)
    {
        english[k] = "";
        spanish[k] = "";
    }
    num_entries = 0;
}

//-----------------------------------------------------------
// Name:  Copy Constructor
// Purpose: Sets the number of entries equal to the passed
//   dictionary. Sets all the entries in the dictionary equal
//   to the passed dictionary's entries.
// Arguments: other Dictionary (pass by value)
//-----------------------------------------------------------
Dictionary::Dictionary(const Dictionary &other)
{
    num_entries = other.num_entries;
    for (int k = 0; k < num_entries; k++)
    {
        english[k] = other.english[k];
        spanish[k] = other.spanish[k];
    }
    // copy the other dictionary's instance variables
    // i.e., copy num_entries and the two arrays
    // cout << "Copy Contructor\n"; // remove when method completed
}

//-----------------------------------------------------------
// Name:  Destructor
// This does nothing since there is no dynamic memory.
//-----------------------------------------------------------
Dictionary::~Dictionary()
{
    cout << "Destructor.\n";
}

//------------------ Mutators -------------------
//-----------------------------------------------------------
// Name: readDictionary
// Purpose: Fills in the dictionary with contents
// Arguments: none
// Return:   True if the file opened successfully and
//   the dictionary arrays were successfully
//   populated. False otherwise.
//-----------------------------------------------------------
bool Dictionary::readDictionary()
{

    bool success = true;
    ifstream Din(FILENAME.c_str());
    if (!Din)
    {
        return false;
    }

    num_entries = 0;
    while (Din >> english[num_entries] >> spanish[num_entries])
    {
        num_entries++;
        if (num_entries == MAX_ENTRIES)
        {
            break;
        }
    }
    return true;
}

//-----------------------------------------------------------
// Name: addPair
// Purpose: Adds an entry to the dictionary (based on the
//     parameters passed) and updates the file to reflect changes.
//     The English and Spanish words are added at the end of the appropriate array
//     and the dictionary file is rewritten to update it. Make sure to check if
//    the array is full before adding a pair.
// Arguments: a spanish word (pass by value string) and an english
//    word (pass by value string)
// Returns: true if the word pair was successfully added, and
//  false otherwise.
//-----------------------------------------------------------
bool Dictionary::addPair(const string englishWord, const string spanishWord)
{
    bool success = true;
    if (isFull())
    {
        return false;
    }

    english[num_entries] = englishWord;
    spanish[num_entries] = spanishWord;
    num_entries++;
    writeDictionary();
    return true;
}

//-----------------------------------------------------------
// Name: removePair - BONUS
// Purpose: Removes an entry from the dictionary (based on the
//     parameters passed) and updates the file to reflect changes.
//    Shift following array entries forward one and decrement
//    num_entries. Then, the dictionary file is updated.
//    Make sure to check if the array is empty before
//    removing a pair.
// Arguments: a spanish word (pass by value string) and an english
//    word (pass by value string)
// Returns: True if the word pair was successfully removed, and
//  false otherwise.
//-----------------------------------------------------------
bool Dictionary::removePair(const int index)
{
    bool success = true;

    cout << "removePair\n"; // remove if method completed

    return success;
}

//------------------ Accessors -------------------
//-----------------------------------------------------------
// Name: getEnglish
// Purpose: Finds the english translation
//    of the spanish word passed in as an parameter.  If the
//    english word passed in as an parameter does not exist
//    in the dictionary, the function returns "DOES NOT EXIST IN DICTIONARY".
// Arguments: A Spanish word (pass by value string)
//            The matching English word (pass by reference string)
// Returns:   bool - true if the spanish word is found
//-----------------------------------------------------------
bool Dictionary::getEnglish(const string spanishWord, string &englishWord) const
{
    int index = find(spanishWord, spanish);
    if (index != -1)
    {
        englishWord = english[index];
        return true;
    }
    return false;
}

//-----------------------------------------------------------
// Name:  getSpanish
// Purpose: Finds the spanish translation of
//    the english word passed in as an parameter.  If the english
//    word passed in as an parameter does not exist in
//    the dictionary, the function returns "DOES NOT EXIST IN DICTIONARY".
// Arguments: An English word (pass by value string).
//            The matching Spanish word (pass by reference string)
// Returns:   bool - true if the English word is found
//-----------------------------------------------------------
bool Dictionary::getSpanish(const string englishWord, string &spanishWord) const
{
    int index = find(englishWord, english);
    if (index != -1)
    {
        spanishWord = spanish[index];
        return true;
    }
    return false;
}
//------------------  Other Useful Functions ----------------

//-----------------------------------------------------------
// Name:  isEmpty
// Purpose: Check if dictionary is empty
// Arguments: None
// Returns : truth value of if number of entries is 0
//-----------------------------------------------------------
bool Dictionary::isEmpty() const
{
    return num_entries == 0;
}

//-----------------------------------------------------------
// Name:  isFull
// Purpose: Check if dictionary is full
// Arguments: None
// Returns : truth value of if number of entries is MAX_ENTRIES
//-----------------------------------------------------------
bool Dictionary::isFull() const
{
    return num_entries == MAX_ENTRIES;
}

//-----------------------------------------------------------
// Name:  Print
// Purpose: Prints out the contents of the dictionary
// to the console.
// Arguments: None
// Returns : void
//-----------------------------------------------------------
void Dictionary::Print() const
{
    if (isEmpty())
        cout << "DICTIONARY IS EMPTY!" << endl;
    else
    {
        for (int i = 0; i < num_entries; i++)
        {
            cout << i << ". English:" << setw(15) << left << english[i]
                 << "Spanish:" << spanish[i] << endl;
        }
    }
}

//================================================================
// Private functions used by the above public functions
//================================================================

//-----------------------------------------------------------
// Name:  writeDictionary
// Purpose: Overwrite file with current dictionary array contents
// Arguments: None
// Returns : None
//-----------------------------------------------------------
void Dictionary::writeDictionary() const
{
    ofstream dout(FILENAME.c_str());
    for (int k = 0; k < num_entries; k++)
    {
        dout << english[k] << " " << spanish[k] << endl;
    }
}

//-----------------------------------------------------------
// Name:  find
// Purpose: Find the location of a word in an array of words
//          Use by getEnglish and getSpanish
// Arguments: The word for which to search
// Returns: The index of that word in the array or
//          -1 if the word is not found
//-----------------------------------------------------------
int Dictionary::find(const string Word, const string Array[]) const
{
    int location = -1;
    int i = 0;

    // if the dictionary is not empty
    // loop over the array until we run out of entries to look at
    // or we find the word
    if (!isEmpty())
    {
        // loop until we run out words or we find the word
        while (i < num_entries && Array[i] != Word)
            i++;

        // if we stopped because we found the word
        // update the location
        if (Array[i] == Word)
            location = i;
    }

    // return the location
    return location;
}
