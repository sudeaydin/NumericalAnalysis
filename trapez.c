#include<stdio.h>
float fonksiyon(float*,int,float);
int main (){
int der,i;
float x0,xn,n,h,toplam=0,katsayi[30],sonuc;
printf("-------Trapez-------\n");
printf("Fonksiyonunuzun derecesini giriniz.\n");
scanf("%d",&der);
for(i=0;i<=der;i++){
   printf("X in ussu %d olan terimin katsayisini giriniz\n",i);
   scanf("%f",&katsayi[i]);
}
printf("Baslangic degerini giriniz.\n");
scanf("%f",&x0 );
printf("Bitis degerini giriniz.\n");
scanf("%f",&xn );
printf("n degerini giriniz.\n");
scanf("%f",&n );
h=(xn-x0)/n;
for (i=0;i<n;i++) {
toplam=toplam+fonksiyon(katsayi,der,x0+(i*h));
}
sonuc=((fonksiyon(katsayi,der,x0)+fonksiyon(katsayi,der,xn))/2+toplam)*h;
printf("Sonucunuz:%f\n",sonuc );

}
float fonksiyon(float*katsayi,int der,float x0){
float fon[30];
float sonuc=1.0;
int i;
float toplam=0.0;
if (x0==0) {
  toplam=katsayi[0];
}
else{

for(i=0;i<der;i++){
  sonuc=sonuc*x0;
}
fon[0]=sonuc;
for(i=1;i<=der;i++){
sonuc=(float)sonuc/x0;
fon[i]=sonuc;
}
for(i=0;i<=der;i++){
  toplam=(fon[i]*katsayi[der-i])+toplam;
}
}
return toplam;

}
