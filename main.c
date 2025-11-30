
#include <stdio.h>
#include <stdlib.h> // rand() ve srand() icin
#include <time.h>   // rastgele sayi uretimi icin
#include <ctype.h>  // tolower()/toupper() icin eklendi
// --- KARAKTER DURUM DEGISKENLERI
int saglik = 100;    // Saglik (0-100)
int enerji = 100;    // Enerji (0-100)
int yemek_sayisi = 5; // Baslangic yemek sayisi
int siginak_var = 0; // Siginak bulunup bulunmadigi (0/1)
char komut;          // Oyuncu komutunu tutar

// --- KOMUT ACIKLAMALARINI GOSTEREN FONKSIYON ---
void komutlari_acikla() {
    printf("Karakter Tabanli Hayatta Kalma Simulatore Hosgeldin!\n");
    printf("Komutlar:\n");
    printf(" A: Avlan  | S: Siginak ara     | E: Envanter\n");
    printf(" R: Dinlen | F: Tehlike dalgasi | P: Sifreli ilerleme\n");
    printf(" X: Cikis  |\n");
}

// --- DURUM GUNCELLEME VE KONTROL FONKSIYONU  ---
void durumu_goster() {
    printf("\n=== DURUM ===\n");
    printf("Saglik: %d | Enerji: %d \n",
           saglik, enerji);
    printf("=============\n");

    // Olum kontrolu
    if (saglik <= 0) {
        printf("\n*** KARAKTER HAYATTA KALAMADI! OYUN BITTI. ***\n");
        exit(0); // Programi sonlandir
    }
}

// --- ENVANTER GORUNTULEME FONKSIYONU  ---
void envanteri_goster() {
    printf("\n--- ENVANTER DURUMU ---\n");
    printf("Yemek: %d adet\n", yemek_sayisi);
    printf("Siginak Durumu: %s\n", siginak_var ? "Bulundu (GUVENDE)" : "Bulunmadi");
    printf("-----------------------\n");
}



// Max Min deger kontrolu (Aritmetik Kontrol)
void deger(){
 if (saglik > 100) saglik = 100;
if (enerji > 100) enerji = 100;
  if (saglik < 0) saglik = 0;
 if (enerji < 0) enerji = 0;
}

