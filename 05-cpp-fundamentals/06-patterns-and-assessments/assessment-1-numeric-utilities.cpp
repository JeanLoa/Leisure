#include <iostream>

using namespace std;

float mayornum(float a, float b, float c) {
	float max;
	(a >= b && a >= c) ? max = a : 0;
	(b >= a && b >= c) ? max = b : 0;
	(c >= a && c >= b) ? max = c : 0;
	return max;
}

char mayorletra(char a, char b, char c) {
	char max;
	(a >= b && a >= c) ? max = a : 0;
	(b >= a && b >= c) ? max = b : 0;
	(c >= a && c >= b) ? max = c : 0;
	return max;
}

int main() {
	char A = 'A', B = 'B', C = 'C';
	float num1, num2, num3, num4, num5, num6, num7, num8, num9, num10;
	char char1, char2, char3, char4, char5, char6, char7, char8, char9, char10;
	
	num1 = mayornum(4.2, 4.2, 4.2);
	num2 = mayornum(4.2, 4.2, 2.4);
	num3 = mayornum(4.2, 2.4, 4.2);
	num4 = mayornum(2.4, 4.2, 4.2);
	num5 = mayornum(1.2, 3.4, 5.6);
	num6 = mayornum(1.2, 5.6, 3.4);
	num7 = mayornum(3.4, 1.2, 5.6);
	num8 = mayornum(3.4, 5.6, 1.2);
	num9 = mayornum(5.6, 1.2, 3.4);
	num10 = mayornum(5.6, 3.4, 1.2);
	char1 = mayorletra(A, B, C);
	char2 = mayorletra(A, C, B);
	char3 = mayorletra(B, A, C);
	char4 = mayorletra(B, C, A);
	char5 = mayorletra(C, A, B);
	char6 = mayorletra(C, B, A);
	char7 = mayorletra(A, A, B);
	char8 = mayorletra(B, A, A);
	char9 = mayorletra(A, B, A);
	char10 = mayorletra(A, A, A);

	cout << num1 << " " << num2 << " " << num3 << " " << num4 << " " << num5 << " " << num6 << " " << num7 << " " << num8 << " " << num9 << " " << num10 << "\n";
	cout << char1 << " " << char2 << " " << char3 << " " << char4 << " " << char5 << " " << char6 << " " << char7 << " " << char8 << " " << char9 << " " << char10 << "\n";

	return 0;
}
