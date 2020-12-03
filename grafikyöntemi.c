#include <stdio.h>

float fonksiyon(float*,int,float);

int main(){
int der,i;
float x0,eps,delta;
float katsayi[20];
printf("Fonksiyonunuzun derecesini giriniz.\n");
scanf("%d",&der);
for(i=0;i<=der;i++){
   printf(" X in ussu %d olan terimin katsayisini giriniz\n",i);
   scanf("%f",&katsayi[i]);
}
printf("Fonksiyonunuzun baslangic degerini giriniz.\n");
scanf("%f",&x0);
printf("Epsilon degerini giriniz.\n");
scanf("%f",&eps);
printf("Delta degerini giriniz.\n");
scanf("%f",&delta);
while(fonksiyon(katsayi,der,x0)!=0 || delta>eps) {
  if(fonksiyon(katsayi,der,x0) * fonksiyon(katsayi,der,x0+delta)>0){
x0=x0+delta;
}
else{
  delta=delta/2;
}
}
if(fonksiyon(katsayi,der,x0)==0){
printf("Kokunuz: %f\n",x0);
}
else{
printf("Kokunuz %f ile %f arasindadir.\n",x0,x0+delta);
}
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
