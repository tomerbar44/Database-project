#include "Database.h"
int main() {
	Database* pDb = Database::getInstance();
	cout << "DATA BASE music_world CREATED" << endl;

	int choice = 0;
	while (choice != 99) {
		cout << "\n****************************************************************************************************\n*"
			<< " Welcome to your Recording Studio. Please choose one of the following:\t\t\t\t   *\n*\t\t\t\t\t\t\t\t\t\t\t\t   *\n"
			<< "* 1) Show number of albums have been recorded between two dates.\t\t\t\t   *\n* 2) Show number of different songs did X musician record between two dates.\t\t\t   *\n"
			<< "* 3) Show number of different albums did X musician participate between two dates.\t\t   *\n* 4) Show the most common instrument.\t\t\t\t\t\t\t\t   *\n"
			<< "* 5) Show the list of instruments in Album A.\t\t\t\t\t\t\t   *\n* 6) Show the most productive producer between two date.\t\t\t\t\t   *\n* 7) Show the most common manufacturer.\t\t\t\t\t\t\t\t   *\n"
			<< "* 8) Show number of All musicians have recorded over the years.\t\t\t\t\t   *\n* 9) Show the musician who cooperated with the largest number other musicians.\t\t\t   *\n* 10) Show the most popular song genre over the years.\t\t\t\t\t\t   *\n"
			<< "* 11) Show the recording technician who recorded the largest number of songs between two dates.\t   *\n* 12) Show the first album recorded in the studio.\t\t\t\t\t\t   *\n* 13) Show All songs in 2 or more albums.\t\t\t\t\t\t\t   *\n"
			<< "* 14) Show ALL of technicians who have shared the recording of an entire album.\t\t\t   *\n* 15) Show who is the most versatile musician.\t\t\t\t\t\t\t   *\n* "
			<< "99) End the program.\t\t\t\t\t\t\t\t\t\t   *\n"
			<< "****************************************************************************************************\nYour Choice:> ";
		cin >> choice;
		switch (choice) {

		case 99: {
			continue;
		}

		case 1: {
			cout << "Enter two date: year-month-day , example: 2018-01-01" << endl;
			string date1;
			string date2;
			cout << "Date 1 : ";
			cin >> date1;
			cout << "Date 2 : ";
			cin >> date2;
			pDb->query1(date1, date2);
			break;
		}

		case 2: {
			cout << "Enter two date: year-month-day , example: 2018-01-01" << endl;
			string date1;
			string date2;
			cout << "Date 1 : " ;
			cin >> date1;
			cout << "Date 2 : " ;
			cin >> date2;
			cout << "* At the beginning of each name a capital letter is required *" << endl;
			std::string name;
			std::cout << "Please, enter musician full name: ";
			cin.ignore();
			std::getline(std::cin, name);
	

			pDb->query2(date1, date2, name);
			break;
		}

		case 3: {
			cout << "Enter two date: year-month-day , example: 2018-01-01" << endl;
			string date1;
			string date2;
			cout << "Date 1 : ";
			cin >> date1;
			cout << "Date 2 : ";
			cin >> date2;
			cout << "* At the beginning of each name a capital letter is required *" << endl;
			std::string name;
			std::cout << "Please, enter musician full name: ";
			cin.ignore();
			std::getline(std::cin, name);
	

			pDb->query3(date1, date2, name);
			break;
		}
		case 4: {
			pDb->query4();
			break;
		}
		case 5: {
			cout << "* At the beginning of each name a capital letter is required *" << endl;
			std::string name;
			std::cout << "Please, enter album full name: ";
			cin.ignore();
			std::getline(std::cin, name);
	

			pDb->query5(name);
			break;
		}

		case 6: {
			cout << "Enter two date: year-month-day , example: 2018-01-01" << endl;
			string date1;
			string date2;
			cout << "Date 1 : ";
			cin >> date1;
			cout << "Date 2 : ";
			cin >> date2;

			pDb->query6(date1, date2);
			break;
		}

		case 7: {
			pDb->query7();
			break;
		}
		case 8: {
			pDb->query8();
			break;
		}

		case 9: {
			pDb->query9();
			break;
		}

		case 10: {
			pDb->query10();
			break;
		}

		case 11: {
			cout << "Enter two date: year-month-day , example: 2018-01-01" << endl;
			string date1;
			string date2;
			cout << "Date 1 : ";
			cin >> date1;
			cout << "Date 2 : ";
			cin >> date2;

			pDb->query11(date1, date2);
			break;
		}
		case 12: {
			pDb->query12();
			break;
		}
		case 13: {
			pDb->query13();
			break;
		}
		case 14: {
			pDb->query14();
			break;
		}
		case 15: {
			pDb->query15();
			break;
		}

		}
		
	}
	getchar();
	delete pDb;
	return 0;
}


