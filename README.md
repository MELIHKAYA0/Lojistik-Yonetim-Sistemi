# Lojistik Ağı ve Paket Takip Sistemi

Bu proje, "Veri Yapıları ve Algoritmalar" dersi final değerlendirme ödevi kapsamında C programlama dili ile geliştirilmiştir. 

Projede bir lojistik firmasının şehirler arası bağlantılarının yönetildiği bir **Graf (Graph)** yapısı ile paket bilgilerinin hızlıca sorgulandığı bir **Hash Tablosu (Hash Table)** yapısı hibrit olarak kullanılmıştır.

## 📌 Sistem Özellikleri ve Algoritmalar
Sistemdeki algoritmalar, ödev yönergesine uygun olarak öğrenci numarasına (5250505034) göre belirlenmiştir:

* **Hash Fonksiyonu:** Tip A (Modulo Yöntemi) kullanılmıştır.
* **Çakışma (Collision) Çözümü:** Açık Adresleme - Doğrusal Yoklama (Linear Probing) kullanılmıştır.
* **Graf Gezinme Algoritması:** DFS (Derinlik Öncelikli Arama) kullanılarak rotalar listelenmiştir.

## 📂 Dosya Yapısı
Proje, mantıksal katmanlarına göre çoklu dosya mimarisiyle tasarlanmıştır:
* `hash.h` & `hash.c` -> Paket yapıları ve Hash algoritması
* `graph.h` & `graph.c` -> Şehir ağı ve DFS algoritması
* `main.c` -> Ana kontrol ve test modülü
