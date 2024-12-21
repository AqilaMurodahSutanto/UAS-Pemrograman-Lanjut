#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256
#define TEMP_FILE "temp.txt"

// Fungsi untuk membaca file dan menampilkan data nasabah
void bacaFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Tidak dapat membuka file %s\n", filename);
        return;
    }

    printf("\nData Nasabah:\n");
    char line[MAX_LINE];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

// Fungsi untuk menghapus nasabah berdasarkan ID
void hapusNasabah(const char *filename, int idHapus) {
    FILE *file = fopen(filename, "r");
    FILE *tempFile = fopen(TEMP_FILE, "w");

    if (file == NULL || tempFile == NULL) {
        printf("Error: Tidak dapat membuka file.\n");
        if (file) fclose(file);
        if (tempFile) fclose(tempFile);
        return;
    }

    int id;
    char nama[50];
    float saldo;
    int found = 0;

    // Baca file baris demi baris dan tulis ulang ke file sementara kecuali ID yang dihapus
    while (fscanf(file, "%d %s %f\n", &id, nama, &saldo) == 3) {
        if (id == idHapus) {
            found = 1;
        } else {
            fprintf(tempFile, "%d %s %.2f\n", id, nama, saldo);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(filename);            // Hapus file asli
        rename(TEMP_FILE, filename); // Ganti file sementara menjadi file asli
        printf("Nasabah dengan ID %d berhasil dihapus.\n", idHapus);
    } else {
        remove(TEMP_FILE); // Hapus file sementara jika ID tidak ditemukan
        printf("Nasabah dengan ID %d tidak ditemukan.\n", idHapus);
    }
}

int main() {
    const char *filename = "data.txt";
    int pilihan, idHapus;

    do {
        printf("\nMenu:\n");
        printf("1. Baca File\n");
        printf("2. Hapus Nasabah\n");
        printf("3. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                bacaFile(filename);
                break;
            case 2:
                printf("Masukkan ID nasabah yang akan dihapus: ");
                scanf("%d", &idHapus);
                hapusNasabah(filename, idHapus);
                break;
            case 3:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 3);

    return 0;
}
