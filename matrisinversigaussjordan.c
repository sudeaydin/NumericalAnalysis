#include<stdio.h>

int main (){
int i,j,m,n;
float matris[30][30],birim[30][30];
printf("Inversini hesaplamak istediginiz matrisin satir sayisini giriniz.\n");
scanf("%d",&m);
printf("Inversini hesaplamak istediginiz matrisin sutun sayisini giriniz.\n");
scanf("%d",&n);
for (i=0;i<m;i++){
  for (j=0;j<n;j++){
    printf("Matrisinizin %d. satir %d. sutun elemanini giriniz.\n",i+1,j+1);
    scanf("%f",&matris[i][j] );
  }
}

for (i=0;i<m;i++){
  for (j=0;j<n;j++){
  if (i==j){
    birim[i][j]=1;
  }
  else
  birim[i][j]=0;
  }
}


for (i=0;i<n;i++){
  birim[0][i]=birim[0][i]/matris[0][0];
}
for (i=n-1;i>-1;i--){
  matris[0][i]=matris[0][i]/matris[0][0];
}


for (i=0;i<n;i++){
  birim[1][i]=birim[1][i]-(matris[1][0]*birim[0][i]);
}
for (i=n-1;i>-1;i--){
  matris[1][i]=matris[1][i]-(matris[1][0]*matris[0][i]);
}


for (i=0;i<n;i++){
  birim[2][i]=birim[2][i]-(matris[2][0]*birim[0][i]);
}
for (i=n-1;i>-1;i--){
  matris[2][i]=matris[2][i]-(matris[2][0]*matris[0][i]);
}


for (i=0;i<n;i++){
  birim[1][i]=birim[1][i]/matris[1][1];
}
for (i=n-1;i>-1;i--){
  matris[1][i]=matris[1][i]/matris[1][1];
}



for (i=0;i<n;i++){
  birim[0][i]=birim[0][i]-(matris[0][1]*birim[1][i]);
}
for (i=n-1;i>-1;i--){
  matris[0][i]=matris[0][i]-(matris[0][1]*matris[1][i]);
}



for (i=0;i<n;i++){
  birim[2][i]=birim[2][i]-(matris[2][1]*birim[1][i]);
}
for (i=n-1;i>-1;i--){
  matris[2][i]=matris[2][i]-(matris[2][1]*matris[1][i]);
}



for (i=0;i<n;i++){
  birim[2][i]=birim[2][i]/matris[2][2];
}
for (i=n-1;i>-1;i--){
  matris[2][i]=matris[2][i]/matris[2][2];
}



for (i=0;i<n;i++){
  birim[0][i]=birim[0][i]-(matris[0][2]*birim[2][i]);
}
for (i=n-1;i>-1;i--){
  matris[0][i]=matris[0][i]-(matris[0][2]*matris[2][i]);
}



for (i=0;i<n;i++){
  birim[1][i]=birim[1][i]-(matris[1][2]*birim[2][i]);
}
for (i=n-1;i>-1;i--){
  matris[1][i]=matris[1][i]-(matris[1][2]*matris[2][i]);
}


printf("Girdiginiz matrisin inversi:\n");
for (i=0;i<m;i++){
  for (j=0;j<n;j++){
    printf(" %.2f",birim[i][j]);
  }
  printf("\n");
}









}
