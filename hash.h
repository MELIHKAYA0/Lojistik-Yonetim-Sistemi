#ifndef HASH_H
#define HASH_H

#define TABLE_SIZE 11 // Çakışmaları azaltmak için asal sayı

typedef struct {
    int package_id;       
    char content[50];     
    int destination_city; 
    int is_empty;         
} Package;

void initHashTable(Package* hashTable);
int hashFunctionTipA(int key); 
void insertPackage(Package* hashTable, int id, const char* content, int city_idx); 
void searchPackage(Package* hashTable, int id);
void printMemoryReport(Package* hashTable);

#endif