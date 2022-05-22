#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Classes.h"

using namespace std;


//admin id:1000
//admin password:admin

int main()
{
	int menu_choice;
	int snack_i = 0, food_i = 0, drink_i = 0, cigarette_i = 0, other_i = 0;
	int snack_index, food_index, drink_index, cigarette_index, other_index;
	int user_flag = 1;
	vector<Snacks> snacks;
	vector<Food> foods;
	vector<Drinks> drinks;
	vector<Cigarettes> cigarettes;
	vector<Other> others;

	Administrator admin;
	vector<FuelSupplier> FS;
	vector<Customer> customer;
	Gasoline gasol[2];
	gasol[0].setType("FuelSave");
	gasol[1].setType("Power Gasoline");
	Diesel diesel[2];
	diesel[0].setType("Euro Diesel");
	diesel[1].setType("Power Diesel");
	LPG lpg;
	cout << "Welcome To Your GasStation" << endl;
	while (true)
	{
		cout << "1. Administrator\n"
			<< "2. Worker \n"
			<< "3. Customer\n"
			<< "4. Exit" << endl;
		int choice;
		cout << "Your choice:";
		cin >> choice;
		cout << endl;
		if (choice == 1)
		{
			int id;
			string password;
			while (true)
			{
				cout << "Please enter the your WorkID:";
				int id;
				cin >> id;
				cout << "Please enter the password:";
				cin >> password;
				if (id == admin.getworkID() && password == admin.getPassword())
				{
					cout << "\nYou're successfully registered." << endl;
					cout << "Your Information:" << endl;
					admin.displayInformation();
					while (true)
					{
						cout << "\nWhat do you want to do?\n"
							<< "1. Add Worker\n"
							<< "2. Fire the Worker\n"
							<< "3. Update the Worker's Salary\n"
							<< "4. Check Your Worker List\n"
							<< "5. Check safe\n"
							<< "6. Check Fuel Tanks and Prices\n"
							<< "7. Check your Marketplace\n"
							<< "8. Change Your Password\n"
							<< "9. Exit to the Main Menu" << endl;
						cout << "Your choice:";
						int choice2;
						cin >> choice2;
						if (choice2 == 1)
						{
							if (FS.size() == 0)
							{
								cout << "\nYou do not have any active employees." << endl;
							}
							else
							{
								cout << "\nList of active employees:" << endl;
								for (int i = 0; i < FS.size(); i++)
								{

									cout << "Worker-" << i + 1 << endl;
									FS[i].displayInformation();
									cout << endl;
								}
							}
							cout << "\nPlease Enter the information of the employee you want to add" << endl;
							string ns_info;
							int age_info;
							bool gender_info;
							int id_info;
							int salary_info;
							cout << "Name and Surname: ";
							cin.ignore();
							getline(cin, ns_info);
							cout << "Age: ";
							cin >> age_info;
							cout << "Gender (For Male press 1,For Female press 0): ";
							cin >> gender_info;

							while (true)
							{
								cout << "WorkID:";
								cin >> id_info;
								if (id_info != 1000)
								{
									if (FS.size() == 0)
									{
										break;
									}
									else
									{
										int controller = 1;
										for (int i = 0; i < FS.size(); i++)
										{
											if (id_info == FS[i].getworkID())
											{
												cout << "Since the ID number you entered conflicts with another employee's ID number, you need to enter a different ID number." << endl;
												controller = 0;
												break;
											}
											else
											{

											}
										}
										if (controller == 1)
										{
											break;
										}


									}
								}
								else
								{
									cout << "Since the ID number you entered conflicts with your own ID number, you need to enter a different ID number." << endl;
								}
							}
							cout << "Net Salary: ";
							cin >> salary_info;
							cout << "As a result of the salary information you enter, the total cost of this employee will be:" << salary_info * 1.3823 << endl;
							FS.push_back(FuelSupplier(ns_info, age_info, gender_info, id_info, salary_info));
							cout << "You have successfully recruited " << ns_info << endl;
							admin.updateSafe(-salary_info * 1.3823);


						}
						else if (choice2 == 2)
						{
							if (FS.size() == 0)
							{
								cout << "\nYou do not have any active employees.Therefore, you cannot fire any of your employees." << endl;
							}
							else
							{
								cout << "\nList of active employees:" << endl;
								for (int i = 0; i < FS.size(); i++)
								{
									cout << "Worker-" << i + 1 << endl;
									FS[i].displayInformation();
								}
								cout << "Which ID do you want to fire your employee?";
								int fireID;
								cin >> fireID;
								for (int i = 0; i < FS.size(); i++)
								{
									if (FS[i].getworkID() == fireID)
									{

										cout << "Since you fired your employee, you will have to pay 3 times their salary, do you approve? (y/n):";
										char cr1;
										cin >> cr1;
										if (cr1 == 'y' || cr1 == 'Y')
										{
											admin.updateSafe(-3 * FS[i].getSalary() * 1.3823);
											FS.erase(FS.begin() + i);
											cout << "Worker " << fireID << " was fired." << endl;

										}
										else
										{
											cout << "You've given up on firing the employee you've chosen." << endl;
										}
									}
									else
									{
										cout << "The ID number you entered does not match any of your employee's ID" << endl;
									}
								}
							}
						}
						else if (choice2 == 3)
						{
							if (FS.size() == 0)
							{
								cout << "\nYou do not have any active employees.Therefore, you cannot update salary any of your employees." << endl;

							}
							else
							{
								cout << "\nList of active employees:" << endl;
								for (int i = 0; i < FS.size(); i++)
								{
									cout << "Worker-" << i + 1 << endl;
									FS[i].displayInformation();
								}
								cout << "Which ID number would you like to update the salary of your employee?";
								int updateID;
								cin >> updateID;
								for (int i = 0; i < FS.size(); i++)
								{
									if (FS[i].getworkID() == updateID)
									{
										cout << "\nCurrent Salary of " << updateID << ": " << FS[i].getSalary() << endl;
										cout << "Please enter the amount of new salary for Emplooye " << updateID;
										double new_salary;
										cin >> new_salary;
										FS[i].updateSalary(new_salary);
										cout << "The operation completed successfully." << endl;

									}
									else
									{
										cout << "The ID number you entered does not match any of your employee's ID" << endl;
									}
								}

							}
						}
						else if (choice2 == 4)
						{
							if (FS.size() == 0)
							{
								cout << "\nYou do not have any active employees." << endl;
							}
							else
							{
								cout << "\nList of active employees:" << endl;
								for (int i = 0; i < FS.size(); i++)
								{

									cout << "Worker-" << i + 1 << endl;
									FS[i].displayInformation();
									cout << endl;
								}
							}
						}
						else if (choice2 == 5)
						{
							cout << "There is " << admin.getSafe() << "$ in the safe of your station." << endl;
							admin.depositAndWithdraw();
						}
						else if (choice2 == 6)
						{
							while (true)
							{
								cout << "\nWhat type of fuel do you want to deal with?\n"
									<< "1. Gasoline\n"
									<< "2. Diesel\n"
									<< "3. LPG\n"
									<< "4. Exit to the upper menu\n"
									<< "Your choice: " << endl;
								int choice3;
								cin >> choice3;
								if (choice3 == 1)
								{
									cout << "\nType, amount and price information for gasoline:" << endl;
									for (int i = 0; i < 2; i++)
									{
										gasol[i].displayInfo();
									}
									cout << "\nWhat/s would you like to update for this fuel type?\n"
										<< "1.Amount\n"
										<< "2.Price\n"
										<< "3.All of the above\n"
										<< "Your choice: ";
									cin >> choice3;
									if (choice3 == 1)
									{
										for (int i = 0; i < 2; i++)
										{
											cout << "For " << gasol[i].getType() << " ,please enter the amount:";
											double amount;
											cin >> amount;
											gasol[i].updateTank(amount);
										}
									}
									else if (choice3 == 2)
									{
										for (int i = 0; i < 2; i++)
										{
											cout << "For " << gasol[i].getType() << " ,please enter the price:";
											float price;
											cin >> price;
											gasol[i].setPrice(price);
										}
									}
									else if (choice3 == 3)
									{
										for (int i = 0; i < 2; i++)
										{
											cout << "For " << gasol[i].getType() << " ,please enter the amount:";
											double amount;
											cin >> amount;
											gasol[i].updateTank(amount);
											cout << "Price:";
											float price;
											cin >> price;
											gasol[i].setPrice(price);
											//gasol[i] = GasStation(amount, price);

										}
									}
								}
								else if (choice3 == 2)
								{
									cout << "\nType, amount and price information for DIESEL:" << endl;
									for (int i = 0; i < 2; i++)
									{
										diesel[i].displayInfo();
									}
									cout << "\nWhat/s would you like to update for this fuel type?\n"
										<< "1.Amount\n"
										<< "2.Price\n"
										<< "3.All of the above\n"
										<< "Your choice: ";
									cin >> choice3;
									if (choice3 == 1)
									{
										for (int i = 0; i < 2; i++)
										{
											cout << "For " << diesel[i].getType() << " ,please enter the amount:";
											double amount;
											cin >> amount;
											diesel[i].updateTank(amount);
										}
									}
									else if (choice3 == 2)
									{
										for (int i = 0; i < 2; i++)
										{
											cout << "For " << diesel[i].getType() << " ,please enter the price:";
											float price;
											cin >> price;
											diesel[i].setPrice(price);
										}
									}
									else if (choice3 == 3)
									{
										for (int i = 0; i < 2; i++)
										{
											cout << "For " << diesel[i].getType() << " ,please enter the amount:";
											double amount;
											cin >> amount;
											diesel[i].updateTank(amount);
											cout << "Price:";
											float price;
											cin >> price;
											diesel[i].setPrice(price);
											//gasol[i] = GasStation(amount, price);

										}
									}
								}
								else if (choice3 == 3)
								{
									cout << "\nAmount and price information for LPG:" << endl;
									cout << "LPG: ";
									lpg.displayInfo();
									cout << "\nWhat/s would you like to update for this fuel type?\n"
										<< "1.Amount\n"
										<< "2.Price\n"
										<< "3.All of the above\n"
										<< "Your choice: ";
									cin >> choice3;
									if (choice3 == 1)
									{

										cout << "For LPG,please enter the amount:";
										double amount;
										cin >> amount;
										lpg.updateTank(amount);

									}
									else if (choice3 == 2)
									{

										cout << "For LPG, please enter the price:";
										float price;
										cin >> price;
										lpg.setPrice(price);

									}
									else if (choice3 == 3)
									{

										cout << "For LPG, please enter the amount:";
										double amount;
										cin >> amount;
										lpg.updateTank(amount);
										cout << "Price:";
										float price;
										cin >> price;
										lpg.setPrice(price);

									}
								}
								else if (choice3 == 4)
								{
									cout << "You are directed to the upper menu." << endl;
									break;
								}
								else
								{
									cout << "Please try again" << endl;
								}
							}

						}
						else if (choice2 == 7)
						{
						int flag = 1;
						while (flag != 0)
						{
							cout << endl;
							int choice1;
							cout << "1.Create a product" << endl;
							cout << "2.Order a Product" << endl;
							cout << "3.Modify a Product" << endl;
							cout << "4.Delete a Product" << endl;
							cout << "5.Show Available Products" << endl;
							cout << "6.Exit.\n" << endl;
							cin >> choice1;
							cout << endl;

							if (choice1 == 1)
							{
								int create_choice;
								cout << "Please choose the product you want to create:" << endl;
								cout << "1.Snacks" << endl;
								cout << "2.Food" << endl;
								cout << "3.Drinks" << endl;
								cout << "4.Cigarettes" << endl;
								cout << "5.Other\n" << endl;
								cin >> create_choice;
								cout << endl;
								if (create_choice == 1)
								{
									string name;
									float price;
									int discount;
									float tax;
									cout << "Enter the name of the product: ";
									cin >> name;
									cout << "Enter the price of the product: ";
									cin >> price;
									cout << "Enter the discount rate of the product: ";
									cin >> discount;
									cout << "Enter the tax value of the product: ";
									cin >> tax;
									snacks.push_back(Snacks(name, price, 0, tax, discount));
									snack_i++;
								}
								if (create_choice == 2)
								{
									string name;
									float price;
									int discount;
									float tax;
									int prep1, prep2;
									cout << "Enter the name of the product: ";
									cin >> name;
									cout << "Enter the price of the product: ";
									cin >> price;
									cout << "Enter the discount rate of the product: ";
									cin >> discount;
									cout << "Enter the tax value of the product: ";
									cin >> tax;
									cout << "Enter the first prepare time: ";
									cin >> prep1;
									cout << "Enter the second prepare time: ";
									cin >> prep2;
									foods.push_back(Food(name, price, 0, tax, discount, prep1, prep2));
									food_i++;
								}
								if (create_choice == 3)
								{
									string name;
									float price;
									int discount, liter;
									float tax;
									cout << "Enter the name of the product: ";
									cin >> name;
									cout << "Enter the price of the product: ";
									cin >> price;
									cout << "Enter the discount rate of the product: ";
									cin >> discount;
									cout << "Enter the tax value of the product: ";
									cin >> tax;
									cout << "Enter the liter of the product: ";
									cin >> liter;
									drinks.push_back(Drinks(name, price, 0, tax, discount, liter));
									drink_i++;
								}
								if (create_choice == 4)
								{
									string name;
									float price;
									int discount;
									float tax;
									cout << "Enter the name of the product: ";
									cin >> name;
									cout << "Enter the price of the product: ";
									cin >> price;
									cout << "Enter the discount rate of the product: ";
									cin >> discount;
									cout << "Enter the tax value of the product: ";
									cin >> tax;
									cigarettes.push_back(Cigarettes(name, price, 0, tax, discount));
									cigarette_i++;
								}
								if (create_choice == 5)
								{
									string name;
									float price;
									int discount;
									float tax;
									cout << "Enter the name of the product: ";
									cin >> name;
									cout << "Enter the price of the product: ";
									cin >> price;
									cout << "Enter the discount rate of the product: ";
									cin >> discount;
									cout << "Enter the tax value of the product: ";
									cin >> tax;
									others.push_back(Other(name, price, 0, tax, discount));
									other_i++;
								}
							}
							else if (choice1 == 2)    //Admin kodundan para artıp azalacak.
							{
								int order_choice;
								
								cout << "Please choose the product you want to order:" << endl;
								cout << "1.Snacks" << endl;
								cout << "2.Food" << endl;
								cout << "3.Drinks" << endl;
								cout << "4.Cigarettes" << endl;
								cout << "5.Other\n" << endl;
								cin >> order_choice;
								cout << endl;
								if (order_choice == 1)
								{
									float temp_balance;
									cout << "Please input the index value of the product you want to order: ";
									cin >> snack_index;
									temp_balance = snacks[snack_index - 1].orderSnack();
									admin.updateSafe(- temp_balance);
									temp_balance = admin.getSafe();
									cout << "Your new balance: " << temp_balance << endl;
								}
								if (order_choice == 2)
								{
									float temp_balance;
									cout << "Please input the index value of the product you want to order: ";
									cin >> food_index;
									temp_balance = foods[food_index - 1].orderFood();
									admin.updateSafe(-temp_balance);
									temp_balance = admin.getSafe(),
									cout << "Your new balance: " << temp_balance << endl;
								}
								if (order_choice == 3)
								{
									float temp_balance, total_balance;
									cout << "Please input the index value of the product you want to order: ";
									cin >> drink_index;
									temp_balance = drinks[drink_index - 1].orderDrink();
									total_balance = admin.getSafe();
									admin.updateSafe(-temp_balance);
									temp_balance = admin.getSafe();
									cout << "Your new balance: " << temp_balance << endl;
								}
								if (order_choice == 4)
								{
									float temp_balance, total_balance;
									cout << "Please input the index value of the product you want to order: ";
									cin >> cigarette_index;
									temp_balance = cigarettes[cigarette_index - 1].orderCigarette();
									total_balance = admin.getSafe();
									admin.updateSafe(-temp_balance);
									temp_balance = admin.getSafe();
									cout << "Your new balance: " << temp_balance << endl;
								}
								if (order_choice == 5)
								{
									float temp_balance, total_balance;
									cout << "Please input the index value of the product you want to order: ";
									cin >> other_index;
									temp_balance = others[other_index - 1].orderOther();
									total_balance = admin.getSafe();
									admin.updateSafe(-temp_balance);
									temp_balance = admin.getSafe();
									cout << "Your new balance: " << temp_balance << endl;
								}
							}
							else if (choice1 == 3)
							{
								int modify_flag = 1;
								int modify_choice, modify_choice2;
								cout << "Please choose the product type you want to modify." << endl;
								cout << "1.Snacks" << endl;
								cout << "2.Food" << endl;
								cout << "3.Drinks" << endl;
								cout << "4.Cigarettes" << endl;
								cout << "5.Other" << endl;
								cin >> modify_choice;
								if (modify_choice == 1)
								{
									modify_flag = 1;
									while (modify_flag != 0)
									{
										cout << "Enter the index value of the product you want to modify: ";
										cin >> snack_index;
										cout << "Which aspect of the product do you want to modify?" << endl;
										cout << "1.Product Name" << endl;
										cout << "2.Price" << endl;
										cout << "3.Quantity" << endl;
										cout << "4.Tax Value" << endl;
										cout << "5.Discount" << endl;
										cout << "6.Stop Modifying." << endl;
										cin >> modify_choice2;
										if (modify_choice2 == 1)
										{
											string modifySnack_name;
											cout << "Enter a new name for product: ";
											cin >> modifySnack_name;
											snacks[snack_index - 1].setName(modifySnack_name);
											cout << "Name of the product has been modified." << endl;
										}
										else if (modify_choice2 == 2)
										{
											float modifySnack_price;
											cout << "Enter a new price for product: ";
											cin >> modifySnack_price;
											snacks[snack_index - 1].setPrice(modifySnack_price);
											cout << "Price of the product has been modified." << endl;
										}
										else if (modify_choice2 == 3)
										{
											int modifySnack_quantity;
											cout << "Enter a new quantity for product: ";
											cin >> modifySnack_quantity;
											snacks[snack_index - 1].setQuantity(modifySnack_quantity);
											cout << "Quantity of the prodcuct has been modified." << endl;
										}
										else if (modify_choice2 == 4)
										{
											float modifySnack_tax;
											cout << "Enter a new tax rate for product: ";
											cin >> modifySnack_tax;
											snacks[snack_index - 1].setTax(modifySnack_tax);
											cout << "Tax rate of the product has been modified." << endl;
										}
										else if (modify_choice2 == 5)
										{
											int modifySnack_discount;
											cout << "Enter a new discount rate for product: ";
											cin >> modifySnack_discount;
											snacks[snack_index - 1].setDiscount(modifySnack_discount);
											cout << "Discount rate of the product has been modified." << endl;
										}
										else if (modify_choice2 == 6)
										{
											modify_flag = 0;
										}
									}
								}
								else if (modify_choice == 2)
								{
									modify_flag = 1;
									while (modify_flag != 0)
									{
										cout << "Enter the index value of the product you want to modify: ";
										cin >> food_index;
										cout << "Which aspect of the product do you want to modify?" << endl;
										cout << "1.Product Name" << endl;
										cout << "2.Price" << endl;
										cout << "3.Quantity" << endl;
										cout << "4.Tax Value" << endl;
										cout << "5.Discount" << endl;
										cout << "6.Prepare Time 1" << endl;
										cout << "7.Prepare Time 2" << endl;
										cout << "8.Stop Modifying." << endl;
										cin >> modify_choice2;
										if (modify_choice2 == 1)
										{
											string modify_name;
											cout << "Enter a new name for product: ";
											cin >> modify_name;
											foods[food_index - 1].setName(modify_name);
											cout << "Name of the product has been modified." << endl;
										}
										else if (modify_choice2 == 2)
										{
											float modify_price;
											cout << "Enter a new price for product: ";
											cin >> modify_price;
											foods[food_index - 1].setPrice(modify_price);
											cout << "Price of the product has been modified." << endl;
										}
										else if (modify_choice2 == 3)
										{
											int modify_quantity;
											cout << "Enter a new quantity for product: ";
											cin >> modify_quantity;
											foods[food_index - 1].setQuantity(modify_quantity);
											cout << "Quantity of the prodcuct has been modified." << endl;
										}
										else if (modify_choice2 == 4)
										{
											float modify_tax;
											cout << "Enter a new tax rate for product: ";
											cin >> modify_tax;
											foods[food_index - 1].setTax(modify_tax);
											cout << "Tax rate of the product has been modified." << endl;
										}
										else if (modify_choice2 == 5)
										{
											int modify_discount;
											cout << "Enter a new discount rate for product: ";
											cin >> modify_discount;
											foods[food_index - 1].setDiscount(modify_discount);
											cout << "Discount rate of the product has been modified." << endl;
										}
										else if (modify_choice2 == 6)
										{
											int modifyFood_prep1;
											cout << "Enter a new preparation time 1 for product: ";
											cin >> modifyFood_prep1;
											foods[food_index - 1].set_Preptime1(modifyFood_prep1);
											cout << "Preparation time 1 has been modified." << endl;
										}
										else if (modify_choice2 == 7)
										{
											int modifyFood_prep2;
											cout << "Enter a new preparation time 2 for product: ";
											cin >> modifyFood_prep2;
											foods[food_index].set_Preptime2(modifyFood_prep2);
											cout << "Preparation time 2 has been modified." << endl;
										}
										else if (modify_choice2 == 8)
										{
											modify_flag = 0;
										}
									}
								}
								else if (modify_choice == 3)
								{
									modify_flag = 1;
									while (modify_flag != 0)
									{
										cout << "Enter the index value of the product you want to modify: ";
										cin >> drink_index;
										cout << "Which aspect of the product do you want to modify?" << endl;
										cout << "1.Product Name" << endl;
										cout << "2.Price" << endl;
										cout << "3.Quantity" << endl;
										cout << "4.Tax Value" << endl;
										cout << "5.Discount" << endl;
										cout << "6.Liter" << endl;
										cout << "7.Stop Modifying." << endl;
										cin >> modify_choice2;
										if (modify_choice2 == 1)
										{
											string modifyDrink_name;
											cout << "Enter a new name for product: ";
											cin >> modifyDrink_name;
											drinks[drink_index - 1].setName(modifyDrink_name);
											cout << "Name of the product has been modified." << endl;
										}
										else if (modify_choice2 == 2)
										{
											int modifyDrink_price;
											cout << "Enter a new price for product: ";
											cin >> modifyDrink_price;
											drinks[drink_index - 1].setPrice(modifyDrink_price);
											cout << "Price of the product has been modified." << endl;
										}
										else if (modify_choice2 == 3)
										{
											int modifyDrink_quantity;
											cout << "Enter a new quantity for product: ";
											cin >> modifyDrink_quantity;
											drinks[drink_index - 1].setQuantity(modifyDrink_quantity);
											cout << "Quantity of the product has been modified." << endl;
										}
										else if (modify_choice2 == 4)
										{
											int modifyDrink_tax;
											cout << "Enter a new tax rate for product: ";
											cin >> modifyDrink_tax;
											drinks[drink_index - 1].setTax(modifyDrink_tax);
											cout << "Tax rate of the product has been modified." << endl;
										}
										else if (modify_choice2 == 5)
										{
											float modifyDrink_discount;
											cout << "Enter a new discount rate for product: ";
											cin >> modifyDrink_discount;
											drinks[drink_index - 1].setDiscount(modifyDrink_discount);
											cout << "Discount rate of the product has been modified." << endl;
										}
										else if (modify_choice2 == 6)
										{
											float modifyDrink_liter;
											cout << "Enter a new liter for product: ";
											cin >> modifyDrink_liter;
											drinks[drink_index].setDrink_liter(modifyDrink_liter);
											cout << "Liter of the product has been modified." << endl;
										}
										else if (modify_choice2 == 7)
										{
											modify_flag = 0;
										}
									}
								}
								else if (modify_choice == 4)
								{
									modify_flag = 1;
									while (modify_flag != 0)
									{
										cout << "Enter the index value of the product you want to modify: ";
										cin >> cigarette_index;
										cout << "Which aspect of the product do you want to modify?" << endl;
										cout << "1.Product Name" << endl;
										cout << "2.Price" << endl;
										cout << "3.Quantity" << endl;
										cout << "4.Tax Value" << endl;
										cout << "5.Discount" << endl;
										cout << "6.Stop Modifying." << endl;
										cin >> modify_choice2;
										if (modify_choice2 == 1)
										{
											string modifyCigarette_name;
											cout << "Enter a new name for product: ";
											cin >> modifyCigarette_name;
											cigarettes[cigarette_index - 1].setName(modifyCigarette_name);
										}
										else if (modify_choice2 == 2)
										{
											int modifyCigarette_price;
											cout << "Enter a new price for product: ";
											cin >> modifyCigarette_price;
											cigarettes[cigarette_index - 1].setPrice(modifyCigarette_price);
										}
										else if (modify_choice2 == 3)
										{
											int modifyCigarette_quantity;
											cout << "Enter a new quantity for product: ";
											cin >> modifyCigarette_quantity;
											cigarettes[cigarette_index - 1].setQuantity(modifyCigarette_quantity);
										}
										else if (modify_choice2 == 4)
										{
											int modifyCigarette_tax;
											cout << "Enter a new tax rate for product: ";
											cin >> modifyCigarette_tax;
											cigarettes[cigarette_index - 1].setTax(modifyCigarette_tax);
										}
										else if (modify_choice2 == 5)
										{
											float modifyCigarette_discount;
											cout << "Enter a new discount rate for product: ";
											cin >> modifyCigarette_discount;
											cigarettes[cigarette_index - 1].setDiscount(modifyCigarette_discount);
										}
										else if (modify_choice2 == 6)
										{
											modify_flag = 0;
										}
									}
								}
								else if (modify_choice == 5)
								{
									modify_flag = 1;
									while (modify_flag != 0)
									{
										cout << "Enter the index value of the product you want to modify: ";
										cin >> other_index;
										cout << "Which aspect of the product do you want to modify?" << endl;
										cout << "1.Product Name" << endl;
										cout << "2.Price" << endl;
										cout << "3.Quantity" << endl;
										cout << "4.Tax Value" << endl;
										cout << "5.Discount" << endl;
										cout << "6.Stop Modifying." << endl;
										cin >> modify_choice2;
										if (modify_choice2 == 1)
										{
											string modifyOther_name;
											cout << "Enter a new name for product: ";
											cin >> modifyOther_name;
											others[other_index].setName(modifyOther_name);
										}
										else if (modify_choice2 == 2)
										{
											int modifyOther_price;
											cout << "Enter a new price for product: ";
											cin >> modifyOther_price;
											others[other_index].setPrice(modifyOther_price);
										}
										else if (modify_choice2 == 3)
										{
											int modifyOther_quantity;
											cout << "Enter a new quantity for product: ";
											cin >> modifyOther_quantity;
											others[other_index].setQuantity(modifyOther_quantity);
										}
										else if (modify_choice2 == 4)
										{
											int modifyOther_tax;
											cout << "Enter a new tax rate for product: ";
											cin >> modifyOther_tax;
											others[other_index].setTax(modifyOther_tax);
										}
										else if (modify_choice2 == 5)
										{
											float modifyOther_discount;
											cout << "Enter a new discount rate for product: ";
											cin >> modifyOther_discount;
											others[other_index].setDiscount(modifyOther_discount);
										}
									}
								}
							}
							else if (choice1 == 4)
							{
								int delete_choice;
								cout << "Please choose the type of the product that you want to delete: " << endl;
								cout << "1.Snacks" << endl;
								cout << "2.Foods" << endl;
								cout << "3.Drinks" << endl;
								cout << "4.Cigarettes" << endl;
								cout << "5.Others" << endl;
								cin >> delete_choice;
								if (delete_choice == 1)
								{
									cout << "Input the index value of the product that you want to delete: ";
									cin >> snack_index;
									snacks[snack_index - 1].setName(" ");
									snacks[snack_index - 1].setPrice(0);
									snacks[snack_index - 1].setQuantity(0);
									snacks[snack_index - 1].setDiscount(0);
									snacks[snack_index - 1].setTax(0);
									cout << "Product is deleted." << endl;
								}
								else if (delete_choice == 2)
								{
									cout << "Input the index value of the product that you want to delete: ";
									cin >> food_index;
									foods[food_index - 1].setName(" ");
									foods[food_index - 1].setPrice(0);
									foods[food_index - 1].setQuantity(0);
									foods[food_index - 1].setDiscount(0);
									foods[food_index - 1].setTax(0);
									foods[food_index - 1].set_Preptime1(0);
									foods[food_index - 1].set_Preptime2(0);
									cout << "Product is deleted." << endl;
								}
								else if (delete_choice == 3)
								{
									cout << "Input the index value of the product that you want to delete: ";
									cin >> drink_index;
									drinks[drink_index - 1].setName(" ");
									drinks[drink_index - 1].setPrice(0);
									drinks[drink_index - 1].setQuantity(0);
									drinks[drink_index - 1].setDiscount(0);
									drinks[drink_index - 1].setTax(0);
									drinks[drink_index - 1].setDrink_liter(0);
									cout << "Product is deleted." << endl;
								}
								else if (delete_choice == 4)
								{
									cout << "Input the index value of the product that you want to delete: ";
									cin >> cigarette_index;
									cigarettes[cigarette_index - 1].setName(" ");
									cigarettes[cigarette_index - 1].setPrice(0);
									cigarettes[cigarette_index - 1].setQuantity(0);
									cigarettes[cigarette_index - 1].setDiscount(0);
									cigarettes[cigarette_index - 1].setTax(0);
									cout << "Product is deleted." << endl;
								}
								else if (delete_choice == 5)
								{
									cout << "Input the index value of the product that you want to delete: ";
									cin >> other_index;
									others[other_index - 1].setName(" ");
									others[other_index - 1].setPrice(0);
									others[other_index - 1].setQuantity(0);
									others[other_index - 1].setDiscount(0);
									others[other_index - 1].setTax(0);
									cout << "Product is deleted." << endl;
								}
							}
							else if (choice1 == 5)
							{
								int display_choice;
								cout << "Please choose the product type that you want to display: " << endl;
								cout << "1.Snacks" << endl;
								cout << "2.Foods" << endl;
								cout << "3.Drinks" << endl;
								cout << "4.Cigarettes" << endl;
								cout << "5.Others" << endl;
								cin >> display_choice;
								if (display_choice == 1)
								{
									if (snack_i == 0)
									{
										cout << "\nYou have no products." << endl;
									}
									for (int i = 0; i < snack_i; i++)
									{
										cout << "\n\n";
										snacks[i].displaySnack();
										cout << "\n\n";
									}
								}
								else if (display_choice == 2)
								{
									if (food_i == 0)
									{
										cout << "\nYou have no products." << endl;
									}
									for (int i = 0; i < food_i; i++)
									{
										cout << "\n\n";
										foods[i].displayFood();
										cout << "\n\n";
									}
								}
								else if (display_choice == 3)
								{
									if (drink_i == 0)
									{
										cout << "\nYou have no products." << endl;
									}
									for (int i = 0; i < drink_i; i++)
									{
										cout << "\n\n";
										drinks[i].displayDrink();
										cout << "\n\n";
									}
								}
								else if (display_choice == 4)
								{
									if (cigarette_i == 0)
									{
										cout << "\nYou have no products." << endl;
									}
									for (int i = 0; i < cigarette_i; i++)
									{
										cout << "\n\n";
										cigarettes[i].displayCigarette();
										cout << "\n\n";
									}
								}
								else if (display_choice == 5)
								{
									if (other_i == 0)
									{
										cout << "\nYou have no products." << endl;
									}
									for (int i = 0; i < other_i; i++)
									{
										cout << "\n\n";
										others[i].displayOther();
										cout << "\n\n";
									}
								}
							}
							else if (choice1 == 6)
							{
								flag = 0;
								cout << "Bye!" << endl;
							}
						}
						}
						else if (choice2 == 8)
						{
							cout << "Please enter the your current password: ";
							cin >> password;
							if (password == admin.getPassword())
							{
								cout << "Please enter the your new password:";
								string p1, p2;
								cin >> p1;
								cout << "Please enter one more:";
								cin >> p2;
								if (p1 == p2)
								{
									admin.setPassword(p1);
									cout << "Your password has been successfully changed" << endl;
								}
								else
								{
									cout << "The passwords you just entered do not match. Please try again." << endl;
								}
							}
						}
						else if (choice2 == 9)
						{
							break;
						}

					}
					cout << "You are redirected to the main menu.\n" << endl;
					break;
				}
				else
				{
					cout << "You entered your work number or password incorrectly." << endl;
					cout << "If u want to try again y/n ?";
					char cr;
					cin >> cr;
					if (cr == 'y' || cr == 'Y')
					{

					}
					else
					{
						cout << "You are redirected to the main menu.\n" << endl;
						break;
					}
					cout << endl;
				}

			}
		}
		else if (choice == 2)
		{
			if (FS.size() == 0)
			{
				cout << "You cannot log in as an employee, as there are no employees at this station." << endl;
			}
			else
			{
				cout << "Please Enter the your WorkID:";
				int workID;
				cin >> workID;
				for (int i = 0; i < FS.size(); i++)
				{
					if (FS[i].getworkID() == workID)
					{
						cout << "Hello, our esteemed employee number " << FS[i].getworkID() << endl;
						cout << "Your Information:" << endl;
						FS[i].displayInformation();
						break;
					}
					else
					{
						cout << "There is no employee belonging to the ID number you entered in our system." << endl;
					}
					cout << endl;
				}
			}
		}
		else if (choice == 3)//customer
		{

			string plate;
			float total_val = 0;
			float wantToBuy = 0;
			float point = 0;
			int hold = 0;
			bool check = 0;
			while (true)
			{
				cout << "Select the operation you want to do\n"
					<< "1. Market\n"
					<< "2. Refueling\n"
					<< "3. Check your point information\n"
					<< "4. See your Total Bill and Exit\n"
					<< "Your choice: ";
				int ch_customer;
				cin >> ch_customer;
				if (ch_customer == 1)//market
				{
					cout << endl;
					int flag = 1;
					float total_market = 0;
					while (flag != 0)
					{
						int choice2;
						cout << "1.Display Available Products." << endl;
						cout << "2.Buy Products." << endl;
						cout << "3.Display Total Price and Exit" << endl;
						
						cin >> choice2;
						if (choice2 == 1)
						{
							cout << "Snacks:" << endl;
							for (int i = 0; i < snack_i; i++)
							{
								cout << "\n\n";
								cout << i + 1 << ")" << endl;
								snacks[i].displaySnack();
								cout << "\n\n";
							}
							cout << "Foods:" << endl;
							for (int i = 0; i < food_i; i++)
							{
								cout << "\n\n";
								cout << i + 1 << ")" << endl;
								foods[i].displayFood();
								cout << "\n\n";
							}
							cout << "Drinks:" << endl;
							for (int i = 0; i < drink_i; i++)
							{
								cout << "\n\n";
								cout << i + 1 << ")" << endl;
								drinks[i].displayDrink();
								cout << "\n\n";
							}
							cout << "Cigarettes:" << endl;
							for (int i = 0; i < cigarette_i; i++)
							{
								cout << "\n\n";
								cout << i + 1 << ")" << endl;
								cigarettes[i].displayCigarette();
								cout << "\n\n";
							}
							cout << "Others:" << endl;
							for (int i = 0; i < other_i; i++)
							{
								cout << "\n\n";
								cout << i + 1 << ")" << endl;
								others[i].displayOther();
								cout << "\n\n";
							}
						}
						else if (choice2 == 2)
						{
							
							int buy_choice;
							float discounted_price;
							cout << "What do you want to buy?" << endl;
							cout << "1.Snacks" << endl;
							cout << "2.Foods" << endl;
							cout << "3.Drinks" << endl;
							cout << "4.Cigarettes" << endl;
							cout << "5.Others" << endl;
							cin >> buy_choice;
							if (buy_choice == 1)
							{
								int snackBuy;
								string buyName;
								float buyPrice;
								int buyDiscount;
								int buyQuantity;
								cout << "Please enter the index value of the snack that you want to buy." << endl;
								cin >> snack_index;
								buyName = snacks[snack_index - 1].getName();
								buyPrice = snacks[snack_index - 1].getPrice();
								buyDiscount = snacks[snack_index - 1].getDiscount();
								buyQuantity = snacks[snack_index - 1].getQuantity();
								cout << "How many " << buyName << "s do you want to buy?";
								cin >> snackBuy;
								discounted_price = buyPrice - (buyPrice / 100 * buyDiscount);
								discounted_price = snackBuy * discounted_price;
								total_market = total_market + discounted_price;
								snacks[snack_index - 1].setQuantity(buyQuantity - snackBuy);
							}
							else if (buy_choice == 2)
							{
								int foodBuy;
								string buyName;
								float buyPrice;
								int buyDiscount;
								int buyQuantity;
								cout << "Please enter the index value of the food that you want to buy." << endl;
								cin >> food_index;
								buyName = foods[food_index - 1].getName();
								buyPrice = foods[food_index - 1].getPrice();
								buyDiscount = foods[food_index - 1].getDiscount();
								buyQuantity = foods[food_index - 1].getQuantity();
								cout << "How many " << buyName << "s do you want to buy?";
								cin >> foodBuy;
								discounted_price = buyPrice - (buyPrice / 100 * buyDiscount);
								discounted_price = foodBuy * discounted_price;
								total_market = total_market + discounted_price;
								foods[food_index - 1].setQuantity(buyQuantity - foodBuy);
							}
							else if (buy_choice == 3)
							{
								int drinkBuy;
								string buyName;
								float buyPrice;
								int buyDiscount;
								int buyQuantity;
								cout << "Please enter the index value of the drink that you want to buy." << endl;
								cin >> drink_index;
								buyName = drinks[drink_index - 1].getName();
								buyPrice = drinks[drink_index - 1].getPrice();
								buyDiscount = drinks[drink_index - 1].getDiscount();
								buyQuantity = drinks[drink_index - 1].getQuantity();
								cout << "How many " << buyName << "s do you want to buy?";
								cin >> drinkBuy;
								discounted_price = buyPrice - (buyPrice / 100 * buyDiscount);
								discounted_price = drinkBuy * discounted_price;
								total_market = total_market + discounted_price;
								drinks[drink_index - 1].setQuantity(buyQuantity - drinkBuy);
							}
							else if (buy_choice == 4)
							{
								int cigaretteBuy;
								string buyName;
								float buyPrice;
								int buyDiscount;
								int buyQuantity;
								cout << "Please enter the index value of the cigarette that you want to buy." << endl;
								cin >> cigarette_index;
								buyName = cigarettes[cigarette_index - 1].getName();
								buyPrice = cigarettes[cigarette_index - 1].getPrice();
								buyDiscount = cigarettes[cigarette_index - 1].getDiscount();
								buyQuantity = cigarettes[cigarette_index - 1].getQuantity();
								cout << "How many " << buyName << "s do you want to buy?";
								cin >> cigaretteBuy;
								discounted_price = buyPrice - (buyPrice / 100 * buyDiscount);
								discounted_price = cigaretteBuy * discounted_price;
								total_market = total_market + discounted_price;
								cigarettes[cigarette_index - 1].setQuantity(buyQuantity - cigaretteBuy);
							}
							else if (buy_choice == 5)
							{
								int otherBuy;
								string buyName;
								float buyPrice;
								int buyDiscount;
								int buyQuantity;
								cout << "Please enter the index value of the product that you want to buy." << endl;
								cin >> other_index;
								buyName = others[other_index - 1].getName();
								buyPrice = others[other_index - 1].getPrice();
								buyDiscount = others[other_index - 1].getDiscount();
								buyQuantity = others[other_index - 1].getQuantity();
								cout << "How many " << buyName << "s do you want to buy?";
								cin >> otherBuy;
								discounted_price = buyPrice - (buyPrice / 100 * buyDiscount);
								discounted_price = otherBuy * discounted_price;
								total_market = total_market + discounted_price;
								others[other_index - 1].setQuantity(buyQuantity - otherBuy);
							}
						}
						else if (choice2 == 3)
						{
							cout << "Total price you need to pay: " << total_market << "$" << endl;
							total_val += total_market;
							cout << "Thanks for shopping from us." << endl;
							break;
						}
						cout << endl;
					}
				}
				else if (ch_customer == 2)
				{

					cout << "Please enter the your plate information (Ex: 06YY68):";
					cin >> plate;
					for (int i = 0; i < customer.size(); i++)
					{
						if (plate.compare(customer[i].getlicense_plate()) == 0)
						{
							check = 1;
							hold = i;
						}
					}
					cout << "Select your vehicle's fuel type\n"
						<< "1. Gasoline\n"
						<< "2. Diesel\n"
						<< "3. LPG\n"
						<< "4. Exit\n"
						<< "Your choice: ";
					int fueltype_ch;
					cin >> fueltype_ch;
					if (fueltype_ch == 1)
					{
						cout << "There are two types of gasoline fuel in our station." << endl;
						for (int i = 0; i < 2; i++)
						{
							cout << i + 1 << ". Type " << gasol[i].getType() << " Price: " << gasol[i].getPrice() << endl;
						}
						cout << "Your choice: ";
						int gasol_ch;
						cin >> gasol_ch;
						if (gasol_ch == 1)
						{
							while (true)
							{
								cout << "How much fuel do you want to buy? :";
								cin >> wantToBuy;
								float calc;
								calc = wantToBuy / gasol[0].getPrice();
								if (calc <= gasol[0].getTank())
								{
									gasol[0].updateTank(-calc);
									admin.updateSafe(wantToBuy);
									total_val += wantToBuy;
									cout << "As a result of your request you made a purchase of " << wantToBuy << " TL from " << gasol[0].getType() << " fuel type." << endl;
									point = wantToBuy * 0.05;
									cout << "And you earned " << point << " points in this way" << endl;

									break;
								}
								else
								{
									cout << "The amount of fuel we have: " << gasol[0].getTank() << " liter. So you can get up to " << gasol[0].getTank() * gasol[0].getPrice() << " TL of fuel." << endl;
									cout << "Would you like to buy accordingly (y/n)?: ";
									char choiceCr;
									cin >> choiceCr;
									if (choiceCr == 'y' || choiceCr == 'Y')
									{
										cout << "Are you being redirected to the upper action menu again?" << endl;
									}
									else
									{
										break;
									}

								}
							}

						}
						else if (gasol_ch == 2)
						{
							while (true)
							{
								cout << "How much fuel do you want to buy? :";
								cin >> wantToBuy;
								float calc;
								calc = wantToBuy / gasol[1].getPrice();
								if (calc <= gasol[1].getTank())
								{
									gasol[1].updateTank(-calc);
									admin.updateSafe(wantToBuy);
									total_val += wantToBuy;
									cout << "As a result of your request you made a purchase of " << wantToBuy << " TL from " << gasol[1].getType() << " fuel type." << endl;
									point = wantToBuy * 0.05;
									cout << "And you earned " << point << " points in this way" << endl;

									break;
								}
								else
								{
									cout << "The amount of fuel we have: " << gasol[1].getTank() << " liter. So you can get up to " << gasol[1].getTank() * gasol[1].getPrice() << " TL of fuel." << endl;
									cout << "Would you like to buy accordingly (y/n)?: ";
									char choiceCr;
									cin >> choiceCr;
									if (choiceCr == 'y' || choiceCr == 'Y')
									{
										cout << "Are you being redirected to the upper action menu again?" << endl;
									}
									else
									{
										break;
									}

								}
							}
						}
					}
					else if (fueltype_ch == 2)
					{
						cout << "There are two types of DIESEL fuel in our station." << endl;
						for (int i = 0; i < 2; i++)
						{
							cout << i + 1 << ". Type " << diesel[i].getType() << " Price: " << diesel[i].getPrice() << endl;
						}
						cout << "Your choice: ";
						int diesel_ch;
						cin >> diesel_ch;
						if (diesel_ch == 1)
						{
							while (true)
							{
								cout << "How much fuel do you want to buy? :";
								cin >> wantToBuy;
								float calc;
								calc = wantToBuy / diesel[0].getPrice();
								if (calc <= diesel[0].getTank())
								{
									diesel[0].updateTank(-calc);
									admin.updateSafe(wantToBuy);
									total_val += wantToBuy;
									cout << "As a result of your request you made a purchase of " << wantToBuy << " TL from " << diesel[0].getType() << " fuel type." << endl;
									point = wantToBuy * 0.05;
									cout << "And you earned " << point << " points in this way" << endl;

									break;
								}
								else
								{
									cout << "The amount of fuel we have: " << diesel[0].getTank() << " liter. So you can get up to " << diesel[0].getTank() * diesel[0].getPrice() << " TL of fuel." << endl;
									cout << "Would you like to buy accordingly (y/n)?: ";
									char choiceCr;
									cin >> choiceCr;
									if (choiceCr == 'y' || choiceCr == 'Y')
									{
										cout << "Are you being redirected to the upper action menu again?" << endl;
									}
									else
									{
										break;
									}

								}
							}

						}
						else if (diesel_ch == 2)
						{
							while (true)
							{
								cout << "How much fuel do you want to buy? :";
								cin >> wantToBuy;
								float calc;
								calc = wantToBuy / diesel[1].getPrice();
								if (calc <= diesel[1].getTank())
								{
									diesel[1].updateTank(-calc);
									admin.updateSafe(wantToBuy);
									total_val += wantToBuy;
									cout << "As a result of your request you made a purchase of " << wantToBuy << " TL from " << diesel[1].getType() << " fuel type." << endl;
									point = wantToBuy * 0.05;
									cout << "And you earned " << point << " points in this way" << endl;

									break;
								}
								else
								{
									cout << "The amount of fuel we have: " << diesel[1].getTank() << " liter. So you can get up to " << diesel[1].getTank() * diesel[1].getPrice() << " TL of fuel." << endl;
									cout << "Would you like to buy accordingly (y/n)?: ";
									char choiceCr;
									cin >> choiceCr;
									if (choiceCr == 'y' || choiceCr == 'Y')
									{
										cout << "Are you being redirected to the upper action menu again?" << endl;
									}
									else
									{
										break;
									}

								}
							}
						}
					}
					else if (fueltype_ch == 3)//lpg
					{
						while (true)
						{
							cout << "How much fuel do you want to buy? :";
							cin >> wantToBuy;
							float calc;
							calc = wantToBuy / lpg.getPrice();
							if (calc <= lpg.getTank())
							{
								lpg.updateTank(-calc);
								admin.updateSafe(wantToBuy);
								total_val += wantToBuy;
								cout << "As a result of your request you made a purchase of " << wantToBuy << " TL from LPG fuel type." << endl;
								point = wantToBuy * 0.05;
								cout << "And you earned " << point << " points in this way" << endl;

								break;
							}
							else
							{
								cout << "The amount of fuel we have: " << lpg.getTank() << " liter. So you can get up to " << lpg.getTank() * lpg.getPrice() << " TL of fuel." << endl;
								cout << "Would you like to buy accordingly (y/n)?: ";
								char choiceCr;
								cin >> choiceCr;
								if (choiceCr == 'y' || choiceCr == 'Y')
								{
									cout << "Are you being redirected to the upper action menu again?" << endl;
								}
								else
								{
									break;
								}

							}
						}
					}
					else if (fueltype_ch == 4)//customer fuel exit
					{
						cout << "You are redirected to the upper menu.\n" << endl;
						break;
					}
					else
					{
						cout << "Please try again." << endl;
					}
				}
				else if (ch_customer == 3)
				{
					cout << "Enter your plate information (Ex. 06YY06): ";
					string plate_info;
					cin >> plate_info;
					int check = 0;
					if (customer.size() != 0)
					{
						for (int i = 0; i < customer.size(); i++)
						{
							if (plate_info.compare(customer[i].getlicense_plate()) == 0)
							{
								check = 1;
								cout << "You have " << customer[i].getPoint() << " points" << endl;
							}
						}
						if (check == 0)
						{
							cout << "Unfortunately, you are not yet our customer" << endl;
						}
					}
					else
					{
						cout << "Unfortunately, you are not yet our customer" << endl;
					}
					cout << endl;

				}
				else if (ch_customer == 4)//customer exit menu
				{
					float discount = 0;
					if (check == 1)
					{
						cout << "Would you like to use the " << customer[hold].getPoint() << " points you have accumulated before (1point==1TL) (y/n)?" << endl;
						char point_cr;
						cin >> point_cr;
						if (point_cr == 'y' || point_cr == 'Y')
						{
							discount = customer[hold].getPoint();
							cout << "Your " << customer[hold].getPoint() << " points have been successfully converted to " << discount << " TL." << endl;
							customer[hold].updatePoint(-discount);
							total_val -= discount;

						}
						customer[hold].updateTotal(total_val);
						customer[hold].updatePoint(point);

					}
					else
					{
						customer.push_back(Customer(plate, total_val, point));
					}
					cout << "Your plate: " << plate << ", Your total spend: " << total_val << " TL," << point << " point earned and " << discount << " point spend" << endl;


					cout << "You are redirected to the main menu.\n" << endl;
					break;
				}
				else
				{
					cout << "Please try again." << endl;
				}
			}



		}
		else if (choice == 4)
		{

			cout << "Bye";
			break;
		}
		else
		{
			cout << "Please Try Again!\n" << endl;
		}


	}

	return 0;
}