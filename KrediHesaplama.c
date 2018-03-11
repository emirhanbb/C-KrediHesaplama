#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// aylikOdemeHesapla adýnda bir fonksiyon oluþturduk.
double aylikOdemeHesapla(double krediMiktari,double faizOran,double taksitSayisi){
	int taksitsayac; //taksit sayýsýný sayan sayaç.
	double kalanAnapara,odenenFaiz,odenenAnapara;
	// Aþaðýdaki satýrda taksit tutarýný hesaplayan iþlem mevcut.
	double taksitTutari=(krediMiktari*(faizOran/100)*pow(1+(faizOran/100),taksitSayisi))/(pow(1+(faizOran/100),taksitSayisi)-1);
	printf("Taksit No\tTaksit Tutari\tOdenen Faiz Tutari\tOdenen Ana Para Tutari\tKalan Ana Para Borcu\n");
	// Aþaðýdaki döngü sayesinde iþlem sürekli dönüyor.
	for(taksitsayac=1; taksitsayac<=taksitSayisi; taksitsayac++){
	    kalanAnapara=krediMiktari; /* Ýlk olarak kullanýcýdan alýnan kredi miktarý hesaplanacak daha sonraki iþlemlerde kalan anapara 
		üzerinden hesaplanacak*/
	    odenenFaiz=(kalanAnapara*faizOran)/100; //Bu satýrda ödenen faiz miktarýný hesaplýyoruz.
	    odenenAnapara= taksitTutari-odenenFaiz; //Bu satýrda ödenen ana para tutarýný hesaplýyoruz.
	    kalanAnapara=krediMiktari-odenenAnapara;//Bu satýrda kalan ana para tutarýný hesaplýyoruz.
	    krediMiktari=kalanAnapara; // Burada da yukarýda yaptýðýmýz iþlemin tam tersini yapýyor ve bir nevi döngü oluþturmuþ oluyoruz.
	    // Aþaðýdaki satýrda bütün iþlemleri ekrana yazdýrýyoruz.
		printf("%d\t\t%8.2lf\t\t%.2lf\t\t\t%.2lf\t\t\t%.2f\n", taksitsayac, taksitTutari, odenenFaiz, odenenAnapara, kalanAnapara);
    }
    printf("\n");
printf("Aylik Odemeniz:\t%.2lf\n",taksitTutari); //Aylýk kaç tl ödeme yaptýðýmýz yani taksit tutarý.
printf("Toplam Kredi Odemesi:\t%.2lf",(taksitSayisi*taksitTutari)); // Toplam faizlerle beraber kaç tl para ödediðimiz.
	
}

int main() {
	double krediMiktari; // ne kadar kredi alýnacaðý
	double faizOran; // yüzde kaç faiz olacaðý
	double taksitSayisi; // kaç taksit olacaðý
	//Kullanýcýdan kredi miktarýný alýyoruz.
	printf("Kredi miktarini giriniz: ");
	scanf("%lf",&krediMiktari);
	//Kullanýcýdan faiz oranýný alýyoruz.
	printf("Faiz oranini giriniz: ");
	scanf("%lf",&faizOran);
	//Kullanýcýdan taksit sayýsýný alýyoruz.
	printf("Taksit sayisini giriniz: ");
	scanf("%lf",&taksitSayisi);	
aylikOdemeHesapla(krediMiktari,faizOran,taksitSayisi); //Burada fonksiyonu ekrana çaðýrýyoruz.
	
	return 0;
}
