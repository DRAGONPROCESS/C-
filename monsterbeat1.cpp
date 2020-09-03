#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;

#define VERSION 1

int main();
void save();
void config_levelup();
void monstermacro(int,int,string,string);
void PlayerInventory();
void wardown(string);
void war(int);
void MonsterspawnMessage();
void RemoveCursorPoint(void);
void MainMessage(string,int);
void tutorial();
void NewGame();
void LoadGame();
void spawn();

struct state{
    int lvl=1;
    int exp=0;
    int hp=100;
    int att=10;
    int maxhp=100;
    int items[10]={0};
    //1:������ 2:��� 3:������� 
};
struct state PlayerState;

void save(){
    if (MessageBoxA(NULL,"������ �����Ͻðڽ��ϱ�?", "���ӵ����� ����", MB_YESNO) == IDYES)
    {
        string filePath = "D:\\MonsterBeat_DataBase.txt";
	ofstream writeFile(filePath.data());
	if(writeFile.is_open()){
		writeFile << PlayerState.lvl<< " " <<PlayerState.exp<< " " <<PlayerState.hp
        << " " << PlayerState.att<<endl;
        for(int i=0;i<10;i++) writeFile << PlayerState.items[i] << " ";
		writeFile.close();
	}
	system("cls");
	return;
    }
    else
    {
    return;
    }
}

void config_levelup(){
        if(PlayerState.exp>=100*PlayerState.lvl){
        PlayerState.lvl++; 
        PlayerState.exp = PlayerState.exp -(100*PlayerState.lvl);
        MessageBox(0,"������ �ϼ̽��ϴ�!","������!",MB_OK);
    }
}

void monstermacro(int monsterhp,int monsteratt,string mob1,string mob2){
        char ascii;
        int hpfull=0;
        while(1){
        system("cls");
        cout << "[ "<< mob2  <<  " ]" << "\nHP: " << monsterhp << "���ݷ�: " << monsteratt << "\n\n                   [a] ����     [b] HPȸ�� (1ȸ��)     [c] ��������\n\n\n" << "[ �� ]\nHP: " << PlayerState.hp << "���ݷ�: "<< PlayerState.att;
        ascii=getch();
        if(ascii==97){
        monsterhp = monsterhp - PlayerState.att;
        PlayerState.hp = PlayerState.hp - monsteratt;
        }
        else if(ascii==98&&hpfull==0){
        PlayerState.hp = PlayerState.maxhp;
        hpfull=1;
        }
        else if(ascii==99){
            wardown("escape");
            break;
        }
        if(PlayerState.hp>PlayerState.maxhp) PlayerState.hp=PlayerState.maxhp;
        if(monsterhp<=0){
            wardown(mob1);
            break;
        }
        if(PlayerState.hp<=0){
            wardown("player");
            break;
        }
    }
}

void PlayerInventory(){
    int i;
    char ascii;
    system("cls");
    cout << "[  �÷��̾� ���ȹ� �κ��丮  ]\n" << endl;
    if(PlayerState.items[0]!=0){
        cout << "�������� ���� x " << PlayerState.items[0] << endl;
    }
    else if(PlayerState.items[1]!=0){
        cout << "����� ����� x " << PlayerState.items[1] << endl;
    }
    else if(PlayerState.items[2]!=0){
        cout << "��������� �۰��� x " << PlayerState.items[2] << endl;
    }
    cout << "\n\n\n\n�÷��̾��: " << PlayerState.lvl << "\n�÷��̾� ����ġ: "<< 100*PlayerState.lvl << "/"
    << PlayerState.exp << "\n\n\n\n[q] �ڷΰ���";
    while(1){
        ascii=getch();
        if(ascii==113) break;
    }
}

