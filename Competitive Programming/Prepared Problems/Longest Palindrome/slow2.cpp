#include <iostream>
using namespace std;
int main() {
  string input;
  cin >> input;
  int N = input.length();
  int ans = 0;
  int j = 0;
  for(int i = 0; i<N; i++){
    if((i+N)%2==0){
      j = 0;
      while(input[(N-i)/2-j-1]==input[(N-i)/2+j] && j<(N-i)/2){
        j++;
      }
      ans = max(ans, 2*j);
      if(i!=0){
        j = 0;
        while(input[(N+i)/2-j-1]==input[(N+i)/2+j] && j<(N-i)/2){
          j++;
        }
        ans = max(ans, 2*j);
      }
      //even
    }
    else{
      j = 0;
      while(input[(N-i)/2-j-1]==input[(N-i)/2+j+1] && j<(N-i)/2){
        j++;
      }
      ans = max(ans, 2*j+1);
      if(i!=0){
        j = 0;
        while(input[(N+i)/2-j-1]==input[(N+i)/2+j+1] && j<(N-i)/2){
          j++;
        }
        ans = max(ans, 2*j+1);
      }
      //odd
    }
    if(ans>=N-i){
      break;
    }
  }
  cout << ans;
}
