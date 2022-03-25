#include <CAN.h> // this needs to be adafruits forked version.....
#include <NMEA2000_FeatherM4CAN.h>

bool
tNMEA2000_FeatherM4CAN::CANSendFrame(unsigned long id, unsigned char len, const unsigned char *buf, bool wait_sent) {
    CAN.beginExtendedPacket(id);
    for (auto i = 0; i != len; ++i)
        CAN.write(buf[i]);
    CAN.endPacket();
    //todo how to wait???
    return true;
}

bool tNMEA2000_FeatherM4CAN::CANOpen() {
    pinMode(PIN_CAN_STANDBY, OUTPUT);
    digitalWrite(PIN_CAN_STANDBY, false); // turn off STANDBY
    pinMode(PIN_CAN_BOOSTEN, OUTPUT);
    digitalWrite(PIN_CAN_BOOSTEN, true); // turn on booster
    // set bus-speed
    if (!CAN.begin(250000))
        return false;
    return true;
}

bool tNMEA2000_FeatherM4CAN::CANGetFrame(unsigned long &id, unsigned char &len, unsigned char *buf) {
    // try to parse packet
    len = CAN.parsePacket();
    id = CAN.packetId();
    for (auto i = 0; i != len; ++i)
        buf[i] = CAN.read();
    return (len != 0);
}

tNMEA2000_FeatherM4CAN::tNMEA2000_FeatherM4CAN() {}

