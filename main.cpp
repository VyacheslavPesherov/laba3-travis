#include <iostream> 
#include <string.h>
#include "comparsion.cpp"
#include "perimetr.cpp"
#include "area.cpp"

using namespace std;

int main()
{
    const char circle[7] = {'c', 'i', 'r', 'c', 'l', 'e'};
    int count;
    do {
        cout << "Enter number of figures" << endl;
        cin >> count;
        if (count < 1) cout << "Error! Invalid number" << endl;
    } while (count < 1);
    cin.get();
    char str[count][30];
    float x[count] = {0}, y[count] = {0}, rad[count] = {0};
    float per[count], ar[count];
    
    for (int i = 0; i < count; i++) {
        cout << "Enter name of figure" << endl;
	    cin.getline(str[i], 30);
	    if (comparsion(str[i]) != 1 ) {
			cout << "Error! Invalid figure" << endl;
			i--;	
			continue;	
	    }
	    if (str[i][6] == '(') {
	    	bool flag = false;
	    	short spaces = 0, komma = 0;
	    	for (int j = 7; j < 30; j++) {
	    		if (str[i][j] == ')') {
					flag = true;
					int temp = j - 1;
					float dig = 1;
					for (temp; str[i][temp] != ' '; temp--) {
						char digit = str[i][temp];
						switch (digit) {
							case '0' : 
								break;
							case '1' : 
								rad[i] += 1 * dig;
								break;
							case '2' : 
								rad[i] += 2 * dig;
								break;
							case '3' : 
								rad[i] += 3 * dig;
								break;
							case '4' : 
								rad[i] += 4 * dig;
								break;
							case '5' : 
								rad[i] += 5 * dig;
								break;
							case '6' : 
								rad[i] += 6 * dig;
								break;
							case '7' : 
								rad[i] += 7 * dig;
								break;
							case '8' : 
								rad[i] += 8 * dig;
								break;
							case '9' : 
								rad[i] += 9 * dig;
								break;
							case '.' :
								rad[i] *= 1 / dig;
								dig /= dig * 10;
								break;
							default : 
								cout << "Error! Invalid radius" << endl;
								i--;
								break;
						}
						dig *= 10;
					}
					break;
				}
	    		if (str[i][j] == ' ') spaces++; 
	    		if (str[i][j] == ' ' && spaces == 1) {
					int temp = j - 1;
					float dig = 1;
					for (temp; str[i][temp] != '('; temp--) {
						char digit = str[i][temp];
						switch (digit) {
							case '0' : 
								break;
							case '1' : 
								x[i] += 1 * dig;
								break;
							case '2' : 
								x[i] += 2 * dig;
								break;
							case '3' : 
								x[i] += 3 * dig;
								break;
							case '4' : 
								x[i] += 4 * dig;
								break;
							case '5' : 
								x[i] += 5 * dig;
								break;
							case '6' : 
								x[i] += 6 * dig;
								break;
							case '7' : 
								x[i] += 7 * dig;
								break;
							case '8' : 
								x[i] += 8 * dig;
								break;
							case '9' : 
								x[i] += 9 * dig;
								break;
							default : 
								cout << "Error! Invalid X coordinate" << endl;
								i--;
								break;
						}
						dig *= 10;
					}
				}
	    		if (str[i][j] == ',') komma++;
	    		if (str[i][j] == ',' && komma == 1) {
	    			int temp = j - 1;
					float dig = 1;
					for (temp; str[i][temp] != ' '; temp--) {
						char digit = str[i][temp];
						switch (digit) {
							case '0' : 
								break;
							case '1' : 
								y[i] += 1 * dig;
								break;
							case '2' : 
								y[i] += 2 * dig;
								break;
							case '3' : 
								y[i] += 3 * dig;
								break;
							case '4' : 
								y[i] += 4 * dig;
								break;
							case '5' : 
								y[i] += 5 * dig;
								break;
							case '6' : 
								y[i] += 6 * dig;
								break;
							case '7' : 
								y[i] += 7 * dig;
								break;
							case '8' : 
								y[i] += 8 * dig;
								break;
							case '9' : 
								y[i] += 9 * dig;
								break;
							default : 
								cout << "Error! Invalid Y coordinate" << endl;
								i--;
								break;
						}
						dig *= 10;
					}
				}
	    	}
	    	if (flag == false) {
				cout << "Error! Invalid format" << endl;
				x[i] = 0;
				y[i] = 0;
				rad[i] = 0;
			 	i--;
			 	continue;
			}
			if (spaces != 2) {
				cout << "Error! Invalid format" << endl;
				x[i] = 0;
				y[i] = 0;
				rad[i] = 0;
				i--;
				continue;
			}
			if (komma != 1) {
				cout << "Error! Invalid format" << endl;
				x[i] = 0;
				y[i] = 0;
				rad[i] = 0;
				i--;
				continue;
			}
		}
		else {
			cout << "Error! Invalid format" << endl;
			i--;
			continue;
		}
		per[i] = perimetr(rad[i]);
		ar[i] = 3.1415 * rad[i] * rad[i];
    }

	cout << endl << endl << endl;
	
    for (int i = 0; i < count; i++) {
        cout << (i + 1) << ".";
        puts(str[i]);
        cout << "	Perimetr = " << per[i] << endl;
        cout << "	Area = " << ar[i] << endl;
        cout << endl;
    }
   
    cin.get();
    return 0;
}
