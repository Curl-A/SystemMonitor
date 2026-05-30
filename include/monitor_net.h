#ifndef MONITOR_NET_H
#define MONITOR_NET_H

struct netSpeed {
    long rx_bytes=0;
    long tx_bytes=0;
};

netSpeed calNetSpeed();

void displayNetSpeed();

#endif
