#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#define N 10000//����곣����ѧ�����������
#define M 30//����곣�����ַ������������
typedef struct student//����嶨��һ��ѧ���Ļ�����Ϣ
{
    char studentname[M];//����
    char studentsex[M];//�Ա�
    char major[M];//רҵ
    char classes[M];//�༶
    long int studentID;//ѧ��
    char building[M];//����¥��
    int dormitory;//���Һ�
    int bed;//��λ
    char province[M];//���Ե�ʡ��
    char nation[M];//����
    long long int phonenum;//�绰
}STU;

typedef struct studententer
{
    long long int stuID;
    char stuname[M];
    int Onecard;//һ��ͨ����
    int Interfee;//����
    int utilitybill;//ˮ���
}STU2;

typedef struct entrance
{
    long long ID;
    char password[M];
}STU3;


STU stu1[N],stu2[N];//��������STU���͵�����
int number = 703;//����ȫ�ֱ���number���ڼ����ļ��ж���������
int studentnum;//����studentnum���ڼ�������������ʹ��ļ��е��������
int samename = 0;//����ȫ�ֱ���samename�������ṹ������ͬ�������ж���
int a[N];
int ziti = 0;

STU3 enter[M];
long long int stuID;
char password[M];
void WritetoFile4(STU3 enter[], int n);//��ѧ������������д������
void ReadfromFile1(STU3 enter[],int *n);//��ȡѧ���������˺���Ϣ
void ReadfromFile2(STU3 enter[],int *n);//��ȥ����Ա�������˺���Ϣ
int SearchID(STU3 enter[],int n,long long int ID, char password[]);//���ں˶�ѧ�Ŷ�Ӧ������
void Menu8();//���ڿ�ʼ�˵�
void Menu9();//���ڶ�ѧ��������Ϣ����ѡ
void StudentEenter();//�������������
void Load();//���ڼ��صĶ���
void SelectItem2();//����ѧ��������ݵ�ѡ��

STU2 pupil[N];
void WritetoFile5(STU2 pupil[], int n);//�����Ա�������������д������
void ReadfromFile3(STU2 pupil[],int *n);//���ļ��ж�ȡѧ���ķ�����Ϣ
int SearchStudentID2(STU2 pupil[], long int ID,int number);//���ڶ�ѧ�ŵĲ���
void PrintInformation2(STU2 pupil[],int number,int n);//���ڴ�ӡѧ���������Ϣ
void AlterOnecard(STU2 pupil[], int number, int n, int money);//������һ��ͨ���Ǯ
void AlterInterFee(STU2 pupil[], int number, int n, int money);//���ڳ�ֵ����
void AlterUtiltybill(STU2 pupil[], int number, int n, int money);//���ڳ�ֵˮ���
void SystemSetting(int xuanzhe);//ϵͳ����
void AlterPassword(STU3 enter[], long long int stuID, char password[], int number);//���ڶ�������޸�
void WritetoFile6(STU3 enter[], int n);//���ڶ������д��

void Menu(); //�������˵�
void Menu1(); //�����Ӳ˵� �����ļ��˵� �д��ļ������ʹӼ�������
void Menu2(); //�����Ӳ˵� ��ѯ��Ϣ�˵� ���������� ѧ�� �ۺϲ�ѯ
void Menu3(); //�����Ӳ˵� ������Ϣ
void Menu4(); //�����Ӳ˵� ͳ�� ������ѧ������ͳ��������Ů����������ͳ��ʡ�ݵ������Ͱٷֱȣ�ͳ�Ƹ�רҵ��������ͳ��
void Menu5(); //�����Ӳ˵� ������Ϣ ���ڱ���ͬʡ�� ͬ�༶ ͬרҵ ͬ�༶ ͬ���ң�ͬ¥�ŵ�ѧ����Ϣ
void Menu6(); //�����Ӳ˵� ���� �������ñ�����ɫ��������ɫ
void Menu7(); //�����޸�ѧ��������Ϣ�Ĳ˵�
void SelectItem(); //����ѡ����Ŀ
void InputInformation(STU stu[],int studentnum);//�������뺯�������û����������
void example(); //�����û���������
void ReadfromFile(STU stu[],int *studentnum);//��ԭ�ļ��ж�ȡ����
void PrintInformation(STU stu[],int studentnum);//���ڴ�ӡ�ṹ���е���Ϣ
int SearchStudentID(STU stu[],long int ID,int studentnum);//���ڶ�ѧ�ŵĲ�ѯ
int SearchStudentname(STU stu[], char str[], int studentnum);//���ڶ������Ĳ�ѯ
void PrintInformation1(STU stu[],int studentnum,int a[]);//���ڴ�ӡ�ṹ����ָ��λ�õ���Ϣ
int SearchPhonenum(STU stu[], long long int phone, int studentnum);//���ڶԽṹ�����ֻ��ŵĲ�ѯ
int SearchComprehensive(STU stu[], STU student, int studentnum);//�����ۺϲ�ѯ
void InputInformation1(STU stu[],int studentnum, int n);//������Ϣ�޸�ʱ��������
void WritetoFile1(STU stu[],int n);//ԭ�ļ��ļ��е������ӵ���Ϣ��
void DeleteStudentInformation(STU stu[], int studentnum, int n);//����ɾ����Ϣ
void EstablishFile(char ch1);//�����ж��û��Ƿ����ݵ����ļ�
void WritetoFile2(STU stu[], int n);//�����½�һ���ļ������޸ĺ����Ϣ
void WritetoFile3(STU stu[], int n);//�����޸ĺ�����ݵ���Դ�ļ���
void AlterInputname();//�����޸�ʱ��������
void AlterSave();//�����ж��޸ĺ��Ƿ񴢴�
void AlterSex(STU stu[], int n, char sex[],int studentnum);//�����޸��Ա�
void AlerMajorAndClasses(STU stu[], int n, char classes[], char major[], int studentnum);//�����޸�רҵ�Ͱ༶
void AlerStudentID(STU stu[], int n,long int ID, int studentnum);//���ڶ�ѧ�ŵ��޸�
void AlterBuilding(STU stu[], int n, char building[],int studentnum);//���ڶ�¥�ŵ��޸�
void AlerDormitory(STU stu[], int n, int dormitory, int studentnum);//���ڶ����ҵ��޸�
void AlerBed(STU stu[], int n, int bed, int studentnum);//���ڴ�λ���޸�
void AlerProvince(STU stu[], int n, char province[], int studentnum);//���ڶ�����ʡ�ݵ��޸�
void AlterNation(STU stu[], int n, char nation[], int studentnum);//�����޸�������Ϣ
void AlterPhone(STU stu[], int n, long long int phone, int studentnum);//���ֻ��ŵ��޸�
void AscendingBubblingSort(STU stu[], int studentnum);//ð�ݷ���������
void DescendingBubblingSort(STU stu[], int studentnum);//ð�ݷ���������
int BoyNumber(STU stu[], int studentnum);//ͳ������������
int GirlNumber(STU stu[], int studentnum);//ͳ��Ů��������
int ProvinceNumber(STU stu[], int studentnum, char province[]);//ͳ��ĳʡ������
int MajorNumber(STU stu[], int studentnum, char major[]);//ͳ��ĳרҵ������
int DormitoryNumber(STU stu[], int studentnum, int dormitory);//ͳ��ĳ�����ҵ�����
int Majorstu1tostu2(STU stu1[], STU stu2[], int studentnum, char major[]);//ʹ�ṹ��stu1�е���ͬרҵ����Ϣ��ֵ��stu2
void MajortoFile(STU stu[],int n);//�����½�һ���ļ�������ͬרҵ����
int Classstu1tostu2(STU stu1[], STU stu2[], int studentnum, char classes[]);//ʹ�ṹ��stu1�е���ͬ�༶����Ϣ��ֵ��stu2
void ClasstoFile(STU stu[],int n);//�����½�һ���ļ�������ͬרҵ����
int Dormitorystu1tostu2(STU stu1[], STU stu2[], int studentnum, int dormitory);//ʹ�ṹ��stu1�е���ͬ���ҵ���Ϣ��ֵ��stu2
void DormitorytoFile(STU stu[],int n);//���ڽ���һ���ļ�������ͬ���ҵ���
int Provincestu1tostu2(STU stu1[], STU stu2[], int studentnum, char province[]);//ʹ�ṹ��stu1�е���ͬʡ�ݵ���Ϣ��ֵ��stu2
void ProvincetoFile(STU stu[],int n);//�����½�һ���ļ�������ͬʡ�ݵ���
int Nationstu1tostu2(STU stu1[], STU stu2[], int studentnum, char nation[]);//ʹ�ṹ��stu1�е���ͬ�������Ϣ��ֵ��stu2
void NationtoFile(STU stu[],int n);//�����½�һ���ļ�������ͬ�������
void SelectFontColor(int n);//ѡ��������ɫ
void SelectBackgroundColor(int n);//ѡ�񱳾���ɫ
void print();
void color_back();              //�����ı��ַ�����ɫ
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
            printf("\t\t\t\t���ף�������������������\a");
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

