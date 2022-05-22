#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

class Person
{
private:
	string nameAndSurname;
	int age;
	bool gender;
public:
	Person();
	Person(string, int, bool);
	virtual void displayInformation()
	{
		cout << "Name and Surname:" << nameAndSurname
			<< "\nAge: " << age
			<< "\nGender: ";
		if (gender == 1)
		{
			cout << "Male" << endl;
		}
		else if (gender == 0)
		{
			cout << "Female" << endl;
		}
	}


};

Person::Person() :nameAndSurname{ "none" }, age{ 0 }, gender{ 0 }
{

}

Person::Person(string name_val, int age_val, bool gender_val) : nameAndSurname{ name_val }, age{ age_val }, gender{ gender_val }
{

}



class Emplooye : public Person
{
private:
	int workID;
	double salary;
public:
	Emplooye();
	Emplooye(string, int, bool, int, double);

	virtual void displayInformation()
	{
		Person::displayInformation();
		cout << "Your ID: " << workID
			<< "\nYour Salary: " << salary << endl;
	}
	void updateSalary(double salary) { this->salary = salary; }
	int getworkID() { return workID; }
	double getSalary() { return salary; }

};


Emplooye::Emplooye() : Person::Person(), workID{ 0 }, salary{ 0 }
{

}

Emplooye::Emplooye(string name_val, int age_val, bool gender_val, int idVal, double salaryVal) : Person::Person(name_val, age_val, gender_val), workID{ idVal }, salary{ salaryVal }
{

}

class GasStation
{
private:
	float tank;
	float price;
public:
	GasStation();
	GasStation(float, float);
	void updateTank(float tank) { this->tank += tank; }
	void setPrice(float price) { this->price = price; }
	double getTank() { return tank; }
	float getPrice() { return price; }

	virtual void displayInfo()
	{
		cout << " Amount: " << tank << " Liter Price: " << price << " TL" << endl;
	}



};

GasStation::GasStation() :tank{ 0 }, price{ 0.0 }
{

}
GasStation::GasStation(float tank_val, float price_val) : tank{ tank_val }, price{ price_val }
{

}



class Administrator : public Emplooye, public GasStation
{
private:
	string password;
	double safe;
public:
	Administrator();
	void updateSafe(double safeVal) { safe += safeVal; }
	void setPassword(string pass) { password = pass; }
	string getPassword() { return password; }
	double getSafe() { return safe; }


