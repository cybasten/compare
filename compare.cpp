#include<iostream>
#include<fstream>
#include<string>

using namespace std;

ifstream fin;
ofstream fout;
char TmpA;
string SizA;
string SizB;
string CrcA;
string CrcB;
string NamA;
string NamB;

int main()
{
	fin.open("00.txt");
	if(fin.fail())
	{
		cout << "Input file open error!" << endl;
		exit(1);
	}
	fout.open("00.bat");
	if(fout.fail())
	{
		cout << "Output file open error!" << endl;
		exit(1);
	}
	do
	{
		do
		{
			TmpA = fin.get();
		}while(TmpA > 126 || TmpA < 33);
		do
		{
			SizA = SizA + TmpA;
			TmpA = fin.get();
		}while(TmpA < 127 && TmpA > 32);
		do
		{
			TmpA = fin.get();
		}while(TmpA > 126 || TmpA < 33);
		do
		{
			CrcA = CrcA + TmpA;
			TmpA = fin.get();
		}while(TmpA < 127 && TmpA > 32);
		do
		{
			TmpA = fin.get();
		}while(TmpA > 126 || TmpA < 33);
		do
		{
			NamA = NamA + TmpA;
			TmpA = fin.get();
		}while(TmpA < 127 && TmpA > 32);
		if (!SizA.compare(SizB) && !CrcA.compare(CrcB))
		{
			cout << SizA << " " << SizB << ", " << CrcA << " " << CrcB << "  OK" << endl;
			if (NamA.length() > NamB.length())
				fout << "del " << NamA << endl;
			else
				fout << "del " << NamB << endl;
		}
		else
			cout << SizA << " " << SizB << "  Fail" << endl;
		SizB.clear();
		SizB = SizB + SizA;
		SizA.clear();
		CrcB.clear();
		CrcB = CrcB + CrcA;		
		CrcA.clear();
		NamB.clear();
		NamB = NamB + NamA;
		NamA.clear();
	}while(!fin.eof());
	return 0;
}


