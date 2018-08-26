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
  int nb;
  
  // for (n=(log2(w)-1);n>-1;n--){
  for (n=(log2(w)-1);n>=0;n--){
    nb=0;
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

      // Initialisation
      while ((a%w<E and (a%w)>0) or (b%w<E and (b%w)>0)){
	if (a%w == 0 and (half-a)>=E){
	  a2=a+E;
	  b2=b;
	  nb=nb+E;
	}
	else if (a%w == 0){
	  a2=half;
	  b2=b+(E-(a2-a));
	  nb=nb+a2-a;
	}
	
	else if (b%w == 0 and (end-b)>=E){
	  a2=a;
	  b2=b+E;
	  nb=nb+E;
	}
	else if (b%w == 0){
	  b2=end;
	  a2=a+(E-(b2-b));
	  nb=nb+b2-b;
	}
	else if (a%w<E and (a%w)>0){
	  if (w-(b%w)< a%w){
	    b2=b+w-b%w;
	    a2=a+E-b2+b;
	  }
	  else{
	    a2=a+E-(a%w);
	    b2=b+E-a2+a;
	  }
	}
	else {
	  if (w-(a%w)< b%w){
	    a2=a+w-a%w;
	    b2=b+E-a2+a;
	  }
	  else{
	    b2=b+E-(b%w);
	    a2=a+E-b2+b;
	  }
	}
	if (a%w<b%w){
	  for (int l=a;l<a2;l++){
	    M[l]=cpt;
	  }
	  cpt++;
	  for (int l=b;l<b2;l++){
	    M[l]=cpt;
	  }
	  cpt++;
	}
	else{
	  for (int l=b;l<b2;l++){
	    M[l]=cpt;
	  }
	  cpt++;
	  for (int l=a;l<a2;l++){
	    M[l]=cpt;
	  }
	  cpt++;
	}
	a=a2;
	b=b2;
      }
	  

      // Recurrence
      while ((half-a)+(end-b)>=E) {
	if (a%w == 0 and (half-a)>=E){
	  a2=a+E;
	  b2=b;
	  nb=nb+E;
	}
	else if (a%w == 0){
	  a2=half;
	  b2=b+(E-(a2-a));
	  nb=nb+a2-a;
	}
	
	else if (b%w == 0 and (end-b)>=E){
	  a2=a;
	  b2=b+E;
	  nb=nb+E;
	}
	else if (b%w == 0){
	  b2=end;
	  a2=a+(E-(b2-b));
	  nb=nb+b2-b;
	}
	else if (a==half) {
	  a2=a;
	  b2=b+E;
	}
	else if (b==end){
	  a2=a+E;
	  b2=b;
	}
	else if ((a%w>b%w) or (a%w==b%w and a>b)){
	  if ((w-(a%w))>=E){
	    if (a+E>half){
	      a2=half;
	      b2=b+E-a2+a;
	    }
	    else{
	      a2=a+E;
	      b2=b;
	    }
	  }
	  else{
	    if (a+(w-(a%w))>half){
	      a2=half;
	      b2=b+E-a2+a;
	    }
	    else if (b+E-w+(a%w)>end){
	      b2=end;
	      a2=a+E-b2+b;
	    }
	    else{
	      a2=a+(w-(a%w));
	      b2=b+E-a2+a;
	    }
	  }
	}
	else{
	  if ((w-(b%w))>=E){
	    if (b+E>end){
	      b2=end;
	      a2=a+E-b2+b;
	    }
	    else{
	      a2=a;
	      b2=b+E;
	    }
	  }
	  else{
	    if (b+(w-(b%w))>end){
	      b2=end;
	      a2=a+E-b2+b;
	    }
	    else if (a+E-w+(b%w)>half){
	      a2=half;
	      b2=b+E-a2+a;
	    }
	    else{
	      b2=b+(w-(b%w));
	      a2=a+E-b2+b;
	    }
	  }
	}
	
	if (a%w<b%w){
	  for (int l=a;l<a2;l++){
	    M[l]=cpt;
	  }
	  cpt++;
	  for (int l=b;l<b2;l++){
	    M[l]=cpt;
	  }
	  cpt++;
	}
	else{
	  for (int l=b;l<b2;l++){
	    M[l]=cpt;
	  }
	  cpt++;
	  for (int l=a;l<a2;l++){
	    M[l]=cpt;
	  }
	  cpt++;
	}

	a=a2;
	b=b2;
      }
    }
    // if (nb==E*E){
    //   cout <<"bank conflicts=1"<< endl;
    // }
    // else{
    //   cout << "bank conflicts=" <<"0."<< (nb*1000)/(E*E) << endl;
    // }
    
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
    
