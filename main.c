#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#define N 10000//定义宏常量，学生的最大人数
#define M 30//定义宏常量，字符串的最大人数
typedef struct student//结果体定义一个学生的基本信息
{
    char studentname[M];//姓名
    char studentsex[M];//性别
    char major[M];//专业
    char classes[M];//班级
    long int studentID;//学号
    char building[M];//宿舍楼号
    int dormitory;//寝室号
    int bed;//床位
    char province[M];//来自的省份
    char nation[M];//民族
    long long int phonenum;//电话
}STU;

typedef struct studententer
{
    long long int stuID;
    char stuname[M];
    int Onecard;//一卡通费用
    int Interfee;//网费
    int utilitybill;//水电费
}STU2;

typedef struct entrance
{
    long long ID;
    char password[M];
}STU3;


STU stu1[N],stu2[N];//定义两个STU类型的数组
int number = 703;//定义全局变量number用于计算文件中多少条数据
int studentnum;//定义studentnum用于键盘输入的人数和从文件中导入的人数
int samename = 0;//定义全局变量samename用与计算结构体中相同的名字有多少
int a[N];
int ziti = 0;

STU3 enter[M];
long long int stuID;
char password[M];
void WritetoFile4(STU3 enter[], int n);//向学生密码中重新写入数据
void ReadfromFile1(STU3 enter[],int *n);//读取学生的密码账号信息
void ReadfromFile2(STU3 enter[],int *n);//读去管理员的密码账号信息
int SearchID(STU3 enter[],int n,long long int ID, char password[]);//用于核对学号对应的密码
void Menu8();//用于开始菜单
void Menu9();//用于对学生界面信息的挑选
void StudentEenter();//用于密码的输入
void Load();//用于加载的动画
void SelectItem2();//用于学生入口内容的选择

STU2 pupil[N];
void WritetoFile5(STU2 pupil[], int n);//向管理员的密码库中重新写入数据
void ReadfromFile3(STU2 pupil[],int *n);//向文件中读取学生的费用信息
int SearchStudentID2(STU2 pupil[], long int ID,int number);//用于对学号的查找
void PrintInformation2(STU2 pupil[],int number,int n);//用于打印学生的余额信息
void AlterOnecard(STU2 pupil[], int number, int n, int money);//用与向一卡通里充钱
void AlterInterFee(STU2 pupil[], int number, int n, int money);//用于充值网费
void AlterUtiltybill(STU2 pupil[], int number, int n, int money);//用于充值水电费
void SystemSetting(int xuanzhe);//系统设置
void AlterPassword(STU3 enter[], long long int stuID, char password[], int number);//用于对密码的修改
void WritetoFile6(STU3 enter[], int n);//用于对密码的写入

void Menu(); //声明主菜单
void Menu1(); //声明子菜单 创建文件菜单 有从文件创建和从键盘输入
void Menu2(); //声明子菜单 查询信息菜单 包括按姓名 学号 综合查询
void Menu3(); //声明子菜单 更改信息
void Menu4(); //声明子菜单 统计 包括按学号排序，统计男生和女生的人数，统计省份的人数和百分比，统计各专业的人数，统计
void Menu5(); //声明子菜单 保存信息 用于保存同省份 同班级 同专业 同班级 同寝室，同楼号的学生信息
void Menu6(); //声明子菜单 设置 用于设置背景颜色和字体颜色
void Menu7(); //声明修改学生个人信息的菜单
void SelectItem(); //声明选择项目
void InputInformation(STU stu[],int studentnum);//声明输入函数用于用户输入的数据
void example(); //提醒用户输入样例
void ReadfromFile(STU stu[],int *studentnum);//从原文件中读取数据
void PrintInformation(STU stu[],int studentnum);//用于打印结构体中的信息
int SearchStudentID(STU stu[],long int ID,int studentnum);//用于对学号的查询
int SearchStudentname(STU stu[], char str[], int studentnum);//用于对姓名的查询
void PrintInformation1(STU stu[],int studentnum,int a[]);//用于打印结构体中指定位置的信息
int SearchPhonenum(STU stu[], long long int phone, int studentnum);//用于对结构体中手机号的查询
int SearchComprehensive(STU stu[], STU student, int studentnum);//用于综合查询
void InputInformation1(STU stu[],int studentnum, int n);//用于信息修改时增加数据
void WritetoFile1(STU stu[],int n);//原文件文件中导入增加的信息；
void DeleteStudentInformation(STU stu[], int studentnum, int n);//用于删除信息
void EstablishFile(char ch1);//用于判断用户是否将数据导入文件
void WritetoFile2(STU stu[], int n);//用于新建一个文件储存修改后的信息
void WritetoFile3(STU stu[], int n);//用于修改后的数据导入源文件中
void AlterInputname();//用于修改时输入姓名
void AlterSave();//用于判断修改后是否储存
void AlterSex(STU stu[], int n, char sex[],int studentnum);//用于修改性别
void AlerMajorAndClasses(STU stu[], int n, char classes[], char major[], int studentnum);//用于修改专业和班级
void AlerStudentID(STU stu[], int n,long int ID, int studentnum);//用于对学号的修改
void AlterBuilding(STU stu[], int n, char building[],int studentnum);//用于对楼号的修改
void AlerDormitory(STU stu[], int n, int dormitory, int studentnum);//用于对寝室的修改
void AlerBed(STU stu[], int n, int bed, int studentnum);//用于床位的修改
void AlerProvince(STU stu[], int n, char province[], int studentnum);//用于对来自省份的修改
void AlterNation(STU stu[], int n, char nation[], int studentnum);//用于修改民族信息
void AlterPhone(STU stu[], int n, long long int phone, int studentnum);//用手机号的修改
void AscendingBubblingSort(STU stu[], int studentnum);//冒泡法升序排序
void DescendingBubblingSort(STU stu[], int studentnum);//冒泡法降序排序
int BoyNumber(STU stu[], int studentnum);//统计男生的人数
int GirlNumber(STU stu[], int studentnum);//统计女生的人数
int ProvinceNumber(STU stu[], int studentnum, char province[]);//统计某省的人数
int MajorNumber(STU stu[], int studentnum, char major[]);//统计某专业的人数
int DormitoryNumber(STU stu[], int studentnum, int dormitory);//统计某个寝室的人数
int Majorstu1tostu2(STU stu1[], STU stu2[], int studentnum, char major[]);//使结构体stu1中的相同专业的信息赋值给stu2
void MajortoFile(STU stu[],int n);//用于新建一个文件储存相同专业的人
int Classstu1tostu2(STU stu1[], STU stu2[], int studentnum, char classes[]);//使结构体stu1中的相同班级的信息赋值给stu2
void ClasstoFile(STU stu[],int n);//用于新建一个文件储存相同专业的人
int Dormitorystu1tostu2(STU stu1[], STU stu2[], int studentnum, int dormitory);//使结构体stu1中的相同寝室的信息赋值给stu2
void DormitorytoFile(STU stu[],int n);//用于建立一个文件储存相同寝室的人
int Provincestu1tostu2(STU stu1[], STU stu2[], int studentnum, char province[]);//使结构体stu1中的相同省份的信息赋值给stu2
void ProvincetoFile(STU stu[],int n);//用于新建一个文件储存相同省份的人
int Nationstu1tostu2(STU stu1[], STU stu2[], int studentnum, char nation[]);//使结构体stu1中的相同民族的信息赋值给stu2
void NationtoFile(STU stu[],int n);//用于新建一个文件储存相同民族的人
void SelectFontColor(int n);//选择字体颜色
void SelectBackgroundColor(int n);//选择背景颜色
void print();
void color_back();              //设置文本字符的颜色
void display_picture();
void quit();
void show();

int main()
{
    char ch;
    system("color 20");
    show();
    system("cls");
    Menu8();
    do
    {
        scanf(" %c",&ch);
        if(ch != 'A' && ch != 'B' && ch != 'C')
        {
            printf("\t\t\t\t☆亲，输入有误！请重新输入\a");
        }
    }while(ch != 'A' && ch != 'B' && ch != 'C');
    if(ch == 'C')
       quit();
    else if( ch == 'A')
    {
        ReadfromFile2(enter,&number);
        StudentEenter();
        system("cls");
        while(1)
        {
            SelectItem();
            system("cls");
        }
    }
    else if (ch == 'B')
    {
        ReadfromFile1(enter, &number);
        StudentEenter();
        while(1)
        {
            SelectItem2(2);
            system("cls");
        }
    }
    return 0;
}

