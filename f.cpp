#include <iostream>

using namespace std;

class Iterator;

class rgr {

	double* coef;
	size_t size;

public:

	rgr(size_t s = 1)
	{
		coef = new double[s];
		size = s;
		for (int i = 0; i < s; i++)
			coef[i] = 0;
	}

	rgr(const rgr& other)
	{
		size = other.size;
		coef = new double[size];
		for (int i = 0; i < size; i++)
			coef[i] = other.coef[i];
	}

	rgr(const rgr* other) //нужно для создания const rgr*
	{
		size = other->size;
		coef = new double[size];
		for (int i = 0; i < size; i++)
			coef[i] = other->coef[i];
	}

	~rgr()
	{
		delete[] coef;
	}

	friend ostream& operator<<(ostream& st, rgr& el);

	friend istream& operator>>(istream& st, rgr& el);

	Iterator begin();

	Iterator end();

	void clear()
	{
		size = 1;
		delete[] coef;
		coef = new double[1];
		coef[0] = 0;
	}

	rgr& operator=(const rgr& other)
	{
		if (&other == this) return *this;

		delete[] coef;
		size = other.size;
		coef = new double[size + (size == 0 ? 1 : 0)];
		for (int i = 0; i < size; i++)
			coef[i] = other.coef[i];

		return (*this);
	}

	double& operator[](int i) const
	{
		if (i<0 || i>=size)throw 1;

		return coef[i];
	}

	double& operator[](int i)
	{
		if (i<0 || i>=size)throw 1;

		return coef[i];
	}

	rgr operator+(const rgr& other) const
	{
		size_t s = (size > other.size ? size : other.size);
		const rgr* max = (size > other.size ? this : &other);
		size_t ms = (size < other.size ? size : other.size);
		rgr res (max);
		if (max != this)
		{
			for (size_t i = 0; i < size; i++)
				res[i] += coef[i];
		}
		else
		{
			for (size_t i = 0; i < other.size; i++)
				res[i] += other[i];
		}
	// убираем превосходящие нули(с наиб. степени), перевыделяем память по новому размеру
		int k = 0;
		for (int i = res.size - 1; res[i] == 0 &&i>0; i--)
			k++;
		if (k == res.size)
		{
			res.size = 1;
			delete[] res.coef;
			res.coef = new double;
			res[0] = 0;
			return res;
		}

		double* sv = new double[res.size - k];
		for (int i = 0; i < res.size - k; i++)
			sv[i] = res[i];
		delete[] res.coef;
		res.size = res.size - k;
		res.coef = sv;

		return res;
	}

	rgr operator-(const rgr& other) const
	{
		size_t m = (size > other.size ? size : other.size);
		const rgr* min = (size < other.size ? this : &other);
		rgr res(m);
		for (int i = 0; i < (min->size); i++)
			res[i] = coef[i] - other[i];

		if (size > other.size)
			for (int i = other.size; i < size; i++)
				res[i] = coef[i];

		if (other.size > size)
			for (int i = size; i < other.size; i++)
				res[i] = (-1) * other[i];

		// убераем идущие спереди(с наиб степени) нули.
		int k = 0;
		for (int i = res.size -1; res[i] == 0 && i>0; i--)
			k++;
		if (k == res.size)
		{
			res.size = 1;
			delete[] res.coef;
			res.coef = new double;
			res[0] = 0;
			return res;
		}

		double* sv = new double[res.size - k];
		for (int i = 0; i < res.size - k; i++)
			sv[i] = res[i];
		delete[] res.coef;

		res.size = res.size - k;
		res.coef = sv;
		
		return res;
	}

	rgr operator*(const rgr& other) const
	{
		rgr res(size + other.size - 1);
		for (int i = 0; i < res.size; i++)
			res[i] = 0;

		for (int i = 0; i < size; i++)
			for (int j = 0; j < other.size; j++)
				res[i + j] += (coef[i] * other[j]);

		// убираем предидущие нули нули
		int k = 0;
		for (int i = res.size - 1; res[i] == 0 && i > 0; i--)
			k++;
		
		double* sv = new double[res.size - k];
		for (int i = 0; i < res.size - k; i++)
			sv[i] = res[i];
		delete[] res.coef;
		res.size = res.size - k;
		res.coef = sv;

		return res;
	}

	rgr operator/(const rgr& other)
	{
		if (other.size == 1 && other[0] == 0)throw 2;

		rgr res;
		if (other.size > size)
		{
			res.size = 1;
			res.coef = new double[1];
			res[0] = 0;
		}
		size_t s = this->size;
		int so = other.size;

		double* q = new double[s - so + 1];
		double* remain = new double[s];

		for (int i = 0; i < s - so + 1; i++)
			q[i] = 0;

		for (int i = 0; i < s; i++) 
			remain[i] = coef[i];

		for (int i = s - 1; i >= so - 1; i--)
		{
				q[i + 1 - so] = (remain[i] / other.coef[so - 1]);

				for (int j = 0; j < so; j++)
				{
					remain[i - j] -= q[i + 1 - so] * other[so - 1 - j];
				}
			
		}
		delete[] res.coef;
		res.size = s + 1 - so;
		res.coef = new double[res.size];

		for (int i = 0; i < res.size; i++)
			res[i] = q[i];

		// убираем пред идущие нули
		long long int m = -1;
		for (int i = 0; i < res.size; i++)
			if (q[i] != 0) m = i;
		if (m == -1) 
		{
			delete[] res.coef;
			res.coef = new double[1];
			res[0] = 0;
			return res;
		}
		delete[] res.coef;
		res.coef = new double[m + 1];
		res.size = m + 1;
		for (int i = 0; i <= m; i++)
			res[i] = q[i];

		return res;
	}

