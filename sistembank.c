#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int id;                 // ID Nasabah
    char namalengkap[100];  // Nama Nasabah
    float saldo;            // Saldo Akun
    char alamat[100];       // Alamat Nasabah
    char nomorTelepon[15];  // Nomor Telepon
    char jenisAkun[20];     // Jenis Akun (Tabungan/Giro)
    char tanggalLahir[11];  // Tanggal Lahir (format: dd/mm/yyyy)
    int statusAkun;         // Status Akun (misalnya, 1 untuk aktif, 0 untuk non-aktif)
}Nasabah;

Nasabah nasabah[100];
int jumlahNasabah = 0;

void TambahNasabah()
{
    printf("Masukkan ID Nasabah: ");
    scanf("%d", &nasabah[jumlahNasabah].id);
    getchar();
    printf("Masukkan Nama Lengkap: ");
    fgets(nasabah[jumlahNasabah].namalengkap, 100, stdin);
    nasabah[jumlahNasabah].namalengkap[strcspn(nasabah[jumlahNasabah].namalengkap, "\n")] = '\0';
    printf("Masukkan Saldo: ");
    scanf("%f", &nasabah[jumlahNasabah].saldo);
    getchar();
    printf("Masukkan Alamat: ");
    fgets(nasabah[jumlahNasabah].alamat, 100, stdin);
    nasabah[jumlahNasabah].alamat[strcspn(nasabah[jumlahNasabah].alamat, "\n")] = '\0';
    printf("Masukkan Nomor Telepon: ");
    fgets(nasabah[jumlahNasabah].nomorTelepon, 15, stdin);
    nasabah[jumlahNasabah].nomorTelepon[strcspn(nasabah[jumlahNasabah].nomorTelepon, "\n")] = '\0';
    printf("Masukkan Jenis Akun (Tabungan/Giro): ");
    fgets(nasabah[jumlahNasabah].jenisAkun, 20, stdin);
    nasabah[jumlahNasabah].jenisAkun[strcspn(nasabah[jumlahNasabah].jenisAkun, "\n")] = '\0';
    printf("Masukkan Tanggal Lahir (dd/mm/yyyy): ");
    fgets(nasabah[jumlahNasabah].tanggalLahir, 11, stdin);
    nasabah[jumlahNasabah].tanggalLahir[strcspn(nasabah[jumlahNasabah].tanggalLahir, "\n")] = '\0';
    printf("Masukkan Status Akun (1: Aktif, 0: Non-Aktif): ");
    scanf("%d", &nasabah[jumlahNasabah].statusAkun);

    jumlahNasabah++;
    printf("Nasabah berhasil ditambahkan!\n");
}
//funfsi2
/*
void BacaFile
void SimpanDatakeFIle
void BackupData
void restoreData
void TambahNasabah
void HapusNasabah
void UpdateSaldoNasabah
void TampilkanNasabah
void CariNasabah (Berdasarkan nama)
void CariNasabah (Berdasarkan saldo)
void UrutkanNasabah (Berdasarkan id)
void UrutkanNasabah (Berdasarkan Nama)
*/

void RestoreData (Nasabah data[], int *jumlahnasabah){

}

void UrutkanNasabahID() {
    for (int i = 1; i < jumlahNasabah; i++) {
        Nasabah key = nasabah[i];  
        int j = i - 1;

        while (j >= 0 && nasabah[j].id > key.id) {
            nasabah[j + 1] = nasabah[j];
            j = j - 1;
        }

        nasabah[j + 1] = key;  
    }
    printf("Data nasabah berhasil diurutkan berdasarkan ID.\n");
}


int main (){
    int pilihan;
    int pil_sort;

    printf("==========Sistem Manajemen Bank===========\n");
    printf("\nMenu Utama:\n");
    printf("1. Tambah Data Nasabah\n");
    printf("2. Tampilkan Semua Data Nasabah\n");
    printf("3. Update Data Saldo\n");
    printf("4. Cari Nasabah (ID/Nama/saldo)\n");
    printf("5. Urutkan Data Nasabah\n");
    printf("6. Keluar\n");
    printf("Pilih Opsi: ");
    scanf("%d", &pilihan);

    do
    {
        switch (pilihan)
        {
        case 1:
            /* code */
            break;
        case 5: 
        printf("\nUrutkan berdasarkan ID atau Nama (1 = ID, 2 = Nama): ");
        scanf("%d", &pil_sort);  
        if (pil_sort == 1) {
            UrutkanNasabahID(nasabah, jumlahNasabah);  
        } else if (pil_sort == 2) {
             // Fungsi untuk mengurutkan berdasarkan Nama
        } else {
            printf("Pilihan tidak valid.\n");
        }
        break;

        default:
            break;
        }
    } while (pilihan !=6);

    return 0;
    
}
