#include <iostream>
//#include <time.h>
//#include <sys/time.h>

#if defined(Darwin)
#   include <mach/mach.h>
#   include <mach/mach_time.h>
#elif defined(__linux__)
#   include <time.h>
#elif defined(WIN32) || defined(_WIN32)
#   include <windows.h>
#else
#   error "Must define Darwin or __linux__ or WIN32"
#endif /* platform includes */


#include <stdio.h>
#include <vector>
#include <algorithm>

int SAMPLE_SIZE	 = 1000000;
uint64_t snapTime()
{
	return mach_absolute_time();
}

class MyTime
{
public:
	MyTime(const std::string& name) : _name(name) 
	{
		_start.reserve(SAMPLE_SIZE);
		_end.reserve(SAMPLE_SIZE);
	}
	void start() { _start.push_back(snapTime()); }
	void stop()  { _end.push_back(snapTime()); }
	void reset()
	{
		_start.clear();
		_end.clear();
	}
	void dumpStat()
	{
		std::vector<uint64_t> result;
		result.reserve(_start.size());
		for(unsigned int i = 0; i < _start.size() && i < _end.size(); ++i)
		{
			//std::cout << " End = " << _end[i] << " Start = " << _start[i] 
			//	  << " Diff = " << _end[i] - _start[i] << std::endl;
			result.push_back(_end[i] - _start[i]);
		}
		std::sort(result.begin(),result.end());
		int nintypercentile = result.size() * 0.9;
		int fiftypercentile = result.size() * 0.5;
		std::cout << "\nStat for SBE " << _name << " Sample size = "<< result.size() << " in nanoseconds"
			  << "\nMin 	= " << result[0] 
			  << "\n50%	= " << result[fiftypercentile]
			  << "\n90%	= " << result[nintypercentile]
			  << "\nMax	= " << result.back() << std::endl;
	}
private:
	std::string _name;
	std::vector<uint64_t> _start;
	std::vector<uint64_t> _end;
};
