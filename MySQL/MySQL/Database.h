#pragma once
#include <mysqlx/xapi.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "root"

class Database
{
private:
	/* Here will be the instance stored. */
	static Database* instance;
	/* Private constructor to prevent instancing. */
	Database();
public:
	/* Static access method. */
	static Database* getInstance();
	~Database();
	mysqlx_session_t* startup();
	void query1(string date1, string date2);
	void query2(string date1, string date2, string name);
	void query3(string date1, string date2, string name);
	void query4();
	void query5(string album_name);
	void query6(string date1, string date2);
	void query7();
	void query8();
	void query9();
	void query10();
	void query11(string date1, string date2);
	void query12();
	void query13();
	void query14();
	void query15();
};



