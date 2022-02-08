#include "customerdb.h"

error_t CustomerDb::addCustomer(CustomeType type, std::string id, std::string name, 
                                std::string phone, double balance) {
    if(type==PREPAID) {
    //m_precustomers.push_back(PrepaidCustomer(id,name,phone,balance));                              
        m_precustomers.emplace_back(id,name,phone,balance);
    }  
    else {  //POSTPAID
    //m_postcustomers.push_back(PrepaidCustomer(id,name,phone,balance));                              
        m_postcustomers.emplace_back(id,name,phone,balance);
    }       
    return SUCCESS;                   
}                                
double CustomerDb::findAveragePrepaidBalance() {
    std::list<PrepaidCustomer> iter;
    for(iter=m_precustomers.begin(); iter!=m_precustomers.end();++iter)
        total += iter->balance();
    return  total/m_precustomers.size();
}

bool CustomerDb::isPrepaidCustomerFoundById(int keyId) {
     std::list<PrepaidCustomer> iter;
     for(iter=m_precustomers.begin(); iter!=m_precustomers.end();++iter)
        if(iter->id()==keyId)
            break; //return true;
     return false; 
}
