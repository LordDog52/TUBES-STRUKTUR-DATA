#include "tubes.h"

int main(){
    listAktor LA;
    listFilm LF;
    aktor newAktor;
    adrAktor P;
    int pilihan;
    string lanjut;

    //create aktor
    createAktor(LA);
    //create film
    createFilm(LF);
    pilihan=showMenu();

    while (pilihan!=0){
        //untuk clear screen
        system("cls");
        if (pilihan==1){
            cout<<"Nama : ";getline(cin>>ws,newAktor.nama);
            cout<<"Asal : ";getline(cin>>ws,newAktor.asal);
            cout<<"Tanggal lahir : ";getline(cin>>ws,newAktor.tanggal);
            cout<<"Umur :";cin>>newAktor.umur;

            //pengecekan apakah aktor tsb ada di list atau tidak, jika tidak maka ditambahkan, jika ada tidak bisa ditambahkan
            if (cekAktor(LA,newAktor.nama,newAktor.asal,newAktor.tanggal,newAktor.umur)==NULL){
                P=createElmAktor(newAktor);
                insertAktor(LA,P);
                cout<<endl;
                cout<<"Aktor "<<newAktor.nama<<" berhasil ditambahkan ke List"<<endl;
            }else{
                cout<<endl;
                cout<<"Aktor tersebut sudah ada di list"<<endl;
            }

        }else if(pilihan==2){
            string nama;
            cout<<"Nama aktor yang dicari : ";getline(cin>>ws,nama);
            cout<<endl;
            printAktor(LA,nama);
        }else if(pilihan==3){
            string nama;
            if (first(LA)==NULL){
                cout<<"List Kosong"<<endl;
            }else{
                cout<<"Nama aktor yang akan dihapus : ";getline(cin>>ws,nama);
                deleteAktorTertentu(LA,nama);
            }
        }else if(pilihan==4){
            insertFilmOlehAktor(LA,LF);
        }else if(pilihan==5){
            string nama,judul;
            cout<<"Nama aktor : ";getline(cin>>ws,nama);
            cout<<"Judul Film : ";getline(cin>>ws,judul);
            deleteFilmDariAktor(LA,LF,nama,judul);
        }else if(pilihan==6){
            string nama;
            cout<<"Nama aktor : ";getline(cin>>ws,nama);
            showFilmDariAktor(LA,nama);
        }else if(pilihan==7){
            string nama,judul;
            cout<<"Nama aktor : ";getline(cin>>ws,nama);
            cout<<"Judul Film : ";getline(cin>>ws,judul);
            AddRelation(LA,LF,nama,judul);
        }else if(pilihan==8){
            string nama,judul;
            cout<<"Nama aktor : ";getline(cin>>ws,nama);
            cout<<"Judul Film : ";getline(cin>>ws,judul);
            DeleteRelation(LA,LF,nama,judul);
        }else if(pilihan==9){
            AktorPopuler(LA,LF);
        }else if(pilihan==10){
            string judul;
            cout<<"Judul : ";getline(cin>>ws,judul);
            showAktorDariFilm(LA,judul);
        }else if (pilihan==11){
            film newFilm;
            cout<<"judul : ";getline(cin>>ws,newFilm.judul);
            cout<<"genre : ";getline(cin>>ws,newFilm.genre);
            cout<<"sutradara : ";getline(cin>>ws,newFilm.sutradara);
            cout<<"Durasi : ";getline(cin>>ws,newFilm.durasi);
            cout<<"tahun tayang : ";cin>>newFilm.tahun;

            //pengecekan apakah film tsb ada di list atau tidak, jika tidak maka ditambahkan, jika ada tidak bisa ditambahkan
            if (cekFilm(LF,newFilm.judul,newFilm.genre,newFilm.sutradara,newFilm.durasi,newFilm.tahun)==NULL){
                adrFilm P=createElmFilm(newFilm);
                insertFilm(LF,P);
                cout<<endl;
                cout<<"Film "<<newFilm.judul<<" berhasil ditambahkan ke list"<<endl;
            }else{
                cout<<endl;
                cout<<"Film tersebut sudah ada di list"<<endl;
            }

        }else if(pilihan==12){
            string judul;
            cout<<"Film yang akan dihapus : ";getline(cin>>ws,judul);
            deleteFilmTertentu(LA,LF,judul);
        }else if (pilihan==98){
            cekIsiAktor(LA);
        }else if (pilihan==99){
            cekIsiFilm(LF);
        }else if(pilihan==100){
            cout<<endl;
            cout<<"============================================"<<endl;
            cout<<"Hanya untuk mengecek relasi nya saja"<<endl;
            showFilmInAktor(LA);
            cout<<endl;
            cout<<"============================================"<<endl;
        }
        cout<<endl;
        cout<<"Kembali ke menu utama (Y/N) : ";cin>>lanjut;
        if (lanjut=="Y" || lanjut=="y"){
            pilihan=showMenu();
        }else{
            pilihan=0;
        }
    }
    cout<<endl;
    cout<<"Program Selesai"<<endl;
    return 0;
}