void wardown(string mob){
    if(mob=="slime"){
    system("cls");
    cout << "�����Ӱ��� �������� �¸��ϼ̽��ϴ�.\n[+] �������� ����x1\n[+] ����ġ +20\n\n\n\n[q] ���ư���";
    PlayerState.items[0]++;
    PlayerState.exp = PlayerState.exp + 20;
    char ascii;
    while(1){
        ascii=getch();
        if(ascii==113) break;
    }
}
else if(mob=="goblin"){
    system("cls");
    cout << "������� �������� �¸��ϼ̽��ϴ�.\n[+] ����� �����x1\n[+] ����ġ +50\n\n\n\n[q] ���ư���";
    PlayerState.items[1]++;
    PlayerState.exp = PlayerState.exp + 50;
    char ascii;
    while(1){
        ascii=getch();
        if(ascii==113) break;
    }
}
else if(mob=="hugemon"){
    system("cls");
    cout << "������װ��� �������� �¸��ϼ̽��ϴ�.\n[+] ��������� �۰���x1\n[+] ����ġ +80\n\n\n\n[q] ���ư���";
    PlayerState.items[2]++;
    PlayerState.exp = PlayerState.exp + 80;
    char ascii;
    while(1){
        ascii=getch();
        if(ascii==113) break;
    }
}
else if(mob=="player"){
    system("cls");
    cout << "�������� �й��ϼ̽��ϴ�.\n������ ���ư��ϴ�.\n\n\n\n[q] ���ư���";
    PlayerState.hp = PlayerState.maxhp;
    char ascii;
    while(1){
        ascii=getch();
        if(ascii==113) break;
    }
}
else if(mob=="escape"){
    system("cls");
    cout << "�������� ���������� ���������ϴ�.\n\n\n\n[q] ���ư���";
    char ascii;
    while(1){
        ascii=getch();
        if(ascii==113) break;
    }
}
}

void war(int number){
    int monsterhp;
    int monsteratt;
    char ascii;
    if(number<=1||number>3){
        monsterhp=80;
        monsteratt=10;
        monstermacro(monsterhp,monsteratt,"slime","������");
    }
    else if(number==2){
        monsterhp=150;
        monsteratt=20;
        monstermacro(monsterhp,monsteratt,"goblin","���");
        }
    else if(number==3){
        monsterhp=80;
        monsteratt=40;
        monstermacro(monsterhp,monsteratt,"hugemon","�������");
}
}

void MonsterspawnMessage(){
    int num;
    char ascii;
    system("cls");
    cout << "���ͻ���� �Ͻðڽ��ϱ�?\n\n\n[Space bar] ��\n[q] �ƴϿ�";
    while(1){
        ascii = getch();
        if(ascii==32){
          num = rand()%10;
          war(num);
          break;
      }
        else if(ascii==113) break;
    }
}

void MainMessage(string str,int sleep)
{
    if(sleep)
    {
    Sleep(30);
    system("cls");
    cout << str << "\n\n\n[1] �� ����\n[2] �ҷ�����\n[3] ����\n[4] ������\n\n\nVer. "<<VERSION;
    }
    else if(!sleep)
    {
    system("cls");
    cout << str << "\n\n\n[1] �� ����\n[2] �ҷ�����\n[3] ����\n[4] ������\n\n\nVer."<<VERSION;
}
}

void RemoveCursorPoint(void)
{
 CONSOLE_CURSOR_INFO curInfo; 
 GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curInfo); 
 curInfo.bVisible = 0;
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curInfo);
}

void tutorial(){
    char ascii;
    system("cls");
    cout << "[!] �÷��̾�� '@'��ǥ�õǸ�, �÷��̾��̵���\nWASD�� ������ �� �ֽ��ϴ�.\n[!] ���� ������Ҵ� 'O'\n[!] ��Ż�� '*'�� ǥ�õ˴ϴ�.\n\n\n\n[A] Ȯ��\n";
    while(1){
        ascii = getch();
        if(ascii==97) break;
    }
    main();
}

void NewGame(){
    PlayerState.lvl=1;
    PlayerState.exp=0;
    PlayerState.hp=100;
    PlayerState.att=10;
    PlayerState.maxhp=100;
    for(int i=0;i<10;i++) PlayerState.items[i]=0;
    spawn();
}

