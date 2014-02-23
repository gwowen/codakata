#include <iostream>

using namespace std;

int solution( int X, int Y, int D ) {
  int d1 = ( Y - X ) % D;
  int d2 = ( Y - X ) / D;
  return d1 == 0 ? d2 : d2 + 1;
}

int main() {
  int x, y, d;
  cout << "Frog jumping program\n";
  cout << "Enter the frog's initial position: ";
  cin >> x;
  cout << "Enter the frog's final distance: ";
  cin >> y;
  cout << "Enter the fixed distance the frog will jump:\n";
  cin >> d;
  cout << "The minimal number of jumps the frog has to do is " << solution( x, y, d ) << "\n";
  return 0;
}
