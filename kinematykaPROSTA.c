/*
 * kinematykaPROSTA.c
 *
 *  Created on: Apr 18, 2020
 *      Author: REMIGIUSZ GOLINSKI
 */

#include <string.h>
#include <stdio.h>
#include <math.h>

#define pi 3.14159265

//Wymiary [mm]

int l1 = 145;
int l2 = 175;
int l3 = 175;

int efektor = 120;

int k=1;

//Ustawienia kątow poczatkowe

int t1p;
int t2p;
int t3p;

//Uswtawienie zadane

int t1z;
int t2z;
int t3z;

//Wspl
int x;
int y;
int z;

//katy poczatkowe
float theta1p;
float theta2p;
float theta3p;

//katy koncowe
float theta1;
float theta2;
float theta3;

float theta1f;
float theta2f;
float theta3f;


Kinematyka(int k1p, int k2p, int k3p, int k1z, int k2z, int k3z){


	//przypisanie wartosci do
	k1p=t1p;
	k2p=t2p;
	k3p=t3p;

	//
	t1z=k1z;
	t2z=k2z;
	t3z=k3z;


	theta1p=(pi/180)*(t1p)*1.0;
	theta2p=(pi/180)*(t2p)*1.0;
	theta3p=(pi/180)*(t3p)*1.0;

	theta1f=(pi/180)*(t1z)*1.0;
	theta2f=(pi/180)*(t2z)*1.0;
	theta3f=(pi/180)*(t3z)*1.0;


	for(int i; i<k; i++){

	theta1=theta1p+((theta1f-theta1p)/k)*i;
	theta2=theta2p+((theta2f-theta2p)/k)*i;
	theta3=theta3p+((theta3f-theta3p)/k)*i;
	    x = -sin(theta1) * (  l3 * sin(theta3  + theta2) - l2 * sin(theta2) );
	    y = cos(theta1) * (  l3 * sin(theta3 + theta2) - l2 * sin(theta2) );
	    z = l1 + l2 * cos(-theta2) + l3 * cos(theta3  + theta2);

	    //z = efektor + l1 + l2 * cos(-theta2) + l3 * cos(theta3  + theta2); //Z efektorem
	}


}


