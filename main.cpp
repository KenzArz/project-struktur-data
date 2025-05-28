#include <iostream>
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
	Movie *next, *prev;
	Time *headTime;
	Time *tailTime;
};

struct Schedule {
	string day;
	int dayIndex;
	Movie *headMovie;
	Movie *tailMovie;
};

struct Bioskop {
	string bioskop;
	Schedule schedule[7] = {{"Senin"}, {"Selasa"}, {"Rabu"}, {"Kamis"}, {"Jumat"}, {"Sabtu"}, {"Minggu"}};
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
int currentBioskopIndex;
int currentDayIndex;
int currentUserIndex;

//	TODO:
//= 0. nyari nama user
//= 1. Menampilkan daftar bioskop
//= 2. Menampilkan list hari
//= 3. Menampilkan list film berdasarkan hari yang sudah dipilih user, 
//= 4. Menampilkan detail film berdasarkan pilihan user;
//= 5. Menampilkan jam tayang dari film yang udah dipilih
//=	6. Membuat fungsi untuk booking kursi
//= 7. Booking tiket berdasarkan nama movie, jam tayang, dan bioskop yang sudah dimasukin user, ticket id bisa pake alamat memori
//= 8. Menampilkan semua ticket yang sudah dibeli user
//= 9. Cari film berdasarkan genre

//! Taro file di sini
#include "addMovie.txt"
#include "searchUsername.txt"

//! Bikin function percobaan di sini, habis tuh hapus pindahin ke file
void tampilkanDaftarBioskop() {
    cout << "\n=== Daftar Bioskop ===" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << bioskop[i].bioskop << endl;
    }

    int pilihan;
    cout << "\nPilih bioskop (1-3): ";
    cin >> pilihan;

    while (pilihan < 1 || pilihan > 3) {
        cout << "Pilihan tidak valid. Silakan pilih lagi (1-3): ";
        cin >> pilihan;
    }

    currentBioskopIndex = pilihan - 1;
    cout << "Bioskop yang dipilih: " << bioskop[currentBioskopIndex].bioskop << endl;
}


void head() {
	cin.ignore().get();
	cout << "\t\t==============================================" << endl;
	cout << "\t\t                 FATIXID" << endl;
	cout << "\t\t==============================================" << endl << endl;
}

int main() {
	string username;
	cout << "Masukkan nama user: ";
	getline(cin >> ws, username);
	userName(username);

	cout << "Nama user: " << user[currentUserIndex].username << endl;
	// head();
	// cout << "\t\t1. Bioskop";
	// cout << "\t\t2. Cari movie berdasarkan genre" << endl;
	// cout << "\t\t3. Cek tiketku" << endl;
	// cout << "\t\t4. Log Out" << endl;
	// cout << "\t\t==============================================\n";
	// cout << "Masukkan pilihan: " << endl;

	return 0;
}