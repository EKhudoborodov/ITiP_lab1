#include<iostream>
#include<string>

using namespace std;

int main(){
  int n, dif, check, birth, res, first, second, third;
  cin >> n;
  string s;
  for(int i=0; i<n; i++){
    cin >> s;
    res = (s[0]-'A'+1)*256;
    dif = 0;
    check = 0;
    birth = 0;
    int sim[66] = {0};
    for(int j = 0; ((j<s.length())&&(check<5)); j++){
      if (s[j] == ','){
        check++;
      }
      else{
        if(check < 3){
          if(sim[s[j]-'A'] == 0){
            dif++;
            sim[s[j]-'A'] = 1;
          }
        }else if(check < 5){
          birth += (s[j]-48)*64;
        }
      }
    }
    res += dif + birth;
    res = res%4096;
    first = (res-(res%256))/256;
    if(first < 10){
      cout << first;
    }else{
      char f = 'A'+first-10;
      cout << f;
    }
    second = (res%256-(res%16))/16;
    if(second < 10){
      cout << second;
    }else{
      char sec = 'A'+second-10;
      cout << sec;
    }
    third = res%16;
    if(third < 10){
      cout << third;
    }else{
      char t = 'A'+third-10;
      cout << t;
    }
    cout << " ";
  }
}