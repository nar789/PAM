#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include "lcs.h"
using namespace std;

double FindCmd(vector<wstring>& str, wstring& cmd) {
	double ret = 0.0f;
	for (auto i : str) {
		double r = (double)lcs(i.c_str(), cmd.c_str(), i.length(), cmd.length());
		/*cout << r << endl;*/
		r = r / (double)cmd.length() * 100.0f;

		ret = max(r, ret);
	}
	return ret;
}
wstring CmdFilter(wchar_t* str) {
	wstring r(str);
	vector<wstring> dic = { L"야말로 ",L"야 ",L"조차 ",L"마저 ",L"까지 ",L"로부터 ",L"부터 ",L"도 ",
		L"랑 ",L"이며 ",L"하고 ",L"과 ",L"와 ",L"이다",L"의 ",L"은 ",L"는 ",L"가 ",L"이 ", L"을 ",
		L"를 ",L"으로 ",L"로 ",L"줘",L"세요" };
	for (auto s : dic)
	{
		do {
			size_t f = r.find(s);
			if (f == wstring::npos)break;
			r.replace(f, s.length(), L"");
		} while (true);
	}
	return r;
}
