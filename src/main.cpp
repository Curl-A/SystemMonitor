#include<iostream>
#include<thread>
#include<chrono>
#include "metrics.h"
int main() 
{
        metricInfo metrics;
	while(true) {
	    system("clear");
           
	    std::cout<<"Monitoring my system"<<std::endl;
	    metrics = calMetrics(); 
	    std::cout <<"\nMemory Usage: "<<metrics.memoryUsage
		    <<"\nCPU Usage: "<<metrics.cpuUsage
		    <<"\nNetwork download speed: "<<metrics.download_speed
		    <<"\nNetwork upload speed: "<<metrics.upload_speed<<std::endl;

	    std::this_thread::sleep_for(std::chrono::seconds(2));	
	}    
	return 0;
}
