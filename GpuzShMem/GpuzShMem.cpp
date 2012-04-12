#define VC_EXTRALEAN			// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>				// MFC core and standard components
#include "GpuzShMem.h"			// (modified) shared memory interface

static HANDLE m_hMapFile;
static LPVOID m_pMapAddr;
static LPGPUZ_SH_MEM lpMem;

//get access to shared memory
extern "C" __declspec(dllexport) int __stdcall InitGpuzShMem(void)
{
	if ((m_hMapFile = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, SHMEM_NAME)) == 0)
		return -1;
	if ((m_pMapAddr = MapViewOfFile(m_hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, 0)) == 0)
		return -2;

	lpMem = (LPGPUZ_SH_MEM)m_pMapAddr;

	return 0;
}

//release resources
extern "C" __declspec(dllexport) int __stdcall RemGpuzShMem(void)
{
	if (m_hMapFile)
		CloseHandle(m_hMapFile);

	lpMem = NULL;
	m_pMapAddr = NULL;
	m_hMapFile = NULL;

	return 0;
}

extern "C" __declspec(dllexport) void * __stdcall GetSensorName(int index)
{
	return (void *)(lpMem->sensors[index]).name;
}

extern "C" __declspec(dllexport) double __stdcall GetSensorValue(int index)
{
	return (lpMem->sensors[index]).value;
}

extern "C" __declspec(dllexport) void * __stdcall GetSensorUnit(int index)
{
	return (void *)(lpMem->sensors[index]).unit;
}

extern "C" __declspec(dllexport) void * __stdcall GetDataKey(int index)
{
	return (void *)(lpMem->data[index]).key; 
}

extern "C" __declspec(dllexport) void * __stdcall GetDataValue(int index)
{
	return (void *)(lpMem->data[index]).value; 
}