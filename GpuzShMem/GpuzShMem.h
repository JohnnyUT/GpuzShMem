#define SHMEM_NAME _T("GPUZShMem")
#define MAX_RECORDS 128

#pragma pack(push, 1)

typedef struct GPUZ_RECORD 
{
	WCHAR key[256];
	WCHAR value[256];
}GPUZ_RECORD;

typedef struct GPUZ_SENSOR_RECORD
{
	WCHAR name[256];
	WCHAR unit[8];
	UINT32 digits;
	double value;
}GPUZ_SENSOR_RECORD;

typedef struct GPUZ_SH_MEM
{
	UINT32 version;			// Version number, 1 for the struct here
	volatile LONG busy;		// Is data being accessed?
	UINT32 lastUpdate;		// GetTickCount() of last update
	GPUZ_RECORD data[MAX_RECORDS];
	GPUZ_SENSOR_RECORD sensors[MAX_RECORDS];
}GPUZ_SH_MEM, *LPGPUZ_SH_MEM;

#pragma pack(pop)