#ifndef __CUSTOMER_H
#define __CUSTOME_H

enum CustomerType {
    PREPAID,
    POSTPAID
};

class ICustomer {                       //abstract classes
    public:
    virtual void makeCall(int)=0;
    virtual void credit(double)=0;
};
class CustomerBase : public ICustomer { //also abstract, as not implementing pure virtual
    std::string m_id;
    std::string m_name;
    std::string m_phone;
    double m_balance;
    public:
    Customer()=default;
    Customer(std::string id, std::string name, std::string phone, double balance);
    Customer(std::string id, std::string name, std::string phone);
    //No need of copy ctor, destructor, operator=
    int balance() const { return m_balance; }   //may be inline
};

#endif
