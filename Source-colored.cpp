#include <iostream>
#include <Windows.h>

//we'll be again using a colorlibrary included in Windows.h

using namespace std;


void gercolor(int front, int back); 

int main() {

	for (int i = 0; i < 512; i++) {
		int a = i % 16;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
		cout << i << endl; // when you try this out, you'll be aware that in every 16, backplan becomes different.
	}
	


}

void gercolor(int front, int back) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back * 16 + front);
} // now it is better here with that function.
