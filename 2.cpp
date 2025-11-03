/*/#include <iostream>
using namespace std;
class Rectangle
{
public:
	Rectangle(int chang, int kuan)
	{
		this->chang = chang;
		this->kuan = kuan;
	}
public:
	int chang;
	int kuan;
public:
	bool operator>(Rectangle& p)
	{
		if (p.chang * p.kuan > this->chang * this->kuan)
		{
			return false;
		}
		else {
			return true;
		}
	}
public:
	int area()
	{
		return this->chang * this->kuan;
	}
public:
	void display()
	{
		cout << this->chang<<endl;
		cout << this->kuan<<endl;
		cout << area()<<endl;
	}
};
int main()
{
	int chang1, kuan1, chang2, kuan2;
	cin >> chang1 >> kuan1 >> chang2 >> kuan2;
	Rectangle r1(chang1,kuan1);
	Rectangle r2(chang2,kuan2);
	if (r1 > r2)
	{
		cout << r1.chang << endl;
		cout << r1.kuan << endl;
	}
	else
	{
		cout << r2.chang << endl;
		cout << r2.kuan << endl;
	}
	return 0;
}*/