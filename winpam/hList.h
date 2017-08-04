/*
*-- https://github.com/nar789/hList
*-- Copyright 2017 all rights reserved by (c)HUME
*-- Written by Junghun,Lee
*-- HList
*-- July 29, 2017
*/
#pragma once
#include<iostream>
#include<string>
#define TAIL L"end"
using namespace std;
struct D {
	wstring speech;
	wstring cmd;
	D() :speech(L""), cmd(L"") {};
	D(wstring _speech, wstring _cmd) :speech(_speech), cmd(_cmd) {};
	D(const D& ref) {
		speech = ref.speech; cmd = ref.cmd;
	}
	D& operator=(const D& ref) {
		speech = ref.speech;
		cmd = ref.cmd;
		return *this;
	}
	friend wostream& operator<<(wostream& os, const D& ref) {
		
		os << "[" << ref.speech << "," << ref.cmd << "]";
		return os;
	}
};
struct E {
	D d;
	E* next = 0;
	E() :next(NULL) {};
	E(D arg) :d(arg) { E::E(); };
	bool operator!=(E& ref) {
		if (d.speech == ref.d.speech && d.cmd == ref.d.cmd && next == ref.next)
			return false;
		return true;
	}
	E& operator=(E& rhs) {
		d = rhs.d;
		next = rhs.next;
		return *this;
	}
	E& operator++() {
		if (next == NULL)
			operator=(E(D(TAIL, TAIL)));
		else
			operator=(*next);
		return *this;
	}
	E& operator*() {
		return *this;
	}
	friend wostream& operator<<(wostream& os, E& rhs) {
		os << rhs.d;
		return os;
	}
};
class hList {
private:
	E* tail;
	E* parent;
	int size;
public:
	hList() :parent(new E()), size(0), tail(new E(D(TAIL, TAIL))) {};
	hList(const hList& ref) {
		tail = ref.tail;
		parent = ref.parent;
	}
	~hList() { delete tail; delete parent; }
	int Size() { return size; }
	void Clear() { delete parent; parent = new E(); size = 0; }
	D& operator[](int n) {
		if (n + 1 > size) {
			cout << "overflow." << endl;
			return parent->d;
		}
		E* itr = parent;
		for (int cnt = -1; cnt != n; cnt++, itr = itr->next) {}
		return itr->d;
	}
	hList& operator=(hList& rhs) {
		tail = rhs.tail;
		parent = rhs.parent;
		return *this;
	}
	hList& operator+(D arg) {
		E* itr = parent;
		while (itr->next != NULL) {
			itr = itr->next;
		}
		itr->next = new E(arg);
		size++;
		return *this;
	}
	friend wostream& operator<<(wostream& os, hList& ref)
	{
		if (ref.size == 0) { os << "empty."; return os; }
		int cnt = 0;
		for (E* itr = ref.parent->next; cnt != ref.size; cnt++, itr = itr->next) {
			os << itr->d << " ";
		}
		return os;
	}
	hList& operator--() {
		E* tmp = parent->next;
		parent->next = parent->next->next;
		delete tmp;
		size--;
		return *this;
	}
	hList& operator--(int) {
		E* itr = parent;
		E* prev = parent;
		while (itr->next != NULL) {
			prev = itr;
			itr = itr->next;
		}
		E* tmp = prev->next;
		prev->next = NULL;
		delete tmp;
		size--;
		return *this;
	}
	E& begin() {
		return *parent->next;
	}
	E& end() {
		return *tail;
	}
};