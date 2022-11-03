#include ".\VTime.h" // This works but is freaky!   I will leave it in so we can talk.

#include <iostream>
#include <chrono>
#include <ctime>
#include "VTime.h"

using namespace std;

// Adds a specified number of seconds onto the time.
void VTime::addSeconds(int a_seconds)
{
	m_SecsSinceMidnight += a_seconds;
	if (m_SecsSinceMidnight = 24) {
		m_SecsSinceMidnight = m_SecsSinceMidnight % 24;
	}
}
VTime VTime::operator +(int a_seconds)
{
	VTime tmp(getHours() / 60, (getMinutes() % 3600) / 60, getSeconds() % 60);
	tmp.addSeconds(a_seconds);
	return tmp;
}
int VTime::operator -(const VTime &a)
{
	if (m_SecsSinceMidnight > a.m_SecsSinceMidnight) {
		m_SecsSinceMidnight = 0;
	}
	else {
		m_SecsSinceMidnight = a.m_SecsSinceMidnight - m_SecsSinceMidnight;
	}
	return m_SecsSinceMidnight;
}
void VTime::PresentTime() {
	auto start = std::chrono::system_clock::now();

	auto end= std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	#pragma warning(suppress : 4996)
	std::cout << "The time is: " << std::ctime(&end_time);
	#pragma warning(suppress : 4996)
	
	std::cout << m_SecsSinceMidnight << endl;
	//std::cout << "The time is: " << m_SecsSinceMidnight.display();
	#pragma warning(suppress : 4996)
}
// Gets the time as an ASCII string
string VTime::getASCIITime()
{
	char buff[128];

	// We will get a special error on this.  I wanted to discuss the error and therefore left this code in.
	sprintf_s(buff, "%2.2d:%2.2d:%2.2d", (getHours() / 3600) % 24, (getMinutes() % 3600) / 60, (getSeconds() % 60));

	return buff;
}