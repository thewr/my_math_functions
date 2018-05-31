#ifndef Math_h
#define Math_h

template<class T, size_t N>
constexpr size_t size(T(&)[N]) { return N; }

class Math
{
public:
	//Math(A);  load arrayA_COV here
	//void jacobi..
	Math() { CAPACITY = 30; T = new int[CAPACITY]; }
	~Math() {delete[] T;}
	void SortA(int *A_,int N);
	float accumulate(int A_[]);
	float average(int* A_);
	double stdev(int* A_);
	double quartile(int* A_, int selection);
	int length(int* A_);
	int sgn(double val) const;
	float distance(float x1, float y1, float x2, float y2);
	//float mad();
	bool whole_num(const double & val);
private:
	float sum = 0;
	int CAPACITY;
	int *T;
};

int Math::sgn(double val) const
{
	if (val > 0)
		return 1;
	else if (val < 0)
		return -1;
	else
		return 0;
}

inline float Math::distance(float x1, float y1, float x2, float y2)
{
	float result; //local variable
	result = pow(x2 - x1, 2.0);
	result += pow(y2 - y1, 2.0);
	return sqrt(result);
}

double distance(float x1, float y1, float x2, float y2)
{
	double result; //local variable
	result = pow(x2 - x1, 2.0);
	result += pow(y2 - y1, 2.0);
	return sqrt(result);
}

void Math::SortA(int *A_,int N)
{
	CAPACITY = N;
	cout << "CAPACITY " << CAPACITY << endl;
	delete[] T; 
	T = new int[CAPACITY];
	for (int i = 0; i < CAPACITY;i++)
	{
		T[i] = A_[i];
	}
	//cout << "------------------ sort function evoked --------------------\n";
	int t;
	for (int i = 0; i < CAPACITY; i++)
	{
		for (int j = 0; j < CAPACITY; j++)
		{
			if (T[i] < T[j])
			{
				t = T[i];     //address of *ai given to tmp
				T[i] = T[j];	   //address of *ai given to *aj
				T[j] = t;	   //address of tmp given to *aj
			}
		}
	}
	//for (int i = 0; i < CAPACITY;i++)
	//{
	//	cout << T[i] << " ";
	//} cout << endl;
}

int Math::length(int* A_)
{
	int N = 0;
	while (A_[N] > 0)
	{
		N++;
	}
	return N;
}

float Math::accumulate(int A_[])
{
	for (int i = 0; i < length(A_); i++)
		sum += A_[i];
	return sum;
}

float Math::average(int* A_)
{
	return sum / length(A_);
}

double Math::stdev(int* A_)
{
	double x_d, x_var_sum = 0;
	double x_bar = average(A_);
	for (int i = 0; i < length(A_);i++)
	{
		x_d = A_[i] - x_bar;
		x_var_sum = x_var_sum + pow(x_d, 2.0);
	}
	return sqrt(x_var_sum / (float)(length(A_) - 1));
}

double Math::quartile(int* A_, int selection)
{
	int N = sizeof(A_[0]);
	//int *T = new int[N];
	//for (int i = 0; i < N;i++)
	//{
	//	T[i] = A_[i];
	//}
	//////cout << endl;
	//////cout << "------------------ sort function evoked --------------------\n";
	//int t;
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		if (T[i] < T[j])
	//		{
	//			t = T[i];     //address of *ai given to tmp
	//			T[i] = T[j];	   //address of *ai given to *aj
	//			T[j] = t;	   //address of tmp given to *aj
	//		}
	//	}
	//}


	double k = (0.25*selection)*CAPACITY;
	cout << selection << " k = " << k << " " << CAPACITY << endl;

	if (selection == 1)
	{
		double Q1;
		if (whole_num(k))
			Q1 = (A_[static_cast<int>(ceil(k))] + A_[static_cast<int>(ceil(k)) - 1]) / 2.0;
		else
			Q1 = A_[static_cast<int>(k)];

		return Q1;
	}
	else if (selection == 2)
	{
		double Q2;
		if (whole_num(k))
			Q2 = (A_[static_cast<int>(ceil(k))] + A_[static_cast<int>(ceil(k)) - 1]) / 2.0;
		else
			Q2 = A_[static_cast<int>(k)];

		return Q2;
	}
	else if (selection == 3)
	{
		double Q3;
		if (whole_num(k))
			Q3 = (A_[static_cast<int>(ceil(k))] + A_[static_cast<int>(ceil(k)) - 1]) / 2.0;
		else
			Q3 = A_[static_cast<int>(k)];

		return Q3;
	}

	else
	{
		cerr << "quartile not selected";
		return -1;
	}

}

bool Math::whole_num(const double & val)
{
	if (floor(val) == val)
		return true;
	else
		return false;
}

#endif