void SelectItem() //����ѡ���� �����Ƕ��������Ͷ��Ӻ����ĵ��ã�����������ĺ���
{
    Menu();
    char ch; //�����ַ�ch���ڶ��Ӳ˵���ѡ���ѡ��
    char ch1;//�����ַ�ch1����ϵͳ���ж�(Y/N)
    char ch2;//�����ַ�ch1���ڶ����Ӳ˵����Ӳ˵����Ӳ˵�����ѡ���ѡ��
    int flag = -1; //����flag���ڶ����˵���ѡ���е�ѡ��
    char choose[M];//�����ַ������ڼ�����������������ʡ�ݣ�����¥����Ϣ�����ڲ�ѯ��
    char sex[M];//�����ַ��������Ա���޸�
    char major[M];//�����ַ�������רҵ���޸�
    char classes[M];//�����ַ������ڶ԰༶���޸�
    long int ID;//�������Ҫ��ѯ��ѧ�ţ����ڶ�ѧ�ŵĲ��Һ��޸�
    long long int phone;//�������phone�����ڶ��ֻ��ŵĲ��Һ��޸�
    char building[M];//�������building,���ڶ�¥�ŵ��޸�
    int dormitory;//�������dormitory�����ڶ�������޸�
    int bed;//�������bed,����Դ�λ���޸�
    char province[M];//�������province,���ڶ�ʡ�ݵ��޸�
    char nation[M];//�������nation,���ڶ�������޸�

    static int temp = 0; //����һ����̬���������ڼ������ʹ���Ƿ�������Ϣ��
    do
    {
       scanf("%d",&flag);
        if((flag != 1)&&(flag != 7)&&(flag != 6)&&(temp == 0))
        {
            fflush(stdin);//������벻�����ڻ����ַ�
            printf("\t\t\t\t\a�ף��״�ʹ�����ȡ�������Ϣ��\n");
            printf("\t\t\t\t��������Ĳ�����");
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
                    printf("\t\t\t�ף�������������������\a");
                }
            }while(ch != 'A' && ch != 'B' && ch != 'C');//��do..while ��ʽ�ĸ�ʽ����֤����ĺϷ��ԣ�����ܶ��������д���Ժ�һһ������
            if (ch == 'C')//�������C�������˵�
                break;
            else if (ch == 'A')
            {
                  temp--;
                  example();
                  printf("\t\t\t��������Ҫ�����������");
                  scanf("%d",&studentnum);
                  InputInformation(stu1,studentnum);
                  printf("\t\t\t�Ƿ�Ҫ�����ݳ�������Ļ��(Y/N)?");
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
                printf("\t\t\t����ļ���һ����%d������\n",number);
                printf("\t\t\t����������ļ��е�����������ݣ�");
                scanf("%d",&studentnum);
                ReadfromFile(stu1,&studentnum);
                printf("\t\t\t��ϲ�㣬�ɹ��������ݣ�\n");
                printf("\t\t\t�Ƿ�Ҫ�����ݳ�������Ļ��(Y/N)?");
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
                    printf("\t\t\t�ף������������������\a");
                }
            }while(ch != 'A' && ch != 'B' && ch != 'C' && ch != 'D' && ch != 'E');
            if (ch == 'E')//���ch == 'E'�򷵻����˵�
                break;
            else if (ch == 'A')
            {
                printf("\t\t\tѧ�ŵ�λ��Ϊʮλ�������� 1767159234\n");
                do
                {
                    printf("\t\t\t��������Ҫ��ѯ��ѧ�ţ�");
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
                        printf("\t\t\t�Բ����������ѧ�Ų����ڡ�\n");
                    }
                    printf("\t\t\t�㻹����ѧ�Ų�ѯ��Ϣ��(Y/N)?");
                    scanf(" %c",&ch1);
                }while (ch1 == 'Y' || ch1 == 'y');
                break;
            }
            else if (ch == 'B')
            {
                do
                {
                    printf("\t\t\t����������Ҫ��ѯ������������ ��ƣ���");
                    scanf("%s",choose);
                    int n;
                    samename = 0;
                    memset(a,0,sizeof(a));
                    n = SearchStudentname(stu1,choose,studentnum);
                    if(n != -1)
                    {
                        PrintInformation1(stu1, studentnum, a);
                        printf("\t\t\t����������нС�%s������һ����%d��\n",choose,samename);
                    }
                    else
                    {
                        printf("\t\t\t�Բ�������������������ڡ�\n");
                    }
                    printf("\t\t\t�㻹����������ѯ��Ϣ��(Y/N)?");
                    scanf(" %c",&ch1);
                }while (ch1 == 'Y' || ch1 == 'y');
                break;
            }
            else if (ch == 'C')
            {
                do
                {
                    printf("\t\t\t����������Ҫ��ѯ���ֻ��ţ�����15847249199����");
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
                        printf("\t\t\t�Բ�����������ֻ��Ų����ڡ�\n");
                    }
                    printf("\t\t\t�㻹�����ֻ��Ų�ѯ��Ϣ��(Y/N)?");
                    scanf(" %c",&ch1);
                }while (ch1 == 'Y' || ch1 == 'y');
                break;
            }
            else if (ch == 'D')
            {
                do
                {
                    example();
                    printf("\t\t\t��������Ҫ��ѯ�˵���ϸ��Ϣ\n");
                    STU student;
                    printf("\t\t\t��������Ҫ��ѯ�˵����֣�");
                    scanf("%s",student.studentname);
                    printf("\t\t\t��������Ҫ��ѯ�˵��Ա�");
                    scanf("%s",student.studentsex);
                    printf("\t\t\t��������Ҫ��ѯ�˵�רҵ��");
                    scanf("%s",student.major);
                    printf("\t\t\t��������Ҫ��ѯ�˵İ༶��");
                    scanf("%s",student.classes);
                    printf("\t\t\t��������Ҫ��ѯ�˵�ѧ�ţ�");
                    scanf("%ld",&student.studentID);
                    printf("\t\t\t��������Ҫ��ѯ�˵�ס��¥�ţ�");
                    scanf("%s",student.building);
                    printf("\t\t\t��������Ҫ��ѯ�˵����᣺");
                    scanf("%d",&student.dormitory);
                    printf("\t\t\t��������Ҫ��ѯ�����ڵĴ��̣�");
                    scanf("%d",&student.bed);
                    printf("\t\t\t��������Ҫ��ѯ�����ڵ�ʡ�ݣ�");
                    scanf("%s",student.province);
                    printf("\t\t\t������������ѯ�����������壺");
                    scanf("%s",student.nation);
                    printf("\t\t\t������������ѯ�˵��ֻ��ţ�");
                    scanf("%lld",&student.phonenum);
                    int n;
                    memset(a,0,sizeof(a));
                    n = SearchComprehensive(stu1,student,studentnum);
                    if(n != -1)
                    {
                        printf("\t\t\t��Ҫ���ҵ��������ݿ��д���\n");
                        PrintInformation1(stu1, studentnum, a);
                    }
                    else
                    {
                        printf("\t\t\t�Բ����������˵���Ϣ�����ڡ�\n");
                    }
                    printf("\t\t\t�㻹�����ۺϲ�ѯ��Ϣ��(Y/N)?");
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
                    printf("\t\t\t�ף������������������\a");
                }
            }while(ch != 'A' && ch != 'B' && ch != 'C' && ch != 'D');
            if (ch == 'D')
                break;
            else if (ch == 'A')
            {
                printf("\t\t\t�������Ӷ����˵���Ϣ������������Ҫ���Ӷ����˵���Ϣ��");
                int n;
                scanf("%d",&n);
                example();
                printf("\t\t\t��������Ҫ�����˵���Ϣ\n");
                InputInformation1(stu1,studentnum,n);
                printf("\t\t\t�����Ƿ��������Ϣ������Ϣ�⣿(Y/N)");
                scanf(" %c",&ch1);
                if(ch1 == 'Y' || ch1 == 'y')
                {
                    number = 703 + n;
                    WritetoFile1(stu1,studentnum+n);
                    Sleep(1000);
                    printf("\t\t\t��ϲ�㣬����ɹ���\n");
                    system("pause");

                }
                studentnum+=n;
                break;
            }
            else if (ch == 'B')
            {
               do
                {
                    printf("\t\t\t��������Ҫɾ���˵����֣�");
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
                            printf("\t\t\t��ϲ�㣬�ɹ�������Ϊ��%s�����˳ɹ�ɾ��\n",choose);
                            printf("\t\t\t���Ƿ����ɾ�������Ϣ������Ϣ�⣿(Y/N)");
                            scanf(" %c",&ch1);
                            EstablishFile(ch1);
                        }
                        else
                        {
                            PrintInformation1(stu1, studentnum, a);
                            printf("\t\t\t����Ҫɾ���С�%s������һ����%d��\n",choose,samename);
                            printf("\t\t\tΪ�˸��Ӿ�ȷ��ɾ������ɾ�����ˣ���������Ҫɾ���˵�ѧ�ţ�");
                            scanf("%ld",&ID);
                            n = SearchStudentID(stu1,ID,studentnum);
                            DeleteStudentInformation(stu1, studentnum,n);
                            printf("\t\t\t��ϲ�㣬�ɹ�������Ϊ��%s����ѧ��Ϊ��%ld�����˳ɹ�ɾ��\n",choose,ID);
                            printf("\t\t\t���Ƿ����ɾ�������Ϣ������Ϣ�⣿(Y/N)");
                            scanf(" %c",&ch1);
                            EstablishFile(ch1);
                         }
                         studentnum--;
                         number--;
                      }
                     else
                     {
                         printf("\t\t\t�Բ�������������������ڡ�\n");
                     }
                     printf("\t\t\t�㻹��ɾ����Ϣ��(Y/N)?");
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
                        printf("\t\t\t�ף������������������\a");
                    }
                }while(ch2 != 'a' && ch2 != 'b' && ch2 != 'c' && ch2 != 'd' && ch2 != 'e' && ch2 != 'f' && ch2 != 'g' && ch2 != 'h' && ch2 != 'i');
                if (ch2 == 'a')
                {
                    do
                    {
                        AlterInputname();//�����޸�ʱ��������
                        scanf("%s",choose);
                        int n;
                        n = SearchStudentname(stu1,choose,studentnum);
                        if(n != -1)
                        {
                            if (samename == 1)
                            {
                                PrintInformation1(stu1,studentnum,a);
                                printf("\t\t\t��������Ҫ�ѡ�%s�����Ա��޸ĳ�ʲô��",choose);
                                scanf("%s",sex);
                                AlterSex(stu1, n, sex, studentnum);
                                printf("\t\t\t��ϲ�㣬�ɹ��޸����Ա�!\n");
                                AlterSave();
                            }
                            else
                            {
                                PrintInformation1(stu1, studentnum, a);
                                printf("\t\t\t����Ҫ�޸ĽС�%s������һ����%d������������Ҫ�޸ĵڼ���:",choose,samename);
                                int n;
                                scanf("%d",&n);
                                printf("\t\t\t��������Ҫ���޸ĵ��˵��Ա�ĳ�ʲô��");
                                scanf("%s",sex);
                                AlterSex(stu1,a[n-1],sex,studentnum);
                                printf("\t\t\t��ϲ�㣬�ɹ��޸����Ա�\n");
                                AlterSave();//�����ж��޸ĺ��Ƿ񴢴�
                            }
                        }
                        else
                        {
                            printf("\t\t\t�Բ�������������������ڡ�\n");
                        }
                        printf("\t\t\t�㻹���޸��˵��Ա���(Y/N)?");
                        scanf(" %c",&ch1);
                    }while (ch1 == 'Y' || ch1 == 'y');
                    break;
                }
                else if (ch2 == 'b')
                {
                    do
                    {
                        AlterInputname();//�����޸�ʱ��������
                        scanf("%s",choose);
                        int n;
                        n = SearchStudentname(stu1,choose,studentnum);
                        if(n != -1)
                        {
                            if (samename == 1)
                            {
                                PrintInformation1(stu1,studentnum,a);
                                printf("\t\t\t��������Ҫ�ѡ�%s����רҵ�Ͱ༶�ĳ�ʲô��",choose);
                                scanf("%s %s",major,classes);
                                AlerMajorAndClasses(stu1, n, classes, major, studentnum);//�����޸�רҵ�Ͱ༶
                                printf("\t\t\t��ϲ�㣬�ɹ��޸���רҵ�Ͱ༶!\n");
                                AlterSave();
                            }
                            else
                            {
                                PrintInformation1(stu1, studentnum, a);
                                printf("\t\t\t����Ҫ�޸ĽС�%s������һ����%d������������Ҫ�޸ĵڼ���",choose,samename);
                                int n;
                                scanf("%d",&n);
                                printf("\t\t\t��������Ҫ���޸ĵ��˵�רҵ�Ͱ༶�޸ĳ�ʲô��");
                                scanf("%s %s",major,classes);
                                AlerMajorAndClasses(stu1, a[n-1], classes, major, studentnum);
                                printf("\t\t\t��ϲ�㣬�ɹ��޸���רҵ�Ͱ༶��\n");
                                AlterSave();
                            }
                        }
                        else
                        {
                            printf("\t\t\t�Բ�������������������ڡ�\n");
                        }
                        printf("\t\t\t�㻹���޸��˵�רҵ�Ͱ༶��(Y/N)?");
                        scanf(" %c",&ch1);
                    }while (ch1 == 'Y' || ch1 == 'y');
                    break;
                }
                else if (ch2 == 'c')
                {
                    do
                    {
                        AlterInputname();//�����޸�ʱ��������
                        scanf("%s",choose);
                        int n;
                        n = SearchStudentname(stu1,choose,studentnum);
                        if(n != -1)
                        {
                            if (samename == 1)
                            {
                                PrintInformation1(stu1,studentnum,a);
                                printf("\t\t\t��������Ҫ�ѡ�%s����ѧ�Ÿĳ�ʲô��",choose);
                                scanf("%ld",&ID);
                                AlerStudentID(stu1, n, ID, studentnum);//���ڶ�ѧ�ŵ��޸�
                                printf("\t\t\t��ϲ�㣬�ɹ��޸���ѧ��!\n");
                                AlterSave();
                            }
                            else
                            {
                                PrintInformation1(stu1, studentnum, a);
                                printf("\t\t\t����Ҫ�޸ĽС�%s������һ����%d������������Ҫ�޸ĵڼ���",choose,samename);
                                int n;
                                scanf("%d",&n);
                                printf("\t\t\t��������Ҫ���޸ĵ��˵�ѧ���޸ĳ�ʲô��");
                                scanf("%ld",&ID);
                                AlerStudentID(stu1, a[n-1], ID, studentnum);//���ڶ�ѧ�ŵ��޸�
                                printf("\t\t\t��ϲ�㣬�ɹ��޸���ѧ�ţ�\n");
                                AlterSave();
                            }
                        }
                        else
                        {
                            printf("\t\t\t�Բ�������������������ڡ�\n");
                        }
                        printf("\t\t\t�㻹���޸��˵�ѧ����(Y/N)?");
                        scanf(" %c",&ch1);
                    }while (ch1 == 'Y' || ch1 == 'y');
                    break;
                }
                else if (ch2 == 'd')
                {
                    do
                    {
                        AlterInputname();//�����޸�ʱ��������
                        scanf("%s",choose);
                        int n;
                        n = SearchStudentname(stu1,choose,studentnum);
                        if(n != -1)
                        {
                            if (samename == 1)
                            {
                                PrintInformation1(stu1,studentnum,a);
                                printf("\t\t\t��������Ҫ�ѡ�%s����¥�Ÿĳ�ʲô��",choose);
                                scanf("%s",building);
                                AlterBuilding(stu1, n, building, studentnum);//���ڶ�¥�ŵ��޸�
                                printf("\t\t\t��ϲ�㣬�ɹ��޸���¥��!\n");
                                AlterSave();
                            }
                            else
                            {
                                PrintInformation1(stu1, studentnum, a);
                                printf("\t\t\t����Ҫ�޸ĽС�%s������һ����%d������������Ҫ�޸ĵڼ���:",choose,samename);
                                int n;
                                scanf("%d",&n);
                                printf("\t\t\t��������Ҫ���޸ĵ��˵�¥���޸ĳ�ʲô��");
                                scanf("%s",building);
                                AlterBuilding(stu1, a[n-1], building, studentnum);//���ڶ�¥�ŵ��޸�
                                printf("\t\t\t��ϲ�㣬�ɹ��޸���¥�ţ�\n");
                                AlterSave();
                            }
                        }
                        else
                        {
                            printf("\t\t\t�Բ�������������������ڡ�\n");
                        }
                        printf("\t\t\t�㻹���޸��˵�¥����(Y/N)?");
                        scanf(" %c",&ch1);
                    }while (ch1 == 'Y' || ch1 == 'y');
                    break;
                }
                else if (ch2 == 'e')
                {
                    do
                    {
                        AlterInputname();//�����޸�ʱ��������
                        scanf("%s",choose);
                        int n;
                        n = SearchStudentname(stu1,choose,studentnum);
                        if(n != -1)
                        {
                            if (samename == 1)
                            {
                                PrintInformation1(stu1,studentnum,a);
                                printf("\t\t\t��������Ҫ�ѡ�%s�������Ҹĳ�ʲô��",choose);
                                scanf("%d",&dormitory);
                                AlerDormitory(stu1, n, dormitory, studentnum);//���ڶ����ҵ��޸�
                                printf("\t\t\t��ϲ�㣬�ɹ��޸���������Ϣ!\n");
                                AlterSave();
                            }
                            else
                            {
                                PrintInformation1(stu1, studentnum, a);
                                printf("\t\t\t����Ҫ�޸ĽС�%s������һ����%d������������Ҫ�޸ĵڼ���",choose,samename);
                                int n;
                                scanf("%d",&n);
                                printf("\t\t\t��������Ҫ���޸ĵ��˵������޸ĳ�ʲô��");
                                scanf("%d",&dormitory);
                                AlerDormitory(stu1, a[n-1], dormitory, studentnum);//���ڶ����ҵ��޸�
                                printf("\t\t\t��ϲ�㣬�ɹ��޸���������Ϣ��\n");
                                AlterSave();
                            }
                        }
                        else
                        {
                            printf("\t\t\t�Բ�������������������ڡ�\n");
                        }
                        printf("\t\t\t�㻹���޸��˵�������(Y/N)?");
                        scanf(" %c",&ch1);
                    }while (ch1 == 'Y' || ch1 == 'y');
                    break;
                }
                else if (ch2 == 'f')
                {
                    do
                    {
                        AlterInputname();//�����޸�ʱ��������
                        scanf("%s",choose);
                        int n;
                        n = SearchStudentname(stu1,choose,studentnum);
                        if(n != -1)
                        {
                            if (samename == 1)
                            {
                                PrintInformation1(stu1,studentnum,a);
                                printf("\t\t\t��������Ҫ�ѡ�%s���Ĵ�λ�ĳ�ʲô��",choose);
                                scanf("%d",&bed);
                                AlerBed(stu1, n, bed, studentnum);//���ڴ�λ���޸�
                                printf("\t\t\t��ϲ�㣬�ɹ��޸��˴�λ��Ϣ!\n");
                                AlterSave();
                            }
                            else
                            {
                                PrintInformation1(stu1, studentnum, a);
                                printf("\t\t\t����Ҫ�޸ĽС�%s������һ����%d������������Ҫ�޸ĵڼ���:",choose,samename);
                                int n;
                                scanf("%d",&n);
                                printf("\t\t\t��������Ҫ���޸ĵ��˵Ĵ�λ�޸ĳ�ʲô��");
                                scanf("%d",&bed);
                                AlerBed(stu1, a[n-1], bed, studentnum);//���ڴ�λ���޸�
                                printf("\t\t\t��ϲ�㣬�ɹ��޸��˴�λ��Ϣ��\n");
                                AlterSave();
                            }
                        }
                        else
                        {
                            printf("\t\t\t�Բ�������������������ڡ�\n");
                        }
                        printf("\t\t\t�㻹���޸��˵Ĵ�λ��(Y/N)?");
                        scanf(" %c",&ch1);
                    }while (ch1 == 'Y' || ch1 == 'y');
                    break;
                }
                else if (ch2 == 'g')
                {
                    do
                    {
                        AlterInputname();//�����޸�ʱ��������
                        scanf("%s",choose);
                        int n;
                        n = SearchStudentname(stu1,choose,studentnum);
                        if(n != -1)
                        {
                            if (samename == 1)
                            {
                                PrintInformation1(stu1,studentnum,a);
                                printf("\t\t\t��������Ҫ�ѡ�%s���������Ե�ʡ�ݸĳ�ʲô��",choose);
                                scanf("%s",province);
                                AlerProvince(stu1, n, province, studentnum);//���ڶ�����ʡ�ݵ��޸�
                                printf("\t\t\t��ϲ�㣬�ɹ��޸���ʡ����Ϣ!\n");
                                AlterSave();
                            }
                            else
                            {
                                PrintInformation1(stu1, studentnum, a);
                                printf("\t\t\t����Ҫ�޸ĽС�%s������һ����%d������������Ҫ�޸ĵڼ���:",choose,samename);
                                int n;
                                scanf("%d",&n);
                                printf("\t\t\t��������Ҫ���޸ĵ��˵������Ե�ʡ���޸ĳ�ʲô��");
                                scanf("%s",province);
                                AlerProvince(stu1, a[n-1], province, studentnum);//���ڶ�����ʡ�ݵ��޸�
                                printf("\t\t\t��ϲ�㣬�ɹ��޸���ʡ�ݣ�\n");
                                AlterSave();
                            }
                        }
                        else
                        {
                            printf("\t\t\t�Բ�������������������ڡ�\n");
                        }
                        printf("\t\t\t�㻹���޸��������Ե�ʡ����(Y/N)?");
                        scanf(" %c",&ch1);
                    }while (ch1 == 'Y' || ch1 == 'y');
                    break;
                }
                else if (ch2 == 'h')
                {
                    do
                    {
                        AlterInputname();//�����޸�ʱ��������
                        scanf("%s",choose);
                        int n;
                        n = SearchStudentname(stu1,choose,studentnum);
                        if(n != -1)
                        {
                            if (samename == 1)
                            {
                                PrintInformation1(stu1,studentnum,a);
                                printf("\t\t\t��������Ҫ�ѡ�%s��������ĳ�ʲô��",choose);
                                scanf("%s",nation);
                                AlterNation(stu1, n, nation, studentnum);//�����޸�������Ϣ
                                printf("\t\t\t��ϲ�㣬�ɹ��޸���������Ϣ!\n");
                                AlterSave();
                            }
                            else
                            {
                                PrintInformation1(stu1, studentnum, a);
                                printf("\t\t\t����Ҫ�޸ĽС�%s������һ����%d������������Ҫ�޸ĵڼ���:",choose,samename);
                                int n;
                                scanf("%d",&n);
                                printf("\t\t\t��������Ҫ���޸ĵ��˵������޸ĳ�ʲô��");
                                scanf("%s",nation);
                                AlterNation(stu1, a[n-1], nation, studentnum);//�����޸�������Ϣ
                                printf("\t\t\t��ϲ�㣬�ɹ��޸���������Ϣ��\n");
                                AlterSave();
                            }
                        }
                        else
                        {
                            printf("\t\t\t�Բ�������������������ڡ�\n");
                        }
                        printf("\t\t\t�㻹���޸���������(Y/N)?");
                        scanf(" %c",&ch1);
                    }while (ch1 == 'Y' || ch1 == 'y');
                    break;
                }
                else if (ch2 == 'i')
                {
                    do
                    {
                        AlterInputname();//�����޸�ʱ��������
                        scanf("%s",choose);
                        int n;
                        n = SearchStudentname(stu1,choose,studentnum);
                        if(n != -1)
                        {
                            if (samename == 1)
                            {
                                PrintInformation1(stu1,studentnum,a);
                                printf("\t\t\t��������Ҫ�ѡ�%s�����ֻ��Ÿĳ�ʲô��",choose);
                                scanf("%lld",&phone);
                                AlterPhone(stu1, n, phone, studentnum);//���ֻ��ŵ��޸�
                                printf("\t\t\t��ϲ�㣬�ɹ��޸����ֻ���!\n");
                                AlterSave();
                            }
                            else
                            {
                                PrintInformation1(stu1, studentnum, a);
                                printf("\t\t\t����Ҫ�޸ĽС�%s������һ����%d������������Ҫ�޸ĵڼ���",choose,samename);
                                int n;
                                scanf("%d",&n);
                                printf("\t\t\t��������Ҫ���޸ĵ��˵��ֻ����޸ĳ�ʲô��");
                                scanf("%lld",&phone);
                                AlterPhone(stu1, a[n-1], phone, studentnum);//���ֻ��ŵ��޸�
                                printf("\t\t\t��ϲ�㣬�ɹ��޸����ֻ��ţ�\n");
                                AlterSave();
                            }
                        }
                        else
                        {
                            printf("\t\t\t�Բ�������������������ڡ�\n");
                        }
                        printf("\t\t\t�㻹���޸��˵��ֻ�����(Y/N)?");
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
                    printf("\t\t\t�ף������������������\a");
                }
            }while(ch != 'A' && ch != 'B' && ch != 'C' && ch != 'D' && ch != 'E' && ch != 'F');
            if (ch == 'F')
                break;
            else if (ch == 'A')
            {
                printf("\t\t\t���������������������뽵������Y/N��(Y��ʾ����)");
                scanf(" %c",&ch1);
                if (ch1 == 'Y' || ch1 =='y')
                {
                    AscendingBubblingSort(stu1, studentnum);//ѡѡ��ķ�������������
                    printf("\t\t\t��ϲ���������\n");
                    AlterSave();//�����ж��޸ĺ��Ƿ񴢴�
                }
                else
                {
                    DescendingBubblingSort(stu1, studentnum);//ѡѡ��ķ����ڽ�������
                    printf("\t\t\t��ϲ���������\n");
                    AlterSave();//�����ж��޸ĺ��Ƿ񴢴�
                    system("pause");
                }
                break;
            }
            else if (ch == 'B')
            {
                printf("\t\t\t�Ե�һ���ӣ�����ͳ������.....\n");
                Sleep(1000);
                int boy,girl;
                boy = BoyNumber(stu1, studentnum);
                girl = GirlNumber(stu1, studentnum);
                printf("\t\t\t         ����       �ٷֱ�\n");
                printf("\t\t\t �� ��      %d        %.2lf%%\n", boy , boy*100.0/studentnum);
                printf("\t\t\t Ů ��      %d        %.2lf%%\n", girl, girl*100.0/studentnum);
                system("pause");
                break;
            }
            else if (ch == 'C')
            {
                do
                {
                    printf("\t\t\t����������ͳ���Ǹ�ʡ��������(���磺ɽ��ʡ):");
                    scanf("%s",province);
                    int n = ProvinceNumber(stu1, studentnum, province);//ͳ��ĳʡ������
                    printf("\t\t\tʡ��        ����      �ٷֱ�\n");
                    printf("\t\t\t%s          %d       %.2lf%%\n", province, n, n*100.0/studentnum);
                    printf("\t\t\t�㻹��ͳ���Ǹ�ʡ������(Y/N)");
                    scanf(" %c",&ch1);
                }while (ch1 == 'Y' || ch1 == 'y');
                break;
            }
            else if (ch == 'D')
            {
                do
                {
                    printf("\t\t\t����������ͳ���Ǹ�רҵ��������(���磺�������)");
                    scanf("%s",major);
                    int n = MajorNumber(stu1, studentnum, major);//ͳ��ĳרҵ������
                    printf("\t\t\tרҵ                ����      �ٷֱ�\n");
                    printf("\t\t\t%s                   %d       %.2lf%%\n", major, n, n*100.0/studentnum);
                    printf("\t\t\t�㻹��ͳ���Ǹ�רҵ������(Y/N)");
                    scanf(" %c",&ch1);
                }while (ch1 == 'Y' || ch1 == 'y');
                break;
            }
            else if (ch == 'E')
            {
                do
                {
                    printf("\t\t\t����������ͳ���Ǹ����ҵ�������(���磺926)");
                    scanf("%d",&dormitory);
                    int n = DormitoryNumber(stu1, studentnum, dormitory);//ͳ��ĳ�����ҵ�����
                    printf("\t\t\t����                ����\n");
                    printf("\t\t\t%d                   %d \n", dormitory, n);
                    printf("\t\t\t�㻹��ͳ���Ǹ����ҵ�����(Y/N)");
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
                    printf("\t\t\t�����������������\a");
                }
            }while(ch != 'A' && ch != 'B' && ch != 'C' && ch != 'D' && ch != 'E' && ch != 'F' && ch != 'G');
            if (ch == 'G')
                break;
            else if (ch == 'A')
            {
                AlterSave();//�����ж��޸ĺ��Ƿ񴢴�
                break;
            }
            else if (ch == 'B')
            {
                memset(stu2,0,sizeof(STU));
                printf("\t\t\t���������뱣���Ǹ�רҵ����Ϣ��(���磺�������)");
                scanf("%s",major);
                int  n = Majorstu1tostu2(stu1, stu2, studentnum, major);//ʹ�ṹ��stu1�е���ͬרҵ����Ϣ��ֵ��stu2
                PrintInformation(stu2,n);
                printf("\t\t\t���רҵ����%d�ˣ���ȷ����Ҫ�������רҵ��Ϣ���ļ��У�(Y/N)");
                scanf(" %c",&ch1);
                if (ch1 == 'Y' || ch1 =='y')
                {
                    MajortoFile(stu2,n);//�����½�һ���ļ�������ͬרҵ����
                    printf("\t\t\t��ϲ�㣬�ɹ����浽�ļ��У����ڵ�ǰ�ļ�����The same major�в鿴\n");
                    system("pause");
                }
                break;
            }
            else if (ch == 'C')
            {
                 memset(stu2,0,sizeof(STU));
                 printf("\t\t\t���������뱣���Ǹ��༶����Ϣ��(���磺���2017-1)");
                 scanf("%s",classes);
                 int n = Classstu1tostu2(stu1, stu2, studentnum, classes);//ʹ�ṹ��stu1�е���ͬ�༶����Ϣ��ֵ��stu2
                 PrintInformation(stu2,n);
                 printf("\t\t\t����༶����%d�ˣ���ȷ����Ҫ��������༶����Ϣ���ļ��У�(Y/N)");
                 scanf(" %c",&ch1);
                 if (ch1 == 'Y' || ch1 =='y')
                 {
                     ClasstoFile(stu2,n);//�����½�һ���ļ�������ͬ�༶����
                     printf("\t\t\t��ϲ�㣬�ɹ����浽�ļ��У����ڵ�ǰ�ļ�����The same class�в鿴\n");
                     system("pause");
                 }
                 break;
            }
            else if (ch == 'D')
            {
                 memset(stu2,0,sizeof(STU));
                 printf("\t\t\t���������뱣���Ǹ����ҵ���Ϣ��(���磺926):");
                 scanf("%d",&dormitory);
                 int n = Dormitorystu1tostu2(stu1, stu2, studentnum, dormitory);//ʹ�ṹ��stu1�е���ͬ���ҵ���Ϣ��ֵ��stu2
                 PrintInformation(stu2,n);
                 printf("\t\t\t������ҹ���%d�ˣ���ȷ����Ҫ�������������Ϣ���ļ��У�(Y/N)");
                 scanf(" %c",&ch1);
                 if (ch1 == 'Y' || ch1 =='y')
                 {
                     DormitorytoFile(stu2,n);//�����½�һ���ļ�������ͬ���ҵ���
                     printf("\t\t\t��ϲ�㣬�ɹ����浽�ļ��У����ڵ�ǰ�ļ�����The same dormitory�в鿴\n");
                     system("pause");
                 }
                 break;
            }
            else if (ch == 'E')
            {
                 memset(stu2,0,sizeof(STU));
                 printf("\t\t\t���������뱣���Ǹ�ʡ������Ϣ��(���磺ɽ��ʡ)");
                 scanf("%s",province);
                 int n = Provincestu1tostu2(stu1, stu2, studentnum, province);//ʹ�ṹ��stu1�е���ͬʡ�ݵ���Ϣ��ֵ��stu2
                 PrintInformation(stu2,n);
                 printf("\t\t\t���ʡ�ݹ���%d�ˣ���ȷ����Ҫ�������ʡ����Ϣ���ļ��У�(Y/N)");
                 scanf(" %c",&ch1);
                 if (ch1 == 'Y' || ch1 =='y')
                 {
                     ProvincetoFile(stu2,n);//�����½�һ���ļ�������ͬʡ�ݵ���
                     printf("\t\t\t��ϲ�㣬�ɹ����浽�ļ��У����ڵ�ǰ�ļ�����The same province�в鿴\n");
                     system("pause");
                 }
                 break;
            }
            else if (ch == 'F')
            {
                 memset(stu2,0,sizeof(STU));
                 printf("\t\t\t���������뱣���Ǹ����������Ϣ��(���磺����)");
                 scanf("%s",nation);
                 int n = Nationstu1tostu2(stu1, stu2, studentnum, nation);//ʹ�ṹ��stu1�е���ͬ�������Ϣ��ֵ��stu2
                 PrintInformation(stu2,n);
                 printf("\t\t\t������干��%d�ˣ���ȷ����Ҫ�������������Ϣ���ļ��У�(Y/N)");
                 scanf(" %c",&ch1);
                 if (ch1 == 'Y' || ch1 =='y')
                 {
                     NationtoFile(stu2,n);//�����½�һ���ļ�������ͬʡ�ݵ���
                     printf("\t\t\t��ϲ�㣬�ɹ����浽�ļ��У����ڵ�ǰ�ļ�����The same nation�в鿴\n");
                     system("pause");
                 }
                 break;
            }
         case 6:
            SystemSetting(1);//ϵͳ����
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
            printf("�ף������������������\a\n");
        }
    }while(ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '5' && ch != '6');
    system("cls");
    if (ch == '6')
        quit();
    else if (ch == '1')
    {
        printf("\t\t\t\t������һ��ͨ������Ǯ��");
        int money,n;
        scanf("%d",&money);
        n = SearchStudentID2(pupil, stuID, number);
        AlterOnecard(pupil,number, n, money);//������һ��ͨ���Ǯ
        WritetoFile5(pupil, number);
        printf("\t\t\t\t��ֵ�ɹ���\n \t\t\t\t���ڷ������Ե�........");
        Sleep(1000);

    }
    else if (ch == '2')
    {
        printf("\t\t\t\t�����ֵ�������ѣ�");
        int money,n;
        scanf("%d",&money);
        n = SearchStudentID2(pupil, stuID, number);
        AlterInterFee(pupil, number, n, money);//���ڳ�ֵ����
        WritetoFile5(pupil, number);
        Sleep(1000);
    }
    else if (ch == '3')
    {
        printf("\t\t\t\t�����ֵ����ˮ��ѣ�");
        int money,n;
        scanf("%d",&money);
        n = SearchStudentID2(pupil, stuID, number);
        AlterUtiltybill(pupil, number, n, money);//���ڳ�ֵˮ���
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

void SystemSetting(int xuanzhe)//ϵͳ����
{
    char ch;
    system("CLS");
    Menu6();
    do
    {
        scanf(" %c",&ch);
        if(ch != 'A' && ch != 'B' && ch != 'C' && ch != 'D')
        {
            printf("\t\t\t�ף�������������������\a");
        }
    }while(ch != 'A' && ch != 'B' && ch != 'C' && ch != 'D');
    if(ch == 'D')
        return;
    else if (ch == 'A')
    {
        system("CLS");
        print();
        printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t~~~~~~~������ɫ�б�~~~~~~~~\n");
        printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t# 0=��ɫ      8=��ɫ      #\n");
        printf("\t\t\t\t\t# 1=��ɫ      9=����ɫ    #\n");
        printf("\t\t\t\t\t# 2=��ɫ      10=����ɫ   #\n");
        printf("\t\t\t\t\t# 3=����ɫ    11=��ǳ��ɫ #\n");
        printf("\t\t\t\t\t# 4=��ɫ      12=����ɫ   #\n");
        printf("\t\t\t\t\t# 5=��ɫ      13=����ɫ   #\n");
        printf("\t\t\t\t\t# 6=��ɫ      14=����ɫ   #\n");
        printf("\t\t\t\t\t# 7=��ɫ      15=����ɫ   #\n");
        printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t��ѡ����Ҫ���õ�������ɫ��");
        scanf("%d",&ziti);
        SelectFontColor(ziti);//ѡ��������ɫ
        system("pause");
        return;
    }
    else if(ch == 'B')
    {
        system("CLS");
        print();
        printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t~~~~~~~������ɫ�б�~~~~~~~~\n");
        printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t# 0=��ɫ      8=��ɫ      #\n");
        printf("\t\t\t\t\t# 1=��ɫ      9=����ɫ    #\n");
        printf("\t\t\t\t\t# 2=��ɫ      10=����ɫ   #\n");
        printf("\t\t\t\t\t# 3=����ɫ    11=��ǳ��ɫ #\n");
        printf("\t\t\t\t\t# 4=��ɫ      12=����ɫ   #\n");
        printf("\t\t\t\t\t# 5=��ɫ      13=����ɫ   #\n");
        printf("\t\t\t\t\t# 6=��ɫ      14=����ɫ   #\n");
        printf("\t\t\t\t\t# 7=��ɫ      15=����ɫ   #\n");
        printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t��ѡ����Ҫ���õı�����ɫ��");
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
            printf("\t\t\t���������ԭ���룺");
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
                printf("\n\t\t\t�������\n");
                printf("\n\t\t\t���������룡\n");
                Sleep(1000);
            }
        }while (n == 0);
        do
        {
            printf("\n\t\t\t��������ĵ������룺");
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
            printf("\n\t\t\t���ٴ�ȷ������������룺");
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
                printf("\n\t\t\t�ף��������벻һ�������ٴ����롣");
            }
        }while(n == 0);
        AlterPassword(enter, stuID, password2, number);//���ڶ�������޸�
        if(xuanzhe == 1)
            WritetoFile6(enter, number);
        else
            WritetoFile4(enter, number);
        printf("\n\t\t\t�����޸ĳɹ���\n");
        system("pause");
    }
}

