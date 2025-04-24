#include<iostream>
using namespace std;

const int r=2;
int m;
int hashArr[r][20];
int pos[r];

void initialize(){
    for(int i=0; i<r; i++){
        for(int j=0; j<m; j++){
            hashArr[i][j] == -1;
        }
    }
}

int hashFunc(int key, int i){
    if(i==0) return key%m;
    return (key/m) % m;
}

void Place(int key, int cnt, int idx, int n){
    if(cnt>=n){
        cout << "cycle completed... rehash required";
    }

    for(int i=0; i<r; i++){
        pos[i] = hashFunc(key, i);
    }
    for(int i=0; i<r; i++){
        if(hashArr[i][pos[i]] == key) return;
    }

    if(hashArr[idx][pos[idx]] != -1){
        int temp = hashArr[idx][pos[idx]];
        hashArr[idx][pos[idx]] = key;
        Place(temp, cnt+1, (idx+1)%r, n);
    }else{
        hashArr[idx][pos[idx]] = key;
    }
}

void printHash(){
    for(int i=0; i<r; i++){
        for(int j=0; j<m; j++){
            cout << hashArr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n; 
    cout << "Enter no.: ";
    cin >> n;
    m=n;

    int arr[n];
    cout << "Enter elements of array:" << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    initialize();
    for(int i=0; i<n; i++){
        Place(arr[i], 0, 0, n);
    }

    printHash();

    return 0;
}
