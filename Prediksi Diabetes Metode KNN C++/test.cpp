#include <bits/stdc++.h>
#include <conio.h>
#include <fstream>
#include <iomanip>
using namespace std;

struct Point
{
	int val;	 // data outcome
	double preg, glu, bp, st, ins, bmi, dpf, age;	 // data input
	double distance; // hasil Euclidean distance
};

// fungsi yang digunakan saat pengurutan data berdasar Euclidean distance
bool comparison(Point a, Point b)
{
	return (a.distance < b.distance);
}

// fungsi untuk mencari klasifikasi
int classifyAPoint(Point arr[], int n, int k, Point p)
{
	for (int i = 0; i < n; i++)
		arr[i].distance =
			sqrt((arr[i].preg - p.preg) * (arr[i].preg - p.preg) +
				 (arr[i].glu - p.glu) * (arr[i].glu - p.glu) +
				 (arr[i].bp - p.bp) * (arr[i].bp - p.bp) +
				 (arr[i].st - p.st) * (arr[i].st - p.st) +
				 (arr[i].ins - p.ins) * (arr[i].ins - p.ins) +
				 (arr[i].bmi - p.bmi) * (arr[i].bmi - p.bmi) +
				 (arr[i].dpf - p.dpf) * (arr[i].dpf - p.dpf) +
				 (arr[i].age - p.age) * (arr[i].age - p.age));

	// fungsi untuk mengurutkan data
	sort(arr, arr+n, comparison);

	// mengelompokkan hasil berdasar K yang telah ditentukan
	int freq1 = 0;	 // Frequency of group 0 (tidak diabetes)
	int freq2 = 0;	 // Frequency of group 1 (diabetes)
	for (int i = 0; i < k; i++)
	{
		if (arr[i].val == 0)
			freq1++;
		else if (arr[i].val == 1)
			freq2++;
	}
	if (freq2 > freq1)
	{
		cout << "pasien mungkin mengidap diabetes" << endl;
		return 0;
	}
	else
	{
		cout << "pasien mungkin tidak mengidap diabetes" << endl;
		return 0;
	}
}

// Driver code
int main()
{
	ifstream file;
	int count = 0;
    string line;
    file.open("train.txt");
    while (getline(file, line))
        count++;
    file.close();
    count = count/9; // jumlah data yang ada
    Point arr[count];
    
    file.open("train.txt");
    for (int i = 0; i < count; i++)
    {
    	file >> arr[i].preg;
    	file >> arr[i].glu;
    	file >> arr[i].bp;
    	file >> arr[i].st;
    	file >> arr[i].ins;
    	file >> arr[i].bmi;
    	file >> arr[i].dpf;
    	file >> arr[i].age;
    	file >> arr[i].val;
    } file.close();

    cout << "=======================================================================================================================================" << endl;
	cout << "| Pregnancies |   Glucose   | Blood Preasure | Skin Thickness |   Insulin   |     BMI     | Diabetes Pedigree |     Age     | Outcome |" << endl;
	cout << "=======================================================================================================================================" << endl;
	for (int i = 0; i < count; i++)
	{
		cout <<"| " << setiosflags(ios::left) << setw(12) << setfill(' ') << arr[i].preg <<"| " ;
		cout << setiosflags(ios::left) << setw(12) << setfill(' ') << arr[i].glu <<"| " ;
		cout << setiosflags(ios::left) << setw(15) << setfill(' ') << arr[i].bp <<"| " ;
		cout << setiosflags(ios::left) << setw(15) << setfill(' ') << arr[i].st <<"| " ;
		cout << setiosflags(ios::left) << setw(12) << setfill(' ') << arr[i].ins <<"| " ;
		cout << setiosflags(ios::left) << setw(12) << setfill(' ') << arr[i].bmi <<"| " ;
		cout << setiosflags(ios::left) << setw(18) << setfill(' ') << arr[i].dpf <<"| " ;
		cout << setiosflags(ios::left) << setw(12) << setfill(' ') << arr[i].age <<"| " ;
		cout << setiosflags(ios::left) << setw(8) << setfill(' ') << arr[i].val <<"| " ;
		cout << endl;
	}

	// data testing
	Point p; 
	cout << "===SILAKAN MASUKKAN DATA===" << endl;
	cout << "Pregnancies : "; cin >> p.preg;
	cout << "Glucose : "; cin >> p.glu;
	cout << "Blood Preasure : "; cin >> p.bp;
	cout << "Skin Thickness : "; cin >> p.st;
	cout << "Insulin : "; cin >> p.ins;
	cout << "BMI : "; cin >> p.bmi;
	cout << "Diabetes Pedigree : "; cin >> p.dpf;
	cout << "Age : "; cin >> p.age;


	int k = 3;
	classifyAPoint(arr, count, k, p);
	getch();
	return 0;
}
