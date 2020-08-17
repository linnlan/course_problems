#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
long long pro_max(const vector <int> &num)
{
    int n = num.size();
    int i{0},j{0};
    long long product {0};
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            product = max(product,static_cast <long long> (num.at(i))*num.at(j));
        }
    }
    return product;
}
long long pro_max_fast(const vector <int> &num)
{
    int n = num.size();
    int i {0}, j {0};
    int max_index1=-1;
    for(i=0;i<n;i++)
    {
        if(max_index1==-1||num.at(i)>num.at(max_index1))
            max_index1=i;
    }
    int max_index2=-1;
    for(j=0;j<n;j++)
    {
        if((j!=max_index1)&&((max_index2==-1)||(num.at(j)>num.at(max_index2))))
            max_index2=j;
    }
    long long result = static_cast <long long> (num.at(max_index1))*num.at(max_index2);
    return result;
}
int main()
{   while(true)                       //this while loop tests for random tests viz stress testing
    {
        int n = rand()%4+2;
        cout << n << "\n";
        vector <int> a;
        for(int i=0;i<n;i++)
            a.push_back(rand()%10);
        for(int i=0;i<n;i++)
            cout << a.at(i) << " ";
        cout << "\n";
        long long res1=pro_max(a);
        long long res2=pro_max_fast(a);
        if(res1!=res2)
            {
                cout << "Wrong answer: " << res1 << " " << res2;
                break;
            }
            else
                cout << "OK" << "\n";
    }
    int n;
    cin >> n;
    vector <int> num (n);
    int i;
    for(i=0;i<n;i++)
    {
        cin >> num.at(i);
    }
    long long result = pro_max_fast(num);
    cout << result;

}
