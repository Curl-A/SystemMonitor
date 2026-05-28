#ifndef MONITOR_MEMORY_H
#define MONITOR_MEMORY_H
struct memInfo {
	long total_memory;
	double memory_used;
	long avail_memory;
};

memInfo CollectMemoryInfo();
void displayMemStats(const memInfo& mem);

#endif
