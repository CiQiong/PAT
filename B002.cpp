#include<iostream>
#include<string>
using namespace std;
int main(){
	string n1;
	cin >> n1;
	int l = n1.length();
	int *n = new int[l];
	int sum = 0,jsq1=0,jsq2=0;//就这一个地方不对jsq1加上=0 
	while (n1[jsq1]!= '\0'){
		sum+= n1[jsq1]-'0';
		jsq1++;
	}
	if (sum != 0)
	{
		int t[10];
		while (sum != 0)
		{
			t[jsq2] = sum % 10;
			jsq2++;
			sum = sum / 10;
		}
		for (int i = jsq2 - 1; i > 0; i--)
		{
			switch (t[i]){
			case 0:cout << "ling"; break;
			case 1:cout << "yi"; break;
			case 2:cout << "er"; break;
			case 3:cout << "san"; break;
			case 4:cout << "si"; break;
			case 5:cout << "wu"; break;
			case 6:cout << "liu"; break;
			case 7:cout << "qi"; break;
			case 8:cout << "ba"; break;
			case 9:cout << "jiu"; break;
			}
			cout << " ";
		}
		switch (t[0]){
		case 0:cout << "ling"; break;
		case 1:cout << "yi"; break;	
		case 2:cout << "er"; break;	
		case 3:cout << "san"; break;
		case 4:cout << "si"; break;
		case 5:cout << "wu"; break;
		case 6:cout << "liu"; break;
		case 7:cout << "qi"; break;
		case 8:cout << "ba"; break;
		case 9:cout << "jiu"; break;
		}
	}
	else{
		cout << "ling";
	}
	delete[] n;
	return 0;
}
