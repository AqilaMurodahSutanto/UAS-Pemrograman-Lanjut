#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struktur Nasabah
typedef struct {
    int id;
    char namalengkap[100];
    float saldo;
    char alamat[100];
    char nomorTelepon[15];
    char jenisAkun[20];
    char tanggalLahir[11];
    int statusAkun; // 1 untuk aktif, 0 untuk non-aktif
} Nasabah;

Nasabah nasabah[100];
int jumlahNasabah = 0;

void simpanKeFile() {
    FILE *file = fopen("nasabah.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file!\n");
        return;
    }

    for (int i = 0; i < jumlahNasabah; i++) {
        fprintf(file, "%d,%s,%.2f,%s,%s,%s,%s,%d\n",
                nasabah[i].id, nasabah[i].namalengkap, nasabah[i].saldo,
                nasabah[i].alamat, nasabah[i].nomorTelepon, nasabah[i].jenisAkun,
                nasabah[i].tanggalLahir, nasabah[i].statusAkun);
    }
    fclose(file);
}

void bacaDariFile() {
    FILE *file = fopen("nasabah.txt", "r");
    if (file == NULL) return; // Jika file tidak ada, tidak ada yang dibaca

    while (fscanf(file, "%d,%99[^,],%f,%99[^,],%14[^,],%19[^,],%10[^,],%d\n",
                  &nasabah[jumlahNasabah].id, nasabah[jumlahNasabah].namalengkap,
                  &nasabah[jumlahNasabah].saldo, nasabah[jumlahNasabah].alamat,
                  nasabah[jumlahNasabah].nomorTelepon, nasabah[jumlahNasabah].jenisAkun,
                  nasabah[jumlahNasabah].tanggalLahir, &nasabah[jumlahNasabah].statusAkun) != EOF) {
        jumlahNasabah++;
    }
    fclose(file);
}

// Fungsi untuk mencari nasabah berdasarkan nama
void cariBerdasarkanNama(char *keyword) {
    int ditemukan = 0;  // Menandakan apakah ada hasil pencarian
    printf("+----+----------------+----------------+----------------+----------------+-----------+--------------+------+\n");
    printf("|%-4s| %-15s| %-15s| %-15s| %-15s| %-10s| %-13s|%-5s|\n", 
            "ID", "Nama", "Saldo", "Alamat", "Telepon", "Akun", "Tgl Lahir", "Status");
    printf("+----+----------------+----------------+----------------+----------------+-----------+--------------+------+\n");
    
    for (int i = 0; i < jumlahNasabah; i++) {
        if (strstr(nasabah[i].namalengkap, keyword)) {
            printf("|%-4d| %-15s| %-15.2f| %-15s| %-15s| %-10s| %-13s| %-5d|\n", 
                nasabah[i].id, 
                nasabah[i].namalengkap, 
                nasabah[i].saldo, 
                nasabah[i].alamat, 
                nasabah[i].nomorTelepon, 
                nasabah[i].jenisAkun, 
                nasabah[i].tanggalLahir, 
                nasabah[i].statusAkun);
            ditemukan = 1;
        }
    }
    if (!ditemukan) {
        printf("Tidak ada nasabah dengan nama yang sesuai.\n");
    }
    printf("+----+----------------+----------------+----------------+----------------+-----------+--------------+------+\n");
}


