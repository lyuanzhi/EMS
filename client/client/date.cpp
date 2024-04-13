#include "date.h"

Date DateClass::getCurrentDate() {

	QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
	QString str_time = time.toString("yyyy-M-d"); //设置显示格式
	QString year = "";
	QString month = "";
	QString day = "";
	int count = 0;

	for (auto& c : str_time) {
		if (count == 0 && c != '-')
			year = year + c;
		if (count == 1 && c != '-')
			month = month + c;
		if (count == 2 && c != '\n')
			day = day + c;
		if (c == '-')
			++count;
	}

	Date date;
	date.year = year;
	date.month = month;
	date.day = day;
	return date;

}

int DateClass::getDayMaxOfMonth(int year, int month) {

	int day_max = 0;
	switch (month)
	{
	case 1:case 3:case 5: case 7:case 8:case 10:case 12: day_max = 31; break;
	case 4:case 6:case 9:case 11: day_max = 30; break;
	case 2:
		//计算闰年
		if ((year % 4 == 0 && year % 100 != 0)
			|| (year % 400 == 0 && year % 3200 != 0)
			|| year % 172800 == 0) {
			day_max = 29;
		}
		else {
			day_max = 28;
		}
		break;
	default:
		break;
	}
	return day_max;

}

int DateClass::getWeekOfMonth(int year, int month) {

	int y = 0, c = 0, m = 0, d = 0, w = 0;
	int day = 1;
	y = year % 100;//年，如2015，即年是15年
	c = year / 100;//年份前两位，如2015即20
	m = month; d = day;
	if (m == 1 || m == 2) { //判断月份是否为1或2
		y--;
		m += 12;//某年的1、2月要看作上一年的13、14月来计算
	}
	w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;//蔡勒公式
	while (w < 0) w += 7;//确保余数为正
	w %= 7;
	if (w == 0) w = 7;

	return w;

}