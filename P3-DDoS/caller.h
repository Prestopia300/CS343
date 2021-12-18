#pragma once
#include <iostream>
using namespace std;
class Caller
{
public:
	Caller();
	Caller(bool botCall, double serviceTime, int eventTime);
	~Caller();

	bool isBot();
	void SetBot(bool botCall);

	void SetEventTime(int time);
	void SetServiceTime(double time);
	
	int GetEventTime();
	double GetServiceTime();

private:
	//string name_;
	//int id_;
	bool is_bot_;
	//bool isServiceEndEvent
	int event_time_;
	double service_time_;
};

