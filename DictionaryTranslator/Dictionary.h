//-----------------------------------------------------
// Author:     Aneesh Komanduri and Susan Gauch
// Purpose:    Uses the file dictionary.txt to translate 
//			   between English and Spanish words.
//-----------------------------------------------------
#include <string>
using namespace std;

static const int MAX_ENTRIES = 300;	// Capacity of the dictionary
const string FILENAME = "dictionary.txt";   // dictionary file

class Dictionary
{
	public:
    // Constructors and Destructors
	Dictionary();	// Default Constructor
	Dictionary(const Dictionary& other); // Copy Constructor
	~Dictionary();	// Destructor
        
    // Mutators
	bool readDictionary();
	bool addPair(const string englishWord, const string spanishWord);
	bool removePair(const int index);
   
    // Accessors
	bool getEnglish(const string spanishWord, string &englishWord) const;
	bool getSpanish(const string englishWord, string &spanishWord) const;

    // Other Useful Methods
    void Print() const;
	bool isEmpty() const;
	bool isFull() const;

private:
	int num_entries;		   				// Current number of entries in the dictionary

	string english[MAX_ENTRIES];   		// Array of english words
	string spanish[MAX_ENTRIES];   		// Array of corresponding spanish words

    // Private methods used by the public methods
    void writeDictionary() const;   	// Write the dictionary to the file
    int find(const string word, const string wordArray[]) const; // Find a word in an array
};
