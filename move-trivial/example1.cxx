#include<iostream>
#include<type_traits>
class Point {
  int m_x;
  int m_y;
  public:
  //Point()=default;
  Point(int x,int y):m_x(x),m_y(y) { }
  //Point(const Simple& lr) {  }
  //~Point() {}
  //Point& operator=(const Simple& lr) {}
};
class Box {
    int m_length;
    int m_breadth;
    int m_height;
public:
    Box() { }
    //Box()=delete;
    Box(int l,int b,int h):m_length(l), m_breadth(b), m_height(h) {  }
    //~Box() { }
    //Box(const Box&)=delete;
};

int main() {
  std::cout << std::is_trivial<Simple>::value << "\n";
  std::cout << std::is_trivial<Point>::value << "\n";

  std::cout <<  std::is_trivially_copyable<Simple>::value << "\n";
  std::cout <<  std::is_trivially_copyable<Point>::value << "\n";
  
 
  return 0;
}





class MyStack {
  int *parr;
  int maxlen;
  int top;
  public:
  MyStack(int len):maxlen(len),top(-1) {
    parr = new int[maxlen];
  }
  MyStack():maxlen(10),top(-1) {
    parr = new int[maxlen];
  }
  ~MyStack() {
    delete[] parr;
  }
  //MyStack(const MyStack& ref) { }
  //MyStack(const MyStack&)=delete;
  //MyStack& operator=(const MyStack&)=delete;
};

