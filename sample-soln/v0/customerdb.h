#ifndef __CUSTOMERDB_H
#define __CUSTOMERDB_H

#include "prepaid.h"
#include "postpaid.h"
#include<list>

enum ErrorCode {
    SUCCESS,
    FAILURE   //TODO: diff failure codes
};
typedef enum ErrorCode error_t;

class CustomerDb {
    std::list<PrepaidCustomer> m_precustomers;
    std::list<PrepaidCustomer> m_postcustomers;  
    //TODO: can we merge both , yes, in next revision
    public:
    CustomerDb(const CustomerDb&)=delete;
    CustomerDb& operator=(const CustomerDb&)=delete;
    
    error_t addCustomer(CustomeType, std::string, std::string, std::string, double );
    error_t removeCustomerById(int id);
    ICustomer* findCustomerById(int id);
    double findAveragePrepaidBalance();
    double findAveragePostpaidBalance();
    ICustomer& findPostpaidCustomerwithMaxBalance();
    ICustomer& findPrepaidCustomerwithMinBalance();
    int countPrepaidCustomersByBalanceLimit(double);
    int countPostpaidCustomersByBalanceRange(double,double);
    std::vector<ICustomer> findCustomersByName(std::string pattern);
};

#endif;

/* BillingSolution class
  * Create a collection of Customer using suitable STL container(s)
  * Implement following operations on the collection
    * add customer
    * remove Customer by id
    * display all customers
    * find Customer by id
    * find all Customers by  matching name (substring match)
    * find average balance of all Prepaid customers
    * find the Postpaid customer with maximum outstanding limit (balance)
    * find the Prepaid with minimum balance
    * count all Prepaid customers whose balance is above certain limit
    * count all Postpaid customer whose balance is in with certain range
*/
