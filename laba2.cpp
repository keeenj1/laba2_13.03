#include <iostream>
#include <fstream>
using namespace std;

class Vector {
	int n;
	double* p;
public:
	Vector(double* p, int n)
	{
		this->n = n;
		this->p = new double[n];
		for (int i = 0;i < n;++i) this->p[i] = p[i];
	}
	Vector(int n) : n(n) {
		cout << "test 1" << endl;
		p = new double[n];
	}
	Vector(const Vector& other)
	{
		this->n = other.n;
		this->p = new double[other.n];
		for (int i = 0;i < other.n;++i) this->p[i] = other.p[i];
	}
	Vector (Vector&& prev)
	{
		cout << "test" << endl;
		//this->n = prev.n; prev.n = 0;
		//this->p = prev.p; prev.p = nullptr;
		swap(p, prev.p);
		swap(n, prev.n);
	}
	void print() const
	{
		for (int i = 0; i < n; i++) {
			cout << p[i] << " ";
		}
		cout << endl;
	}
	double& operator[](int index)
	{
		return p[index];
	}
	Vector& operator = (const Vector& other)
	{
		this->n = other.n;
		this->p = new double[other.n];
		for (int i = 0;i < other.n;++i) this->p[i] = other.p[i];
	}
	friend Vector operator *(double x, Vector& v2);
	friend Vector operator +(const Vector& v1, const Vector& v2);
	~Vector()
	{
		if (this->p != nullptr) delete[] p;
	}
	friend ostream& operator<<(ostream& os, const Vector& v) { // Перегруженный оператор вывода в поток
		for (int i = 0; i < v.n; i++) // Вывод значений через поток вывода
			os << v.p[i] << " ";
		return os;
	}

	friend istream& operator>>(istream& is, Vector& v) { // Перегруженный оператор ввода из потока
		for (int i = 0; i < v.n; i++) // Считывание значений из потока ввода
			is >> v.p[i];
		return is;
	}
};
Vector operator *(double x, Vector& v)
{
	Vector Vproiz(v.n);
	for (int i = 0; i < v.n;++i) Vproiz[i] = v.p[i] * x;
	return Vproiz;
}
Vector operator +(const Vector& v1, const Vector& v2)
{
	if (v1.n == v2.n) {
		Vector Vsum(v1.n);
		for (int i = 0; i < v1.n;++i) Vsum.p[i] = v1.p[i] + v2.p[i];
		return Vsum;
	}
	else {
		cout << "Diff size of mas";
	}
}

Vector func() {
	Vector vec(5);
	return vec;
}

int main() {
	setlocale(LC_ALL, "RU");

	ifstream inputFile("input.txt");
	int size; double ch = 3;
	inputFile >> size;
	double* mas = new double[size];
	for (int i = 0; i < size; ++i) {
		inputFile >> mas[i];
	}
	Vector V1(mas, size);
	cout << "Vector 1: " << V1 << endl;
	Vector V2 = ch * V1;
	cout << "Vector 2: " << V2 << endl;
	Vector V3 = V1 + V2;
	cout << "Vector 3: " << V3;



	return 0;
}