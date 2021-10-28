#include <iostream>
using namespace std;
int main () {

int edad;
string leyenda;

cout << "ingrese una edad" << endl;

cin >> edad;

if (edad <= 12){

	leyenda = "menor";
	cout << leyenda;
}
	if (edad > 12 && edad <= 18)
	{
		leyenda = "cadete";
		cout << leyenda;
		}
		else
		{
		if (edad > 18 && edad <= 26) {
			leyenda = "mayor";
			cout << leyenda;
		}
		else
		{
			if (edad > 26)
			{
			leyenda = "veterano";
			cout << leyenda << endl;
			}
		}
}
}