
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include "DictionaryEntry.h"
#include "Hashtable.h"
#include <sstream>

using namespace std;

int main (int argc, char *argv[]){
	HashTable<DictionaryEntry> hashtb = HashTable<DictionaryEntry>() ;
	if (argc != 2){ //if there is an incorrect number of arguments, which means the arguments have to equal 2
		cout << "Incorrect Number of Command Line Arguments" << endl;
		exit(1);//exit program
	}
    	std::string filetoopen;
    	filetoopen = argv[1];
	std::ifstream frenchfile(filetoopen.c_str()); // This uses the ifstream class to open and read the text file line by line
	string currentline;
	vector<string> input;//this has duplicates
  	std::string str2 ("#");
	int vectornum=0;
	string needed;
	string word;
	string definition;

	if (frenchfile.is_open()){ //as long as the ifstream is open
		while(getline(frenchfile, currentline)){
			//std::size_t found = currentline.find(str2);
 			//if (found!=std::string::npos){
				//}
 			//else{
 			stringstream currentlinestream(currentline);
			needed = currentline;
			getline(currentlinestream, needed, '\t');
			word=needed;
	   		getline(currentlinestream, needed, '\t');
	 		definition = needed;
			input.push_back(word);
			input.push_back(definition);
			vectornum=vectornum+2;
 			//}
		}
	frenchfile.close(); //close the fstream, save memory.
	}
	else {
		cout << "Can't open the file. Wrong filename or doesn't exist." << endl;
		exit(1);
	}
	int numberofwords = 0;
	vector<string> noduplicate;
	for(int i = 0; i < vectornum;i+=2){
			DictionaryEntry temp(input[i],input[i+1]);
			if(hashtb.insert(temp)==true){
				hashtb.insert(temp);
				noduplicate.push_back(input[i]);
				numberofwords++;
			}
	}
	string userenter;
	int random=0;
	srand(time(NULL)); /* seed random number generator */
	while (1<2){
		cin >> userenter;
		if (userenter == "random"){
		random = rand()%numberofwords;
		DictionaryEntry output = hashtb.retrieve(noduplicate[random]);
		cout << output.getword()<< endl;
		cout << output.getdefinition() << endl;
		}
		else{
			DictionaryEntry gotten;
			gotten = hashtb.retrieve(userenter);
			cout << gotten.getword()<< endl;
			cout << gotten.getdefinition() << endl;
		}
		}
	}

