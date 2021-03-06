#include <ctime>
#include <iostream>
#include "cppformat/format.h"


using namespace std;

string time2s(time_t t) {
    struct tm * now = localtime( & t );
	auto s = fmt::format("{:0>2}:{:0>2}", now->tm_hour, now->tm_min);
	return s;
}

string curTime2s() {
	return time2s(time(0));
}

time_t todayAtNow() {
	time_t t = time(0);   // get time now
	return t;
}

string diffTime(time_t s, time_t d) {
	int df  = difftime(d, s);
	auto sign = "";
	if(df < 0) {
		sign = "-";
		df = -1 * df;
	}
	auto sec = df % 60;
	df = df / 60;
	int hr  = df / (60);
	int min = (df % 60);
	return fmt::format("{}{:0>2}:{:0>2}:{:0>2}", sign, hr, min, sec);
}


time_t todayAt(int hours, int minutes) {
	time_t t = time(0);   // get time now
	struct tm * now = localtime( & t );
	now -> tm_hour = hours;
	now -> tm_min = minutes;
	now -> tm_sec = 0;
	return mktime(now);
}

