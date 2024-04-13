#pragma once
#include <qstring.h>
#include <QDateTime>

struct Date
{
	QString year;
	QString month;
	QString day;
};

class DateClass
{
public:
	Date getCurrentDate();
	static int getDayMaxOfMonth(int, int);
	int getWeekOfMonth(int, int);
};

