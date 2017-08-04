/*
*-- 
*-- Copyright 2017 all rights reserved by (c)HUME
*-- Written by Junghun,Lee
*-- HList
*-- Aug 04, 2017
*/
#pragma once
#include<cstring>
#define max(a,b) (a>b?a:b)
#include<iostream>
using namespace std;
int lcs(const wchar_t *A, const wchar_t *B,int an,int bn) {
	wchar_t *a = new wchar_t[an+2];
	wchar_t *b = new wchar_t[bn+2];

	for (int i = 1; i < an + 1; i++)a[i] = A[i-1];
	for (int i = 1; i < bn + 1; i++)b[i] = B[i-1];

	a[0] = b[0] = 0xAC00;
	b[bn+1]=a[an+1] = 0x0000;
	
	int**d = NULL;
	d = new int*[an+1];
	for (int i = 0; i < an+1; i++)d[i] = new int[bn+1];
	for (int i = 0; i < an+1; i++)for (int j = 0; j < bn+1; j++)d[i][j] = 0;	
	for (int i = 1; i < an+1; i++)
		for (int j = 1; j < bn+1; j++)
			d[i][j] = max(max(d[i - 1][j - 1] + (a[i]==b[j]?1:0), d[i - 1][j]), d[i][j - 1]);

	int r = d[an][bn];
	for (int i = 0; i < an+1; i++)delete d[i];
	delete d; 
	delete a; delete b;
	return r;
}
