#include<stdio.h>
float fonksiyon(float*,int,float);
int main(){
  int der,i;
  float katsayi[30],gt,it,mt,h,x0;
  printf("-------Turev-------\n");
  printf("Fonksiyonunuzun derecesini giriniz.\n");
  scanf("%d",&der);
  for(i=0;i<=der;i++){
     printf("X in ussu %d olan terimin katsayisini giriniz\n",i);
     scanf("%f",&katsayi[i]);
  }
  printf(" h degerini  giriniz.\n");
  scanf("%f",&h);
  printf("Turevini hesaplamak istediginiz degeri giriniz.\n");
  scanf("%f",&x0);
gt=(fonksiyon(katsayi,der,x0)-fonksiyon(katsayi,der,x0-h))/h;
it=(fonksiyon(katsayi,der,x0+h)-fonksiyon(katsayi,der,x0))/h;
mt=(fonksiyon(katsayi,der,x0+h)-fonksiyon(katsayi,der,x0-h))/(2*h);
printf("Geri turev : %f\n",gt);
printf("Ileri turev : %f\n",it);
printf("Merkezi turev : %f\n",mt);

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
