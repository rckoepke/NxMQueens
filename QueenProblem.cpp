#include <iostream>
#include <string>

using namespace std;



bool isSafe(int **arr, int x, int y, int n, int m){
    if(x<n && y<m && y>=0 && x>=0 && arr[x][y] == 0){
        return true;
    }
    return false;
}


bool QueenOnBoard(int** arr, int x,int y,int n, int m, int count){
    int cc = 0;
    if(n>m){
        cc = m;
    }
    else if(m>n){
        cc = n;
    }
    else{
        cc = n;
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(arr[x][y]==1 || arr[x][y]==2){
                count++;
            }
        }
    }
    if(count == (n*m)){
        return true;
    }
    count = 0;
    if(isSafe(arr, x, y, n, m)){
        arr[x][y] = 2;
        for(int k = 0;k<n;k++){
            if(x+k < n){
              arr[x+k][y] = 1;
              arr[x][y] = 2; 
            }

            if(x-k >= 0){
              arr[x-k][y] = 1;
              arr[x][y] = 2; 
            }
        }
        for(int k = 0;k<m;k++){      
            if(y+k < m){
              arr[x][y+k] = 1;
              arr[x][y] = 2; 
            }
            if(y-k >= 0){
              arr[x][y-k] = 1;
              arr[x][y] = 2; 
            }
        }
        for(int j=0;j<cc;j++){
            if((x+j)<cc && (y+j)<cc){
               arr[x+j][y+j] = 1;
               arr[x][y] = 2; 
            }
            if((x-j)>=0 && (y+j)<cc){
               arr[x-j][y+j] = 1;
               arr[x][y] = 2; 
            }
            if((x-j)>=0 && (y-j)>=0){
               arr[x-j][y-j] = 1;
               arr[x][y] = 2; 
            }
            if((x+j)<cc && (y-j)>=0){
               arr[x+j][y-j] = 1;
               arr[x][y] = 2; 
            } 
        }
        if(QueenOnBoard(arr, x+1,y+2,n, m, count)){
            return true;
        }
        if(QueenOnBoard(arr, x-1,y+2,n, m, count)){
            return true;
        }
        if(QueenOnBoard(arr, x+1,y-2,n, m, count)){
            return true;
        }
        if(QueenOnBoard(arr, x-1,y-2,n, m, count)){
            return true;
        }
        if(QueenOnBoard(arr, x+2,y+1,n, m, count)){
            return true;
        }
        if(QueenOnBoard(arr, x+2,y-1,n, m, count)){
            return true;
        }
        if(QueenOnBoard(arr, x-2,y+1,n, m, count)){
            return true;
        }
        if(QueenOnBoard(arr, x-2,y-1,n, m, count)){
            return true;
        }
        for(int k = 0;k<n;k++){
            if(x+k < n){
              arr[x+k][y] = 0;
              arr[x][y] = 0; 
            }

            if(x-k >= 0){
              arr[x-k][y] = 0;
              arr[x][y] = 0; 
            }
        }
        for(int k = 0;k<m;k++){      
            if(y+k < m){
              arr[x][y+k] = 0;
              arr[x][y] = 0; 
            }
            if(y-k >= 0){
              arr[x][y-k] = 0;
              arr[x][y] = 0; 
            }
        }
        for(int j=0;j<cc;j++){
            if((x+j)<cc && (y+j)<cc){
               arr[x+j][y+j] = 0;
               arr[x][y] = 0; 
            }
            if((x-j)>=0 && (y+j)<cc){
               arr[x-j][y+j] = 0;
               arr[x][y] = 0; 
            }
            if((x-j)>=0 && (y-j)>=0){
               arr[x-j][y-j] = 0;
               arr[x][y] = 0; 
            }
            if((x+j)<cc && (y-j)>=0){
               arr[x+j][y-j] = 0;
               arr[x][y] = 0; 
            } 
        }
        return false;
    }
    return false;
}


int main(){
    int n,m;
    int count = 0;
    cout << "Enter the dimensions for N: ";
    cin >> n;
    cout << "Enter the dimensions for M: ";
    cin >> m;
    int **arr = new int*[n];
    for(int i = 0;i<n;i++){
        arr[i] = new int[m];
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            arr[i][j] = 0;
        }
    }
    if(QueenOnBoard(arr,0,0,n,m,count)){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    

}