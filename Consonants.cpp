//Name: Alieu Barrow
//Class: Structured Programming In C++
//Date: 13/12/2021
//Assignment 4B: Task 4; Military Language
//IDE: Visual Studio 2022

//Header files
#include <iostream>
using namespace std;

//Size of char array
const int MAXLEN = 100;
const int SIZE = 2;

//Function prototypes 
bool isConsonant(char letter);
bool exists(char letter, char* abbreviation);
void moreThanFiveConsonants(char* word, char* abbreviation, int length);


int main() {

        // Variables
        char word[MAXLEN];
        char  abbreviation[MAXLEN] = { '\0' };
        int length;
        bool check;
        int counter = 0;
        char answer;

        do {

                cout << "Enter a word: ";
                cin.getline(word, MAXLEN); //Take input from user. Hundred characters maximum

                length = strlen(word); //Take length of user input 

                //Check to see if there are more than five consonants in the word
                for (int i = 0; i < length; i++) {
                        check = isConsonant(word[i]); //Check if letter is consonant in given word
                        if (check) {
                                counter++;
                        }
                }

                //If there are more than five consonants, run a seperate function moreThanFiveConsonants()
                if (counter > 5) {
                        moreThanFiveConsonants(word, abbreviation, length);
                }
                else {
                        //Add every letter that's a consonant to the abbreviation[] array
                        for (int i = 0; i < length; i++) {
                                check = isConsonant(word[i]); //Check if letter is a consonant 
                                if (check) {
                                        check = exists(word[i], abbreviation); //Check if consonant is already in abbreviation[] array using exists() function
                                        if (check) {
                                                abbreviation[i] = word[i]; //Add it in abbreviaion[] array if not
                                        }
                                }
                        }
                }

                cout << "Abbreviation: " << abbreviation << endl << endl;

                cout << "Do you want to check another word (Y/N)? ";
                cin >> answer;
                cin.ignore(); //Clear buffer

                cout << endl;

                //Reset spaces in array in case of reuse 
                memset(word, 0, sizeof word);
                memset(abbreviation, 0, sizeof abbreviation);

        } while (toupper(answer) == 'Y');

        return 0;
}

//Check if letter is a consonant and return true if it is, false otherwise
bool isConsonant(char letter) {

        char uppercaseLetter = toupper(letter);
        char consonants[] = { 'B', 'C',  'D', 'F', 'G',  'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z' }; //All 21 consonants
        int length = 21; //The fixed length of the consonants 

        //Loop through consonants[] array to check if letter is a consonant 
        for (int i = 0; i < length; i++) {
                if (consonants[i] == uppercaseLetter) {
                        return true;
                }
        }
        return false;
}

//exists() function checks if consonant is already in abbreviation[] array, return true if it is, false otherwise
bool exists(char letter, char* abbreviation) {

        int length = strlen(abbreviation); //Take length of abbreviation 
        int checkDuplicate = 0;

        //Loop through abbreviation[] array and check if letter is already there or not
        for (int i = 0; i < length; i++) {
                if (abbreviation[i] == letter) {
                        return false;
                }
        }
        return true;
}

//Function creates an abbreviation by keeping the first three and the last two consonants
void moreThanFiveConsonants(char* word, char* abbreviation, int length) {

        //Variables 
        int counter = 0; //Counter keeps track of how many cosonants are inserted in abbreviation[]
        bool check;
        int  indexPosition = 0; //Counter keeps track of position in abbreviation[]
        char temporary[SIZE];
        int tempCounter = 0;

        //Loop through and add first 3 consonants to abbreviation[] array
        for (int i = 0; i < length; i++) {
                check = isConsonant(word[i]); //Check if letter is a consonant
                if (check) {
                        abbreviation[indexPosition] = word[i]; //Add to abbreviation[]
                        indexPosition++;
                        counter++;
                }
                //If the first three have been added, then break out of loop
                if (counter == 3) {
                        break;
                }
        }

        counter = 0; //Reset counter

        //Loop and add last two consonats to abbreviation[]
        //Loop will start from the end of words[] array 
        for (int j = length; j > 0; j--) {
                check = isConsonant(word[j]); //Check if letter is a consonant
                if (check) {
                        temporary[tempCounter] = word[j]; //Add to temp array
                        tempCounter++;
                        counter++;
                }
                //If last two have been added to abbreviation[], break out of loop
                if (counter == 2) {
                        break;
                }
        }

        //Add last from temp to arrbeviation[] array
        for (int k = SIZE - 1; k >= 0; k--) {
                abbreviation[indexPosition] = temporary[k];
                indexPosition++;
        }
}

