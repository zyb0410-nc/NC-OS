#include<iostream>
#include<cstring>
#include<fstream>
#include<unistd.h>
#include<stdlib.h>
#include<sstream>
using namespace std;
/*
NC OS is a grace OS

These notices to show my mind about the NC OS 3 Stable Developer Release.
We're spining our brain to think more ideas.

1.Update About Clip UI -- New name of the Clip UI (Clip UI X). It'a great name with a new version.
2.Kernel Update

*/
//Class
class HeaderCoreDataBase
{
public:
    string OS_version,OS_platform,OS_start;
    string Kernel_version;
    string UI_version;
    string User_username,User_password,User_password_tip;
    string Secure_version;
    string Framework_version;
}Lib;
//Data
string NowLocation;
char Image[40][101] = {'\0'};
string ColorData[40][100] = {"30"};
//Functions
//HeaderCore Basic Functions
void ReBoot()
{
    system("./OS");
    exit(0);
}
void Shutdown()
{
    exit(0);
}
void CleanScreen()
{
    system("clear");
}
void WhiteScreen()
{
    for(int i = 0;i < 40;i++)
    {
        for(int j = 0;j < 100;j++)
        {
            Image[i][j] = ' ';
        }
    }
}
void ShowImage()
{
    for(int i = 0;i < 40;i++)
    {
        for(int j = 0;j < 100;j++)
        {
            cout<<"\033["<<ColorData[i][j]<<"m"<<Image[i][j]<<"\033[0m";
        }
        cout<<endl;
    }
}
string ReplaceText(string info,char from,char to)
{
    char infoc[1000] = {'\0'};
    strcpy(infoc,info.c_str());
    for(int i = 0;i < strlen(infoc);i++)
    {
        if(infoc[i] == from)
        {
            infoc[i] = to;
        }
    }
    string result = infoc;
    return result;
}
string NRead(string path)
{
    ifstream tmp;
    tmp.open(path);
    string tmps;
    tmp >> tmps;
    tmp.close();
    return tmps;
}
int StringLength(string in)
{
    char inc[1000] = {'\0'};
    strcpy(inc,in.c_str());
    return strlen(inc);
}
void NWrite(string path,string text)
{
    ofstream tmp(path);
    tmp << text;
    tmp.close();
}
int ItemsInCharNum(string infos,char target)
{
    int partnum = 1;

    char info[1000] = {'\0'};
    strcpy(info,infos.c_str());
    for(int i = 0;i < strlen(info);i++)
    {
        if(info[i] == target)
        {
            partnum++;
        }
    }

    return partnum;
}
void WhiteTwoChar(char target[][500],int cols)
{
    for(int i = 0;i < cols;i++)
    {
        target[i][0] = '\0';
    }
}
void SplitChar(char * info,char target,char result[][500])
{
    int partnum = ItemsInCharNum(info,target);

    int nownum = 0,nownum1 = 0;

    for(int i = 0;i < strlen(info);i++)
    {
        if(info[i] != target)   result[nownum][i-nownum1] = info[i];

        else
        {
            nownum1 = i+1; 
            nownum++;
        }
    }
}
string IntToString(int indata)
{
    stringstream ss;
    ss << indata;
    string out_string = ss.str();
    return out_string;
}
void DrawLines(int x,int y,int x1,int y1,char text,string color)
{
    if(x1 > x && y == y1)
    {
        for(int i = x;i <= x1;i++)
        {
            Image[i][y] = text;
            ColorData[i][y] = color;
        }
    }
    if(x1 == x && y < y1)
    {
        for(int i = y;i <= y1;i++)
        {
            Image[x][i] = text;
            ColorData[x][i] = color;
        }
    }
}
void AroundBorder()
{
    for(int i = 0;i < 40;i++)
    {
        Image[i][0] = '$';
        Image[i][99] = '$';
        ColorData[i][0] = "33";
        ColorData[i][99] = "33";
    }
    for(int j = 1;j < 99;j++)
    {
        Image[0][j] = '$';
        Image[39][j] = '$';
        Image[34][j] = '_';
        ColorData[34][j] = "33";
        ColorData[0][j] = "33";
        ColorData[39][j] = "33";
    }
}
void WhiteScreenInRange(int x1,int y1,int x2,int y2)
{
    for(int i = x1;i < x2+1;i++)
    {
        for(int j = y1;j < y2+1;j++)
        {
            Image[i][j] = ' ';
        }
    }
}
void FillText(int x,int y,string title,string titlecolor)
{
    char titlec[1000];
    strcpy(titlec,title.c_str());
    for(int i = y;i < y+strlen(titlec);i++)
    {
        Image[x][i] = titlec[i-y];
        ColorData[x][i] = titlecolor;
    }
}
void DrawBtn(int x,int y,int w,int h,string title,string btncolor,string titlecolor)
{
    for(int i = x+1;i < x+h-1;i++)
    {
        Image[i][y] = '|';
        Image[i][y+w-1] = '|';
        ColorData[i][y] = btncolor;
        ColorData[i][y+w-1] = btncolor;
    }
    for(int i = y+1;i < y+w-1;i++)
    {
        Image[x][i] = '_';
        Image[x+h-1][i] = '_';
        ColorData[x][i] = btncolor;
        ColorData[x+h-1][i] = btncolor;
    }
    Image[x+1][y] = '/';
    Image[x+1][y+w-1] = '\\';
    Image[x+h-1][y] = '\\';
    Image[x+h-1][y+w-1] = '/';
    ColorData[x+1][y] = btncolor;
    ColorData[x+1][y+w-1] = btncolor;
    ColorData[x+h-1][y] = btncolor;
    ColorData[x+h-1][y+w-1] = btncolor;
    //filltext
    char titlec[1000];
    strcpy(titlec,title.c_str());
    int midnumw = (w-2-strlen(titlec))/2;
    int midnumh = h/2;
    FillText(x+midnumh,y+midnumw+1,title,titlecolor);
}
void DrawWindow(int x,int y,int w,int h,string title,string windowcolor,string titlecolor)
{
    WhiteScreenInRange(x,y,x+h-1,y+w-1);

    for(int i = x+1;i < x+h-1;i++)
    {
        Image[i][y] = '|';
        Image[i][y+w-1] = '|';
        ColorData[i][y] = windowcolor;
        ColorData[i][y+w-1] = windowcolor;
    }
    for(int i = y+1;i < y+w-1;i++)
    {
        Image[x][i] = '_';
        Image[x+h-1][i] = '_';
        Image[x+2][i] = '_';
        ColorData[x][i] = windowcolor;
        ColorData[x+h-1][i] = windowcolor;
        ColorData[x+2][i] = windowcolor;
    }
    Image[x+1][y] = '/';
    Image[x+1][y+w-1] = '\\';
    Image[x+h-1][y] = '\\';
    Image[x+h-1][y+w-1] = '/';
    ColorData[x+1][y] = windowcolor;
    ColorData[x+1][y+w-1] = windowcolor;
    ColorData[x+h-1][y] = windowcolor;
    ColorData[x+h-1][y+w-1] = windowcolor;

    char titlec[1000];
    strcpy(titlec,title.c_str());
    int midnum = (w-2-strlen(titlec))/2;
    FillText(x+1,y+midnum+1,title,titlecolor);
}
void DrawSideBtns(string infos)
{
    WhiteScreenInRange(35,1,38,98);
    char info[500];
    strcpy(info,infos.c_str());
    int itemnum = 0;
    int nownum = 0;
    for(int i = 0;i < strlen(info);i++)
    {
        if(info[i] == '`')
        {
            itemnum++;
        }
        if(info[i] == '^')
        {
            info[i] = ' ';
        }
    }
    char result[50][500] = {' '};
    for(int i = 0;i < itemnum+1;i++)
    {
        for(int j = nownum;j < strlen(info);j++)
        {
            if(info[j] != '`')
            {
                result[i][j-nownum] = info[j];
            }
            else
            {
                nownum = j+1;
                break;
            }
        }
    }
    int yn = 2,bw = 0;
    for(int i = 0;i < itemnum+1;i++)
    {
        bw = strlen(result[i])+3;
        if(i == 0)
        {
            DrawBtn(35,2,bw,3,result[i],"33","33");
            yn = yn + bw + 1;
        }
        else
        {
            DrawBtn(35,yn,bw,3,result[i],"33","33");
            yn = yn + bw + 1;
        }
    }
}
void DrawCircleSquare(int x,int y,int w,int h,string color)
{
    for(int i = x+2;i < x+h-1;i++)
    {
        Image[i][y] = '|';
        Image[i][y+w-1] = '|';
        ColorData[i][y] = color;
        ColorData[i][y+w-1] = color;
    }
    for(int i = y+1;i < y+w-1;i++)
    {
        Image[x][i] = '_';
        Image[x+h-1][i] = '_';
        ColorData[x][i] = color;
        ColorData[x+h-1][i] = color;
    }
    Image[x+1][y] = '/';
    Image[x+h-1][y] = '\\';
    Image[x+h-1][y+w-1] = '/';
    Image[x+1][y+w-1] = '\\';
    ColorData[x+1][y] = color;
    ColorData[x+h-1][y] = color;
    ColorData[x+h-1][y+w-1] = color;
    ColorData[x+1][y+w-1] = color;
}
void MiddleFillText(int x,int winw,int winy,string title,string titlecolor)
{
    char titlec[1000];
    strcpy(titlec,title.c_str());
    for(int i = 0;i < strlen(titlec);i++)
    {
        if(titlec[i] == '^')
        {
            titlec[i] = ' ';
        }
    }
    FillText(x,((winw-2-strlen(titlec))/2) + winy + 1,title,titlecolor);
}
void NMessageBox(int x,int y,string title,string messagetext,string wincolor,string titcolor,string messagetextcolor)
{
    char titlec[500];
    strcpy(titlec,title.c_str());
    char messagetextc[1000];
    strcpy(messagetextc,messagetext.c_str());
    DrawWindow(x,y,strlen(messagetextc)+4,5,title,wincolor,titcolor);
    FillText(x+3,y+2,messagetext,messagetextcolor);
}
//绘制桌面图标
void DrawIcons()
{
    //Get username char
    char UsernameC[100] = {'\0'};
    char Data[100][500] = {'\0'};
    strcpy(UsernameC,Lib.User_username.c_str());
    //Plus Read Path
    char ReadPath[500] = {'\0'};
    sprintf(ReadPath,"%s%s%s","Data/Users/",UsernameC,"/Desktop/Info.di");
    string ReadPathS = ReadPath;
    //Read Info text
    string InfoS = NRead(ReadPathS);
    char InfoC[1000];
    strcpy(InfoC,InfoS.c_str());
    //Think Info Text
    SplitChar(InfoC,'#',Data);

    for(int i = 0;i < ItemsInCharNum(InfoC,'#');i++)
    {
        char TmpInfo1[2][500] = {'\0'},TmpInfo2[100][500] = {'\0'},TmpInfo3[100][500] = {'\0'};;

        SplitChar(Data[i],'=',TmpInfo1);
        string Obj = TmpInfo1[0];
        SplitChar(TmpInfo1[1],'~',TmpInfo2);
        string AppName = TmpInfo2[0];

        if(Obj == "Desktop")
        {
            char * desktoplocation = TmpInfo2[2];
            char desktoplocationtc[2][500] = {'\0'};
            SplitChar(desktoplocation,';',desktoplocationtc);
            int desktopiconx = atoi(desktoplocationtc[0]),desktopicony = atoi(desktoplocationtc[1]);
            WhiteTwoChar(desktoplocationtc,2);
            //Icon size: width:9 height:6
            SplitChar(TmpInfo2[1],';',TmpInfo3);
            string iconinfo,iconcolor,appname = TmpInfo2[0];
            for(int j = 0;j < 6;j++)
            {
                iconinfo = TmpInfo3[j];
                iconcolor = TmpInfo2[3];
                FillText(desktopiconx + j,desktopicony,ReplaceText(iconinfo,'^',' '),iconcolor);
            }
            FillText(desktopiconx + 7,desktopicony,ReplaceText(appname,'^',' '),iconcolor);
        }
    }
}
void GUICommands()
{
    CleanScreen();
    WhiteScreen();
    AroundBorder();
}
void DrawDesktopPattern()
{
    string CommandS = NRead("Data/Users/" + Lib.User_username + "/Desktop/Pattern.dpi");
    char Command[1000] = {'\0'};
    strcpy(Command,CommandS.c_str());
    if(CommandS == "Plain")
    {
        GUICommands();
    }
    else
    {
        char ObjAndInfo[2][500] = {'\0'};
        char PatternList[50][500] = {'\0'};
        SplitChar(Command,':',ObjAndInfo);
        SplitChar(ObjAndInfo[1],'-',PatternList);

        string ClassName = ObjAndInfo[0];
        string Text = PatternList[0];
        //11*3 竖列 Three Partitions, 11 pixels per partition
        //14*7 横列 Fourteen Partitions, 7 pixels per partition
        //Result partitions: 14(横)*3（竖）
        //Result Pixels: 7(heng)*11(shu)

        if(ClassName == "Customize")
        {
            for(int z = 1;z <= 33;z++)
            {
                for(int i = 0;i < 14;i++)
                {
                    FillText(z,i*7+1,ReplaceText(Text,'^',' '),"37");
                }
            }   
        }
        else
        {
            NMessageBox(5,15,"Desktop Pattern Warring","Your Desktop Pattern's Conofig Files Isn't Right, Please Change Your Local Config And ReBoot!","33","32","31");
        }
    }
}
void DesktopWorks()
{
    GUICommands();
    DrawDesktopPattern();
    DrawIcons();
}
void DrawNCheckBox(int x,int y,string title,bool is_checked,string color)
{
    if(is_checked == true)
    {
        FillText(x+1,y,"(*)",color);
        FillText(x+1,y+4,title,color);
    }
    else
    {
        FillText(x+1,y,"( )",color);
        FillText(x+1,y+4,title,color);
    }
}
void BugScreen()
{
    MiddleFillText(14,100,0,"Your OS has some problems!","31");
    MiddleFillText(15,100,0,"We'll reboot the OS for you in 5 secs!","31");
    MiddleFillText(16,100,0,"Please check the OS's local files!","31");
    DrawSideBtns("^Recovery^Screen");
}
//刷新系统各项参数
void RefreshData()
{
    Lib.OS_version = NRead("System/OS/Version.nsf");
    Lib.Kernel_version = NRead("System/Kernel/Version.nsf");
    Lib.Secure_version = NRead("System/Secure/Version.nsf");
    string FrameworkConfig = NRead("System/Frameworks/Config.nsf");
    string UIConfig = NRead("System/UIs/Config.nsf");
    Lib.OS_start = NRead("System/OS/Start.nsf");
    Lib.OS_platform = NRead("System/OS/Platform.nsf");
    char Path[500] = {'\0'};
    sprintf(Path,"%s%s%s","System/Frameworks/",ReplaceText(FrameworkConfig,'^',' ').c_str(),"/Version.nsf");
    string PathS = Path;
    Lib.Framework_version = NRead(PathS);
    Path[0] = '\0';
    sprintf(Path,"%s%s%s","System/UIs/",ReplaceText(UIConfig,'^',' ').c_str(),"/Version.nsf");
    PathS = Path;
    Lib.UI_version = NRead(PathS);
    if(Lib.OS_start == "True")
    {
        string UsnmTmpS = NRead("Data/Users/UserInfo.nsf");
        char UsnmTmp[10000] = {'\0'};
        strcpy(UsnmTmp,UsnmTmpS.c_str());
        //用户上限为500个用户
        char Users[500][500] = {'\0'};
        SplitChar(UsnmTmp,'-',Users);
        string PreSelect = NRead("Data/Users/SelectUser.nsf");
        int PreNum;
        for(int z = 0;z < ItemsInCharNum(UsnmTmp,'-');z++)
        {
            string change = Users[z];
            if(PreSelect == change)
            {
                PreNum = z;
            }
        }
        Lib.User_username = Users[PreNum];
        char ReadPath[100] = {'\0'};
        sprintf(ReadPath,"%s%s%s","Data/Users/",Lib.User_username.c_str(),"/UserInfo.nsf");
        string ReadPathS = ReadPath;
        string InfoClassS = NRead(ReadPathS);
        char InfoClass[500] = {'\0'};
        strcpy(InfoClass,InfoClassS.c_str());
        char ResultClassInfo[2][500] = {'\0'};
        SplitChar(InfoClass,'-',ResultClassInfo);
        Lib.User_password = ResultClassInfo[0];
        Lib.User_password_tip = ResultClassInfo[1];
    }
}
//交换内核数据函数
string ExchangeHDCsData(string datain)
{
    if(datain == "%HDC.OS_version")
    {
        return Lib.OS_version;
    }
    if(datain == "%HDC.Kernel_version")
    {
        return Lib.Kernel_version;
    }
    if(datain == "%HDC.OS_platform")
    {
        return Lib.OS_platform;
    }
    if(datain == "%HDC.UI_version")
    {
        return Lib.UI_version;
    }
    if(datain == "%HDC.Secure_version")
    {
        return Lib.Secure_version;
    }
    if(datain == "%HDC.Framework_version")
    {
        return Lib.Framework_version;
    }
    if(datain == "%HDC.User_username")
    {
        return Lib.User_username;
    }
    if(datain == "%HDC.User_password_tip")
    {
        return Lib.User_password_tip;
    }
    else
    {
        return datain;
    }
}
//Get a NScript Application's Window's Locations
int GetWinInfo(string scriptpaths,string mode,string nwinobj)
{
    string CommandS = NRead(scriptpaths);
    char Command[2000] = {'\0'};
    strcpy(Command,CommandS.c_str());
    char Data[500][500] = {'\0'};
    SplitChar(Command,'#',Data);

    //Get the value
    int winx = 0,winy = 0,winw = 0,winh = 0;
    string Windows[50] = {""};
    char LocationsOfWindows[50][11] = {'\0'};
    char SizesOfWindows[50][11] = {'\0'};
    int WinNum = 0;
    string WinMode;
    int WinClassNum[50] = {0};
    int WinClassNumStorage = 0;

    for(int z = 0;z < ItemsInCharNum(Command,'#');z++)
    {
        char ObjAndInfo[2][500] = {'\0'};
        char InfoToGet[500][500] = {'\0'};
        char XandY[2][500] = {'\0'};
        char WandH[2][500] = {'\0'};

        SplitChar(Data[z],':',ObjAndInfo);

        string ClassName = ObjAndInfo[0];

        SplitChar(ObjAndInfo[1],'-',InfoToGet);

        if(ClassName == "NMainWin" || ClassName == "NMainWindow")
        {
            WinClassNum[WinClassNumStorage] = z;
            WinClassNumStorage++;
            WinMode = InfoToGet[0];
            winx = atoi(InfoToGet[0]);
            winy = atoi(InfoToGet[1]);
            winw = atoi(InfoToGet[2]);
            winh = atoi(InfoToGet[3]);
            Windows[WinNum] = InfoToGet[8];
            sprintf(LocationsOfWindows[WinNum],"%i%s%i",winx,"-",winy);
            sprintf(SizesOfWindows[WinNum],"%i%s%i",winw,"-",winh);
            WinNum++;
        }
        if(ClassName == "NWin" || ClassName == "NWindow")
        {
            winx = atoi(InfoToGet[0]);
            winy = atoi(InfoToGet[1]);
            winw = atoi(InfoToGet[2]);
            winh = atoi(InfoToGet[3]);
            WinClassNum[WinClassNumStorage] = z;
            WinClassNumStorage++;
            Windows[WinNum] = InfoToGet[7];
            sprintf(LocationsOfWindows[WinNum],"%i%s%i",atoi(InfoToGet[0]),"-",atoi(InfoToGet[1]));
            WinNum++;
        }
    }

    int TargetWinnum = 0;
    for(int i = 0;i < WinNum;i++)
    {
        if(Windows[i] == nwinobj)
        {
            TargetWinnum = i;
        }
    }

    char TmpXandY[2][500] = {'\0'};
    char TmpWandH[2][500] = {'\0'};

    SplitChar(LocationsOfWindows[TargetWinnum],'-',TmpXandY);
    SplitChar(SizesOfWindows[TargetWinnum],'-',TmpWandH);

    winx = atoi(TmpXandY[0]);
    winy = atoi(TmpXandY[1]);
    winw = atoi(TmpWandH[0]);
    winh = atoi(TmpWandH[1]);

    int resultvalue;

    if(mode == "WinX")
    {
        resultvalue = winx;
    }
    if(mode == "WinY")
    {
        resultvalue = winy;
    }
    if(mode == "WinW")
    {
        resultvalue = winw;
    }
    if(mode == "WinH")
    {
        resultvalue = winh;
    }

    return resultvalue;
}
//GUI 图形界面程序框架
void PaperFramework(string appname,string mode,string nwinobj)
{
    char Path[1000] = {'\0'};
    sprintf(Path,"%s%s%s","Data/Apps/",appname.c_str(),"/Graphics/Command.txt");
    string PathS = Path;
    string CommandS = NRead(PathS);
    char Command[2000] = {'\0'};
    strcpy(Command,CommandS.c_str());
    char Data[500][500] = {'\0'};
    SplitChar(Command,'#',Data);

    if(mode == "MoveWindowWithPath" || mode == "MoveWindowByLocationWithPath")
    {
        //Read The Common Files
        string CommandS = NRead(appname);
        char Command[2000] = {'\0'};
        strcpy(Command,CommandS.c_str());
        char Data[500][500] = {'\0'};
        SplitChar(Command,'#',Data);
        //Application common files
        // string APPname,APPversion,OSversion,PFversion;
        int winx = 0,winy = 0,winw = 0,winh = 0;
        string wintit,winsidebtns;
        string titcolor,wincolor;
        string Windows[50] = {""};
        char LocationsOfWindows[50][11] = {'\0'};
        char SizesOfWindows[50][11] = {'\0'};
        int WinNum = 0;
        string WinMode;
        int WinClassNum[50] = {0};
        int WinClassNumStorage = 0;

        for(int z = 0;z < ItemsInCharNum(Command,'#');z++)
        {
            char ObjAndInfo[2][500] = {'\0'};
            char InfoToGet[500][500] = {'\0'};
            char XandY[2][500] = {'\0'};
            char WandH[2][500] = {'\0'};

            SplitChar(Data[z],':',ObjAndInfo);

            string ClassName = ObjAndInfo[0];

            SplitChar(ObjAndInfo[1],'-',InfoToGet);

            if(ClassName == "NMainWin" || ClassName == "NMainWindow")
            {
                WinClassNum[WinClassNumStorage] = z;
                WinClassNumStorage++;
                WinMode = InfoToGet[0];
                if(WinMode == "FULLSCREEN" || WinMode == "fullscreen")
                {
                    winsidebtns = InfoToGet[1];
                    DrawSideBtns(winsidebtns);
                }
                else
                {
                    winx = atoi(InfoToGet[0]);
                    winy = atoi(InfoToGet[1]);
                    winw = atoi(InfoToGet[2]);
                    winh = atoi(InfoToGet[3]);
                    wintit = InfoToGet[4];
                    winsidebtns = InfoToGet[5];
                    string objname;
                    wincolor = InfoToGet[6];
                    titcolor = InfoToGet[7];
                    Windows[WinNum] = InfoToGet[8];
                    sprintf(LocationsOfWindows[WinNum],"%i%s%i",winx,"-",winy);
                    sprintf(SizesOfWindows[WinNum],"%i%s%i",winw,"-",winh);
                    DrawWindow(winx,winy,winw,winh,ReplaceText(wintit,'^',' '),wincolor,titcolor);
                    DrawSideBtns(winsidebtns);
                    WinNum++;
                }
            }
            if(ClassName == "NWin" || ClassName == "NWindow")
            {
                WinClassNum[WinClassNumStorage] = z;
                WinClassNumStorage++;
                Windows[WinNum] = InfoToGet[7];
                string wintit = InfoToGet[4];
                string wincolor = InfoToGet[5],titcolor = InfoToGet[6];
                DrawWindow(atoi(InfoToGet[0]),atoi(InfoToGet[1]),atoi(InfoToGet[2]),atoi(InfoToGet[3]),ReplaceText(wintit,'^',' '),wincolor,titcolor);
                sprintf(LocationsOfWindows[WinNum],"%i%s%i",atoi(InfoToGet[0]),"-",atoi(InfoToGet[1]));
                WinNum++;
            }
        }

        int TargetWinnum = 0;
        for(int i = 0;i < WinNum;i++)
        {
            if(Windows[i] == nwinobj)
            {
                TargetWinnum = i;
            }
        }

        char TmpXandY[2][500] = {'\0'};
        char TmpWandH[2][500] = {'\0'};

        SplitChar(LocationsOfWindows[TargetWinnum],'-',TmpXandY);
        SplitChar(SizesOfWindows[TargetWinnum],'-',TmpWandH);

        int x = atoi(TmpXandY[0]),y = atoi(TmpXandY[1]),w = atoi(TmpWandH[0]),h = atoi(TmpWandH[1]);

        while(mode == "MoveWindowByLocationWithPath")
        {
            WhiteScreen();
            CleanScreen();
            AroundBorder();
            DrawWindow(x,y,w,h,ReplaceText(wintit,'^',' '),wincolor,titcolor);
            DrawSideBtns(winsidebtns);
            ShowImage();
            cout<<"X:"<<x<<" Y:"<<y<<endl;
            NowLocation = "Type X and Y to Move The Window (x space y) >>>";
            cout<<NowLocation;
            int tx,ty;
            cin >> tx >> ty;
            if(Image[tx][ty] != '$')
            {
                x = tx;
                y = ty;
            }

            char WriteInfo[500] = {'\0'};
            sprintf(WriteInfo,"%s%i%s%i%s%i%s%i%s%s%s%s%s%s%s%s%s%s","NMainWin:",x,"-",y,"-",w,"-",h,"-",ReplaceText(wintit,' ','^').c_str(),"-",winsidebtns.c_str(),"-",wincolor.c_str(),"-",titcolor.c_str(),"-",Windows[TargetWinnum].c_str());
            //WinClassNum[TargetWinNum]
            Data[WinClassNum[TargetWinnum]][0] = '\0';
            for(int i = 0;i < strlen(WriteInfo);i++)
            {
                Data[WinClassNum[TargetWinnum]][i] = WriteInfo[i];
            }
            int nownum = 0;
            char ResultWrite[1000] = {'\0'};
            for(int i = 0;i < ItemsInCharNum(Command,'#');i++)
            {
                for(int j = 0;j < strlen(Data[i]);j++)
                {
                    ResultWrite[nownum] = Data[i][j];
                    nownum++;
                }
                if(i != ItemsInCharNum(Command,'#')-1)
                {
                    ResultWrite[nownum] = '#';
                    nownum++;
                }
            }
            string ResultWriteS = ResultWrite;
            NWrite(appname,ResultWriteS);
            break;
        }
        while(mode == "MoveWindowWithPath")
        {
            WhiteScreen();
            CleanScreen();
            AroundBorder();
            DrawWindow(x,y,w,h,ReplaceText(wintit,'^',' '),wincolor,titcolor);
            DrawSideBtns(winsidebtns);
            ShowImage();
            cout<<"X:"<<x<<" Y:"<<y<<endl;
            NowLocation = "MoveWindow By Using W,A,S,D >>>";
            cout<<NowLocation;
            char way;
            cin >> way;
            if(way == 'W' || way == 'w')
            {
                if(Image[x][y] != '$')
                {
                    x--;
                }
            }
            if(way == 'S' || way == 's')
            {
                x++;
            }
            if(way == 'A' || way == 'a')
            {
                if(Image[x][y] != '$')
                {
                    y--;
                }
            }
            if(way == 'D' || way == 'd')
            {
                y++;
            }
            if(way == 'Y' || way == 'y')
            {
                char WriteInfo[500] = {'\0'};
                sprintf(WriteInfo,"%s%i%s%i%s%i%s%i%s%s%s%s%s%s%s%s%s%s","NMainWin:",x,"-",y,"-",w,"-",h,"-",ReplaceText(wintit,' ','^').c_str(),"-",winsidebtns.c_str(),"-",wincolor.c_str(),"-",titcolor.c_str(),"-",Windows[TargetWinnum].c_str());
                //WinClassNum[TargetWinNum]
                Data[WinClassNum[TargetWinnum]][0] = '\0';
                for(int i = 0;i < strlen(WriteInfo);i++)
                {
                    Data[WinClassNum[TargetWinnum]][i] = WriteInfo[i];
                }
                int nownum = 0;
                char ResultWrite[1000] = {'\0'};
                for(int i = 0;i < ItemsInCharNum(Command,'#');i++)
                {
                    for(int j = 0;j < strlen(Data[i]);j++)
                    {
                        ResultWrite[nownum] = Data[i][j];
                        nownum++;
                    }
                    if(i != ItemsInCharNum(Command,'#')-1)
                    {
                        ResultWrite[nownum] = '#';
                        nownum++;
                    }
                }
                string ResultWriteS = ResultWrite;
                NWrite(appname,ResultWriteS);
                break;
            }
        }
    }
    if(mode == "MoveWindow" || mode == "MoveWindowByLocation")
    {
        //Application common files
        // string APPname,APPversion,OSversion,PFversion;
        int winx = 0,winy = 0,winw = 0,winh = 0;
        string wintit,winsidebtns;
        string titcolor,wincolor;
        string Windows[50] = {""};
        char LocationsOfWindows[50][11] = {'\0'};
        char SizesOfWindows[50][11] = {'\0'};
        int WinNum = 0;
        string WinMode;
        int WinClassNum[50] = {0};
        int WinClassNumStorage = 0;

        for(int z = 0;z < ItemsInCharNum(Command,'#');z++)
        {
            char ObjAndInfo[2][500] = {'\0'};
            char InfoToGet[500][500] = {'\0'};
            char XandY[2][500] = {'\0'};
            char WandH[2][500] = {'\0'};

            SplitChar(Data[z],':',ObjAndInfo);

            string ClassName = ObjAndInfo[0];

            SplitChar(ObjAndInfo[1],'-',InfoToGet);

            if(ClassName == "NMainWin" || ClassName == "NMainWindow")
            {
                WinClassNum[WinClassNumStorage] = z;
                WinClassNumStorage++;
                WinMode = InfoToGet[0];
                if(WinMode == "FULLSCREEN" || WinMode == "fullscreen")
                {
                    winsidebtns = InfoToGet[1];
                    DrawSideBtns(winsidebtns);
                }
                else
                {
                    winx = atoi(InfoToGet[0]);
                    winy = atoi(InfoToGet[1]);
                    winw = atoi(InfoToGet[2]);
                    winh = atoi(InfoToGet[3]);
                    wintit = InfoToGet[4];
                    winsidebtns = InfoToGet[5];
                    string objname;
                    wincolor = InfoToGet[6];
                    titcolor = InfoToGet[7];
                    Windows[WinNum] = InfoToGet[8];
                    sprintf(LocationsOfWindows[WinNum],"%i%s%i",winx,"-",winy);
                    sprintf(SizesOfWindows[WinNum],"%i%s%i",winw,"-",winh);
                    DrawWindow(winx,winy,winw,winh,ReplaceText(wintit,'^',' '),wincolor,titcolor);
                    DrawSideBtns(winsidebtns);
                    WinNum++;
                }
            }
            if(ClassName == "NWin" || ClassName == "NWindow")
            {
                WinClassNum[WinClassNumStorage] = z;
                WinClassNumStorage++;
                Windows[WinNum] = InfoToGet[7];
                string wintit = InfoToGet[4];
                string wincolor = InfoToGet[5],titcolor = InfoToGet[6];
                DrawWindow(atoi(InfoToGet[0]),atoi(InfoToGet[1]),atoi(InfoToGet[2]),atoi(InfoToGet[3]),ReplaceText(wintit,'^',' '),wincolor,titcolor);
                sprintf(LocationsOfWindows[WinNum],"%i%s%i",atoi(InfoToGet[0]),"-",atoi(InfoToGet[1]));
                WinNum++;
            }
        }

        int TargetWinnum = 0;
        for(int i = 0;i < WinNum;i++)
        {
            if(Windows[i] == nwinobj)
            {
                TargetWinnum = i;
            }
        }

        char TmpXandY[2][500] = {'\0'};
        char TmpWandH[2][500] = {'\0'};

        SplitChar(LocationsOfWindows[TargetWinnum],'-',TmpXandY);
        SplitChar(SizesOfWindows[TargetWinnum],'-',TmpWandH);

        int x = atoi(TmpXandY[0]),y = atoi(TmpXandY[1]),w = atoi(TmpWandH[0]),h = atoi(TmpWandH[1]);

        while(mode == "MoveWindowByLocation")
        {
            WhiteScreen();
            CleanScreen();
            AroundBorder();
            DrawWindow(x,y,w,h,ReplaceText(wintit,'^',' '),wincolor,titcolor);
            DrawSideBtns(winsidebtns);
            ShowImage();
            cout<<"X:"<<x<<" Y:"<<y<<endl;
            NowLocation = "Type X and Y to Move The Window (x space y) >>>";
            cout<<NowLocation;
            int tx,ty;
            cin >> tx >> ty;
            if(Image[tx][ty] != '$')
            {
                x = tx;
                y = ty;
            }

            char WriteInfo[500] = {'\0'};
            sprintf(WriteInfo,"%s%i%s%i%s%i%s%i%s%s%s%s%s%s%s%s%s%s","NMainWin:",x,"-",y,"-",w,"-",h,"-",ReplaceText(wintit,' ','^').c_str(),"-",winsidebtns.c_str(),"-",wincolor.c_str(),"-",titcolor.c_str(),"-",Windows[TargetWinnum].c_str());
            //WinClassNum[TargetWinNum]
            Data[WinClassNum[TargetWinnum]][0] = '\0';
            for(int i = 0;i < strlen(WriteInfo);i++)
            {
                Data[WinClassNum[TargetWinnum]][i] = WriteInfo[i];
            }
            int nownum = 0;
            char ResultWrite[1000] = {'\0'};
            for(int i = 0;i < ItemsInCharNum(Command,'#');i++)
            {
                for(int j = 0;j < strlen(Data[i]);j++)
                {
                    ResultWrite[nownum] = Data[i][j];
                    nownum++;
                }
                if(i != ItemsInCharNum(Command,'#')-1)
                {
                    ResultWrite[nownum] = '#';
                    nownum++;
                }
            }
            string ResultWriteS = ResultWrite;
            NWrite(PathS,ResultWriteS);
            break;
        }
        while(mode == "MoveWindow")
        {
            WhiteScreen();
            CleanScreen();
            AroundBorder();
            DrawWindow(x,y,w,h,ReplaceText(wintit,'^',' '),wincolor,titcolor);
            DrawSideBtns(winsidebtns);
            ShowImage();
            cout<<"X:"<<x<<" Y:"<<y<<endl;
            NowLocation = "MoveWindow By Using W,A,S,D >>>";
            cout<<NowLocation;
            char way;
            cin >> way;
            if(way == 'W' || way == 'w')
            {
                if(Image[x][y] != '$')
                {
                    x--;
                }
            }
            if(way == 'S' || way == 's')
            {
                x++;
            }
            if(way == 'A' || way == 'a')
            {
                if(Image[x][y] != '$')
                {
                    y--;
                }
            }
            if(way == 'D' || way == 'd')
            {
                y++;
            }
            if(way == 'Y' || way == 'y')
            {
                char WriteInfo[500] = {'\0'};
                sprintf(WriteInfo,"%s%i%s%i%s%i%s%i%s%s%s%s%s%s%s%s%s%s","NMainWin:",x,"-",y,"-",w,"-",h,"-",ReplaceText(wintit,' ','^').c_str(),"-",winsidebtns.c_str(),"-",wincolor.c_str(),"-",titcolor.c_str(),"-",Windows[TargetWinnum].c_str());
                //WinClassNum[TargetWinNum]
                Data[WinClassNum[TargetWinnum]][0] = '\0';
                for(int i = 0;i < strlen(WriteInfo);i++)
                {
                    Data[WinClassNum[TargetWinnum]][i] = WriteInfo[i];
                }
                int nownum = 0;
                char ResultWrite[1000] = {'\0'};
                for(int i = 0;i < ItemsInCharNum(Command,'#');i++)
                {
                    for(int j = 0;j < strlen(Data[i]);j++)
                    {
                        ResultWrite[nownum] = Data[i][j];
                        nownum++;
                    }
                    if(i != ItemsInCharNum(Command,'#')-1)
                    {
                        ResultWrite[nownum] = '#';
                        nownum++;
                    }
                }
                string ResultWriteS = ResultWrite;
                NWrite(PathS,ResultWriteS);
                break;
            }
        }
    }
    //最常用的模式,配置软件界面
    if(mode == "ConfigureApp")
    {
        //Program Data
        int winx = 0,winy = 0,winw = 0,winh = 0;
        string wintit,winsidebtns,wincolor,wintitcolor;
        string Windows[50] = {""};
        int WinNum = 0;
        char LocationsOfWindows[50][11] = {'\0'};
        char SizesOfWindows[50][11] = {'\0'};
        string WinMode;

        for(int z = 0;z < ItemsInCharNum(Command,'#');z++)
        {
            char ObjAndInfo[2][500] = {'\0'};
            char InfoToGet[500][500] = {'\0'};
            char XandY[2][500] = {'\0'};
            char WandH[2][500] = {'\0'};

            SplitChar(Data[z],':',ObjAndInfo);

            string ClassName = ObjAndInfo[0];

            SplitChar(ObjAndInfo[1],'-',InfoToGet);

            if(ClassName == "NMainWin" || ClassName == "NMainWindow")
            {
                WinMode = InfoToGet[0];

                if(WinMode != "FULLSCREEN")
                {
                    winx = atoi(InfoToGet[0]);
                    winy = atoi(InfoToGet[1]);
                    winw = atoi(InfoToGet[2]);
                    winh = atoi(InfoToGet[3]);
                    wintit = InfoToGet[4];
                    wintit = ReplaceText(wintit,'^',' ');
                    winsidebtns = InfoToGet[5];
                    string wincolor,titcolor;
                    wincolor = InfoToGet[6];
                    titcolor = InfoToGet[7];
                    Windows[WinNum] = InfoToGet[8];
                    sprintf(LocationsOfWindows[WinNum],"%i%s%i",winx,"-",winy);
                    sprintf(SizesOfWindows[WinNum],"%i%s%i",winw,"-",winh);
                    DrawWindow(winx,winy,winw,winh,wintit,wincolor,titcolor);
                    DrawSideBtns(winsidebtns);
                    WinNum++;
                }
                else
                {
                    Windows[WinNum] = InfoToGet[2];
                    winx = 0;
                    winy = 0;
                    winw = 100;
                    winh = 40;
                    sprintf(LocationsOfWindows[WinNum],"%i%s%i",winx,"-",winy);
                    sprintf(SizesOfWindows[WinNum],"%i%s%i",winw,"-",winh);
                    winsidebtns = InfoToGet[1];
                    DrawSideBtns(winsidebtns);
                }
            }
            if(ClassName == "NWin" || ClassName == "NWindow")
            {
                Windows[WinNum] = InfoToGet[7];
                string title = InfoToGet[4];
                string wincolor = InfoToGet[5],titcolor = InfoToGet[6];
                DrawWindow(atoi(InfoToGet[0]),atoi(InfoToGet[1]),atoi(InfoToGet[2]),atoi(InfoToGet[3]),title,wincolor,titcolor);
                sprintf(LocationsOfWindows[WinNum],"%i%s%i",atoi(InfoToGet[0]),"-",atoi(InfoToGet[1]));
                WinNum++;
            }
            if(ClassName == "CircleSquare" || ClassName == "CESE")
            {
                string pointto = InfoToGet[5];
                string color = InfoToGet[4];
                int TargetWinnum;
                for(int i = 0;i <= WinNum;i++)
                {
                    if(Windows[i] == pointto)
                    {
                        TargetWinnum = i;
                    }
                }
                SplitChar(LocationsOfWindows[TargetWinnum],'-',XandY);
                DrawCircleSquare(atoi(XandY[0]) + atoi(InfoToGet[0]),atoi(XandY[1]) + atoi(InfoToGet[1]),atoi(InfoToGet[2]),atoi(InfoToGet[3]),color);
            }
            if(ClassName == "MiddleFillTextWithoutWindowsData" || ClassName == "MFWWD")
            {
                string title = InfoToGet[4],color = InfoToGet[5];
                MiddleFillText(atoi(InfoToGet[0]),atoi(InfoToGet[1]),atoi(InfoToGet[2]),ReplaceText(ExchangeHDCsData(title),'^',' '),color);
            }
            if(ClassName == "MFTXT" || ClassName == "MiddleFillText")
            {
                string title = InfoToGet[1],color = InfoToGet[2];
                //x-title-color-PointToWindow
                string pointto = InfoToGet[3];
                int TargetWinnum;
                for(int i = 0;i <= WinNum;i++)
                {
                    if(Windows[i] == pointto)
                    {
                        TargetWinnum = i;
                    }
                }
                SplitChar(SizesOfWindows[TargetWinnum],'-',WandH);
                SplitChar(LocationsOfWindows[TargetWinnum],'-',XandY);
                MiddleFillText(atoi(InfoToGet[0])+atoi(XandY[0]),atoi(WandH[0]),atoi(XandY[1]),ReplaceText(ExchangeHDCsData(title),'^',' '),color);
            }
            if(ClassName == "DrawLines" || ClassName == "DWLS")
            {
                string pointto = InfoToGet[4];
                int TargetWinnum;
                for(int i = 0;i <= WinNum;i++)
                {
                    if(Windows[i] == pointto)
                    {
                        TargetWinnum = i;
                    }
                }
                SplitChar(LocationsOfWindows[TargetWinnum],'-',XandY);
                string color = InfoToGet[5];
                DrawLines(atoi(InfoToGet[0]) + atoi(XandY[0]),atoi(InfoToGet[1]) + atoi(XandY[1]),atoi(InfoToGet[2]) + atoi(XandY[0]),atoi(InfoToGet[3]) + atoi(XandY[1]),InfoToGet[4][0],color);
            }
            if(ClassName == "FTXT" || ClassName == "FillText")
            {
                string pointto = InfoToGet[4];
                int TargetWinnum;
                for(int i = 0;i <= WinNum;i++)
                {
                    if(Windows[i] == pointto)
                    {
                        TargetWinnum = i;
                    }
                }
                SplitChar(LocationsOfWindows[TargetWinnum],'-',XandY);
                string title = InfoToGet[2],color = InfoToGet[3];
                FillText(atoi(InfoToGet[0]) + atoi(XandY[0]),atoi(InfoToGet[1]) + atoi(XandY[1]),ReplaceText(ExchangeHDCsData(title),'^',' '),color);
            }
            if(ClassName == "NBtn" || ClassName == "NButton")
            {
                int x = atoi(InfoToGet[0]),y = atoi(InfoToGet[1]),w = atoi(InfoToGet[2]),h = atoi(InfoToGet[3]);
                string title = InfoToGet[4];
                string btncolor = InfoToGet[5],titcolor = InfoToGet[6];
                string pointto = InfoToGet[7];
                int TargetWinnum;
                for(int i = 0;i <= WinNum;i++)
                {
                    if(Windows[i] == pointto)
                    {
                        TargetWinnum = i;
                    }
                }
                SplitChar(LocationsOfWindows[TargetWinnum],'-',XandY);
                DrawBtn(x + atoi(XandY[0]),y + atoi(XandY[1]),w,h,ReplaceText(title,'^',' '),btncolor,titcolor);
            }
        }
    }
    if(mode == "CreateView")
    {
        //Special Data Progress
        string CommandS = NRead(appname);
        strcpy(Command,CommandS.c_str());
        SplitChar(Command,'#',Data);
        //Application common files
        int winx = 0,winy = 0,winw = 0,winh = 0;
        string wintit,winsidebtns;
        string Windows[50] = {""};
        char LocationsOfWindows[50][11] = {'\0'};
        char SizesOfWindows[50][11] = {'\0'};
        int WinNum = 0;
        string WinMode;

        for(int z = 0;z < ItemsInCharNum(Command,'#');z++)
        {
            char ObjAndInfo[2][500] = {'\0'};
            char InfoToGet[500][500] = {'\0'};
            char XandY[2][500] = {'\0'};
            char WandH[2][500] = {'\0'};

            SplitChar(Data[z],':',ObjAndInfo);

            string ClassName = ObjAndInfo[0];

            SplitChar(ObjAndInfo[1],'-',InfoToGet);

            if(ClassName == "NWin" || ClassName == "NWindow")
            {
                Windows[WinNum] = InfoToGet[7];
                string title = InfoToGet[4];
                string wincolor = InfoToGet[5],titcolor = InfoToGet[6];
                DrawWindow(atoi(InfoToGet[0]),atoi(InfoToGet[1]),atoi(InfoToGet[2]),atoi(InfoToGet[3]),title,wincolor,titcolor);
                sprintf(LocationsOfWindows[WinNum],"%i%s%i",atoi(InfoToGet[0]),"-",atoi(InfoToGet[1]));
                WinNum++;
            }
            if(ClassName == "NMainWin" || ClassName == "NMainWindow")
            {
                WinMode = InfoToGet[0];

                if(WinMode != "FULLSCREEN")
                {
                    winx = atoi(InfoToGet[0]);
                    winy = atoi(InfoToGet[1]);
                    winw = atoi(InfoToGet[2]);
                    winh = atoi(InfoToGet[3]);
                    wintit = InfoToGet[4];
                    wintit = ReplaceText(wintit,'^',' ');
                    winsidebtns = InfoToGet[5];
                    string wincolor,titcolor;
                    wincolor = InfoToGet[6];
                    titcolor = InfoToGet[7];
                    Windows[WinNum] = InfoToGet[8];
                    sprintf(LocationsOfWindows[WinNum],"%i%s%i",winx,"-",winy);
                    sprintf(SizesOfWindows[WinNum],"%i%s%i",winw,"-",winh);
                    DrawWindow(winx,winy,winw,winh,wintit,wincolor,titcolor);
                    DrawSideBtns(winsidebtns);
                    WinNum++;
                }
                else
                {
                    Windows[WinNum] = InfoToGet[2];
                    winx = 0;
                    winy = 0;
                    winw = 100;
                    winh = 40;
                    sprintf(LocationsOfWindows[WinNum],"%i%s%i",winx,"-",winy);
                    sprintf(SizesOfWindows[WinNum],"%i%s%i",winw,"-",winh);
                    winsidebtns = InfoToGet[1];
                    DrawSideBtns(winsidebtns);
                }
            }
            if(ClassName == "MFTXT" || ClassName == "MiddleFillText")
            {
                string title = InfoToGet[1],color = InfoToGet[2];
                //x-title-color-PointToWindow
                string pointto = InfoToGet[3];
                int TargetWinnum;
                for(int i = 0;i <= WinNum;i++)
                {
                    if(Windows[i] == pointto)
                    {
                        TargetWinnum = i;
                    }
                }
                SplitChar(SizesOfWindows[TargetWinnum],'-',WandH);
                SplitChar(LocationsOfWindows[TargetWinnum],'-',XandY);
                MiddleFillText(atoi(InfoToGet[0]) + atoi(XandY[0]),atoi(WandH[0]),atoi(XandY[1]),ReplaceText(ExchangeHDCsData(title),'^',' '),color);
            }
            if(ClassName == "CircleSquare" || ClassName == "CESE")
            {
                string pointto = InfoToGet[5];
                string color = InfoToGet[4];
                int TargetWinnum;
                for(int i = 0;i <= WinNum;i++)
                {
                    if(Windows[i] == pointto)
                    {
                        TargetWinnum = i;
                    }
                }
                SplitChar(LocationsOfWindows[TargetWinnum],'-',XandY);
                DrawCircleSquare(atoi(XandY[0]) + atoi(InfoToGet[0]),atoi(XandY[1]) + atoi(InfoToGet[1]),atoi(InfoToGet[2]),atoi(InfoToGet[3]),color);
            }
            if(ClassName == "DrawLines" || ClassName == "DWLS")
            {
                string pointto = InfoToGet[4];
                int TargetWinnum;
                for(int i = 0;i <= WinNum;i++)
                {
                    if(Windows[i] == pointto)
                    {
                        TargetWinnum = i;
                    }
                }
                SplitChar(LocationsOfWindows[TargetWinnum],'-',XandY);
                string color = InfoToGet[5];
                DrawLines(atoi(InfoToGet[0]) + atoi(XandY[0]),atoi(InfoToGet[1]) + atoi(XandY[1]),atoi(InfoToGet[2]) + atoi(XandY[0]),atoi(InfoToGet[3]) + atoi(XandY[1]),InfoToGet[4][0],color);
            }
            if(ClassName == "FTXT" || ClassName == "FillText")
            {
                string pointto = InfoToGet[4];
                int TargetWinnum;
                for(int i = 0;i <= WinNum;i++)
                {
                    if(Windows[i] == pointto)
                    {
                        TargetWinnum = i;
                    }
                }
                SplitChar(LocationsOfWindows[TargetWinnum],'-',XandY);
                string title = InfoToGet[2],color = InfoToGet[3];
                FillText(atoi(InfoToGet[0]),atoi(InfoToGet[1]),ReplaceText(ExchangeHDCsData(title),'^',' '),color);
            }
            if(ClassName == "NBtn" || ClassName == "NButton")
            {
                int x = atoi(InfoToGet[0]),y = atoi(InfoToGet[1]),w = atoi(InfoToGet[2]),h = atoi(InfoToGet[3]);
                string title = InfoToGet[4];
                string btncolor = InfoToGet[5],titcolor = InfoToGet[6];
                string pointto = InfoToGet[7];
                int TargetWinnum;
                for(int i = 0;i <= WinNum;i++)
                {
                    if(Windows[i] == pointto)
                    {
                        TargetWinnum = i;
                    }
                }
                SplitChar(LocationsOfWindows[TargetWinnum],'-',XandY);
                DrawBtn(x + atoi(XandY[0]),y + atoi(XandY[1]),w,h,ReplaceText(title,'^',' '),btncolor,titcolor);
            }
        }
    }
}

