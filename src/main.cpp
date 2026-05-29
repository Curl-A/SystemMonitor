#include<iostream>
#include<thread>
#include<chrono>
#include "monitor_memory.h"
#include "monitor_cpu.h"

int main() 
{
	while(true) {
	    system("clear");

	    std::cout<<"Monitoring my system"<<std::endl;

            memInfo mem=CollectMemoryInfo(); 
	    displayMemStats(mem);
	    displayCpuUsage();

	    std::this_thread::sleep_for(std::chrono::seconds(2));	
	}    
	return 0;
}
