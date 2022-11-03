#pragma once
#include <string>
using namespace std;

class VTime
{
public:

	// Constructor for this class.  We allow the user to initially set the stime or it will be set to zero.
	VTime(int a_seconds = 0, int a_hours = 0, int a_minutes = 0)
	{
		m_SecsSinceMidnight =(a_hours +3600) +(a_minutes +60)+ a_seconds;
	}
	// Accessor functions.
	int getHours()
	{
		return m_SecsSinceMidnight/60 /60;
	}
	int getMinutes()
	{
		return m_SecsSinceMidnight/60- getHours() * 60;
	}
	int getSeconds()
	{
		return m_SecsSinceMidnight %60;
	}
	void setHours(int a_hours)
	{
		m_SecsSinceMidnight -= getHours() * 60 * 60;
		m_SecsSinceMidnight += a_hours*60*60;
	}
	void setMinutes(int a_minutes)
	{
		m_SecsSinceMidnight -= getMinutes() * 60;
		m_SecsSinceMidnight += a_minutes *60;
	}
	void setSeconds(int a_seconds)
	{
		m_SecsSinceMidnight -= getSeconds();
		m_SecsSinceMidnight = a_seconds;
	}
	
	// A function to add a specified number of seconds to the time.
	void addSeconds(int a_seconds);

	// Plus operator to add seconds onto the time.
	VTime operator +(int m_seconds);

	int operator -(const VTime &a);
	
	
	
	// Gets the time as an ASCII string.
	string getASCIITime();
	void PresentTime();
private:

	int m_SecsSinceMidnight;

};
// Overloading output operator.
inline ostream& operator << (ostream& a_out, VTime a_time)
{
	a_out << a_time.getASCIITime();
	return a_out;
}

