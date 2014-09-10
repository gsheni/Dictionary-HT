#include<stdlib.h>
#include<iostream>
#include<string>

using namespace std;

class DictionaryEntry{
private:
	string word;
	string definition;
public:
	DictionaryEntry(){
		word ="";
		definition = "";
		//Constructor to create table.
	}
	DictionaryEntry(string wor, string def){
		word = wor;
		definition = def;
		//Constructor
	}
    	~DictionaryEntry()
		{}
	string getdefinition() const {
		return definition;
	}
	string getword() const{
		return word;
	}

    bool operator== ( const DictionaryEntry & rhs ) const
      {
    	if(getword() == rhs.getword()){
    		if(getdefinition() == rhs.getdefinition() ){
    			return true;
    		}
    		else{
    			return false;
    		}
    	}
    	else{
    		return false;
    	}
      }

    bool operator!= ( const DictionaryEntry & rhs ) const
      { return !( *this == rhs ); } //just the opposite of the equals
};
int hashf( const string & key ){
    int hashVal = 0;

    for( int i = 0; i < key.length( ); i++ )
        hashVal = 37 * hashVal + key[ i ];

    return hashVal;
}
int hashf( const DictionaryEntry & x ){
	string hashtoget = x.getword();
    int hashed = hashf(hashtoget);
    return hashed;
}

