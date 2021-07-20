#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

vector<string> daysVector = {
	"sunday", "monday", "tuesday", "wednesday", 
	"thursday","friday", "saturday"};
	
time_t GetDate( int day, int month, int year )
{
    struct tm ttm = {0};
    ttm.tm_mday = day;
    ttm.tm_mon = month-1;
    ttm.tm_year = year-1900;
    return mktime(&ttm);
}

string dayofweek(int d, int m, int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    int idx = ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
    return daysVector[idx];
}

void printDate(struct tm *cur) {
	cout << cur->tm_mday << " " << cur->tm_mon+1 << " " << cur->tm_year + 1900 << " ";
	cout << dayofweek(cur->tm_mday,cur->tm_mon+1,cur->tm_year + 1900) << "\n";
}

// eg. check if given day is 4th saturday of the month, given today is saturday
// isNthWeekday(t, cur, 4)
bool isNthWeekday(time_t t, struct tm *cur, int weekNumber) {

	time_t tmp = t - 86400 * 7 * (weekNumber-1);
	int curMonth = cur->tm_mon;
	struct tm *nWeeksBefore = gmtime(&tmp);
	int preMonth = nWeeksBefore->tm_mon;
	
	time_t tmp2 = t - (86400 * 7 * (weekNumber));
	struct tm *nWeeksBefore2 = gmtime(&tmp2);
	int ppeMonth = nWeeksBefore2->tm_mon;
	
	gmtime(&t);
	return curMonth == preMonth && preMonth != ppeMonth;
}
void solve()
{	
	int s_year, s_mon, s_day;
	int e_year, e_mon, e_day;
	
	s_year = 2021;
	s_mon = 7;
	s_day = 20;
	
	e_year = 2021;
	e_mon = 8;
	e_day = 20;
	
	time_t start = GetDate(s_day, s_mon, s_year) + 86400;
	time_t end = GetDate(e_day, e_mon, e_year) + 86400;
	for( time_t t = start; t <= end; t += 86400 )
	{
		struct tm *cur = gmtime(&t);
		printDate(cur);
		if(isNthWeekday(t, cur, 4)) 
			cout << "this is 4th " << dayofweek(cur->tm_mday, cur->tm_mon+1, cur->tm_year+1900) << " of the month\n";
	}
}

signed main()
{
    solve();
}

/*
// ref
// https://www.cplusplus.com/reference/ctime/tm/

Output :

20 7 2021 tuesday
21 7 2021 wednesday
22 7 2021 thursday
this is 4th thursday of the month
23 7 2021 friday
this is 4th friday of the month
24 7 2021 saturday
this is 4th saturday of the month
25 7 2021 sunday
this is 4th sunday of the month
26 7 2021 monday
this is 4th monday of the month
27 7 2021 tuesday
this is 4th tuesday of the month
28 7 2021 wednesday
this is 4th wednesday of the month
29 7 2021 thursday
30 7 2021 friday
31 7 2021 saturday
1 8 2021 sunday
2 8 2021 monday
3 8 2021 tuesday
4 8 2021 wednesday
5 8 2021 thursday
6 8 2021 friday
7 8 2021 saturday
8 8 2021 sunday
9 8 2021 monday
10 8 2021 tuesday
11 8 2021 wednesday
12 8 2021 thursday
13 8 2021 friday
14 8 2021 saturday
15 8 2021 sunday
16 8 2021 monday
17 8 2021 tuesday
18 8 2021 wednesday
19 8 2021 thursday
20 8 2021 friday
*/
