# text-based-survival-game-c

KARAKTER TABANLI HAYATTA KALMA SİMÜLASYONU – KOD MANTIĞI AÇIKLAMASI
1. GENEL YAPI
Program, karakterĜn hayatta kalmasını sağlayan basĜt bĜr komut tabanlı sĜmülasyondur. Sağlık,
enerjĜ, yemek sayısı ve sığınak durumunu Ĝzleyen değĜşkenler kullanılır. Oyuncu komutlar vererek
hayatta kalmaya çalışır.
2. ANA DEĞİŞKENLER
- saglĜk: KarakterĜn can mĜktarı (0–100)
- enerjĜ: KarakterĜn hareket enerjĜsĜ (0–100)
- yemek_sayĜsĜ: Avlanınca artan, dĜnlenĜrken tüketĜlen kaynak
- sĜgĜnak_var: Sığınak bulunup bulunmadığını tutar (0 veya 1)
- komut: Kullanıcıdan alınan karakter komutu
3. TEMEL FONKSİYONLAR
• komutlarĜ_acĜkla():
 Oyuncuya kullanılabĜlecek komutları lĜsteler.
• durumu_goster():
 Sağlık ve enerjĜ değerlerĜnĜ ekrana yazdırır.
 Sağlık 0 olursa oyun sona erer.
• envanterĜ_goster():
 Yemek ve sığınak durumunu ekrana yazdırır.
• deger():
 Sağlık ve enerjĜ değerlerĜnĜ 0 Ĝle 100 arasında tutar.
4. ANA PROGRAM AKIŞI (maĜn)
- srand(tĜme(0)) Ĝle rastgele mekanĜk aktĜf edĜlĜr.
- Kullanıcıdan süreklĜ olarak bĜr komut ĜstenĜr.
5. KOMUTLARIN YAPISI
A) Avlanma (A)
 - EnerjĜ 10’dan düşükse avlanamaz.
 - %33 ĜhtĜmalle yemek bulunur.
 - %33 ĜhtĜmalle yaralanma olur.
 - AksĜ halde av başarısız olur.
B) Sığınak Arama (S)
 - Zaten sığınak varsa tekrar arayamaz.
 - EnerjĜ 10’dan azsa arama yapılamaz.
 - EnerjĜ > 50 Ĝse %50 ĜhtĜmalle sığınak bulunur.
 - EnerjĜ < 30 Ĝse başarısızlık şansı artar.
C) DĜnlenme (R)
 - Yemek varsa sağlık +15, enerjĜ +20.
 - Yemek yoksa enerjĜ +5.
D) Envanter (E)
 - Yemek ve sığınak bĜlgĜlerĜnĜ gösterĜr.
E) TehlĜke Dalgası (F)
 - Üç aşamalı bĜr döngü ĜçĜnde rastgele zarar veya enerjĜ kaybı oluşur.
F) ŞĜfrelĜ GeçĜt (P)
 - Rastgele seçĜlmĜş bĜr harf bulunmaya çalışılır.
 - Oyuncunun 5 deneme hakkı vardır.
 - Doğru tahmĜnde enerjĜ +10.
G) Çıkış (X)
 - SĜmülasyon sonlanır.
6. DÖNGÜ SİSTEMLERİ
Program bĜrçok farklı döngü ĜçerĜr:
- do–whĜle: Ana oyun döngüsü ve şĜfre bulma bölümü
- for: TehlĜke dalgaları
- Ĝf–else: Avlanma, sığınak arama ve dĜnlenme mantığı
Bu yapı kullanıcıya basĜt ama dĜnamĜk bĜr hayatta kalma deneyĜmĜ sunar.
