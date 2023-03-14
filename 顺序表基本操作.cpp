#include <iostream>
#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef int elemtype; //elemtype 可以为任意类型
typedef struct sequlist
 //一般来说取数据元素的数组data和存储顺序最后一个元素的下标last同时存放数据结构
{
 elemtype data[MAXSIZE];
 int last;

}SequenList;


SequenList *Init_SequenList() //顺序表的初始化
{
 SequenList *L;
 L = (SequenList *)malloc(sizeof(SequenList)); //申请分配内存空间

 //检查分配内存空间是否成功

 if (L != NULL)
 {
  L->last = 0; //设置顺序表的长度为0，表示为空的顺序表
  cout << "分配内存空间成功！" << endl;

 }
 return L; //返回顺序表的首地址
}




int SequenList_Length(SequenList *L) //顺序表的长度
{

 cout <<"该顺序表的长度是："<< L->last << endl; //输出顺序的长度，通过last+1
 return (L->last );
}






int Insert_SequenList(SequenList *L, elemtype x, int i) //顺序表插入元素

{

 int j;

 //先检查顺序表是否满了
 if (L->last >= MAXSIZE-1)
 {
  cout << "顺序表已满！！！" << endl;
  return 0;
 }

 //在检查插入数据的位置是否有效
 if (i<1 || i>L->last + 2)
 {
  cout << "插入位置有问题，无法插入！" << endl;

 }
 //1、将插入第i个位置以后的数的结点往后移动
 //2、将数据x插入到第i个位置上
 // 3、还要将顺序表的长度加1
 for (j = L->last; j >= i - 1; j--)
 {
  L->data[j + 1] = L->data[j];
  L->data[i - 1] = x;
  L->last = L->last + 1;
  return 1;

 }
 cout << "插入元素成功！" << endl;
 return 1;
}

//删除一个数i：1、检查数据i是否再有效范围以内 2、删除之后在i之后的元素的下标要往前移动
int Delete_SequenList(SequenList *&L, int i)
{
 int j;
 //检查位置有效性
 if (i<1 || i>L->last + 1)
 {
  cout << "删除位置无效！" << endl;
 }
 else
 {
  //往前移动结点
  for (j = i; j <= L->last; j++)
   L->data[j - 1] = L->data[j]; //将结点j赋值给j-1;
      L->last--; //整个表要减一

   cout << "删除成功！" << endl;
 }
 return 1;


}

int Print_SequenList(SequenList *L) //遍历顺序表
{
 int i;
 if (L->last == -1)
 {
  cout << "顺序表为空！" << endl;

 }
 for (i = 0; i <= L->last-1; i++)
 {
  cout << L->data[i] << endl;
  if ((i + 1) % 5 == 0) //每行输出为5个元素
   cout << endl;
 }
 return 1;
}

int Search_SequenList(SequenList *L, elemtype key) //查找key
{
 int i;
 for (i = 0; i <= L->last; i++)
 {
  if (L->data[i] == key)
  {
   cout << key << "在第"<<i+1<<"位" << endl;
  }
  else
  {
   cout << "查找失败！！！" << endl;
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
  cout << "* 1、顺序表的初始化 2、插入顺序表 *" << endl;
  cout << "* 3、顺序表的长度 4、顺序表查找 *" << endl;
  cout << "* 5、顺序表删除 6、输出顺序表 7、退出 *" << endl;
  cout << "****************************************" << endl;

  int k;
  cout << "请输入你的选择：";
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
   cout << "请选择输入元素的位置：";
   cin >> i;
   cout << "请输入需要的元素：";
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
   cout << "请选择你需要查找的元素：";
   cin >> key;
   Search_SequenList(L, key);
   system("pause");
   system("cls");
   continue;

  case 5:
   cout << "请输入需要删除的元素：";
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
   cout << "请输入正确的选项!!!" << endl;
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
