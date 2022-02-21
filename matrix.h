#ifndef Matrix_H
#define Matrix_H
#include <vector>
using namespace std;
class matrix{
  
  int row;
  int col;
  vector<vector<float>> mat;
public:
  matrix();
  matrix(int Row, int Col);
  
	void operator=(vector<vector<float>>);
  matrix operator+(const matrix&);
  matrix operator-(const matrix&);
  matrix operator*(const matrix&);
  matrix operator*(const float&);
	float operator() (int r,int c);
	void operator() (int r,int c, float a);
	void transpose();
	void setRC();
  void display();
};
#endif