#include<iostream>
#include<string>

using namespace std;

int main(){
  int n, left_n[100]={0}, right_n[100]={0}, left_w[100]={0}, right_w[100]={0}, left_a[100]={0}, right_a[100]={0};
  cin >> n;
  char c;
  string s[100]={""};
  for(int i=0; i<7*n; i++){
    cin >> c;
    s[i/7] += c;
    if(c == '.'){
      if(i%7 == 0){
        left_n[i/7]++;
        left_w[i/7] = 1;
      }
      else if(i%7 == 1){
        left_n[i/7]++;
      }
      else if(i%7 == 2){
        left_n[i/7]++;
        left_a[i/7] = 1;
      }
      else if(i%7 == 4){
        right_n[i/7]++;
        right_a[i/7] = 1;
      }
      else if(i%7 == 5){
        right_n[i/7]++;
      }
      else if(i%7 == 6){
        right_n[i/7]++;
        right_w[i/7] = 1;
      }
    }
  }
  int m, k, check, pos;
  string side, position, res;
  char letter[3];
  cin >> m;
  for(int i=0; i<m; i++){
    cin >> k >> side >> position;
    check = 0;
    if ((side == "left")&&(position == "window")){
      for(int j=0; j<n; j++){
        if((left_w[j]==1)&&(left_n[j]>=k)&&((left_n[j]!=2)||(left_a[j]!=1)||(k==1))){
          check = 1;
          res = s[j];
          pos = j;
          for(int z=0; z<k; z++){
            if(z==0){letter[z]='A';}
            else if(z==1){letter[z]='B';}
            else if(z==2){letter[z]='C';}
            s[j][z] = '#';
            res[z] = 'X';
          }
          left_w[j] = 0;
          left_n[j] -= k;
          if(k==3){
            left_a[j] = 0;
          }
          cout << "Passengers can take seats: ";
          for(int z=0; z<k; z++){
            if (z == k-1){
              cout << j+1 << letter[z];
            }
            else{
              cout << j+1 << letter[z] << " ";
            }
          }
          break;
        }
      }
      if (check==0){
        cout << "Cannot fulfill passengers requirements" << "\n";
      }
    }
    else if ((side=="left")&&(position=="aisle")){
      for(int j=0; j<n; j++){
        if((left_a[j]==1)&&(left_n[j]>=k)&&((left_n[j]!=2)||(left_w[j]!=1)||(k==1))){
          check = 1;
          res = s[j];
          pos = j;
          for(int z=0; z<k; z++){
            if(z==0){letter[z]='C';}
            else if(z==1){letter[z]='B';}
            else if(z==2){letter[z]='A';}
            s[j][2-z] = '#';
            res[2-z] = 'X';
          }
          left_a[j] = 0;
          left_n[j] -= k;
          if(k==3){left_w[j] = 0;}
          cout << "Passengers can take seats: ";
          for(int z=0; z<k; z++){
            if (z == k-1){
              cout << j+1 << letter[k-z-1];
            }
            else{
              cout << j+1 << letter[k-z-1] << " ";
            }
          }
          break;
        }
      }
      if (check==0){
        cout << "Cannot fulfill passengers requirements" << "\n";
      }
    }
    else if ((side=="right")&&(position=="aisle")){
      for(int j=0; j<n; j++){
        if((right_a[j]==1)&&(right_n[j]>=k)&&((right_n[j]!=2)||(right_w[j]!=1)||(k==1))){
          check = 1;
          res = s[j];
          pos = j;
          for(int z=0; z<k; z++){
            if(z==0){letter[z]='D';}
            else if(z==1){letter[z]='E';}
            else if(z==2){letter[z]='F';}
            s[j][4+z] = '#';
            res[4+z] = 'X';
          }
          right_a[j] = 0;
          right_n[j] -= k;
          if(k==3){right_w[j] = 0;}
          cout << "Passengers can take seats: ";
          for(int z=0; z<k; z++){
            if (z == k-1){
              cout << j+1 << letter[z];
            }
            else{
              cout << j+1 << letter[z] << " ";
            }
          }
          break;
        }
      }
      if (check==0){
        cout << "Cannot fulfill passengers requirements" << "\n";
      }
    }
    else if ((side == "right")&&(position == "window")){
      for(int j=0; j<n; j++){
        if((right_w[j]==1)&&(right_n[j]>=k)&&((right_n[j]!=2)||(right_a[j]!=1)||(k==1))){
          check = 1;
          res = s[j];
          pos = j;
          for(int z=0; z<k; z++){
            if(z==0){letter[z]='F';}
            else if(z==1){letter[z]='E';}
            else if(z==2){letter[z]='D';}
            s[j][6-z] = '#';
            res[6-z] = 'X';
          }
          right_w[j] = 0;
          right_n[j] -= k;
          if(k==3){
            right_a[j] = 0;
          }
          cout << "Passengers can take seats: ";
          for(int z=0; z<k; z++){
            if (z == k-1){
              cout << j+1 << letter[k-z-1];
            }
            else{
              cout << j+1 << letter[k-z-1] << " ";
            }
          }
          break;
        }
      }
      if (check==0){
        cout << "Cannot fulfill passengers requirements" << "\n";
      }
    }
    if(check == 1){
      cout << "\n";
      for(int j=0; j<n; j++){
        if(j==pos){
          cout << res << "\n";
        }
        else{
          cout << s[j] << "\n";
        }
      }
    }
  }
}