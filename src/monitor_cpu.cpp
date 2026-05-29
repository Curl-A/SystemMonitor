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
		
void displayCpuUsage() {
	cpuInfo cpuinfo=calCpuUsage();
	long total1=cpuinfo.total;
	long idle1=cpuinfo.idle;

	std::this_thread::sleep_for(std::chrono::seconds(1));

	cpuInfo cpuinfo1=calCpuUsage();
        long delta_total=cpuinfo1.total-cpuinfo.total;
        long delta_idle=cpuinfo1.idle-cpuinfo.idle;
	
	double usage = ((double)(delta_total-delta_idle)/delta_total)*100;
	std::cout<<"CPU Usage % : "<<usage<<std::endl;

}

