////#include <fstream>
////#include <iostream>
////#include <string>
////#include <sstream>
////#include <vector>
////#include <iomanip>
////
////
////
////#ifndef EIG_VEC_JKMTX_h
////#define EIG_VEC_JKMTX_h
////
////class JKMTX
////{
////public:
////	JKMTX(double **A);
////	~JKMTX();
////private:
////
////};
////
////
////
////
////#endif
////
////
//double Sin2, Cos2, Cos_, Sin_, Tan2, Cot2, tmp;
//double den = 0.0, num = 0.0;
//double sumsqr, prev_sumsqr = 0.0;
//const double eps = 1E-16;
//
//for (int count = 1; count <= 15; count++) {
//	for (int j = 0; j < N - 1; j++) {
//		for (int k = j + 1; k < N; k++) {
//			num = 0.0;
//			den = 0.0;
//			for (int i = 0; i < N; i++) {
//				num += 2 * cov_matrix[i][j] * cov_matrix[i][k];
//				den += (cov_matrix[i][j] + cov_matrix[i][k]) * (cov_matrix[i][j] - cov_matrix[i][k]);
//			}
//			if (abs(num) < eps && den >= 0) {
//				break; //exit for loop
//			}
//			// find sin(2*theta) and cos(2*theta)
//			if (abs(num) <= abs(den)) {    // 2*sigma(xy) <= |sqrt(x2-y2)|
//				Tan2 = abs(num) / abs(den);
//				Cos2 = 1 / sqrt(1 + Tan2 * Tan2);
//				Sin2 = Tan2 * Cos2;
//			}
//			else {
//				Cot2 = abs(den) / abs(num);
//				Sin2 = 1 / sqrt(1 + Cot2 * Cot2);
//				Cos2 = Cot2 * Sin2;
//			}
//			// condition +/- for cos(theta) and sin(theta)
//			Cos_ = sqrt((1 + Cos2) / 2);
//			Sin_ = Sin2 / (2 * Cos_);
//			if (den < 0) {
//				tmp = Cos_;
//				Cos_ = Sin_;
//				Sin_ = tmp;
//			}
//			Sin_ = m.sgn(num) * Sin_;
//			// perform rotation on matrix
//			for (int i = 0; i < N; i++) {
//				tmp = cov_matrix[i][j];
//				cov_matrix[i][j] = tmp * Cos_ + cov_matrix[i][k] * Sin_;
//				cov_matrix[i][k] = -tmp * Sin_ + cov_matrix[i][k] * Cos_;
//			}
//		}// NEXT k
//	}// NEXT j
//
//	sumsqr = 0;
//	for (int c = 0; c < N; c++) {
//		sumsqr += cov_matrix[0][c] * cov_matrix[c][0];
//	}
//	// display some results from the iteration.
//	//if (count > 5) {
//	//	cout << "\t\t" << "---------------- " << "count:" << count << " ---------------" << endl;
//	//	cout << "\t\t" << "prev_sumsqr = " << prev_sumsqr << ";\n\t\t" << "sumsqr = " << sumsqr << ";\n";
//	//	cout << "\t\t" << "Error:" << abs(sumsqr - prev_sumsqr) << endl;
//	//}
//	// if error is small break loop else continue
//	if (abs(sumsqr - prev_sumsqr) < eps) {
//		break;
//	}
//	else { prev_sumsqr = sumsqr; }
//}// NEXT count
//
//record_t eval(N);
////now we have an empty 2D-matrix of size (0,0). Resizing it with one single command:
//evec.resize(N, record_t(2, 0.0));
//// and we are good to go .
//// find eigen values
//int j, k;
//for (j = 0; j < N; j++)
//{
//	for (k = 0; k < N; k++)
//	{
//		eval[j] += (cov_matrix[k][j])*(cov_matrix[k][j]);
//
//	}
//	eval[j] = sqrt(eval[j]);
//}
//// find eigen vectors
//int i;
//for (i = 0; i < 2; i++) //column
//{
//	for (j = 0; j < N; j++) //row
//	{
//		evec[j][i] = cov_matrix[j][i] / eval[i];
//	}
//}
//
//ofstream out;
//out.open("eig_vectors.txt");
//string Name[4] = { "A","B","C","D" };
//for (i = 0;i < 2;i++) {
//	out << "Cells(k, feature" << Name[i] << ").Value = ";
//	for (j = 0; j < N; j++)
//	{
//		if (j < (N - 1)) {
//			out << evec[j][i] << "*" << Name[j] << " +";
//		}
//		else
//		{
//			out << evec[j][i] << "*" << Name[j];
//		}
//	}  out << endl;
//}out.close();