// --- ANA OYUN FONKSIYONU ---
int main() {
    // Rastgele sayi uretici icin tohumlama
    srand(time(0)); 

    printf("--- KARAKTER TABANLI HAYATTA KALMA SIMULATORU ---\n");
    komutlari_acikla(); // Komutlari goster
    durumu_goster();

    // 1. DO-WHILE dongusu: Ana komut dinleme dongusu
    do {
        printf("\nKomut girin (A, S, R, E, F, P, X): ");
        scanf(" %c", &komut); // Komut al

        // 2. SWITCH-CASE: Komut Sistemini Yonetme
        switch (komut) {
            case 'A': // Avlan
            case 'a':
                if (enerji <=10){
                    printf("Avlanmak icin yeterli enerjin yok");
                    break;}
                // Yemek bulma ihtimali (Mantiksal Operatorler)
                if ((enerji > 10) && (rand() % 3 == 0)) {
                    printf("Avlanmaya gidiliyor...\n");
                    printf("Basarili av! 3 adet yemek bulundu.\n");
                    enerji -= 10;
                    yemek_sayisi += 3;

                } 
                // Yaralanma/Basarisizlik Kontrolu
                 else if ((enerji > 10) && (rand() % 3 == 0)) {
                    printf("Avlanmaya gidiliyor...\n");
                    printf("Avlanirken yaralandiniz/basarisiz oldunuz. Saglik: -10.\n");
                    enerji -= 10;
                    saglik -= 10;
                    
                } 

                else {
                    printf("Avlanmaya gidiliyor...\n");
                    printf("Avlanma basarisiz oldu, yiyecek bulunamadi.\n");
                    enerji -= 10;
                    
                }
                deger();
                break;

            case 'S': // Siginak Ara
            case 's':
                if (siginak_var) {
                    printf("Zaten bir siginaginiz var. Bosa enerji harcamayin.\n");
                    break;
                }
                
                if (enerji <20){
                    printf("Siginak aramak icin yeterli enerjin yok");
                    break;
				}
				
                printf("Siginak araniyor...\n");
                
                // Siginak Bulma Ihtimali (IF-ELSE Yapilari)
                if ((rand() % 2 == 0) && (enerji >= 20)) {
                    siginak_var = 1; 
                    enerji -= 5;
                    printf("Genis ve guvenli bir siginak bulundu!\n");
                } 
                else if ((rand() % 3 == 0) || (enerji >= 20)) {
                    printf("Siginak bulunamadi, arama sirasinda yoruldunuz.\n");
                    enerji -= 10;
                } 

                else {
                    printf("Siginak bulunamadi, aramaya devam edin.\n");
                }
                deger();
                break;

            case 'R': // Dinlen
            case 'r':
                printf("Dinleniliyor...\n");
                
                // Dinlenme sirasinda saglik ve enerji artisi (Aritmetik Islemler)
                if (yemek_sayisi > 0) {
                    saglik += 15;   
                    enerji += 20;   
                    yemek_sayisi -= 1; 
                    printf("Biraz yemek yediniz ve dinlendiniz. Saglik: +15, Enerji: +20.\n");
                } else {
                    enerji += 5; 
                    printf("Yemek yiyemediginiz icin yavas dinleniyorsunuz. Enerji: +5.\n");
                }
                 deger();
                break;

            case 'E': // Envanter Goruntule (Yeni Fonksiyon Cagrisi)
            case 'e':
                envanteri_goster();
                break;
            
            case 'F': // Tehlike Serisi (FOR Dongusu)
            case 'f': {
                printf("!!! BOLGEDE TEHLIKE SERISI BASLADI !!!\n");
                int tehlike_sayisi = 3;
                
                // 3. FOR Dongusu: Tehlike dalgasi simulasyonu
                int i;
                for (i=1 ; i <= tehlike_sayisi; i++) {
                    printf("--- Tehlike Dalgasi %d ---\n", i);
                    
                    // Rastgele tehlike kontrolu
                    if (rand() % 4 == 0) { 
                        saglik -= (rand() % 10 + 5); 
                        printf("Saldiriya ugradiniz! Saglik dustu. ");
                    } else if (rand() % 3 == 0 && enerji > 20) {
                        enerji -= 10;
                        printf("Hizli hareket etmek zorunda kaldiniz. Enerji dustu.");
                    } else {
                        printf("Tehlikeden basariyla kacinildi.\n");
                    }

                    // Her dongu sonunda saglik kontrolu
                    if (saglik <= 0) break;
                }
                printf("!!! TEHLIKE SERISI SONA ERDI !!!\n");
                deger();
                break;
            }

            case 'P': // Sifreli Ilerleme (DO-WHILE Dogrulama Dongusu)
            case 'p': {
                char dogru_sifre ='A' + (rand() % 14);
                char girilen_sifre;
                int deneme_sayaci = 0;
                
                

                // 4. DO-WHILE Dongusu: Dogru sifre girilene kadar devam et
                do {
                    printf("Engeli asmak icin harf girin (A ile N arasi): ");
                    scanf(" %c", &girilen_sifre);
                    girilen_sifre = toupper(girilen_sifre);
                    deneme_sayaci++;
                    
                    if (girilen_sifre == dogru_sifre) {
                        printf("Engeli basariyla astiniz! Enerji: +10.\n");
                        
                        enerji += 10;
                    }
                    
                    else if (girilen_sifre < dogru_sifre) {
                        printf("Yanlis Sifre! Alfabetik siraya gore ileride bir harf dene.");
                        printf("\nkalan deneme: %d \n\n",5-deneme_sayaci);
                    }
                    
                       else if (girilen_sifre > dogru_sifre) {
                        printf("Yanlis Sifre! Alfabetik siraya gore geride bir harf dene.");
                        printf("\nkalan deneme: %d \n\n",5-deneme_sayaci);
                    }

                    
                    // 5 deneme hakki kontrolu
                    if (deneme_sayaci >= 5 && girilen_sifre != dogru_sifre) {
                        printf("\nCok fazla yanlis deneme. Engel asilamadi.\n");
                        saglik -= 5;
                        deger();
                        break; // Donguden cik
                    
                    }

                } while (girilen_sifre != dogru_sifre);
                break;
            }
            
            case 'X': // Cikis
            case 'x':
                printf("Simulatorden cikiliyor. Hoscakalin.\n");
                break;

            default:
                printf("Gecersiz komut. Lutfen gecerli bir komut girin.\n");
                break;
        }

         durumu_goster();
        

    } while (komut != 'X' && komut != 'x'); // Cikis komutu verilmedikce simulasyon devam

    return 0;
}
