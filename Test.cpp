/*
 * SymMatEXEC.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: David Lopez
 */
#include<stdio.h>
#include<iostream>
#include<stdexcept>
#include "symMat.h"
using namespace std;
using namespace Eigen;
int main(){

	/*********testing conversion from Eigen:Matrix to symMat*********/
	cout<< "Symmetrical matrix Test"<<endl<<
			"The following 3x3 Matrix will be converted to a symmetrical matrix (let it be matrix A)"<<endl;
	MatrixXd m(3, 3);
	m(0, 1) = 6;
	m(0, 0) = 2;
	m(1,0) = 4;
	m(1,1)= 3;
	m(0,2)= 2;
	m(1,2)= 3;
	m(2,0)= 5;
	m(2,1)= 4;
	m(2,2)= 2;
	cout<<m;
	cout<<endl;

	symMat newSymMatrix{m};
	cout<<"After converting symmetrical Matrix A, its new values are: "<<endl;
	Matrix3d SymMat;
	SymMat = newSymMatrix.getSymMatrix();
	cout<< SymMat;
	cout<<endl;

	//Variables for user input
	int posA = 0;
	int posB = 0;
	float replace = 0;

	/**************testing accessors**************/
	cout<<"We will now test the accessors:"<<endl<<
			"Please enter the X coordinate of the index, and follow it by the Y coordinate of the matrix"<<endl;
	cin>>posA;
	cin>>posB;

	float value = newSymMatrix.getValuesAtPosition(posA,posB);//get function
	cout<<"The number at index( "<<posA<<","<<posB<<") is:"<<endl
			<<value<<endl<<"Now, please enter a value to insert at the given index"<<endl;
	cin>>replace;
	newSymMatrix.setValueAtPosition(replace,posA,posB);//set function
	cout<<"The new symmetrical matrix A is:"<<endl;
	SymMat = newSymMatrix.getSymMatrix();
	cout<<SymMat;
	cout<<endl;

	/**********testing matrix algebra**********/
	cout<<"We will now perform some algebra with our symMat!"<<endl<<"For this we need a new Eigen::Matrix"
			"we will be using the following arbitrary matrix (let it be Matrix K)"<<endl;

	Matrix3d k;//declaring new matrix k
	k(0, 1) = 3;
	k(0, 0) = 8;
	k(1,0) = 4;
	k(1,1)= 3;
	k(0,2)= 2;
	k(1,2)= 3;
	k(2,0)= 3;
	k(2,1)= 2;
	k(2,2)= 2;

	cout<<k;
	cout<<endl;
	cout<<"Let's add A and K, and we will have a new matrix A"<<endl;
	Matrix3d addition;
	addition = newSymMatrix.addMat(k);//addition between Eigen::Matrix and symMat
	cout<< addition;
	cout<<endl;
	cout<<"substract k from new matrix A"<<endl;
	Matrix3d substraction;
	substraction = newSymMatrix.substractMat(k);//substraction between Eigen::Matrix and symMat
	cout<<substraction;
	cout<<endl;
	cout<<"multiply A times K"<<endl;
	Matrix3d multiply;
	multiply = newSymMatrix.multiplyMat(k);//multiplication between Eigen::Matrix and symMat
	cout<<multiply;
	cout<<endl;

	cout<<"We will now test algebra between two symMats by converting matrix k to a symMat"<<endl;
	MatrixXi j(3,3);
	j(0, 1) = 3;
	j(0, 0) = 8;
	j(1,0) = 4;
	j(1,1)= 3;
	j(0,2)= 2;
	j(1,2)= 3;
	j(2,0)= 3;
	j(2,1)= 2;
	j(2,2)= 2;
	symMat secondMatrix {j};//conversion of matrix k to symMat
	Matrix3d newSecMatrix;
	newSecMatrix = secondMatrix.getSymMatrix();
	cout<<newSecMatrix;
	cout<<endl;

	symMat additionR = newSymMatrix.addSymMat(secondMatrix);//addition between two symmetrical matrices
	cout<<"The result of the addition of the two symmetrical matrices A and K is (our new A matrix):"<<endl<<additionR.getSymMatrix();
	cout<<endl;
	symMat substractR = newSymMatrix.substractSymMat(secondMatrix);//substraction between two symmetrical matrices
	cout<<"The result of substracting symmetrical matrix K from symMat A is:"<<endl<<substractR.getSymMatrix();
	cout<<endl;
	Matrix3d multiplyR = newSymMatrix.multiplySymMat(secondMatrix);//multiplication between two symmetrical matrices
	cout<<"result of the multiplication of both symmetrical matrices is:"<<endl<<multiplyR;
	cout<<endl;
	cout<<"End of test!";
}


