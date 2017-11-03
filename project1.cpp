/* ******************************************************************************************************
Author: Mohammad Adeel
Course: {135, 136}
Section: Tuesday 7:00PM - 8:40PM
Instructor: R.K. & G.P., respectively
Assignment: "PROJECT 1"
Date: October, 24, 2017

This program retrieves and stores words from a file with a list of two (2) to eight (8).
It then:
(1) Searches through a separate file of arbitrary length and searches the file for the first word.
(1) Outputs all matching sentences to a file named "matches.txt".
(2) Replaces the first word with the second word and outputs all of them to a second file named "replace.txt". 
(3) Searches through the same file as in (1) for sentences that contain ALL of the words in
    the words.txt file and outputs it to a file named "allwords.txt".
(4) Counts the number of sentences that contain word1.
(5) Sorts the matching sentences into the longest and second longest.
(6) Counts the words in the longest and second longest sentence.
(7) Outputs messages to the screen containing information regarding (4), (5), and (6).

****************************************************************************************************** */

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void menu(void);

void getWords(ifstream& inputStream);
//precondition: the file exists
//postcondition: all of the words are saved into separate variables

void matchesTxt(ifstream& inputStream, ofstream& outputStream, ofstream& tempStream, ifstream& temp_inStream, ofstream& temp_outStream, string word1, long& word1_sen_cnt);
//pre-condition: must ignore case when matching words in the sentence to words in words.txt.
//post-condition: if the words match, output the sentence containing the word to matches.txt.

void replaceTxt(ifstream& inputStream, ofstream& outputStream,ifstream& temp_inStream, ofstream& temp_outStream, string word1, string word2);
//pre-condition: There must be a second word present in words.txt. The sentence must contain the first word in words.txt.
//post-condition: the second word replaces the first word

void allWordsTxt(ifstream& inputStream, ofstream& outputStream, string word1, string word2, string word3,  string word4, string word5, string word6, string word7, string word8, long& allWords_cnt);
//pre-condition: the sentence must contain all of the words listed in words.txt
//post-condition: output the sentence to allwords.txt

void straightMatches(ifstream& temp_inStream, ofstream& temp_outStream, ofstream& outputStream, ofstream& tempStream, string newSentence);

void straightAllWords(ifstream& temp_inStream, ofstream& temp_outStream, ofstream& outputStream, string newSentence);

void replaceWords(ifstream& temp_inStream, ofstream& temp_outStream, ofstream& outputStream, string newSentence, string word1,  string word2);

void screenMessages(ifstream& inputStream, long word1_sen_cnt, long allWords_cnt);

string startCapital(string sentence);

string lowerCase(string word);
//precondition:
//postcondition:

int main()
{
    
    ///////////////////////////////////////////////////
    //*** PART ONE: Extract and save first word ***
    //////////////////////////////////////////////////
    
    ifstream inputStream;
    ifstream temp_inStream;
    ofstream outputStream;
    ofstream temp_outStream;
    ofstream tempStream;
    long word1_sen_cnt = 0;
    long allWords_cnt = 0;
    
    
    
    //open words.txt
    //error message if fail to open
    inputStream.open("words.txt");
    if (inputStream.fail())
    {
        cerr << "Words file failed to open. \n";
        exit(1);
    }
    
    //extract first word
    //assign first word to variable
    //close file
    
    char menuOption;
    //static long word1_sen_cnt;
    //static long currLong_wordCnt;
    //static long allWords_cnt;
    string word1, word2, word3, word4, word5, word6, word7, word8;
    

    inputStream >> word1 >> word2 >> word3 >> word4 >> word5 >> word6 >> word7 >> word8;
    
    inputStream.close();
    
    
    cout << "Make a selection: " << endl << endl;
    
    //This creates an interactive menu that allows the user the control which function to test or output.
    do
    {
        menu();

        cin >> menuOption;

        if (menuOption == '1')
        {
            matchesTxt(inputStream, outputStream, tempStream, temp_inStream, temp_outStream, word1, word1_sen_cnt);
        }

        else if (menuOption == '2')
        {
            replaceTxt(inputStream, outputStream, temp_inStream, temp_outStream, word1, word2);
        }

        else if (menuOption == '3')
        {
            allWordsTxt(inputStream, outputStream, word1, word2, word3, word4, word5, word6, word7, word8, allWords_cnt);
        }

        else if (menuOption == '4')
        {
            screenMessages(inputStream, word1_sen_cnt, allWords_cnt);
        }
        
        else if (menuOption == '5')
        {
            matchesTxt(inputStream, outputStream, tempStream, temp_inStream, temp_outStream, word1, word1_sen_cnt);
            replaceTxt(inputStream, outputStream, temp_inStream, temp_outStream, word1, word2);
            allWordsTxt(inputStream, outputStream, word1, word2, word3, word4, word5, word6, word7, word8, allWords_cnt);
            screenMessages(inputStream, word1_sen_cnt, allWords_cnt);
        }
        
        else if (menuOption == '6')
        {
            cout << "Exiting Program. \n";
            break;
        }
        else
        {
            menu ();
            cout << "Invalid choice. Choose again. \n" << endl; 
        }
        
    } while (menuOption != '1' || menuOption != '2' ||
             menuOption != '3' || menuOption != '4' ||
             menuOption != '5' || menuOption != '6'  );

    return 0;
}


