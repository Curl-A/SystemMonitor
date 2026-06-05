#ifndef MONITOR_CPU_H
#define MONITOR_CPU_H	

struct cpuInfo{
    long total=0;
    long idle=0;
};

cpuInfo calCpuUsage();

#endif

