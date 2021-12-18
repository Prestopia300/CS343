#include "caller.h"

Caller::Caller()
{
}

Caller::Caller(bool botCall, double serviceTime, int eventTime)
{
	is_bot_ = botCall;
	//start_time_ = startTime;
	service_time_ = serviceTime;
	event_time_ = eventTime;
}

Caller::~Caller()
{
}

bool Caller::isBot()
{
	return is_bot_;
}

void Caller::SetBot(bool botCall)
{
	is_bot_ = botCall;
}

void Caller::SetEventTime(int time)
{
	event_time_ = time;
}

void Caller::SetServiceTime(double time)
{
	service_time_ = time;
}

//void Caller::SetStartTime(int time)
//{
//	start_time_ = time;
//}

int Caller::GetEventTime()
{
	return event_time_;
}

double Caller::GetServiceTime()
{
	return service_time_;
}

//int Caller::GetStartTime()
//{
//	return start_time_;
//}