void matchesTxt(ifstream& inputStream, ofstream& outputStream, ofstream& tempStream, ifstream& temp_inStream, ofstream& temp_outStream, string word1, long& word1_sen_cnt)
{
    //////////////////////////////////////////////////////////////
    //*** PART TWO: compare stored word to sentences in file ***
    /////////////////////////////////////////////////////////////
    
    //create/open matches file
    //opening and closing to clear the file
    //because a function uses the append
    //operation
    //error message if fail to open
    outputStream.open("matches.txt");
    
    if (outputStream.fail())
    {
        cerr << "Failed to open file 'matches'. \n";
        exit(1);
    }
    outputStream.close(); //CLOSE STREAM
    
    //create/open a temp file
    //opening and closing to clear the file
    //because a function uses the append
    //operation
    //error message if fail to open
    tempStream.open("temp.txt");
    
    if (tempStream.fail())
    {
        cerr << "Failed to open file 'temp'. \n";
        exit(1);
    }
    tempStream.close(); //CLOSE STREAM
    
    
    
    //open file Sentences
    //error message if fail to open
    inputStream.open("sentences.txt");
    if (inputStream.fail())
    {
        cerr << "Failed to open file 'sentences'. \n";
        exit(1);
    }
    
    string sentence;
    string newSentence;
    string copyNewSentence;
    string senWord;
    string nextWord;
    string nextLine;
    static long countw1 = 0;
    word1_sen_cnt = 0;
    
    
    //Go through the file line by line.
    //The function ends once it reaches the end of the file.
    while (getline(inputStream, nextLine))
    {
        for ( long i = 0; i <= nextLine.length(); i++)
        {
            sentence = sentence + nextLine[i];
            if (nextLine[i] == '.')
            {
                newSentence = sentence;
                sentence = "";
                i = i + 1;
                if (nextLine[nextLine.length()-1] == ' ')
                {
                    sentence = sentence + " " + nextLine[i];
                }
                
                else if ((nextLine[nextLine.length()-1] != '\n') && (sentence[i+1] != '\n'))
                {
                    sentence = sentence + " " + nextLine[i];
                }
                else
                {
                    sentence = sentence + nextLine[i];
                }
                
                
                for (long h = 0; h <= newSentence.length(); h++)
                {
                    char senChar = newSentence[h];

                    if (senChar != ' ' && senChar != '\t' && senChar != '.')
                    {
                        senWord = senWord + senChar;
                    }
                    
                    else
                    {
                        //test to see if the word in the sentence is
                        //the same as the first word in the words.txt file
                        //the lowerCase makes the both words case insensitive
                        //during the comparison.
                        if (lowerCase(senWord) == lowerCase(word1))
                        {
                            countw1 += 1;
                            senWord = "";
                        }

                        else
                        {
                            senWord = "";
                        }
                        
                        //if word1 is empty and its count is not at least one,
                        //the sentence is outputted
                        //this is an unnecessary portion, but I am leaving it
                        //because I have spent a lot of time on this project already
                        //to get it to work and I do not want something else going wrong
                        //last minute.
                        if (!(word1.empty()) && (countw1 >= 1))
                        {
                            
                            straightMatches(temp_inStream, temp_outStream, outputStream, tempStream, newSentence);    

                            word1_sen_cnt = word1_sen_cnt + 1;
                            senWord = "";
                            newSentence = "";
                            countw1 = 0;
                            
                        }//last if

                    }//else
                    
                }//inner for loop
                
            }//outermost if

            else
            {
                sentence = sentence;
            }
            
        }//outermost for loop

    }// while
    
    inputStream.close(); //CLOSE STREAM
}

    
    