void Menu() //�������˵�
{
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t�� ****�ﻶӭʹ��ѧ��������Ϣ����ϵͳ��****��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��               �����˵���                ��\n");
    printf("\t\t\t\t *******************************************\n");
    printf("\t\t\t\t *\t����������  ��������������������������               *\n");
    printf("\t\t\t\t *\t�� 1.��  �� ����Ϣ���멧               *\n");
    printf("\t\t\t\t *\t����������  ��������������������������               *\n");
    printf("\t\t\t\t *\t����������  ��������������������������               *\n");
    printf("\t\t\t\t *\t�� 2.��  �� ����Ϣ��ѯ��               *\n");
    printf("\t\t\t\t *\t����������  ��������������������������               *\n");
    printf("\t\t\t\t *\t����������  ��������������������������               *\n");
    printf("\t\t\t\t *\t�� 3.��  �� ����Ϣ�޸ĩ�               *\n");
    printf("\t\t\t\t *\t����������  ��������������������������               *\n");
    printf("\t\t\t\t *\t����������  ��������������������������               *\n");
    printf("\t\t\t\t *\t�� 4.��  �� ����Ϣͳ�Ʃ�               *\n");
    printf("\t\t\t\t *\t����������  ��������������������������               *\n");
    printf("\t\t\t\t *\t����������  ��������������������������               *\n");
    printf("\t\t\t\t *\t�� 5.��  �� ����Ϣ���橧               *\n");
    printf("\t\t\t\t *\t����������  ��������������������������               *\n");
    printf("\t\t\t\t *\t����������  ��������������������������               *\n");
    printf("\t\t\t\t *\t�� 6.��  �� ��ϵͳ���é�               *\n");
    printf("\t\t\t\t *\t����������  ��������������������������               *\n");
    printf("\t\t\t\t *\t����������  ��������������������������               *\n");
    printf("\t\t\t\t *\t�� 7.��  �� ���˳�ϵͳ��               *\n");
    printf("\t\t\t\t *\t����������  ��������������������������               *\n");
    printf("\t\t\t\t *******************************************\n");
    printf("\n");
    printf("\t\t\t\t����������Ĳ�����");
}

