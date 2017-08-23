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
	vector<wstring> dic = { L"�߸��� ",L"�� ",L"���� ",L"���� ",L"���� ",L"�κ��� ",L"���� ",L"�� ",
		L"�� ",L"�̸� ",L"�ϰ� ",L"�� ",L"�� ",L"�̴�",L"�� ",L"�� ",L"�� ",L"�� ",L"�� ", L"�� ",
		L"�� ",L"���� ",L"�� ",L"��",L"����" };
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