void replaceTxt(ifstream& inputStream, ofstream& outputStream,ifstream& temp_inStream, ofstream& temp_outStream, string word1, string word2)
{
    //////////////////////////////////////////////////////////////
    // *** PART THREE: replace word in replace.txt ***
    /////////////////////////////////////////////////////////////    
    
    //create/open replace file
    //opening and closing file to clear replace.txt
    //error message if fail to open
    outputStream.open("replace.txt");
    if (outputStream.fail())
    {
        cerr << "Failed to open file. \n";
        exit(1);
    }
    
    outputStream.close(); //CLOSE STREAM
    
    
    
    //open file Sentences
    //error message if fail to open
    inputStream.open("sentences.txt");
    if (inputStream.fail())
    {
        cerr << "Failed to open 'sentences' file. \n";
        exit(1);
    }

    
    
    //Resetting previously declared Variables
    //Declaring new variable
    
    string nextLine;        //stores the value of the most newly extracted line
    string sentence;        //a sentence that will take and hold the value of newLine
    string newSentence;     //holds the value of sentence without punctuation

    
    //This continues until the end of the file
    //when there are no more lines to read
    //It creates a sentence to use for comparing the words
    //I did it this way to avoid opening and closing too many files
    //but, it may not have mattered in the end
    while (getline(inputStream, nextLine))
    {
        for ( long i = 0; i <= nextLine.length(); i++)
        {
            sentence = sentence + nextLine[i];
            if (nextLine[i] == '.')
            {
                newSentence = sentence;
                
                sentence = "";
                i = i + 1;
                if (nextLine[nextLine.length()-1] == ' ')
                {
                    sentence = sentence + " " + nextLine[i];
                }
                else if ((nextLine[nextLine.length()-1] != '\n') && (sentence[i+1] != '\n'))
                {
                    sentence = sentence + " " + nextLine[i];
                }
                else
                {
                    sentence = sentence + nextLine[i];
                }
                
                //this function does the work of replacing the words
                replaceWords(temp_inStream, temp_outStream, outputStream, newSentence, word1, word2);
                
            }//outermost if
            
            else
            {
                sentence = sentence;
            }
            
        }//for loop

    }//outermost while
  
    inputStream.close(); //CLOSE STREAM
}


