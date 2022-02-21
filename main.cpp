//test different methods and operations using matrix
#include "matrix.h"
#include <iostream>
using namespace std;
int main(int argc, char **argv) {
  matrix m1(2,3);
  matrix m2;
  matrix m3;
	vector<vector<float>> m4 = {{1, 2},{4, 5},{7, 8}};
	vector<vector<float>> m5 = {{1, 7, 3},{4, 5, 6}};
	vector<vector<float>> m6 = {{1, 7},{4, 5}};
	m1.display();
	cout << endl;
	m1 = m4;
	m1.display();
	cout << endl;
	m2 = m1;
	m2 = m2 + m1;
	m2.display();
	cout << endl;
	m2 = m5;
	m2.display();
	cout << endl;
	m3 = m2*m1;
	m3.display();
	cout << endl;
	m2 = m6;
	m3 = m3 - m2;
	m3.display();
	cout << endl;
	cout << m3(1,1) << endl;
	cout << endl;
	m3(1,1, 10);
	cout << m3(1,1) << endl;
}