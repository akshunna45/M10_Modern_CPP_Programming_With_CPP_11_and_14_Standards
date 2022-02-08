#include<type_traits>
#include<iostream>

class Box {
    int m_length;
    int m_breadth;
    int m_height;
public:
    Box(int l,int b,int h):m_length(l), m_breadth(b), m_height(h) {  }
    Box(int s):Box(s,s,s) { }
    
    int volume() const { return m_length * m_breadth * m_height; }
};

int main() {
  std::cout << std::is_trivial<Box>::value << "\n";
  Box b1(10,12,5);
  Box b2(std::move(b1));
  std::cout << b1.volume() << "\n";
  std::cout << b2.volume() << "\n";

}
