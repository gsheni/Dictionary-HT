
#include <vector>
#include "List.h"
#include <string>
using namespace std;

template <typename HashedObj>
class HashTable
{
  public:
	//constructor (explicit so no implicit conversion)
	explicit HashTable( int size = 101 ):
	theLists(size)
	{tableSize=size; currentSize=0; }

    //empty the Hashtable
    void makeEmpty( )
    {
    	currentSize = 0;
    	//clear each linked list from hashtable
        for( int i = 0; i < tableSize; i++ )
            theLists[ i ].clear( );
    }

    //search for x in the hash table
    bool contains( const HashedObj & x ) const
    {
    	//assign reference variable to rename the complicated object
        const List<HashedObj> & whichList = theLists[ myhash( x ) ];
        //return whether x already exists in the list
        return whichList.find(x) != whichList.end( );
    }

    //insert x into Hashtable (true if successful, false if already exists)
    bool insert(  const HashedObj & x )
    {
    	//assign reference variable to rename the complicated object
        List<HashedObj> & whichList = theLists[ myhash( x ) ];

        //if x already exists in the list, return false
        if( whichList.find(x) != whichList.end( ) ){
            return false;
        }
        //otherwise push to list
        whichList.push_front( x );

        //rehash if new size is greater than hashtable size
        if( ++currentSize > tableSize ){
            rehash( );
    	}
        return true;
    }

    //remove x from Hashtable(true if successful, false if not found)
    bool remove( const HashedObj & x ){
    	//assign reference variable to rename the complicated object
        List<HashedObj> & whichList = theLists[ myhash( x ) ];

        //iterator is at end of list (i.e., not found)
        if( whichList.find(x) == whichList.end( ) ){
            return false;
        }

        //erase x
        whichList.erase(  whichList.find(x) );
        --currentSize;
        return true;
    }
    //
    HashedObj retrieve(string & x ){
    	int hashed = myhash( x );
    	HashedObj found;
    	found = *theLists[hashed].find(x);
    	return found;
    }


  private:
    //the vector of linked-lints hashtable
    vector<List<HashedObj> > theLists;   // The array of Lists
    int  currentSize;
    int  tableSize;


    //because coming up with new stuff is hard
    //rehashing for separate chaining hash method
    void rehash( ){
        vector<List<HashedObj> > oldLists = theLists;
        int oldtableSize = tableSize;
        tableSize = nextPrime(2 * oldtableSize);
        // Create new double-sized, empty table
        theLists.resize( tableSize );
        for( int i = 0; i< tableSize; i++ ){
            theLists[ i ].clear( );
        }
        // Copy table over
        currentSize = 0;
        for( int i = 0; i < oldtableSize; i++ ){
        	while (!oldLists[i].empty()){
        		insert(oldLists[i].front());
        		oldLists[i].pop_front();
        	}
        }
    }

    //call hash function and makes sure values fit in table
    int myhash( const HashedObj & x ) const
    {
        int hashVal = hashf( x ); // call hash function

        //make sure the has values fit into hashtable
        hashVal %= tableSize;

        //check for overflow
        if( hashVal < 0 ){
            hashVal += tableSize;
        }
        return hashVal;
    }
    int myhash( const string & x ) const
       {
           int hashVal = hashf( x ); // call hash function

           //make sure the has values fit into hashtable
           hashVal %= tableSize;

           //check for overflow
           if( hashVal < 0 ){
               hashVal += tableSize;
           }
           return hashVal;
       }
    bool isPrime( int n )
     {
         if( n == 2 || n == 3 )
             return true;

         if( n == 1 || n % 2 == 0 )
             return false;

         for( int i = 3; i * i <= n; i += 2 )
             if( n % i == 0 )
             return false;

         return true;
     }

     //Internal method to return a prime number at least as large as n.
     //Assumes n > 0.
     int nextPrime( int n )
     {
         if( n % 2 == 0 )
             n++;

         for( ; !isPrime( n ); n += 2 )
             ;

         return n;
     }
};

