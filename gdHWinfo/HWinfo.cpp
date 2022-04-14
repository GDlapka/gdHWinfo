#include "HWinfo.h"

HWinfo::HWinfo()
{
	this->memory.dwLength = sizeof(this->memory);

	GetSystemInfo(&(this->info));
	GlobalMemoryStatusEx(&(this->memory));
	this->initCpuFrequency();

	unsigned long long TotalMemoryInKilobytes = 0;
	GetPhysicallyInstalledSystemMemory(&TotalMemoryInKilobytes);

	wostringstream wss;

	wss << L"  ������� ����������: " << this->getCpuFrequency() << L"���" << endl;
	wss << L"  ���������� ����: " << this->info.dwNumberOfProcessors << endl;

	unsigned long long memory = TotalMemoryInKilobytes;
	memory /= 1024;
	wss << L"  ���������� ������: " << memory << L"��" << endl;
	wss << L"  ---- ���� ---- " << endl;
	wss << this->freqs;

	wstring out = wss.str();
	MessageBox(NULL, out.c_str(), L"���������� � ������", MB_OK);
}


HWinfo::~HWinfo()
{
}

void HWinfo::initCpuFrequency(void)
{
	std::vector<PROCESSOR_POWER_INFORMATION> a(this->info.dwNumberOfProcessors);
	DWORD dwSize = sizeof(PROCESSOR_POWER_INFORMATION) * this->info.dwNumberOfProcessors;
	CallNtPowerInformation(ProcessorInformation, NULL, 0, &a[0], dwSize);
	this->cpuFrequency = a[0].MaxMhz;

	wstringstream wss;
	for (auto core : a) {
		wss << L"pNum: " << core.Number << L"; F: " << core.MaxMhz << L"���" << endl;
	}

	this->freqs = wss.str();

	a.clear();
}

ULONG HWinfo::getCpuFrequency(void)
{
	return this->cpuFrequency;
}