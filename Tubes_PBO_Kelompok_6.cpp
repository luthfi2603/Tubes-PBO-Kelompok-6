/*
    Tubes Kelompok 6
    Pembelian Token Listrik

    1. Muhammad Luthfi (221402050)
    2. Perwira Satria Taufik QD (221402124)
    3. Fenaya Cecilly Nababan (221402100)
    4. Rizqi Siti Aulia (221402127)
    5. Fadillah Emilia Nst (221402034)
*/

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// kelas TokenListrik untuk menjalankan program pembelian token listrik
class TokenListrik {
    protected:
        // deklarasi data member untuk program
        char namaPembeli[255];
        int nominal[10], jumlahPembelian, totalPembelian, diBayar, kembalian, totalDiskon, totalBayar;

    public:
        // default constructor untuk memberikan nilai default pada data member
        TokenListrik(){
            jumlahPembelian = 0;
            totalPembelian = 0;
            diBayar = 0;
            kembalian = 0;
            totalDiskon = 0;
            totalBayar = 0;
        }
        // method yang dijalankan pertama kali
        void menu(){
            system("CLS");
            cout << "\t======================================================================" << endl;
            cout << "\t|                                                                    |" << endl;
            cout << "\t|                   WARUNG PEMBELIAN TOKEN LISTRIK                   |" << endl;
            cout << "\t|                                                                    |" << endl;
            cout << "\t======================================================================" << endl;
            
            // meminta user untuk memasukkan namanya
            cout << "\tMasukkan nama anda : ";
            cin.getline(namaPembeli, 255);
            system("CLS");
        }

        // method untuk menampilkan menu pilihan
        void tokenMenu(){
            int pilihan;

            cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n";
            cout << "\t|   Menu :                    |\n";
            cout << "\t|                             |\n";
            cout << "\t|   1. Beli token listrik     |\n";
            cout << "\t|   0. Keluar                 |\n";
            cout << "\t| _ _ _ _ _ _ _ _ _ _ _ _ _ _ |\n";
            cout << "\t Pilih anda : ";
            cin >> pilihan;
            system("CLS");

            switch(pilihan){
                case 1:
                    // memanggil method lain untuk meneruskan program
                    beliTokenListrik();
                    break;
                case 0:
                    // keluar dari program
                    exit(1);
                    break;
                default:
                    cout << "\n\t Pilihan tidak valid\n";
                    exit(1);
            }
        }

        // method untuk memilih nominal pembelian
        void beliTokenListrik(){
            cout << "\t============================================================================  " << endl;
            cout << "\t|                                                                          |  " << endl;
            cout << "\t|                 NOMINAL                           KODE NORMAL            |  " << endl;
            cout << "\t|                                                                          |  " << endl;
            cout << "\t============================================================================  " << endl;
            cout << "\t|                                                                          |  " << endl;
            cout << "\t|                Rp. 20000                              A                  |  " << endl;
            cout << "\t|                Rp. 50000                              B                  |  " << endl;
            cout << "\t|                Rp. 100000                             C                  |  " << endl;
            cout << "\t|                Rp. 200000                             D                  |  " << endl;
            cout << "\t|                Rp. 500000                             E                  |  " << endl;
            cout << "\t|                                                                          |  " << endl;
            cout << "\t============================================================================  " << endl;
            cout << "\tPembelian di atas 200 ribu akan mendapatkan diskon 5%\n\tMaksimal 5 kali\n\tIsi berapa kali: ";

            // memasukkan jumlah pembelian berapa kali
            cin >> jumlahPembelian;
            if(jumlahPembelian == 0 || jumlahPembelian > 5){
                cout << "\n\tTidak valid\n";
                exit(1);
            }
            system("CLS");

            // looping sesuai jumlah inputan di atas
            for(int i = 0; i < jumlahPembelian; i++){
                cout << "\t============================================================================  " << endl;
                cout << "\t|                                                                          |  " << endl;
                cout << "\t|                 NOMINAL                           KODE NORMAL            |  " << endl;
                cout << "\t|                                                                          |  " << endl;
                cout << "\t============================================================================  " << endl;
                cout << "\t|                                                                          |  " << endl;
                cout << "\t|                Rp. 20000                              A                  |  " << endl;
                cout << "\t|                Rp. 50000                              B                  |  " << endl;
                cout << "\t|                Rp. 100000                             C                  |  " << endl;
                cout << "\t|                Rp. 200000                             D                  |  " << endl;
                cout << "\t|                Rp. 500000                             E                  |  " << endl;
                cout << "\t|                                                                          |  " << endl;
                cout << "\t============================================================================  " << endl;
                cout << "\tPilih nominal token(A/B/C/D/E): ";
                char input;
                cin >> input;
                system("CLS");

                switch(input){
                    case 'A':
                    case 'a':
                        nominal[i] = 20000;
                        break;
                    case 'B':
                    case 'b':
                        nominal[i] = 50000;
                        break;
                    case 'C':
                    case 'c':
                        nominal[i] = 100000;
                        break;
                    case 'D':
                    case 'd':
                        nominal[i] = 200000;
                        break;
                    case 'E':
                    case 'e':
                        nominal[i] = 500000;
                        break;
                    default:
                        cout << "\tPilihan tidak valid" << endl;
                        i--;
                        continue;
                }

                // data member menampung total yang harus dibayar
                totalPembelian += nominal[i];
            }

            // ada diskon 5% jika lebih dari 200 ribu
            if(totalPembelian > 200000){
                totalDiskon = 0.05 * totalPembelian;
                totalBayar = totalPembelian - totalDiskon;
            }else{
                totalDiskon = 0;
                totalBayar = totalPembelian - totalDiskon;
            }

            // lanjut ke menu pembayaran
            tampilkanPembayaran();
        }

