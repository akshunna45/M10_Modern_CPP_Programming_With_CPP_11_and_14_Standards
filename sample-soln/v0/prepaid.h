#ifndef __PREPAID_H
#define __PREPAID_H

#include "customer.h"

class PrepaidCustomer : public CustomerBase {
    int m_validity;
    public:
    virtual void makeCall(int nmins) override;
    virtual void credit(double amt) override;
    //define above in cpp file
};

#endif
