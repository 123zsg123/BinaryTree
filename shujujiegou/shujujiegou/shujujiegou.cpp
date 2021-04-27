#include<stdio.h>  
#include<stdlib.h>  
//二叉树的二叉链表结点的结构定义 
typedef struct BiTNode
{
    int key;  //结点的数据
    struct BiTNode* lchild, * rchild;//左右孩子指针  
} BiTNode, * BiTree;
//递归查找二叉排序树的查找是如何实现的'
//指针f是指向T的双亲 其初始调用值为NULL
//若查找成功  则指针p执行那个该数据元素的结点 并返回true
//否则指针p指向查找路径上访问的最后一个结点并返回false
//在二叉树中插入数据
int InsertBST(BiTree& T, int key)//插入 
{
    //这个函数是采用递归函数的思想  层层递归  最后新建一个结点 插入值
    if (!T)
    {//如果这颗树是空树,那么给这颗树分配空间  初始化二叉树  
        T = (BiTree)malloc(sizeof(BiTNode));
        T->key = key;
        T->lchild = (T)->rchild = NULL;
    }
    //如果要插入的值恰好等于根结点的值 那么就直接退出
    if (key == T->key) return 0;
    //左右递归
    if (key > T->key) InsertBST(T->rchild, key);
    else InsertBST(T->lchild, key);
}
//遍历
void zhongxu(BiTree T)//中序遍历
{
    if (T)//判断这棵树是否为空
    {  //按照LDR的顺序
        zhongxu(T->lchild);
        printf("%d ", T->key);
        zhongxu(T->rchild);
    }
}
void xianxu(BiTree T)
{
    if (T)
    {
        printf("%d ", T->key);
        xianxu(T->lchild);
        xianxu(T->rchild);
    }
}
void houxu(BiTree T)
{
    if (T)
    {
        houxu(T->lchild);
        houxu(T->rchild);
        printf("%d ", T->key);
    }
}
void Delete(BiTree& p) //删除 
{
    BiTree q, s;
    if (!p->lchild && !p->rchild) //p为叶子节点  
   //如果这个结点没有左右孩子的话  直接将这个结点指针指向空  就代表删除了这个指针
        p = NULL;
    else if (!p->lchild) //左子树为空，重接右子树
    {  //如果这棵树只有右子树
    //那么删除这个结点后  将它的右子树放到原来的结点的位置 
        q = p;   //将左子数赋值给临时指针q
        p = p->rchild;  //将右孩子放到原来的删除结点的位置
        free(q);  //释放q所指向的空间
    }
    else if (!p->rchild) //右子树为空，重接左子树
    {  //左子树道理同右子
        q = p;
        p = p->lchild;
        free(q);
    }
    else  //左右子树均不为空  这种情况稍微复杂一点
    //按照中中序排列 将要删除的结点的直接前驱放到被删除结点的位置   
    {
        q = p;  //现将q指向p所指向的空间
        s = p->lchild; // 临时指针S指向p的左孩子
        while (s->rchild)//一直遍历到s的最后一个右孩子
        {
            q = s;  //将最后一个右孩子所指向的空间赋给p指针
    //这里的意思就是将p指针左孩子的最后一个右孩子移位到原来p的指针
            s = s->rchild;
        }
        p->key = s->key;  //再将这个右孩子的数据域赋值给p
        if (q != p)//如果q指针与p指针不相等的时 将s的左孩子已到q结点的右孩子的位置
            q->rchild = s->lchild;
        else
            //这里的else 是指q与p相等的情况  这个情况有点难理解  
            //就是指s没有经过70行的while循环 也就是s没有右孩子的情况
            q->lchild = s->lchild;//就将s的左孩子重接到q的左孩子的位置
        free(s);
    }
}
int DeleteBST(BiTree& T, int key)//删除 
{  //删除给定值的结点
    if (!T) return 0;
    else
    {  //判断这个点是否是根结点
    //下面是左右孩子遍历
        if (key == T->key) Delete(T);
        else if (key < T->key)  DeleteBST(T->lchild, key);
        else  DeleteBST(T->rchild, key);
    }
}

int main()
{
    int e, n, t = 0;
    BiTree T = NULL, f, p;
    printf("输入长度：");
    scanf_s("%d", &n);
    printf("输入元素：");
    while (n--)
    {
        scanf_s("%d", &e);
        InsertBST(T, e);
    }
    printf("先序遍历:");
    xianxu(T);
    printf("\n");
    printf("中序遍历:");
    zhongxu(T);
    printf("\n");
    printf("后序遍历:");
    houxu(T);
    printf("\n");
    while (1)
    {
        printf("删除元素请输入1，插入元素请输入2\n");
        scanf_s("%d", &t);
        if (t == 1)
        {
            printf("输入要删除元素：");
            scanf_s("%d", &e);
            DeleteBST(T, e);
            printf("先序遍历:");
            xianxu(T);
            printf("\n");
            printf("中序遍历:");
            zhongxu(T);
            printf("\n");
            printf("后序遍历:");
            houxu(T);
            printf("\n");
        }
        if (t == 2)
        {
            printf("输入要插入元素：");
            scanf_s("%d", &e);
            InsertBST(T, e);
            printf("先序遍历:");
            xianxu(T);
            printf("\n");
            printf("中序遍历:");
            zhongxu(T);
            printf("\n");
            printf("后序遍历:");
            houxu(T);
            printf("\n");
        }
    }
}