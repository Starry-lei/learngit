

#include<vector>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
#define maxn 20
#define maxnn 60
typedef int ElemType;
typedef int Status;

int code[maxn];

typedef struct LNode{
    ElemType date;
    struct LNode *next;
    struct LNode *prior;
}LNode,*LinkList;


Status fListfind (int &fe,int i,LinkList &pf,LinkList &zanshif)  // 教官A找到第 i 个结点（逆时针）
{
    pf=zanshif;
    int j=0;
    while(pf->next&&j<i){
        pf=pf->next;
        j++;
    }
//if( !(p->next) || j>i-1 )
//   return 0;
    fe=pf->date;
    return 0;
}

Status fListdelete (LinkList &zanshif,LinkList &pf)  // 教官A删除第 i 个结点（逆时针）
{

    zanshif=pf->prior;
    pf->prior->next = pf->next;      //删除结点核心代码
    pf->next->prior = pf->prior;
    free(pf);
    return 0;
}

Status bListfind (int &be,int i,LinkList &pb,LinkList &zanshib)  // 教官B找到第 i 个结点（顺时针）
{
    pb=zanshib;
    int j=0;
    while(pb->prior&&j<i){
        pb=pb->prior;
        j++;
    }
    be=pb->date;
    return 0;
}

Status bListdelete (LinkList &zanshib,LinkList &pb)  // 教官B删除第 i 个结点（顺时针）
{

    zanshib=pb->next;
    pb->prior->next = pb->next;      //删除结点核心代码
    pb->next->prior = pb->prior;
    free(pb);
    return 0;
}


void Creatlist (LinkList &L,int n)  // 建立有 n 个结点的链表   双向链表。。。。有问题？？没实现
{
    L=(LinkList)malloc(sizeof(LNode));
//   L->next=NULL;
    LinkList r;
    r = L;
    for(int i=1;i<=n;i++){
        LinkList p=(LinkList)malloc(sizeof(LNode));
        p->date=i;
//        p->next=NULL;
        p->prior=r;
        r->next=p;
        r=p;
    }
    r->next=L->next;  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    L->next->prior=r;
}

int main()
{
    LinkList L,pb,pf;
    int n,k,m;
    int fe,be;
    cin >> n>>k>>m;
    Creatlist(L,n);
    LinkList zanshif=L;
    LinkList zanshib=L->next;
    while(L!=NULL){   //头结点指针域为空？？？？
        fListfind(fe,k,pf,zanshif);
        bListfind(be,m,pb,zanshib);
        fListdelete(zanshif,pf);
        cout<<fe<<"  ";
        if (be!=fe){
        bListdelete(zanshib,pb);
        cout<<be<<"  ";
        }
    }

    return 0;

}





