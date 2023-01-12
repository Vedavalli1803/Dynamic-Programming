#include <stdio.h>
#include<stdlib.h>
int main(void){
    int m,n;
    printf("Enter the length of the string1 and string 2:");
    scanf("%d %d",&m,&n);
    char str1[m],str2[n];
    printf("Enter the string1:");
    scanf("%s",str1);
    printf("Enter the string2:");
    scanf("%s",str2);
    int arr[m+1][n+1];
    int penalty[m+1][n+1];
    int i_p[m+1][n+1],j_p[m+1][n+1];
    for(int i=0;i<m+1;i++){
        arr[i][0]=0;
        arr[0][i]=0;
        i_p[i][0]=0;
        i_p[0][i]=0;
        j_p[i][0]=0;
        j_p[0][i]=0;
    }
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(str1[i-1]==str2[j-1]){
                arr[i][j]=arr[i-1][j-1]+2;
                i_p[i][j]=i-1;
                j_p[i][j]=j-1;
            }
            else{
                if(arr[i-1][j-1]>arr[i-1][j]){
                    arr[i][j]=arr[i-1][j-1]-1;
                    i_p[i][j]=i-1;
                    j_p[i][j]=j-1;
                }
                else{
                    if(arr[i-1][j]>arr[i][j-1]){
                        arr[i][j]=arr[i-1][j]-1;
                        i_p[i][j]=i-1;
                        j_p[i][j]=j;
                    }
                    else{
                        arr[i][j]=arr[i][j-1]-1;
                        i_p[i][j]=i;
                        j_p[i][j]=j-1;
                    }
                }
            }
        }
    }
    /*for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            printf("%d \t",arr[i][j]);
        }
        printf("\n");
    }
    printf("i matrix:\n");
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            printf("%d \t",i_p[i][j]);
        }
        printf("\n");
    }
    printf("j matrix:\n");
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            printf("%d \t",j_p[i][j]);
        }
        printf("\n");
    }*/
    
    //notmal trace back
    int c=0;
    int a;
    for(int i=0;i<m+1;i++){
       if(arr[i][n]>c){
           c=arr[i][m];
           a=i;
       }
    }
    int b=n;
    int d=arr[a][b];
    while(d>0){
        printf("%d \t",d);
        int i=a;
        a=i_p[i][b];
        b=j_p[i][b];
        d=arr[a][b];
    }
    
    /*string s_1[100] ;
    string s_2 =[100] ;
    i =least_r ;
    j = least_c ;
    while(i!=0 && j !=0)
    {
    if(s_parent[j-1]==s_offsp[i-1])
    {
        s_1 = s_parent[j-1] + s_1 ;
        s_2 = s_offsp[i-1] + s_2 ;
    }   
    else
    {
        int t = row[i][j] ;
        int p = col[i][j] ;
        if(p==j)
        {
            s_1 = '_' + s_1 ;
            s_2 = s_offsp[i-1] + s_2 ;
        }
        else
        {
            s_1 = s_parent[i-1] + s_1 ;
            s_2 = '_' + s_2 ;
        }
    }
    int i1=row[i][j] ;
    int j1 = col[i][j] ;
    i =i1 ;
    j =j1 ;
    }
    cout << s_1 <<"\n" ;
    cout <*/

    
    //prims
    
    int e=0;
    int f;
    for(int i=0;i<m+1;i++){
       if(arr[i][n]>e){
           e=arr[i][m];
           f=i;
       }
    }
    printf("\n");
    int g=arr[f][n];
    int h;
    while(g>0){
        printf("%d\t",g);
        if(abs(arr[f][n-1]-arr[f][n]) > abs(arr[f-1][n-1]-arr[f][n])){
            f=f-1;
            n=n-1;
        }
        else{
            if(abs(arr[f][n-1]-arr[f][n]) > abs(arr[f-1][n]-arr[f][n])){
                f=f-1;
                n=n;
            }
            else{
                f=f;
                n=n-1;
            }
            
        }
        g=arr[f][n];
    }
    printf("%d\t",g);
    return 0;

} 