template<typename T>
class MyStack {
   T *m_arr;
   int m_capacity;
   int m_top;
   public:
   MyStack(int len):m_capacity(len), m_top(-1) {
      m_arr = new T[m_capacity];
   }
   MyStack():m_capacity(10), m_top(-1) {
      m_arr = new T[m_capacity];
   }
   ~MyStack() {
      if(m_arr)              //m_capacity>0
        delete[] m_arr;
   }
   MyStack(const MyStack& ref)=delete;
   MyStack& operator=(const MyStack& ref)=delete;
   MyStack(MyStack&& rr):m_capacity(rr.m_capacity),m_top(-1) {
      m_arr = rr.m_arr;
      rr.m_arr=nullptr;
      rr.m_capacity=0;
   }
   MyStack& operator=(MyStack&& rr):m_capacity(rr.m_capacity),m_top(-1) {
      if(this==&rr) return *this;
      if(m_arr) delete[] m_arr;
      m_arr = rr.m_arr;
      rr.m_arr=nullptr;
      rr.m_capacity=0;
      return *this;
   }
   /*void push(T& lr) {
     m_arr[++m_top]=lr;     //copy ctor
   }
   void push(T&& rr) {
     m_arr[++m_top]=rr;     //move ctor
   }*/
   void push(T&& ur) {
     m_arr[++m_top]=std::forward<T>(ur);    //perfect forwarding   
   }
   //pop
   //isEmpty
   //isFull
};
int main() {
  MyStack s1(20);
  
  //MyStack s2(s1);     //error
  MyStack s3;           //??
  //s3=s1;              //error
  
  MyStack s2(std::move(s1));        //move ctor
  s3 = std::move(s2);               //move assignment
  
  return 0;
}
