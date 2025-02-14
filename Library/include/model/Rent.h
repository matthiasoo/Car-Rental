#ifndef RENT_H
#define RENT_H

#include <string>
#include "typedefs.h"
#include <boost/date_time.hpp>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class Client;
class Vehicle;

class Rent {
private:
    int id; // maybe unsigned
    ClientPtr client;
    VehiclePtr vehicle;
    pt::ptime beginTime;
    pt::ptime endTime = pt::not_a_date_time;
    int rentCost = 0;

public:
    Rent(const int &id, Client *client, Vehicle *vehicle, const pt::ptime &beginTime);
    ~Rent();

    // getters
    std::string getRentInfo() const;
    const int &getId() const;
    const Client *getClient() const;
    const Vehicle *getVehicle() const;
    const pt::ptime &getBeginTime() const;
    const pt::ptime &getEndTime() const;
    int getRentDays();
    int getRentCost();

    void endRent(const pt::ptime &endRent);
};



#endif //RENT_H