void SelectItem() //定义选择函数 里面是对主函数和对子函数的调用，是整个程序的核心
{
    Menu();
    char ch; //定义字符ch用于对子菜单中选项的选择
    char ch1;//定义字符ch1用于系统的判断(Y/N)
    char ch2;//定义字符ch1用于对子子菜单（子菜单的子菜单）中选项的选择
    int flag = -1; //定义flag用于对主菜单中选项中的选择
    char choose[M];//定义字符串用于键盘输入姓名，来自省份，宿舍楼等信息，用于查询等
    char sex[M];//定义字符串用于性别的修改
    char major[M];//定义字符串用于专业的修改
    char classes[M];//定义字符串用于对班级的修改
    long int ID;//定义变量要查询的学号，用于对学号的查找和修改
    long long int phone;//定义变量phone，用于对手机号的查找和修改
    char building[M];//定义变量building,用于对楼号的修改
    int dormitory;//定义变量dormitory，用于对宿舍的修改
    int bed;//定义变量bed,用与对床位的修改
    char province[M];//定义变量province,用于对省份的修改
    char nation[M];//定义变量nation,用于对民族的修改

    static int temp = 0; //定义一个静态常量，用于检测首先使用是否“载入信息”
    do
    {
       scanf("%d",&flag);
        if((flag != 1)&&(flag != 7)&&(flag != 6)&&(temp == 0))
        {
            fflush(stdin);//如果输入不对用于缓冲字符
            printf("\t\t\t\t\a亲，首次使用请先“载入信息”\n");
            printf("\t\t\t\t请输入你的操作：");
        }
    }while((flag != 1)&&(flag != 7)&&(flag != 6)&&(temp == 0));
    switch(flag)
    {
        case 1:
            system("CLS");
            Menu1();
            do
            {
                scanf(" %c",&ch);
                if(ch != 'A' && ch != 'B' && ch != 'C')
                {
                    printf("\t\t\t亲，输入有误！请重新输入\a");
                }
            }while(ch != 'A' && ch != 'B' && ch != 'C');//用do..while 形式的格式来保证输入的合法性，后面很多代码这样写，以后不一一解释了
            if (ch == 'C')//如果等于C返回主菜单
                break;
            else if (ch == 'A')
            {
                  temp--;
                  example();
                  printf("\t\t\t请输入你要输入的人数：");
                  scanf("%d",&studentnum);
                  InputInformation(stu1,studentnum);
                  printf("\t\t\t是否要把数据呈现在屏幕上(Y/N)?");
                  scanf(" %c",&ch1);
                  if (ch1 == 'y' || ch1 == 'Y')
                  {
                     system("CLS");
                     PrintInformation(stu1,studentnum);
                     system("pause");
                     break;
                  }
                  break;
            }
            else
            {
                temp--;
                printf("\t\t\t这个文件中一共有%d条数据\n",number);
                printf("\t\t\t输入你想从文件中导入多少条数据：");
                scanf("%d",&studentnum);
                ReadfromFile(stu1,&studentnum);
                printf("\t\t\t恭喜你，成功导入数据！\n");
                printf("\t\t\t是否要把数据呈现在屏幕上(Y/N)?");
                scanf(" %c",&ch1);
                if (ch1 == 'y' || ch1 == 'Y')
                {
                    system("CLS");
                    PrintInformation(stu1,studentnum);
                    system("pause");
                    break;
                }
                else
                {
                    break;
                }
            }
        case 2:
            system("CLS");
            Menu2();
             do
            {
                getchar();
                ch = getchar();
                if(ch != 'A' && ch != 'B' && ch != 'C' && ch != 'D' && ch !='E')
                {
                    printf("\t\t\t亲，输入有误！请从新输入\a");
                }
            }while(ch != 'A' && ch != 'B' && ch != 'C' && ch != 'D' && ch != 'E');
            if (ch == 'E')//如果ch == 'E'则返回主菜单
                break;
            else if (ch == 'A')
            {
                printf("\t\t\t学号的位数为十位数，例如 1767159234\n");
                do
                {
                    printf("\t\t\t请输入你要查询的学号：");
                    int n;
                    scanf("%ld",&ID);
                    memset(a,0,sizeof(a));
                    n = SearchStudentID(stu1,ID,studentnum);
                    if(n != -1)
                    {
                        PrintInformation1(stu1, studentnum, a);
                    }
                    else
                    {
                        printf("\t\t\t对不起，你输入的学号不存在。\n");
                    }
                    printf("\t\t\t你还想用学号查询信息吗(Y/N)?");
                    scanf(" %c",&ch1);
                }while (ch1 == 'Y' || ch1 == 'y');
                break;
            }
            else if (ch == 'B')
            {
                do
                {
                    printf("\t\t\t请输入你需要查询的姓名（例如 李浩）：");
                    scanf("%s",choose);
                    int n;
                    samename = 0;
                    memset(a,0,sizeof(a));
                    n = SearchStudentname(stu1,choose,studentnum);
                    if(n != -1)
                    {
                        PrintInformation1(stu1, studentnum, a);
                        printf("\t\t\t导入的数据中叫“%s”的人一共有%d个\n",choose,samename);
                    }
                    else
                    {
                        printf("\t\t\t对不起，你输入的姓名不存在。\n");
                    }
                    printf("\t\t\t你还想用姓名查询信息吗(Y/N)?");
                    scanf(" %c",&ch1);
                }while (ch1 == 'Y' || ch1 == 'y');
                break;
            }
            else if (ch == 'C')
            {
                do
                {
                    printf("\t\t\t请输入你需要查询的手机号（例如15847249199）：");
                    scanf("%lld",&phone);
                    int n;
                    memset(a,0,sizeof(a));
                    n = SearchPhonenum(stu1,phone,studentnum);
                    if(n != -1)
                    {
                        PrintInformation1(stu1, studentnum, a);
                    }
                    else
                    {
                        printf("\t\t\t对不起，你输入的手机号不存在。\n");
                    }
                    printf("\t\t\t你还想用手机号查询信息吗(Y/N)?");
                    scanf(" %c",&ch1);
                }while (ch1 == 'Y' || ch1 == 'y');
                break;
            }
            else if (ch == 'D')
            {
                do
                {
                    example();
                    printf("\t\t\t请输入你要查询人的详细信息\n");
                    STU student;
                    printf("\t\t\t请输入你要查询人的名字：");
                    scanf("%s",student.studentname);
                    printf("\t\t\t请输入你要查询人的性别：");
                    scanf("%s",student.studentsex);
                    printf("\t\t\t请输入你要查询人的专业：");
                    scanf("%s",student.major);
                    printf("\t\t\t请输入你要查询人的班级：");
                    scanf("%s",student.classes);
                    printf("\t\t\t请输入你要查询人的学号：");
                    scanf("%ld",&student.studentID);
                    printf("\t\t\t请输入你要查询人的住的楼号：");
                    scanf("%s",student.building);
                    printf("\t\t\t请输入你要查询人的宿舍：");
                    scanf("%d",&student.dormitory);
                    printf("\t\t\t请输入你要查询人所在的床铺：");
                    scanf("%d",&student.bed);
                    printf("\t\t\t请输入你要查询人所在的省份：");
                    scanf("%s",student.province);
                    printf("\t\t\t请输入你所查询人所属的民族：");
                    scanf("%s",student.nation);
                    printf("\t\t\t请输入你所查询人的手机号：");
                    scanf("%lld",&student.phonenum);
                    int n;
                    memset(a,0,sizeof(a));
                    n = SearchComprehensive(stu1,student,studentnum);
                    if(n != -1)
                    {
                        printf("\t\t\t你要查找的人在数据库中存在\n");
                        PrintInformation1(stu1, studentnum, a);
                    }
                    else
                    {
                        printf("\t\t\t对不起，你输入人的信息不存在。\n");
                    }
                    printf("\t\t\t你还想用综合查询信息吗(Y/N)?");
                    scanf(" %c",&ch1);
                }while (ch1 == 'Y' || ch1 == 'y');
                break;
            }
        case 3:
            system("CLS");
            Menu3();
            do
            {
                getchar();
                ch = getchar();
                if(ch != 'A' && ch != 'B' && ch != 'C' && ch != 'D')
                {
                    printf("\t\t\t亲，输入有误！请从新输入\a");
                }
            }while(ch != 'A' && ch != 'B' && ch != 'C' && ch != 'D');
            if (ch == 'D')
                break;
            else if (ch == 'A')
            {
                printf("\t\t\t你想增加多少人的信息，请你输入你要增加多少人的信息？");
                int n;
                scanf("%d",&n);
                example();
                printf("\t\t\t请输入你要增加人的信息\n");
                InputInformation1(stu1,studentnum,n);
                printf("\t\t\t请问是否将输入的信息导入信息库？(Y/N)");
                scanf(" %c",&ch1);
                if(ch1 == 'Y' || ch1 == 'y')
                {
                    number = 703 + n;
                    WritetoFile1(stu1,studentnum+n);
                    Sleep(1000);
                    printf("\t\t\t恭喜你，导入成功！\n");
                    system("pause");

                }
                studentnum+=n;
                break;
            }
            else if (ch == 'B')
            {
               do
                {
                    printf("\t\t\t请输入你要删除人的名字：");
                    scanf("%s",choose);
                    int n;
                    samename = 0;
                    memset(a,0,sizeof(a));
                    n = SearchStudentname(stu1,choose,studentnum);
                    if(n != -1)
                    {
                        if(samename == 1)
                        {
                            DeleteStudentInformation(stu1, studentnum,n);
                            printf("\t\t\t恭喜你，成功把姓名为“%s”的人成功删除\n",choose);
                            printf("\t\t\t你是否想把删除后的信息导入信息库？(Y/N)");
                            scanf(" %c",&ch1);
                            EstablishFile(ch1);
                        }
                        else
                        {
                            PrintInformation1(stu1, studentnum, a);
                            printf("\t\t\t你需要删除叫“%s”的人一共有%d个\n",choose,samename);
                            printf("\t\t\t为了更加精确的删除你想删除的人，请你输入要删除人的学号：");
                            scanf("%ld",&ID);
                            n = SearchStudentID(stu1,ID,studentnum);
                            DeleteStudentInformation(stu1, studentnum,n);
                            printf("\t\t\t恭喜你，成功把姓名为“%s”，学号为“%ld”的人成功删除\n",choose,ID);
                            printf("\t\t\t你是否想把删除后的信息导入信息库？(Y/N)");
                            scanf(" %c",&ch1);
                            EstablishFile(ch1);
                         }
                         studentnum--;
                         number--;
                      }
                     else
                     {
                         printf("\t\t\t对不起，你输入的姓名不存在。\n");
                     }
                     printf("\t\t\t你还想删除信息吗(Y/N)?");
                     scanf(" %c",&ch1);
                }while (ch1 == 'Y' || ch1 == 'y');
                break;
            }
            else if (ch == 'C')
            {
                system("CLS");
                Menu7();
                do
                {
                    getchar();
                    ch2 = getchar();
                    if(ch2 != 'a' && ch2 != 'b' && ch2 != 'c' && ch2 != 'd' && ch2 != 'e' && ch2 != 'f' && ch2 != 'g' && ch2 != 'h' && ch2 != 'i')
                    {
                        printf("\t\t\t亲，输入有误！请从新输入\a");
                    }
                }while(ch2 != 'a' && ch2 != 'b' && ch2 != 'c' && ch2 != 'd' && ch2 != 'e' && ch2 != 'f' && ch2 != 'g' && ch2 != 'h' && ch2 != 'i');
                if (ch2 == 'a')
                {
                    do
                    {
                        AlterInputname();//用于修改时输入姓名
                        scanf("%s",choose);
                        int n;
                        n = SearchStudentname(stu1,choose,studentnum);
                        if(n != -1)
                        {
                            if (samename == 1)
                            {
                                PrintInformation1(stu1,studentnum,a);
                                printf("\t\t\t请你输入要把“%s”的性别修改成什么：",choose);
                                scanf("%s",sex);
                                AlterSex(stu1, n, sex, studentnum);
                                printf("\t\t\t恭喜你，成功修改了性别!\n");
                                AlterSave();
                            }
                            else
                            {
                                PrintInformation1(stu1, studentnum, a);
                                printf("\t\t\t你需要修改叫“%s”的人一共有%d个，请输入你要修改第几个:",choose,samename);
                                int n;
                                scanf("%d",&n);
                                printf("\t\t\t请你输入要把修改的人的性别改成什么：");
                                scanf("%s",sex);
                                AlterSex(stu1,a[n-1],sex,studentnum);
                                printf("\t\t\t恭喜你，成功修改了性别！\n");
                                AlterSave();//用于判断修改后是否储存
                            }
                        }
                        else
                        {
                            printf("\t\t\t对不起，你输入的姓名不存在。\n");
                        }
                        printf("\t\t\t你还想修改人的性别吗(Y/N)?");
                        scanf(" %c",&ch1);
                    }while (ch1 == 'Y' || ch1 == 'y');
                    break;
                }
                else if (ch2 == 'b')
                {
                    do
                    {
                        AlterInputname();//用于修改时输入姓名
                        scanf("%s",choose);
                        int n;
                        n = SearchStudentname(stu1,choose,studentnum);
                        if(n != -1)
                        {
                            if (samename == 1)
                            {
                                PrintInformation1(stu1,studentnum,a);
                                printf("\t\t\t请你输入要把“%s”的专业和班级改成什么：",choose);
                                scanf("%s %s",major,classes);
                                AlerMajorAndClasses(stu1, n, classes, major, studentnum);//用于修改专业和班级
                                printf("\t\t\t恭喜你，成功修改了专业和班级!\n");
                                AlterSave();
                            }
                            else
                            {
                                PrintInformation1(stu1, studentnum, a);
                                printf("\t\t\t你需要修改叫“%s”的人一共有%d个，请输入你要修改第几个",choose,samename);
                                int n;
                                scanf("%d",&n);
                                printf("\t\t\t请你输入要把修改的人的专业和班级修改成什么：");
                                scanf("%s %s",major,classes);
                                AlerMajorAndClasses(stu1, a[n-1], classes, major, studentnum);
                                printf("\t\t\t恭喜你，成功修改了专业和班级！\n");
                                AlterSave();
                            }
                        }
                        else
                        {
                            printf("\t\t\t对不起，你输入的姓名不存在。\n");
                        }
                        printf("\t\t\t你还想修改人的专业和班级吗(Y/N)?");
                        scanf(" %c",&ch1);
                    }while (ch1 == 'Y' || ch1 == 'y');
                    break;
                }
                else if (ch2 == 'c')
                {
                    do
                    {
                        AlterInputname();//用于修改时输入姓名
                        scanf("%s",choose);
                        int n;
                        n = SearchStudentname(stu1,choose,studentnum);
                        if(n != -1)
                        {
                            if (samename == 1)
                            {
                                PrintInformation1(stu1,studentnum,a);
                                printf("\t\t\t请你输入要把“%s”的学号改成什么：",choose);
                                scanf("%ld",&ID);
                                AlerStudentID(stu1, n, ID, studentnum);//用于对学号的修改
                                printf("\t\t\t恭喜你，成功修改了学号!\n");
                                AlterSave();
                            }
                            else
                            {
                                PrintInformation1(stu1, studentnum, a);
                                printf("\t\t\t你需要修改叫“%s”的人一共有%d个，请输入你要修改第几个",choose,samename);
                                int n;
                                scanf("%d",&n);
                                printf("\t\t\t请你输入要把修改的人的学号修改成什么：");
                                scanf("%ld",&ID);
                                AlerStudentID(stu1, a[n-1], ID, studentnum);//用于对学号的修改
                                printf("\t\t\t恭喜你，成功修改了学号！\n");
                                AlterSave();
                            }
                        }
                        else
                        {
                            printf("\t\t\t对不起，你输入的姓名不存在。\n");
                        }
                        printf("\t\t\t你还想修改人的学号吗(Y/N)?");
                        scanf(" %c",&ch1);
                    }while (ch1 == 'Y' || ch1 == 'y');
                    break;
                }
                else if (ch2 == 'd')
                {
                    do
                    {
                        AlterInputname();//用于修改时输入姓名
                        scanf("%s",choose);
                        int n;
                        n = SearchStudentname(stu1,choose,studentnum);
                        if(n != -1)
                        {
                            if (samename == 1)
                            {
                                PrintInformation1(stu1,studentnum,a);
                                printf("\t\t\t请你输入要把“%s”的楼号改成什么：",choose);
                                scanf("%s",building);
                                AlterBuilding(stu1, n, building, studentnum);//用于对楼号的修改
                                printf("\t\t\t恭喜你，成功修改了楼号!\n");
                                AlterSave();
                            }
                            else
                            {
                                PrintInformation1(stu1, studentnum, a);
                                printf("\t\t\t你需要修改叫“%s”的人一共有%d个，请输入你要修改第几个:",choose,samename);
                                int n;
                                scanf("%d",&n);
                                printf("\t\t\t请你输入要把修改的人的楼号修改成什么：");
                                scanf("%s",building);
                                AlterBuilding(stu1, a[n-1], building, studentnum);//用于对楼号的修改
                                printf("\t\t\t恭喜你，成功修改了楼号！\n");
                                AlterSave();
                            }
                        }
                        else
                        {
                            printf("\t\t\t对不起，你输入的姓名不存在。\n");
                        }
                        printf("\t\t\t你还想修改人的楼号吗(Y/N)?");
                        scanf(" %c",&ch1);
                    }while (ch1 == 'Y' || ch1 == 'y');
                    break;
                }
                else if (ch2 == 'e')
                {
                    do
                    {
                        AlterInputname();//用于修改时输入姓名
                        scanf("%s",choose);
                        int n;
                        n = SearchStudentname(stu1,choose,studentnum);
                        if(n != -1)
                        {
                            if (samename == 1)
                            {
                                PrintInformation1(stu1,studentnum,a);
                                printf("\t\t\t请你输入要把“%s”的寝室改成什么：",choose);
                                scanf("%d",&dormitory);
                                AlerDormitory(stu1, n, dormitory, studentnum);//用于对寝室的修改
                                printf("\t\t\t恭喜你，成功修改了寝室信息!\n");
                                AlterSave();
                            }
                            else
                            {
                                PrintInformation1(stu1, studentnum, a);
                                printf("\t\t\t你需要修改叫“%s”的人一共有%d个，请输入你要修改第几个",choose,samename);
                                int n;
                                scanf("%d",&n);
                                printf("\t\t\t请你输入要把修改的人的寝室修改成什么：");
                                scanf("%d",&dormitory);
                                AlerDormitory(stu1, a[n-1], dormitory, studentnum);//用于对寝室的修改
                                printf("\t\t\t恭喜你，成功修改了寝室信息！\n");
                                AlterSave();
                            }
                        }
                        else
                        {
                            printf("\t\t\t对不起，你输入的姓名不存在。\n");
                        }
                        printf("\t\t\t你还想修改人的寝室吗(Y/N)?");
                        scanf(" %c",&ch1);
                    }while (ch1 == 'Y' || ch1 == 'y');
                    break;
                }
                else if (ch2 == 'f')
                {
                    do
                    {
                        AlterInputname();//用于修改时输入姓名
                        scanf("%s",choose);
                        int n;
                        n = SearchStudentname(stu1,choose,studentnum);
                        if(n != -1)
                        {
                            if (samename == 1)
                            {
                                PrintInformation1(stu1,studentnum,a);
                                printf("\t\t\t请你输入要把“%s”的床位改成什么：",choose);
                                scanf("%d",&bed);
                                AlerBed(stu1, n, bed, studentnum);//用于床位的修改
                                printf("\t\t\t恭喜你，成功修改了床位信息!\n");
                                AlterSave();
                            }
                            else
                            {
                                PrintInformation1(stu1, studentnum, a);
                                printf("\t\t\t你需要修改叫“%s”的人一共有%d个，请输入你要修改第几个:",choose,samename);
                                int n;
                                scanf("%d",&n);
                                printf("\t\t\t请你输入要把修改的人的床位修改成什么：");
                                scanf("%d",&bed);
                                AlerBed(stu1, a[n-1], bed, studentnum);//用于床位的修改
                                printf("\t\t\t恭喜你，成功修改了床位信息！\n");
                                AlterSave();
                            }
                        }
                        else
                        {
                            printf("\t\t\t对不起，你输入的姓名不存在。\n");
                        }
                        printf("\t\t\t你还想修改人的床位吗(Y/N)?");
                        scanf(" %c",&ch1);
                    }while (ch1 == 'Y' || ch1 == 'y');
                    break;
                }
                else if (ch2 == 'g')
                {
                    do
                    {
                        AlterInputname();//用于修改时输入姓名
                        scanf("%s",choose);
                        int n;
                        n = SearchStudentname(stu1,choose,studentnum);
                        if(n != -1)
                        {
                            if (samename == 1)
                            {
                                PrintInformation1(stu1,studentnum,a);
                                printf("\t\t\t请你输入要把“%s”的所来自的省份改成什么：",choose);
                                scanf("%s",province);
                                AlerProvince(stu1, n, province, studentnum);//用于对来自省份的修改
                                printf("\t\t\t恭喜你，成功修改了省份信息!\n");
                                AlterSave();
                            }
                            else
                            {
                                PrintInformation1(stu1, studentnum, a);
                                printf("\t\t\t你需要修改叫“%s”的人一共有%d个，请输入你要修改第几个:",choose,samename);
                                int n;
                                scanf("%d",&n);
                                printf("\t\t\t请你输入要把修改的人的所来自的省份修改成什么：");
                                scanf("%s",province);
                                AlerProvince(stu1, a[n-1], province, studentnum);//用于对来自省份的修改
                                printf("\t\t\t恭喜你，成功修改了省份！\n");
                                AlterSave();
                            }
                        }
                        else
                        {
                            printf("\t\t\t对不起，你输入的姓名不存在。\n");
                        }
                        printf("\t\t\t你还想修改人所来自的省份吗(Y/N)?");
                        scanf(" %c",&ch1);
                    }while (ch1 == 'Y' || ch1 == 'y');
                    break;
                }
                else if (ch2 == 'h')
                {
                    do
                    {
                        AlterInputname();//用于修改时输入姓名
                        scanf("%s",choose);
                        int n;
                        n = SearchStudentname(stu1,choose,studentnum);
                        if(n != -1)
                        {
                            if (samename == 1)
                            {
                                PrintInformation1(stu1,studentnum,a);
                                printf("\t\t\t请你输入要把“%s”的民族改成什么：",choose);
                                scanf("%s",nation);
                                AlterNation(stu1, n, nation, studentnum);//用于修改民族信息
                                printf("\t\t\t恭喜你，成功修改了民族信息!\n");
                                AlterSave();
                            }
                            else
                            {
                                PrintInformation1(stu1, studentnum, a);
                                printf("\t\t\t你需要修改叫“%s”的人一共有%d个，请输入你要修改第几个:",choose,samename);
                                int n;
                                scanf("%d",&n);
                                printf("\t\t\t请你输入要把修改的人的民族修改成什么：");
                                scanf("%s",nation);
                                AlterNation(stu1, a[n-1], nation, studentnum);//用于修改民族信息
                                printf("\t\t\t恭喜你，成功修改了民族信息！\n");
                                AlterSave();
                            }
                        }
                        else
                        {
                            printf("\t\t\t对不起，你输入的姓名不存在。\n");
                        }
                        printf("\t\t\t你还想修改人民族吗(Y/N)?");
                        scanf(" %c",&ch1);
                    }while (ch1 == 'Y' || ch1 == 'y');
                    break;
                }
                else if (ch2 == 'i')
                {
                    do
                    {
                        AlterInputname();//用于修改时输入姓名
                        scanf("%s",choose);
                        int n;
                        n = SearchStudentname(stu1,choose,studentnum);
                        if(n != -1)
                        {
                            if (samename == 1)
                            {
                                PrintInformation1(stu1,studentnum,a);
                                printf("\t\t\t请你输入要把“%s”的手机号改成什么：",choose);
                                scanf("%lld",&phone);
                                AlterPhone(stu1, n, phone, studentnum);//用手机号的修改
                                printf("\t\t\t恭喜你，成功修改了手机号!\n");
                                AlterSave();
                            }
                            else
                            {
                                PrintInformation1(stu1, studentnum, a);
                                printf("\t\t\t你需要修改叫“%s”的人一共有%d个，请输入你要修改第几个",choose,samename);
                                int n;
                                scanf("%d",&n);
                                printf("\t\t\t请你输入要把修改的人的手机号修改成什么：");
                                scanf("%lld",&phone);
                                AlterPhone(stu1, a[n-1], phone, studentnum);//用手机号的修改
                                printf("\t\t\t恭喜你，成功修改了手机号！\n");
                                AlterSave();
                            }
                        }
                        else
                        {
                            printf("\t\t\t对不起，你输入的姓名不存在。\n");
                        }
                        printf("\t\t\t你还想修改人的手机号吗(Y/N)?");
                        scanf(" %c",&ch1);
                    }while (ch1 == 'Y' || ch1 == 'y');
                    break;
                }
            }
         case 4:
            system("CLS");
            Menu4();
            do
            {
                getchar();
                ch = getchar();
                if(ch != 'A' && ch != 'B' && ch != 'C' && ch != 'D' && ch != 'E' && ch != 'F')
                {
                    printf("\t\t\t亲，输入有误！请从新输入\a");
                }
            }while(ch != 'A' && ch != 'B' && ch != 'C' && ch != 'D' && ch != 'E' && ch != 'F');
            if (ch == 'F')
                break;
            else if (ch == 'A')
            {
                printf("\t\t\t请输入你想升序排序还是想降序排序（Y/N）(Y表示升序)");
                scanf(" %c",&ch1);
                if (ch1 == 'Y' || ch1 =='y')
                {
                    AscendingBubblingSort(stu1, studentnum);//选选择的发用于升序排序
                    printf("\t\t\t恭喜你排序完成\n");
                    AlterSave();//用于判断修改后是否储存
                }
                else
                {
                    DescendingBubblingSort(stu1, studentnum);//选选择的发用于降序排序
                    printf("\t\t\t恭喜你排序完成\n");
                    AlterSave();//用于判断修改后是否储存
                    system("pause");
                }
                break;
            }
            else if (ch == 'B')
            {
                printf("\t\t\t稍等一秒钟，正在统计数据.....\n");
                Sleep(1000);
                int boy,girl;
                boy = BoyNumber(stu1, studentnum);
                girl = GirlNumber(stu1, studentnum);
                printf("\t\t\t         人数       百分比\n");
                printf("\t\t\t 男 ♂      %d        %.2lf%%\n", boy , boy*100.0/studentnum);
                printf("\t\t\t 女 ♀      %d        %.2lf%%\n", girl, girl*100.0/studentnum);
                system("pause");
                break;
            }
            else if (ch == 'C')
            {
                do
                {
                    printf("\t\t\t请输入你想统计那个省的人数？(例如：山东省):");
                    scanf("%s",province);
                    int n = ProvinceNumber(stu1, studentnum, province);//统计某省的人数
                    printf("\t\t\t省份        人数      百分比\n");
                    printf("\t\t\t%s          %d       %.2lf%%\n", province, n, n*100.0/studentnum);
                    printf("\t\t\t你还想统计那个省的人吗？(Y/N)");
                    scanf(" %c",&ch1);
                }while (ch1 == 'Y' || ch1 == 'y');
                break;
            }
            else if (ch == 'D')
            {
                do
                {
                    printf("\t\t\t请输入你想统计那个专业的人数？(例如：软件工程)");
                    scanf("%s",major);
                    int n = MajorNumber(stu1, studentnum, major);//统计某专业的人数
                    printf("\t\t\t专业                人数      百分比\n");
                    printf("\t\t\t%s                   %d       %.2lf%%\n", major, n, n*100.0/studentnum);
                    printf("\t\t\t你还想统计那个专业的人吗？(Y/N)");
                    scanf(" %c",&ch1);
                }while (ch1 == 'Y' || ch1 == 'y');
                break;
            }
            else if (ch == 'E')
            {
                do
                {
                    printf("\t\t\t请输入你想统计那个寝室的人数？(例如：926)");
                    scanf("%d",&dormitory);
                    int n = DormitoryNumber(stu1, studentnum, dormitory);//统计某个寝室的人数
                    printf("\t\t\t寝室                人数\n");
                    printf("\t\t\t%d                   %d \n", dormitory, n);
                    printf("\t\t\t你还想统计那个寝室的人吗？(Y/N)");
                    scanf(" %c",&ch1);
                }while (ch1 == 'Y' || ch1 == 'y');
                break;
            }
         case 5:
            system("CLS");
            Menu5();
            do
            {
                getchar();
                ch = getchar();
                if(ch != 'A' && ch != 'B' && ch != 'C' && ch != 'D' && ch != 'E' && ch != 'F' && ch != 'G')
                {
                    printf("\t\t\t输入有误！请从新输入\a");
                }
            }while(ch != 'A' && ch != 'B' && ch != 'C' && ch != 'D' && ch != 'E' && ch != 'F' && ch != 'G');
            if (ch == 'G')
                break;
            else if (ch == 'A')
            {
                AlterSave();//用于判断修改后是否储存
                break;
            }
            else if (ch == 'B')
            {
                memset(stu2,0,sizeof(STU));
                printf("\t\t\t请输入你想保存那个专业的信息？(例如：软件工程)");
                scanf("%s",major);
                int  n = Majorstu1tostu2(stu1, stu2, studentnum, major);//使结构体stu1中的相同专业的信息赋值给stu2
                PrintInformation(stu2,n);
                printf("\t\t\t这个专业共有%d人，你确定想要保存这个专业信息到文件中？(Y/N)");
                scanf(" %c",&ch1);
                if (ch1 == 'Y' || ch1 =='y')
                {
                    MajortoFile(stu2,n);//用于新建一个文件储存相同专业的人
                    printf("\t\t\t恭喜你，成功保存到文件中，请在当前文件夹下The same major中查看\n");
                    system("pause");
                }
                break;
            }
            else if (ch == 'C')
            {
                 memset(stu2,0,sizeof(STU));
                 printf("\t\t\t请输入你想保存那个班级的信息？(例如：软件2017-1)");
                 scanf("%s",classes);
                 int n = Classstu1tostu2(stu1, stu2, studentnum, classes);//使结构体stu1中的相同班级的信息赋值给stu2
                 PrintInformation(stu2,n);
                 printf("\t\t\t这个班级共有%d人，你确定想要保存这个班级的信息到文件中？(Y/N)");
                 scanf(" %c",&ch1);
                 if (ch1 == 'Y' || ch1 =='y')
                 {
                     ClasstoFile(stu2,n);//用于新建一个文件储存相同班级的人
                     printf("\t\t\t恭喜你，成功保存到文件中，请在当前文件夹下The same class中查看\n");
                     system("pause");
                 }
                 break;
            }
            else if (ch == 'D')
            {
                 memset(stu2,0,sizeof(STU));
                 printf("\t\t\t请输入你想保存那个寝室的信息？(例如：926):");
                 scanf("%d",&dormitory);
                 int n = Dormitorystu1tostu2(stu1, stu2, studentnum, dormitory);//使结构体stu1中的相同寝室的信息赋值给stu2
                 PrintInformation(stu2,n);
                 printf("\t\t\t这个寝室共有%d人，你确定想要保存这个寝室信息到文件中？(Y/N)");
                 scanf(" %c",&ch1);
                 if (ch1 == 'Y' || ch1 =='y')
                 {
                     DormitorytoFile(stu2,n);//用于新建一个文件储存相同寝室的人
                     printf("\t\t\t恭喜你，成功保存到文件中，请在当前文件夹下The same dormitory中查看\n");
                     system("pause");
                 }
                 break;
            }
            else if (ch == 'E')
            {
                 memset(stu2,0,sizeof(STU));
                 printf("\t\t\t请输入你想保存那个省的人信息？(例如：山东省)");
                 scanf("%s",province);
                 int n = Provincestu1tostu2(stu1, stu2, studentnum, province);//使结构体stu1中的相同省份的信息赋值给stu2
                 PrintInformation(stu2,n);
                 printf("\t\t\t这个省份共有%d人，你确定想要保存这个省份信息到文件中？(Y/N)");
                 scanf(" %c",&ch1);
                 if (ch1 == 'Y' || ch1 =='y')
                 {
                     ProvincetoFile(stu2,n);//用于新建一个文件储存相同省份的人
                     printf("\t\t\t恭喜你，成功保存到文件中，请在当前文件夹下The same province中查看\n");
                     system("pause");
                 }
                 break;
            }
            else if (ch == 'F')
            {
                 memset(stu2,0,sizeof(STU));
                 printf("\t\t\t请输入你想保存那个民族的人信息？(例如：汉族)");
                 scanf("%s",nation);
                 int n = Nationstu1tostu2(stu1, stu2, studentnum, nation);//使结构体stu1中的相同民族的信息赋值给stu2
                 PrintInformation(stu2,n);
                 printf("\t\t\t这个民族共有%d人，你确定想要保存这个民族信息到文件中？(Y/N)");
                 scanf(" %c",&ch1);
                 if (ch1 == 'Y' || ch1 =='y')
                 {
                     NationtoFile(stu2,n);//用于新建一个文件储存相同省份的人
                     printf("\t\t\t恭喜你，成功保存到文件中，请在当前文件夹下The same nation中查看\n");
                     system("pause");
                 }
                 break;
            }
         case 6:
            SystemSetting(1);//系统设置
            break;
         case 7:
           quit();

    }
}

