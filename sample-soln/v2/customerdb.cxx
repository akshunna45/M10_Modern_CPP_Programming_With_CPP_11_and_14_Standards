#include "customerdb.h"

error_t CustomerDb::addCustomer(CustomeType type, std::string id, std::string name, 
                                std::string phone, double balance) {
    if(type==PREPAID) {                            
        m_precustomers.emplace_back(id,name,phone,balance);
    }  
    else {                          
        m_postcustomers.emplace_back(id,name,phone,balance);
    }       
    return SUCCESS;                   
}                                
double CustomerDb::findAveragePrepaidBalance() {
    double total=0;
    std::for_each(m_precustomers.begin(), m_precustomers.end(), [&total](ICustomer& ref) {
        total += ref.getBalance();
    }
    /* for(auto& rcust : m_precustomers)
            total + = rcust.getBalance();
    */
    return  total/m_precustomers.size();
}
bool CustomerDb::isPrepaidCustomerFoundById(int keyId) {
     auto iter = std::find_if(m_precustomers.begin(), m_precustomers.end(), 
                    [keyId](ICustomer& ref) {
                        return ref.id() == keyId;
     } );
     if(iter!=m_precustomers.end()) rerurn true;
     else return false;
}
ICustomer* CustomerDb::findPrepaidCustomerById(int keyId) {
     auto iter = std::find_if(m_precustomers.begin(), m_precustomers.end(), 
                    [keyId](ICustomer& ref) {
                        return ref.id() == keyId;
     } );
     if(iter!=m_precustomers.end()) rerurn &(*iter);
     else return nullptr;
}
error_t CustomerDb::removeCustomerById(int keyId) {
    std::remove_if(m_precustomers.begin(), m_precustomers.end(), 
                    [keyId](ICustomer& ref) {
                        return ref.id() == keyId;
     } );

}
ICustomer& CustomerDb::findPostpaidCustomerwithMaxBalance() {
    auto iter=std::max_element(m_postcustomers.begin(), m_postcustomers.end(),
             [](ICustomer& r1, ICustomer& r2) {
                    return r1.getBalance() < r2.getBalance();                     
    }); 
    return *iter;
}
ICustomer& CustomerDb::findPrepaidCustomerwithMinBalance() {
    auto iter=std::min_element(m_precustomers.begin(), m_precustomers.end(),
             [](ICustomer& r1, ICustomer& r2) {
                    return r1.getBalance() < r2.getBalance();                     
    }); 
    return *iter;
}
int CustomerDb::countPostpaidCustomersByBalanceRange(double bmin,double bmax) {
    int kount;
    kount=std::count_if(m_precustomers.begin(), m_precustomers.end(), 
            [bmin, bmax](ICustomer& ref) {
                return ref.getBalance() > bmin && ref.getBalance() < bmax;
    };
    return kcount;
}
//int countPrepaidCustomersByBalanceLimit(double);

std::vector<ICustomer> CustomerDb::findPrepaidCustomersByName(std::string pattern)
{
    std::vector<ICustomer> results;
      for(auto& ref : m_postcustomers) 
        if(ref.getName().find(pattern)
             results.push_back(ref);
    return results;
}
std::vector<ICustomer> CustomerDb::findPostpaidCustomersByBalance(double minbal) {
    std::vector<ICustomer> results;
    for(auto& ref : m_postcustomers) 
        if(ref.getBalance() > minbal)
             results.push_back(ref);
    return results;
}
