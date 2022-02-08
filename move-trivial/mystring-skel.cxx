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
  int length() const { return m_len; }
};

int main() {
  MyString s1("abcdxyz");
  
  MyString s2(s1);              //copy constructor
  
 return 0;
}