void SelectItem2()
{
    system("CLS");
    Menu9();
    ReadfromFile3(pupil,&number);
    char ch;
    do
    {
        scanf(" %c",&ch);
        if(ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch !='5' && ch != '6')
        {
            printf("亲，输入有误！请从新输入\a\n");
        }
    }while(ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '5' && ch != '6');
    system("cls");
    if (ch == '6')
        quit();
    else if (ch == '1')
    {
        printf("\t\t\t\t你想向一卡通里充多少钱？");
        int money,n;
        scanf("%d",&money);
        n = SearchStudentID2(pupil, stuID, number);
        AlterOnecard(pupil,number, n, money);//用于向一卡通里充钱
        WritetoFile5(pupil, number);
        printf("\t\t\t\t充值成功！\n \t\t\t\t正在返回请稍等........");
        Sleep(1000);

    }
    else if (ch == '2')
    {
        printf("\t\t\t\t你想充值多少网费？");
        int money,n;
        scanf("%d",&money);
        n = SearchStudentID2(pupil, stuID, number);
        AlterInterFee(pupil, number, n, money);//用于充值网费
        WritetoFile5(pupil, number);
        Sleep(1000);
    }
    else if (ch == '3')
    {
        printf("\t\t\t\t你想充值多少水电费？");
        int money,n;
        scanf("%d",&money);
        n = SearchStudentID2(pupil, stuID, number);
        AlterUtiltybill(pupil, number, n, money);//用于充值水电费
        WritetoFile5(pupil, number);
        Sleep(1000);
    }
    else if (ch == '4')
    {
        int n;
        n = SearchStudentID2(pupil, stuID, number);
        PrintInformation2(pupil,number,n);
        system("pause");
    }
    else if (ch == '5')
    {
        SystemSetting(2);
    }
}

