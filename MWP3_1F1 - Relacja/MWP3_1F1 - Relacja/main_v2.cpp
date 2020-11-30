#include <iostream>
#include <string>
using namespace std;



int zwrotnosc(int max, int tab[150][150]) {
	int zwrotnosc = 1;
	for (int i = 0; i < max; i++) {
		if (tab[i][i] == 0) {
			zwrotnosc = 0;
		}
	}
	return zwrotnosc;
}

int przecizwrotnosc(int max, int tab[150][150]) {
	int przeciwzwrotnosc = 1;
	for (int i = 0; i < max; i++) {
		if (tab[i][i] == 1) {
			przeciwzwrotnosc = 0;
		}
	}
	return przeciwzwrotnosc;
}

int symetria(int max, int tab[150][150]) {
	int symetria = 1;
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			if (tab[i][j] != tab[j][i]) {
				symetria = 0;
			}
		}
	}
	return symetria;
}

int antysymetria(int max, int tab[150][150]) {
	int antysymetria = 1;
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			if (i != j) {
				if (tab[i][j] == 1 && tab[j][i] == 1) {
					antysymetria = 0;
				}
			}
		}
	}
	return antysymetria;
}

int przechodniosc(int max, int tab[150][150]) {
	int tab2[150][150];
	int przechodniosc = 1;
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			int s = 0;
			for (int k = 0; k < max; k++) {
				s += tab[i][k] * tab[k][j];
				tab2[i][j] = s;
				if (tab2[i][j] > 1) tab2[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			if (tab[i][j] != tab2[i][j]) {
				przechodniosc = 0;
			}
		}
	}
	return przechodniosc;
}

int spojnosc(int max, int tab[150][150]) {
	int spojnosc = 1;
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			if (tab[i][j] == 0 && tab[j][i] == 0) {
				spojnosc = 0;
			}
		}
	}
	return spojnosc;
}

int main() {

	int tab[150][150] = { 0 };
	int a, b, max = 0, z = 0, pz = 0, s = 0, as = 0, p = 0, sp = 0, x = 0, rr = 0, rpl = 0, rpcz = 0;

	while (cin >> a >> b) {
		if (a > max) max = a - 1;
		if (b > max) max = b - 1;
		tab[a - 1][b - 1] = 1;
	}

	if (zwrotnosc(max, tab) == 1) z = 1, cout << "Z ";
	if (przecizwrotnosc(max, tab) == 1) pz = 1, cout << "PZ ";
	if (symetria(max, tab) == 1) s = 1, cout << "S ";
	if (antysymetria(max, tab) == 1) as = 1, cout << "AS ";
	if (przechodniosc(max, tab) == 1) p = 1, cout << "P ";
	if (spojnosc(max, tab) == 1) sp = 1, cout << "SP";
	if (z == 0 && pz == 0 && s == 0 && as == 0 && p == 0 && sp == 0) x = 1, cout << "X";

	if (x == 0) {
		cout << endl;
		if (z == 1 && s == 1 && p == 1) rr = 1, cout << "RR ";
		if (z == 1 && p == 1 && as == 1 && sp == 1) rpl = 1, cout << "RPL ";
		if (rpl == 0 && z == 1 && p == 1 && as == 1) rpcz = 1, cout << "RPCz";
		if (rr == 0 && rpl == 0 && rpcz == 0) cout << "X";
	}

	return 0;
}