// Fungsi untuk mencari nasabah berdasarkan jenis akun
void cariBerdasarkanJenisAkun(char *keyword) {

    int dataDitemukan = 0; // Menandakan apakah ada data yang ditemukan
    
    // Mencari nasabah berdasarkan jenis akun

     printf("+----+----------------+----------------+----------------+----------------+-----------+--------------+------+\n");
     printf("|%-4s| %-15s| %-15s| %-15s| %-15s| %-10s| %-13s|%-5s|\n", 
             "ID", "Nama", "Saldo", "Alamat", "Telepon", "Akun", "Tgl Lahir", "Status");
    printf("+----+----------------+----------------+----------------+----------------+-----------+--------------+------+\n");
    printf("Data Ditemukan\n");

    for (int i = 0; i < jumlahNasabah; i++) {
        if (strstr(nasabah[i].jenisAkun, keyword)) {
            if (dataDitemukan == 0) {
                printf("Data Ditemukan:\n");
                dataDitemukan = 1; // Menandakan bahwa setidaknya ada satu data yang ditemukan
            }
            // Menampilkan informasi nasabah
            printf("|%-4d| %-15s| %-15.2f| %-15s| %-15s| %-10s| %-13s|%-5s|\n", 
                   nasabah[i].id, nasabah[i].namalengkap, nasabah[i].saldo,
                   nasabah[i].alamat, nasabah[i].nomorTelepon, nasabah[i].jenisAkun,
                   nasabah[i].tanggalLahir, (nasabah[i].statusAkun == 1) ? "Aktif" : "Non-Aktif");
        }
    }
    printf("+----+----------------+----------------+----------------+----------------+-----------+--------------+------+\n");

    // Jika tidak ada data yang ditemukan
    if (dataDitemukan == 0) {
        printf("Data tidak ditemukan dengan jenis akun: %s\n", keyword);
    }
}


// Fungsi untuk mencari nasabah berdasarkan status akun
void cariBerdasarkanStatusAkun(int status) {
    printf("+----+----------------+----------------+----------------+----------------+-----------+--------------+------+\n");
    printf("|%-4s| %-15s| %-15s| %-15s| %-15s| %-10s| %-13s|%-5s|\n", 
            "ID", "Nama", "Saldo", "Alamat", "Telepon", "Akun", "Tgl Lahir", "Status");
    printf("+----+----------------+----------------+----------------+----------------+-----------+--------------+------+\n");
    for (int i = 0; i < jumlahNasabah; i++) {
        if (nasabah[i].statusAkun == status) {
            
            char *statusAkun;
            if (status == 1) {
                statusAkun = "Aktif";
            } else {
                statusAkun = "Non-Aktif";
            }

            // Menampilkan informasi nasabah dengan format yang benar
            printf("|%-4d| %-15s| %-15.2f| %-15s| %-15s| %-10s| %-13s| %-5s|\n", 
                nasabah[i].id, 
                nasabah[i].namalengkap, 
                nasabah[i].saldo, 
                nasabah[i].alamat, 
                nasabah[i].nomorTelepon, 
                nasabah[i].jenisAkun, 
                nasabah[i].tanggalLahir, 
                statusAkun);  // Mengganti status dengan statusAkun (string)
        }
    }
    
}
// mencari id
int cariId(int id) {
    for (int i = 0; i < jumlahNasabah; i++) {
        if (nasabah[i].id == id) return i;
    }
    return -1;
}

void tambahNasabah() {
    int id;
    printf("Masukkan ID: ");
    scanf("%d", &id);

    if (cariId(id) != -1) {
        printf("ID sudah ada!\n");
        return;
    }

    Nasabah baru;
    baru.id = id;
    printf("Masukkan Nama Lengkap: ");
    scanf(" %[^\n]", baru.namalengkap); // Membaca input hingga akhir baris
    printf("Masukkan Saldo: ");
    scanf("%f", &baru.saldo);
    printf("Masukkan Alamat: ");
    scanf(" %[^\n]", baru.alamat); // Membaca input hingga akhir baris
    printf("Masukkan Nomor Telepon: ");
    scanf(" %[^\n]", baru.nomorTelepon); // Membaca input hingga akhir baris
    printf("Masukkan Jenis Akun (Tabungan/Giro): ");
    scanf(" %[^\n]", baru.jenisAkun); // Membaca input hingga akhir baris
    printf("Masukkan Tanggal Lahir (dd/mm/yyyy): ");
    scanf(" %[^\n]", baru.tanggalLahir); // Membaca input hingga akhir baris
    printf("Masukkan Status Akun (1: Aktif, 0: Non-Aktif): ");
    scanf("%d", &baru.statusAkun);


    nasabah[jumlahNasabah++] = baru;
    simpanKeFile();
    printf("Nasabah berhasil ditambahkan!\n");
}