void Menu1()//�����Ӳ˵� �����ļ��˵� �д��ļ������ʹӼ�������
{
    print();
    printf("\t\t\t��                           ��������Ϣ��                            ��\n");
    printf("\t\t\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t\t\t��         ��A-----------------�Ӽ�������-----------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��B-----------------���ļ�����-----------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��C-----------------�������˵�-----------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\n");
    printf("\t\t\t����������Ĳ�����");
}

void Menu2()//�����Ӳ˵� ��ѯ��Ϣ�˵� ������������ѯ ��ѧ�Ų�ѯ ���绰��ѯ �ۺϲ�ѯ
{
     print();
    printf("\t\t\t��                           ����Ϣ��ѯ��                            ��\n");
    printf("\t\t\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t\t\t��         ��A-----------------��ѧ�Ų�ѯ-----------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��B-----------------��������ѯ-----------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��C-----------------���ֻ��Ų�ѯ---------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��D-----------------�ۺϲ�ѯ-------------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��E-----------------�������˵�-----------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\n");
    printf("\t\t\t����������Ĳ�����");
}

void Menu3()//�����Ӳ˵� ������Ϣ
{
     print();
    printf("\t\t\t��                           ����Ϣ�޸ġ�                            ��\n");
    printf("\t\t\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t\t\t��         ��A-----------------������Ϣ-------------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��B-----------------ɾ����Ϣ-------------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��C-----------------�޸ĸ�����Ϣ---------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��D-----------------�������˵�-----------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\n");
    printf("\t\t\t����������Ĳ�����");
}