void SystemSetting(int xuanzhe)//系统设置
{
    char ch;
    system("CLS");
    Menu6();
    do
    {
        scanf(" %c",&ch);
        if(ch != 'A' && ch != 'B' && ch != 'C' && ch != 'D')
        {
            printf("\t\t\t亲，输入有误！请重新输入\a");
        }
    }while(ch != 'A' && ch != 'B' && ch != 'C' && ch != 'D');
    if(ch == 'D')
        return;
    else if (ch == 'A')
    {
        system("CLS");
        print();
        printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t~~~~~~~字体颜色列表~~~~~~~~\n");
        printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t# 0=黑色      8=灰色      #\n");
        printf("\t\t\t\t\t# 1=蓝色      9=淡蓝色    #\n");
        printf("\t\t\t\t\t# 2=绿色      10=淡绿色   #\n");
        printf("\t\t\t\t\t# 3=湖蓝色    11=淡浅绿色 #\n");
        printf("\t\t\t\t\t# 4=红色      12=淡红色   #\n");
        printf("\t\t\t\t\t# 5=紫色      13=淡紫色   #\n");
        printf("\t\t\t\t\t# 6=黄色      14=淡黄色   #\n");
        printf("\t\t\t\t\t# 7=白色      15=亮白色   #\n");
        printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t请选择你要设置的字体颜色？");
        scanf("%d",&ziti);
        SelectFontColor(ziti);//选择字体颜色
        system("pause");
        return;
    }
    else if(ch == 'B')
    {
        system("CLS");
        print();
        printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t~~~~~~~背景颜色列表~~~~~~~~\n");
        printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t# 0=黑色      8=灰色      #\n");
        printf("\t\t\t\t\t# 1=蓝色      9=淡蓝色    #\n");
        printf("\t\t\t\t\t# 2=绿色      10=淡绿色   #\n");
        printf("\t\t\t\t\t# 3=湖蓝色    11=淡浅绿色 #\n");
        printf("\t\t\t\t\t# 4=红色      12=淡红色   #\n");
        printf("\t\t\t\t\t# 5=紫色      13=淡紫色   #\n");
        printf("\t\t\t\t\t# 6=黄色      14=淡黄色   #\n");
        printf("\t\t\t\t\t# 7=白色      15=亮白色   #\n");
        printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t请选择你要设置的背景颜色？");
        int n;
        scanf("%d",&n);
        SelectBackgroundColor(n);
        system("pause");
        return;
    }
    else if (ch == 'C')
    {
        char password2[M],password3[M];
        int n = 0;
        do
        {
            printf("\t\t\t请输入你的原密码：");
            int p = 0;
            char ch1;
            while((ch1 = getch()) != '\r')
            {
                if (ch1 == 8)
                {
                    putchar('\b');
                    putchar(' ');
                    putchar('\b');
                    if(p>0)
                        p--;
                }
                if (!isdigit(ch1) && !isalpha(ch1))
                continue;
                putch('*');
                password[p++] = ch1;
            }
            password[p] = 0;
            n = SearchID(enter, number, stuID, password);
            if(n == 0)
            {
                printf("\n\t\t\t密码错误\n");
                printf("\n\t\t\t请重新输入！\n");
                Sleep(1000);
            }
        }while (n == 0);
        do
        {
            printf("\n\t\t\t请输入你的的新密码：");
            int p = 0;
            char ch1;
            while((ch1 = getch()) != '\r')
            {
                if (ch1 == 8)
                {
                    putchar('\b');
                    putchar(' ');
                    putchar('\b');
                    if(p>0)
                        p--;
                }
                if (!isdigit(ch1) && !isalpha(ch1))
                continue;
                putch('*');
                password2[p++] = ch1;
            }
            password2[p] = 0;
            printf("\n\t\t\t请再次确认你输入的密码：");
            p = 0;
            while((ch1 = getch()) != '\r')
            {
                if (ch1 == 8)
                {
                    putchar('\b');
                    putchar(' ');
                    putchar('\b');
                    if(p>0)
                        p--;
                }
                if (!isdigit(ch1) && !isalpha(ch1))
                continue;
                putch('*');
                password3[p++] = ch1;
            }
            password3[p] = 0;
            if (strcmp(password3,password2) == 0)
                n = 1;
            else
            {
                n = 0;
                printf("\n\t\t\t亲，两次输入不一样，请再次输入。");
            }
        }while(n == 0);
        AlterPassword(enter, stuID, password2, number);//用于对密码的修改
        if(xuanzhe == 1)
            WritetoFile6(enter, number);
        else
            WritetoFile4(enter, number);
        printf("\n\t\t\t密码修改成功！\n");
        system("pause");
    }
}

void Menu() //定义主菜单
{
    printf("\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t\t\t\t┃ ****★欢迎使用学生宿舍信息管理系统☆****┃\n");
    printf("\t\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\t\t\t\t┃               ★主菜单☆                ┃\n");
    printf("\t\t\t\t *******************************************\n");
    printf("\t\t\t\t *\t┏━━━┓  ┏━━━━━━━━━━━┓               *\n");
    printf("\t\t\t\t *\t┃ 1.┃  ┃ ★信息载入┃               *\n");
    printf("\t\t\t\t *\t┗━━━┛  ┗━━━━━━━━━━━┛               *\n");
    printf("\t\t\t\t *\t┏━━━┓  ┏━━━━━━━━━━━┓               *\n");
    printf("\t\t\t\t *\t┃ 2.┃  ┃ ★信息查询┃               *\n");
    printf("\t\t\t\t *\t┗━━━┛  ┗━━━━━━━━━━━┛               *\n");
    printf("\t\t\t\t *\t┏━━━┓  ┏━━━━━━━━━━━┓               *\n");
    printf("\t\t\t\t *\t┃ 3.┃  ┃ ★信息修改┃               *\n");
    printf("\t\t\t\t *\t┗━━━┛  ┗━━━━━━━━━━━┛               *\n");
    printf("\t\t\t\t *\t┏━━━┓  ┏━━━━━━━━━━━┓               *\n");
    printf("\t\t\t\t *\t┃ 4.┃  ┃ ★信息统计┃               *\n");
    printf("\t\t\t\t *\t┗━━━┛  ┗━━━━━━━━━━━┛               *\n");
    printf("\t\t\t\t *\t┏━━━┓  ┏━━━━━━━━━━━┓               *\n");
    printf("\t\t\t\t *\t┃ 5.┃  ┃ ★信息保存┃               *\n");
    printf("\t\t\t\t *\t┗━━━┛  ┗━━━━━━━━━━━┛               *\n");
    printf("\t\t\t\t *\t┏━━━┓  ┏━━━━━━━━━━━┓               *\n");
    printf("\t\t\t\t *\t┃ 6.┃  ┃ ★系统设置┃               *\n");
    printf("\t\t\t\t *\t┗━━━┛  ┗━━━━━━━━━━━┛               *\n");
    printf("\t\t\t\t *\t┏━━━┓  ┏━━━━━━━━━━━┓               *\n");
    printf("\t\t\t\t *\t┃ 7.┃  ┃ ★退出系统┃               *\n");
    printf("\t\t\t\t *\t┗━━━┛  ┗━━━━━━━━━━━┛               *\n");
    printf("\t\t\t\t *******************************************\n");
    printf("\n");
    printf("\t\t\t\t★请输入你的操作：");
}