void hapusNasabah() {
    int id;
    printf("Masukkan ID nasabah yang akan dihapus: ");
    scanf("%d", &id);

    int index = cariId(id);
    if (index == -1) {
        printf("Nasabah tidak ditemukan!\n");
        return;
    }

    for (int i = index; i < jumlahNasabah - 1; i++) {
        nasabah[i] = nasabah[i + 1];
    }
    jumlahNasabah--;
    simpanKeFile();
    printf("Nasabah berhasil dihapus!\n");
}

void updateSaldo() {
    int id;
    printf("Masukkan ID nasabah: ");
    scanf("%d", &id);

    int index = cariId(id);
    if (index == -1) {
        printf("Nasabah tidak ditemukan!\n");
        return;
    }

    printf("Masukkan saldo baru: ");
    scanf("%f", &nasabah[index].saldo);
    simpanKeFile();
    printf("Saldo berhasil diperbarui!\n");
}

void tampilkanSemua() {
    printf("+----+----------------+----------------+----------------+----------------+-----------+--------------+------+\n");
    printf("|%-4s| %-15s| %-15s| %-15s| %-15s| %-10s| %-13s|%-5s|\n", 
            "ID", "Nama", "Saldo", "Alamat", "Telepon", "Akun", "Tgl Lahir", "Status");
    printf("+----+----------------+----------------+----------------+----------------+-----------+--------------+------+\n");

    for (int i = 0; i < jumlahNasabah; i++) {
        // Menentukan status berdasarkan nilai statusAkun
        char *status;
        if (nasabah[i].statusAkun == 1) {
            status = "Aktif";
        } else {
            status = "Non-Aktif";
        }

        // Menampilkan data nasabah dalam format tabel
        printf("|%-4d| %-15s| %-15.2f| %-15s| %-15s| %-10s| %-13s| %-5s|\n", 
                nasabah[i].id, 
                nasabah[i].namalengkap, 
                nasabah[i].saldo, 
                nasabah[i].alamat, 
                nasabah[i].nomorTelepon, 
                nasabah[i].jenisAkun, 
                nasabah[i].tanggalLahir, 
                status);
    }

    printf("+----+----------------+----------------+----------------+----------------+-----------+--------------+------+\n");
}

void sortingBerdasarkanId() {
    for (int i = 0; i < jumlahNasabah - 1; i++) {
        for (int j = 0; j < jumlahNasabah - i - 1; j++) {
            if (nasabah[j].id > nasabah[j + 1].id) {
                Nasabah temp = nasabah[j];
                nasabah[j] = nasabah[j + 1];
                nasabah[j + 1] = temp;
            }
        }
    }
    printf("Data berhasil diurutkan berdasarkan ID!\n");
}

void sortingBerdasarkanSaldo() {
    for (int i = 1; i < jumlahNasabah; i++) {
        Nasabah temp = nasabah[i];
        int j = i - 1;

        while (j >= 0 && nasabah[j].saldo > temp.saldo) {
            nasabah[j + 1] = nasabah[j];
            j--;
        }

        nasabah[j + 1] = temp;
    }
    printf("Data berhasil diurutkan berdasarkan saldo!\n");
}

