#include <stdio.h>
#include <string.h>
#include "hash.h"

void initHashTable(Package* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].is_empty = 1;
    }
}

// Tip A Hash Fonksiyonu: Basit Modulo Yöntemi
int hashFunctionTipA(int key) {
    return key % TABLE_SIZE;
}

// Açık Adresleme (Linear Probing) ile Çakışma Çözümü
void insertPackage(Package* hashTable, int id, const char* content, int city_idx) {
    int index = hashFunctionTipA(id);
    int original_index = index;
    int i = 0;

    while (!hashTable[index].is_empty) {
        if (hashTable[index].package_id == id) {
            printf("Hata: %d ID'li paket zaten var.\n", id);
            return;
        }
        i++;
        index = (original_index + i) % TABLE_SIZE;
        if (i == TABLE_SIZE) {
            printf("Hata: Hash tablosu dolu!\n");
            return;
        }
    }

    hashTable[index].package_id = id;
    strcpy(hashTable[index].content, content);
    hashTable[index].destination_city = city_idx;
    hashTable[index].is_empty = 0;
    printf("Paket eklendi -> ID: %d, Hash Index: %d\n", id, index);
}

void searchPackage(Package* hashTable, int id) {
    int index = hashFunctionTipA(id);
    int original_index = index;
    int i = 0;

    while (!hashTable[index].is_empty) {
        if (hashTable[index].package_id == id) {
            printf(">> Paket Bulundu! ID: %d | Icerik: %s | Sehir Indeksi: %d\n",
                   hashTable[index].package_id, hashTable[index].content, hashTable[index].destination_city);
            return;
        }
        i++;
        index = (original_index + i) % TABLE_SIZE;
        if (i == TABLE_SIZE) break;
    }
    printf(">> Hata: %d ID'li paket bulunamadi.\n", id);
}

// Odevde istenen Bellek Izleme Raporu
void printMemoryReport(Package* hashTable) {
    printf("\n=== BELLEK IZLEME RAPORU ===\n");
    printf("Index\t| Bellek Adresi\t\t| Paket ID\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!hashTable[i].is_empty) {
            printf("%d\t| %p\t| %d\n", i, (void*)&hashTable[i], hashTable[i].package_id);
        }
    }
    printf("============================\n");
}