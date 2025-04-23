#include <iostream>
#include<cmath>
using namespace std;

bool place(int k ,int i,int x[]){
    for(int j=0;j<k;j++){
        if(x[j]==i||abs(x[j]-i)==abs(j-k)){
            return false;
        }
    }
    return true;
}

void nqueens(int k,int n,int x[]){
    for(int i=0;i<n;i++){
        if(place(k,i,x)){
            x[k]=i;
            if(k==n-1){
                for(int row=0;row<n;row++){
                    for(int col=0;col<n;col++){
                        if(x[row]==col){
                            cout<<row+1<<" ";
                        }else{
                            cout<<" ";
                        }
                    }
                    cout<<endl;
                }
                cout<<endl;
            }else{
                nqueens(k+1,n,x);
            }
        }
    }
}

int main(){
int n;
cout<<"Enter size:";
cin>>n;
int x[n];
nqueens(0,n,x);
return 0;
}
