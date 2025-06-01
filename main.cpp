#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;

struct Time {
	int showTimes; //! jam tayang
	bool seats[3][15]; //!3 baris 15 kolom
};

struct Schedule {
	int day;
	Time time[10] = {{-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}};
};

struct Movie {
	string movieTitle;
	string genre[3];
	string sutradara;
	string ratingUsia;
	int duration;
	Schedule dayIndex[7] = {{-1}, {-1}, {-1}, {-1}, {-1}, {-1}, {-1}};
	Movie *next;
};

struct Bioskop {
	string bioskop;
	Movie *headMovie = NULL;
	Movie *tailMovie = NULL;
};

struct Ticket {
	string ticketId; //!Ticket id
	string bioskop; //!Nama bioskop
	string movieTitle; //!Judul Movie
	string seatNumber; //!Nomer kursi (A2)
	int day; //! Hari ticket tujuan
	int showTime; // !jam tayangnya
	Ticket *next; //!Pointer ke tiket berikutnya
};

//!User bisa punya tiket lebih dari 1 make linked list
struct User {
	string username;
	Ticket *headTicket;
	Ticket *tailTicket;
};

struct Moviesorted {
	int day;
	int bioskopIndex;
	Movie *movie;
};

string schedule[7] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu", "Minggu"};
User user[6] = {{"Adelyn"}, {"Aldi"}, {"Bajang"}, {"Devika"}, {"Ibnu"}, {"Mediana"}};
Bioskop bioskop[3] = {{ "FESTIVE WALK CGV" },{ "TECHONMART CGV" }, { "MAL KARAWANG XXI"	}};
Moviesorted sorted[50];
Movie* currentMovie;
int currentBioskopIndex = -1; //!index bioskop saat ini
int currentDayIndex = -1; //!index hari saat ini
int currentUserIndex = -1; //!index user saat ini
int currentShowTimeIndex = -1; //!index jam tayang saat ini
int ticketCount = 0;

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
#include "header.txt"
#include "selectionSort.txt"
#include "searchGenre.txt"
#include "bookingKursi.txt"
#include "cekTiket.txt"

//! Bikin function percobaan di sini, habis tuh hapus pindahin ke file


int main() {
	generateMovie();

	int choice;
	while (choice != 5) {
		if(currentUserIndex == -1) {
			head();
			userName();
			if(currentUserIndex == -1) continue;
		}

		head();
		cout << "\t\t\t\t\t\t  MENU UTAMA" << endl;
		cout << "\t\t1. Pilih Bioskop" << endl;
		cout << "\t\t2. Cek Tiket" << endl;
		cout << "\t\t3. Cari Movie berdasarkan genre" << endl;
		cout << "\t\t4. Log Out" << endl;
		cout << "\t\t5. Akhiri program" << endl;
		cout << "\t\t==============================================================================" << endl;
		cout << "\t\tMasukkan pilihan anda: ";
		cin >> choice;

	
		int padding;
		int leftPad;
		int rightPad;
		
		switch (choice) {
		case 1:
			head();
			nampilinBioskop(currentBioskopIndex);
			head();
			tampilkanHari();
			head();
			currentMovie = listMovie();
			head();
			tampilkanDetailFilm ();
			tampilkanJamTayang ();
			bookingKursi();
			break;
		case 2:
			// MENAMPILKAN TIKET DARI USER
			break;
		case 3:
			head();
			currentMovie = searchGenre();
			head();
			tampilkanDetailFilm ();
			tampilkanJamTayang ();
			break;
		case 4:
			currentUserIndex = -1;
			break;
		default:
			cout << "\t\t=============================================================" << endl;
			cout << "\t\tMenu yang anda pilih tidak tersedia" << endl;
			break;
		}
	}
	
	cin.ignore().get();
	cleanup();
	return 0;
}