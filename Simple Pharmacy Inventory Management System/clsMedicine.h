#pragma once
#include<iostream>
using namespace std;
class clsMedicine
{
public:
	int ID;
	string Name; 
	int Price;
	int Quantity;
	string ExpiryDate;
	string Location;
	string Brand;
	string Category;

	clsMedicine* Next;

	clsMedicine(int i, string n, int p, int q, string e, string l, string b, string c)
	{
		ID = i;
		Name = n;
		Price = p;
		Quantity = q;
		ExpiryDate = e;
	    Location = l;
	    Brand = b;
		Category = c;
		Next = nullptr;
	}
};