void Menu4() //�����Ӳ˵� ͳ�� ������ѧ������ͳ��������Ů����������ͳ��ʡ�ݵ������Ͱٷֱȣ�ͳ�Ƹ�רҵ��������ͳ��
{
    print();
    printf("\t\t\t��                           ����Ϣͳ�ơ�                            ��\n");
    printf("\t\t\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t\t\t��         ��A-----------------��ѧ������-----------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��B-----------------ͳ����Ů�������ٷֱ�-------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��C-----------------ͳ��ʡ���������ٷֱ�-------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��D-----------------ͳ��רҵ�������ٷֱ�-------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��E-----------------ͳ����������---------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��F-----------------�������˵�-----------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\n");
    printf("\t\t\t����������Ĳ�����");
}

void Menu5()//�����Ӳ˵� ������Ϣ ���ڱ���ͬʡ�� ͬ�༶ ͬרҵ ͬ�༶ ͬ���ң�ͬ¥�ŵ�ѧ����Ϣ
{
    print();
    printf("\t\t\t��                           ����Ϣ�����                            ��\n");
    printf("\t\t\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t\t\t��         ��A-----------------����ȫ����Ϣ---------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��B-----------------����ͬרҵ����Ϣ-----------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��C-----------------����ͬ�༶����Ϣ-----------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��D-----------------����ͬ���ҵ���Ϣ-----------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��E-----------------����ͬʡ�ݵ���Ϣ-----------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��F-----------------����ͬ�������Ϣ-----------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��G-----------------�������˵�-----------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\n");
    printf("\t\t\t����������Ĳ�����");
}

