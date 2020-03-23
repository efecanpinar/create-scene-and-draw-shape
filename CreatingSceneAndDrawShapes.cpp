#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <iomanip>
using namespace std;

void koordinatAta(int x, int y)//Koordinat fonksiyonu
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


struct Sahne//Sahne yapısı
{
	char karakter = 0;
	int genislik = 0;
	int yukseklik = 0;
};

struct Sahne sahneOlustur()//Sahne oluşturma fonksiyonu
{
	struct Sahne sahne;
	int genislik[3] = { 30, 40, 50 };
	int yukseklik[11] = { 20,21,22,23,24,25,26,27,28,29,30 };
	int karakter[5] = { '#', '+', '@', '$', '*' };

	int randgenislik = rand() % 3;
	sahne.genislik = genislik[randgenislik];

	int randyukseklik = rand() % 11;
	sahne.yukseklik = yukseklik[randyukseklik];

	int randkarakter = rand() % 5;
	sahne.karakter = karakter[randkarakter];
	return sahne;
}

struct Sahne sahneCiz(struct Sahne sahne)//Sahneyi çizdirme fonksitonu
{

	for (int i = 0; i < sahne.genislik - 1; i++)//Sahne üst taraf
	{
		cout << sahne.karakter;
	}
	cout << endl;
	for (int j = 0; j < sahne.yukseklik; j++)//Sahne sağ ve sol taraf
	{
		cout << sahne.karakter << setw(sahne.genislik - 1) << sahne.karakter;
		cout << endl;
	}
	for (int k = 0; k < sahne.genislik; k++)//Sahne alt taraf
	{
		cout << sahne.karakter;
	}
	return sahne;
}

struct LSekli //L şeklinin yapısı
{
	int koordx;
	int koordy;
	int boyut = 0;
	char lkarakter = 0;
};

struct LSekli lSekliOlustur()//L şeklini oluşturma fonksiyonu
{
	struct LSekli lsekli;
	int koordx[21] = { 5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
	lsekli.koordy = 3;
	int boyut[6] = { 2,3,4,5,6,7 };
	int lkarakter[5] = { '#', '+', '@', '$', '*' };

	int randkoordx = rand() % 21;
	lsekli.koordx = koordx[randkoordx];

	int randboyut = rand() % 6;
	lsekli.boyut = boyut[randboyut];

	int randlkarakter = rand() % 5;
	lsekli.lkarakter = lkarakter[randlkarakter];

	return lsekli;
}

struct LSekli lSekliCiz(struct LSekli lsekli)//L şeklini çizdirme fonksiyonu
{
	int x;
	int y;
	x = lsekli.koordx;
	y = lsekli.koordy;



	for (int i = 0; i < (lsekli.boyut / 2) + 1; i++)//L şeklini çizdirme
	{
		koordinatAta(x, y);
		cout << lsekli.lkarakter;
		x++;
	}

	y++;
	x = lsekli.koordx;
	koordinatAta(x, y);

	for (int j = 0; j < lsekli.boyut + 2; j++)//L şeklini çizdirme
	{
		cout << lsekli.lkarakter;
		y++;
		koordinatAta(x, y);
	}

	for (int k = 0; k < lsekli.boyut / 2 + 2; k++)//L şeklini çizdirme
	{
		koordinatAta((lsekli.koordx+lsekli.boyut / 2), lsekli.koordy+k);
		cout << lsekli.lkarakter;
	}

	y = lsekli.koordy + lsekli.boyut/2;

	for (int s = 0; s < lsekli.boyut / 2 + 1; s++)//L şeklini çizdirme
	{
		koordinatAta(x + lsekli.boyut / 2, y+1);
		cout << lsekli.lkarakter;
		x++;
	}

	x = lsekli.koordx;

	for (int t = 0; t < lsekli.boyut / 2 + 2; t++)//L şeklini çizdirme
	{
		koordinatAta(lsekli.koordx + lsekli.boyut, lsekli.koordy + (lsekli.boyut / 2 + 1) + t);
		cout << lsekli.lkarakter;
		y++;
		koordinatAta(x, y);
	}

	for (int a = 0; a < lsekli.boyut + 1; a++)//L şeklini çizdirme
	{
		koordinatAta(lsekli.koordx+a, lsekli.koordy+lsekli.boyut + 2);
		cout << lsekli.lkarakter;
	}

	return lsekli;
}

struct LSekli lSekliAsagiGotur(struct LSekli lsekli)//L şeklini aşağı götürme yapısı
{
	lsekli.koordy++;

	return lsekli;
}


int main()
{
	struct LSekli lsekli;
	struct Sahne sahne;
	sahne = sahneOlustur();
	lsekli = lSekliOlustur();

	while (true)//Fonksiyonları döngüye sokma
	{
		system("cls");
		sahneCiz(sahne);
		lSekliCiz(lsekli);
		Sleep(100);
		
		while (lsekli.koordy != sahne.yukseklik-lsekli.boyut - 2) //Alt sınır kontrolü
		{
			system("cls");
			lsekli = lSekliAsagiGotur(lsekli);
			sahneCiz(sahne);
			lSekliCiz(lsekli);
			Sleep(100);
		}

		lsekli = lSekliOlustur();
	}
	cin.get();
}