void RunApp(string appname)
{
    if(appname == "Desktop-Pattern")
    {
        while(true)
        {
            DesktopWorks();
            PaperFramework("Desktop-Special","ConfigureApp","NONE");
            PaperFramework("Desktop-Pattern","ConfigureApp","NONE");
            ShowImage();
            NowLocation = "Desktop-Pattern >>>";
            cout << NowLocation;
            string in;
            cin >> in;
            if(in == "movewindow" || in == "MOVEWINDOW")
            {
                PaperFramework("Desktop-Pattern","MoveWindow","MainWin");
            }
            if(in == "MWBL" || in == "MOVEWINDOWBYLOCATION")
            {
                PaperFramework("Desktop-Pattern","MoveWindowByLocation","MainWin");
            }
            if(in == "#q" || in == "#Q" || in == "quit" || in == "QUIT")
            {
                break;
            }
            if(in == "#c" || in == "#C" || in == "CLEANSCREEN" || in == "cleanscreen")
            {
                CleanScreen();
            }
            if(in == "in" || in == "IN")
            {
                while(true)
                {
                    DesktopWorks();
                    PaperFramework("Desktop-Special","ConfigureApp","NONE");
                    PaperFramework("Desktop-Pattern","ConfigureApp","NONE");
                    ShowImage();
                    NowLocation = "Make Desktop Patterns >>>";
                    cout << "Tips: Don't type SPACE in the text, you can type ^ to replace the space. And you must type 7 characters to set the new pattern!" << endl;
                    cout << NowLocation;
                    string in;
                    cin >> in;
                    if(StringLength(in) != 7)
                    {
                        CleanScreen();
                        NMessageBox(1,1,"Desktop","Desktop Pattern File Must Be Lager Than 7 Digits! Please Reset Again!","33","32","31");
                        ShowImage();
                        sleep(2);
                    }
                    else
                    {
                        NWrite("Data/Users/" + Lib.User_username + "/Desktop/Pattern.dpi","Customize:" +  in);
                        break;
                    }
                }
            }
        }
    }
    if(appname == "Desktop-Special")
    {
        while(true)
        {
            DesktopWorks();
            PaperFramework("Desktop-Special","ConfigureApp","NONE");
            ShowImage();
            NowLocation = "Desktop-Special >>>";
            cout << NowLocation;
            string in;
            cin >> in;
            if(in == "1")
            {
                RunApp("Desktop-Pattern");
            }
            if(in == "movewindow" || in == "MOVEWINDOW")
            {
                PaperFramework("Desktop-Special","MoveWindow","MainWin");
            }
            if(in == "MWBL" || in == "MOVEWINDOWBYLOCATION")
            {
                PaperFramework("Desktop-Special","MoveWindowByLocation","MainWin");
            }
            if(in == "#q" || in == "#Q" || in == "quit" || in == "QUIT")
            {
                break;
            }
            if(in == "#c" || in == "#C" || in == "CLEANSCREEN" || in == "cleanscreen")
            {
                CleanScreen();
            }
        }
    }
    if(appname == "Security")
    {
        while(true)
        {
            DesktopWorks();
            PaperFramework("Settings","ConfigureApp","NONE");
            PaperFramework("Security","ConfigureApp","NONE");
            ShowImage();
            NowLocation = "Security >>>";
            cout << NowLocation;
            string in;
            cin >> in;
            if(in == "1")
            {
                bool is_old_password_correct = false;
                while(true)
                {
                    DesktopWorks();
                    PaperFramework("Settings","ConfigureApp","NONE");
                    PaperFramework("Security","ConfigureApp","NONE");
                    PaperFramework("Change Password","ConfigureApp","NONE");
                    ShowImage();
                    NowLocation = "Change Password >>>";
                    cout << NowLocation;
                    string in;
                    cin >> in;
                    if(in == "IN" || in == "in")
                    {
                        while(is_old_password_correct == false)
                        {
                            DesktopWorks();
                            PaperFramework("Settings","ConfigureApp","NONE");
                            PaperFramework("Security","ConfigureApp","NONE");
                            PaperFramework("Change Password","ConfigureApp","NONE");
                            ShowImage();
                            NowLocation = "Type Old Password >>>";
                            cout << NowLocation;
                            string in;
                            cin >> in;
                            if(in == Lib.User_password)
                            {
                                CleanScreen();
                                NMessageBox(5,15,"Security","Your Password Is Correct! Now You Can Set The New Password!","33","32","31");
                                ShowImage();
                                sleep(2);
                                is_old_password_correct = true;
                                break;
                            }
                            else
                            {
                                CleanScreen();
                                NMessageBox(5,15,"Security","Your Password Is Wrong! Please Try Again!","33","32","31");
                                ShowImage();
                                sleep(2);
                            }
                        }
                        while(is_old_password_correct == true)
                        {
                            DesktopWorks();
                            PaperFramework("Settings","ConfigureApp","NONE");
                            PaperFramework("Security","ConfigureApp","NONE");
                            PaperFramework("Change Password","ConfigureApp","NONE");
                            ShowImage();
                            NowLocation = "Type New Password >>>";
                            cout << NowLocation;
                            string in;
                            cin >> in;
                            if(StringLength(in) < 4)
                            {
                                CleanScreen();
                                NMessageBox(5,15,"Security","Password Must Be Larger Than 4 Digits! Please Try Again!","33","32","31");
                                ShowImage();
                                sleep(2);
                            }
                            else
                            {
                                CleanScreen();
                                NMessageBox(5,15,"Security","Congratulations! New Password Now Avilable!","33","32","31");
                                ShowImage();
                                sleep(2);

                                //Progresses
                                NWrite("Data/Users/" + Lib.User_username + "/UserInfo.nsf",in + "-" + Lib.User_password_tip);

                                break;
                            }
                        }
                    }
                    if(in == "#q" || in == "#Q" || in == "quit" || in == "QUIT")
                    {
                        break;
                    }
                    if(in == "#c" || in == "#C" || in == "cleanscreen" || in == "CLEANSCREEN")
                    {
                        CleanScreen();
                    }
                    if(in == "movewindow" || in == "MOVEWINDOW")
                    {
                        PaperFramework("Change Password","MoveWindow","MainWin");
                    }
                    if(in == "MWBL" || in == "MOVEWINDOWBYLOCATION")
                    {
                        PaperFramework("Change Password","MoveWindowByLocation","MainWin");
                    }
                }
            }
            if(in == "2")
            {
                while(true)
                {
                    DesktopWorks();
                    PaperFramework("Settings","ConfigureApp","NONE");
                    PaperFramework("Security","ConfigureApp","NONE");
                    PaperFramework("Change Password Tip","ConfigureApp","NONE");
                    ShowImage();
                    NowLocation = "Change Password Tip >>>";
                    cout << NowLocation;
                    string in;
                    cin >> in;
                    if(in == "in" || in == "IN")
                    {
                        while(true)
                        {
                            DesktopWorks();
                            PaperFramework("Settings","ConfigureApp","NONE");
                            PaperFramework("Security","ConfigureApp","NONE");
                            PaperFramework("Change Password","ConfigureApp","NONE");
                            ShowImage();
                            NowLocation = "Set New Password Tip >>>";
                            cout << NowLocation;
                            string in;
                            cin >> in;

                            Lib.User_password_tip = in;
                            NWrite("Data/Users/" + Lib.User_username + "/UserInfo.nsf",Lib.User_password + "-" + in);

                            CleanScreen();
                            NMessageBox(5,15,"Security","Congratulations! New Password Tip Now Avilable!","33","32","31");
                            ShowImage();
                            sleep(2);

                            break;
                        }
                    }
                    if(in == "#q" || in == "#Q" || in == "quit" || in == "QUIT")
                    {
                        break;
                    }
                    if(in == "#c" || in == "#C" || in == "cleanscreen" || in == "CLEANSCREEN")
                    {
                        CleanScreen();
                    }
                    if(in == "movewindow" || in == "MOVEWINDOW")
                    {
                        PaperFramework("Change Password Tip","MoveWindow","MainWin");
                    }
                    if(in == "MWBL" || in == "MOVEWINDOWBYLOCATION")
                    {
                        PaperFramework("Change Password Tip","MoveWindowByLocation","MainWin");
                    }
                }
            }
            if(in == "#q" || in == "#Q" || in == "quit" || in == "QUIT")
            {
                break;
            }
            if(in == "#c" || in == "#C" || in == "cleanscreen" || in == "CLEANSCREEN")
            {
                CleanScreen();
            }
            if(in == "movewindow" || in == "MOVEWINDOW")
            {
                PaperFramework("About","MoveWindow","AboutNMainWindow");
            }
            if(in == "MWBL" || in == "MOVEWINDOWBYLOCATION")
            {
                PaperFramework("About","MoveWindowByLocation","AboutNMainWindow");
            }
        }
    }
    if(appname == "Recovery")
    {
        while(true)
        {
            DesktopWorks();
            PaperFramework("Settings","ConfigureApp","NONE");
            PaperFramework("Recovery","ConfigureApp","NONE");
            ShowImage();
            NowLocation = "Recovery >>>";
            cout << NowLocation;
            string in;
            cin >> in;
            if(in == "1")
            {
                while(true)
                {
                    DesktopWorks();
                    PaperFramework("Settings","ConfigureApp","NONE");
                    PaperFramework("Recovery","ConfigureApp","NONE");
                    PaperFramework("Data/Apps/Recovery/Graphics/Reset.txt","CreateView","NONE");
                    ShowImage();
                    NowLocation = "Reset The OS >>>";
                    cout << NowLocation;
                    string in;
                    cin >> in;
                    if(in == "IN" || in == "in")
                    {
                        while(true)
                        {
                            DesktopWorks();
                            PaperFramework("Settings","ConfigureApp","NONE");
                            PaperFramework("Recovery","ConfigureApp","NONE");
                            PaperFramework("Data/Apps/Recovery/Graphics/Reset.txt","CreateView","NONE");
                            ShowImage();
                            NowLocation = "Input Password >>>";
                            cout << NowLocation;
                            string in;
                            cin >> in;
                            if(in == Lib.User_password)
                            {
                                CleanScreen();
                                NMessageBox(5,15,"Security","Your Password Is Right, Now Into The Recovery Mode!","33","32","31");
                                ShowImage();
                                NWrite("System/OS/Start.nsf","Recovery");
                                NWrite("Recovery/Rec.nsf","ResetTheOS");
                                ReBoot();
                            }
                        }
                    }
                    if(in == "#q" || in == "#Q")
                    {
                        break;
                    }
                    if(in == "movewindow" || in == "MOVEWINDOW")
                    {
                        PaperFramework("Data/Apps/Recovery/Graphics/Reset.txt","MoveWindowWithPath","MainWin");
                    }
                    if(in == "MWBL" || in == "MOVEWINDOWBYLOCATION")
                    {
                        PaperFramework("Data/Apps/Recovery/Graphics/Reset.txt","MoveWindowByLocationWithPath","MainWin");
                    }
                    if(in == "#c" || in == "#C" || in == "cleanscreen" || in == "CLEANSCREEN")
                    {
                        CleanScreen();
                    }
                }
            }
            if(in == "movewindow" || in == "MOVEWINDOW")
            {
                PaperFramework("Recovery","MoveWindow","MainWin");
            }
            if(in == "MWBL" || in == "MOVEWINDOWBYLOCATION")
            {
                PaperFramework("Recoverys","MoveWindowByLocation","MainWin");
            }
            if(in == "#c" || in == "#C" || in == "cleanscreen" || in == "CLEANSCREEN")
            {
                CleanScreen();
            }
            if(in == "#q" || in == "#Q" || in == "quit" || in == "QUIT")
            {
                break;
            }
        }
    }
    if(appname == "Users")
    {
        int NowPage = 1;
        int EndPage = 1;
        while(true)
        {
            DesktopWorks();
            PaperFramework("Settings","ConfigureApp","NONE");
            PaperFramework("Users","ConfigureApp","NONE");
            //Draw Users' list
            string UsersS = NRead("Data/Users/UserInfo.nsf");
            char Users[10000] = {'\0'};
            strcpy(Users,UsersS.c_str());
            char UsersList[500][500] = {'\0'};
            SplitChar(Users,'-',UsersList);
            EndPage = ItemsInCharNum(Users,'-') / 5 + 1;
            if(ItemsInCharNum(Users,'-') <= 5)  EndPage = 1;
            for(int i = 0;i < 5;i++)
            {
                MiddleFillText(GetWinInfo("Data/Apps/Users/Graphics/Command.txt","WinX","MainWin") + i*2 + 7,GetWinInfo("Data/Apps/Users/Graphics/Command.txt","WinW","MainWin"),GetWinInfo("Data/Apps/Users/Graphics/Command.txt","WinY","MainWin"),UsersList[(NowPage-1)*5 + i],"37");
                FillText(GetWinInfo("Data/Apps/users/Graphics/Command.txt","WinX","MainWin") + i*2 + 7,GetWinInfo("Data/Apps/Users/Graphics/Command.txt","WinY","MainWin")+3,IntToString(i+1),"30");
                MiddleFillText(GetWinInfo("Data/Apps/Users/Graphics/Command.txt","WinX","MainWin") + i*2+1 + 7,GetWinInfo("Data/Apps/Users/Graphics/Command.txt","WinW","MainWin"),GetWinInfo("Data/Apps/Users/Graphics/Command.txt","WinY","MainWin"),"___________________________________________________","33");
            }
            //Middle text
            string IntPack[2];
            IntPack[0] = IntToString(NowPage);
            IntPack[1] = IntToString(EndPage);
            MiddleFillText(19 + GetWinInfo("Data/Apps/Users/Graphics/Command.txt","WinX","MainWin"),GetWinInfo("Data/Apps/Users/Graphics/Command.txt","WinW","MainWin"),GetWinInfo("Data/Apps/Users/Graphics/Command.txt","WinY","MainWin"),"Now you're at " + IntPack[0] + " / " + IntPack[1] + " Page.","35");
            ShowImage();
            NowLocation = "Users >>>";
            cout << NowLocation;
            string in;
            cin >> in;
            if(in == "<" && NowPage > 1)
            {
                NowPage--;
            }
            else if(in == ">" && NowPage <= EndPage)
            {
                NowPage++;
            }
            else if(in == "ADD" || in == "add")
            {
                while(true)
                {
                    CleanScreen();
                    ShowImage();
                    NowLocation = "Add Users >>>";
                    cout << NowLocation;
                    string in;
                    cin >> in;
                    UsersS = UsersS + "-" + in;
                    NWrite("Data/Users/UserInfo.nsf",UsersS);

                    while(true)
                    {
                        DesktopWorks();
                        PaperFramework("Settings","ConfigureApp","NONE");
                        PaperFramework("Users","ConfigureApp","NONE");
                        //Draw Users' list
                        string UsersS = NRead("Data/Users/UserInfo.nsf");
                        char Users[10000] = {'\0'};
                        strcpy(Users,UsersS.c_str());
                        char UsersList[500][500] = {'\0'};
                        SplitChar(Users,'-',UsersList);
                        EndPage = ItemsInCharNum(Users,'-') / 5 + 1;
                        if(ItemsInCharNum(Users,'-') <= 5)  EndPage = 1;
                        for(int i = 0;i < 5;i++)
                        {
                            MiddleFillText(GetWinInfo("Data/Apps/Users/Graphics/Command.txt","WinX","MainWin") + i*2 + 7,GetWinInfo("Data/Apps/Users/Graphics/Command.txt","WinW","MainWin"),GetWinInfo("Data/Apps/Users/Graphics/Command.txt","WinY","MainWin"),UsersList[(NowPage-1)*5 + i],"37");
                            FillText(GetWinInfo("Data/Apps/users/Graphics/Command.txt","WinX","MainWin") + i*2 + 7,GetWinInfo("Data/Apps/Users/Graphics/Command.txt","WinY","MainWin")+3,IntToString(i+1),"30");
                            MiddleFillText(GetWinInfo("Data/Apps/Users/Graphics/Command.txt","WinX","MainWin") + i*2+1 + 7,GetWinInfo("Data/Apps/Users/Graphics/Command.txt","WinW","MainWin"),GetWinInfo("Data/Apps/Users/Graphics/Command.txt","WinY","MainWin"),"___________________________________________________","33");
                        }
                        //Middle text
                        string IntPack[2];
                        IntPack[0] = IntToString(NowPage);
                        IntPack[1] = IntToString(EndPage);
                        MiddleFillText(19 + GetWinInfo("Data/Apps/Users/Graphics/Command.txt","WinX","MainWin"),GetWinInfo("Data/Apps/Users/Graphics/Command.txt","WinW","MainWin"),GetWinInfo("Data/Apps/Users/Graphics/Command.txt","WinY","MainWin"),"Now you're at " + IntPack[0] + " / " + IntPack[1] + " Page.","35");
                        ShowImage();
                        NowLocation = "New Password + (SPACE) + New Password Tip / NONE >>>";
                        cout << NowLocation;
                        string inp,inti;
                        cin >> inp >> inti;
                        if(StringLength(inp) < 4)
                        {
                            CleanScreen();
                            NMessageBox(5,15,"Security","Password must bigger that 4 digits!","33","32","31");
                            ShowImage();
                            sleep(2);
                        }
                        else
                        {
                            string CommandS = "mkdir Data/Users/" + in;
                            char Command[300] = {'\0'};
                            strcpy(Command,CommandS.c_str());
                            system(Command);
                            CommandS = "mkdir Data/Users/" + in + "/Desktop Data/Users/" + in + "/Documents";
                            strcpy(Command,CommandS.c_str());
                            system(Command);
                            CommandS = "touch Data/Users/" + in + "/UserInfo.nsf";
                            strcpy(Command,CommandS.c_str());
                            system(Command);
                            NWrite("Data/Users/" + in + "/UserInfo.nsf",inp + "-" + inti);
                            sprintf(Command,"%s%s%s","touch Data/Users/",in.c_str(),"/Desktop/Info.di");
                            system(Command);
                            sprintf(Command,"%s%s%s","Data/Users/",in.c_str(),"/Desktop/Info.di");
                            CommandS = Command;
                            NWrite(CommandS,"Desktop=Settings~^*______^;*[______];^*^|^^|^^;^^^|^^|^^;^^^|^^|^^;^^^|__|^^~2;89~32#Desktop=NWrite~^_______^;/^^^^^_^\\;|----//-|;|---//--|;|--|/---|;\\_______/~11;89~35");
                            NWrite("Data/Users/" + in + "/Desktop/Pattern.dpi","Plain");
                        }
                    }   
                }
            }
            else if(in == "DELETE" || in == "delete")
            {
                while(true)
                {
                    CleanScreen();
                    ShowImage();
                    NowLocation = "Delete Users >>>";
                    cout << NowLocation;
                    int in;
                    cin >> in;
                    int GetNum = (NowPage-1) * 5 + in - 1;
                    char ResultUserList[500][500] = {'\0'};
                    int NowNum = 0;
                    for(int i = 0;i < ItemsInCharNum(Users,'-');i++)
                    {
                        for(int j = 0;j < strlen(UsersList[i]);j++)
                        {
                            if(i != GetNum)
                            {
                                ResultUserList[NowNum][j] = UsersList[i][j];
                            }
                        }
                        if(i != GetNum)
                        {
                            NowNum++;
                        }
                    }

                    //Put'em together
                    char ResultWrite[2000] = {'\0'};
                    NowNum = 0;
                    for(int i = 0;i < ItemsInCharNum(Users,'-')-1;i++)
                    {
                        for(int j = 0;j < strlen(ResultUserList[i]);j++)
                        {
                            ResultWrite[NowNum] = ResultUserList[i][j];
                            NowNum++;
                        }
                        ResultWrite[NowNum] = '-';
                        NowNum++;
                    }
                    ResultWrite[strlen(ResultWrite)-1] = '\0';

                    string ResultWriteS = ResultWrite;
                    NWrite("Data/Users/UserInfo.nsf",ResultWriteS);
                    char RCommand[] = {'\0'};
                    sprintf(RCommand,"%s%s","rm -r Data/Users/",UsersList[GetNum]);
                    system(RCommand);

                    RefreshData();

                    break;
                }
            }
            else if(in == "#q" || in == "#Q" || in == "quit" || in == "QUIT")
            {
                break;
            }
            else if(in == "movewindow" || in == "MOVEWINDOW")
            {
                PaperFramework("Users","MoveWindow","MainWin");
            }
            else if(in == "MWBL" || in == "MOVEWINDOWBYLOCATION")
            {
                PaperFramework("Users","MoveWindowByLocation","MainWin");
            }
            else if(in == "#c" || in == "#C" || in == "cleanscreen" || in == "CLEANSCREEN")
            {
                CleanScreen();
            }
        }
    }
    if(appname == "Settings")
    {
        while(true)
        {
            DesktopWorks();
            PaperFramework("Settings","ConfigureApp","NONE");
            ShowImage();
            NowLocation = "Settings >>>";
            cout << NowLocation;
            string in;
            cin >> in;
            if(in == "4")
            {
                RunApp("Users");
            }
            if(in == "3")
            {
                RunApp("Recovery");
            }
            if(in == "2")
            {
                RunApp("Security");
            }
            if(in == "1")
            {
                while(true)
                {
                    DesktopWorks();
                    PaperFramework("Settings","ConfigureApp","NONE");
                    PaperFramework("About","ConfigureApp","NONE");
                    ShowImage();
                    NowLocation = "Settings-About >>>";
                    cout << NowLocation;
                    string in;
                    cin >> in;
                    if(in == "#q" || in == "#Q" || in == "quit" || in == "QUIT")
                    {
                        break;
                    }
                    if(in == "#c" || in == "#C" || in == "cleanscreen" || in == "CLEANSCREEN")
                    {
                        CleanScreen();
                    }
                    if(in == "movewindow" || in == "MOVEWINDOW")
                    {
                        PaperFramework("About","MoveWindow","AboutNMainWindow");
                    }
                    if(in == "MWBL" || in == "MOVEWINDOWBYLOCATION")
                    {
                        PaperFramework("About","MoveWindowByLocation","AboutNMainWindow");
                    }
                }
            }
            if(in == "movewindow" || in == "MOVEWINDOW")
            {
                PaperFramework("Settings","MoveWindow","MainWin");
            }
            if(in == "MWBL" || in == "MOVEWINDOWBYLOCATION")
            {
                PaperFramework("Settings","MoveWindowByLocation","MainWin");
            }
            if(in == "#c" || in == "#C" || in == "cleanscreen" || in == "CLEANSCREEN")
            {
                CleanScreen();
            }
            if(in == "#q" || in == "#Q" || in == "quit" || in == "QUIT")
            {
                break;
            }
        }
    }
    if(appname == "NWrite")
    {
        string FileName = "untitled";

        while(true)
        {
            DesktopWorks();
            PaperFramework("NWrite","ConfigureApp","NONE");
            MiddleFillText(8+GetWinInfo("Data/Apps/NWrite/Graphics/Command.txt","WinX","MainWin"),GetWinInfo("Data/Apps/NWrite/Graphics/Command.txt","WinW","MainWin"),GetWinInfo("Data/Apps/NWrite/Graphics/Command.txt","WinY","MainWin"),FileName,"37");
            ShowImage();
            NowLocation = "NWrite >>>";
            cout << NowLocation;
            string in;
            cin >> in;
            if(in == "new" || in == "NEW")
            {
                while(true)
                {
                    DesktopWorks();
                    PaperFramework("NWrite","ConfigureApp","NONE");
                    MiddleFillText(8+GetWinInfo("Data/Apps/NWrite/Graphics/Command.txt","WinX","MainWin"),GetWinInfo("Data/Apps/NWrite/Graphics/Command.txt","WinW","MainWin"),GetWinInfo("Data/Apps/NWrite/Graphics/Command.txt","WinY","MainWin"),FileName,"37");
                    PaperFramework("Data/Apps/NWrite/Graphics/NewFileWindow.txt","CreatView","MainWin");
                    ShowImage();
                    NowLocation = "New NWrite Document >>>";
                    cout << NowLocation;
                    string in;
                    cin >> in;
                    if(in == "movewindow" || in == "MOVEWINDOW")
                    {
                        PaperFramework("Data/Apps/NWrite/Graphics/NewFileWindow.txt","MoveWindowWithPath","MainWin");
                    }
                    if(in == "MOVEWINDOWBYLOCATION" || in == "MWBL")
                    {
                        PaperFramework("Data/Apps/NWrite/Graphics/NewFileWindow.txt","MoveWindowByLocationWithPath","MainWin");
                    }
                    if(in == "#q" || in == "#Q" || in == "quit" || in == "QUIT")
                    {
                        break;
                    }
                    if(in == "#c" || in == "#C" || in == "cleanscreen" || in == "CLEANSCREEN")
                    {
                        CleanScreen();
                    }
                }
            }
            if(in == "open" || in == "OPEN")
            {

            }
            if(in == "movewindow" || in == "MOVEWINDOW")
            {
                PaperFramework("NWrite","MoveWindow","MainWin");
            }
            if(in == "MOVEWINDOWBYLOCATION" || in == "MWBL")
            {
                PaperFramework("NWrite","MoveWindowByLocation","MainWin");
            }
            if(in == "#q" || in == "#Q" || in == "quit" || in == "QUIT")
            {
                break;
            }
            if(in == "#c" || in == "#C" || in == "cleanscreen" || in == "CLEANSCREEN")
            {
                CleanScreen();
            }
        }
    }
    if(appname == "Desktop")
    {
        while(true)
        {
            DesktopWorks();
            DrawSideBtns("^Shutdown`^CleanScreen`^About`^Special");
            ShowImage();
            NowLocation = "Desktop >>>";
            cout << NowLocation;
            string in;
            cin >> in;
            if(in == "nwrite" || in == "NWRITE")
            {
                RunApp("NWrite");
            }
            if(in == "special" || in == "SPECIAL")
            {
                RunApp("Desktop-Special");
            }
            if(in == "settings" || in == "SETTINGS")
            {
                RunApp("Settings");
            }
            if(in == "about" || in == "ABOUT")
            {
                while(true)
                {
                    DesktopWorks();
                    DrawSideBtns("^Shutdown`^CleanScreen`^About`^Special");
                    PaperFramework("Desktop-About","ConfigureApp","NONE");
                    ShowImage();
                    NowLocation = "Desktop/About >>>";
                    cout << NowLocation;
                    string in;
                    cin >> in;
                    if(in == "movewindow" || in == "MOVEWINDOW")
                    {
                        PaperFramework("Desktop-About","MoveWindow","AD");
                    }
                    if(in == "MWBL" || in == "MOVEWINDOWBYLOCATION")
                    {
                        PaperFramework("Desktop-About","MoveWindowByLocation","AD");
                    }
                    if(in == "#c" || in == "#C" || in == "CLEANSCREEN" || in == "cleanscreen")
                    {
                        CleanScreen();
                    }
                    if(in == "#q" || in == "#Q" || in == "quit" || in == "QUIT")
                    {
                        break;
                    }
                }
            }
            if(in == "#c" || in == "#C" || in == "CLEANSCREEN" || in == "cleanscreen")
            {
                CleanScreen();
            }
            if(in == "#s" || in == "#S" || in == "shutdown" || in == "SHUTDOWN")
            {
                Shutdown();
            }
        }
    }
    if(appname == "Check Personal Info")
    {
        int PswdInTime = 5;
        RefreshData();

        while(true)
        {
            GUICommands();
            PaperFramework("Check Personal Info","ConfigureApp","NONE");
            ShowImage();
            NowLocation = "Check Personal Info >>>";
            cout << NowLocation;
            string in;
            cin >> in;
            if(in == "in" || in == "IN")
            {
                if(PswdInTime <= 0)
                {
                    GUICommands();
                    PaperFramework("Check Personal Info","ConfigureApp","NONE");
                    NMessageBox(5,15,"Log In","You don't have chance to type password!","33","32","31");
                    ShowImage();
                }
                while(PswdInTime > 0)
                {
                    GUICommands();
                    PaperFramework("Check Personal Info","ConfigureApp","NONE");
                    ShowImage();
                    cout << "You have "<<PswdInTime<<" chances!"<<endl;
                    NowLocation = "Type your password >>>";
                    cout << NowLocation;
                    string in;
                    cin >> in;
                    if(in == Lib.User_password)
                    {
                        CleanScreen();
                        NMessageBox(1,5,"Log In","Congratulations! Password is correct! Now in desktop!","33","32","31");
                        ShowImage();
                        sleep(2);
                        RunApp("Desktop");
                        break;
                    }
                    else
                    {
                        CleanScreen();
                        NMessageBox(1,5,"Log In","Password is wrong, try again!","33","32","31");
                        ShowImage();
                        sleep(2);
                        PswdInTime --;
                    }
                }
            }
            if(in == "about" || in == "ABOUT")
            {
                while(true)
                {
                    RefreshData();
                    GUICommands();
                    PaperFramework("Check Personal Info","ConfigureApp","NONE");
                    PaperFramework("About","ConfigureApp","NONE");
                    ShowImage();
                    NowLocation = "About >>>";
                    cout << NowLocation;
                    string in;
                    cin >> in;
                    if(in == "movewindow" || in == "MOVEWINDOW")
                    {
                        PaperFramework("About","MoveWindowWithPath","AboutNMainWindow");
                    }
                    if(in == "MWBL" || in == "MOVEWINDOWBYLOCATION")
                    {
                        PaperFramework("About","MoveWindowByLocationWithPath","AboutNMainWindow");
                    }
                    if(in == "#q" || in == "#Q" || in == "quit" || in == "QUIT")
                    {
                        break;
                    }
                    if(in == "#c" || in == "#C" || in == "cleanscreen" || in == "CLEANSCREEN")
                    {
                        CleanScreen();
                    }
                }
            }
            if(in == "switch" || in == "SWITCH")
            {
                int NowPage = 1;
                int EndPage = 1;
                while(true)
                {
                    RefreshData();
                    GUICommands();
                    PaperFramework("Check Personal Info","ConfigureApp","NONE");
                    PaperFramework("Data/Apps/Check Personal Info/Graphics/Switch.txt","CreateView","NONE");
                    //Draw Users' list
                    string UsersS = NRead("Data/Users/UserInfo.nsf");
                    char Users[10000] = {'\0'};
                    strcpy(Users,UsersS.c_str());
                    char UsersList[500][500] = {'\0'};
                    SplitChar(Users,'-',UsersList);
                    EndPage = ItemsInCharNum(Users,'-') / 5 + 1;
                    for(int i = 0;i < 5;i++)
                    {
                        MiddleFillText(GetWinInfo("Data/Apps/Check Personal Info/Graphics/Switch.txt","WinX","MainWin") + i*2 + 7,GetWinInfo("Data/Apps/Check Personal Info/Graphics/Switch.txt","WinW","MainWin"),GetWinInfo("Data/Apps/Check Personal Info/Graphics/Switch.txt","WinY","MainWin"),UsersList[(NowPage-1)*5 + i],"37");
                        FillText(GetWinInfo("Data/Apps/Check Personal Info/Graphics/Switch.txt","WinX","MainWin") + i*2 + 7,GetWinInfo("Data/Apps/Check Personal Info/Graphics/Switch.txt","WinY","MainWin")+3,IntToString(i+1),"30");
                        MiddleFillText(GetWinInfo("Data/Apps/Check Personal Info/Graphics/Switch.txt","WinX","MainWin") + i*2+1 + 7,GetWinInfo("Data/Apps/Check Personal Info/Graphics/Switch.txt","WinW","MainWin"),GetWinInfo("Data/Apps/Check Personal Info/Graphics/Switch.txt","WinY","MainWin"),"_________________________________________","33");
                    }
                    //Middle text
                    string IntPack[2];
                    IntPack[0] = IntToString(NowPage);
                    IntPack[1] = IntToString(EndPage);
                    MiddleFillText(19 + GetWinInfo("Data/Apps/Check Personal Info/Graphics/Switch.txt","WinX","MainWin"),GetWinInfo("Data/Apps/Check Personal Info/Graphics/Switch.txt","WinW","MainWin"),GetWinInfo("Data/Apps/Check Personal Info/Graphics/Switch.txt","WinY","MainWin"),"Now you're at " + IntPack[0] + " / " + IntPack[1] + " Page.","35");

                    ShowImage();
                    NowLocation = "Switch Users >>>";
                    cout << NowLocation;
                    string in;
                    cin >> in;
                    if(in == "<" && NowPage > 1)
                    {
                        NowPage--;
                    }
                    else if(in == ">" && NowPage <= EndPage)
                    {
                        NowPage++;
                    }
                    else if(in == "movewindow" || in == "MOVEWINDOW")
                    {
                        PaperFramework("Data/Apps/Check Personal Info/Graphics/Switch.txt","MoveWindowWithPath","MainWin");
                    }
                    else if(in == "MWBL" || in == "MOVEWINDOWBYLOCATION")
                    {
                        PaperFramework("Data/Apps/Check Personal Info/Graphics/Switch.txt","MoveWindowByLocationWithPath","MainWin");
                    }
                    else if(in == "#q" || in == "#Q" || in == "quit" || in == "QUIT")
                    {
                        break;
                    }
                    else if(in == "#c" || in == "#C" || in == "CLEANSCREEN" || in == "cleanscreen")
                    {
                        CleanScreen();
                    }
                    else
                    {
                        int TargetNum = atoi(in.c_str());
                        int UserNumber = (NowPage-1)*5+TargetNum-1;
                        Lib.User_username = UsersList[UserNumber];
                        NWrite("Data/Users/SelectUser.nsf",Lib.User_username);
                        RefreshData();
                        break;
                    }
                }
            }
            if(in == "#s" || in == "#S" || in == "shutdown" || in == "SHUTDOWN")
            {
                Shutdown();
            }
            if(in == "#c" || in == "#C" || in == "cleanscreen" || in == "CLEANSCREEN")
            {
                CleanScreen();
            }
        }
    }
    if(appname == "SetUp Your OS")
    {
        bool Is_Seted_Username = false,Is_Seted_Password = false;

        while(true)
        {
            if(Is_Seted_Username == true && Is_Seted_Password == true)
            {
                GUICommands();
                PaperFramework("Data/Apps/SetUp Your OS/Graphics/Tip.txt","CreateView","NONE");
                ShowImage();
                NowLocation = "Set New Password Tip >>>";
                cout << NowLocation;
                string in;
                cin >> in;
                if(in == "in" || in == "IN")
                {
                    while(true)
                    {
                        CleanScreen();
                        ShowImage();
                        NowLocation = "Type your new password tip >>>";
                        cout << NowLocation;
                        string inp;
                        cin >> inp;

                        Lib.User_password_tip = inp;

                        CleanScreen();
                        NMessageBox(5,15,"Secure","Congratulations, Password tip is setting completed! Next you can install your OS!","33","32","31");
                        ShowImage();
                        sleep(2);

                        break;
                    }
                }
                if(in == "install" || in == "INSTALL")
                {
                    while(true)
                    {
                        GUICommands();
                        NMessageBox(5,15,"NC OS","Just wait a minute... We are installing your OS...","33","32","31");
                        ShowImage();
                        
                        NWrite("Data/Users/UserInfo.nsf",Lib.User_username + "-root");
                        string CommandS = "mkdir Data/Users/" + Lib.User_username;
                        char Command[300] = {'\0'};
                        strcpy(Command,CommandS.c_str());
                        system(Command);
                        CommandS = "mkdir Data/Users/" + Lib.User_username + "/Desktop Data/Users/" + Lib.User_username + "/Documents";
                        strcpy(Command,CommandS.c_str());
                        system(Command);
                        CommandS = "touch Data/Users/" + Lib.User_username + "/UserInfo.nsf";
                        strcpy(Command,CommandS.c_str());
                        system(Command);
                        NWrite("Data/Users/" + Lib.User_username + "/UserInfo.nsf",Lib.User_password + "-" + Lib.User_password_tip);
                        NWrite("System/OS/Start.nsf","True");
                        sprintf(Command,"%s%s%s","touch Data/Users/",Lib.User_username.c_str(),"/Desktop/Info.di");
                        system(Command);
                        sprintf(Command,"%s%s%s","Data/Users/",Lib.User_username.c_str(),"/Desktop/Info.di");
                        CommandS = Command;
                        NWrite(CommandS,"Desktop=Settings~^*______^;*[______];^*^|^^|^^;^^^|^^|^^;^^^|^^|^^;^^^|__|^^~2;89~32#Desktop=NWrite~^_______^;/^^^^^_^\\;|----//-|;|---//--|;|--|/---|;\\_______/~11;89~35");
                        NWrite("Data/Users/SelectUser.nsf",Lib.User_username);
                        NWrite("Data/Users/" + Lib.User_username + "/Desktop/Pattern.dpi","Plain");

                        sleep(3);
                        ReBoot();
                    }
                }
                if(in == "#c" || in == "#C" || in == "CLEANSCREEN" || in == "cleanscreen")
                {
                    CleanScreen();
                }
                if(in == "#s" || in == "#S" || in == "shutdown" || in == "SHUTDOWN")
                {
                    Shutdown();
                }
            }
            if(Is_Seted_Password == false && Is_Seted_Username == false)
            {
                GUICommands();
                PaperFramework("SetUp Your OS","ConfigureApp","NONE");
                ShowImage();
                NowLocation = "Hello >>>";
                cout << NowLocation;
                string in;
                cin >> in;
                if(in == "next" || in == "NEXT")
                {
                    while(true)
                    {
                        GUICommands();
                        PaperFramework("Data/Apps/SetUp Your OS/Graphics/SetUsnm.txt","CreateView","NONE");
                        ShowImage();
                        NowLocation = "Set New Username >>>";
                        cout << NowLocation;
                        string in;
                        cin >> in;
                        if(in == "in" || in == "IN")
                        {
                            CleanScreen();
                            ShowImage();
                            NowLocation = "Type your new username >>>";
                            cout << NowLocation;
                            string inu;
                            cin >> inu;

                            Lib.User_username = inu;

                            CleanScreen();
                            NMessageBox(5,15,"Secure","Congratulations! Username is setting completed!","33","32","31");
                            ShowImage();
                            sleep(2);

                            Is_Seted_Username = true;
                        }
                        if(in == "OK" || in == "ok")
                        {
                            if(Is_Seted_Username == true)
                            {
                                break;
                            }
                        }
                        if(in == "#s" || in == "#S" || in == "shutdown" || in == "SHUTDOWN")
                        {
                            break;
                        }
                        if(in == "cleanscreen" || in == "CLEANSCREEN" || in == "#C" || in == "#c")
                        {
                            CleanScreen();
                        }
                    }
                }
                if(in == "cleanscreen" || in == "CLEANSCREEN" || in == "#C" || in == "#c")
                {
                    CleanScreen();
                }
                if(in == "shutdown" || in == "SHUTDOWN" || in == "#s" || in == "#S")
                {
                    Shutdown();
                }
                if(in == "about" || in == "ABOUT")
                {
                    while(true)
                    {
                        CleanScreen();
                        PaperFramework("SetUp Your OS","ConfigureApp","NONE");
                        PaperFramework("About","ConfigureApp","NONE");
                        ShowImage();
                        NowLocation = "About >>>";
                        cout << NowLocation;
                        string in;
                        cin >> in;
                        if(in == "movewindow" || in == "MOVEWINDOW")
                        {
                            PaperFramework("About","MoveWindow","AboutNMainWindow");
                        }
                        if(in == "MOVEWINDOWBYLOCATION" || in == "MWBL")
                        {
                            PaperFramework("About","MoveWindowByLocation","AboutNMainWindow");
                        }
                        if(in == "#q" || in == "#Q" || in == "quit" || in == "QUIT")
                        {
                            break;
                        }
                        if(in == "cleanscreen" || in == "CLEANSCREEN" || in == "#C" || in == "#c")
                        {
                            CleanScreen();
                        }
                    }
                }
            }
            if(Is_Seted_Username == true && Is_Seted_Password == false)
            {
                while(true)
                {
                    GUICommands();
                    PaperFramework("Data/Apps/SetUp Your OS/Graphics/SetPswd.txt","CreateView","NONE");
                    ShowImage();
                    NowLocation = "Set New Password >>>";
                    cout << NowLocation;
                    string in;
                    cin >> in;
                    while(in == "in" || in == "IN")
                    {
                        CleanScreen();
                        ShowImage();
                        NowLocation = "Type your new password >>>";
                        cout << NowLocation;
                        string inp;
                        cin >> inp;

                        if(StringLength(inp) > 3)
                        {
                            Lib.User_password = inp;

                            CleanScreen();
                            NMessageBox(5,15,"Secure","Congratulations! Password is setting completed!","33","32","31");
                            ShowImage();
                            sleep(2);

                            Is_Seted_Password = true;

                            break;
                        }
                        else
                        {
                            CleanScreen();
                            NMessageBox(5,15,"Secure","Password's length must be greater than 4 digits!","33","32","31");
                            ShowImage();
                            sleep(2);
                        }
                    }
                    if(in == "OK" || in == "ok")
                    {
                        if(Is_Seted_Username == true)
                        {
                            break;
                        }
                    }
                    if(in == "#s" || in == "#S" || in == "shutdown" || in == "SHUTDOWN")
                    {
                        Shutdown();
                    }
                    if(in == "cleanscreen" || in == "CLEANSCREEN" || in == "#C" || in == "#c")
                    {
                        CleanScreen();
                    }
                }
            }
        }
    }
}

