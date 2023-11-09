#include <iostream>
using namespace std;
int main () {
	setlocale (0, "");
float a, d;
int b;
int c;
cout << "Local operators:\tvodafone - 1;\tlifecell - 2;\tkyivstar - 3;\n\n";
cout << "Enter the call cost"<<endl;	
cin >> a;
cout << "Select the first operator" <<endl;	
cin >> b;
cout << "Select the second operator" << endl;
cin >> c;
switch (b)
 {
	case 1:
		switch (c)
		{
			case 1:	
			d = a;
				break;
			case 2:
			d = a*1.1;
				break;	
			case 3:
			d = a*1.2;
				break;	
		}
		break;
		
		case 2:
			a = a*1.1;
		switch (c)
		{
			case 1:
			d = a*0.9;	
				break;
			case 2:
				d = a;
				break;	
			case 3:
			d = a*1.1;
				break;	
		}
		break;
		
		case 3:
			a = a*1.2;
		switch (c)
		{
			case 1:	
			d = a*0.8;
				break;
			case 2:
			d = a*0.9;
				break;	
			case 3:
			d = a;
				break;	
		}
		break;
		
}
	cout << d;
	
	
}
	
	

	
	