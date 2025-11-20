#include<bits/stdc++.h>
using namespace std;

void pattern1(int n){
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << "*\t";
        }
    cout << endl;
    }
}
void pattern2(int n){
    for (int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout << "*\t";
        }
    cout << endl;
    }
}
void pattern3(int n){
    for (int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << j << "\t";
        }
    cout << endl;
    }
    /*for (int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout << j+1 << "\t";
        }
    cout << endl;
    }*/
}
void pattern4(int n){
    for (int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << i << "\t";
        }
    cout << endl;
    }
}
void pattern5(int n){
    for (int i=1; i<=n; i++){
        for(int j=1; j<=n-i+1; j++){
            cout << "*" << "\t";
        }
    cout << endl;
    }
    /*for (int i=1; i<=n; i++){
        for(int j=n-i+1; j>0; j--){
            cout << "*" << "\t";
        }
    cout << endl;
    }*/
}
void pattern6(int n){
    for (int i=1; i<=n; i++){
        for(int j=1; j<=n-i+1; j++){
            cout << j << "\t";
        }
    cout << endl;
    }
}
void pattern7(int n){
    for (int i=0; i<n; i++){
        for(int j=1; j<=n-i-1; j++){
            cout << " ";
        }
        for(int j=0; j<2*i+1; j++){
            cout << "*";
        }
        for(int j=1; j<=n-i-1; j++){
            cout << " ";
        }
    cout << endl;
    }
}
void pattern8(int n){
    for (int i=n; i>0; i--){
        for(int j=0; j<n-i; j++){
            cout << " ";
        }
        for(int j=0; j<2*i-1; j++){
            cout << "*";
        }
        for(int j=0; j<n-i; j++){
            cout << " ";
        }
    cout << endl;
    }
}
void pattern9(int n){
    for (int i=0; i<n; i++){
        for(int j=1; j<=n-i-1; j++){
            cout << " ";
        }
        for(int j=0; j<2*i+1; j++){
            cout << "*";
        }
        for(int j=1; j<=n-i-1; j++){
            cout << " ";
        }
    cout << endl;
    }
    for (int i=n; i>0; i--){
        for(int j=0; j<n-i; j++){
            cout << " ";
        }
        for(int j=0; j<2*i-1; j++){
            cout << "*";
        }
        for(int j=0; j<n-i; j++){
            cout << " ";
        }
    cout << endl;
    }
}
void pattern10(int n){
    /*for (int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout << "*";
        }
    cout << endl;
    }
    for (int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout << "*";
        }
    cout << endl;
    }*/
    for (int i=1; i<=2*n-1; i++){
        int stars=i;
        if(i>n) stars= 2*n-i;
        for(int j=1; j<=stars; j++){
            cout << "*";
        }
    cout << endl;
    }
}
void pattern11(int n){
    for (int i=0; i<n; i++){
        int start;
        if(i%2==0) start= 1;
        else start= 0;
        for(int j=0; j<=i; j++){
            cout << start;
            start= 1 - start;
        }
    cout << endl;
    }
}
void pattern12(int n){
    for (int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << j;
        }
        for(int j=1; j<=2*(n-i); j++){
            cout << " ";
        }
        /*int rev=i;
        for(int j=1; j<=i; j++){
            cout << rev;
            rev=rev-1;
        }*/
        for(int j=i; j>=1; j--){
            cout << j;
        }
    cout << endl;
    }
}
void pattern13(int n){
    int num=1;
    for (int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << num << " ";
            num+=1;
        }
    cout << endl;
    }
}
void pattern14(int n){
    for (int i=0; i<n; i++){
        for(char ch ='A'; ch<='A'+ i; ch++){
            cout << ch << " ";
        }
    cout << endl;
    }
}
void pattern15(int n){
    for (int i=n; i>0; i--){
        for(char ch ='A'; ch<='A'+ i-1; ch++){
            cout << ch << " ";
        }
    cout << endl;
    }
}
void pattern16(int n){
    /*for (char c ='A'; c<='A'+n-1; c++){
        for(char ch ='A'; ch<=c; ch++){
            cout << c << " ";
        }
    cout << endl;
    }*/
    for(int i=0; i<n; i++){
        char ch= 'A'+i;
        for(int j=0; j<=i; j++){
            cout << ch << " ";
        }
    cout << endl;    
    }
}
void pattern17(int n){
    /*for (int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout << " ";
        }
        int num;
        int rev=i;
        for(int j=0; j<=2*(i-1); j++){
            if(j>=i){
                cout << rev-1;
                rev-=1;
            } 
            else{
                num=j+1; 
                cout << num;
            } 
        }
        for(int j=1; j<=n-i; j++){
            cout << " ";
        }
    cout << endl;
    }*/
    for (int i=0; i<n; i++){
        for(int j=1; j<=n-i-1; j++){
            cout << " ";
        }
        char rev='A'+ i;
        for(char ch ='A'; ch<='A'+ 2*i; ch++){
            if(ch>rev){
                char reverse= rev-1;
                cout << reverse;
                rev--;
            }
            else{
                cout << ch;
            }    
        } 
        for(int j=1; j<=n-i; j++){
            cout << " ";
        }
    cout << endl;
    }
}
void pattern18(int n){
    for (int i=1; i<=n; i++){
        char alph= 'A'+n-i;
        for(char ch =alph; ch<='A'+ n-1; ch++){
            cout << ch << " ";
        }
    cout << endl;
    }
    /*for (int i=0; i<n; i++){
        for(char ch ='E'-i; ch<='E'; ch++){
            cout << ch << " ";
        }
    cout << endl;
    }
   for (int i=1; i<=n; i++){
        char alph= 'A'+n-i;
        for(char ch ='A'+ n-1; ch>=alph; ch--){
            cout << ch << " ";
        }
    cout << endl;
    }*/
}
void pattern19(int n){
    for (int i=n; i>=1; i--){
        for(int j=i; j>=1; j--){
            cout << "*";
        }
        for(int j=1; j<=2*(n-i); j++){
            cout << " ";
        }
        for(int j=i; j>=1; j--){
            cout << "*";
        }
    cout << endl;
    }
    for (int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << "*";
        }
        for(int j=1; j<=2*(n-i); j++){
            cout << " ";
        }
        for(int j=1; j<=i; j++){
            cout << "*";
        }
    cout << endl;
    }
}
void pattern20(int n){
    int spaces=2*(n-1);
    for (int i=1; i<=2*n-1; i++){
        int stars=i;
        if(i>n) stars= 2*n-i;
        for(int j=1; j<=stars; j++){
            cout << "*";
        }
        for(int j=1; j<=spaces; j++){
            cout << " "; 
        }
        for(int j=1; j<=stars; j++){
            cout << "*";
        } 
    cout << endl;
    int breakpoint= ((2*n-1)/2)+1;
    if(i>=breakpoint) spaces+=2;
    else spaces-=2;
    }
}
void pattern21(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==1 || j==1 || i==n || j==n) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
}
void pattern22(int n){
    int limit =2*n-1;
    for(int i=0; i<limit; i++){
        for(int j=0; j<limit; j++){
            int top=i;
            int bottom=2*(n-1)-i;
            int left=j;
            int right=2*(n-1)-j;
            cout << n-min(min(top,bottom),min(left,right));
            }
        cout << endl; 
        }
}

int main(){
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        int n;
        cin >> n;
        pattern22(n);
        cout << endl;
    }
}