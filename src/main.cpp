#include<iostream>
#include<thread>
#include<chrono>
#include "monitor_memory.h"
#include "monitor_cpu.h"
#include "monitor_net.h"
int main() 
{
	while(true) {
	    system("clear");

	    std::cout<<"Monitoring my system"<<std::endl;

            memInfo mem=CollectMemoryInfo(); 
	    displayMemStats(mem);
	    displayCpuUsage();
	    std::cout<<"Network Speed"<<std::endl;
            displayNetSpeed();
	    std::this_thread::sleep_for(std::chrono::seconds(2));	
	}    
	return 0;
}