int main()
{
    CleanScreen();

    RefreshData();

    if(Lib.OS_start == "False")
    {
        RunApp("SetUp Your OS");
    }
    else if(Lib.OS_start == "True")
    {
        RunApp("Check Personal Info");
    }
    else if(Lib.OS_start == "Console")
    {
        while(true)
        {
            NowLocation = "Console >>>";
            cout << NowLocation;
            string in;
            cin >> in;
            if(in == "boot" || in == "BOOT")
            {
                while(true)
                {
                    NowLocation = "Boot Config File >>>";
                    cout << NowLocation;
                    string in;
                    cin >> in;
                    if(in == "False")
                    {
                        NWrite("System/OS/Start.nsf","False");
                    }
                    if(in == "True")
                    {
                        NWrite("System/OS/Start.nsf","True");
                    }
                    if(in == "Console")
                    {
                        NWrite("System/OS/Start.nsf","Console");
                    }
                    ReBoot();
                    break;
                }
            }
            if(in == "about" || in == "ABOUT")
            {
                cout << ReplaceText(Lib.OS_version,'^',' ') << endl;
                cout << ReplaceText(Lib.OS_platform,'^',' ') << endl;
                cout << ReplaceText(Lib.Kernel_version,'^',' ') << endl;
                cout << ReplaceText(Lib.UI_version,'^',' ') << endl;
                cout << ReplaceText(Lib.Secure_version,'^',' ') << endl;
                cout << ReplaceText(Lib.Framework_version,'^',' ') << endl;
            }
            if(in == "#c" || in == "#C" || in == "cleanscreen" || in == "CLEANSCREEN")
            {
                CleanScreen();
            }
            if(in == "#r" || in == "#R" || in == "reboot" || in == "REBOOT")
            {
                ReBoot();
            }
            if(in == "#s" || in == "#S" || in == "shutdown" || in == "SHUTDOWN")
            {
                Shutdown();
            }
        }
    }
    if(Lib.OS_start == "Recovery")
    {
        system("./Recovery/RecProgram.nap");
    }
    else
    {
        GUICommands();
        BugScreen();
        ShowImage();
        sleep(5);
    }

    return 0;
}