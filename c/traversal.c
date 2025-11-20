#include <stdio.h>
int main(){
int a[4],i;
printf("Input elements in the array\n");
    for(i=0;i<4;i++){
        printf("enter elements  a[%d] : ",i);
	    scanf("%d",&a[i]);
    }
printf("array elements are: ");   
    for(i=0;i<4;i++){
        printf("%d\t",a[i]);
    }
return 0;
}