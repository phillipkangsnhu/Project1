//============================================================================
// Name        : Project1.cpp
// Author      : Phillip Kang
// Version     :
// Copyright   : Your copyright notice
// Description : Project One
//============================================================================

#include <iostream>
#include <ctime>
using namespace std;

// "clearing" the screen by making new lines to push old output out of view
void clear_screen(){
	for( int i = 0; i < 40; i++ ){
		cout << endl;
	}
}

// hour12 expected as "HH:MM:SS XX"
// hour24 expected as "HH:MM:SS"
void print_clock(string hour12, string hour24){
	cout << "***************************     ***************************" << endl;
	cout << "*      12-Hour Clock      *     *      24-Hour Clock      *" << endl;
	cout << "*       " << hour12 << "       *     *         " << hour24 << "        *" << endl;
	cout << "***************************     ***************************" << endl;
}

// prints the user menu
void print_menu(){
	cout << "************************" << endl;
	cout << "* 1 - Add One Hour     *" << endl;
	cout << "* 2 - Add One Minute   *" << endl;
	cout << "* 3 - Add One Second   *" << endl;
	cout << "* 4 - Exit Program     *" << endl;
	cout << "************************" << endl;
}

// formatting int to string by making sure single digit numbers have zero prepended
string to_clock_string(int number){
	if(number<10){
		return "0"+to_string(number);
	} else {
		return to_string(number);
	}
}

// returns 12 hour time string in the form of "HH:MM:SS XX"
string format_12_hour_string(int hour, int min, int sec){
	string period = "AM";
	if (hour >= 12){
		period = "PM";
	}

	if (hour == 0){
		hour = 12;
	}
	if (hour >= 13){
		hour -= 12;
	}
	return to_clock_string(hour)+":"+to_clock_string(min)+":"+to_clock_string(sec)+" "+period;
}

// return 24 hour time string in the form of "HH:MM:SS"
string format_24_hour_string(int hour, int min, int sec){
	return to_clock_string(hour)+":"+to_clock_string(min)+":"+to_clock_string(sec);
}

int main() {
	// current date/time based on current system
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int option;

	int hour = ltm->tm_hour;
	int minute = ltm->tm_min;
	int second = ltm->tm_sec;

	// initialize the clock and menu
	print_clock(format_12_hour_string(hour,minute,second), format_24_hour_string(hour,minute,second));
	print_menu();
	cin >> option;

	// main loop
	while(true){
		switch(option){
		case 1:
			hour++;
			break;
		case 2:
			minute++;
			break;
		case 3:
			second++;
			break;
		case 4:
			return 0;
		}

		// properly increment the time
		if (second > 59 ){
			second -= 60;
			minute++;
		}
		if ( minute > 59 ){
			minute -= 60;
			hour++;
		}
		if ( hour > 23 ){
			hour -= 24;
		}

		clear_screen();
		print_clock(format_12_hour_string(hour,minute,second), format_24_hour_string(hour,minute,second));
		print_menu();
		cin >> option;
	}
	return 0;
}

