/*
 * Matrix.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: David Lopez
 */
#include<stdio.h>
#include<iostream>
#include "symMat.h"
#include<stdexcept>

using namespace std;
using namespace Eigen;

	/******************Constructor***********************/
	symMat::symMat(MatrixXd m){ //stores only the upper right triangle of the matrix
		if (m.rows()==3 && m.cols()==3){//checks if matrix is of the correct size

			for(int rows = 0; rows<3; rows++){
				for(int columns = rows; columns<3; columns++){
					uTriangleMatrix(rows,columns) = m(rows,columns);//Assign the upper right triangle to the stored matrix
				}
			}
		}
		else {
			throw invalid_argument("Please use th Eigen::Matrix");
		}
	}

	/*******************ACCESORS************************/

	float symMat::getValuesAtPosition(int x, int y){ //retrieves values from any part of the matrix

		if(x>y){//checks if index is in strictly lower part of matrix
			return uTriangleMatrix(y,x);
		}
		else{
			return uTriangleMatrix(x,y);
		}
	}

	void symMat::setValueAtPosition(float value, int x, int y){//sets values at index, and if
		if(x>y){// temporary fix,
			uTriangleMatrix(y,x) = value;
		}
		else{
			uTriangleMatrix(x,y) = value;
		}

	}
	Matrix3d symMat::getSymMatrix(){//returns a full symmetrical Matrix

		Matrix3d Result(3,3);
		for(int rows = 0; rows<3; rows++){
			for(int columns = 0; columns<3; columns++){
				Result(rows,columns) = this->getValuesAtPosition(rows, columns);//Assign the upper right triangle to the stored matrix
			}
		}
		return Result;
	}

	/*********************FUNCTIONS********************/



	symMat symMat::addSymMat(symMat& m){	//loops through both matrices and returns the addition of the two upper triangles

		for(int rows = 0; rows<3; rows++){
			for(int columns = rows; columns<3; columns++){
				//Assign the upper right triangle to the stored matrix
				float newValue = uTriangleMatrix(rows,columns)+ m.getValuesAtPosition(rows,columns);
				m.setValueAtPosition(newValue, rows, columns);//without getValuesAtPosition
			}
		}
		return m;
	}

	Matrix3d symMat::addMat(Matrix3d& m){//loops through the symmetrical and the Eigen::Matrix, and returns their additon

		for(int rows = 0; rows<3; rows++){
			for(int columns = 0; columns<3; columns++){
				//Assign the upper right triangle to the stored matrix
				float newValue = m(rows, columns) + this->getValuesAtPosition(rows,columns);
				m(rows, columns)= newValue;//without getValuesAtPosition
			}
		}
		return m;

	}
	symMat symMat::substractSymMat(symMat& m){	//loops through both matrices and returns the substraction of the two upper triangles

		for(int rows = 0; rows<3; rows++){
			for(int columns = rows; columns<3; columns++){
				//Assign the upper right triangle to the stored matrix
				float newValue = uTriangleMatrix(rows,columns)+ m.getValuesAtPosition(rows,columns);
				m.setValueAtPosition(newValue, rows, columns);//without getValuesAtPosition
			}
		}
		return m;
	}

	Matrix3d symMat::substractMat(Matrix3d& m){//loops through the symmetrical and the Eigen::Matrix, and returns their substraction

		for(int rows = 0; rows<3; rows++){
			for(int columns = 0; columns<3; columns++){
				//Assign the upper right triangle to the stored matrix
				float newValue = m(rows,columns) - this->getValuesAtPosition(rows,columns);
				m(rows, columns)= newValue;//without getValuesAtPosition
			}
		}
		return m;
	}
	Matrix3d symMat::multiplySymMat(symMat& m){//performs matrix multiplication between the two symMats

		Matrix3d returnMat;
		for (int row = 0; row<3; row++){
			for(int columnOne = 0; columnOne<3; columnOne++){
				float matValue{};
				for(int columnTwo = 0; columnTwo<3; columnTwo++){
					//Assign the upper right triangle to the stored matrix
					float newValue = this->getValuesAtPosition(row,columnTwo)*m.getValuesAtPosition(columnTwo, columnOne);
					matValue += newValue;
				}
				returnMat(row,columnOne)= matValue;
			}
		}
		return returnMat;

	}
	Matrix3d symMat::multiplyMat(Matrix3d& m){//performs Matrix multiplication between the Eigen::Matrix and the symMat

		Matrix3d returnMat;
		for (int row = 0; row<3; row++){
			for(int columnOne = 0; columnOne<3; columnOne++){
				float matValue{};
				for(int columnTwo = 0; columnTwo<3; columnTwo++){
					//Assign the upper right triangle to the stored matrix
					float newValue = this->getValuesAtPosition(row,columnTwo)*m(columnTwo, columnOne);
					matValue += newValue;
				}
				returnMat(row,columnOne)= matValue;
			}
		}
		return returnMat;
	}



