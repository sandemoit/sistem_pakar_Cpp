#include <iostream>
#include <conio.h>
#include <math.h>
#include <iomanip>
#include <windows.h>
#include <string>
using namespace std;

int main()
{
	int respon, valid;
	char nama[50], jwb;
	std::string pertanyaan[22] = {
		// Keluhan fisik
		"Apakah Anda memiliki keluhan Sakit Kepala?",
		"Apakah Anda memiliki keluhan Pusing?",
		"Apakah Anda memiliki keluhan Mudah Lelah?",
		"Apakah Anda merasa Gelisah?",
		"Apakah Anda memiliki keluhan Penglihatan Terganggu?",
		"Apakah Anda memiliki keluhan Rasa sakit di Dada?",
		"Apakah Anda memiliki keluhan Jantung Berdebar - debar?",
		"Apakah Anda memiliki keluhan Berat pada tengkuk?",
		// Riwayat hiperensi pribadi
		"Apakah Anda sedang dalam masa pengobatan hipertensi?",
		// Riwayat penyakit keras
		"Apakah Anda memiliki riwayat penyakit jantung?",
		"Apakah Anda memiliki riwayat penyakit otak?",
		"Apakah Anda memiliki riwayat penyakit mata?",
		"Apakah Anda memiliki riwayat penyakit diabetes melitus?",
		"Apakah Anda memiliki riwayat penyakit ginjal?",
		// Riwayat sosial
		"Apakah Anda sering Menjalani aktivitas berat?",
		"Apakah Anda seorang perokok?",
		"Apakah Anda Mengkonsumsi Alkohol?",
		"Apakah Anda Mengkonsumsi Garam berlebihan?",
		"Apakah Anda Mengkonsumsi Makanan berlemak?",
		"Apakah Anda Mengkonsumsi kopi?",
		"Apakah Anda Sedang stres?",
		"Apakah Anda Kurang Olahraga?",
	};
	std::string opsi[6] = {
		"* [0] Tidak                       *",
		"* [1] Kurang Yakin                *",
		"* [2] Sedikit Yakin               *",
		"* [3] Cukup Yakin                 *",
		"* [4] Yakin                       *",
		"* [5] Sangat Yakin                *",
	};
	float cf_pertanyaan[22] = {
		0.3, // 1
		0.4, // 2
		0.2, // 3
		0.1, // 4
		0.5, // 5
		0.3, // 6
		0.2, // 7
		0.1, // 8
		0.6, // 9
		0.6, // 10
		0.5, // 11
		0.4, // 12
		0.8, // 13
		0.3, // 14
		0.3, // 15
		0.4, // 16
		0.2, // 17
		0.1, // 18
		0.5, // 19
		0.3, // 20
		0.2, // 21
		0.1, // 22
	};
	float cf_user[6] = {0, 0.2, 0.4, 0.6, 0.8, 1};
	double cf = 0;
	double cf_pararel[22] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
	};
	double cf_gabungan = 0;

	system("cls");
	cout << "**********************************************************************" << endl;
	cout << "*                SISTEM PAKAR DIAGNOSA PENYAKIT HIPERTENSI           *" << endl;
	cout << "**********************************************************************" << endl;
	cout << "*                         SELAMAT DATANG                             *" << endl;
	cout << "*                                                                    *" << endl;
	cout << "**********************************************************************" << endl;
	cout << "Masukkan nama anda : ";
	cin.getline(nama, 50);
	cout << endl
		 << endl;
awal:
	system("cls");
	cout << "Halo " << nama << "! Anda akan memulai tes tipe kepribadian." << endl;
	cout << "Silakan mengikuti intruksi berikut untuk menjawab pertanyaan" << endl
		 << endl;
	cout << "***********************************" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << opsi[i] << endl;
	}
	cout << "***********************************" << endl;
	cout << endl
		 << endl;

	for (int i = 0; i < 22; i++)
	{
		valid = 0;
		do
		{
			cout << pertanyaan[i] << endl;
			cout << "jawab : ";
			cin >> respon;
			if (respon >= 0 && respon <= 5)
			{
				valid = 1;
				cf_pararel[i] = cf_pertanyaan[i] * cf_user[respon];
			}
			else
			{
				cout << "\t jawaban tidak sesuai" << endl;
			}
		} while (valid == 0);
	}
	cf = cf_pararel[0];
	for (int i = 1; i < 22; i++)
	{
		cf = cf + (cf_pararel[i] * (1 - cf));
	}
	cf_gabungan = cf;
	cout << "*************************************************************************************" << endl;
	cout << "                   Hasil Diagnosa Faktor Risiko Hipertensi                           " << endl;
	cout << "*************************************************************************************" << endl;
	cout << "              Anda memiliki resiko " << cf_gabungan * 100 << "% hipertensi " << endl;
	cout << "*************************************************************************************" << endl;

	cout << endl
		 << "Apakah anda ingin menghitung kembali (1. Ya/2. Tidak)? ";
	cin >> respon;
	if (respon == 1)
	{
		goto awal;
	}
}
