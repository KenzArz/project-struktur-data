#include <iostream>
#include <string>
using namespace std;

struct Time {
	int showTimes;
	bool seats[3][15];
	Time *next;
};

struct Movie {
	string movieTitle;
	string genre[3];
	string sutradara;
	string ratingUsia;
	int duration;
	int dayIndex[7] = {-1, -1, -1, -1, -1, -1, -1};
	Movie *next;
	Time time[10] = {{-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}};
};

struct Schedule {
	string day;
};

struct Bioskop {
	string bioskop;
	Movie *headMovie = NULL;
	Movie *tailMovie = NULL;
	string schedule[7] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu", "Minggu"};
};

struct Ticket {
	string ticketId;
	string bioskop;
	string movieTitle;
	string seatNumber;
	int day;
	int showTime;
};

struct User {
	string username;
	Ticket *headTicket;
	Ticket *tailTicket;
};

User user[6] = {{"Adelyn"}, {"Aldi"}, {"Bajang"}, {"Devika"}, {"Ibnu"}, {"Mediana"}};
Bioskop bioskop[3] = {{ "FESTIVE WALK CGV" },{ "TECHONMART CGV" }, { "MAL KARAWANG XXI"	}};
Movie* currentMovie;
int currentBioskopIndex = -1;
int currentDayIndex = -1;
int currentUserIndex = -1;

//	TODO:
//= 1. Menampilkan daftar bioskop -- Mediana
//= 2. Menampilkan list hari -- Devika
//= 3. Menampilkan list film berdasarkan hari yang sudah dipilih user -- Aldi,
//= 4. Menampilkan detail film berdasarkan pilihan user -- Nata;
//= 5. Menampilkan jam tayang dari film yang udah dipilih -- Nata
//=	6. Membuat fungsi untuk booking kursi --  Bajang
//= 7. Nyimpen tiket berdasarkan nama movie, jam tayang, dan bioskop yang sudah dimasukin user, ticket id bisa pake alamat memori -- Bajang
//= 8. Menampilkan semua ticket yang sudah dibeli user -- Adelyn
//= 9. Cari film berdasarkan genre --Aldi

//! Taro file di sini
#include "addMovie.txt"
#include "searchUsername.txt"
#include "tampilkanHari.txt"
#include "nampilinBioskop.txt"
#include "displayMovie.txt"
#include "cleanup.txt"
#include "detailMovie.txt"
#include "jamTayang.txt"

//! Bikin function percobaan di sini, habis tuh hapus pindahin ke file



void head() {
	system("cls");
	cout << "\t\t=============================================================" << endl;
	cout << "\t\t                 	  FATIXID" << endl;
	cout << "\t\t=============================================================" << endl;
}

int main() {
	generateMovie();
	int choice;
	while (choice != 5) {
		if(currentUserIndex == -1) {
			head();
			userName();
		}

		head();
		cout << "\t\t                 	 MENU UTAMA" << endl;
		cout << "\t\t1. Pilih Bioskop" << endl;
		cout << "\t\t2. Cek Tiket" << endl;
		cout << "\t\t3. Cari Movie berdasarkan genre" << endl;
		cout << "\t\t4. Log Out" << endl;
		cout << "\t\t5. Akhiri program" << endl;
		cout << "\t\t=============================================================" << endl;
		cout << "\t\tMasukkan pilihan anda: ";
		cin >> choice;

		head();
		switch (choice) {
		case 1:
			nampilinBioskop(currentBioskopIndex);
			head();
			tampilkanHari();
			head();
			currentMovie = listMovie();
			tampilkanDetailFilm ();
			tampilkanJamTayang ();
			system("pause");
			break;
		case 2:
			//CEK TIKET
			break;
		case 3:
			// Cari Genre
			break;
		case 4:
			currentUserIndex = -1;
			//Log out
			break;
		default:
			cout << "\t\t=============================================================" << endl;
			cout << "\t\tMenu yang anda pilih tidak tersedia" << endl;
			break;
		}
	}
	
	cleanup();
	return 0;
}
