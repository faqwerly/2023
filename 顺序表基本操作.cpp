#include <iostream>
#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef int elemtype; //elemtype ����Ϊ��������
typedef struct sequlist
 //һ����˵ȡ����Ԫ�ص�����data�ʹ洢˳�����һ��Ԫ�ص��±�lastͬʱ������ݽṹ
{
 elemtype data[MAXSIZE];
 int last;

}SequenList;


SequenList *Init_SequenList() //˳���ĳ�ʼ��
{
 SequenList *L;
 L = (SequenList *)malloc(sizeof(SequenList)); //��������ڴ�ռ�

 //�������ڴ�ռ��Ƿ�ɹ�

 if (L != NULL)
 {
  L->last = 0; //����˳���ĳ���Ϊ0����ʾΪ�յ�˳���
  cout << "�����ڴ�ռ�ɹ���" << endl;

 }
 return L; //����˳�����׵�ַ
}




int SequenList_Length(SequenList *L) //˳���ĳ���
{

 cout <<"��˳���ĳ����ǣ�"<< L->last << endl; //���˳��ĳ��ȣ�ͨ��last+1
 return (L->last );
}






int Insert_SequenList(SequenList *L, elemtype x, int i) //˳������Ԫ��

{

 int j;

 //�ȼ��˳����Ƿ�����
 if (L->last >= MAXSIZE-1)
 {
  cout << "˳�������������" << endl;
  return 0;
 }

 //�ڼ��������ݵ�λ���Ƿ���Ч
 if (i<1 || i>L->last + 2)
 {
  cout << "����λ�������⣬�޷����룡" << endl;

 }
 //1���������i��λ���Ժ�����Ľ�������ƶ�
 //2��������x���뵽��i��λ����
 // 3����Ҫ��˳���ĳ��ȼ�1
 for (j = L->last; j >= i - 1; j--)
 {
  L->data[j + 1] = L->data[j];
  L->data[i - 1] = x;
  L->last = L->last + 1;
  return 1;

 }
 cout << "����Ԫ�سɹ���" << endl;
 return 1;
}

//ɾ��һ����i��1���������i�Ƿ�����Ч��Χ���� 2��ɾ��֮����i֮���Ԫ�ص��±�Ҫ��ǰ�ƶ�
int Delete_SequenList(SequenList *&L, int i)
{
 int j;
 //���λ����Ч��
 if (i<1 || i>L->last + 1)
 {
  cout << "ɾ��λ����Ч��" << endl;
 }
 else
 {
  //��ǰ�ƶ����
  for (j = i; j <= L->last; j++)
   L->data[j - 1] = L->data[j]; //�����j��ֵ��j-1;
      L->last--; //������Ҫ��һ

   cout << "ɾ���ɹ���" << endl;
 }
 return 1;


}

int Print_SequenList(SequenList *L) //����˳���
{
 int i;
 if (L->last == -1)
 {
  cout << "˳���Ϊ�գ�" << endl;

 }
 for (i = 0; i <= L->last-1; i++)
 {
  cout << L->data[i] << endl;
  if ((i + 1) % 5 == 0) //ÿ�����Ϊ5��Ԫ��
   cout << endl;
 }
 return 1;
}

int Search_SequenList(SequenList *L, elemtype key) //����key
{
 int i;
 for (i = 0; i <= L->last; i++)
 {
  if (L->data[i] == key)
  {
   cout << key << "�ڵ�"<<i+1<<"λ" << endl;
  }
  else
  {
   cout << "����ʧ�ܣ�����" << endl;
   return 0;
  }
 return 1;
 }
}


int main()
{
 static SequenList *L;
 while (1)
 {
  cout << "****************************************" << endl;
  cout << "* 1��˳���ĳ�ʼ�� 2������˳��� *" << endl;
  cout << "* 3��˳���ĳ��� 4��˳������ *" << endl;
  cout << "* 5��˳���ɾ�� 6�����˳��� 7���˳� *" << endl;
  cout << "****************************************" << endl;

  int k;
  cout << "���������ѡ��";
  cin >> k;
  switch (k)
  {
  case 1:
   L=Init_SequenList();
   system("pause");
   system("cls");
   continue;

  case 2:
   int x, i;
   cout << "��ѡ������Ԫ�ص�λ�ã�";
   cin >> i;
   cout << "��������Ҫ��Ԫ�أ�";
   cin >> x;
   Insert_SequenList(L, x, i);
   system("pause");
   system("cls");
   continue;

  case 3:
   SequenList_Length(L);
   system("pause");
   system("cls");
   continue;

  case 4:
   int key;
   cout << "��ѡ������Ҫ���ҵ�Ԫ�أ�";
   cin >> key;
   Search_SequenList(L, key);
   system("pause");
   system("cls");
   continue;

  case 5:
   cout << "��������Ҫɾ����Ԫ�أ�";
   cin >> i;
   Delete_SequenList(L, i);
   system("pause");
   system("cls");
   continue;


  case 6:
   Print_SequenList(L);
   system("pause");
   system("cls");
   continue;

  case 7:
   break;

  default:
   cout << "��������ȷ��ѡ��!!!" << endl;
   system("pause");
   system("cls");
   continue;
  }

  system("cls");
  break;

 }

 system("pause");
 return 0;
}