void spawn(){
    SetConsoleTitle("[  ������ ����  ]");
    int i,j,x,y,monster=0;
    char ascii;
    string arr[10][10];
    for(i=0;i<10;i++){ //�� ���� 
        for(j=0;j<10;j++){
        arr[i][j]='-';
        }
    }
    arr[4][4]='@';
    while(1){//�÷��̾� ������ ��ǥ�� ���
    config_levelup();
    system("cls"); 
        for(i=0;i<10;i++){
        for(j=0;j<10;j++){
        if(arr[i][j]=="@"){
        y=i;
        x=j;
        }
        }
    }
    for(i=0;i<10;i++){
            int ran1 = rand()%10;
            int ran2 = rand()%10;
        if(arr[ran1][ran2]=="-"){
            if(monster<10){
                monster++;
                arr[ran1][ran2]='O';
            }
            }
        }
        cout << "[V] ���ӵ���������\n[I] �κ��丮�� ���� Ȯ��\n[T] Ÿ��Ʋȭ������\n\n\n\n";
    for(i=0;i<10;i++){ //�� ��� 
        for(j=0;j<10;j++){
        cout << arr[i][j];
        }
        cout << "\n";
    }
    
    ascii = getch();
    if(ascii==105){//�÷��̾� �κ��丮�� ���ȿ��� 
    PlayerInventory();
    }
    else if(ascii==118){//����  
    save();
    }
    else if(ascii==116){//Ÿ��Ʋȭ������
     return;
    }
    else if(ascii==97&&x!=0&&arr[y][x-1]=="-"){//���������̵� 
    arr[y][x]='-';
    arr[y][x-1]='@';
    }
    else if(ascii==100&&x!=9&&arr[y][x+1]=="-"){//�����������̵� 
    arr[y][x]='-';
    arr[y][x+1]='@';
    }
    else if(ascii==119&&y!=0&&arr[y-1][x]=="-"){//�����̵� 
    arr[y][x]='-';
    arr[y-1][x]='@';
    }
    else if(ascii==115&&y!=9&&arr[y+1][x]=="-"){ //�Ʒ����̵� 
    arr[y][x]='-';
    arr[y+1][x]='@';
    }
    
    else if(ascii==97&&x!=0&&arr[y][x-1]=="O"){//���������̵� 
    arr[y][x]='-';
    arr[y][x-1]='@';
    monster--;
    MonsterspawnMessage();
    }
    else if(ascii==100&&x!=9&&arr[y][x+1]=="O"){//�����������̵� 
    arr[y][x]='-';
    arr[y][x+1]='@';
    monster--;
    MonsterspawnMessage();
    }
    else if(ascii==119&&y!=0&&arr[y-1][x]=="O"){//�����̵� 
    arr[y][x]='-';
    arr[y-1][x]='@';
    monster--;
    MonsterspawnMessage();
    }
    else if(ascii==115&&y!=9&&arr[y+1][x]=="O"){ //�Ʒ����̵� 
    arr[y][x]='-';
    arr[y+1][x]='@';
    monster--;
    MonsterspawnMessage();
    }
    else system("cls");
}
}

void LoadGame(){
    int i;
    string filePath = "D:\\MonsterBeat_DataBase.txt";
    ifstream openFile(filePath.data());
	if(openFile.is_open()){
		string line;
        openFile >> PlayerState.lvl >>
        PlayerState.exp >> PlayerState.hp >> PlayerState.att;
		    for(i=0;i<10;i++) openFile >> PlayerState.items[i];
		}
		openFile.close();
system("cls");
spawn();
}

int main(){
    char ascii;
    system("mode con: cols=70 lines=20");
    RemoveCursorPoint();
    SetConsoleTitle("Monster Beat");
    system("cls");
    while(1){
    MainMessage("Mo",false);
    MainMessage("Most",true);
    MainMessage("Monster",true);
    MainMessage("Monster Be",true);
    MainMessage("Monster Beat",true);
    MainMessage("Monster Beat!!!",true);
    ascii = getch();
    if(ascii==49) NewGame();
    else if(ascii==50) LoadGame();
    else if(ascii==51) tutorial();
    else if(ascii==52) break;
    else continue;
    }
}