// Fungsi untuk melakukan transfer saldo antar nasabah
void transferSaldo() {
    int idPengirim, idPenerima;
    float jumlahTransfer;

    // Input ID Pengirim dan Penerima
    printf("Masukkan ID Pengirim: ");
    scanf("%d", &idPengirim);
    printf("Masukkan ID Penerima: ");
    scanf("%d", &idPenerima);

    // Mencari ID Pengirim dan Penerima
    int indexPengirim = cariId(idPengirim);
    int indexPenerima = cariId(idPenerima);

    if (indexPengirim == -1) {
        printf("Nasabah Pengirim tidak ditemukan!\n");
        return;
    }

    if (indexPenerima == -1) {
        printf("Nasabah Penerima tidak ditemukan!\n");
        return;
    }

    // Input jumlah transfer
    printf("Masukkan jumlah yang akan ditransfer: ");
    scanf("%f", &jumlahTransfer);

    // Memeriksa apakah saldo pengirim cukup
    if (nasabah[indexPengirim].saldo < jumlahTransfer) {
        printf("Saldo Pengirim tidak cukup untuk melakukan transfer!\n");
        return;
    }

    // Melakukan transfer saldo
    nasabah[indexPengirim].saldo -= jumlahTransfer; // Kurangi saldo pengirim
    nasabah[indexPenerima].saldo += jumlahTransfer; // Tambah saldo penerima

    // Simpan data setelah transfer
    simpanKeFile();

    printf("Transfer berhasil!\n");
    printf("Saldo Pengirim: %.2f\n", nasabah[indexPengirim].saldo);
    printf("Saldo Penerima: %.2f\n", nasabah[indexPenerima].saldo);
}


void menu() {
    int pilihan;
    do {
        printf("\n=== Sistem Manajemen Bank ===\n");
        printf("1. Tambah Nasabah\n");
        printf("2. Hapus Nasabah\n");
        printf("3. Update Saldo\n");
        printf("4. Tampilkan Semua Nasabah\n");
        printf("5. Cari Nasabah\n");
        printf("6. Sorting Berdasarkan ID\n");
        printf("7. Sorting Berdasarkan Saldo\n"); // Opsi baru untuk sorting saldo
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahNasabah();
                break;
            case 2:
                hapusNasabah();
                break;
            case 3:
                updateSaldo();
                break;
            case 4:
                tampilkanSemua();
                break;
            case 5:
                //bacaDariFile();
                printf("Pilih cara pencarian:\n");
                printf("1. Cari Berdasarkan Nama\n");
                printf("2. Cari Berdasarkan Jenis Akun\n");
                printf("3. Cari Berdasarkan Status Akun (1: Aktif, 0: Non-Aktif)\n");
                printf("Masukkan pilihan: ");
                char keyword[100];
                int pilihan;
                int statusAkun;
                scanf("%d", &pilihan);
                switch (pilihan) {
                case 1:
                    printf("Masukkan nama yang dicari: ");
                    scanf(" %[^\n]", keyword);
                    cariBerdasarkanNama(keyword);
                    break;
                case 2:
                    printf("Masukkan jenis akun yang ingin dicari: ");
                    scanf(" %[^\n]", keyword);
                    cariBerdasarkanJenisAkun(keyword);
                    break;
                case 3:
                    printf("Masukkan status akun yang ingin dicari (1: Aktif, 0: Non-Aktif): ");
                    scanf("%d", &statusAkun);
                    cariBerdasarkanStatusAkun(statusAkun);
                    break;
                default:
                    printf("Pilihan tidak valid.\n");
                    }
                break;
            case 6:
                //bacaDariFile();
                sortingBerdasarkanId();
                tampilkanSemua();
                break;
            case 7: 
                //bacaDariFile();
                sortingBerdasarkanSaldo();
                tampilkanSemua();
                break;
            case 8: 
                transferSaldo();
                break;
            case 0:
                printf("Terima kasih telah menggunakan Sistem Manajemen Bank!\n");
                break;
            default:
                printf("Pilihan tidak valid! Silakan coba lagi.\n");
        }
    } while (pilihan != 0);
}

int main() {
    bacaDariFile(); // Membaca data dari file saat program dimulai
    menu();         // Memulai menu interaktif
    return 0;
}
