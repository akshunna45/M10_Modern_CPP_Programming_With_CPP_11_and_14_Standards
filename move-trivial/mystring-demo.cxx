#include<iostream>
#include<cstring>

class MyString
{
  char *m_buf;
  int   m_len;

public:
  MyString() : m_buf(nullptr), m_len(0) {}
  MyString(const char *pbuf)
  {
    m_len = strlen(pbuf);
    m_buf = new char[m_len + 1];
    strcpy(m_buf, pbuf);
  }
  MyString(const MyString& ref):m_len(ref.m_len) {
    m_buf = new char[m_len + 1];
    strcpy(m_buf, ref.m_buf);
  }
  MyString(MyString&& rr) {
    m_len = rr.m_len;
    m_buf = rr.m_buf;
    rr.m_buf = nullptr;
    rr.m_len = 0;
  }

  
  ~MyString() {
    if(m_buf)  //m_buf!=nullptr
        delete[] m_buf;
  }
  MyString& operator=(const MyString& ref) {
      if(this==&ref) return *this;
      if(m_buf) delete[] m_buf;
      m_len = ref.m_len;
      m_buf = new char[m_len + 1];
      strcpy(m_buf, ref.m_buf);    
      return *this;  
  }
  MyString&  operator=(const MyString&& rr) {
    if(this==&ref) return *this;
      if(m_buf) delete[] m_buf;
    m_len = rr.m_len;
    m_buf = rr.m_buf;
    rr.m_buf = nullptr;
    rr.m_len = 0;
    return *this;
  }

  int length() const { return m_len; }
};

int main() {
  MyString s1("abcdxyz");
  
  MyString s2(s1);              //copy constructor
  
  MyString s3;
  s3 = s2;                      //overloaded operator=, copy assignment
  
  std::cout << std::is_trivial<MyString>::value << "\n";
  
  MyString s4(std::move(s2));   //move constructor
  
  MyString s5;
  s5=std::move(s3);             //move operator=, move assignment
  
  MyString s6("hello");
  s6 = std::move(s5);
  
  MyString s7("something");
  s7=s7;
  s7=std::move(s7);
  
  return 0;
}
