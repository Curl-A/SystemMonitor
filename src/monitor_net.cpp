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
    
    int index;
    long value;
    netSpeed netinfo;
    while(ss>>value){
        if(index==1)
	    netinfo.rx_bytes = value;
	else if(index==9)
	    netinfo.tx_bytes = value;
	else
	    continue;
    }

    return netinfo;
}

void displayNetSpeed() {
    netSpeed speed1 = calNetSpeed();
    
    std::this_thread::sleep_for(std::chrono::seconds(1));

    netSpeed speed2 = calNetSpeed();

    std::cout<<"Download: "<<(speed2.rx_bytes - speed1.rx_bytes)/1024<<" kb/s\n"
	    <<"Upload: "<<(speed2.tx_bytes - speed1.tx_bytes)/1024<<" kb/s"<<std::endl;

}


	    
