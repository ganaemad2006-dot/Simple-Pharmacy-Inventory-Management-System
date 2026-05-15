#pragma once
#include<iomanip>
#include<iostream>
#include"clsPharmacySystem.h"
#include"clsMedicine.h"
class clsUserInterFace
{
public:
	void ShoMenu()
	{
		clsPharmacySystem pharmacy;
		pharmacy.LoadFromFile();
		int Choice;
		while (1) {
			system("cls");

			cout << "\n\n";
			cout << setw(30) << "" << "------------------------------------------------------------" << endl;
			cout << setw(30) << "" << setw(45) << right << "Pharmacy Drug Management System" << endl;
			cout << setw(30) << "" << "------------------------------------------------------------" << endl;

			cout << setw(30) << "" << setw(42) << right << "1. Add a new medication" << endl;
			cout << setw(30) << "" << setw(40) << right << "2. View all inventory" << endl;
			cout << setw(30) << "" << setw(41) << right << "3. Search for medicine" << endl;
			cout << setw(30) << "" << setw(39) << right << "4. Delete medication" << endl;
			cout << setw(30) << "" << setw(37) << right << "5. Update quantity" << endl;
			cout << setw(30) << "" << setw(35) << right << "6. Save and exit" << endl;

			cout << setw(30) << "" << "------------------------------------------------------------" << endl;
			cout << setw(46) << "" << "   Please choose from [1-6] : ";
			cin >> Choice;
			switch (Choice)
			{
			case 1: {
				int i; string n; int p; int q; string e; string l; string b; string c;

				system("cls");
				cout << "\n\n";

				cout << setw(30) << "" << "------------------------------------------------------------" << endl;
				cout << setw(30) << "" << setw(53) << right << "Please enter details of the new medication." << endl;
				cout << setw(30) << "" << "------------------------------------------------------------" << endl;
				cout <<"\n\n1.ID of the medicine          :"; cin >> i; "\n";
				cout << "2.Name of the medicine        :"; cin >> n; "\n";
				cout  << "3.Price of the medicine       :"; cin >> p; "\n";
				cout << "4.Quantity of the medicine    :"; cin >> q; "\n";
				cout  << "5.Expiry Date of the medicine :"; cin >> e; "\n";
				cout << "6.Location of the medicine    :"; cin >> l; "\n";
				cout <<  "7.Brand of the medicine       :"; cin >> b; "\n";
				cout <<"8.Category  of the medicine   :"; cin >> c; "\n";
				cout << "\n------------------------------------------------------------" << endl;

				if (pharmacy.AddMedicine(i, n, p, q, e, l, b, c) )
				{
					cout << "\n" << setw(30) << "" << "Done: The medication has been added successfully! :-)\n";
				}
				else
				{
					cout << "\n" << setw(30) << "" << "Error: Medication with ID (" << i << ") already exists!\n";
				}

				system("pause>0");
				break;
			}
			case 2: {
				system("cls");
				cout << "\n\n";

				cout << setw(30) << "" << "------------------------------------------------------------" << endl;
				cout << setw(30) << "" << setw(44) << right << "Pharmacy medication list." << endl;
				cout << setw(30) << "" << "------------------------------------------------------------" << endl;
				pharmacy.DispalyAll();
				system("pause>0");
				break;
			}
			case 3:
			{
				system("cls");
				cout << "\n\n";

				cout << setw(30) << "" << "------------------------------------------------------------" << endl;
				cout << setw(30) << "" << setw(40) << right << "Search for medicine." << endl;
				cout << setw(30) << "" << "------------------------------------------------------------" << endl;
				int i;
				cout <<"\n\nID Medicine for research :";
				cin >> i;
				pharmacy.SearchMedicine(i);
				system("pause>0");
				break;
			}
			case 4:
			{
				system("cls");
				cout << "\n\n";

				int i;
				cout << setw(30) << "" << "------------------------------------------------------------" << endl;
				cout << setw(30) << "" << setw(42) << right << "Delete for medicine." << endl;
				cout << setw(30) << "" << "------------------------------------------------------------" << endl;
				cout << "\n\nID Medicine for research :";
				cin >> i;
				
				pharmacy.DeleteMedicine(i);
				system("pause>0");
				break;
			}
			case 5:
			{

				int i, q;
				system("cls");
				cout << "\n\n";

			
				cout << setw(30) << "" << "------------------------------------------------------------" << endl;
				cout << setw(30) << "" << setw(40) << right << "Change the quantity of medication." << endl;
				cout << setw(30) << "" << "------------------------------------------------------------" << endl;
				cout <<  "\n\nID Medicine for research :";
				cin >> i;
				cout <<  "\n\nPlease enter the new quantity :";
				cin >> q;
				pharmacy.UpdateQuantity(i, q);
				system("pause>0");
				break;
			}
			case 6:
				system("cls");
								cout << "\n\n";

				char c;
				cout << setw(30) << "" << "------------------------------------------------------------" << endl;
				cout << setw(30) << "" << setw(40) << right << "Save the medicine." << endl;
				cout << setw(30) << "" << "------------------------------------------------------------" << endl;
				cout << "\n\nPlease choose [y/n] : ";

				cin >> c;
				if (c == 'y')
				{
					pharmacy.SaveToFile();
					cout <<"\n\nFarewell ! ";
				}
				else
				{
					cout <<  "\n\nThe medicine is not on the list :-( ";

				}
				system("pause>0");
				break;
			}
		}
	}

};