void Menu1()//声明子菜单 创建文件菜单 有从文件创建和从键盘输入
{
    print();
    printf("\t\t\t┃                           ★载入信息☆                            ┃\n");
    printf("\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t\t\t┃         ★A-----------------从键盘输入-----------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★B-----------------从文件导入-----------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★C-----------------返回主菜单-----------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\n");
    printf("\t\t\t★请输入你的操作：");
}

void Menu2()//声明子菜单 查询信息菜单 包括按姓名查询 按学号查询 按电话查询 综合查询
{
     print();
    printf("\t\t\t┃                           ★信息查询☆                            ┃\n");
    printf("\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t\t\t┃         ★A-----------------按学号查询-----------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★B-----------------按姓名查询-----------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★C-----------------按手机号查询---------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★D-----------------综合查询-------------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★E-----------------返回主菜单-----------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\n");
    printf("\t\t\t★请输入你的操作：");
}

void Menu3()//声明子菜单 更改信息
{
     print();
    printf("\t\t\t┃                           ★信息修改☆                            ┃\n");
    printf("\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t\t\t┃         ★A-----------------增加信息-------------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★B-----------------删除信息-------------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★C-----------------修改个人信息---------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★D-----------------返回主菜单-----------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\n");
    printf("\t\t\t★请输入你的操作：");
}

void Menu4() //声明子菜单 统计 包括按学号排序，统计男生和女生的人数，统计省份的人数和百分比，统计各专业的人数，统计
{
    print();
    printf("\t\t\t┃                           ★信息统计☆                            ┃\n");
    printf("\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t\t\t┃         ★A-----------------按学号排序-----------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★B-----------------统计男女人数及百分比-------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★C-----------------统计省份人数及百分比-------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★D-----------------统计专业人数及百分比-------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★E-----------------统计寝室人数---------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★F-----------------返回主菜单-----------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\n");
    printf("\t\t\t★请输入你的操作：");
}

void Menu5()//声明子菜单 保存信息 用于保存同省份 同班级 同专业 同班级 同寝室，同楼号的学生信息
{
    print();
    printf("\t\t\t┃                           ★信息保存☆                            ┃\n");
    printf("\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t\t\t┃         ★A-----------------保存全部信息---------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★B-----------------保存同专业的信息-----------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★C-----------------保存同班级的信息-----------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★D-----------------保存同寝室的信息-----------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★E-----------------保存同省份的信息-----------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★F-----------------保存同民族的信息-----------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★G-----------------返回主菜单-----------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\n");
    printf("\t\t\t★请输入你的操作：");
}

void Menu6()//声明子菜单 设置 用于设置背景颜色和字体颜色
{
    print();
    printf("\t\t\t┃                           ★系统设置☆                            ┃\n");
    printf("\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t\t\t┃         ★A-----------------更换字体颜色---------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★B-----------------更换背景颜色---------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★C-----------------修改密码-------------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ★D-----------------返回主菜单-----------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\n");
    printf("\t\t\t★请输入你的操作：");
}

void Menu7() //声明修改学生个人信息的菜单
{
   print();
    printf("\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t\t\t┃                           ★信息统计☆                            ┃\n");
    printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\t\t\t┃                           ☆修改个人信息                          ┃\n");
    printf("\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t\t\t┃         ☆a-----------------修改性别-------------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ☆b-----------------修改专业和班级-------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ☆c-----------------修改学号-------------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ☆d-----------------修改楼号-------------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ☆e-----------------修改寝室-------------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ☆f-----------------修改床位-------------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ☆g-----------------修改省份-------------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ☆h-----------------修改民族-------------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┃         ☆i-----------------修改电话-------------------           ┃\n");
    printf("\t\t\t┃                                                                   ┃\n");
    printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\n");
    printf("\t\t\t★请输入你的操作：");
}

void Menu8()//一开始的界面
{
    printf("\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t\t\t\t┃ ****★欢迎使用学生宿舍信息管理系统☆****┃\n");
    printf("\t\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\t\t\t\t********************************************\n");
    printf("\t\t\t\t*\t┏━━┓  ┏━━━━━━━━━━━━┓               *\n");
    printf("\t\t\t\t*\t┃ A┃  ┃★管理员入口┃               *\n");
    printf("\t\t\t\t*\t┗━━┛  ┗━━━━━━━━━━━━┛               *\n");
    printf("\t\t\t\t*\t┏━━┓  ┏━━━━━━━━━━┓                 *\n");
    printf("\t\t\t\t*\t┃ B┃  ┃★学生入口┃                 *\n");
    printf("\t\t\t\t*\t┗━━┛  ┗━━━━━━━━━━┛                 *\n");
    printf("\t\t\t\t*\t┏━━┓  ┏━━━━━━━━━━┓                 *\n");
    printf("\t\t\t\t*\t┃ C┃  ┃★退出系统┃                 *\n");
    printf("\t\t\t\t*\t┗━━┛  ┗━━━━━━━━━━┛                 *\n");
    printf("\t\t\t\t********************************************\n");
    printf("\n");
    printf("\t\t\t\t★请输入你的操作：");
}

void Menu9()//一开始界面
{
    printf("\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t\t\t\t┃ ****★欢迎使用学生宿舍信息管理系统☆****┃\n");
    printf("\t\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\t\t\t\t┃                ★主菜单☆               ┃\n");
    printf("\t\t\t\t ******************************************\n");
    printf("\t\t\t\t *\t┏━━━┓  ┏━━━━━━━━━━━━━┓            *\n");
    printf("\t\t\t\t *\t┃ 1.┃  ┃ ★一卡通充值┃            *\n");
    printf("\t\t\t\t *\t┗━━━┛  ┗━━━━━━━━━━━━━┛            *\n");
    printf("\t\t\t\t *\t┏━━━┓  ┏━━━━━━━━━━━┓              *\n");
    printf("\t\t\t\t *\t┃ 2.┃  ┃ ★网费充值┃              *\n");
    printf("\t\t\t\t *\t┗━━━┛  ┗━━━━━━━━━━━┛              *\n");
    printf("\t\t\t\t *\t┏━━━┓  ┏━━━━━━━━━━━━━┓            *\n");
    printf("\t\t\t\t *\t┃ 3.┃  ┃ ★水电费充值┃            *\n");
    printf("\t\t\t\t *\t┗━━━┛  ┗━━━━━━━━━━━━━┛            *\n");
    printf("\t\t\t\t *\t┏━━━┓  ┏━━━━━━━━━━━┓              *\n");
    printf("\t\t\t\t *\t┃ 4.┃  ┃ ★余额查询┃              *\n");
    printf("\t\t\t\t *\t┗━━━┛  ┗━━━━━━━━━━━┛              *\n");
    printf("\t\t\t\t *\t┏━━━┓  ┏━━━━━━━━━━━┓              *\n");
    printf("\t\t\t\t *\t┃ 5.┃  ┃ ★系统设置┃              *\n");
    printf("\t\t\t\t *\t┗━━━┛  ┗━━━━━━━━━━━┛              *\n");
    printf("\t\t\t\t *\t┏━━━┓  ┏━━━━━━━━━━━┓              *\n");
    printf("\t\t\t\t *\t┃ 6.┃  ┃ ★退出系统┃              *\n");
    printf("\t\t\t\t *\t┗━━━┛  ┗━━━━━━━━━━━┛              *\n");
    printf("\t\t\t\t ******************************************\n");
    printf("\n");
    printf("\t\t\t\t★请输入你的操作：");
}

void InputInformation(STU stu[], int studentnum)//声明输入函数用于用户输入的数据
{
    int i;
    for(i = 0; i < studentnum; i++)
    {
        printf("\t\t\t请输入第%d个人的信息\n",i+1);
        scanf("%s",stu[i].studentname);
        scanf("%s",stu[i].studentsex);
        scanf("%s",stu[i].major);
        scanf("%s",stu[i].classes);
        scanf("%ld",&stu[i].studentID);
        scanf("%s",stu[i].building);
        scanf("%d",&stu[i].dormitory);
        scanf("%d",&stu[i].bed);
        scanf("%s",stu[i].province);
        scanf("%s",stu[i].nation);
        scanf("%lld",&stu[i].phonenum);
    }
}

void example()//声明用户输入是样例的函数，
{
    printf("\t\t\t请根据要求输入数据,例如\n");
    printf("\t\t\t姓名 性别 专业      班级        学号        楼号      宿舍  床铺  省份    民族  手机号\n");
    printf("\t\t\t李浩 男   软件工程  软件2017-2  1767159234  23号楼    926   6     山东省  汉族  15847249689\n");
}