void Menu6()//�����Ӳ˵� ���� �������ñ�����ɫ��������ɫ
{
    print();
    printf("\t\t\t��                           ��ϵͳ���á�                            ��\n");
    printf("\t\t\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t\t\t��         ��A-----------------����������ɫ---------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��B-----------------����������ɫ---------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��C-----------------�޸�����-------------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��D-----------------�������˵�-----------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\n");
    printf("\t\t\t����������Ĳ�����");
}

void Menu7() //�����޸�ѧ��������Ϣ�Ĳ˵�
{
   print();
    printf("\t\t\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t\t\t��                           ����Ϣͳ�ơ�                            ��\n");
    printf("\t\t\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t\t\t��                           ���޸ĸ�����Ϣ                          ��\n");
    printf("\t\t\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t\t\t��         ��a-----------------�޸��Ա�-------------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��b-----------------�޸�רҵ�Ͱ༶-------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��c-----------------�޸�ѧ��-------------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��d-----------------�޸�¥��-------------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��e-----------------�޸�����-------------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��f-----------------�޸Ĵ�λ-------------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��g-----------------�޸�ʡ��-------------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��h-----------------�޸�����-------------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t��         ��i-----------------�޸ĵ绰-------------------           ��\n");
    printf("\t\t\t��                                                                   ��\n");
    printf("\t\t\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\n");
    printf("\t\t\t����������Ĳ�����");
}

