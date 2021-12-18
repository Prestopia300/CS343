#include "CallProcessor.h"



CallProcessor::CallProcessor()
{
	//
}

CallProcessor::CallProcessor(int numOfCallTakers, int legitCallsPerhour, int aveSecondsPerLegitCall, int numOfBots)
{
	// 28, 887, 120, 0
	numberOfCallTakers = numOfCallTakers; 
	legitCallsPerHour = double(legitCallsPerhour);
	averageSecondsPerLegitCall = double(aveSecondsPerLegitCall);
	numberOfBots = numOfBots;
}


void CallProcessor::RunSimulation()
{
	BotCallGenerator(numberOfBots);
	LegitamateCallGenerator();
	//printGeneratedCalls();
	//cout << "\n\n\n\n----------------\n\n\n\n";

	// incomming calls PQ
	PriorityQueue incomming_calls; 
	for (int i = 0; i < generated_calls.size(); i++) 
	{
		incomming_calls.push(generated_calls[i]);
	}

	// call takers parallel vectors initialization
	vector<int> call_takers(numberOfCallTakers); 
	vector<bool> call_taker_available(numberOfCallTakers);
	for (int i = 0; i < call_takers.size(); i++)
	{
		call_taker_available[i] = true;
	}
	vector<double> call_total_time(numberOfCallTakers); // waiting time(can be 0) + service time  in parallel vector to be added to a total that can be averaged when call_takers vector of i position reaches 0v
	vector<bool> is_bot(numberOfCallTakers);

	// Actions: 
	// Initialize waiting time and service time along with call_takers vector

	// waiting list
	PriorityQueue waiting_list;
	
	int count_legit_calls = 0;
	int count_waitinglistamajigers = 0;
	int count_added_calls = 0;

	int count_completed_legit_calls = 0;
	

	double total_time = 0;
	while (clock_time_ <= 3600)
	{
		//cout << "cl time : " << clock_time_ << endl;
		//waiting list priority
		for (int j = 0; j < call_takers.size(); j++) // check call takers
		{
			if (!waiting_list.empty())
			{
				if (call_taker_available[j] == true) // if call taker available,                   shouldn't do this only once, because multiple openings might be avalible.
				{
					double serviceTime = waiting_list.top().GetServiceTime(); // add service time of caller to call_taker
					int waitingTime = clock_time_ - waiting_list.top().GetEventTime();
					
					//cout << "event time : " << waiting_list.top().GetEventTime() << endl;
					
					call_takers[j] = serviceTime;
					call_total_time[j] = waitingTime + serviceTime;

					is_bot[j] = waiting_list.top().isBot();

					waiting_list.pop();

					call_taker_available[j] = false; // call taker now unavailable
					//cout << "call taken from waiting list" << endl;
					
					count_waitinglistamajigers++;
					count_added_calls++;
				}
			}
		}

		// new calls get second priority


		
		while (incomming_calls.size() > 0 && incomming_calls.top().GetEventTime() == clock_time_) // new caller has arived!
		{
			Caller new_caller = incomming_calls.top(); // get caller
			incomming_calls.pop();
			
			//cout << "      : " << new_caller.GetEventTime() << endl;

			bool call_recieved = false;
			for (int j = 0; j < call_takers.size(); j++) // check call takers
			{
				if ((call_taker_available[j] == true) && (call_recieved == false)) // if call taker available(second parameter to make sure it only does this once),
				{
					double serviceTime = new_caller.GetServiceTime(); // add service time of caller to call_taker
					double waitingTime = double(clock_time_) - new_caller.GetEventTime();

					call_takers[j] = serviceTime; // add service time of caller to call_taker
					call_total_time[j] = waitingTime + serviceTime;

					is_bot[j] = new_caller.isBot();

					call_taker_available[j] = false; // call taker now unavailable
					call_recieved = true;
					//cout << "new caller taken directly" << endl;

					count_added_calls++;
				}
			}

			if (!call_recieved) // call takers unavaliable, call added to waiting list
			{
				waiting_list.push(new_caller);
				//cout << "call added to waiting list" << endl;
			}
		}

		// taken call_taker's caller service time decreases with each second.
		for (int k = 0; k < call_takers.size(); k++)
		{
			if (call_taker_available[k] == false) // call taker in call
			{
				//cout << "clock_time_ = " << clock_time_ ;

				//cout << " time in call = " << call_takers[k] - 1 << endl;
				call_takers[k]--;
				if (call_takers[k] <= 0) // call taker reset // == should work as well <<<<
				{
					call_taker_available[k] = true;
					call_takers[k] = 0;

					if (!is_bot[k])
					{
						total_time += call_total_time[k];
						//cout << "This service time : " << call_total_time[k] << endl;
						call_total_time[k] = 0;
						count_completed_legit_calls++; // now completed legit calls
					}
				}
			}
		}		
		clock_time_++;
		//cout << "final clock_time_ = " << clock_time_ << endl;
	}
	//cout << "count_waitinglistamajigers = " << count_waitinglistamajigers << endl;
	//cout << "count_added_calls = " << count_added_calls << endl;

	// total time (of fishished calls) / # competed legit calls = average total service time
	// total time (including unfinished calls) / # of completed calls 

	// denying too many calls, or bots are taking too much 



	cout << "Average time per call = " << total_time / count_completed_legit_calls << endl;    
	//cout << "total time (waitinglist + service time) = " << total_time << endl;
	cout << "Total completed legit calls : " << count_completed_legit_calls << endl;




	// reset
	clock_time_ = 0;
	generated_calls.clear();
}

