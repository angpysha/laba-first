#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define POINT_NUMBER 9
#define ARGUMENT 24
#define FUNCTION 24
int main()
{
    HANDLE hconsole;
    WORD point_color,arg_c,func_c,header;
    COORD cursorPos;
    CONSOLE_SCREEN_BUFFER_INFO SBInfo;
    char choise=0,choise2=0;
    float heigh_value;
    int status=1,i,con=1;
    hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    point_color = ((14) << 4) + (2);
    arg_c = ((15) << 4) + (12);
    func_c= ((11) << 4) + (9);
    header = ((9) << 4) + (14);
    float xmin,xmax,step,x,n,y,coutt;
    SetConsoleTextAttribute(hconsole,15);
    printf("Enter xmin: ");
    scanf("%f",&xmin);
    printf("\nEnter xmax: ");
    scanf("%f",&xmax);
    printf("Enter s for step or n for number: ");
    scanf("%s",&choise);
    switch (choise)
    {
    case 's':
    case 'S':
        {
           printf("\nEnter step: ");
            scanf("%f", &step);
            heigh_value=((xmax-xmin)/step)+1;
        };break;
    case 'n':
        case 'N':
            {
            printf("\nChange your number: ");
            scanf("%f",&heigh_value);
            step=(xmax-xmin)/(heigh_value-1);
            //printf("step===%f",&step);
            };break;
            default:
                {printf("Wrong data\n");
                getch();
                system("cls");
                return main();}
    }
   // printf("%lf",xmin);
    printf("\n");
    if (xmin>xmax)
    {
        printf("Wrong data!!!");
        getch();
        system("cls");
        return main();
    }
    coutt=1;
    int length = POINT_NUMBER+ARGUMENT+FUNCTION;
    x=xmin;
    for (i=0;i<length+4;i++){
        printf("%c",196);
    }
 //   printf("\n|   N   |              X              |        Y          |");
    SetConsoleTextAttribute(hconsole,header);
    printf("\n|%-*s|%-*s|%-*s|",POINT_NUMBER,"N",ARGUMENT,"X",FUNCTION,"Y");
    SetConsoleTextAttribute(hconsole,15);
    printf("\n");
 //   printf("\n\n%f\n\n",xmin);
    for (i=0;i<length+4;i++){
        printf("%c",196);
    }
//    for (int i=0;i<)
   /* for (int i=xmin;i<xmax;i+step)
    {
        y=i*i+3*i-4;
    }*/
   while (coutt<=heigh_value)
    {
        printf("\n");
        y=x*x-3*x-4;
        //for (int j=heigh_value;j++)
        //{
            //printf("|%-f*|%-f%*c|%-f%*c|",coutt,POINT_NUMBER,x,ARGUMENT,y,FUNCTION);
        //}
       //printf("|%7.0f|%-+29.3f|%-+19.3f|\n",point_color,coutt,x,y);
            SetConsoleTextAttribute(hconsole,15);
            printf("|");
            SetConsoleTextAttribute(hconsole,point_color);
           // SETCON
           // printf("%*s%-7.0f",3,"",coutt);
           // printf("%-9.0f",coutt);
           printf("%-*.0f",POINT_NUMBER,coutt);
            SetConsoleTextAttribute(hconsole,15);
            printf("|");
            SetConsoleTextAttribute(hconsole,arg_c);
            printf("%-*.3f",ARGUMENT,x);
            SetConsoleTextAttribute(hconsole,15);
            printf("|");
            SetConsoleTextAttribute(hconsole,func_c);
            printf("%-*.3f",FUNCTION,y);
            SetConsoleTextAttribute(hconsole,15);
            printf("|\n");
        //for

        for (i=0;i<length+4;i++){
        printf("%c",196);
        }
        if (con==1)
        {


        if ((int)coutt%10==0)
        {
            printf("\nPress key to continue");//fflush(stdout);
            //system("cls");
            getch();
           // printf("");fflush(stdout);
           printf("\r%*s",21," ");
//           cursorPos = GetCursorPos();
       //    cursorPos.Y = cursorPos.Y-1;
    //   cursorPos.Y = 25;
       //cursorPos.X = 62;
//GetConsoleCursorInfo(hconsole);
    GetConsoleScreenBufferInfo(hconsole,&SBInfo);
    cursorPos.Y = SBInfo.dwCursorPosition.Y-1;
    cursorPos.X=length+5;
      SetConsoleCursorPosition(hconsole,cursorPos);
     /*  for (i=0;i<length+4;i++){
        printf("%c",196);
        }*/
//           SetCursorPos(hconsole,cursorPos);
           //SetCursorPos()
           //GetCursorPos()
           //ESC
        }
        }

        if (con==0)
        {
           if ((int)coutt%12==0)
        {
            printf("\nPress key to continue");//fflush(stdout);
            //system("cls");
            getch();
           // printf("");fflush(stdout);
           printf("\r%*s",21," ");
           GetConsoleScreenBufferInfo(hconsole,&SBInfo);
    cursorPos.Y = SBInfo.dwCursorPosition.Y-1;
    cursorPos.X=length+5;
      SetConsoleCursorPosition(hconsole,cursorPos);
        }
        }
        con=0;
        x+=step;
        coutt++;
    }
    //getch();
    do
        {
            printf("\nAre you want to continue? ");
            scanf("%s",&choise2);
            switch (choise2)
            {
            case 'n':
                case 'N':status=1;return 0;break;
                case 'y':
                    case 'Y': status=1;system("cls");return main();break;
                    default : status=0;
            }
        } while (status==0);
}
