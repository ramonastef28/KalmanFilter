#include <iostream>
#include "Dense"
#include <vector>

using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;

MatrixXd CalculateJacobian(const VectorXd& x_state);

int main() {

	/*
	 * Compute the Jacobian Matrix
	 */

	//predicted state  example
	//px = 1, py = 2, vx = 0.2, vy = 0.4
	VectorXd x_predicted(4);
	x_predicted << 1, 2, 0.2, 0.4;

	MatrixXd Hj = CalculateJacobian(x_predicted);

	cout << "Hj:" << endl << Hj << endl;

	return 0;
}

MatrixXd CalculateJacobian(const VectorXd& x_state) {

	MatrixXd Hj(3,4);
	//recover state parameters
	float px = x_state(0);
	float py = x_state(1);
	float vx = x_state(2);
	float vy = x_state(3);

	//TODO: YOUR CODE HERE 
    float div =px*px + py*py;
    float sq = pow(div,0.5);
    float pw3 = pow(div,3/2);
	//check division by zero
	if (div == 0){
	    cout << "Error messaje" << endl;
	}
	else{
	    Hj << px/sq, py/sq, 0, 0,
	          -py/div, px/div, 0, 0,
	          (py*(vx*py - vy*px))/pw3, (px*(vy*px-vx*py)/pw3), px/sq, py/sq;
	}
	//compute the Jacobian matrix

	return Hj;
}