void CallProcessor::BotCallGenerator(int numOfBots)
{
	default_random_engine generator(time(NULL)); // random number
	uniform_int_distribution<int> uniform(0, 3600);

	for (int i = 0; i < numOfBots; i++)
	{
		//cout << uniform(generator) << endl;
		
		Caller c(true, 6.0, uniform(generator)); // isBot, serviceTime, eventTime
		generated_calls.push_back(c);
	}
}

void CallProcessor::LegitamateCallGenerator()
{
	//legitCallsPerHour = 887.0;
	//averageSecondsPerLegitCall = 120.0;
	double legitCallsPerSecond = legitCallsPerHour / 3600;

	default_random_engine event_generator(time(NULL)); // generator
	exponential_distribution<double> event_expDist(1.0 / (1.0/legitCallsPerSecond)); // distribution; lambda is rate
	
	default_random_engine service_generator(time(NULL)); // generator
	exponential_distribution<double> service_expDist(1.0 / averageSecondsPerLegitCall); // distribution; lambda is rate 

	int event_time = 0;
	int count = 0;
	while(event_time <= 3600)
	{
		double service_time = ceil(service_expDist(service_generator)); // was int() cast
		int theEventInterval = ceil(event_expDist(event_generator)); // was int() cast

		//cout << "service_time : " << service_time << " ";
		//cout << "event_time : " << event_time << endl;
		//cout << "theEventInterval : " << theEventInterval << "\ntheServiceInterval : " << service_time << endl;

		Caller c(false, service_time, event_time); // isBot, serviceTime, eventTime
		generated_calls.push_back(c);

		event_time += theEventInterval; // call time
	}
}

void CallProcessor::printGeneratedCalls()
{
	int count_bots = 0;
	int count_legit = 0;
	for (int i = 0; i < generated_calls.size(); i++)
	{
		cout << "event time : " << generated_calls[i].GetEventTime() << " ";
		cout << "service time : " << generated_calls[i].GetServiceTime() << endl;
		if (generated_calls[i].isBot())
		{
			count_bots++;
		}
		else
		{
			count_legit++;
		}
	}
	//cout << "Number of bots : " << count_bots << endl;
	//cout << "Number of legit : " << count_legit << endl;

	//generated_calls.clear(); // remove if printing in RunSimulation

}

