#ifndef MONITOR_MEMORY_H
#define MONITOR_MEMORY_H
struct memInfo {
	long total_memory;
	long avail_memory;
};

double CollectMemoryInfo();

#endif
