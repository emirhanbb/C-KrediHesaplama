#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// aylikOdemeHesapla ad�nda bir fonksiyon olu�turduk.
double aylikOdemeHesapla(double krediMiktari,double faizOran,double taksitSayisi){
	int taksitsayac; //taksit say�s�n� sayan saya�.
	double kalanAnapara,odenenFaiz,odenenAnapara;
	// A�a��daki sat�rda taksit tutar�n� hesaplayan i�lem mevcut.
	double taksitTutari=(krediMiktari*(faizOran/100)*pow(1+(faizOran/100),taksitSayisi))/(pow(1+(faizOran/100),taksitSayisi)-1);
	printf("Taksit No\tTaksit Tutari\tOdenen Faiz Tutari\tOdenen Ana Para Tutari\tKalan Ana Para Borcu\n");
	// A�a��daki d�ng� sayesinde i�lem s�rekli d�n�yor.
	for(taksitsayac=1; taksitsayac<=taksitSayisi; taksitsayac++){
	    kalanAnapara=krediMiktari; /* �lk olarak kullan�c�dan al�nan kredi miktar� hesaplanacak daha sonraki i�lemlerde kalan anapara 
		�zerinden hesaplanacak*/
	    odenenFaiz=(kalanAnapara*faizOran)/100; //Bu sat�rda �denen faiz miktar�n� hesapl�yoruz.
	    odenenAnapara= taksitTutari-odenenFaiz; //Bu sat�rda �denen ana para tutar�n� hesapl�yoruz.
	    kalanAnapara=krediMiktari-odenenAnapara;//Bu sat�rda kalan ana para tutar�n� hesapl�yoruz.
	    krediMiktari=kalanAnapara; // Burada da yukar�da yapt���m�z i�lemin tam tersini yap�yor ve bir nevi d�ng� olu�turmu� oluyoruz.
	    // A�a��daki sat�rda b�t�n i�lemleri ekrana yazd�r�yoruz.
		printf("%d\t\t%8.2lf\t\t%.2lf\t\t\t%.2lf\t\t\t%.2f\n", taksitsayac, taksitTutari, odenenFaiz, odenenAnapara, kalanAnapara);
    }
    printf("\n");
printf("Aylik Odemeniz:\t%.2lf\n",taksitTutari); //Ayl�k ka� tl �deme yapt���m�z yani taksit tutar�.
printf("Toplam Kredi Odemesi:\t%.2lf",(taksitSayisi*taksitTutari)); // Toplam faizlerle beraber ka� tl para �dedi�imiz.
	
}

int main() {
	double krediMiktari; // ne kadar kredi al�naca��
	double faizOran; // y�zde ka� faiz olaca��
	double taksitSayisi; // ka� taksit olaca��
	//Kullan�c�dan kredi miktar�n� al�yoruz.
	printf("Kredi miktarini giriniz: ");
	scanf("%lf",&krediMiktari);
	//Kullan�c�dan faiz oran�n� al�yoruz.
	printf("Faiz oranini giriniz: ");
	scanf("%lf",&faizOran);
	//Kullan�c�dan taksit say�s�n� al�yoruz.
	printf("Taksit sayisini giriniz: ");
	scanf("%lf",&taksitSayisi);	
aylikOdemeHesapla(krediMiktari,faizOran,taksitSayisi); //Burada fonksiyonu ekrana �a��r�yoruz.
	
	return 0;
}
