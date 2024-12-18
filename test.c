#include <stdio.h>
#include <string.h>

struct Tanggal
{
    int tgl, bln, thn;
};

struct Rekening
{
    int No_rek;
    char Nama_rek[10];
    char Nama[25];
    long Saldo;
    struct Tanggal Catatan_Rekening;
};

int main()
{
    struct Rekening Rek1;

    printf("Masukkan No Rekening:\n");
    scanf("%d", &Rek1.No_rek);
    printf("Masukkan Nama Rekening:\n");
    scanf("%s", Rek1.Nama_rek);
    printf("Masukkan Nama Anda:\n");
    scanf("%s", Rek1.Nama);
    printf("Masukkan Jumlah Saldo:\n");
    scanf("%ld", &Rek1.Saldo);

    printf("Info rekening Anda... \n");

    printf("No Rek: %d\n", Rek1.No_rek);
    printf("Tipe Rek: %s\n", Rek1.Nama_rek); // Cetak string Tipe_rek
    printf("Nama: %s\n", Rek1.Nama);
    printf("Saldo: %ld\n", Rek1.Saldo);
}