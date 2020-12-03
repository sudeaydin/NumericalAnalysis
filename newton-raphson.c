#include<stdio.h>
#include<math.h>
float fonksiyon(float*,int,float);
float turev(float,float*,int);
int main(){
  int der,i;
  float katsayi[30],bas,son,eps,fark;
  printf("Fonksiyonunuzun derecesini giriniz.\n");
  scanf("%d",&der);
  for(i=0;i<=der;i++){
     printf("X in ussu %d olan terimin katsayisini giriniz\n",i);
     scanf("%f",&katsayi[i]);
  }
  printf("Baslangic degerini giriniz.\n");
  scanf("%f",&bas);
  printf("Epsilon degerini giriniz.\n");
  scanf("%f",&eps);
  fark=5;
  while (fark>eps) {
    son=bas-(fonksiyon(katsayi,der,bas)/turev(bas,katsayi,der));
    fark=son-bas;
    fark=fabsf(fark);
    bas=son;
  }
printf("Kokunuz yaklasik olarak %.3f dir\n",son);



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
float turev(float x,float*katsayi,int der){
float turev;
float  h=0.1;
turev=(fonksiyon(katsayi,der,x+h)-fonksiyon(katsayi,der,x-h))/(2*h);
return turev;


}
