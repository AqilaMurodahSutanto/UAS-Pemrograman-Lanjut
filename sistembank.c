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

//funfsi2
/*
void BacaFile
void SimpanDatakeFIle
void TambahNasabah
void UpdateSaldoNasabah
void HapusNasabah
void TampilkanNasabah
void CariNasabah (Berdasarkan nama/saldo)
void UrutkanNasabah (Berdasarkan id/nama/saldo)
*/

int main (){
    int pilihan;

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
        
        default:
            break;
        }
    } while (pilihan !=6);

    return 0;
    
}
