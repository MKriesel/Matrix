#include "matrix.h"
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;
matrix::matrix(){
	row = 1;
	col = 1;
  mat.resize(1 , vector<float> (1));
}
matrix::matrix(int Row, int Col){
  row = Row;
  col = Col;
  mat.resize(row , vector<float> (col));
}

void matrix::operator=(vector<vector<float>> m){
	mat.resize(m.size());
	for (int i = 0; i < m.size(); ++i)
    mat[i].resize(m[i].size());
	for (int i = 0; i < m.size(); i++){
    for (int j = 0; j < m[0].size(); j++){
      mat[i][j] = m[i][j];
    }
  }
	setRC();
}

matrix matrix::operator+(const matrix& m){

	if(row != m.row || col != m.col){
		throw invalid_argument("dimension must be the same.");
		}
  matrix temp(row,col);
  for (int i = 0; i < mat.size(); i++){
    for (int j = 0; j < mat[0].size(); j++){
      temp.mat[i][j] = mat[i][j] + m.mat[i][j];
    }
  }
  return temp;
  }

matrix matrix::operator-(const matrix& m){
	
	if(row != m.row || col != m.col){
		throw invalid_argument("dimension must be the same.");
		}
  matrix temp(row,col);
  for (int i = 0; i < mat.size(); i++){
    for (int j = 0; j < mat[0].size(); j++){
      temp.mat[i][j] = mat[i][j] - m.mat[i][j];
    }
  }
  return temp;
  }

matrix matrix::operator*(const matrix& m){
	if(row != m.mat[0].size()){
		throw invalid_argument("the row of matrix 1 must equal the column of matrix 2.");
		}
  matrix temp(row, m.mat[0].size());
  for (int i = 0; i < mat.size(); i++){
    for (int j = 0; j < m.mat[0].size(); j++){
			for (int k = 0; k < mat[0].size(); k++){
      	temp.mat[i][j] += mat[i][k] * m.mat[k][j];
				}
    }
  }
  return temp;

  }

matrix matrix::operator*(const float& s){
	
  matrix temp(row, col);
	for (int i = 0; i < mat.size(); i++){
    for (int j = 0; j < mat[0].size(); j++){
      temp.mat[i][j] = mat[i][j] * s;
    }
  }
  return temp;
  }

float matrix::operator() (int r,int c){
	
	if(r > mat.size() || c > mat[0].size()){
		throw invalid_argument("dimension must be in the scope of matrix.");
		}
	return mat[r][c];

	}
void matrix::operator() (int r,int c, float a){
	if(r > mat.size() || c > mat[0].size()){
		throw invalid_argument("dimension must be in the scope of matrix.");
		}
	mat[r][c] = a;
	}

void matrix::transpose(){
	setRC();
	matrix temp(col, row);
	for (int i = 0; i < mat.size(); i++){
    for (int j = 0; j < mat[0].size(); j++){
      temp.mat[j][i] = mat[i][j];
    }
  }
	mat.resize(row , vector<float> (col));
	mat = temp.mat;
}

void matrix::setRC(){
	row = mat.size();
	col = mat[0].size();
}

void matrix::display(){

  for (int i = 0; i < mat.size(); i++){
    for (int j = 0; j < mat[0].size(); j++){
      cout << mat[i][j] << " ";
    }
		cout << endl;
  }
}


