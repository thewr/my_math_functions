#ifndef Math_h
#define Math_h

class Math
{
public:
	Math(int* A_) { N = sizeof(A_[0]); cout << N << endl;/* T = new int[N]; SortA(A_);*/ }
	~Math() {/* delete[] T;*/ }
	//void SortA(int* A_);
	float accumulate(int* A_);
	float average(int* A_);
	double stdev(int* A_);
	double quartile(int* A_, int selection);
	//float mad();
	bool whole_num(const double & val);
private:
	int N;
	float sum = 0;
	//int* T;
};

//void Math::SortA(int* A_)
//{
//	int *T;
//	T = new int[N];
//	for (int i = 0; i < N;i++)
//	{
//		T[i] = A_[i];
//	}
//	//cout << "------------------ sort function evoked --------------------\n";
//	int t;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			if (T[i] < T[j])
//			{
//				t = T[i];     //address of *ai given to tmp
//				T[i] = T[j];	   //address of *ai given to *aj
//				T[j] = t;	   //address of tmp given to *aj
//			}
//		}
//	}
//	//for (int i = 0; i < N;i++)
//	//{
//	//	cout << T[i] << " ";
//	//} cout << endl;
//}


float Math::accumulate(int* A_)
{
	for (int i = 0; i < N; i++)
		sum += A_[i];
	return sum;
}

float Math::average(int* A_)
{
	return sum / N;
}

double Math::stdev(int* A_)
{
	float x_d, x_var_sum = 0;
	float x_bar = average(A_);
	for (int i = 0; i < N;i++)
	{
		x_d = A_[i] - x_bar;
		x_var_sum = x_var_sum + pow(x_d, 2.0);
	}
	return sqrt(x_var_sum / (float)(N - 1));
}

double Math::quartile(int* A_, int selection)
{
	int *T;
	T = new int[N];
	for (int i = 0; i < N;i++)
	{
		T[i] = A_[i];
	}
	//cout << "------------------ sort function evoked --------------------\n";
	int t;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (T[i] < T[j])
			{
				t = T[i];     //address of *ai given to tmp
				T[i] = T[j];	   //address of *ai given to *aj
				T[j] = t;	   //address of tmp given to *aj
			}
		}
	}
	for (int i = 0; i < N;i++)
	{
		cout << T[i] << " ";
	} cout << endl;

	double k = (0.25*selection)*N;
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
