#include "Database.h"
#include <iostream>
#include "sqlite3.h"

Database::Database(char* filename)
{
	db= NULL;
	open(filename);
}

Database::~Database()
{
}


/*static*/ int Database::callback(
  //callback function that will be called by sqlite3_exec() for each
  //row in the query result table when the query has completed.
  void * data, //pass through data provided to sqlite3_exec() [4th argument]
  int argc, //Number of columns in answer table row
  char ** argv, //array of strings representing table row values
  char ** azColName //array of strings representing column names
  ){
    //cout << (const char *) data << "\n";
	//print values for the row
    for (int i=0; i<argc; i++){
      cout << argv[i] << ", ";
    }
    cout << "\n";
    return 0;
  }
  
void Database:: queryDatabase(string randQuery){
	  const char * sqlQuery = randQuery.c_str();
	
	if (rc = sqlite3_exec(db, sqlQuery, callback, (void *) data, &zErrMsg) == SQLITE_OK){
		 cout << "\nSQL QUERY SUCCEEDED\n";
	 }else{
		  cout << "ERROR EXECUTING SQL: " << zErrMsg;
          sqlite3_free(zErrMsg);
	  }
	}
	
//looooooooooooooooooooooooooooooooooooooooool


rc = sqlite3_open(db_file_name, &db);
  if(rc){
    cout << "ERROR: Could Not Open Database: "
         << sqlite3_errmsg(db);
    cout << "\nEXITING\n";
    return 0;
  }

  cout << "\nSUCCESSFULLY OPENED DATABASE: " << db_file_name << "\n\n";
  
  
if(sqlite3_open(filename, &database) == SQLITE_OK)
		cout << "True\n";
		return true;
	cout << "False\n";	
	return false;   
	
bool Database::open (char* filename){
	if(sqlite3_open(filename, &database) == SQLITE_OK)
		cout << "True\n";
		return true;
	cout << "False\n";	
	return false; 
}
	i
	 
	
	
	
	
