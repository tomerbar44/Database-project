#include <mysqlx/xapi.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "root"

void createDB();
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

int main() {


	createDB();
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

			query1(date1, date2);
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
	

			query2(date1, date2, name);
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
	

			query3(date1, date2, name);
			break;
		}
		case 4: {
			query4();
			break;
		}
		case 5: {
			cout << "* At the beginning of each name a capital letter is required *" << endl;
			std::string name;
			std::cout << "Please, enter album full name: ";
			cin.ignore();
			std::getline(std::cin, name);
	

			query5(name);
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

			query6(date1, date2);			
			break;
		}

		case 7: {
			query7();
			break;
		}
		case 8: {
			query8();	
			break;
		}

		case 9: {
			query9();
			break;
		}

		case 10: {
			query10();
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

			query11(date1, date2);
			break;
		}
		case 12: {
			query12();
			break;
		}
		case 13: {
			query13();
			break;
		}
		case 14: {
			query14();
			break;
		}
		case 15: {
			query15();
			break;
		}

		}
		
	}
	getchar();
	return 0;
}



mysqlx_session_t* startup() {
	char err_msg[256] = {};
	int err_code = 0;

	//creration of an sql connection aka session to the mysql server
	mysqlx_session_t* sess = mysqlx_get_session(DB_HOST, DEFAULT_MYSQLX_PORT, DB_USER, DB_PASS, "", err_msg, &err_code);
	if (NULL == sess) {
		cerr << err_msg << endl;
		exit(err_code);
	}
	return sess;
}

