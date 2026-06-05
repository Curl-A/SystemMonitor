#include "monitor_cpu.h"
#include "monitor_memory.h"
#include "monitor_net.h"
#include "metrics.h"
#include<chrono>
#include<thread>
#include <iostream>

metricInfo calMetrics() {

	metricInfo metrics;
	
	//Memory usage
	metrics.memoryUsage = CollectMemoryInfo();
	
	//CPU Usage
	cpuInfo cpuinfo=calCpuUsage();
        long total1=cpuinfo.total;
        long idle1=cpuinfo.idle;

        std::this_thread::sleep_for(std::chrono::seconds(1));

        cpuInfo cpuinfo1=calCpuUsage();
        long delta_total=cpuinfo1.total-cpuinfo.total;
        long delta_idle=cpuinfo1.idle-cpuinfo.idle;

        metrics.cpuUsage = ((double)(delta_total-delta_idle)/delta_total)*100;

	//Network Speed
	 netSpeed speed1 = calNetSpeed();

    	 std::this_thread::sleep_for(std::chrono::seconds(1));

    	 netSpeed speed2 = calNetSpeed();
         
    	 metrics.download_speed = (speed2.rx_bytes - speed1.rx_bytes);
    	 metrics.upload_speed = (speed2.tx_bytes - speed1.tx_bytes);

	return metrics;	 
       
}