//This functions checks for sentences that contain all of the words in the word.txt file
//It also counts the number of sentences that have all of the words in them.
//It stores the counts by altering a variable in the long main() function through call-by-reference
void allWordsTxt(ifstream& inputStream, ofstream& outputStream, string word1, string word2, string word3, string word4, string word5, string word6, string word7, string word8, long& allWords_cnt)
{ 
    
    //////////////////////////////////////////////////////////////
    // *** PART FOUR: allwords.txt *** 
    /////////////////////////////////////////////////////////////

    //create/open matches file
    //doing this to clear the file in case it is not empty
    //I am clearing it because the straightAllWords functions
    //appends to the file, thus retaining the data
    //if the stream is not reopened and closed
    //error message if fail to open
    ifstream temp_inStream;
    ofstream temp_outStream;
    
    outputStream.open("allwords.txt");
    
    if (outputStream.fail())
    {
        cerr << "Failed to open file 'allwords'. \n";
        exit(1);
    }
    outputStream.close(); //CLOSE STREAM
    

    //open file Sentences
    //error message if fail to open
    inputStream.open("sentences.txt");
    if (inputStream.fail())
    {
        cerr << "Failed to open 'sentences' file. \n";
        exit(1);
    }
    
    //Emptied previously used variables
    //Declared counter variables
    
    string nextLine;        //stores the value of the most newly extracted line
    string sentence;        //a sentence that will take and hold the value of newLine
    string newSentence;     //holds the value of sentence without punctuation
    string senWord;         //a word without spaces, tabs, or a period

    static long wordCount1 = 0; //keeps a count of word1 in the words.txt
    static long wordCount2 = 0; //keeps a count of word2 in the words.txt
    static long wordCount3 = 0; //keeps a count of word3 in the words.txt
    static long wordCount4 = 0; //keeps a count of word4 in the words.txt
    static long wordCount5 = 0; //keeps a count of word5 in the words.txt
    static long wordCount6 = 0; //keeps a count of word6 in the words.txt
    static long wordCount7 = 0; //keeps a count of word7 in the words.txt
    static long wordCount8 = 0; //keeps a count of word8 in the words.txt
    allWords_cnt = 0;
    
    while (getline(inputStream, nextLine))
    {  
        startCapital(nextLine);
        
        for ( long i = 0; i <= nextLine.length(); i++)
        {
            sentence = sentence + nextLine[i];
            if (nextLine[i] == '.')
            {
                newSentence = sentence;
                
                sentence = "";
                
                i = i +1;
                
                if (nextLine[nextLine.length()-1] == ' ')
                {
                    sentence = sentence + " " + nextLine[i];
                }
                
                else if ((nextLine[nextLine.length()-1] != '\n') && (sentence[i+1] != '\n'))
                {
                    sentence = sentence + ' ' + nextLine[i];
                }
                else
                {
                    sentence = sentence + nextLine[i];
                }
                
                //creates a word free of spaces or a period
                //if it conains any other punctuation,
                //that punctuation is considered part of the word
                //(e.g. "part," and "part!" are different from "part")
                for (long h = 0; h <= newSentence.length(); h++)
                {
                    char senChar = newSentence[h];

                    if (senChar != ' ' && senChar != '\t' && senChar != '.')
                    {
                        senWord = senWord + senChar;
                    }
                    
                    //Checks to see if the word appears in the sentence
                    //Through a word match after converting both words to lowercase
                    //If there is a match, the counter for that word goes up by one (1)
                    //each positive match resets the string holding the word in the sentence (senWord)
                    //if there is no match, it resets the string senWord (sentence word) to empty
                    //and move on to the next word
                    else
                    {
                        if ((lowerCase(senWord) == lowerCase(word1)))
                        {
                            wordCount1 += 1;
                            senWord = "";
                        }

                        else if ((lowerCase(senWord) == lowerCase(word2)))
                        {
                            wordCount2 += 1;
                            senWord = "";
                        }

                        else if ((lowerCase(senWord) == lowerCase(word3)))
                        {
                            wordCount3 += 1;
                            senWord = "";
                        }

                        else if ((lowerCase(senWord) == lowerCase(word4)))
                        {
                            wordCount4 += 1;
                            senWord = "";
                        }

                        else if ((lowerCase(senWord) == lowerCase(word5)))
                        {
                            wordCount5 += 1;
                            senWord = "";
                        }

                        else if ((lowerCase(senWord) == lowerCase(word6)))
                        {
                            wordCount6 += 1;
                            senWord = "";
                        }

                        else if ((lowerCase(senWord) == lowerCase(word7)))
                        {
                            wordCount7 += 1;
                            senWord = "";
                        }

                        else if ((lowerCase(senWord) == lowerCase(word8)))
                        {
                            wordCount8 += 1;
                            senWord = "";
                        }

                        else
                        {
                            senWord = "";
                        }
                        
                        
                        //This if statements tests if the word variable is empty
                        //or if it has a count of greater than one (1).
                        //All of the conditions must be true for the sentence
                        //to be output/printed.
                        //Since the words list could have only a max of eight (8)
                        //words, this was the easiest method for me to use.
                        //if any list of words contains less than eight words
                        //it is declared empty and this function returns true
                        //the program then resets all the word counters to zero
                        //empties the string senWord, and empties the string newSentence
                        //so they can be used again for the next word or sentence.
                        if ((( word1.empty()) || (wordCount1 >= 1)) &&
                            (( word2.empty()) || (wordCount2 >= 1)) &&
                            (( word3.empty()) || (wordCount3 >= 1)) &&
                            (( word4.empty()) || (wordCount4 >= 1)) &&
                            (( word5.empty()) || (wordCount5 >= 1)) &&
                            (( word6.empty()) || (wordCount6 >= 1)) &&
                            (( word7.empty()) || (wordCount7 >= 1)) &&
                            (( word8.empty()) || (wordCount8 >= 1))  )
                            
                        {
                            straightAllWords(temp_inStream, temp_outStream, outputStream, newSentence);
                            allWords_cnt = allWords_cnt + 1;

                            wordCount1 = 0;
                            wordCount2 = 0;
                            wordCount3 = 0;
                            wordCount4 = 0;
                            wordCount5 = 0;
                            wordCount6 = 0;
                            wordCount7 = 0;
                            wordCount8 = 0;
                            
                            senWord = "";
                            newSentence = "";
                            
                        }//if counter  
                        
                    }//inner else

                }//inner for
                
            }//first if
            
            else
            {
                sentence = sentence;
            }
            
            
        }//outer for


    }// while
  
    inputStream.close(); //CLOSE STREAM   
}



