#include<stdio.h>
#include<math.h>
float fonksiyon(float*,int,float);
int main (){
int i,der;
float katsayi[20],n,h,x0,xn,integral;
float tektop=0;
float cifttop=0;
printf("--------Simpson-------\n");
printf("Fonksiyonunuzun derecesini giriniz.\n");
scanf("%d",&der);
for(i=0;i<=der;i++){
   printf(" X in ussu %d olan terimin katsayisini giriniz\n",i);
   scanf("%f",&katsayi[i]);
}
printf(" n i giriniz.\n");


scanf("%f",&n);
printf("Fonksiyonunuzun baslangic degerini giriniz.\n");
scanf("%f",&x0);
printf("Fonksiyonunuzun bitis degerini giriniz.\n");
scanf("%f",&xn);
h=(xn-x0)/n;
h=fabsf(h);
printf(" h %f\n",h );
for (i=1;i<=n-1;i+=2) {
  tektop=tektop+fonksiyon(katsayi,der,x0+i*h);
}
for (i=2;i<=n-2;i+=2) {
  cifttop=cifttop+fonksiyon(katsayi,der,x0+i*h);
}
printf("1. %f 2.%f\n",fonksiyon(katsayi,der,x0),fonksiyon(katsayi,der,xn) );
integral=(h/3)*(fonksiyon(katsayi,der,x0)+fonksiyon(katsayi,der,xn)+4*tektop+2*cifttop);

printf("Fonksiyonunuzun integrali: %f \n",integral);








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