	rgr operator%(const rgr& other)
	{
		if (other.size == 1 && other[0] == 0)throw 2;
		
		if (other.size > size)
		{
			
			return (*this);
		}
		rgr a;
		a = (this->operator/(other));
		rgr b;
		b= (a * other);
		rgr c;
		c = (this->operator-(b));
		return c;
	}

	rgr operator*(double k) const
	{
		if (k == 0)
		{
			rgr res;
			return res;
		}

		rgr res(size);
		for (int i = 0; i < size; i++)
			res[i] = coef[i] * k;

		return res;
	}

	rgr operator/(double k) const
	{
		rgr res(size);
		for (int i = 0; i < size; i++)
			res[i] = coef[i] / k;

		return res;
	}

	rgr derivative() const
	{
		rgr res(size - 1);

		for (int i = size; i >0; i--)
			res[i-1] = coef[i] * i; 
			//коэф при x^n * n к элементу со степенью n-1

		return res;
	}

	double count(double x)
	{
		double res = coef[size-1];
		for (int i = size - 2; i >= 0; i--)
			res = res * x + coef[i];

		return res;
	}

	size_t degree() { return size - 1; }

	bool operator==(rgr& other)
	{
		if (size != other.size) return false;
		for (int i = 0; i < size; i++)
			if (coef[i] != other[i])return false;
		return true;
	}

	bool operator!=(rgr& other)
	{
		if (size != other.size)return true;
		for (int i = 0; i < size; i++)
			if (coef[i] != other[i])return true;
		return false;
	}
};

ostream& operator<<(ostream& st,rgr& el)
{
	st << "[";
	st.setf(std::ios::showpos);
	for (int i = 0; i < el.size; i++)
	{
		st << el[i];
		for (int j = 0; j < i; j++)
			st << "x";
	}
	st.unsetf(std::ios::showpos);
	st << "]";
	return st;
}

istream& operator>>(istream& st, rgr& el) //[+17+32xxxxxxxx-15xxxxxxxxxxxxxxxxx]
{
	double val; char ch; int cnt = 0;	 el.clear();
	bool f = 0;
	
		st >> ch; if (ch != '[') throw 1;					//+14xx... no [

		double* u = new double[1];
		u[0] = 0;
		int sz = 1; // выделеная память
		int n = 0;	// степень x
		while (st.peek()!=EOF && st.peek() != ']')
		{
			st >> ch; if (ch != '+' && ch != '-') throw 1;		//[15...

			if (st.peek() == 'x') if (ch == '+') { f = 1; val = 1; } else { f = 1; val = -1; }		

			if (!f)
			{
				int k;
				if (ch == '+')k = 1; else k = -1;
				st >> val;
				val = val * k;
				if (!st.good()) throw 1;
			}
			
			f = 0;
			n = 0;
			// считаем степень у коэфициента
			while (st.peek() == 'x')
			{
				n++;
				st.ignore();

			}
			if (st.peek() != 'x' && st.peek() != '+' && st.peek() != '-'&&st.peek()!=']') // [...+17xxxxxk...
				throw 1;
			// если не хватает места для степени - довыделяем память
			while (sz <= n)
			{
				double* sv = new double[n+1];
				for (int i = 0; i < n+1; i++) sv[i] = 0;

				for (int i = 0; i < sz; i++)
					sv[i] = u[i];

				sz = n + 1;
				delete[] u;

				u = sv;

			}
			
			u[n] = val;
			

		}
		if (st.peek() != ']')throw 1;
		else st.ignore();
		int m = -1;
		//ищим максимальный ненулевой коэфициент
		for (int i = 0; i < sz; i++)
			if (u[i] != 0) m = i;
		if (m == -1) {
			el.coef = new double[1];
			el[0] = 0;
			return st;
		}
		el.coef = new double[m + 1];
		el.size = m + 1;
		for (int i = 0; i <= m; i++)
			el[i] = u[i];

	
	
	return st;
}

class Iterator
{
protected:
	double* ptr;
	size_t index;
	size_t Size;
public:

	friend class rgr;

	double& operator*() const
	{
		return *ptr;
	}

	Iterator& operator++() 
	{
		if (index < Size - 1) { index++; ptr++; return *this; }
		index++;
		ptr = nullptr;
		return *this;
	}

	Iterator operator++(int)
	{
		Iterator s = (*this);
		if (index < Size - 1) { index++; ptr++; return *this; }
		index++;
		ptr = nullptr;
		return s;
	}

	bool operator==(Iterator& I)
	{
		return (ptr == I.ptr && index == I.index);
	}
};

Iterator rgr::begin()
{
	Iterator I;
	I.Size = size;
	I.index = 0;
	I.ptr = coef;
	return I;
}

Iterator rgr::end()
{
	Iterator I;
	I.Size = size;
	I.index = size;
	I.ptr = nullptr;
	return I;
}



int main()
{
	rgr a;

	try 
	{
		cin >> a;
	
	}
	catch (...)
	{
		cout << "wrong input\n";
	}
	cout << a << endl;
	double x = a.count(5);
	cout << "x = " << x;
	
}