void print()
{
   printf("\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
   printf("\t\t\t┃ ****************★欢迎使用学生宿舍信息管理系统☆******************┃\n");
   printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void EstablishFile(char ch1)//用于判断用户是否将数据导入文件
{
    if(ch1 == 'Y' || ch1 == 'y')
    {
        printf("\t\t\t你是想存在原先的文件中还是想新建一个文件存储？(Y/N)（Y表示想重新建一个文件储存）");
        scanf(" %c",&ch1);
        if(ch1 == 'Y' || ch1 == 'y')
        {
            WritetoFile2(stu1,studentnum);
            printf("\t\t\t恭喜你，成功建立一个叫StudentInformation1的文件，请在当前文件夹下查看。\n");
        }
        else
        {
            WritetoFile3(stu1,studentnum);
            printf("\t\t\t恭喜你，成功把原文件的数据改变。\n");
        }
    }
}

void AlterInputname()//用于修改时输入姓名
{
     printf("\t\t\t请你输入你要修改人的姓名：(例如：李浩)");
     samename = 0;
     memset(a,0,sizeof(a));
}

void AlterSave()//用于判断修改后是否储存
{
    int ch1;
    printf("\t\t\t你是否想把修该后的信息导入信息库？(Y/N):");
    scanf(" %c",&ch1);
    EstablishFile(ch1);
}
void ReadfromFile(STU stu[],int *studentnum)//从原文件中读取数据
{
    FILE *fp;
    int i;
    if ((fp = fopen("StudentInformation.txt","r")) == NULL)
    {
        printf("Failure to open StudentInformation. txt!\n");
        exit(0);
    }
    for(i = 0; i < *studentnum; i++)
    {
        fscanf(fp,"%10s",stu[i].studentname);
        fscanf(fp,"%3s",stu[i].studentsex);
        fscanf(fp,"%20s",stu[i].major);
        fscanf(fp,"%15s",stu[i].classes);
        fscanf(fp,"%15ld",&stu[i].studentID);
        fscanf(fp,"%8s",stu[i].building);
        fscanf(fp,"%5d",&stu[i].dormitory);
        fscanf(fp,"%3d",&stu[i].bed);
        fscanf(fp,"%15s",stu[i].province);
        fscanf(fp,"%8s",stu[i].nation);
        fscanf(fp,"%15lld",&stu[i].phonenum);
    }
    fclose(fp);
}

void PrintInformation(STU stu[],int studentnum)//用于打印结构体中的信息
{
    int i;
    for(i = 0; i < studentnum ; i++)
    {
        printf("%-10s%3s%20s%15s%15ld%8s%5d%3d%15s%8s%15lld\n",
                    stu[i].studentname,
                    stu[i].studentsex,
                    stu[i].major,
                    stu[i].classes,
                    stu[i].studentID,
                    stu[i].building,
                    stu[i].dormitory,
                    stu[i].bed,
                    stu[i].province,
                    stu[i].nation,
                    stu[i].phonenum);
    }
}

int SearchStudentID(STU stu[], long int ID,int studentnum)//用于对学号的查找
{
    int i,k=-1, j = 0;
    for (i = 0; i < studentnum; i++)
    {
        if(stu[i].studentID == ID)
        {
            a[j++] = i;
            k = i;
        }
    }
    return k;
}

int SearchStudentname(STU stu[], char str[], int studentnum)//用于对姓名的查找
{
    int i,k=-1,j=0;
    for (i = 0; i < studentnum; i++)
    {
        if(strcmp(stu[i].studentname,str) == 0)
        {
            a[j++]=i;
            samename=samename+1;
            k = i;
        }
    }
    return k;
}

void PrintInformation1(STU stu[],int studentnum,int a[])//用于打印结构体中名字(包括重名)的信息
{
    int i,j=0;
    for(i = 0; i < studentnum ; i++)
    {
        if(i == a[j])
        {
            printf("%-10s%3s%20s%15s%15ld%8s%5d%3d%15s%8s%15lld\n",
                    stu[i].studentname,
                    stu[i].studentsex,
                    stu[i].major,
                    stu[i].classes,
                    stu[i].studentID,
                    stu[i].building,
                    stu[i].dormitory,
                    stu[i].bed,
                    stu[i].province,
                    stu[i].nation,
                    stu[i].phonenum);
            j++;
        }
    }
}

int SearchPhonenum(STU stu[], long long int phone, int studentnum)//用于对结构体中手机号的查询
{
    int i,k=-1, j = 0;
    for (i = 0; i < studentnum; i++)
    {
        if(stu[i].phonenum == phone)
        {
            a[j++]=i;
            k = i;
        }
    }
    return k;
}

int SearchComprehensive(STU stu[], STU student, int studentnum)//用于综合查询
{
    int i,k = -1, j =0;
    for(i = 0; i < studentnum; i++)
    {
        if((strcmp(stu1[i].studentname,student.studentname) == 0)&&
           (strcmp(stu1[i].studentsex,student.studentsex) == 0)&&
           (strcmp(stu1[i].major,student.major) == 0)&&
           (strcmp(stu1[i].classes,student.classes) == 0)&&
           (stu1[i].studentID == student.studentID)&&
           (strcmp(stu1[i].building,student.building) == 0)&&
           (stu1[i].dormitory == student.dormitory)&&
           (stu1[i].bed == student.bed)&&
           (strcmp(stu1[i].province,student.province) == 0)&&
           (strcmp(stu1[i].nation,student.nation) == 0)&&
           (stu[i].phonenum == student.phonenum))
        {
            a[j++] = i;
            k = i;
        }
    }
    return k;
}

void InputInformation1(STU stu[], int studentnum, int n)//用于信息修改时增加数据
{
    int i;
    for(i = studentnum; i < studentnum+n; i++)
    {
        printf("\t\t\t请输入增加的第%d个人的信息\n",i+1-studentnum);
        scanf("%s",stu[i].studentname);
        scanf("%s",stu[i].studentsex);
        scanf("%s",stu[i].major);
        scanf("%s",stu[i].classes);
        scanf("%ld",&stu[i].studentID);
        scanf("%s",stu[i].building);
        scanf("%d",&stu[i].dormitory);
        scanf("%d",&stu[i].bed);
        scanf("%s",stu[i].province);
        scanf("%s",stu[i].nation);
        scanf("%lld",&stu[i].phonenum);
    }
}

void WritetoFile1(STU stu[],int n)//用于向源文件文件中写入增加的数据
{
    FILE *fp;
    int i;
    if((fp = fopen("StudentInformation.txt","a")) == NULL)//“a”,使指针移动到文件的末尾，在文件末尾添加数据。
    {
        printf("Failure to open StudentInformation.text!\n");
        exit(0);
    }
    for (i = studentnum; i < n; i++)
    {
        fprintf(fp,"%10s%3s%20s%15s%15ld%8s%5d%3d%15s%8s%15lld\n",
                    stu[i].studentname,
                    stu[i].studentsex,
                    stu[i].major,
                    stu[i].classes,
                    stu[i].studentID,
                    stu[i].building,
                    stu[i].dormitory,
                    stu[i].bed,
                    stu[i].province,
                    stu[i].nation,
                    stu[i].phonenum);
    }
    fclose(fp);
}

void DeleteStudentInformation(STU stu[], int studentnum, int n)//用于删除文件指定的信息
{
    int i,j;
    for(i = 0; i < studentnum; i++)
    {
        if(i == n)//当查找到要删除的下标时
        {
            for (j = i; j < studentnum; j++)
            {
                strcpy(stu[j].studentname,stu[j+1].studentname);
                strcpy(stu[j].studentsex,stu[j+1].studentsex);
                strcpy(stu[j].major,stu[j+1].major);
                strcpy(stu[j].classes,stu[j+1].classes);
                stu[j].studentID = stu[j+1].studentID;
                strcpy(stu[j].building,stu[j+1].building);
                stu[j].dormitory = stu[j+1].dormitory;
                stu[j].bed == stu[j+1].bed;
                strcpy(stu[j].province,stu[j+1].province);
                strcpy(stu[j].nation,stu[j+1].nation);
                stu[j].phonenum == stu[j+1].phonenum;
            }
            studentnum--;
        }
    }
}

void WritetoFile2(STU stu[],int n)//用于修改和删除后的数据新建一个文件导入数据
{
    FILE *fp;
    int i;
    if((fp = fopen("StudentInformation1.txt","w")) == NULL)
    {
        printf("Failure to open StudentInformation1.text!\n");
        exit(0);
    }
    for (i = 0; i < n; i++)
    {
        fprintf(fp,"%-10s%3s%20s%15s%15ld%8s%5d%3d%15s%8s%15lld\n",
                    stu[i].studentname,
                    stu[i].studentsex,
                    stu[i].major,
                    stu[i].classes,
                    stu[i].studentID,
                    stu[i].building,
                    stu[i].dormitory,
                    stu[i].bed,
                    stu[i].province,
                    stu[i].nation,
                    stu[i].phonenum);
    }
    fclose(fp);
}

void WritetoFile3(STU stu[],int n)//用于改变的信息重新导入原文件
{
    FILE *fp;
    int i;
    if((fp = fopen("StudentInformation.txt","w")) == NULL)
    {
        printf("Failure to open StudentInformation.text!\n");
        exit(0);
    }
    for (i = 0; i < n; i++)
    {
        fprintf(fp,"%-10s%3s%20s%15s%15ld%8s%5d%3d%15s%8s%15lld\n",
                    stu[i].studentname,
                    stu[i].studentsex,
                    stu[i].major,
                    stu[i].classes,
                    stu[i].studentID,
                    stu[i].building,
                    stu[i].dormitory,
                    stu[i].bed,
                    stu[i].province,
                    stu[i].nation,
                    stu[i].phonenum);
    }
    fclose(fp);
}

void AlterSex(STU stu[], int n, char sex[],int studentnum)//用于修改性别
{
    int i;
    for (i = 0; i < studentnum; i++)
    {
        if (i == n)
        {
            strcpy(stu[i].studentsex,sex);
        }
    }
}

void AlerMajorAndClasses(STU stu[], int n, char classes[], char major[], int studentnum)//用于修改专业和班级
{
    int i;
    for (i = 0; i < studentnum; i++)
    {
        if (i == n)
        {
            strcpy(stu[i].major,major);
            strcpy(stu[i].classes,classes);
        }
    }
}

void AlerStudentID(STU stu[], int n, long int ID, int studentnum)//用于对学号的修改
{
    int i;
    for (i = 0; i < studentnum; i++)
    {
        if (i == n)
        {
            stu[i].studentID = ID;
        }
    }
}

void AlterBuilding(STU stu[], int n, char building[],int studentnum)//用于对楼号的修改
{
    int i;
    for (i = 0; i < studentnum; i++)
    {
        if (i == n)
        {
            strcpy(stu[i].building,building);
        }
    }
}

void AlerDormitory(STU stu[], int n, int dormitory, int studentnum)//用于对寝室的修改
{
    int i;
    for (i = 0; i < studentnum; i++)
    {
        if (i == n)
        {
            stu[i].dormitory = dormitory;
        }
    }
}

void AlerBed(STU stu[], int n, int bed, int studentnum)//用于床位的修改
{
    int i;
    for (i = 0; i < studentnum; i++)
    {
        if (i == n)
        {
            stu[i].bed = bed;
        }
    }
}

void AlerProvince(STU stu[], int n, char province[], int studentnum)//用于对来自省份的修改
{
    int i;
    for (i = 0; i < studentnum; i++)
    {
        if (i == n)
        {
            strcpy(stu[i].province,province);
        }
    }
}

void AlterNation(STU stu[], int n, char nation[], int studentnum)//用于修改民族信息
{
    int i;
    for (i = 0; i < studentnum; i++)
    {
        if (i == n)
        {
            strcpy(stu[i].nation,nation);
        }
    }
}

void AlterPhone(STU stu[], int n, long long int phone, int studentnum)//用手机号的修改
{
    int i;
    for (i = 0; i < studentnum; i++)
    {
        if(i == n)
        {
            stu[i].phonenum = phone;
        }
    }
}

void AscendingBubblingSort(STU stu[], int studentnum)//冒泡发升序排序
{
    int i,j;
    STU t;
    for(i = 0; i < studentnum - 1; i++)
    {
        for (j = i + 1; j < studentnum; j++)
        {
            if (stu[j].studentID > stu[i].studentID)
            {
                t = stu[i];
                stu[i] = stu[j];
                stu[j] = t;
            }
        }
    }
}

void DescendingBubblingSort(STU stu[], int studentnum)//冒泡发降序排序
{
    int i,j;
    STU t;
    for(i = 0; i < studentnum - 1; i++)
    {
        for (j = i + 1; j < studentnum; j++)
        {
            if (stu[j].studentID < stu[i].studentID)
            {
                t = stu[i];
                stu[i] = stu[j];
                stu[j] = t;
            }
        }
    }
}

int BoyNumber(STU stu[], int studentnum)//统计男生的人数
{
    int i,j=0;
    char boy[M] = "男";
    for (i = 0; i < studentnum; i++)
    {
        if (strcmp(stu[i].studentsex ,boy) == 0)
            j++;
    }
    return j;
}

int GirlNumber(STU stu[], int studentnum)//统计女生的人数
{
    int i,j=0;
    char girl[M] = "女";
    for (i = 0; i < studentnum; i++)
    {
        if (strcmp(stu[i].studentsex , girl) == 0)
            j++;
    }
    return j;
}

int ProvinceNumber(STU stu[], int studentnum, char province[])//统计某省的人数
{
    int i,j=0;
    for (i = 0; i < studentnum; i++)
    {
        if (strcmp(stu[i].province, province) == 0)
            j++;
    }
    return j;
}

int MajorNumber(STU stu[], int studentnum, char major[])//统计某专业的人数
{
    int i,j = 0;
    for (i = 0; i < studentnum; i++)
    {
        if (strcmp(stu[i].major, major) == 0)
        {
            j++;
        }
    }
    return j;
}

int DormitoryNumber(STU stu[], int studentnum, int dormitory)//统计某个寝室的人数
{
    int i,j = 0;
    for (i = 0; i < studentnum; i++)
    {
        if (stu[i].dormitory == dormitory)
        {
            j++;
        }
    }
    return j;
}

int  Majorstu1tostu2(STU stu1[], STU stu2[], int studentnum, char major[])//使结构体stu1中的相同专业的信息赋值给stu2
{
    int i,j = 0;
    for (i = 0; i < studentnum; i++)
    {
        if (strcmp(stu1[i].major,major) == 0)
        {
            stu2[j++] = stu1[i];
        }
    }
    return j;
}

void MajortoFile(STU stu[],int n)//用于新建一个文件储存相同专业的人
{
    FILE *fp;
    int i;
    if((fp = fopen("The same major.txt","w")) == NULL)
    {
        printf("Failure to open The same major.text!\n");
        exit(0);
    }
    for (i = 0; i < n; i++)
    {
        fprintf(fp,"%-10s%3s%20s%15s%15ld%8s%5d%3d%15s%8s%15lld\n",
                    stu[i].studentname,
                    stu[i].studentsex,
                    stu[i].major,
                    stu[i].classes,
                    stu[i].studentID,
                    stu[i].building,
                    stu[i].dormitory,
                    stu[i].bed,
                    stu[i].province,
                    stu[i].nation,
                    stu[i].phonenum);
    }
    fclose(fp);
}

int Classstu1tostu2(STU stu1[], STU stu2[], int studentnum, char classes[])//使结构体stu1中的相同班级的信息赋值给stu2
{
    int i,j = 0;
    for (i = 0; i < studentnum; i++)
    {
        if (strcmp(stu1[i].classes,classes) == 0)
        {
            stu2[j++] = stu1[i];
        }
    }
    return j;
}

void ClasstoFile(STU stu[],int n)//用于新建一个文件储存相同专业的人
{
    FILE *fp;
    int i;
    if((fp = fopen("The same class.txt","w")) == NULL)
    {
        printf("Failure to open The class major.text!\n");
        exit(0);
    }
    for (i = 0; i < n; i++)
    {
        fprintf(fp,"%-10s%3s%20s%15s%15ld%8s%5d%3d%15s%8s%15lld\n",
                    stu[i].studentname,
                    stu[i].studentsex,
                    stu[i].major,
                    stu[i].classes,
                    stu[i].studentID,
                    stu[i].building,
                    stu[i].dormitory,
                    stu[i].bed,
                    stu[i].province,
                    stu[i].nation,
                    stu[i].phonenum);
    }
    fclose(fp);
}

int Dormitorystu1tostu2(STU stu1[], STU stu2[], int studentnum, int dormitory)//使结构体stu1中的相同寝室的信息赋值给stu2
{
    int i,j = 0;
    for (i = 0; i < studentnum; i++)
    {
        if (stu1[i].dormitory == dormitory)
        {
            stu2[j++] = stu1[i];
        }
    }
    return j;
}

void DormitorytoFile(STU stu[],int n)//用于建立一个文件储存相同寝室的人
{
    FILE *fp;
    int i;
    if((fp = fopen("The same dormitory.txt","w")) == NULL)
    {
        printf("Failure to open The class dormitory.text!\n");
        exit(0);
    }
    for (i = 0; i < n; i++)
    {
        fprintf(fp,"%-10s%3s%20s%15s%15ld%8s%5d%3d%15s%8s%15lld\n",
                    stu[i].studentname,
                    stu[i].studentsex,
                    stu[i].major,
                    stu[i].classes,
                    stu[i].studentID,
                    stu[i].building,
                    stu[i].dormitory,
                    stu[i].bed,
                    stu[i].province,
                    stu[i].nation,
                    stu[i].phonenum);
    }
    fclose(fp);
}

int Provincestu1tostu2(STU stu1[], STU stu2[], int studentnum, char province[])//使结构体stu1中的相同省份的信息赋值给stu2
{
    int i,j = 0;
    for (i = 0; i < studentnum; i++)
    {
        if (strcmp(stu1[i].province, province) == 0)
        {
            stu2[j++] = stu1[i];
        }
    }
    return j;
}

void ProvincetoFile(STU stu[],int n)//用于新建一个文件储存相同省份的人
{
    FILE *fp;
    int i;
    if((fp = fopen("The same province.txt","w")) == NULL)
    {
        printf("Failure to open The same province.text!\n");
        exit(0);
    }
    for (i = 0; i < n; i++)
    {
        fprintf(fp,"%-10s%3s%20s%15s%15ld%8s%5d%3d%15s%8s%15lld\n",
                    stu[i].studentname,
                    stu[i].studentsex,
                    stu[i].major,
                    stu[i].classes,
                    stu[i].studentID,
                    stu[i].building,
                    stu[i].dormitory,
                    stu[i].bed,
                    stu[i].province,
                    stu[i].nation,
                    stu[i].phonenum);
    }
    fclose(fp);
}

int Nationstu1tostu2(STU stu1[], STU stu2[], int studentnum, char nation[])//使结构体stu1中的相同民族的信息赋值给stu2
{
    int i,j = 0;
    for (i = 0; i < studentnum; i++)
    {
        if (strcmp(stu1[i].nation, nation) == 0)
        {
            stu2[j++] = stu1[i];
        }
    }
    return j;
}

void NationtoFile(STU stu[],int n)//用于新建一个文件储存相同民族的人
{
    FILE *fp;
    int i;
    if((fp = fopen("The same nation.txt","w")) == NULL)
    {
        printf("Failure to open The same nation.text!\n");
        exit(0);
    }
    for (i = 0; i < n; i++)
    {
        fprintf(fp,"%-10s%3s%20s%15s%15ld%8s%5d%3d%15s%8s%15lld\n",
                    stu[i].studentname,
                    stu[i].studentsex,
                    stu[i].major,
                    stu[i].classes,
                    stu[i].studentID,
                    stu[i].building,
                    stu[i].dormitory,
                    stu[i].bed,
                    stu[i].province,
                    stu[i].nation,
                    stu[i].phonenum);
    }
    fclose(fp);
}

void SelectFontColor(int n)//选择字体颜色
{
    if (n == 0) system("color 20");
    else if (n == 1) system("color 21");
    else if (n == 2) system("color 22");
    else if (n == 3) system("color 23");
    else if (n == 4) system("color 24");
    else if (n == 5) system("color 25");
    else if (n == 6) system("color 26");
    else if (n == 7) system("color 27");
    else if (n == 8) system("color 28");
    else if (n == 9) system("color 29");
    else if (n == 10) system("color 2A");
    else if (n == 11) system("color 2B");
    else if (n == 12) system("color 2C");
    else if (n == 13) system("color 2D");
    else if (n == 14) system("color 2E");
    else if (n == 15) system("color 2F");
}

void SelectBackgroundColor(int n)
{
    switch(ziti)
    {
        case 0:
            if (n == 0) system("color 00");
            else if (n == 1) system("color 10");
            else if (n == 2) system("color 20");
            else if (n == 3) system("color 30");
            else if (n == 4) system("color 40");
            else if (n == 5) system("color 50");
            else if (n == 6) system("color 60");
            else if (n == 7) system("color 70");
            else if (n == 8) system("color 80");
            else if (n == 9) system("color 90");
            else if (n == 10) system("color A0");
            else if (n == 11) system("color B0");
            else if (n == 12) system("color C0");
            else if (n == 13) system("color D0");
            else if (n == 14) system("color E0");
            else if (n == 15) system("color F0");
            break;
        case 1:
            if (n == 0) system("color 01");
            else if (n == 1) system("color 11");
            else if (n == 2) system("color 21");
            else if (n == 3) system("color 31");
            else if (n == 4) system("color 41");
            else if (n == 5) system("color 51");
            else if (n == 6) system("color 61");
            else if (n == 7) system("color 71");
            else if (n == 8) system("color 81");
            else if (n == 9) system("color 91");
            else if (n == 10) system("color A1");
            else if (n == 11) system("color B1");
            else if (n == 12) system("color C1");
            else if (n == 13) system("color D1");
            else if (n == 14) system("color E1");
            else if (n == 15) system("color F1");
            break;
        case 2:
            if (n == 0) system("color 02");
            else if (n == 1) system("color 12");
            else if (n == 2) system("color 22");
            else if (n == 3) system("color 32");
            else if (n == 4) system("color 42");
            else if (n == 5) system("color 52");
            else if (n == 6) system("color 62");
            else if (n == 7) system("color 72");
            else if (n == 8) system("color 82");
            else if (n == 9) system("color 92");
            else if (n == 10) system("color A2");
            else if (n == 11) system("color B2");
            else if (n == 12) system("color C2");
            else if (n == 13) system("color D2");
            else if (n == 14) system("color E2");
            else if (n == 15) system("color F2");
            break;
        case 3:
            if (n == 0) system("color 03");
            else if (n == 1) system("color 13");
            else if (n == 2) system("color 23");
            else if (n == 3) system("color 33");
            else if (n == 4) system("color 43");
            else if (n == 5) system("color 53");
            else if (n == 6) system("color 63");
            else if (n == 7) system("color 73");
            else if (n == 8) system("color 83");
            else if (n == 9) system("color 93");
            else if (n == 10) system("color A3");
            else if (n == 11) system("color B3");
            else if (n == 12) system("color C3");
            else if (n == 13) system("color D3");
            else if (n == 14) system("color E3");
            else if (n == 15) system("color F3");
            break;
        case 4:
            if (n == 0) system("color 04");
            else if (n == 1) system("color 14");
            else if (n == 2) system("color 24");
            else if (n == 3) system("color 34");
            else if (n == 4) system("color 44");
            else if (n == 5) system("color 54");
            else if (n == 6) system("color 64");
            else if (n == 7) system("color 74");
            else if (n == 8) system("color 84");
            else if (n == 9) system("color 94");
            else if (n == 10) system("color A4");
            else if (n == 11) system("color B4");
            else if (n == 12) system("color C4");
            else if (n == 13) system("color D4");
            else if (n == 14) system("color E4");
            else if (n == 15) system("color F4");
            break;
        case 5:
            if (n == 0) system("color 05");
            else if (n == 1) system("color 15");
            else if (n == 2) system("color 25");
            else if (n == 3) system("color 35");
            else if (n == 4) system("color 45");
            else if (n == 5) system("color 55");
            else if (n == 6) system("color 65");
            else if (n == 7) system("color 75");
            else if (n == 8) system("color 85");
            else if (n == 9) system("color 95");
            else if (n == 10) system("color A5");
            else if (n == 11) system("color B5");
            else if (n == 12) system("color C5");
            else if (n == 13) system("color D5");
            else if (n == 14) system("color E5");
            else if (n == 15) system("color F5");
            break;
        case 6:
            if (n == 0) system("color 06");
            else if (n == 1) system("color 16");
            else if (n == 2) system("color 26");
            else if (n == 3) system("color 36");
            else if (n == 4) system("color 46");
            else if (n == 5) system("color 56");
            else if (n == 6) system("color 66");
            else if (n == 7) system("color 76");
            else if (n == 8) system("color 86");
            else if (n == 9) system("color 96");
            else if (n == 10) system("color A6");
            else if (n == 11) system("color B6");
            else if (n == 12) system("color C6");
            else if (n == 13) system("color D6");
            else if (n == 14) system("color E6");
            else if (n == 15) system("color F6");
            break;
        case 7:
            if (n == 0) system("color 07");
            else if (n == 1) system("color 17");
            else if (n == 2) system("color 27");
            else if (n == 3) system("color 37");
            else if (n == 4) system("color 47");
            else if (n == 5) system("color 57");
            else if (n == 6) system("color 67");
            else if (n == 7) system("color 77");
            else if (n == 8) system("color 87");
            else if (n == 9) system("color 97");
            else if (n == 10) system("color A7");
            else if (n == 11) system("color B7");
            else if (n == 12) system("color C7");
            else if (n == 13) system("color D7");
            else if (n == 14) system("color E7");
            else if (n == 15) system("color F7");
            break;
        case 8:
            if (n == 0) system("color 08");
            else if (n == 1) system("color 18");
            else if (n == 2) system("color 28");
            else if (n == 3) system("color 38");
            else if (n == 4) system("color 48");
            else if (n == 5) system("color 58");
            else if (n == 6) system("color 68");
            else if (n == 7) system("color 78");
            else if (n == 8) system("color 88");
            else if (n == 9) system("color 98");
            else if (n == 10) system("color A8");
            else if (n == 11) system("color B8");
            else if (n == 12) system("color C8");
            else if (n == 13) system("color D8");
            else if (n == 14) system("color E8");
            else if (n == 15) system("color F8");
            break;
        case 9:
            if (n == 0) system("color 09");
            else if (n == 1) system("color 19");
            else if (n == 2) system("color 29");
            else if (n == 3) system("color 39");
            else if (n == 4) system("color 49");
            else if (n == 5) system("color 59");
            else if (n == 6) system("color 69");
            else if (n == 7) system("color 79");
            else if (n == 8) system("color 89");
            else if (n == 9) system("color 99");
            else if (n == 10) system("color A9");
            else if (n == 11) system("color B9");
            else if (n == 12) system("color C9");
            else if (n == 13) system("color D9");
            else if (n == 14) system("color E9");
            else if (n == 15) system("color F9");
            break;
        case 10:
            if (n == 0) system("color 0A");
            else if (n == 1) system("color 1A");
            else if (n == 2) system("color 2A");
            else if (n == 3) system("color 3A");
            else if (n == 4) system("color 4A");
            else if (n == 5) system("color 5A");
            else if (n == 6) system("color 6A");
            else if (n == 7) system("color 7A");
            else if (n == 8) system("color 8A");
            else if (n == 9) system("color 9A");
            else if (n == 10) system("color AA");
            else if (n == 11) system("color BA");
            else if (n == 12) system("color CA");
            else if (n == 13) system("color DA");
            else if (n == 14) system("color EA");
            else if (n == 15) system("color FA");
            break;
        case 11:
            if (n == 0) system("color 0B");
            else if (n == 1) system("color 1B");
            else if (n == 2) system("color 2B");
            else if (n == 3) system("color 3B");
            else if (n == 4) system("color 4B");
            else if (n == 5) system("color 5B");
            else if (n == 6) system("color 6B");
            else if (n == 7) system("color 7B");
            else if (n == 8) system("color 8B");
            else if (n == 9) system("color 9B");
            else if (n == 10) system("color AB");
            else if (n == 11) system("color BB");
            else if (n == 12) system("color CB");
            else if (n == 13) system("color DB");
            else if (n == 14) system("color EB");
            else if (n == 15) system("color FB");
            break;
        case 12:
            if (n == 0) system("color 0C");
            else if (n == 1) system("color 1C");
            else if (n == 2) system("color 2C");
            else if (n == 3) system("color 3C");
            else if (n == 4) system("color 4C");
            else if (n == 5) system("color 5C");
            else if (n == 6) system("color 6C");
            else if (n == 7) system("color 7C");
            else if (n == 8) system("color 8C");
            else if (n == 9) system("color 9C");
            else if (n == 10) system("color AC");
            else if (n == 11) system("color BC");
            else if (n == 12) system("color CC");
            else if (n == 13) system("color DC");
            else if (n == 14) system("color EC");
            else if (n == 15) system("color FC");
            break;
        case 13:
            if (n == 0) system("color 0D");
            else if (n == 1) system("color 1D");
            else if (n == 2) system("color 2D");
            else if (n == 3) system("color 3D");
            else if (n == 4) system("color 4D");
            else if (n == 5) system("color 5D");
            else if (n == 6) system("color 6D");
            else if (n == 7) system("color 7D");
            else if (n == 8) system("color 8D");
            else if (n == 9) system("color 9D");
            else if (n == 10) system("color AD");
            else if (n == 11) system("color BD");
            else if (n == 12) system("color CD");
            else if (n == 13) system("color DD");
            else if (n == 14) system("color ED");
            else if (n == 15) system("color FD");
            break;
        case 14:
            if (n == 0) system("color 0E");
            else if (n == 1) system("color 1E");
            else if (n == 2) system("color 2E");
            else if (n == 3) system("color 3E");
            else if (n == 4) system("color 4E");
            else if (n == 5) system("color 5E");
            else if (n == 6) system("color 6E");
            else if (n == 7) system("color 7E");
            else if (n == 8) system("color 8E");
            else if (n == 9) system("color 9E");
            else if (n == 10) system("color AE");
            else if (n == 11) system("color BE");
            else if (n == 12) system("color CE");
            else if (n == 13) system("color DE");
            else if (n == 14) system("color EE");
            else if (n == 15) system("color FE");
            break;
        case 15:
            if (n == 0) system("color 0F");
            else if (n == 1) system("color 1F");
            else if (n == 2) system("color 2F");
            else if (n == 3) system("color 3F");
            else if (n == 4) system("color 4F");
            else if (n == 5) system("color 5F");
            else if (n == 6) system("color 6F");
            else if (n == 7) system("color 7F");
            else if (n == 8) system("color 8F");
            else if (n == 9) system("color 9F");
            else if (n == 10) system("color AF");
            else if (n == 11) system("color BF");
            else if (n == 12) system("color CF");
            else if (n == 13) system("color DF");
            else if (n == 14) system("color EF");
            else if (n == 15) system("color FF");
            break;
    }
}

void StudentEenter()
{
    char ch;
    do
    {
        stuID = 0;
        system("cls");
        print();
        char ch1;
        int p = 0;
        int j,k;
        char output1[5]="";
        char output2[5];
        char a[36]="abcdefghijklmnopqrstuvwxyz123456789";//定义一个包含26个小写字母和9个数字的字符串
        printf("\t\t\t☆请输入你的用户名:");
        scanf("%lld",&stuID);
        printf("\t\t\t☆请输入你的密码：");
        while((ch1 = getch()) != '\r')
        {
            if (ch1 == 8)
            {
                putchar('\b');
                putchar(' ');
                putchar('\b');
                if(p>0)
                    p--;
            }
            if (!isdigit(ch1) && !isalpha(ch1))
                continue;
            putch('*');
            password[p++] = ch1;
        }
        password[p] = 0;
        printf("\n\t\t\t☆验证码\t");
        srand((int)time(0));//初始化随机数发生器
        for(k=0;k<4;k++)
        {
            j= rand()%35;//取得0~25的随机数
            printf("%c",a[j]);//从字符串中随机取一个小写字母，并循环四次，获得四个随机的小写字母
            output1[k]=a[j];
        }
        printf("\n\t\t\t请输入验证码：");
        scanf("%s",output2);
        if(strcmp(output1,output2) == 0)
        {
            int i = SearchID(enter, number, stuID, password);
            if(i == -1)
            {
                printf("\n\t\t\t!你输入的用户名不存在。\n");
                printf("\t\t\t!请重新输入！\n");
                Sleep(1000);
            }
            else if (i == 0)
            {
                printf("\n\t\t\t!亲，密码错误\n");
                printf("\t\t\t!请重新输入！\n");
                Sleep(1000);
            }
            else
            {
                ch = 'Y';
                printf("\n\t\t\t亲，成功登陆!\n");
                printf("\t\t\t正在加载请稍后！\n");
                Sleep(1000);
                Load();
            }
        }
        else
        {
            printf("\n\t\t\t亲，验证码输入错误！");
            printf("\n\t\t\t请重新输入！");
            Sleep(1000);
        }
    }while(ch != 'Y');
}

void WritetoFile4(STU3 enter[], int n)
{
    FILE *fp;
    int i;
    if((fp = fopen("student register.txt","w")) == NULL)
    {
        printf("Failure to open student register.text!\n");
        exit(0);
    }
    for (i = 0; i < n; i++)
    {
        fprintf(fp,"%15lld%20s\n",enter[i].ID,enter[i].password);
    }
    fclose(fp);
}

void ReadfromFile1(STU3 enter[],int *n)
{
    FILE *fp;
    int i;
    if ((fp = fopen("student register.txt","r")) == NULL)
    {
        printf("Failure to open student register.txt!\n");
        exit(0);
    }
    for(i = 0; i < *n; i++)
    {
        fscanf(fp,"%15lld",&enter[i].ID);
        fscanf(fp,"%20s",enter[i].password);
    }
    fclose(fp);
}
void ReadfromFile2(STU3 enter[],int *n)
{
    FILE *fp;
    int i;
    if ((fp = fopen("Administrator register.txt","r")) == NULL)
    {
        printf("Failure to open Administrator register.txt!\n");
        exit(0);
    }
    for(i = 0; i < *n; i++)
    {
        fscanf(fp,"%15lld",&enter[i].ID);
        fscanf(fp,"%20s",enter[i].password);
    }
    fclose(fp);
}

int SearchID(STU3 enter[], int n, long long int ID, char password[])
{
    int i;
    int flag = -1;
    for (i = 0; i < n; i++)
    {
        if (ID == enter[i].ID)
        {
            flag = 0;
            if (strcmp(enter[i].password,password) == 0)
                flag = 1;
        }
    }
    return flag;
}

void Load()
{
   	char str[35]={0};
	int i;
	system("cls");
	for(i=0;i<34;i+=2)
	{
        printf("\n\n\n\n\n\n\t\t\tLoading, please wait...\n");
		str[i]=0xa8;
		str[i+1]=0x80;
		printf("\t\t\t%-35s",str);
		fflush(stdout);
		Sleep(60);
		system("cls");
	}
}

void WritetoFile5(STU2 pupil[], int n)
{
    FILE *fp;
    int i;
    if((fp = fopen("Student Balance.txt","w")) == NULL)
    {
        printf("Failure to open Student Balance.txt!\n");
        exit(0);
    }
    for (i = 0; i < n; i++)
    {
        fprintf(fp,"%15lld%20s%10d%10d%10d\n",
                    pupil[i].stuID,
                    pupil[i].stuname,
                    pupil[i].Onecard,
                    pupil[i].Interfee,
                    pupil[i].utilitybill);
    }
    fclose(fp);
}

void ReadfromFile3(STU2 pupil[],int *n)
{
    FILE *fp;
    int i;
    if ((fp = fopen("Student Balance.txt","r")) == NULL)
    {
        printf("Failure to openStudent Balance.txt!\n");
        exit(0);
    }
    for(i = 0; i < *n; i++)
    {
        fscanf(fp,"%15lld",&pupil[i].stuID);
        fscanf(fp,"%20s",pupil[i].stuname);
        fscanf(fp,"%10d",&pupil[i].Onecard);
        fscanf(fp,"%10d",&pupil[i].Interfee);
        fscanf(fp,"%10d",&pupil[i].utilitybill);
    }
    fclose(fp);
}

int SearchStudentID2(STU2 pupil[], long int ID,int number)//用于对学号的查找
{
    int i, k;
    for (i = 0; i < number; i++)
    {
        if(pupil[i].stuID == stuID)
        {
            k = i;
        }
    }
    return k;
}

void PrintInformation2(STU2 pupil[],int number,int n)//用于打印学生的余额信息
{
    printf("         学号                 姓名       一卡通       网费    水电费\n");
    int i,j=0;
    for(i = 0; i < number ; i++)
    {
        if(i == n)
        {
            printf("%15lld%20s%10d%10d%10d\n",
                            pupil[i].stuID,
                            pupil[i].stuname,
                            pupil[i].Onecard,
                            pupil[i].Interfee,
                            pupil[i].utilitybill);
        }
    }
}

void AlterOnecard(STU2 pupil[], int number, int n, int money)//用于向一卡通里充钱
{
    int i;
    for (i = 0; i < number; i++)
    {
        if (i == n)
        {
            pupil[i].Onecard += money;
        }
    }
}

void AlterInterFee(STU2 pupil[], int number, int n, int money)//用于充值网费
{
    int i;
    for (i = 0; i < number; i++)
    {
        if (i == n)
        {
            if(money > pupil[i].Onecard)
            {
                printf("\t\t\t\t一卡通余额不足，请先充值一卡通！");
                return;
            }
            else
            {
                pupil[i].Onecard-=money;
                pupil[i].Interfee+=money;
                printf("\t\t\t\t充值成功！\n \t\t\t\t正在返回请稍等........");
            }
        }
    }
}

void AlterUtiltybill(STU2 pupil[], int number, int n, int money)//用于充值水电费
{
    int i;
    for (i = 0; i < number; i++)
    {
        if (i == n)
        {
            if(money > pupil[i].Onecard)
            {
                printf("\t\t\t\t一卡通余额不足，请先充值一卡通！");
                return;
            }
            else
            {
                pupil[i].Onecard-=money;
                pupil[i].utilitybill+=money;
                printf("\t\t\t\t充值成功！\n 正在返回请稍等........");
            }
        }
    }
}

void AlterPassword(STU3 enter[], long long int ID, char password[], int n)//用于对密码的修改
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (ID == enter[i].ID)
        {
            strcpy(enter[i].password,password);
        }
    }
}

