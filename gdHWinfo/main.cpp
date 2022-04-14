#include <windows.h>
#include "HWinfo.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	HWinfo * h = new HWinfo();
	delete h;
	return 0;
}