void createDB() {

	//creration of an sql connection aka session to the mysql server
	char err_msg[256] = {};
	int err_code = 0;
	mysqlx_session_t* sess = mysqlx_get_session(DB_HOST, DEFAULT_MYSQLX_PORT, DB_USER, DB_PASS, "", err_msg, &err_code);
	if (NULL == sess) {
		cerr << err_msg << endl;
		exit(err_code);
	}
	//******* create all the tables *******
	
	char* query1 = { "DROP DATABASE `music_world`;" };
	mysqlx_result_t* res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);

	query1 = { "CREATE DATABASE  IF NOT EXISTS `music_world`;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);

	query1 = { "USE `music_world`;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}

	// 1.create album table
	query1 = { "DROP TABLE IF EXISTS `album`;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "CREATE TABLE `music_world`.`album` (`ID` int(11) NOT NULL,`START_DATE` date DEFAULT NULL,`END_DATE` date DEFAULT NULL,`NUM_OF_SONGS` int(11) DEFAULT NULL,`NAME` varchar(45) DEFAULT NULL,PRIMARY KEY(`ID`))" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	// 2.create instrument table
	query1 = { "DROP TABLE IF EXISTS `instrument`;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "CREATE TABLE `instrument` (`ID` int(11) NOT NULL,`NAME` varchar(45) DEFAULT NULL,`TYPE` varchar(45) DEFAULT NULL,`MANUFACTURER_NAME` varchar(45) DEFAULT NULL,PRIMARY KEY(`ID`));" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	// 3.create persona table
	query1 = { "DROP TABLE IF EXISTS `persona`;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "CREATE TABLE `persona` ("\
		"`ID` int(11) NOT NULL,"\
		"`NAME` varchar(45) DEFAULT NULL,"\
		"`ADDRESS` varchar(45) DEFAULT NULL,"\
		"`PHONE` varchar(45) DEFAULT NULL,"\
		"`INFO` varchar(200) DEFAULT NULL,"\
		"PRIMARY KEY(`ID`)); " };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}

	// 4.create role table
	query1 = { "DROP TABLE IF EXISTS `role`;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "CREATE TABLE `role` (`ID` int(11) NOT NULL,`NAME` varchar(45) DEFAULT NULL,PRIMARY KEY(`ID`));" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	// 5.create track table
	query1 = { "DROP TABLE IF EXISTS `track`;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "CREATE TABLE `track` ("\
		"`ID` int(11) NOT NULL,"\
		"`NAME` varchar(45) DEFAULT NULL,"\
		"`TYPE` varchar(45) DEFAULT NULL,"\
		"`AUTHOR_ID` int(11) DEFAULT NULL,"\
		"`COMPOSER_ID` int(11) DEFAULT NULL,"\
		"`DURATION` varchar(45) DEFAULT NULL,"\
		"`GENRE` varchar(45) DEFAULT NULL,"\
		"`RECORDING_TECHNITIAN_ID` int(11) DEFAULT NULL,"\
		"`RECORDING_DATE` date DEFAULT NULL,"\
		"PRIMARY KEY(`ID`),"\
		"KEY `AUTHOR_ID_idx` (`AUTHOR_ID`),"\
		"KEY `COMPOSER_ID_idx` (`COMPOSER_ID`),"\
		"KEY `RECORDING_TECHNITIAN_ID_idx` (`RECORDING_TECHNITIAN_ID`),"\
		"CONSTRAINT `AUTHOR_ID` FOREIGN KEY(`AUTHOR_ID`) REFERENCES `persona` (`ID`),"\
		"CONSTRAINT `COMPOSER_ID` FOREIGN KEY(`COMPOSER_ID`) REFERENCES `persona` (`ID`),"\
		"CONSTRAINT `RECORDING_TECHNITIAN_ID` FOREIGN KEY(`RECORDING_TECHNITIAN_ID`) REFERENCES `persona` (`ID`)"\
		") ENGINE = InnoDB DEFAULT CHARSET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci; " };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	// 6.create track_instruments table
	query1 = { "DROP TABLE IF EXISTS `track_instruments`;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "CREATE TABLE `track_instruments` ("\
		"`TRACK_ID` int(11) NOT NULL,"\
		"`INSTRUMENT_ID` int(11) NOT NULL,"\
		"PRIMARY KEY(`TRACK_ID`,`INSTRUMENT_ID`),"\
		"KEY `INSRUMENT_ID2_idx` (`INSTRUMENT_ID`),"\
		"CONSTRAINT `INSRUMENT_ID2` FOREIGN KEY(`INSTRUMENT_ID`) REFERENCES `instrument` (`ID`),"\
		"CONSTRAINT `TRACK_ID3` FOREIGN KEY(`TRACK_ID`) REFERENCES `track` (`ID`)"\
		") ENGINE = InnoDB DEFAULT CHARSET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci; " };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	// 7.create persona_roles table
	query1 = { "DROP TABLE IF EXISTS `persona_roles`;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "CREATE TABLE `persona_roles` ("\
		"`PERSONA_ID` int(11) NOT NULL,"\
		"`ROLE_ID` int(11) NOT NULL,"\
		"PRIMARY KEY(`PERSONA_ID`,`ROLE_ID`),"\
		"KEY `id_idx` (`ROLE_ID`),"\
		"CONSTRAINT `PERSONA_ID` FOREIGN KEY(`PERSONA_ID`) REFERENCES `persona` (`ID`),"\
		"CONSTRAINT `ROLE_ID` FOREIGN KEY(`ROLE_ID`) REFERENCES `role` (`ID`)"\
		") ENGINE = InnoDB DEFAULT CHARSET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci; " };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	// 8.create album_producers table
	query1 = { "DROP TABLE IF EXISTS `album_producers`;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "CREATE TABLE `album_producers` ("\
		"`ALBUM_ID` int(11) NOT NULL,"\
		"`PRODUCER_ID` int(11) NOT NULL,"\
		"PRIMARY KEY(`ALBUM_ID`,`PRODUCER_ID`),"\
		"KEY `PRODUCER_ID_idx` (`PRODUCER_ID`),"\
		"CONSTRAINT `ALBUM_ID` FOREIGN KEY(`ALBUM_ID`) REFERENCES `album` (`ID`),"\
		"CONSTRAINT `PRODUCER_ID` FOREIGN KEY(`PRODUCER_ID`) REFERENCES `persona` (`ID`)"\
		") ENGINE = InnoDB DEFAULT CHARSET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci; " };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	// 9.create album_tracks table

	query1 = { "DROP TABLE IF EXISTS `album_tracks`;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "CREATE TABLE `album_tracks` ("\
		"`ALBUM_ID` int(11) NOT NULL,"\
		"`TRACK_ID` int(11) NOT NULL,"\
		"PRIMARY KEY(`ALBUM_ID`,`TRACK_ID`),"\
		"KEY `TRACK_ID_idx` (`TRACK_ID`),"\
		"CONSTRAINT `ALBUM_ID2` FOREIGN KEY(`ALBUM_ID`) REFERENCES `album` (`ID`),"\
		"CONSTRAINT `TRACK_ID` FOREIGN KEY(`TRACK_ID`) REFERENCES `track` (`ID`)"\
		") ENGINE = InnoDB DEFAULT CHARSET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci; " };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	// 10.create musician_instruments table
	query1 = { "DROP TABLE IF EXISTS `musician_instruments`;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "CREATE TABLE `musician_instruments` ("\
		"`MUSICIAN_ID` int(11) NOT NULL,"\
		"`INSTRUMENT_ID` int(11) NOT NULL,"\
		"PRIMARY KEY(`MUSICIAN_ID`,`INSTRUMENT_ID`),"\
		"KEY `INSTRUMENT_ID_idx` (`INSTRUMENT_ID`),"\
		"CONSTRAINT `INSTRUMENT_ID` FOREIGN KEY(`INSTRUMENT_ID`) REFERENCES `instrument` (`ID`),"\
		"CONSTRAINT `MUCISIAN_ID` FOREIGN KEY(`MUSICIAN_ID`) REFERENCES `persona` (`ID`)"\
		") ENGINE = InnoDB DEFAULT CHARSET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci; " };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	// 11.create musician_tracks table

	query1 = { "DROP TABLE IF EXISTS `musician_tracks`;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "CREATE TABLE `musician_tracks` ("\
		"`MUSICIAN_ID` int(11) NOT NULL,"\
		"`TRACK_ID` int(11) NOT NULL,"\
		"PRIMARY KEY(`MUSICIAN_ID`,`TRACK_ID`),"\
		"KEY `TRACK_ID_idx` (`TRACK_ID`),"\
		"CONSTRAINT `MUSICIAN_ID` FOREIGN KEY(`MUSICIAN_ID`) REFERENCES `persona` (`ID`),"\
		"CONSTRAINT `TRACK_ID2` FOREIGN KEY(`TRACK_ID`) REFERENCES `track` (`ID`)"\
		") ENGINE = InnoDB DEFAULT CHARSET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci; " };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	//******* insert data to all the tables *******

	// 1.insert data to album table

	query1 = { "LOCK TABLES `album` WRITE;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "INSERT INTO `album` VALUES"\
		"(1,'2018-01-01','2018-01-02',10,'Simla Levana'),"\
		"(2,'2018-01-01','2018-01-02',8,'Yalduti Hashniya')"\
		",(3,'2018-01-01','2018-01-02',12,'Dark Side Of The Moon')"\
		",(4,'2015-01-02','2015-01-02',19,'The Best of Arik Einstein')"\
		",(5,'1995-07-02','1995-10-02',8,'Fragile')"\
		",(6,'1984-07-02','1984-10-02',10,'Timeout'),"\
		"(7,'1972-02-02','1972-12-02',13,'Love To Be Home'),"\
		"(8,'1987-07-02','1987-12-10',10,'Filled With Love'),"\
		"(9,'1973-01-02','1973-07-02',14,'The Good Old Land Of Israel'),"\
		"(10,'1999-01-02','1999-05-02',13,'Muscat');" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "UNLOCK TABLES;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}


	// 2.insert data to instrument table

	query1 = { "LOCK TABLES `instrument` WRITE;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "INSERT INTO `instrument` VALUES (1,'PIANO','classic','Halilit'),(2,'GUITAR','classic','Halilit'),(3,'Accordion','classic','Kley Zemer'),(4,'Acoustic bass guitar','bass','Kley Zemer'),(5,'Acoustic guitar','bass','Kley Zemer'),(6,'Alto saxophone','classic','Halilit'),(7,'Baritone horn','classic','Halilit'),(8,'Bass drum','bass','Halilit'),(9,'Bass guitar','bass','Halilit'),(10,'Cello','classic','Kley Zemer');" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "UNLOCK TABLES;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	// 3.insert data to persona table

	query1 = { "LOCK TABLES `persona` WRITE;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "INSERT INTO `persona` VALUES(1,'Omer Adam','Bialik 12','054-5417741','very talented'),(2,'Shalom Hanoch','Bialik 28 ','055-4514447',NULL),(3,'Samir Shukri','Nisim 18','054-5689741',NULL),(4,'Amir BenAion','Narkis 24','052-5689745',NULL),(5,'Ivri Lider','Gordon 108','050-5894789',NULL),(6,'Aviv Geffen','Rivkin 222','052-3568478',NULL),(7,'Matti Caspi','HaTavor 12','053-4568259',NULL),(8,'Yossi Gispan','Haim 44','055-5897458',NULL),(9,'Idan Raichel','Israeli 24','055-7894128',NULL),(10,'Jordi','HaShalom 32','052-4789541',NULL),(11,'Arik Einshtin','israel 2','052-2232321',NULL),(12,'Miki Gavrirlov','TelAviv 12','052-2321346',NULL),(13,'Shem Tov Levi','Sharon 1','052-9948695',NULL),(14,'Yoni Rehter','Dekel 13','052-3837483',NULL); " };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "UNLOCK TABLES;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}

	// 4.insert data to role table

	query1 = { "LOCK TABLES `role` WRITE;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "INSERT INTO `role` VALUES (1,'Singer'),(2,'Player'),(3,'Producer'),(4,'Technician'),(5,'Author'),(6,'Composer'); " };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "UNLOCK TABLES;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}

	// 5.insert data to track table

	query1 = { "LOCK TABLES `track` WRITE;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}

	query1 = { "INSERT INTO `track` VALUES (1,'LEAT-LEAT','SONG',2,2,'2:32','ROCK',12,'2018-01-01'),"\
		"(2,'Perach','SONG',1,2,'2:44','ROCK',12,'2018-01-01'),(3,'Simla Levane','SONG',2,2,'2:22','DANCE',12,'2018-01-01')"\
		",(4,'The long sad days','SONG',11,12,'2:32','CLASSIC',10,'1995-07-02'),(5,'What was','SONG',11,12,'2:32','CLASSIC',10,'1972-02-02')"\
		",(6,'San Francisco on the water','SONG',11,14,'2:22','CLASSIC',10,'1987-07-02'),(7,'A wooden horse','SONG',12,13,'2:22','CLASSIC',10,'1995-07-02')"\
		",(8,'Lullaby','SONG',11,12,'3:10','CLASSIC',10,'1999-01-10'),(9,'Finish','SONG',11,13,'2:32','CLASSIC',10,'1973-01-02')"\
		",(10,'She sat down at the window','SONG',13,14,'2:44','CLASSIC',10,'1999-01-12')"\
		",(11,'Bring me under your wing','SONG',12,13,'2:32','CLASSIC',10,'1984-07-22')"\
		",(12,'Sitting on the fence','SONG',11,14,'2:44','CLASSIC',10,'1999-01-16')"\
		",(13,'Madness in the stage','SONG',11,11,'2:32','CLASSIC',10,'1987-07-04')"\
		",(14,'Praise the Samba','SONG',14,11,'2:22','CLASSIC',10,'1987-07-11')"\
		",(15,'Fragile','SONG',11,13,'2:22','CLASSIC',10,'1987-07-08')"\
		",(16,'One hand does it','SONG',13,14,'2:22','CLASSIC',10,'1987-07-09')"\
		",(17,'He still met','SONG',14,12,'2:32','CLASSIC',10,'1995-08-02')"\
		",(18,'Ayelet Loves','SONG',11,11,'3:10','CLASSIC',10,'1995-08-02')"\
		",(19,'Timeout','SONG',11,11,'2:22','CLASSIC',10,'1984-08-02'),(20,'Three to four work','SONG',11,14,'2:32','CLASSIC',10,'1984-08-02')"\
		",(21,'He became religious','SONG',12,13,'3:10','CLASSIC',10,'1984-08-02')"\
		",(22,'Made in Israel','SONG',11,13,'2:22','CLASSIC',10,'1984-08-02');" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "UNLOCK TABLES;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}

	// 6.insert data to persona_roles table

	query1 = { "LOCK TABLES `persona_roles` WRITE;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "INSERT INTO `persona_roles` VALUES (1,1),(2,1),(11,1),(12,1),(2,3),(7,3),(14,3),(10,4),(2,5),(11,5),(12,5),(13,5),(2,6),(11,6),(12,6),(13,6),(14,6);" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "UNLOCK TABLES;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	// 7.insert data to track_instruments table

	query1 = { "LOCK TABLES `track_instruments` WRITE;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "INSERT INTO `track_instruments` VALUES (1,1),(5,1),(8,1),(9,1),(10,1),(11,1),(12,1),(13,1),(14,1),(16,1),(17,1),(18,1),(19,1),(20,1),(21,1),(22,1),(1,2),(2,2),(4,2),(5,2),(7,2),(9,2),(10,2),(11,2),(12,2),(13,2),(14,2),(16,2),(17,2),(18,2),(19,2),(20,2),(21,2),(4,3),(7,3),(10,3),(12,3),(13,3),(16,3),(17,3),(18,3),(19,3),(20,3),(21,3),(4,4),(13,4),(14,4),(21,4),(4,5),(6,5),(7,5),(8,5),(22,5),(4,6),(15,6),(5,7),(15,7),(6,8),(8,8),(15,8),(8,9),(9,10);" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "UNLOCK TABLES;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}

	// 8.insert data to album_producers table

	query1 = { "LOCK TABLES `album_producers` WRITE;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "INSERT INTO `album_producers` VALUES (1,2),(3,4),(1,7),(2,7),(4,14),(5,14),(6,14),(7,14),(8,14),(9,14),(10,14);" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "UNLOCK TABLES;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}

	// 9.insert data to album_tracks table

	query1 = { "LOCK TABLES `album_tracks` WRITE;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "INSERT INTO `album_tracks` VALUES (1,1),(2,3),(4,4),(5,4),(4,5),(7,5),(4,6),(8,6),(4,7),(5,7),(4,8),(10,8),(4,9),(9,9),(4,10),(10,10),(4,11),(6,11),(4,12),(10,12),(4,13),(8,13),(4,14),(8,14),(4,15),(8,15),(4,16),(8,16),(4,17),(5,17),(4,18),(5,18),(4,19),(6,19),(6,20),(4,20),(4,21),(4,22),(6,22);" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "UNLOCK TABLES;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}

	// 10.insert data to musician_tracks table

	query1 = { "LOCK TABLES `musician_tracks` WRITE;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "INSERT INTO `musician_tracks` VALUES (1,1),(1,2),(2,3),(4,4),(11,4),(4,5),(11,5),(11,6),(12,6),(11,7),(11,8),(12,9),(3,10),(4,10),(11,10),(11,11),(11,12),(12,13),(1,14),(11,14),(5,15),(12,15),(11,16),(11,17),(11,18),(11,19),(11,20),(11,21),(11,22);" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "UNLOCK TABLES;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}

	// 11.insert data to musician_instruments table

	query1 = { "LOCK TABLES `musician_instruments` WRITE;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "INSERT INTO `musician_instruments` VALUES (1,1),(4,1),(5,1),(6,1),(7,1),(8,1),(11,1),(12,1),(13,1),(14,1),(10,2),(11,2),(12,2),(2,3),(3,3),(7,3),(11,3),(14,3),(1,5),(12,5);" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	query1 = { "UNLOCK TABLES;" };
	res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	mysqlx_session_close(sess);
}

void query1(string date1, string date2) {

	//open session with our data base.
	mysqlx_session_t* curSess = startup();
	char query1[] = { "USE `music_world`;" };
	mysqlx_result_t* res = mysqlx_sql(curSess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}
	string s = "\"";
	date1 = s + date1;
	date1 = date1 + s;
	date2 = s + date2;
	date2 = date2 + s;

	string q = { "select count(a.name) "\
		"FROM music_world.album a "\
	"where a.start_date >= DATE("\
	+ date1 + ")"\
	"and a.end_date <= DATE("\
	 + date2 + "); " };
	char char_array[1000];

	// copying the contents of the 
	// string to char array 
	strcpy_s(char_array, q.c_str());



	int64_t x;
	res = mysqlx_sql(curSess, char_array, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_sint(row, 0, &x);
				cout << "Number Of Albums: " << x << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}

	// close the session
	mysqlx_session_close(curSess);
}

void query2(string date1, string date2, string name)
{
	//open session with our data base.
	mysqlx_session_t* curSess = startup();
	char query1[] = { "USE `music_world`;" };
	mysqlx_result_t* res = mysqlx_sql(curSess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}
	string s = "\"";
	date1 = s + date1;
	date1 = date1 + s;
	date2 = s + date2;
	date2 = date2 + s;


	string q = { "select count(t.id) songs "\
		"from music_world.track t,"\
		"music_world.persona m,"\
		"music_world.musician_tracks mt,"\
		"music_world.persona_roles pr,"\
		"music_world.role r "\
		"where t.id = mt.track_id "\
		"and m.id = mt.musician_id "\
		"and m.id = pr.persona_id "\
		"and r.id = pr.role_id "\
		"and r.name in('Singer','Player') "\
		"and t.recording_date between DATE("\
		+ date1 + ") and DATE("\
		+ date2 + ")"\
		"and m.name = '"\
		+ name + "';" };


	char char_array[1000];

	// copying the contents of the 
	// string to char array 
	strcpy_s(char_array, q.c_str());


	int64_t x;
	res = mysqlx_sql(curSess, char_array, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_sint(row, 0, &x);
				cout << "Number Of Songs: " << x << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}


	// close the session
	mysqlx_session_close(curSess);
}

void query3(string date1, string date2, string name)
{
	//open session with our data base.
	mysqlx_session_t* curSess = startup();
	char query1[] = { "USE `music_world`;" };
	mysqlx_result_t* res = mysqlx_sql(curSess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}
	string s = "\"";
	date1 = s + date1;
	date1 = date1 + s;
	date2 = s + date2;
	date2 = date2 + s;


	string q = { "select count(a.id) albums "\
		"from music_world.track t,"\
		"music_world.persona m,"\
		"music_world.musician_tracks mt,"\
		"music_world.persona_roles pr,"\
		"music_world.role r,"\
		"music_world.album a,"\
		"music_world.album_tracks atr "\
		"where t.id = mt.track_id "\
		"and m.id = mt.musician_id "\
		"and m.id = pr.persona_id "\
		"and r.id = pr.role_id "\
		"and r.name in('Singer','Player') "\
		"and a.id = atr.album_id "\
		"and t.id = atr.track_id "\
		"and ((a.start_date between DATE("\
		+ date1 + ") and DATE("\
		+ date2 + ")) OR(a.end_date between DATE("\
		+ date1 + ") and DATE("\
		+ date2 + ")) "\
		"OR(DATE("\
		+ date1 + ") between a.start_date and a.end_date)) "\
		"and m.name = '"\
		+ name + "';" };



	char char_array[1000];

	// copying the contents of the 
	// string to char array 
	strcpy_s(char_array, q.c_str());


	int64_t x;
	res = mysqlx_sql(curSess, char_array, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_sint(row, 0, &x);
				cout << "Number Of Albums: " << x << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}


	// close the session
	mysqlx_session_close(curSess);

}

void query4()
{
	//open session with our data base.
	mysqlx_session_t* curSess = startup();
	char query1[] = { "USE `music_world`;" };
	mysqlx_result_t* res = mysqlx_sql(curSess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}



	string q = { "with tracks_per_instrument as "\
		"(select ti.instrument_id, count(ti.track_id) cnt "\
		"from music_world.track_instruments ti "\
		"group by ti.instrument_id) "\
		"select i.name "\
		"from tracks_per_instrument t, "\
		"music_world.instrument i "\
		"where t.cnt = (select max(t1.cnt) "\
		"from tracks_per_instrument t1) "\
		"and t.instrument_id = i.id;" };



	char char_array[1000];

	// copying the contents of the 
	// string to char array 
	strcpy_s(char_array, q.c_str());


	res = mysqlx_sql(curSess, char_array, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;
		int i = 1;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << i << ". " << buff << endl;
				i++;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}

	// close the session
	mysqlx_session_close(curSess);
}

void query5(string album_name)
{
	//open session with our data base.
	mysqlx_session_t* curSess = startup();
	char query1[] = { "USE `music_world`;" };
	mysqlx_result_t* res = mysqlx_sql(curSess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}



	string q = { "select distinct(i.name)  "\
		"from music_world.instrument i,"\
		"music_world.album a,"\
		"music_world.track t,"\
		"music_world.track_instruments ti,"\
		"music_world.album_tracks atr "\
		"where atr.album_id = a.id "\
		"and atr.TRACK_ID = t.id "\
		"and ti.track_id = t.id "\
		"and ti.instrument_id = i.id "\
		"and a.name ='"\
		+ album_name + "';" };
		
	


	char char_array[1000];

	// copying the contents of the 
	// string to char array 
	strcpy_s(char_array, q.c_str());


	res = mysqlx_sql(curSess, char_array, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;
		int i = 1;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << i << ". " << buff << endl;
				i++;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}

	// close the session
	mysqlx_session_close(curSess);
}

void query6(string date1, string date2)
{
	//open session with our data base.
	mysqlx_session_t* curSess = startup();
	char query1[] = { "USE `music_world`;" };
	mysqlx_result_t* res = mysqlx_sql(curSess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}
	string s = "\"";
	date1 = s + date1;
	date1 = date1 + s;
	date2 = s + date2;
	date2 = date2 + s;

	string q = { "with albums_per_producer as "\
		"(select p.name, p.id, count(a.id) album_cnt "\
		"from music_world.album a,"\
		"music_world.album_producers ap,"\
		"music_world.persona p,"\
		"music_world.role r,"\
		"music_world.persona_roles pr "\
		"where r.name = 'Producer' "\
		"and pr.role_id = r.id "\
		"and pr.persona_id = p.id "\
		"and ap.album_id = a.id "\
		"and ap.producer_id = p.id "\
		"and a.start_date between DATE("\
		+ date1 + ") and DATE("\
		+ date2 + ") "\
		"and a.end_date between DATE("\
		+ date1 + ") and DATE("\
		+ date2 + ")"\
		"group by p.name, p.id)"\
		"select t.name from albums_per_producer t "\
		"where t.album_cnt = (select max(album_cnt) from albums_per_producer t1); " };

	char char_array[1000];

	// copying the contents of the 
	// string to char array 
	strcpy_s(char_array, q.c_str());



	res = mysqlx_sql(curSess, char_array, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << buff << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}

	// close the session
	mysqlx_session_close(curSess);
}

void query7()
{
	//open session with our data base.
	mysqlx_session_t* curSess = startup();
	char query1[] = { "USE `music_world`;" };
	mysqlx_result_t* res = mysqlx_sql(curSess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}



	string q = { "with tracks_per_instrument as "\
		"(select ti.instrument_id, count(ti.track_id) cnt "\
		"from music_world.track_instruments ti "\
		"group by ti.instrument_id) "\
		"select i.manufacturer_name "\
		"from tracks_per_instrument t, "\
		"music_world.instrument i "\
		"where t.cnt = (select max(t1.cnt) "\
		"from tracks_per_instrument t1) "\
		"and t.instrument_id = i.id; " };



	char char_array[1000];

	// copying the contents of the 
	// string to char array 
	strcpy_s(char_array, q.c_str());


	res = mysqlx_sql(curSess, char_array, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << buff << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}

	// close the session
	mysqlx_session_close(curSess);
}

void query8()
{
	//open session with our data base.
	mysqlx_session_t* curSess = startup();
	char query1[] = { "USE `music_world`;" };
	mysqlx_result_t* res = mysqlx_sql(curSess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}
	string q = { "select count(distinct mt.musician_id) musician_cnt from music_world.musician_tracks mt;" };
	char char_array[1000];
	// copying the contents of the 
	// string to char array 
	strcpy_s(char_array, q.c_str());
	int64_t x;
	res = mysqlx_sql(curSess, char_array, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_sint(row, 0, &x);
				cout << "Number Of All Musicians: " << x << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}

	// close the session
	mysqlx_session_close(curSess);
}

void query9()
{
	//open session with our data base.
	mysqlx_session_t* curSess = startup();
	char query1[] = { "USE `music_world`;" };
	mysqlx_result_t* res = mysqlx_sql(curSess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}
	string q = { "with partners as "\
		"(select mt.musician_id, p.name, count(*) partners_cnt "\
		"from music_world.musician_tracks mt, "\
		"music_world.track t, "\
		"music_world.persona p, "\
		"music_world.role r, "\
		"music_world.persona_roles pr, "\
		"music_world.musician_tracks mt1, "\
		"music_world.role r1, "\
		"music_world.persona_roles pr1 "\
		"where mt.musician_id = p.id "\
		"and mt.track_id = t.id "\
		"and pr.persona_id = p.id "\
		"and pr.role_id = r.id "\
		"and r.name in('Singer','Player')"\
		"and mt.TRACK_ID = mt1.TRACK_ID "\
		"and pr1.role_id = r1.id "\
		"and r1.name in('Singer','Player') "\
		"and pr1.persona_id = mt1.musician_id "\
		"and mt.musician_id != mt1.musician_id "\
		"group by mt.musician_id,p.name) "\
		"select t.name from partners t "\
		"where t.partners_cnt in(select max(partners_cnt) from partners t1); " };

	char char_array[1000];

	// copying the contents of the 
	// string to char array 
	strcpy_s(char_array, q.c_str());


	res = mysqlx_sql(curSess, char_array, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;


		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << buff << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}

	// close the session
	mysqlx_session_close(curSess);
}

void query10()
{
	//open session with our data base.
	mysqlx_session_t* curSess = startup();
	char query1[] = { "USE `music_world`;" };
	mysqlx_result_t* res = mysqlx_sql(curSess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}

	string q = { "with tracks_per_genre as "\
		"(select t.GENRE, count(*) cnt "\
		"from music_world.track t "\
		"group by t.GENRE) "\
		"select t.genre from tracks_per_genre t "\
		"where t.cnt = (select max(t1.cnt) from tracks_per_genre t1); " };

	char char_array[1000];

	// copying the contents of the 
	// string to char array 
	strcpy_s(char_array, q.c_str());

	res = mysqlx_sql(curSess, char_array, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;
	

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << buff << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}

	// close the session
	mysqlx_session_close(curSess);
}

void query11(string date1, string date2)
{
	//open session with our data base.
	mysqlx_session_t* curSess = startup();
	char query1[] = { "USE `music_world`;" };
	mysqlx_result_t* res = mysqlx_sql(curSess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}
	string s = "\"";
	date1 = s + date1;
	date1 = date1 + s;
	date2 = s + date2;
	date2 = date2 + s;

	string q = { "with tracks_per_technitian as "\
		"(select p.id, p.name, count(t.id) track_cnt "\
		"from music_world.track t, "\
		"music_world.persona p "\
		"where t.recording_technitian_id = p.id "\
		"and t.recording_date between DATE("\
		+ date1 + ") and DATE("\
		+ date2 + ") "\
		"group by p.id, p.name) "\
		"select t.name from tracks_per_technitian t "\
		"where t.track_cnt = (select max(t1.track_cnt) from tracks_per_technitian t1); " };

	char char_array[1000];

	// copying the contents of the 
	// string to char array 
	strcpy_s(char_array, q.c_str());

	res = mysqlx_sql(curSess, char_array, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;
		

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << buff << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}

	// close the session
	mysqlx_session_close(curSess);
}

void query12()
{
	//open session with our data base.
	mysqlx_session_t* curSess = startup();
	char query1[] = { "USE `music_world`;" };
	mysqlx_result_t* res = mysqlx_sql(curSess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}
	string q = { "SELECT music_world.album.name FROM music_world.album WHERE end_date = (SELECT MIN(end_date) FROM music_world.album); " };
	char char_array[1000];

	// copying the contents of the 
	// string to char array 
	strcpy_s(char_array, q.c_str());
	res = mysqlx_sql(curSess, char_array, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;


		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << buff << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}

	// close the session
	mysqlx_session_close(curSess);
}

void query13()
{
	//open session with our data base.
	mysqlx_session_t* curSess = startup();
	char query1[] = { "USE `music_world`;" };
	mysqlx_result_t* res = mysqlx_sql(curSess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}
	string q = { "select t.name "\
		"from(select atr.TRACK_ID, count(atr.album_id) cnt "\
		"from music_world.album_tracks atr "\
		"group by atr.TRACK_ID "\
		"having cnt >= 2) t1, "\
		"music_world.track t "\
		"where t1.track_id = t.id;" };

	char char_array[1000];

	// copying the contents of the 
	// string to char array 
	strcpy_s(char_array, q.c_str());

	res = mysqlx_sql(curSess, char_array, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;
		int i = 1;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << i << ". " << buff << endl;
				i++;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}

	// close the session
	mysqlx_session_close(curSess);
}

void query14()
{
	//open session with our data base.
	mysqlx_session_t* curSess = startup();
	char query1[] = { "USE `music_world`;" };
	mysqlx_result_t* res = mysqlx_sql(curSess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}

	string q = { "with technitian_songs_per_album as "\
		"(select p.id tecnician_id, p.name tecnician_name, a.id album_id, count(t.id) track_cnt "\
		"from  music_world.track t, "\
		"music_world.persona p, "\
		"music_world.album a, "\
		"music_world.album_tracks s "\
		"where t.recording_technitian_id = p.id "\
		"and a.id = s.album_id "\
		"and t.id = s.track_id "\
		"group by p.id, p.name, a.id) "\
		"select distinct t.tecnician_name "\
		"from music_world.album a, technitian_songs_per_album t "\
		"where a.id = t.album_id "\
		"And a.num_of_songs = t.track_cnt; " };

	char char_array[1000];

	// copying the contents of the 
	// string to char array 
	strcpy_s(char_array, q.c_str());


	res = mysqlx_sql(curSess, char_array, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;
		int i = 1;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << i << ". " << buff << endl;
				i++;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}

	// close the session
	mysqlx_session_close(curSess);

}

void query15()
{
	//open session with our data base.
	mysqlx_session_t* curSess = startup();
	char query1[] = { "USE `music_world`;" };
	mysqlx_result_t* res = mysqlx_sql(curSess, query1, MYSQLX_NULL_TERMINATED);
	if (res == NULL) {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}

	string q = { "with genre_per_musician as "\
		"(select p.id, p.name, count(distinct t.genre) genre_cnt "\
		"from music_world.track t, "\
		"music_world.persona p, "\
		"music_world.role r, "\
		"music_world.persona_roles pr, "\
		"music_world.musician_tracks mt "\
		"where mt.musician_id = p.id "\
		"and mt.track_id = t.id "\
		"and pr.persona_id = p.id "\
		"and pr.role_id = r.id "\
		"and r.name in('Singer','Player') "\
		"group by p.id, p.name) "\
		"select t.name from genre_per_musician t "\
		"where t.genre_cnt in(select max(genre_cnt) from genre_per_musician t1); " };

	char char_array[1000];

	// copying the contents of the 
	// string to char array 
	strcpy_s(char_array, q.c_str());


	res = mysqlx_sql(curSess, char_array, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;
		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << buff << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(curSess) << endl;
		exit(mysqlx_error_num(curSess));
	}

	// close the session
	mysqlx_session_close(curSess);
}
