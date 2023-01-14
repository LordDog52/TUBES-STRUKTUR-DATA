#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <stdlib.h> //agar bisa clear screen
#include <iostream>
using namespace std;

#define info(P) (P)->info
#define child(P) (P)->child
#define lastChild(P) (P)->lastChild
#define prev(P) (P)->prev
#define next(P) (P)->next
#define first(L) ((L).first)
#define last(L) ((L).last)

typedef struct elmAktor *adrAktor;
typedef struct elmChild *adrChild;
typedef struct elmFilm *adrFilm;

struct aktor{ //tipe data List 1 (Parent)
    string nama,asal,tanggal;
    int umur;
};
struct film{ //tipe data List 2
    string judul,sutradara,genre,durasi;
    int tahun;
};
//Circular Double linked list
struct elmAktor{ //elemen aktor yaitu List 1 (Parent)
    aktor info;
    adrChild child;
    adrChild lastChild;
    adrAktor prev,next;
};
//Double lingked list
struct elmChild{ //elemen child dari List parent
    adrFilm info;
    adrChild prev,next;
};
//Double lingked list
struct elmFilm{ //elemen film yaitu List 2
    film info;
    adrFilm prev,next;
};
struct listAktor{ //List 1 (Parent)
    adrAktor first,last;
};
struct listFilm{ // List 2 (Parent)
    adrFilm first,last;
};

int showMenu();//fungsi menunjukkan menu
//fungsi create List
void createAktor(listAktor &LA);
void createFilm(listFilm &LF);
//fungsi create elemen
adrAktor createElmAktor(aktor x);
adrChild createElmChild(adrFilm P);
adrFilm createElmFilm(film x);

void insertFilm(listFilm &LF,adrFilm P);//insert last data film ke List 2
//fungsi delete
void deleteFirstAktor(listAktor &LA,adrAktor &P);
void deleteFirstChild(adrAktor P,adrChild &Q);
void deleteFirstFilm(listFilm &LF,adrFilm &P);
void deleteLastAktor(listAktor &LA,adrAktor &P);
void deleteLastChild(adrAktor P,adrChild &Q);
void deleteLastFilm(listFilm &LF,adrFilm &P);
void deleteAfterAktor(adrAktor prec,adrAktor &P);
void deleteAfterChild(adrChild prec,adrChild &Q);
void deleteAfterFilm(adrFilm prec,adrFilm &P);

void deleteAktor(listAktor &LA,string nama,adrAktor &P);
void deleteChild(adrAktor &P,adrChild Q,adrChild &R);
void deleteFilm(listFilm &LF,string judul,adrFilm &P);

//pembantu
void connecting(adrAktor P,adrChild Q);     //untuk membuat relasi
adrFilm searchFilm(listFilm LF,string judul);   //Mencri film untuk di cek di yg no 4
void showFilmInAktor(listAktor LA);         //hanya membantu untuk melihat apakah sudah ter relasi atau belum
void deleteFilmTertentu(listAktor &LA,listFilm &LF,string judul);   //untuk menghapus film tertentu
adrAktor cekAktor(listAktor LA,string nama,string asal,string tgl,int umur);    //untuk mengecek apakah data aktor sudah ada di list atau blm
adrFilm cekFilm(listFilm LF,string judul,string genre,string sutradara,string durasi,int tahun);    //untuk mengecek apakah data film sudah ada di list atau blm
void cekIsiAktor(listAktor LA);
void cekIsiFilm(listFilm LF);


//fungsi ditugas besar
void insertAktor(listAktor &LA,adrAktor P); // 1) Menambahkan aktor baru
void printAktor(listAktor LA,string nama); // 2) Menampilkan data aktor X
void deleteAktorTertentu(listAktor &LA,string nama); // 3) Menghapus aktor tertentu
adrAktor searchAktor(listAktor LA,string nama); // 4) Mencari aktor X
void insertFilmOlehAktor(listAktor &LA,listFilm &LF); // 5)	Menambahkan film Y oleh aktor X
void deleteFilmDariAktor(listAktor &LA,listFilm &LF,string nama,string judul); // 6) Menghapus film Y dari aktor X
void showFilmDariAktor(listAktor LA,string nama); // 7) Menampilkan seluruh film oleh aktor X
adrChild searchFilmDariAktor(listAktor LA,listFilm LF,string nama,string judul); // 8) Mencari film Y dari aktor X
void AddRelation(listAktor LA,listFilm LF,string nama,string judul); // 9) Membuat relasi antara aktor X dan film Y
void DeleteRelation(listAktor LA,listFilm LF,string nama,string judul); // 10) Menghapus relasi antara aktor X dan film Y
void AktorPopuler(listAktor LA,listFilm LF); // 11) Menampilkan aktor yang memiliki jumlah jumlah film paling banyak dan menampilkan judul filmnya
void showAktorDariFilm(listAktor LA,string judul); // 12) Menampilkan aktor-aktor dari film Y

#endif // TUBES_H_INCLUDED
