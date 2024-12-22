#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id;                 // ID Nasabah
    char namalengkap[100];  // Nama Nasabah
    float saldo;            // Saldo Akun
    char alamat[100];       // Alamat Nasabah
    char nomorTelepon[15];  // Nomor Telepon
    char jenisAkun[10];     // Jenis Akun (Tabungan/Giro)
    char tanggalLahir[11];  // Tanggal Lahir (format: dd/mm/yyyy)
    int statusAkun;         // Status Akun (misalnya, 1 untuk aktif, 0 untuk non-aktif)
} Nasabah;

Nasabah nasabah[100];
int jumlahNasabah = 0;

void BacaData() {
    FILE *file = fopen("data-nasabah.txt", "r");
    if (file == NULL) {
        printf("File tidak ditemukan, data tidak dapat dimuat.\n");
        return;
    }
    char buffer[256];
    printf("Mulai membaca data...\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        sscanf(buffer, "%d %s %f %[^\n] %s %s %s %d",
               &nasabah[jumlahNasabah].id,
               nasabah[jumlahNasabah].namalengkap,
               &nasabah[jumlahNasabah].saldo,
               nasabah[jumlahNasabah].alamat,
               nasabah[jumlahNasabah].nomorTelepon,
               nasabah[jumlahNasabah].jenisAkun,
               nasabah[jumlahNasabah].tanggalLahir,
               &nasabah[jumlahNasabah].statusAkun);
        jumlahNasabah++;
    }

    fclose(file);
}

void SimpanData() {
    FILE *file = fopen("data-nasabah.txt", "w");
    if (file == NULL) {
        printf("Gagal menyimpan data.\n");
        return;
    }

    for (int i = 0; i < jumlahNasabah; i++) {
        fprintf(file, "%d %s %.2f %s %s %s %s %d\n", 
                nasabah[i].id,
                nasabah[i].namalengkap,
                nasabah[i].saldo,
                nasabah[i].alamat,
                nasabah[i].nomorTelepon,
                nasabah[i].jenisAkun,
                nasabah[i].tanggalLahir,
                nasabah[i].statusAkun);
    }

    fclose(file);
}

void tambahNasabah() {
    if (jumlahNasabah >= 100) {
        printf("Jumlah nasabah sudah mencapai batas maksimum.\n");
        return;
    }

    Nasabah newNasabah;
    printf("Masukkan ID Nasabah: ");
    scanf("%d", &newNasabah.id);
    getchar();  // clear the newline character left by scanf

    printf("Masukkan Nama Lengkap: ");
    fgets(newNasabah.namalengkap, 100, stdin);
    newNasabah.namalengkap[strcspn(newNasabah.namalengkap, "\n")] = '\0'; // remove newline character

    printf("Masukkan Saldo: ");
    scanf("%f", &newNasabah.saldo);
    getchar();

    printf("Masukkan Alamat: ");
    fgets(newNasabah.alamat, 100, stdin);
    newNasabah.alamat[strcspn(newNasabah.alamat, "\n")] = '\0';

    printf("Masukkan Nomor Telepon: ");
    fgets(newNasabah.nomorTelepon, 15, stdin);
    newNasabah.nomorTelepon[strcspn(newNasabah.nomorTelepon, "\n")] = '\0';

    printf("Masukkan Jenis Akun (Tabungan/Giro): ");
    fgets(newNasabah.jenisAkun, 20, stdin);
    newNasabah.jenisAkun[strcspn(newNasabah.jenisAkun, "\n")] = '\0';

    printf("Masukkan Tanggal Lahir (dd/mm/yyyy): ");
    fgets(newNasabah.tanggalLahir, 11, stdin);
    newNasabah.tanggalLahir[strcspn(newNasabah.tanggalLahir, "\n")] = '\0';

    printf("Masukkan Status Akun (1 untuk aktif, 0 untuk non-aktif): ");
    scanf("%d", &newNasabah.statusAkun);

    nasabah[jumlahNasabah] = newNasabah;
    jumlahNasabah++;
    SimpanData();
    printf("Nasabah berhasil ditambahkan!\n");
}

void hapusNasabah() {
    int id;
    printf("Masukkan ID Nasabah yang ingin dihapus: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < jumlahNasabah; i++) {
        if (nasabah[i].id == id) {
            for (int j = i; j < jumlahNasabah - 1; j++) {
                nasabah[j] = nasabah[j + 1];
            }
            jumlahNasabah--;
            SimpanData();
            printf("Nasabah dengan ID %d telah dihapus.\n", id);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Nasabah dengan ID %d tidak ditemukan.\n", id);
    }
}

void lihatNasabah() {
    if (jumlahNasabah == 0) {
        printf("Tidak ada data nasabah.\n");
        return;
    }

    printf("+----+----------------+----------------+----------------+----------------+-----------+--------------+------+\n");
    printf("|%-4s| %-15s| %-15s| %-15s| %-15s| %-10s| %-13s|%-5s|\n", 
           "ID", "Nama", "Saldo", "Alamat", "Telepon", "Akun", "Tgl Lahir", "Status");
    printf("+----+----------------+----------------+----------------+----------------+-----------+--------------+------+\n");
    for (int i = 0; i < jumlahNasabah; i++) {
        printf("|%-4d| %-15s| %-15.2f| %-15s| %-15s| %-10s| %-13s| %-5d|\n", 
               nasabah[i].id, 
               nasabah[i].namalengkap, 
               nasabah[i].saldo, 
               nasabah[i].alamat, 
               nasabah[i].nomorTelepon, 
               nasabah[i].jenisAkun, 
               nasabah[i].tanggalLahir, 
               nasabah[i].statusAkun);
    }
    printf("+----+----------------+----------------+----------------+----------------+-----------+--------------+------+\n");
}


int main() {
    printf("Program dimulai...\n");
    // Pointer ke file
    FILE *file = fopen("data-nasabah.txt", "r"); // Buka file dalam mode tambah
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return 1;
    }
    printf("File berhasil dibuka.\n");

    BacaData();

    int pilihan;
    do {
        printf("\nMenu Sistem Manajemen Bank\n");
        printf("1. Tambah Nasabah\n");
        printf("2. Hapus Nasabah\n");
        printf("3. Lihat Nasabah\n");
        printf("4. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahNasabah();
                break;
            case 2:
                hapusNasabah();
                break;
            case 3:
                lihatNasabah();
                break;
            case 4:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
        }
    } while (pilihan != 4);

    // Menutup file setelah operasi selesai
    fclose(file);

    return 0;
}
