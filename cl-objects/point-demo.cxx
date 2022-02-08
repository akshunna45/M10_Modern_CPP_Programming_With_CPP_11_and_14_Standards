class Point {
  int m_x;
  int m_y;
  public:
  Point()=default;
  Point(int x,int y):m_x(x),m_y(y) { }
  //Simple(const Simple& lr)=delete;
  //~Simple() {}
  //Simple& operator=(const Simple& lr) {}
};
