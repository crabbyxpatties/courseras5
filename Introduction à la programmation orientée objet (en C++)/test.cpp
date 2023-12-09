#include <iostream>

using namespace std;

class Number {
private:
    int n;
public:
    Number() 
      : n(0) 
    { std::cout << n; }
    Number( int nn )
      : n(nn)
    { std::cout << n; }
    Number(Number const& otherNum)
      : n(otherNum.n+1)
    { std::cout << n; }
    void display() { std::cout << n; }
    void increase() { n += 1; }
};

int main()
{
    Number a, b(1), c(b);
    b.increase();
    c.display();
    b.display();
    return 0;
}