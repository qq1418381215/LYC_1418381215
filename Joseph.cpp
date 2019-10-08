#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct node {
	int data;
	struct node* link;
}LinkNode;
typedef LinkNode* LinkList;

LinkList CreateLinkR(int n) {
	LinkList first = new LinkNode;
	//LinkList s,r=first;
	LinkNode* s, * r = first;
	first->data = 1;
	first->link = NULL;
	int i=1;
	while (i<n) {
		i++;
		s = new LinkNode;
		s->data = i;
		r->link = s;
		s->link = NULL;
		r = s;
		//接上去后就做前面的 
	}
	r->link = first;
	return first;
}

void print(LinkList &first) {
	LinkList p;
	p=first;
	printf("%d ", p->data);
	p = p->link;
	while (p!=first)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}

int DeleteIt(LinkList& allP, int m) {
	int outNumber=0;
	int i = 0;
	LinkList deleted;
	if (m = 1&&allP->link!=NULL) {
		outNumber = allP->data;
		deleted=allP;
		allP = allP->link;
		delete(deleted);
		return outNumber;
	}
	for (i = 0; i < m-2; i++) {
		allP = allP->link;
	}
	outNumber=allP->link->data;
	deleted=allP->link;
	allP->link=allP->link->link;
	
	delete(deleted);
	allP = allP->link;
	return outNumber;
}
int main(int argc, char** argv) {
	printf("请输入总数和间隔数\n");
	int m, n;
	scanf("%d %d", &n, &m);
	LinkList first;
	first = CreateLinkR(n);
	print(first);
	int outNumber = 0;
	LinkList allP;
	allP = first;
	if (m == 1) {
		while (allP->link != NULL) {
			outNumber = DeleteIt(allP, m);
			printf("%d ", outNumber);
		}
	}
	else {
		while (allP->link != allP) {
			outNumber = DeleteIt(allP, m);
			printf("%d ", outNumber);
		}
	}
	
	print(first);


	return 0;
}