//This function does three things:
//(1) It sorts the lines into longest and secondlongest.
//(2) It counts the number of words in each of these lines.
//(3) It outputs messages to the screeen.
void screenMessages(ifstream& inputStream, long word1_sen_cnt, long allWords_cnt)
{

    
    //////////////////////////////////////////////////////////////
    // *** PART FIVE: Outputting counts to the Screen *** 
    /////////////////////////////////////////////////////////////
    
    //open file Sentences
    //error message if fail to open
    inputStream.open("temp.txt");
    if (inputStream.fail())
    {
        cerr << "Failed to open 'temp.txt' file. \n";
        exit(1);
    }
    
    string currentLongest;  //represents second longest sentence
    string newLongest;      //represents longest sentence
    string newLine;         //incoming line that is being evaluated
    string senWord;          //a sentence word that will hold unpunctuated words
    
    //static long allWords_cnt;
    //static long word1_sen_cnt;
    long currLong_wordCnt = 0;
    long newLongest_wordCnt = 0;
    
    //evaluates the length of the incoming line
    //sorts each incoming line into longest
    //or second longest after comparting the
    //lengths of the currently stored lines
    //and the new line
    while (getline(inputStream, newLine))
    {
        if (newLine.length() > currentLongest.length())
        {
            currentLongest = newLine;
        }
        
        if (newLine.length() > newLongest.length())
        {
            currentLongest = newLongest;
            newLongest = newLine;
        }
    }

    //creates words free of punctuation for longest sentence
    //counts the number of words for longest sentence
    
    for (long g = 0; g <= newLongest.length(); g++)
    {
        char senChar = newLongest[g];

        if (senChar != ' ' && senChar != '\t' && senChar != '.')
        {
            senWord = senWord + senChar;
        }
        else
        {
            newLongest_wordCnt = newLongest_wordCnt + 1;
            senWord = "";
        }
    }
    
    //creates words free of punctuation for second longest sentence
    //counts the number of words for second longest sentence
    for (long h = 0; h <= currentLongest.length(); h++)
    {
        char senChar = currentLongest[h];

        if (senChar != ' ' && senChar != '\t' && senChar != '.')
        {
            senWord = senWord + senChar;
        }
        else
        {
            currLong_wordCnt = currLong_wordCnt + 1;
            senWord = "";
        }
    }
            
    inputStream.close(); //CLOSE STREAM

    cout << "<" << word1_sen_cnt << ">" << " sentences that match the "
         << "first word saved in file match. \n";
    
    cout << "The longest sentence matching the first word has " << "<" << newLongest_wordCnt << ">"
         << " words, and the 2nd longest has " << "<" << currLong_wordCnt << ">" << " words. \n";
    
    
    cout << "<" << allWords_cnt << ">" << " sentences that match every word saved in file allwords. \n";
    
    newLongest_wordCnt = 0;
    currLong_wordCnt = 0;
}

//This function outputs a menu for the user to choose what to do
//This served as my driver function to test the various functions,
//but I shortened it to test only functions responsibile for
//completing the tasks outlined in the project assignment.
void menu(void)
{
    cout << "** MENU **" << endl;
    cout << "(1) Matches" << endl;
    cout << "(2) Replace" << endl;
    cout << "(3) All Words" << endl;
    cout << "(4) Screen Message of sentence counts (must run 2 & 3 or 5 first.)" << endl;
    cout << "(5) All of the above" << endl;
    cout << "(6) Exit" << endl;
}


