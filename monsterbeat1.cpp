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
    //1:슬라임 2:고블린 3:대왕지네 
};
struct state PlayerState;

void save(){
    if (MessageBoxA(NULL,"정말로 저장하시겠습니까?", "게임데이터 저장", MB_YESNO) == IDYES)
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
        MessageBox(0,"레벨업 하셨습니다!","레벨업!",MB_OK);
    }
}

void monstermacro(int monsterhp,int monsteratt,string mob1,string mob2){
        char ascii;
        int hpfull=0;
        while(1){
        system("cls");
        cout << "[ "<< mob2  <<  " ]" << "\nHP: " << monsterhp << "공격력: " << monsteratt << "\n\n                   [a] 공격     [b] HP회복 (1회용)     [c] 도망가기\n\n\n" << "[ 나 ]\nHP: " << PlayerState.hp << "공격력: "<< PlayerState.att;
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
    cout << "[  플레이어 스탯및 인벤토리  ]\n" << endl;
    if(PlayerState.items[0]!=0){
        cout << "슬라임의 진액 x " << PlayerState.items[0] << endl;
    }
    else if(PlayerState.items[1]!=0){
        cout << "고블린의 쇠붙이 x " << PlayerState.items[1] << endl;
    }
    else if(PlayerState.items[2]!=0){
        cout << "대왕지네의 송곳니 x " << PlayerState.items[2] << endl;
    }
    cout << "\n\n\n\n플레이어레벨: " << PlayerState.lvl << "\n플레이어 경험치: "<< 100*PlayerState.lvl << "/"
    << PlayerState.exp << "\n\n\n\n[q] 뒤로가기";
    while(1){
        ascii=getch();
        if(ascii==113) break;
    }
}

void wardown(string mob){
    if(mob=="slime"){
    system("cls");
    cout << "슬라임과의 전투에서 승리하셨습니다.\n[+] 슬라임의 진액x1\n[+] 경험치 +20\n\n\n\n[q] 돌아가기";
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
    cout << "고블린과의 전투에서 승리하셨습니다.\n[+] 고블린의 쇠붙이x1\n[+] 경험치 +50\n\n\n\n[q] 돌아가기";
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
    cout << "대왕지네과의 전투에서 승리하셨습니다.\n[+] 대왕지네의 송곳니x1\n[+] 경험치 +80\n\n\n\n[q] 돌아가기";
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
    cout << "전투에서 패배하셨습니다.\n마을로 돌아갑니다.\n\n\n\n[q] 돌아가기";
    PlayerState.hp = PlayerState.maxhp;
    char ascii;
    while(1){
        ascii=getch();
        if(ascii==113) break;
    }
}
else if(mob=="escape"){
    system("cls");
    cout << "전투에서 성공적으로 도망갔습니다.\n\n\n\n[q] 돌아가기";
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
        monstermacro(monsterhp,monsteratt,"slime","슬라임");
    }
    else if(number==2){
        monsterhp=150;
        monsteratt=20;
        monstermacro(monsterhp,monsteratt,"goblin","고블린");
        }
    else if(number==3){
        monsterhp=80;
        monsteratt=40;
        monstermacro(monsterhp,monsteratt,"hugemon","대왕지네");
}
}

void MonsterspawnMessage(){
    int num;
    char ascii;
    system("cls");
    cout << "몬스터사냥을 하시겠습니까?\n\n\n[Space bar] 네\n[q] 아니요";
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
    cout << str << "\n\n\n[1] 새 게임\n[2] 불러오기\n[3] 도움말\n[4] 나가기\n\n\nVer. "<<VERSION;
    }
    else if(!sleep)
    {
    system("cls");
    cout << str << "\n\n\n[1] 새 게임\n[2] 불러오기\n[3] 도움말\n[4] 나가기\n\n\nVer."<<VERSION;
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
    cout << "[!] 플레이어는 '@'로표시되며, 플레이어이동은\nWASD로 움직일 수 있습니다.\n[!] 몬스터 생성장소는 'O'\n[!] 포탈은 '*'로 표시됩니다.\n\n\n\n[A] 확인\n";
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
    SetConsoleTitle("[  시작의 마을  ]");
    int i,j,x,y,monster=0;
    char ascii;
    string arr[10][10];
    for(i=0;i<10;i++){ //맵 생성 
        for(j=0;j<10;j++){
        arr[i][j]='-';
        }
    }
    arr[4][4]='@';
    while(1){//플레이어 생성과 좌표값 계산
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
        cout << "[V] 게임데이터저장\n[I] 인벤토리및 스탯 확인\n[T] 타이틀화면으로\n\n\n\n";
    for(i=0;i<10;i++){ //맵 출력 
        for(j=0;j<10;j++){
        cout << arr[i][j];
        }
        cout << "\n";
    }
    
    ascii = getch();
    if(ascii==105){//플레이어 인벤토리및 스탯열기 
    PlayerInventory();
    }
    else if(ascii==118){//저장  
    save();
    }
    else if(ascii==116){//타이틀화면으로
     return;
    }
    else if(ascii==97&&x!=0&&arr[y][x-1]=="-"){//왼쪽으로이동 
    arr[y][x]='-';
    arr[y][x-1]='@';
    }
    else if(ascii==100&&x!=9&&arr[y][x+1]=="-"){//오른쪽으로이동 
    arr[y][x]='-';
    arr[y][x+1]='@';
    }
    else if(ascii==119&&y!=0&&arr[y-1][x]=="-"){//위로이동 
    arr[y][x]='-';
    arr[y-1][x]='@';
    }
    else if(ascii==115&&y!=9&&arr[y+1][x]=="-"){ //아래로이동 
    arr[y][x]='-';
    arr[y+1][x]='@';
    }
    
    else if(ascii==97&&x!=0&&arr[y][x-1]=="O"){//왼쪽으로이동 
    arr[y][x]='-';
    arr[y][x-1]='@';
    monster--;
    MonsterspawnMessage();
    }
    else if(ascii==100&&x!=9&&arr[y][x+1]=="O"){//오른쪽으로이동 
    arr[y][x]='-';
    arr[y][x+1]='@';
    monster--;
    MonsterspawnMessage();
    }
    else if(ascii==119&&y!=0&&arr[y-1][x]=="O"){//위로이동 
    arr[y][x]='-';
    arr[y-1][x]='@';
    monster--;
    MonsterspawnMessage();
    }
    else if(ascii==115&&y!=9&&arr[y+1][x]=="O"){ //아래로이동 
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