void WritetoFile6(STU3 enter[], int n)//用于对密码的写入
{
    FILE *fp;
    int i;
    if((fp = fopen("Administrator register.txt","w")) == NULL)
    {
        printf("Failure to open Administrator register.txt!\n");
        exit(0);
    }
    for (i = 0; i < n; i++)
    {
        fprintf(fp,"%15lld%20s\n",enter[i].ID,enter[i].password);
    }
    fclose(fp);
}

void color_back()              //设置文本字符的颜色
{
        int i;
        srand((unsigned)time(NULL));      //初始化时钟
        i=rand()%15;                                 //随机一个0到14的整数
        switch(i)
        {
               case 0: system("color 27");break;
               case 1: system("color 28");break;
               case 2: system("color 39");break;
               case 3: system("color 3A");break;
               case 4: system("color 3B");break;
               case 5: system("color 3C");break;
               case 6: system("color 3D");break;
               case 7: system("color 3E");break;
               case 8: system("color 2F");break;
               case 9: system("color 21");break;
               case 10:system("color 22");break;
               case 11:system("color 23");break;
               case 12:system("color 24");break;
               case 13:system("color 25");break;
               case 14:system("color 26");break;
        }
}

void display_picture()
{
    system("cls");
    printf("\n\n\n\n\n\n\n");
    printf("\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
    printf("\t\t☆\t\t\t\t\t\t\t\t\t☆\n");
    color_back();                  //随机一个文本颜色
    Sleep(400);                    //让系统暂停300毫秒，1秒 = 1 000 毫秒
    printf("\t\t☆\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\t\t\t\t☆\n");
    printf("\t\t☆\t\t┃谢谢你的使用，欢迎下次光临！┃\t\t\t\t☆\n");
    printf("\t\t☆\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\t\t\t\t☆\n");
    color_back();
    Sleep(400);
    printf("\t\t☆\t\t\t\t\t\t\t\t\t☆\n");
    printf("\t\t☆\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\t\t☆\n");
    printf("\t\t☆\t\t┃Thank you for your use. Welcome next time┃\t\t☆\n");
    printf("\t\t☆\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\t\t☆\n");
    color_back();
    Sleep(400);
    printf("\t\t☆\t\t\t\t\t\t\t\t\t☆\n");
    printf("\t\t☆\t\t┏━━━━━━━┓\t\t\t┏━━━━━┓\t\t\t☆\n");
    printf("\t\t☆\t\t┃ 制作人┃\t\t\t┃ 李浩┃\t\t\t☆\n");
    printf("\t\t☆\t\t┗━━━━━━━┛\t\t\t┗━━━━━┛\t\t\t☆\n");
    color_back();
    Sleep(400);
    printf("\t\t☆\t\t\t\t\t\t\t\t\t☆\n");
    printf("\t\t☆\t\t┏━━━━━┓\t\t\t\t┏━━━━━━━━━┓\t\t☆\n");
    printf("\t\t☆\t\t┃ 时间┃\t\t\t\t┃ 2017.12 ┃\t\t☆\n");
    printf("\t\t☆\t\t┗━━━━━┛\t\t\t\t┗━━━━━━━━━┛\t\t☆\n");
    color_back();
    Sleep(400);
    printf("\t\t☆\t\t\t\t\t\t\t\t\t☆\n");
    printf("\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
    printf("\n\n");
}

void quit()
{
    int i;                                   //用户循环
    for(i=0;i<5;i++)
        display_picture();      //打印动画效果
    exit(0);
}

void show()
{
    int k;
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t  ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t\t\t\t  ┃ ★欢迎使用学生宿舍信息管理系统☆┃\n");
    printf("\t\t\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\n\n\n\n");
    printf("\t\t\t\t\t正在载入数据，请稍等......\n\n");
    for (k = 0; k < 40; k++)
    {
        if(k > 10)
            Sleep(10);
        else Sleep(50);
        printf("■ ");
    }
}
