//Biblioteka na potrzeby kinematyki manipulatora 3DOF

#include <string.h>
#include <stdio.h>
#include <math.h>

//****** Setup IK variables ******
#define PI 3.14159265
float ShoulderLength = 175.0;
float ElbowLength = 175.0;
float WristLength = 70.0;
float Hypot, Slope, CirclePointX, CirclePointY;
float x1 = 100.0;//Target end point.10.6
float y11 = 80.0;//Target end point.7.5
float x2 = 0.0;//origin start point.
float y2 = 0.0;//origin start point.
float A, B, C,
      PosXAnswer,   //positive X portion of Quadratic Equation.
      PosYAnswer,   //positive Y portion of Qudratic Equation.
      NegXAnswer,   //negative X portion of Quadratic Equation.
      NegYAnswer,   //negative Y portion of Quadratic Equation.
      Angle_D,      //Angle located at origin (0,0).
      Angle_E_Temp, //Second 1/2 of Angle located at origin (0,0).Shoulder servo setting.
      Angle_F,      //Elbow servo setting.
      Angle_G;      //Wrist servo setting subtracted from 180.

//MACIERZE

//int A, B, C, D;

//********************************

void set_angleA(uint16_t val, uint16_t s, uint16_t pulsePin, uint16_t dirPin){

	//Paste PWM reg for engines

}

/*
 *
 * KINEMATICS US METHOD

void MatrixMath(int A,int B, int m, int n, int C){
	// A = input matrix (m x n)
	// B = input matrix (m x n)
	// m = number of rows in A = number of rows in B
	// n = number of columns in A = number of columns in B
	// C = output matrix = A+B (m x n)
	int i, j;
	for (i = 0; i < m; i++)
		for(j = 0; j < n; j++)
		//	C[n * i + j] = A[n * i + j] + B[n * i + j];
}

void MatrixMathMultiply(int A, int B, int m, int p, int n, int C){
	// A = input matrix (m x p)
	// B = input matrix (p x n)
	// m = number of rows in A
	// p = number of columns in A = number of rows in B
	// n = number of columns in B
	// C = output matrix = A*B (m x n)
	int i, j, k;
	for (i = 0; i < m; i++)
		for(j = 0; j < n; j++)
		{
			C[n * i + j] = 0;
			for (k = 0; k < p; k++)
				C[n * i + j] = C[n * i + j] + A[p * i + k] * B[n * k + j];
		}
}

void MatrixMathAdd(int A, int B, int m, int n, int C){
	// A = input matrix (m x n)
	// B = input matrix (m x n)
	// m = number of rows in A = number of rows in B
	// n = number of columns in A = number of columns in B
	// C = output matrix = A+B (m x n)
	int i, j;
	for (i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			C[n * i + j] = A[n * i + j] + B[n * i + j];
}


void MatrixMathSubtract(int A, int B, int m, int n, int C){
	// A = input matrix (m x n)
	// B = input matrix (m x n)
	// m = number of rows in A = number of rows in B
	// n = number of columns in A = number of columns in B
	// C = output matrix = A-B (m x n)
	int i, j;
	for (i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			C[n * i + j] = A[n * i + j] - B[n * i + j];
}

void MatrixMathScale(int A, int m, int n, int k){
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			A[n * i + j] = A[n * i + j] * k;
}

void MatrixMathTranspose(int A, int m, int n, int C){
	// A = input matrix (m x n)
	// m = number of rows in A
	// n = number of columns in A
	// C = output matrix = the transpose of A (n x m)
	int i, j;
	for (i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			C[m * j + i] = A[n * i + j];
}

*/

//KINEMATICS ARDUINO METHOD

void Calc_Ang(){
  //******************************************************************
  //*********** Starting Special Circle Calcs ********************************
  //******************************************************************

  Hypot = sqrt(sqrt(x1) + sqrt(y11)) + WristLength;
  A = ElbowLength;     //zeby tyle nie pisac za kazdym razem
  B = Hypot;
  C = ShoulderLength;



  //*** Calculate angle A ***//
  Angle_D = acos((sqrt(B) + sqrt(C) - sqrt(A)) / (2 * B * C)) * (180 / PI);
  //    Angle_A_Temp = acos((sq(x1) + sq(Hypot) - sq(y1)) / (2 * x1 * Hypot))*(180 / PI); //Second 1/2 of Angle A from X axis upto Shoulder arm.
  //    Angle_A = Angle_A + Angle_A_Temp; //Second 1/2 of Angle A from X axis plus Shoulder arm angle.


  //*** Calculate angle B ***//
  Angle_F =  acos((sqrt(C) + sqrt(A) - sqrt(B)) / (2 * A * C)) * (180 / PI);

  //*** Calculate angle C ***//
  Angle_G = acos((sqrt(A) + sqrt(B) - sqrt(C)) / (2 * A * B)) * (180 / PI);
  //  Angle_C = 180 - Angle_C; //must calc larger opposite side angle.

  Angle_D = Angle_D * (1 + (Angle_D / (Angle_F + Angle_G))); // Angle A is recalculated due to the servo gearbox used.

  if (Angle_D < 35) {// Angle A is recalculated due to the servo gearbox used.
    Angle_F = 35;
  }//End if <35.

}

//KINEMATICS ARABIAN METHOD

void kine(){

}