        // method untuk menampilkan pembayaran
        void tampilkanPembayaran(){
            cout << "\t========================================================================\n";
            cout << "\t                                                                        \n";
            cout << "\t                             PEMBAYARAN                                 \n";
            cout << "\t                                                                        \n";
            cout << "\t========================================================================\n";
            cout << "\t                                                                        \n";
            cout << "\t    BANYAK PEMBELIAN : " << jumlahPembelian <<                         "\n";
            cout << "\t                                                                        \n";
            cout << "\t    TOTAL            : Rp. " << totalPembelian <<                      "\n";
            cout << "\t                                                                        \n";
            cout << "\t    Diskon           : Rp. " << totalDiskon <<                         "\n";
            cout << "\t                                                                        \n";
            cout << "\t    Total bayar      : Rp. " << totalBayar <<                          "\n";
            cout << "\t                                                                        \n";
            cout << "\t========================================================================\n";

            // jika yang dibayar lebih kecil dari total yang harus dibayar
            do {
                cout << "\tDIBAYAR          = Rp. ";
                cin >> diBayar;
                if(diBayar < totalBayar){
                    cout << "\tUang tidak cukup. Silakan masukkan nominal yang cukup." << endl;
                }
            }while(diBayar < totalBayar);

            // kembalian jika yang dibayar lebih besar dari total
            kembalian = diBayar - totalBayar;
            cout << "\tKEMBALIAN        = Rp. " << kembalian << endl;
        }

        // destructor
        ~TokenListrik(){};
};

/*
    kelas untuk membuat struk belanja yang diturunkan dari kelas TokenListrik agar dapat
    menggunakan data member dari kelas induknya
*/
class Receipt : public TokenListrik {
    protected:
        // deklarasi data member untuk keperluan struk
        char namaFile[255] = "";
        int random[5];

    public:
        // method untuk membuat struk
        void printReceipt(){
            // pembuatan nama file dari nama yang kita inputkan di awal
            strcat(namaFile, namaPembeli);
            strcat(namaFile, " - Receipt.txt");

            // pembuatan kode token listrik
            srand(time(0));
            for(int i = 0; i < 5; i++){
                random[i] = 0;
                while(random[i] < 1000){
                    random[i] = rand() % 10000 + 1;
                }
            }

            // menulis file txt untuk struk belanja
            ofstream outf(namaFile);
            outf << "====================================================" << endl;
            outf << "              Token Listrik Kelompok 6" << endl;
            outf << "====================================================\n\n";
            outf << "Nama pembeli         : " << namaPembeli << endl;
            outf << "Banyak Pembelian     : " << jumlahPembelian << endl;
            outf << "TOTAL                : Rp." << totalBayar << endl;
            outf << "TOTAL Bayar          : Rp." << diBayar << endl;
            outf << "Kembalian            : Rp." << kembalian << endl;
            outf << endl;
            outf << "====================================================" << endl;
            outf << "Kode Token           : ";
            for(int i = 0; i < 5; i++){
                if(i < 4){
                    outf << random[i] << "-";
                }else{
                    outf << random[i];
                }
            };
            outf << "\n====================================================";
            outf.close();

            // tampilan akhir dari program
            cout << "\n\n\t=============================================================================================" << endl;
            cout << "\t                                                                                                 " << endl;
            cout << "\t                                                                                                 " << endl;
            cout << "\t  Terima kasih sudah membeli token. Silakan ambil receipt di file : " << namaFile                  << endl;
            cout << "\t                                                                                                 " << endl;
            cout << "\t                                                                                                 " << endl;
            cout << "\t============================================================================================="     << endl;
        }
};

int main(){
    // deklarasi objek dari kelas Receipt
    Receipt token;

    // pemanggilan method dari kelas induk dan turunan
    token.menu();
    token.tokenMenu();
    token.printReceipt();

    return 0;
}