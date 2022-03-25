#include <NMEA2000.h>

#pragma once

class tNMEA2000_FeatherM4CAN : public tNMEA2000 {
protected:
    bool CANSendFrame(unsigned long id, unsigned char len, const unsigned char *buf, bool wait_sent);

    bool CANOpen();

    bool CANGetFrame(unsigned long &id, unsigned char &len, unsigned char *buf);

public:
    tNMEA2000_FeatherM4CAN();
};


