#include<iostream>
#include "monitor_memory.h"
#include<fstream>
#include<sstream>
memInfo CollectMemoryInfo(){
	   std::ifstream memoryInfo("/proc/meminfo");

           if(!memoryInfo.is_open()){
	       std::cout<<"Error opening file"<<std::endl;
	       return {};
	   }
	   
	   memInfo mem;

	   std::string line;
	   while(std::getline(memoryInfo,line)){

	      if(line.find("MemTotal")!=std::string::npos){
	    	size_t pos = line.find(":");
		std::string value = line.substr(pos+1);
		std::stringstream ss(value);
		ss >> mem.total_memory;
	     }
	      else if(line.find("MemAvailable")!=std::string::npos){
                size_t pos = line.find(":");
                std::string value = line.substr(pos+1);
                std::stringstream ss(value);
                ss >> mem.avail_memory;
		break;
             }
	   }
	   mem.memory_used = ((double)(mem.total_memory-mem.avail_memory)/mem.total_memory)*100;

	   return mem;
	   
}

void displayMemStats(const memInfo& mem){
	std::cout<<"Total Memory: "<<mem.total_memory<<std::endl;
	std::cout<<"Memory Available: "<<mem.avail_memory<<std::endl;
	std::cout<<"Memory used %: "<<mem.memory_used<<std::endl;
}

	
