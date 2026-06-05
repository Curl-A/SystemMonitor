#include<iostream>
#include<thread>
#include<sstream>
#include<fstream>
#include "monitor_net.h"

netSpeed calNetSpeed() {
    std::ifstream file("/proc/net/dev");

    std::string line;

    while(std::getline(file,line))
    {
	    if(line.find("eth0") != std::string::npos)
		  break;
    }
    
    std::stringstream ss(line);
    std::string intf;
    ss >> intf;
    int index=1;
    long value;
    netSpeed netinfo;
    while(ss>>value){
        if(index==1)
	    netinfo.rx_bytes = value;
	else if(index==9)
	    netinfo.tx_bytes = value;

	index++;
    }
    return netinfo;
}



	    
