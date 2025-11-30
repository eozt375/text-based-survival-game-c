# text-based-survival-game-c

KARAKTER TABANLI HAYATTA KALMA SİMÜLASYONU – KOD MANTIĞI AÇIKLAMASI

1. GENEL YAPI
Program, karakterin hayatta kalmasını sağlayan basit bir komut tabanlı simülasyondur. Sağlık, enerji, yemek sayısı ve sığınak durumunu izleyen değişkenler kullanılır. Oyuncu komutlar vererek hayatta kalmaya çalışır.

2. ANA DEĞİŞKENLER
- saglik: Karakterin can miktarı (0–100)
- enerji: Karakterin hareket enerjisi (0–100)
- yemek_sayisi: Avlanınca artan, dinlenirken tüketilen kaynak
- siginak_var: Sığınak bulunup bulunmadığını tutar (0 veya 1)
- komut: Kullanıcıdan alınan karakter komutu

3. TEMEL FONKSİYONLAR
• komutlari_acikla():
  Oyuncuya kullanılabilecek komutları listeler.

• durumu_goster():
  Sağlık ve enerji değerlerini ekrana yazdırır.
  Sağlık 0 olursa oyun sona erer.

• envanteri_goster():
  Yemek ve sığınak durumunu ekrana yazdırır.

• deger():
  Sağlık ve enerji değerlerini 0 ile 100 arasında tutar.

4. ANA PROGRAM AKIŞI (main)
- srand(time(0)) ile rastgele mekanik aktif edilir.
- Kullanıcıdan sürekli olarak bir komut istenir.

5. KOMUTLARIN YAPISI
A) Avlanma (A)
  - Enerji 10’dan düşükse avlanamaz.
  - %33 ihtimalle yemek bulunur.
  - %33 ihtimalle yaralanma olur.
  - Aksi halde av başarısız olur.

B) Sığınak Arama (S)
  - Zaten sığınak varsa tekrar arayamaz.
  - Enerji 10’dan azsa arama yapılamaz.
  - Enerji > 50 ise %50 ihtimalle sığınak bulunur.
  - Enerji < 30 ise başarısızlık şansı artar.

C) Dinlenme (R)
  - Yemek varsa sağlık +15, enerji +20.
  - Yemek yoksa enerji +5.

D) Envanter (E)
  - Yemek ve sığınak bilgilerini gösterir.

E) Tehlike Dalgası (F)
  - Üç aşamalı bir döngü içinde rastgele zarar veya enerji kaybı oluşur.

F) Şifreli Geçit (P)
  - Rastgele seçilmiş bir harf bulunmaya çalışılır.
  - Oyuncunun 5 deneme hakkı vardır.
  - Doğru tahminde enerji +10.

G) Çıkış (X)
  - Simülasyon sonlanır.

6. DÖNGÜ SİSTEMLERİ
Program birçok farklı döngü içerir:
- do–while: Ana oyun döngüsü ve şifre bulma bölümü
- for: Tehlike dalgaları
- if–else: Avlanma, sığınak arama ve dinlenme mantığı

Bu yapı kullanıcıya basit ama dinamik bir hayatta kalma deneyimi sunar.
