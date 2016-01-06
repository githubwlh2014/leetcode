string itoa(int m)
{
    if(m==0)
        return "0";
    if(m==-2147483648)
        return "-2147483648";
    string tag="";
    string str="";
    if(m<0)
    {
        tag+='-';
        m=-m;
    }

    while(m)
    {
        str=char(m%10+'0')+str;
        m/=10;
    }
    str=tag+str;
    return str;
}