void Menu8()//һ��ʼ�Ľ���
{
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t�� ****�ﻶӭʹ��ѧ��������Ϣ����ϵͳ��****��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t********************************************\n");
    printf("\t\t\t\t*\t��������  ����������������������������               *\n");
    printf("\t\t\t\t*\t�� A��  �������Ա��ک�               *\n");
    printf("\t\t\t\t*\t��������  ����������������������������               *\n");
    printf("\t\t\t\t*\t��������  ������������������������                 *\n");
    printf("\t\t\t\t*\t�� B��  ����ѧ����ک�                 *\n");
    printf("\t\t\t\t*\t��������  ������������������������                 *\n");
    printf("\t\t\t\t*\t��������  ������������������������                 *\n");
    printf("\t\t\t\t*\t�� C��  �����˳�ϵͳ��                 *\n");
    printf("\t\t\t\t*\t��������  ������������������������                 *\n");
    printf("\t\t\t\t********************************************\n");
    printf("\n");
    printf("\t\t\t\t����������Ĳ�����");
}

void Menu9()//һ��ʼ����
{
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t�� ****�ﻶӭʹ��ѧ��������Ϣ����ϵͳ��****��\n");
    printf("\t\t\t\t��������������������������������������������������������������������������������������\n");
    printf("\t\t\t\t��                �����˵���               ��\n");
    printf("\t\t\t\t ******************************************\n");
    printf("\t\t\t\t *\t����������  ������������������������������            *\n");
    printf("\t\t\t\t *\t�� 1.��  �� ��һ��ͨ��ֵ��            *\n");
    printf("\t\t\t\t *\t����������  ������������������������������            *\n");
    printf("\t\t\t\t *\t����������  ��������������������������              *\n");
    printf("\t\t\t\t *\t�� 2.��  �� �����ѳ�ֵ��              *\n");
    printf("\t\t\t\t *\t����������  ��������������������������              *\n");
    printf("\t\t\t\t *\t����������  ������������������������������            *\n");
    printf("\t\t\t\t *\t�� 3.��  �� ��ˮ��ѳ�ֵ��            *\n");
    printf("\t\t\t\t *\t����������  ������������������������������            *\n");
    printf("\t\t\t\t *\t����������  ��������������������������              *\n");
    printf("\t\t\t\t *\t�� 4.��  �� ������ѯ��              *\n");
    printf("\t\t\t\t *\t����������  ��������������������������              *\n");
    printf("\t\t\t\t *\t����������  ��������������������������              *\n");
    printf("\t\t\t\t *\t�� 5.��  �� ��ϵͳ���é�              *\n");
    printf("\t\t\t\t *\t����������  ��������������������������              *\n");
    printf("\t\t\t\t *\t����������  ��������������������������              *\n");
    printf("\t\t\t\t *\t�� 6.��  �� ���˳�ϵͳ��              *\n");
    printf("\t\t\t\t *\t����������  ��������������������������              *\n");
    printf("\t\t\t\t ******************************************\n");
    printf("\n");
    printf("\t\t\t\t����������Ĳ�����");
}

