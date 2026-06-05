#include<iostream>
#include<fstream>
#include<sstream>
#include<thread>
#include "monitor_cpu.h"

cpuInfo calCpuUsage(){
	std::ifstream file("/proc/stat");
	std::string line;
	long value;
	std::getline(file,line);
	std::stringstream ss(line);
	int index=0;
	std::string cpu;

	cpuInfo cpuinfo; 
	ss>>cpu;
	while(ss>>value) {
		if(index == 3)
		    cpuinfo.idle=value;

		cpuinfo.total += value;
		index++;
	}
	return cpuinfo;	
}	
		

