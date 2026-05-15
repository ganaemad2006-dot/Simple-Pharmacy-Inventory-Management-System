#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<sstream>
#include"clsMedicine.h"
using namespace std;
class clsPharmacySystem
{
private:
	clsMedicine* head;
	clsMedicine* _Find(int &id) {
		clsMedicine* temp = head;
		while (temp != nullptr) {
			if (temp->ID == id)
			
				return temp;

				temp = temp->Next;
			
		}
		return nullptr;
	}
public:
		clsPharmacySystem()
		{
			head = __nullptr;
		}
		bool AddMedicine(int i, string n, int p, int q, string e, string l, string b, string c)
		{
			if (_Find(i) != nullptr) {
				return false;
			}

			clsMedicine* newNode = new clsMedicine(i, n, p, q, e, l, b, c);
			newNode->Next = head;
			head = newNode;

			return true;
		}
		void DispalyAll()
		{
			if (!head)
			{
				cout << "\n\nThe pharmacy is currently empty.\n";
				return;
			}
			cout << "\n------------------------------------------------------------------------------------------------------------------------\n";
			cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(15) << "Price" << setw(15) << "Quantity" << setw(15) << "Expiry Date" << setw(15) << "Location" << setw(15) << "Brand" << setw(15) << "Category" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------\n";

			clsMedicine* temp = head;
			while (temp)
			{
				cout << left << setw(10) << temp->ID << setw(20) << temp->Name << setw(15) << temp->Price << setw(15) << temp->Quantity << setw(15) << temp->ExpiryDate << setw(15) << temp->Location << setw(15) << temp->Brand << setw(15) << temp->Category << endl;
				cout << "------------------------------------------------------------------------------------------------------------------------\n";

				temp = temp->Next;
			}
		}
		void SearchMedicine(int i)
		{
			clsMedicine* temp = head;
			while (temp)
			{
				if (temp->ID == i)
				{
					cout << "\n\n";
					cout << setw(30) << "" << "------------------------------------------------------------" << endl;
					cout << setw(30) << "" << setw(40) << right << "The medicine was found : " << temp->ID << endl;
					cout << setw(30) << "" << "------------------------------------------------------------" << endl;
					cout << setw(30) << "" << setw(45) << right << "1.ID of the medicine         :" << temp->ID << endl;
					cout << setw(30) << "" << setw(45) << right << "2.Name of the medicine       :" << temp->Name << endl;
					cout << setw(30) << "" << setw(45) << right << "3.Price of the medicine      :" << temp->Price << endl;
					cout << setw(30) << "" << setw(45) << right << "4.Quantity of the medicine   :" << temp->Quantity << endl;
					cout << setw(30) << "" << setw(45) << right << "5.Expiry Date of the medicine:" << temp->ExpiryDate << endl;
					cout << setw(30) << "" << setw(45) << right << "6.Location of the medicine   :" << temp->Location << endl;
					cout << setw(30) << "" << setw(45) << right << "7.Brand of the medicine      :" << temp->Brand << endl;
					cout << setw(30) << "" << setw(45) << right << "8.Category of the medicine   :" << temp->Category << endl;
					cout << setw(30) << "" << "------------------------------------------------------------" << endl;

					return;
				}
				temp = temp->Next;
			}
			cout << "\nThe medicine is not available .\n";
		}
		void DeleteMedicine(int i)
		{
			clsMedicine* temp = head, * prev = nullptr;

			if (temp != nullptr && temp->ID == i)
			{
				head = temp->Next;
				delete temp;
				cout << "\n\n";

				cout << "\n\nThe medication was successfully deleted :-) .";
				return;
			}

			while (temp != NULL && temp->ID != i) {
				prev = temp;
				temp = temp->Next;
			}
			if (temp == nullptr)
			{
				cout << "\n\nError: Medication with ID (" << i << ") was not found!";

				return;
			}
			prev->Next = temp->Next;
			delete temp;
			cout << "\n\nThe medication was successfully deleted :-) .";
		}
		void UpdateQuantity(int i, int q)
		{
			clsMedicine* target = _Find(i);

			if (target == nullptr) {
				cout << "\nError: Medication with ID (" << i << ") not found. Cannot update quantity.\n";
				return;
			}

			target->Quantity = q;
			cout << "\nQuantity has been updated successfully :-).\n";
		}
		void SaveToFile() {
			ofstream outFile("pharmacy_stock.txt");
			clsMedicine* temp = head;
			while (temp) {
				outFile << temp->ID << "|" << temp->Name << "|" << temp->Price << "|" << temp->Quantity << "|" << temp->ExpiryDate << "|" << temp->Location << "|"
					<< temp->Brand << "|" << temp->Category << "|" << endl;
				temp = temp->Next;
			}
			outFile.close();
			cout << "\nAll data was saved in the file  .\n";
		}
		void LoadFromFile() {
			ifstream inFile("pharmacy_stock.txt");
			if (!inFile) return;
			string line;
			while (getline(inFile, line)) {
				if (line.empty()) continue;
				stringstream ss(line);
				string idStr, name, priceStr, qtyStr, exp, loc, brand, cat;
				getline(ss, idStr, '|');
				getline(ss, name, '|');
				getline(ss, priceStr, '|');
				getline(ss, qtyStr, '|');
				getline(ss, exp, '|');
				getline(ss, loc, '|');
				getline(ss, brand, '|');
				getline(ss, cat, '|');

				if (!idStr.empty()) {
					int id = stoi(idStr);
					int price = stoi(priceStr);
					int qty = stoi(qtyStr);

					AddMedicine(id, name, price, qty, exp, loc, brand, cat);
				}
			}
			inFile.close();

		}
}; 