//判断是否是回文串
//判断镜像串在刘汝佳2中 P49 操作太骚了


//比下面的方法好
#include<stdio.h>
#include<string.h>
int main()
{

    char s[20];
    scanf("%s",s);
    int count=strlen(s);
        printf("       %s",s);
        printf("   %d",count);
        for(int i=0;i<=count/2;i++){
            if(s[i]==s[count-1-i]){
                if (i==count/2)
                    printf("是呀\n");

            }
            else{
                printf("不是\n");
                break;
            }

        }

    return 0;
}


//判断是否是回文串
//判断镜像串在刘汝佳2中 P49 操作太骚了


//次于上面的方法
#include<stdio.h>
#include<string.h>
int main()
{

    int a,count =0;
    char s[99];
    while((a=getchar())!= EOF){
        s[count]=a;
        count++;
        }
        //printf("       %s",s);
        //printf("%d",count);
        for(int i=0;i<=count/2;i++){
            if(s[i]==s[count-1-i]){
                if (i==count/2)
                    printf("是呀\n");
            }
            else{
                printf("不是\n");
                break;
            }


        }

    return 0;
}