//This function changes the first letter of the sentence string to an uppercase
//But, it does so only if the character is in the first position.
//I am still experiencing bugs with it that may have to do with getline.
string startCapital(string sentence)
{  
    for (int i = 0; i <= sentence.length(); i++)
    {
        if (!( 97 <= sentence[i] && sentence[i] <= 122 ))
        {
            if ((65 <= sentence[i] && sentence[i] <= 90))
            {
                break;
            }
            else
            {
                sentence[i] = sentence[i];
            }
        }
    
        else if (( 97 <= sentence[i] && sentence[i] <= 122))
        {
            sentence[i] = sentence[i] - 32;
            break;
        }    
    }
    
    return (sentence);
    
}

//this function converts all the characters in a word to lowercase
//this is used for purposes of making word matching case insensitive
string lowerCase(string word)
{
    for (long i = 0; i < word.length(); i++)
    {
        if ((65 <= word[i]) && (word[i] <= 90))
        {
            word[i] = word[i] + 32;
        }        
    }  
    return (word);
}

//This function simply straightens out the lines in matches.txt
//to remove whitespace in front of the sentence
//it takes in a sentence as an actual parameter and outputs it
//to a temporary holding file.
//it then reads the sentence from that file, word by word and
//stores it in a new sentence variable that is then output
//to the matches file.
void straightMatches(ifstream& temp_inStream, ofstream& temp_outStream, ofstream& outputStream, ofstream& tempStream, string newSentence)
{
    
    string copyNewSentence;
    string nextWord; //
    
    
    temp_outStream.open("holdFile.txt");
    if (temp_outStream.fail())
    {
        cerr << "Temp_outStream: Failed to open file. \n";
        exit(1);
    }

    temp_outStream << newSentence << endl;

    temp_outStream.close(); //CLOSE STREAM

    temp_inStream.open("holdFile.txt");
    if (temp_inStream.fail())
    {
        cerr << "Temp_inStream: Failed to open file. \n";
        exit(1);
    }

    while (temp_inStream >> nextWord)
    {
        if (nextWord[nextWord.length()-1] != '.')
        {
            copyNewSentence = copyNewSentence + nextWord + " ";
        }

        else
        {
            copyNewSentence = copyNewSentence + nextWord;
        }
    }
    
    temp_inStream.close(); //CLOSE STREAM
    
    //create/open matches file
    //error message if fail to open
    
    outputStream.open("matches.txt", ios::app);
    
    if (outputStream.fail())
    {
        cerr << "Failed to open file 'matches'. \n";
        exit(1);
    }
    
    outputStream << startCapital(copyNewSentence) << endl;
    
    outputStream.close(); //CLOSE STREAM
    
    
    //create/open matches file
    //error message if fail to open
    tempStream.open("temp.txt", ios::app);
    
    if (tempStream.fail())
    {
        cerr << "Failed to open file 'temp'. \n";
        exit(1);
    }
    
    tempStream << copyNewSentence << endl;
    
    tempStream.close(); //CLOSE STREAM
    
    
}

//This function simply straightens out the lines in allwords.txt
//to remove whitespace in front of the sentence
//it takes in a sentence as an actual parameter and outputs it
//to a temporary holding file.
//it then reads the sentence from that file, word by word and
//stores it in a new sentence variable that is then output
//to the allwords file.
void straightAllWords(ifstream& temp_inStream, ofstream& temp_outStream, ofstream& outputStream, string newSentence)
{
    
    string copyNewSentence;
    string nextWord;
    
    
    temp_outStream.open("holdFile.txt");
    if (temp_outStream.fail())
    {
        cerr << "Temp_outStream: Failed to open file. \n";
        exit(1);
    }

    temp_outStream << newSentence << endl;

    temp_outStream.close(); //CLOSE STREAM

    temp_inStream.open("holdFile.txt");
    if (temp_inStream.fail())
    {
        cerr << "Temp inStream: Failed to open file. \n";
        exit(1);
    }

    while (temp_inStream >> nextWord)
    {
        if (nextWord[nextWord.length()-1] != '.')
        {
            copyNewSentence = copyNewSentence + nextWord + " ";
        }

        else
        {
            copyNewSentence = copyNewSentence + nextWord;
        }
    }
    
    temp_inStream.close(); //CLOSE STREAM
    
    //create/open matches file
    //error message if fail to open
    
    outputStream.open("allwords.txt", ios::app);
    
    if (outputStream.fail())
    {
        cerr << "Failed to open file 'matches'. \n";
        exit(1);
    }
    
    outputStream << startCapital(copyNewSentence) << endl;
    
    outputStream.close(); //CLOSE STREAM
    
    
}