void InputInformation(STU stu[], int studentnum)//�������뺯�������û����������
{
    int i;
    for(i = 0; i < studentnum; i++)
    {
        printf("\t\t\t�������%d���˵���Ϣ\n",i+1);
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

void example()//�����û������������ĺ�����
{
    printf("\t\t\t�����Ҫ����������,����\n");
    printf("\t\t\t���� �Ա� רҵ      �༶        ѧ��        ¥��      ����  ����  ʡ��    ����  �ֻ���\n");
    printf("\t\t\t��� ��   �������  ���2017-2  1767159234  23��¥    926   6     ɽ��ʡ  ����  15847249689\n");
}

void print()
{
   printf("\t\t\t������������������������������������������������������������������������������������������������������������������������������������������\n");
   printf("\t\t\t�� ****************�ﻶӭʹ��ѧ��������Ϣ����ϵͳ��******************��\n");
   printf("\t\t\t������������������������������������������������������������������������������������������������������������������������������������������\n");
}

void EstablishFile(char ch1)//�����ж��û��Ƿ����ݵ����ļ�
{
    if(ch1 == 'Y' || ch1 == 'y')
    {
        printf("\t\t\t���������ԭ�ȵ��ļ��л������½�һ���ļ��洢��(Y/N)��Y��ʾ�����½�һ���ļ����棩");
        scanf(" %c",&ch1);
        if(ch1 == 'Y' || ch1 == 'y')
        {
            WritetoFile2(stu1,studentnum);
            printf("\t\t\t��ϲ�㣬�ɹ�����һ����StudentInformation1���ļ������ڵ�ǰ�ļ����²鿴��\n");
        }
        else
        {
            WritetoFile3(stu1,studentnum);
            printf("\t\t\t��ϲ�㣬�ɹ���ԭ�ļ������ݸı䡣\n");
        }
    }
}

void AlterInputname()//�����޸�ʱ��������
{
     printf("\t\t\t����������Ҫ�޸��˵�������(���磺���)");
     samename = 0;
     memset(a,0,sizeof(a));
}

void AlterSave()//�����ж��޸ĺ��Ƿ񴢴�
{
    int ch1;
    printf("\t\t\t���Ƿ�����޸ú����Ϣ������Ϣ�⣿(Y/N):");
    scanf(" %c",&ch1);
    EstablishFile(ch1);
}
void ReadfromFile(STU stu[],int *studentnum)//��ԭ�ļ��ж�ȡ����
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

void PrintInformation(STU stu[],int studentnum)//���ڴ�ӡ�ṹ���е���Ϣ
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

int SearchStudentID(STU stu[], long int ID,int studentnum)//���ڶ�ѧ�ŵĲ���
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

int SearchStudentname(STU stu[], char str[], int studentnum)//���ڶ������Ĳ���
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

void PrintInformation1(STU stu[],int studentnum,int a[])//���ڴ�ӡ�ṹ��������(��������)����Ϣ
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

int SearchPhonenum(STU stu[], long long int phone, int studentnum)//���ڶԽṹ�����ֻ��ŵĲ�ѯ
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

int SearchComprehensive(STU stu[], STU student, int studentnum)//�����ۺϲ�ѯ
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

void InputInformation1(STU stu[], int studentnum, int n)//������Ϣ�޸�ʱ��������
{
    int i;
    for(i = studentnum; i < studentnum+n; i++)
    {
        printf("\t\t\t���������ӵĵ�%d���˵���Ϣ\n",i+1-studentnum);
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

void WritetoFile1(STU stu[],int n)//������Դ�ļ��ļ���д�����ӵ�����
{
    FILE *fp;
    int i;
    if((fp = fopen("StudentInformation.txt","a")) == NULL)//��a��,ʹָ���ƶ����ļ���ĩβ�����ļ�ĩβ������ݡ�
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

void DeleteStudentInformation(STU stu[], int studentnum, int n)//����ɾ���ļ�ָ������Ϣ
{
    int i,j;
    for(i = 0; i < studentnum; i++)
    {
        if(i == n)//�����ҵ�Ҫɾ�����±�ʱ
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

void WritetoFile2(STU stu[],int n)//�����޸ĺ�ɾ����������½�һ���ļ���������
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

void WritetoFile3(STU stu[],int n)//���ڸı����Ϣ���µ���ԭ�ļ�
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

void AlterSex(STU stu[], int n, char sex[],int studentnum)//�����޸��Ա�
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

void AlerMajorAndClasses(STU stu[], int n, char classes[], char major[], int studentnum)//�����޸�רҵ�Ͱ༶
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

void AlerStudentID(STU stu[], int n, long int ID, int studentnum)//���ڶ�ѧ�ŵ��޸�
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

void AlterBuilding(STU stu[], int n, char building[],int studentnum)//���ڶ�¥�ŵ��޸�
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

void AlerDormitory(STU stu[], int n, int dormitory, int studentnum)//���ڶ����ҵ��޸�
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

void AlerBed(STU stu[], int n, int bed, int studentnum)//���ڴ�λ���޸�
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

void AlerProvince(STU stu[], int n, char province[], int studentnum)//���ڶ�����ʡ�ݵ��޸�
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

void AlterNation(STU stu[], int n, char nation[], int studentnum)//�����޸�������Ϣ
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

void AlterPhone(STU stu[], int n, long long int phone, int studentnum)//���ֻ��ŵ��޸�
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

void AscendingBubblingSort(STU stu[], int studentnum)//ð�ݷ���������
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

void DescendingBubblingSort(STU stu[], int studentnum)//ð�ݷ���������
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

int BoyNumber(STU stu[], int studentnum)//ͳ������������
{
    int i,j=0;
    char boy[M] = "��";
    for (i = 0; i < studentnum; i++)
    {
        if (strcmp(stu[i].studentsex ,boy) == 0)
            j++;
    }
    return j;
}

int GirlNumber(STU stu[], int studentnum)//ͳ��Ů��������
{
    int i,j=0;
    char girl[M] = "Ů";
    for (i = 0; i < studentnum; i++)
    {
        if (strcmp(stu[i].studentsex , girl) == 0)
            j++;
    }
    return j;
}

int ProvinceNumber(STU stu[], int studentnum, char province[])//ͳ��ĳʡ������
{
    int i,j=0;
    for (i = 0; i < studentnum; i++)
    {
        if (strcmp(stu[i].province, province) == 0)
            j++;
    }
    return j;
}

int MajorNumber(STU stu[], int studentnum, char major[])//ͳ��ĳרҵ������
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

int DormitoryNumber(STU stu[], int studentnum, int dormitory)//ͳ��ĳ�����ҵ�����
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

int  Majorstu1tostu2(STU stu1[], STU stu2[], int studentnum, char major[])//ʹ�ṹ��stu1�е���ͬרҵ����Ϣ��ֵ��stu2
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

void MajortoFile(STU stu[],int n)//�����½�һ���ļ�������ͬרҵ����
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

int Classstu1tostu2(STU stu1[], STU stu2[], int studentnum, char classes[])//ʹ�ṹ��stu1�е���ͬ�༶����Ϣ��ֵ��stu2
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

void ClasstoFile(STU stu[],int n)//�����½�һ���ļ�������ͬרҵ����
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

int Dormitorystu1tostu2(STU stu1[], STU stu2[], int studentnum, int dormitory)//ʹ�ṹ��stu1�е���ͬ���ҵ���Ϣ��ֵ��stu2
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

void DormitorytoFile(STU stu[],int n)//���ڽ���һ���ļ�������ͬ���ҵ���
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

int Provincestu1tostu2(STU stu1[], STU stu2[], int studentnum, char province[])//ʹ�ṹ��stu1�е���ͬʡ�ݵ���Ϣ��ֵ��stu2
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

void ProvincetoFile(STU stu[],int n)//�����½�һ���ļ�������ͬʡ�ݵ���
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

int Nationstu1tostu2(STU stu1[], STU stu2[], int studentnum, char nation[])//ʹ�ṹ��stu1�е���ͬ�������Ϣ��ֵ��stu2
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

void NationtoFile(STU stu[],int n)//�����½�һ���ļ�������ͬ�������
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

void SelectFontColor(int n)//ѡ��������ɫ
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
        char a[36]="abcdefghijklmnopqrstuvwxyz123456789";//����һ������26��Сд��ĸ��9�����ֵ��ַ���
        printf("\t\t\t������������û���:");
        scanf("%lld",&stuID);
        printf("\t\t\t��������������룺");
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
        printf("\n\t\t\t����֤��\t");
        srand((int)time(0));//��ʼ�������������
        for(k=0;k<4;k++)
        {
            j= rand()%35;//ȡ��0~25�������
            printf("%c",a[j]);//���ַ��������ȡһ��Сд��ĸ����ѭ���ĴΣ�����ĸ������Сд��ĸ
            output1[k]=a[j];
        }
        printf("\n\t\t\t��������֤�룺");
        scanf("%s",output2);
        if(strcmp(output1,output2) == 0)
        {
            int i = SearchID(enter, number, stuID, password);
            if(i == -1)
            {
                printf("\n\t\t\t!��������û��������ڡ�\n");
                printf("\t\t\t!���������룡\n");
                Sleep(1000);
            }
            else if (i == 0)
            {
                printf("\n\t\t\t!�ף��������\n");
                printf("\t\t\t!���������룡\n");
                Sleep(1000);
            }
            else
            {
                ch = 'Y';
                printf("\n\t\t\t�ף��ɹ���½!\n");
                printf("\t\t\t���ڼ������Ժ�\n");
                Sleep(1000);
                Load();
            }
        }
        else
        {
            printf("\n\t\t\t�ף���֤���������");
            printf("\n\t\t\t���������룡");
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

int SearchStudentID2(STU2 pupil[], long int ID,int number)//���ڶ�ѧ�ŵĲ���
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

void PrintInformation2(STU2 pupil[],int number,int n)//���ڴ�ӡѧ���������Ϣ
{
    printf("         ѧ��                 ����       һ��ͨ       ����    ˮ���\n");
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

void AlterOnecard(STU2 pupil[], int number, int n, int money)//������һ��ͨ���Ǯ
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

void AlterInterFee(STU2 pupil[], int number, int n, int money)//���ڳ�ֵ����
{
    int i;
    for (i = 0; i < number; i++)
    {
        if (i == n)
        {
            if(money > pupil[i].Onecard)
            {
                printf("\t\t\t\tһ��ͨ���㣬���ȳ�ֵһ��ͨ��");
                return;
            }
            else
            {
                pupil[i].Onecard-=money;
                pupil[i].Interfee+=money;
                printf("\t\t\t\t��ֵ�ɹ���\n \t\t\t\t���ڷ������Ե�........");
            }
        }
    }
}

void AlterUtiltybill(STU2 pupil[], int number, int n, int money)//���ڳ�ֵˮ���
{
    int i;
    for (i = 0; i < number; i++)
    {
        if (i == n)
        {
            if(money > pupil[i].Onecard)
            {
                printf("\t\t\t\tһ��ͨ���㣬���ȳ�ֵһ��ͨ��");
                return;
            }
            else
            {
                pupil[i].Onecard-=money;
                pupil[i].utilitybill+=money;
                printf("\t\t\t\t��ֵ�ɹ���\n ���ڷ������Ե�........");
            }
        }
    }
}

void AlterPassword(STU3 enter[], long long int ID, char password[], int n)//���ڶ�������޸�
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

void WritetoFile6(STU3 enter[], int n)//���ڶ������д��
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

void color_back()              //�����ı��ַ�����ɫ
{
        int i;
        srand((unsigned)time(NULL));      //��ʼ��ʱ��
        i=rand()%15;                                 //���һ��0��14������
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
    printf("\t\t��������������������������������������\n");
    printf("\t\t��\t\t\t\t\t\t\t\t\t��\n");
    color_back();                  //���һ���ı���ɫ
    Sleep(400);                    //��ϵͳ��ͣ300���룬1�� = 1 000 ����
    printf("\t\t��\t\t������������������������������������������������������������\t\t\t\t��\n");
    printf("\t\t��\t\t��лл���ʹ�ã���ӭ�´ι��٣���\t\t\t\t��\n");
    printf("\t\t��\t\t������������������������������������������������������������\t\t\t\t��\n");
    color_back();
    Sleep(400);
    printf("\t\t��\t\t\t\t\t\t\t\t\t��\n");
    printf("\t\t��\t\t��������������������������������������������������������������������������������������\t\t��\n");
    printf("\t\t��\t\t��Thank you for your use. Welcome next time��\t\t��\n");
    printf("\t\t��\t\t��������������������������������������������������������������������������������������\t\t��\n");
    color_back();
    Sleep(400);
    printf("\t\t��\t\t\t\t\t\t\t\t\t��\n");
    printf("\t\t��\t\t������������������\t\t\t��������������\t\t\t��\n");
    printf("\t\t��\t\t�� �����˩�\t\t\t�� ��Ʃ�\t\t\t��\n");
    printf("\t\t��\t\t������������������\t\t\t��������������\t\t\t��\n");
    color_back();
    Sleep(400);
    printf("\t\t��\t\t\t\t\t\t\t\t\t��\n");
    printf("\t\t��\t\t��������������\t\t\t\t����������������������\t\t��\n");
    printf("\t\t��\t\t�� ʱ�䩧\t\t\t\t�� 2017.12 ��\t\t��\n");
    printf("\t\t��\t\t��������������\t\t\t\t����������������������\t\t��\n");
    color_back();
    Sleep(400);
    printf("\t\t��\t\t\t\t\t\t\t\t\t��\n");
    printf("\t\t��������������������������������������\n");
    printf("\n\n");
}

void quit()
{
    int i;                                   //�û�ѭ��
    for(i=0;i<5;i++)
        display_picture();      //��ӡ����Ч��
    exit(0);
}

void show()
{
    int k;
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t  ����������������������������������������������������������������������\n");
    printf("\t\t\t\t  �� �ﻶӭʹ��ѧ��������Ϣ����ϵͳ�\n");
    printf("\t\t\t\t  ����������������������������������������������������������������������\n");
    printf("\n\n\n\n");
    printf("\t\t\t\t\t�����������ݣ����Ե�......\n\n");
    for (k = 0; k < 40; k++)
    {
        if(k > 10)
            Sleep(10);
        else Sleep(50);
        printf("�� ");
    }
}
