#ifndef __DATABASE_H__
	#define __DATABASE_H__	 
	#include <string>
	#include <vector>
	extern "C"{
	#include "sqlite3.h"
	}
	using namespace std;
	 
	class Database
	{
	public:
	    Database(char* filename);
	    ~Database();
	    bool open(char* filename);
	    //vector<vector<string> > query(const char* query);
	    void close();
	   static int callback(void*, int,char**,char **);
	 void   queryDatabase(string );
	private:

	const char * db_file_name = "beatles.db";
	sqlite3 *db; //pointer to our database
	char * zErrMsg = 0;  //will be used for query error messages
	int rc; //return code
	const char * data = "callback called"; //data passed through to callback
	

	};

	 

	#endif
