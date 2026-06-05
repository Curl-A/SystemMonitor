#ifndef METRICS_H
#define METRICS_H

struct metricInfo{
	double memoryUsage=0.0;
	double cpuUsage=0.0;
	double download_speed=0.0;
	double upload_speed=0.0;
};

metricInfo calMetrics();

#endif
