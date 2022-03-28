// Matrix Class Implementation

#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <string>

#include "Matrix.h"

using namespace std;

Matrix::Matrix() {
	vector<float> thisRow(3, 0);
	for (int i = 0; i < 3; i++) {
		m.push_back(thisRow);
	}
}

Matrix::Matrix(const MIL& inMIL) {
	vector<float> r(3, 0);
	for (int i = 0; i < 3; i++) {
		m.push_back(r);
	}

	vector<tuple<int, int> > m_indices = inMIL.indices;
	vector<float> m_vals = inMIL.values;

	for (int i = 0; m_vals.size(); i++) {
		// use set_val method to set the element at the index to the corresponding value
		tuple<int, int> index = m_indices[i];
		float val = m_vals[i];
		set_val(get<0>(index), get<1>(index), val);
	}
}

Matrix::Matrix(const Matrix& inMatrix) {
	m = inMatrix.m;
}

float Matrix::get_val(int r, int c) {
	float val = m[r][c];
	return val;
}

void Matrix::set_val(int r, int c, float val) {
	m[r][c] = val;
	return;
}

void Matrix::printMatrix() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << m[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {

	Matrix M;
	M.printMatrix();

	return 0;
}
