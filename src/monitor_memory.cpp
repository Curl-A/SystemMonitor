#include<iostream>
#include "monitor_memory.h"
#include<fstream>
#include<sstream>
double CollectMemoryInfo(){
	   std::ifstream memoryInfo("/proc/meminfo");
           double memory_used=0.0;

           if(!memoryInfo.is_open()){
	       std::cout<<"Error opening file"<<std::endl;
	       return {};
	   }
	   
	   long long total_memory, avail_memory;
	   std::string line;
	   while(std::getline(memoryInfo,line)){

	      if(line.find("MemTotal")!=std::string::npos){
	    	size_t pos = line.find(":");
		std::string value = line.substr(pos+1);
		std::stringstream ss(value);
		ss >> total_memory;
	     }
	      else if(line.find("MemAvailable")!=std::string::npos){
                size_t pos = line.find(":");
                std::string value = line.substr(pos+1);
                std::stringstream ss(value);
                ss >> avail_memory;
		break;
             }
	   }
	   memory_used = ((double)(total_memory-avail_memory)/total_memory)*100;

	   return memory_used;
	   
}

