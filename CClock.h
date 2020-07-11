#pragma once
#include <ctime>
#include <cstdio>

class CClock
{
public:
	CClock();
	~CClock();
	
	void end();
private:
	timespec m_beginTime;
	timespec m_endTime;
};

CClock::CClock()
{
	timespec_get(&m_beginTime,10);
}

CClock::~CClock()
{

}

void CClock::end()
{
	timespec_get(&m_endTime, 10);

	time_t diffSec = m_endTime.tv_sec - m_beginTime.tv_sec;
	int diffMs = (m_endTime.tv_nsec - m_beginTime.tv_nsec) / 1000;
	int diffUs = (m_endTime.tv_nsec - m_beginTime.tv_nsec) / 1000000;
	
	printf("time use is: %lld s %d ms %d us\n",diffSec,diffMs,diffUs);
}
