#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

int main(){
  int E=15;
  int w=32;
  int M[w*E],Mt[w*E],Tmp[w*E];
  int a,b,cpt;
  int beg,half,end;

  for (int i=0;i<w*E;i++){
    M[i]=i;
    Mt[i]=0;
    Tmp[i]=0;
  }
  cout << "M_start :" << endl;
  for (int i=0;i<w;i++){
    for (int j=0;j<E;j++){
      cout << M[w*j+i] << " ";
    }
    cout << endl;
  }

  for (int n=(log2(w)-1);n>-1;n--){
    for (int i=0;i<w;i++){
      for (int j=0;j<E;j++){
	cin >> Mt[j*w+i];
      }
    }
    cout << "entré :" << endl;
    for (int i=0;i<w;i++){
      for (int j=0;j<E;j++){
	cout << Mt[w*j+i] << " ";
      }
      cout << endl;
    }
    
    cpt=0;
    for (int k=0;k<(w/(2<<n));k++){
      beg=k*(E*(2<<n));
      half=beg+(E*(2<<n))/2;
      end=(k+1)*(E*(2<<n));
      a=beg;
      b=half;
      cout << beg << "-" << half << "-" << end<< endl;
      while ((a<half) || (b<end)){
	if (a==half){
	  Tmp[b]=M[cpt];
	  cpt++;
	  b++;
	}
	else if (b==end){
	  Tmp[a]=M[cpt];
	  cpt++;
	  a++;
	}
	else if (Mt[a]<=Mt[b]){
	  Tmp[a]=M[cpt];
	  cpt++;
	  a++;
	}
	else if (b<end){
	  Tmp[b]=M[cpt];
	  cpt++;
	  b++;
	}
	else {
	  Tmp[a]=M[cpt];
	  cpt++;
	  a++;
	} 
      }
    }
    for (int i=0;i<w*E;i++){
      M[i]=Tmp[i];
    }

    
    cout << "sortie :" << endl;
    for (int i=0;i<w;i++){
      for (int j=0;j<E;j++){
	cout << M[w*j+i] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
  ofstream output ("output.txt", ios::trunc);
  
  for (int i=0;i<w*E;i++){
    output << M[i] << endl;
  }
  output.close();
}
