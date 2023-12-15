#include <iostream>
#include <iomanip>
using namespace std;
const int SIZE = 3;

class Pair 
{
protected:
	virtual void plus() {
		return;
	}
	virtual void min() {
		return;
	}
	virtual void div() {
		return;
	}
	virtual void mul() {
		return;
	}
	virtual void equ() {
		return;
	}
	virtual void Enter()
	{
		return;
	}
	virtual void Out(int n)
	{ 
		return;
	}
};

class Money: protected Pair 
{
private:
	long rubles;
	unsigned char* kopeika;

	long RetRubles() 
	{
		return rubles;
	}
	unsigned char* RetKop()
	{
		return kopeika;
	}

public:
	Money() 
	{
		this->rubles = 0;
		this->kopeika = new unsigned char[SIZE];
	}
	virtual void Enter()
	{
		cin >> rubles;
		cin >> kopeika;
	}
	virtual void Out(int n)
	{
		cout << "Money"<<n<<" ("<<rubles<<"."<<kopeika<<" u.e.)";

	}
	virtual void plus(Money plus)
	{
		long s1 = rubles + plus.RetRubles();
		int n1 = 10*(kopeika[0]-'0') + (kopeika[1]-'0');
		double temp1 = rubles + (n1 * pow(10, -2));
		int n2 = 10 * (plus.RetKop()[0]-'0') + (plus.RetKop()[1]-'0');
		double temp2 = plus.RetRubles() + (n2 * pow(10, -2));
		double res = temp1 + temp2;

		cout << fixed << setprecision(2) << "Money1+Money2" << " (" << res << " u.e.)\n";
	}
	virtual void min(Money min)
	{
		long s1 = rubles + min.RetRubles();
		int n1 = 10 * (kopeika[0] - '0') + (kopeika[1] - '0');
		double temp1 = rubles + (n1 * pow(10, -2));
		int n2 = 10 * (min.RetKop()[0] - '0') + (min.RetKop()[1] - '0');
		double temp2 = min.RetRubles() + (n2 * pow(10, -2));
		double res = temp1 - temp2;

		cout << fixed << setprecision(2) << "Money1-Money2" << " (" << res << " u.e.)\n";
	}
	virtual void mul(double num, int n) 
	{
		int kop = 10 * (kopeika[0] - '0') + (kopeika[1] - '0');
		double temp = rubles + (kop*pow(10, -2));
		double res = num*temp;
		cout << fixed << setprecision(2) << "Money" << n << "*chislo" << " (" << res << " u.e.)\n";
	}
	virtual void div(Money num)
	{
		long s1 = rubles + num.RetRubles();
		int n1 = 10 * (kopeika[0] - '0') + (kopeika[1] - '0');
		double temp1 = rubles + (n1 * pow(10, -2));
		int n2 = 10 * (num.RetKop()[0] - '0') + (num.RetKop()[1] - '0');
		double temp2 = num.RetRubles() + (n2 * pow(10, -2));
		double res = temp1 / temp2;
		cout << fixed << setprecision(5) << "Money1/Money2" << " (" << res << ")\n";
	}


};

class Complex:protected Pair
{
private:
	int a;
	int b;
	int RetA() { return a; }
	int RetB() { return b; }
public:
	Complex()
	{
		this->a = 0;
		this->b = 0;
	}
	virtual void Enter()
	{
		cin >> a;
		cin >> b;

	}
	virtual void Out(int n)
	{
		cout << "Complex" << n << " (" << a << "+i*" << b << ")";

	}
	virtual void plus(Complex second)
	{
		cout << "Complex1+Complex2 (" << a+second.RetA() << "+i*" << b+second.RetB() << ")\n";
	}
	virtual void min(Complex second)
	{
		cout << "Complex1-Complex2 (" << a - second.RetA() << "+i*" << b - second.RetB() << ")\n";
	}
	virtual void mul(Complex second)
	{
		int c = second.RetA(), d = second.RetB();
		cout << "Complex1*Complex2 (" << a*c-b*d << "+i*" << a*d+b*c << ")\n";
	}
	virtual void div(Complex second, int n, int m)
	{
		int c = second.RetA(), d = second.RetB(), sq = c*c+d*d;
		cout <<fixed<< setprecision(n) << "Complex1/Complex2 (" << double(a * c + b * d)/sq << "+i*" <<setprecision(m) <<double(b*c-a*d)/sq<< ")\n";

	}


};
void Commands(Money m1, Money m2, Complex c1, Complex c2, double num) 
{
	int n;
	bool fl = true;
	while (fl) 
	{
		cin >> n;
		switch (n)
		{
		case 1:
			m1.Enter();
			m1.Out(1);
			cout << " ";
			m2.Out(2);
			cout << endl;
			m1.plus(m2);
			m1.min(m2);
			m1.mul(num, 1);
			m2.mul(num, 2);
			m1.div(m2);
			break;
		case 2:
			m2.Enter();
			m1.Out(1);
			cout << " ";
			m2.Out(2);
			cout << endl;
			m1.plus(m2);
			m1.min(m2);
			m1.mul(num, 1);
			m2.mul(num, 2);
			m1.div(m2);
			break;
		case 3:
			c1.Enter();
			c1.Out(1);
			cout << " ";
			c2.Out(2);
			cout << endl;
			c1.plus(c2);
			c1.min(c2);
			c1.mul(c2);
			c1.div(c2, 6, 6);
			break;
		case 4:
			c2.Enter();
			c1.Out(1);
			cout << " ";
			c2.Out(2);
			cout << endl;
			c1.plus(c2);
			c1.min(c2);
			c1.mul(c2);
			c1.div(c2, 5, 5);
			break;
		case 5:
			cin >> num;
			m1.Out(1);
			cout << " ";
			m2.Out(2);
			cout << endl;
			m1.plus(m2);
			m1.min(m2);
			m1.mul(num, 1);
			m2.mul(num, 2);
			m1.div(m2);
			break;
		case 0:
			fl = false;
			break;


		}

	}


}








int main(void)
{
	Money mon, val;
	double num;
	mon.Enter();
	val.Enter();
	cin >> num;
	mon.Out(1);
	cout << " ";
	val.Out(2);
	cout << endl;
	mon.plus(val);
	mon.min(val);
	mon.mul(num, 1);
	val.mul(num, 2);
	mon.div(val);

	Complex uno, dos;
	uno.Enter();
	dos.Enter();

	uno.Out(1);
	cout << " ";
	dos.Out(2);
	cout << endl;
	uno.plus(dos);
	uno.min(dos);
	uno.mul(dos);
	uno.div(dos, 6, 7);

	Commands(mon, val, uno, dos, num);
	return 0;
}

