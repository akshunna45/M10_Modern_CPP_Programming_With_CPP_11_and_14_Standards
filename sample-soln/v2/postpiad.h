#ifndef __POSTPAID_H
#define __POSTPAID_H

#include "customer.h"

class PostpaidCustomer : public CustomerBase {
    int m_billdate;
    public:
    virtual void makeCall(int nmins) override;
    virtual void credit(double amt) override;
    //define above in cpp file
};

#endif