	void depositAndWithdraw();

};
Administrator::Administrator() :Emplooye::Emplooye("Admin", 45, 1, 1000, 10000), password{ "admin" }, safe{ 100000 }
{

}
void Administrator::depositAndWithdraw()
{
	int choice3;
	while (true)
	{
		cout << "1. Deposits money in the safe.\n"
			<< "2. Withdraws money in the safe\n"
			<< "3. Exit" << endl;
		cin >> choice3;
		int money_val;
		if (choice3 == 1)
		{
			cout << "How much money do you want to deposit?: ";
			cin >> money_val;
			safe += money_val;
			cout << endl;
		}
		else if (choice3 == 2)
		{
			cout << "How much money do you want to withdraw?: ";
			cin >> money_val;
			safe -= money_val;
			cout << endl;
		}
		else if (choice3 == 3)
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



class FuelSupplier :public Emplooye
{
public:
	FuelSupplier();
	FuelSupplier(string, int, bool, int, double);



};

FuelSupplier::FuelSupplier() :Emplooye::Emplooye("Worker", 30, 1, 2000, 4253)
{

}

FuelSupplier::FuelSupplier(string name_val, int age_val, bool gender_val, int idVal, double salaryVal) : Emplooye::Emplooye(name_val, age_val, gender_val, idVal, salaryVal)
{

}






class Gasoline : public GasStation
{
private:
	string type;
public:
	Gasoline();
	Gasoline(float, float);
	virtual void displayInfo()
	{
		cout << "Type: " << type;
		GasStation::displayInfo();
	}
	void setType(string type1) { type = type1; }
	string getType() { return type; }
};

Gasoline::Gasoline() : GasStation(), type{ "none gasoline" }
{

}
Gasoline::Gasoline(float tank_val, float price_val) : GasStation(tank_val, price_val)
{

}



class Diesel : public GasStation
{
private:
	string type;
public:
	Diesel();
	Diesel(float, float, string);
	void setType(string type1) { type = type1; }
	virtual void displayInfo()
	{
		cout << "Type: " << type;
		GasStation::displayInfo();
	}
	string getType() { return type; }
};

Diesel::Diesel() :GasStation(), type{ "none diesel" }
{

}
Diesel::Diesel(float tank_val, float price_val, string type_val) : GasStation(tank_val, price_val), type{ type_val }
{

}

class LPG : public GasStation
{
public:
	LPG();
	LPG(float, float);
};
LPG::LPG() :GasStation()
{

}
LPG::LPG(float tank_val, float price_val) : GasStation(tank_val, price_val)
{

}



class Customer : public GasStation {
private:
	string license_plate;
	float  total;
	float point;
public:
	Customer();
	Customer(string, float, float);
	void updateTotal(float total1) { total += total1; }
	void updatePoint(float point1) { point += point1; }
	string getlicense_plate() { return license_plate; }
	float getPoint() { return point; }


};
Customer::Customer() :license_plate{ "none" }, total{ 0 }, point{ 0 }{

}
Customer::Customer(string license_plate_value, float total_value, float point_value) : license_plate{ license_plate_value }, total{ total_value }, point{ point_value }{

}

//adil

class Marketplace
{
protected:
	string product_name;
	float price, tax_value;
	int quantity, discount;
public:
	Marketplace()
	{
		product_name = " ";
		price = 0;
		quantity = 0;
		tax_value = 0;
		discount = 0;
	}
	Marketplace(string product_name, float price, int quantity, float tax_value, int discount)
	{
		this->product_name = product_name;
		this->price = price;
		this->quantity = quantity;
		this->tax_value = tax_value;
		this->discount = discount;
	}
	~Marketplace()
	{
	}
	void setName(string val_name)
	{
		product_name = val_name;
	}
	string getName()
	{
		return product_name;
	}
	void setPrice(float val_price)
	{
		price = val_price;
	}
	float getPrice()
	{
		return price;
	}
	void setQuantity(int val_quantity)
	{
		quantity = val_quantity;
	}
	int getQuantity()
	{
		return quantity;
	}
	void setTax(float val_tax)
	{
		tax_value = val_tax;
	}
	float getTax()
	{
		return tax_value;
	}
	void setDiscount(int val_discount)
	{
		discount = val_discount;
	}
	int getDiscount()
	{
		return discount;
	}
};

class Snacks : public Marketplace
{
public:
	Snacks() : Marketplace(product_name, price, quantity, tax_value, discount)
	{
		product_name = " ";
		price = 0;
		quantity = 0;
		tax_value = 0.0;
		discount = 0;
	}
	Snacks(string product_name, float price, int quantity, float tax_value, int discount)
	{
		this->product_name = product_name;
		this->price = price;
		this->quantity = quantity;
		this->tax_value = tax_value;
		this->discount = discount;
	}
	~Snacks()
	{
	}
	void displaySnack(void)
	{
		cout << "Product Name: " << product_name << endl;
		cout << "Price: " << price << endl;
		cout << "Quantity:  " << quantity << endl;
		cout << "Tax Value: " << tax_value << endl;
		cout << "Discount Rate: " << discount << endl;
	}
	float orderSnack(void)
	{
		int order_amount;
		int order_discount;
		int display;
		float order_price = 0;
		cout << "Every snack is priced as 3$.\n\n" << endl;
		cout << "How many products do you want to order? (If you order more than 350, you get %20 discount.You can't order more than 1000 per order.) ";
		cin >> order_amount;
		while (order_amount > 1000)
		{
			cout << "You ordered more than the order limit. Please change the order amount. ";
			cout << "New order amount: ";
			cin >> order_amount;
		}
		if (order_amount > 350)
		{
			order_discount = ((3 * order_amount) / 100) * 20;
			order_price = (3 * order_amount) - order_discount;
		}
		else
			order_price = 3 * order_amount;
		setQuantity(order_amount + quantity);
		display = getQuantity();
		cout << "You will pay " << order_price << " dollars." << endl;
		cout << "New quantity of the product that you order: " << display << endl;
		return order_price;
	}
};

class Food : public Marketplace
{
protected:
	int prepare_time1, prepare_time2;
public:
	Food() : Marketplace(product_name, price, quantity, tax_value, discount)
	{
		product_name = " ";
		price = 0;
		quantity = 0;
		tax_value = 0;
		discount = 0;
		prepare_time1 = 0;
		prepare_time2 = 0;
	}
	Food(string product_name, float price, int quantity, float tax_value, int discount, int prepare_time1, int prepare_time2)
	{
		this->product_name = product_name;
		this->price = price;
		this->quantity = quantity;
		this->tax_value = tax_value;
		this->discount = discount;
		this->prepare_time1 = prepare_time1;
		this->prepare_time2 = prepare_time2;
	}
	~Food()
	{
	}
	void set_Preptime1(int prep1)
	{
		prepare_time1 = prep1;
	}
	int get_Preptime1()
	{
		return prepare_time1;
	}
	void set_Preptime2(int prep2)
	{
		prepare_time2 = prep2;
	}
	int get_Preptime2()
	{
		return prepare_time1;
	}
	void displayFood()
	{
		cout << "Product Name: " << product_name << endl;
		cout << "Price: " << price << endl;
		cout << "Quantity:  " << quantity << endl;
		cout << "Tax Value: " << tax_value << endl;
		cout << "Discount Rate: " << discount << endl;
		cout << "Ready Time: " << prepare_time1 << " - " << prepare_time1 << "minutes." << endl;
	}
	float orderFood(void)
	{
		int order_amount;
		int order_discount;
		int display;
		float order_price = 0;
		cout << "Every Food is priced as 8$.\n\n" << endl;
		cout << "How many products do you want to order? (If you order more than 200, you get %15 discount.You can't order more than 1000 products per order.) ";
		cin >> order_amount;
		while (order_amount > 1000)
		{
			cout << "You ordered more than the order limit. Please change the order amount." << endl;
			cout << "New order amount: ";
			cin >> order_amount;
		}
		if (order_amount > 200)
		{
			order_discount = ((8 * order_amount) / 100) * 15;
			order_price = (8 * order_amount) - order_discount;
		}
		else
			order_price = 8 * order_amount;
		setQuantity(order_amount + quantity);
		display = getQuantity();
		cout << "You will pay " << order_price << " dollars." << endl;
		cout << "New quantity of the product that you order: " << display << endl;
		return order_price;
	}
};

class Drinks : public Marketplace
{
protected:
	int liter;
public:
	Drinks() : Marketplace(product_name, price, quantity, tax_value, discount)
	{
		product_name = " ";
		price = 0;
		quantity = 0;
		tax_value = 0;
		discount = 0;
		liter = 0;
	}
	Drinks(string product_name, float price, int quantity, float tax_value, int discount, int liter)
	{
		this->product_name = product_name;
		this->price = price;
		this->quantity = quantity;
		this->tax_value = tax_value;
		this->discount = discount;
		this->liter = liter;
	}
	void setDrink_liter(int drink_liter)
	{
		liter = drink_liter;
	}
	int getDrink_liter()
	{
		return liter;
	}
	void displayDrink()
	{
		cout << "Product Name: " << product_name << endl;
		cout << "Price: " << price << endl;
		cout << "Quantity:  " << quantity << endl;
		cout << "Tax Value: " << tax_value << endl;
		cout << "Discount Rate: " << discount << endl;
		cout << "Liter: " << liter << endl;
	}
	float orderDrink()
	{
		int order_amount;
		int order_discount;
		int display;
		float order_price = 0;
		cout << "Every Drink is priced as 2$.\n\n" << endl;
		cout << "How many products do you want to order? (If you order more than 700, you get %40 discount.You can't order more than 1000 products per order.) ";
		cin >> order_amount;
		while (order_amount > 1000)
		{
			cout << "You ordered more than the order limit. Please change the order amount." << endl;
			cout << "New order amount: ";
			cin >> order_amount;
		}
		if (order_amount > 700)
		{
			order_discount = ((2 * order_amount) / 100) * 40;
			order_price = (2 * order_amount) - order_discount;
		}
		else
			order_price = 2 * order_amount;
		setQuantity(order_amount + quantity);
		display = getQuantity();
		cout << "You will pay " << order_price << " dollars." << endl;
		cout << "New quantity of the product that you order: " << display << endl;
		return order_price;
	}
};

class Cigarettes : public Marketplace
{
public:
	Cigarettes() : Marketplace(product_name, price, quantity, tax_value, discount)
	{
		product_name = " ";
		price = 0;
		quantity = 0;
		tax_value = 0;
		discount = 0;
	}
	Cigarettes(string product_name, float price, int quantity, float tax_value, int discount)
	{
		this->product_name = product_name;
		this->price = price;
		this->quantity = quantity;
		this->tax_value = tax_value;
		this->discount = discount;
	}
	void displayCigarette()
	{
		cout << "Product Name: " << product_name << endl;
		cout << "Price: " << price << endl;
		cout << "Quantity:  " << quantity << endl;
		cout << "Tax Value: " << tax_value << endl;
		cout << "Discount Rate: " << discount << endl;
	}
	float orderCigarette(void)
	{
		int order_amount;
		int order_discount;
		int display;
		float order_price = 0;
		cout << "Every Cigarette is priced as 10$.\n\n" << endl;
		cout << "How many products do you want to order? (If you order more than 650, you get %5 discount.You can't order more than 1000 products per order.) ";
		cin >> order_amount;
		while (order_amount > 1000)
		{
			cout << "You ordered more than the order limit. Please change the order amount." << endl;
			cout << "New order amount: ";
			cin >> order_amount;
		}
		if (order_amount > 650)
		{
			order_discount = ((10 * order_amount) / 100) * 5;
			order_price = (10 * order_amount) - order_discount;
		}
		else
			order_price = 10 * order_amount;
		setQuantity(order_amount + quantity);
		display = getQuantity();
		cout << "You will pay " << order_price << " dollars." << endl;
		cout << "New quantity of the product that you order: " << display << endl;
		return order_price;
	}
};

class Other : public Marketplace
{
public:
	Other() : Marketplace(product_name, price, quantity, tax_value, discount)
	{
		product_name = " ";
		price = 0;
		quantity = 0;
		tax_value = 0;
		discount = 0;
	}
	Other(string product_name, float price, int quantity, float tax_value, int discount)
	{
		this->product_name = product_name;
		this->price = price;
		this->quantity = quantity;
		this->tax_value = tax_value;
		this->discount = discount;
	}
	void displayOther()
	{
		cout << "Product Name: " << product_name << endl;
		cout << "Price: " << price << endl;
		cout << "Quantity:  " << quantity << endl;
		cout << "Tax Value: " << tax_value << endl;
		cout << "Discount Rate: " << discount << endl;
	}
	float orderOther(void)
	{
		int order_amount;
		int order_discount;
		int display;
		float order_price = 0;
		cout << "Every Other product is priced as 5$.\n\n" << endl;
		cout << "How many products do you want to order? (If you order more than 500, you get %35 discount.You can't order more than 1000 products per order.) ";
		cin >> order_amount;
		while (order_amount > 1000)
		{
			cout << "You ordered more than the order limit. Please change the order amount." << endl;
			cout << "New order amount: ";
			cin >> order_amount;
		}
		if (order_amount > 200)
		{
			order_discount = ((5 * order_amount) / 100) * 35;
			order_price = (5 * order_amount) - order_discount;
		}
		else
			order_price = 5 * order_amount;
		setQuantity(order_amount + quantity);
		display = getQuantity();
		cout << "You will pay " << order_price << " dollars." << endl;
		cout << "New quantity of the product that you order: " << display << endl;
		return order_price;
	}
};