void replaceWords(ifstream& temp_inStream, ofstream& temp_outStream, ofstream& outputStream, string newSentence, string word1,  string word2)
{
    
    string senWord;
    string nextWord;
    string replacementSentence;
    

    for (long h = 0; h <= newSentence.length(); h++)
    {
        char senChar = newSentence[h];

        if (senChar != ' ' && senChar != '\t' && senChar != '.')
        {
            senWord = senWord + senChar;
        }
        else
        {
            //this portion replaces the word1 one with word2
            //using filstreams and a temporary holder file.
            //I tried to turn it into a function, but did not
            //know how.
            if (lowerCase(senWord) == lowerCase(word1))
            {

                temp_outStream.open("holdFile.txt");
                if (temp_outStream.fail())
                {
                    cerr << "Temp_outStream: Failed to open file. \n";
                    exit(1);
                }

                temp_outStream << newSentence << endl;

                temp_outStream.close(); //CLOSE STREAM

                temp_inStream.open("holdFile.txt");
                if (temp_inStream.fail())
                {
                    cerr << "Temp_inStream: Failed to open file. \n";
                    exit(1);
                }

                while (temp_inStream >> nextWord)
                {
                    if (nextWord[nextWord.length() - 1] != '.')
                    {
                        if (lowerCase(nextWord) != lowerCase(word1))
                        {
                            replacementSentence = replacementSentence + nextWord + " ";
                        }

                        else if (lowerCase(nextWord) == lowerCase(word1))
                        {
                            replacementSentence = replacementSentence + word2 + " ";
                        }       
                    } // end if

                    else
                    {
                        if (lowerCase(nextWord) == lowerCase(word1 + '.'))
                        {
                            replacementSentence = replacementSentence + word2 + '.';
                        }
                        else
                        {
                            replacementSentence = replacementSentence + nextWord;
                        }
                    } // end else

                } // end while


                //create/open replace.txt file
                //error message if fail to open
                //appends the sentences to it
                outputStream.open("replace.txt", ios::app);
                if (outputStream.fail())
                {
                    cerr << "Failed to open file. \n";
                    exit(1);
                }

                outputStream << startCapital(replacementSentence) << endl;
                
                
                senWord = "";
                newSentence = "";
                replacementSentence = "";
            }//inner if

            else
            {
                senWord = "";
            }

        }
    }//inner for
    
    temp_inStream.close(); //CLOSE STREAM
    outputStream.close(); //CLOSE STREAM
}

/**

NOTE:
I tried using this function to replace the words, but it was not working the way I wanted.
I also did not know we were allowed to creat temporary files to help us with the task.

//this function is used to replace word1 in sentences with word2
string replaceWord(string sentence_one, const string& word1, const string& word2)
{

    string senWord;
    string sentence_two;
    static long c;
    static long w;
    char ch;

    c = 0;
    w = 0;
    
    
    while (ch != '.')
    {
        
        ch = sentence_one[c];
        sentence_two = sentence_two + ch;
        
        if (((ch != ' ') && (ch != '\t') && (ch != '.')))
        {
            senWord = senWord + ch;
            //cout << senWord << endl;
        }
        
        else if (lowerCase(senWord) == lowerCase(word1))
        {   
            c = c - word1.length();
            while (w <= word1.length())
            {
                sentence_two.at(c) = word2[w];
                w++;
                c++;
            }
            c--;
            sentence_two = sentence_two + ch;
            senWord = "";
            
            w = 0;
        }
        
        else
        {
            senWord = "";
        }
        
        c++;
    }
    
    return(sentence_two);  
}

*/