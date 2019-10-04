// 10.3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

const int maxLen = 128;
typedef struct {
	char *ch;
	int curLen;
}HString;

int Length(HString *S) {
	return S->curLen;
}

int Compare(HString *S, HString *T) {
	return strcmp(S->ch, T->ch);
}

void SubStr(HString *T, HString *S, int pos, int count) {
	int i, charsleft;
	char *p, *q;
	if (pos<0 || pos>S->curLen - 1) {
		printf_s("λ��pos��Ч\n");
		exit(1);
	}
	if (count < 0) {
		printf_s("����count��Ч\n");
		exit(1);
	}
	charsleft = S->curLen - pos;
	if (count > charsleft) {
		count = charsleft;
		free(T->ch);
		T->ch = new char[count+1];
		if (T->ch == NULL) {
			printf_s("overflow");
			exit(1);
		}
		p = T->ch;
		q = S->ch + pos;
		for (i = 1; i <= count; i++) {
			*p++= *q++;
		}
		*p = '\0';
		T->curLen = count;
	}
}

int index(HString *T, HString *P) {
	int LT = Length(T), LP = Length(P);
	HString *subString;
	int i = 0;
	while (i <= LT - LP) {
		SubStr(subString, T, i, LP);
		if (!Compare(subString, P)) {
			return i;
		}else {
			i++;
		}
	}
	return -1;
}


int main()
{

    return 0;
}

