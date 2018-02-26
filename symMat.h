///*
// * symMat.h
// *
// *  Created on: Feb 26, 2018
// *      Author: David Lopez
// */
//
#ifndef SYMMAT_H_
#define SYMMAT_H_
#include<Eigen/Dense>
using namespace Eigen;

class symMat{
public:

	//Constructor for symMat
	symMat(MatrixXi);
	//Accessors functions
	float getValuesAtPosition(int, int);
	void setValueAtPosition(float, int, int);
	Matrix3d getSymMatrix();
	//Matrix Algebra
	symMat addSymMat(symMat&);
	symMat substractSymMat(symMat&);
	Matrix3d addMat( Matrix3d&);
	Matrix3d substractMat(Matrix3d&);
	Matrix3d multiplySymMat(symMat&);
	Matrix3d multiplyMat( Matrix3d&);

private:
	Matrix3d uTriangleMatrix;//stores upper triangle Matrix
};

#endif /* SYMMAT_H_ */

