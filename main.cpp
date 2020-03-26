#include <iostream>
using namespace std;
void shift_l(int *p ,int n);
void print(int *p ,int n);
void shift_r(int *p,int n);
void shift_r(int *p,int n)
{
    static int r = 0;
    cout << "请输入右移的位数：";
    cin >> r;
    if(r > n)
        r = r % n;
    else if ( r == n)
        print(p, n);
    int *q = new int [r];
    for(int i = 0 ; i < r;i++)
    {
        q[i] = p[n-r+i];//将后r位保存下来
    }
    cout << endl;
    for(int j = n-r-1; j >= 0 ; j--)
    {
        p[j+r] = p[j];//将前r位右移k位
    }
    for(int i = 0; i < r;i++)
    {
        p[i] = q[i];//将后k位移到前k位
    }
    delete [] q;
}
void shift_l(int *p ,int n)
{
    static int w = 0;
    cout << "请输入数组循环左移的位数：" ;
    cin >> w;
    if ( w > n){
        w = w % n;}
    else if (w == n){
             print(p, n);
    }
    int *p1 = new int[w];
    for(int i = 0; i < w;i++)
    {
        p1[i] = p[i];
    }
    cout << endl;
    for(int i = 0 ; i < n;i++)
    {
        if((w+i) < n){//把在移位数后面的元素映射到前面
            p[i] = p[(w+i) % n]; }//左移比右移好写
        else {
            p[i] = p1[i-n+w];
        }
    }
    delete [] p1;
}
    
void print(int *p ,int n)
{
    for(int i = 0; i < n ; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}
int main(){
    cout << "Enter the N is ：" ;
    int N;
    cin >> N;
    int *p = new int [N];
    for(int i = 0; i < N ; i++)
    {
        p[i] = i+1;
    }
    for(int i = 0; i < N ; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
    shift_r(p, N);
    cout << "移位后的数组为：" << endl;
    print(p, N);
    delete [] p;
    return 0;
}
