#include <iostream>
#include<fstream>
#include<math.h> //log2

using namespace std;

int main(){
  int E=15;
  int w=32;
  int n=0;
  int M[w*E];
  int a,a2,b,b2;
  int beg,end,half;
  int cpt=0;
  
  for (n=(log2(w)-1);n>-1;n--){
  
    for (int i=0;i<w*E;i++){
      M[i]=0;
    }
    
    for (int k=0;k<(w/(2<<n));k++){
      beg=k*(E*(2<<n));
      half=beg+(E*(2<<n))/2;
      end=(k+1)*(E*(2<<n));
      a=beg;
      b=half;
      cpt=0;

      
      if ((a%w<E) && (a%w>0)){	
	M[a]=cpt;
	for (int l=b;l<b+(a%w)+1;l++){
	  M[l]=cpt;
	}
	cpt++;
	for (int l=a+1;l< a+(E-a%w-1);l++){
	  M[l]=cpt;
	}
	cpt++;
	a2=a+(E-a%w-1);
	b=b+(a%w)+1;
	a=a2;
      }
      
      while ((half-a)+(end-b)>=E) {
	if (a%w == 0 and (half-a)>=E){
	  a2=a+E;
	  b2=b;
	}
	else if (a%w == 0){
	  a2=half;
	  b2=b+(E-(a2-a));
	}
	else if (a<half){
	  if (w - (a%w) >=E){
	    if (half-a>=E){
	      a2=a+E;
	      b2=b;
	    }
	    else{
	      a2=half;
	      b2=b+E-(a2-a);
	    }
	  }
	  else{
	    if ( (half-a) <= (w-a%w)){
	      a2=half;
	      b2=b+E-(a2-a);
	    }
	    else{ 
	      a2= a+w-(a%w);
	      b2=b+ E-(a2-a);
	    }
	  }
	}
	else {
	  a2=a;
	  b2=b+E;
	}
      
	for (int l=a;l<a2;l++){
	  M[l]=cpt;
	}
	cpt++;
	for (int l=b;l<b2;l++){
	  M[l]=cpt;
	}
	cpt++;

	a=a2;
	b=b2;
      }
    }
    
    // for (int i=0,i<w*E,i++){
    //   cout << M[i];
    // }
    
    for (int i=0;i<w;i++){
      for (int j=0;j<E;j++){
	cout << M[w*j+i] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
}
    
