#include<iostream>
#include<string>
#include<vector>
#include "core.h"

using namespace std;

void run(wstring& cmdstr)
{
	const int N = 2;
	const wstring cmd[N] = { L"PageNext",L"PagePrev" };
	vector<wstring> k[N];
	k[0].push_back(CmdFilter(L"다음으로 넘겨주세요."));
	k[0].push_back(CmdFilter(L"다음으로 넘겨줘"));
	k[0].push_back(CmdFilter(L"뒤로 넘겨줘"));
	k[1].push_back(CmdFilter(L"앞으로 넘겨주세요."));

	int idx = -1;
	double m = 0;
	for (int i = 0; i < N; i++)
	{
		double f = FindCmd(k[i], cmdstr);
		if (f > m) {
			m = f; idx = i;
		}
	}
	
	if(idx<0) cout << "Can't find command." << endl;
	else wcout <<"result:"<< cmd[idx] << endl;
}


int init(wstring& cmdstr, int& argc, wchar_t* argv[])
{
	setlocale(LC_ALL, "korean");
	wcout.imbue(locale("korean"));
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			if (i != 1)cmdstr += L" ";
			cmdstr += argv[i];
		}
		wcout << "cmd:" << cmdstr << endl;
	}
	else {
		cout << "PAM v0.000823" << endl;
		cout << "usage : pam [msg;korean message]" << endl;
		return 0;
	}
	return 1;
}

int wmain(int argc, wchar_t* argv[]) {
	wstring cmdstr = L"";
	if (!init(cmdstr, argc, argv))return 0;
	run(cmdstr);
	return 0;
}

