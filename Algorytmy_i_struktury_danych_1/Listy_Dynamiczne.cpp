// Listy_Dynamiczne.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>

using namespace std;
struct node {
	int val;
	node* next;
};

void AddToList(node* &H, int x)
{
	node* p = new node;
	p->val = x;
	p->next = H;
	H = p;
};
void ShowList(node* H) {
	cout << "H->" << endl;
	node* p = H;
	while (p != NULL)
	{
		cout << p->val << "->" << endl;
		p = p->next;
	}
	cout << "NULL" << endl;
}
void Del(node* &H) {
	if (H != NULL)
	{
		node* p = H;
		H = H->next;
		delete p;
	}
}
void DelLast(node*& H) {
	node* p = H;
	if (H == NULL) return;
	if (H->next != NULL)
	{
		while (p->next->next != NULL)
		{
			p = p->next;
		}
		Del(p->next);
	}
	else
	{
		Del(H);
	}
}
void Swap(node*& H) {
	if (H != NULL && H->next != NULL) {
		node* p = H;
		H = p->next;
		p->next = p->next->next;
		H->next = p;
	}
}
void SwapLast(node*& H) {
	node* p = H;
	while (p->next->next->next != NULL)
	{
		p = p->next;
	}
	Swap(p->next);
	//node* temp = p->next;
	//p->next = p->next->next;
	//p->next->next = temp;
	//temp->next = NULL;
}

int main()
{
	node *H = NULL;
	//AddToList(H, 5);
	//AddToList(H, 10);
	//AddToList(H, 15);
	//AddToList(H->next, 7);
	//ShowList(H);
	//Del(H->next->next);
	//ShowList(H);
	AddToList(H, 3);
	AddToList(H, 12);
	AddToList(H, 7);
	AddToList(H, 6);
	AddToList(H, 3);
	SwapLast(H);
	ShowList(H);
	return 0;

}

