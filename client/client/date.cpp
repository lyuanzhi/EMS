#include "date.h"

Date DateClass::getCurrentDate() {

	QDateTime time = QDateTime::currentDateTime();//��ȡϵͳ���ڵ�ʱ��
	QString str_time = time.toString("yyyy-M-d"); //������ʾ��ʽ
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
		//��������
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
	y = year % 100;//�꣬��2015��������15��
	c = year / 100;//���ǰ��λ����2015��20
	m = month; d = day;
	if (m == 1 || m == 2) { //�ж��·��Ƿ�Ϊ1��2
		y--;
		m += 12;//ĳ���1��2��Ҫ������һ���13��14��������
	}
	w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;//���չ�ʽ
	while (w < 0) w += 7;//ȷ������Ϊ��
	w %= 7;
	if (w == 0) w = 7;

	return w;

}