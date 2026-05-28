#include<iostream>
#include<thread>
#include<chrono>
#include "monitor_memory.h"
int main() 
{
	while(true) {
	    system("clear");

	    std::cout<<"Monitoring my system"<<std::endl;

            memInfo mem=CollectMemoryInfo(); 
	    displayMemStats(mem);

	    std::this_thread::sleep_for(std::chrono::seconds(10));	
	}    
	return 0;
}
