/*
 * kinematyka.h
 *
 *  Created on: Jan 1, 2021
 *      Author: Remigiusz G
 */

#ifndef INC_KINEMATYKA_H_
#define INC_KINEMATYKA_H_

void set_angleA(uint16_t val, uint16_t s, uint16_t pulsePin, uint16_t dirPin);

void MatrixMath(int A, int B, int m, int n, int C);

void MatrixMathMultiply(int A, int B, int m, int n, int C);

void MatrixMathAdd(int A, int B, int m, int n, int C);

void MatrixMathSubtract(int A, int B, int m, int n, int C);

void MatrixMathTranspose(int A, int B, int m, int n, int C);

void MatrixMathScale(int A, int B, int m, int n, int C);



void Calc_Ang();

#endif /* INC_KINEMATYKA_H_ */
