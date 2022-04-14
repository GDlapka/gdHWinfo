#pragma once
#define _WIN32_WINNT 0x0600

#include <Windows.h>
#include <string>
#include <vector>
#include <sstream>
#include <powrprof.h>

using namespace std;

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "PowrProf.lib")

typedef struct _PROCESSOR_POWER_INFORMATION {
	ULONG  Number;
	ULONG  MaxMhz;
	ULONG  CurrentMhz;
	ULONG  MhzLimit;
	ULONG  MaxIdleState;
	ULONG  CurrentIdleState;
} PROCESSOR_POWER_INFORMATION, *PPROCESSOR_POWER_INFORMATION;

class HWinfo
{
public:
	HWinfo();
	~HWinfo();
	ULONG getCpuFrequency(void);

private:
	void initCpuFrequency(void);
	SYSTEM_INFO info;
	MEMORYSTATUSEX memory;
	ULONG cpuFrequency;
	wstring freqs;
};

