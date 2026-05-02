#include <stdio.h>
#include "hash.h"
#include "graph.h"

int main() {
    printf("--- Lojistik Yonetim Sistemine Hos Geldiniz ---\n\n");

    // 1. GRAF YAPISINI KURMA
    Graph map;
    initGraph(&map);

    addCity(&map, "Istanbul"); // Indeks: 0
    addCity(&map, "Ankara");   // Indeks: 1
    addCity(&map, "Izmir");    // Indeks: 2
    addCity(&map, "Antalya");  // Indeks: 3
    addCity(&map, "Bursa");    // Indeks: 4

    addEdge(&map, 0, 1, 450); // Istanbul - Ankara
    addEdge(&map, 0, 4, 150); // Istanbul - Bursa
    addEdge(&map, 1, 2, 600); // Ankara - Izmir
    addEdge(&map, 2, 3, 400); // Izmir - Antalya

    // 2. HASH TABLOSUNU KURMA VE VERI GIRISI
    Package hashTable[TABLE_SIZE];
    initHashTable(hashTable);

    printf("Paketler Sisteme Ekleniyor...\n");
    // Odev sarti: En az 5 veri girisi yapilmalidir. 
    // Bilerek cakisacak ID'ler (301 ve 521) verdim ki "Acik Adresleme" calissin.
    insertPackage(hashTable, 105, "Elektronik", 1); 
    insertPackage(hashTable, 213, "Tekstil", 2);    
    insertPackage(hashTable, 301, "Gida", 3);       
    insertPackage(hashTable, 440, "Mobilya", 4);    
    insertPackage(hashTable, 521, "Ilac", 0);       

    // 3. SORGULAMA TESTI
    printf("\n[Test] Hash Tablosunda Arama Yapiliyor:\n");
    searchPackage(hashTable, 301); 

    // 4. GRAF UZERINDE GEZINME TESTI (DFS)
    printf("\n[Test] Lojistik Agi DFS Gezinme Rotalari (Baslangic: Istanbul):\n");
    resetVisited(&map);
    DFS(&map, 0);
    printf("SON\n");

    // 5. BELLEK IZLEME RAPORU
    printMemoryReport(hashTable);

    return 0;
}