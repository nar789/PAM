#include<iostream>
#include<string>
#include<vector>
#include<tchar.h>
#include "lcs.h"
#include "hList.h"

using namespace std;

const wstring cmd[] = { L"PageNext",L"PagePrev" };

int wmain(int argc, wchar_t* argv[]) {
	
	setlocale(LC_ALL, "korean");
	wcout.imbue(locale("korean"));

	if (argc > 1) {
		wcout <<"cmd:"<< argv[1] << endl;
	}
	cout << endl;
	vector<hList*> cmdtree;
	hList next;
	next + D(L"������", cmd[0]) + D(L"����", cmd[0]) + D(L"��������", cmd[0]);
	hList prev;
	prev + D(L"������", cmd[1]) + D(L"�ڷ�", cmd[1]) + D(L"�ڷΰ���", cmd[1]) + D(L"������", cmd[1]);
	cmdtree.push_back(&next);
	cmdtree.push_back(&prev);
	hList* sel = NULL;
	int hsum = 0xffffffff;
	for (auto i : cmdtree) {
		int sum = 0;
		wcout << "[" << (*i)[0].cmd << " LCS]" << endl;
		for (auto j : (*i)) {
			sum += lcs(j.d.speech.c_str(), argv[1], wcslen(j.d.speech.c_str()), wcslen(argv[1]));
			wcout << j.d.speech << " ";
			cout << lcs(j.d.speech.c_str(), argv[1], wcslen(j.d.speech.c_str()), wcslen(argv[1])) << endl;
		}
		cout << "[lcs_sum:" << sum << "]" << endl << "--------" << endl;
		if (hsum < sum) {
			hsum = sum;
			sel = i;
		}
	}
	wcout << "result:"<<(*sel)[0].cmd << endl;
	return 0;
}