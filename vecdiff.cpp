#include <vector>
#include <cmath>
#include <iostream>

//codeility - Minimize the value |(A[0] + ... + A[P-1]) - (A[P] + ... + A[N-1])|
 
using namespace std;

int solution(vector<int> &A) {
  
  //so this finds the sum of the left value up to P, sums everything after P
  //subtracts the difference of left sum from right, repeat ad nauseum
  //for all parts in the vector

    int leftSum;
    int rightSum = 0;
    vector<int> diff;
    int ans, localMin;
    int minValue;

    //kick off with the starting value
 
    leftSum = A[0];
 
    //sum up the left values
    for( int i = 1; i < A.size(); i++ ) {
      rightSum += A[i];
    }

    
    //kick off calculating differences
    ans = abs( leftSum - rightSum );
 
    for( int p = 1; p < A.size(); p++ ) {
      localMin = abs( leftSum - rightSum);
 
      if(localMin < ans ) {
	ans = localMin;
      }
      leftSum += A[p];
      rightSum -= A[p];
      diff.push_back(localMin);
    }
 
    //find the minimum value
    minValue = diff[0];

    for( int i = 1; i < diff.size(); i++) {
      if( diff[i] < minValue ) {
	minValue = diff[i];
      }
    }
 
    return minValue;
}

int main() {
  vector<int> numbers;
  numbers.push_back(3);
  numbers.push_back(1);
  numbers.push_back(2);
  numbers.push_back(4);
  numbers.push_back(3);

  cout << "These are the values in our vector:";
  for( int i = 0; i < numbers.size(); i++ ) {
    cout << numbers[i];
  }

  cout << "\n";

  cout << "We are going to calculate the minimum value of abs((A[0] + ... + A[P-1]) - (A[P] + ... + A[N-1]))\n, that is the minimum value of sum of the left and right vectors iteratively\n";
  cout << "The minimum value is : " << solution(numbers) << endl;
  return 0;
}

  
