#include<iostream>
#include<string.h>
using namespace std;


/*struct Rec{
    int bottomX;
    int bottomY;
    int topX;
    int topY;
};
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int leftArea=(C-A)*(D-B);
    int rightArea=(G-E)*(H-F);
    Rec recl;
    Rec recr;
    if(A<E)
    {
        recl.bottomX=A;
        recl.bottomY=B;
        recl.topX=C;
        recl.topY=D;

        recr.bottomX=E;
        recr.bottomY=F;
        recr.topX=G;
        recr.topY=H;
    }else
    {
        recr.bottomX=A;
        recr.bottomY=B;
        recr.topX=C;
        recr.topY=D;

        recl.bottomX=E;
        recl.bottomY=F;
        recl.topX=G;
        recl.topY=H;
    }
    if(recr.bottomX>=recl.topX||recr.bottomY>=recl.topY||recl.bottomY>=recr.topY)
        return (leftArea+rightArea);
    int len=0;
    int width=(recl.topX>recr.topX?recr.topX:recl.topX)-recr.bottomX;
    if(recl.bottomY<recr.bottomY)
        len=(recl.topY>recr.topY?recr.topY:recl.topY)-recr.bottomY;
    else
        len=(recr.topY>recl.topY?recl.topY:recr.topY)-recl.bottomY;
    return (leftArea+rightArea-(width*len));


}*/

void PrintNumber(char* number)
{
    bool isBeginning0 = true;
    int nLength = strlen(number);

    for(int i = 0; i < nLength; ++ i)
    {
        if(isBeginning0 && number[i] != '0')
            isBeginning0 = false;

        if(!isBeginning0)
        {
            //printf("%c", number[i]);
            cout<<number[i];
        }
    }

    //printf("\t");
    cout<<'\t';
}
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
    if(index == length - 1)
    {
        PrintNumber(number);
        return;
    }

    for(int i = 0; i < 10; ++i)
    {
        number[index + 1] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
    }
}

void Print1ToMaxOfNDigits_2(int n)
{
    if(n <= 0)
        return;

    char* number = new char[n + 1];
    number[n] = '\0';

    for(int i = 0; i < 10; ++i)
    {
        number[0] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, n, 0);
    }

    delete[] number;
}


int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
 int res = (D - B) * (C - A) + (H - F) * (G - E);
 int A1 = A>E?A:E;
 int B1 =B>F?B:F;
 int C1 =C>G?G:C;
 int D1 =D>H?H:D;
 if (D1 <= B1 || C1 <= A1) return res;
 return res - (D1 - B1) * (C1 - A1);
}

int main()
{
    Print1ToMaxOfNDigits_2(2);
}
