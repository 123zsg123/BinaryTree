#include<stdio.h>  
#include<stdlib.h>  
//�������Ķ���������Ľṹ���� 
typedef struct BiTNode
{
    int key;  //��������
    struct BiTNode* lchild, * rchild;//���Һ���ָ��  
} BiTNode, * BiTree;
//�ݹ���Ҷ����������Ĳ��������ʵ�ֵ�'
//ָ��f��ָ��T��˫�� ���ʼ����ֵΪNULL
//�����ҳɹ�  ��ָ��pִ���Ǹ�������Ԫ�صĽ�� ������true
//����ָ��pָ�����·���Ϸ��ʵ����һ����㲢����false
//�ڶ������в�������
int InsertBST(BiTree& T, int key)//���� 
{
    //��������ǲ��õݹ麯����˼��  ���ݹ�  ����½�һ����� ����ֵ
    if (!T)
    {//���������ǿ���,��ô�����������ռ�  ��ʼ��������  
        T = (BiTree)malloc(sizeof(BiTNode));
        T->key = key;
        T->lchild = (T)->rchild = NULL;
    }
    //���Ҫ�����ֵǡ�õ��ڸ�����ֵ ��ô��ֱ���˳�
    if (key == T->key) return 0;
    //���ҵݹ�
    if (key > T->key) InsertBST(T->rchild, key);
    else InsertBST(T->lchild, key);
}
//����
void zhongxu(BiTree T)//�������
{
    if (T)//�ж�������Ƿ�Ϊ��
    {  //����LDR��˳��
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
void Delete(BiTree& p) //ɾ�� 
{
    BiTree q, s;
    if (!p->lchild && !p->rchild) //pΪҶ�ӽڵ�  
   //���������û�����Һ��ӵĻ�  ֱ�ӽ�������ָ��ָ���  �ʹ���ɾ�������ָ��
        p = NULL;
    else if (!p->lchild) //������Ϊ�գ��ؽ�������
    {  //��������ֻ��������
    //��ôɾ���������  �������������ŵ�ԭ���Ľ���λ�� 
        q = p;   //����������ֵ����ʱָ��q
        p = p->rchild;  //���Һ��ӷŵ�ԭ����ɾ������λ��
        free(q);  //�ͷ�q��ָ��Ŀռ�
    }
    else if (!p->rchild) //������Ϊ�գ��ؽ�������
    {  //����������ͬ����
        q = p;
        p = p->lchild;
        free(q);
    }
    else  //������������Ϊ��  ���������΢����һ��
    //�������������� ��Ҫɾ���Ľ���ֱ��ǰ���ŵ���ɾ������λ��   
    {
        q = p;  //�ֽ�qָ��p��ָ��Ŀռ�
        s = p->lchild; // ��ʱָ��Sָ��p������
        while (s->rchild)//һֱ������s�����һ���Һ���
        {
            q = s;  //�����һ���Һ�����ָ��Ŀռ丳��pָ��
    //�������˼���ǽ�pָ�����ӵ����һ���Һ�����λ��ԭ��p��ָ��
            s = s->rchild;
        }
        p->key = s->key;  //�ٽ�����Һ��ӵ�������ֵ��p
        if (q != p)//���qָ����pָ�벻��ȵ�ʱ ��s�������ѵ�q�����Һ��ӵ�λ��
            q->rchild = s->lchild;
        else
            //�����else ��ָq��p��ȵ����  �������е������  
            //����ָsû�о���70�е�whileѭ�� Ҳ����sû���Һ��ӵ����
            q->lchild = s->lchild;//�ͽ�s�������ؽӵ�q�����ӵ�λ��
        free(s);
    }
}
int DeleteBST(BiTree& T, int key)//ɾ�� 
{  //ɾ������ֵ�Ľ��
    if (!T) return 0;
    else
    {  //�ж�������Ƿ��Ǹ����
    //���������Һ��ӱ���
        if (key == T->key) Delete(T);
        else if (key < T->key)  DeleteBST(T->lchild, key);
        else  DeleteBST(T->rchild, key);
    }
}

int main()
{
    int e, n, t = 0;
    BiTree T = NULL, f, p;
    printf("���볤�ȣ�");
    scanf_s("%d", &n);
    printf("����Ԫ�أ�");
    while (n--)
    {
        scanf_s("%d", &e);
        InsertBST(T, e);
    }
    printf("�������:");
    xianxu(T);
    printf("\n");
    printf("�������:");
    zhongxu(T);
    printf("\n");
    printf("�������:");
    houxu(T);
    printf("\n");
    while (1)
    {
        printf("ɾ��Ԫ��������1������Ԫ��������2\n");
        scanf_s("%d", &t);
        if (t == 1)
        {
            printf("����Ҫɾ��Ԫ�أ�");
            scanf_s("%d", &e);
            DeleteBST(T, e);
            printf("�������:");
            xianxu(T);
            printf("\n");
            printf("�������:");
            zhongxu(T);
            printf("\n");
            printf("�������:");
            houxu(T);
            printf("\n");
        }
        if (t == 2)
        {
            printf("����Ҫ����Ԫ�أ�");
            scanf_s("%d", &e);
            InsertBST(T, e);
            printf("�������:");
            xianxu(T);
            printf("\n");
            printf("�������:");
            zhongxu(T);
            printf("\n");
            printf("�������:");
            houxu(T);
            printf("\n");
        }
    }
}