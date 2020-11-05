#include <iostream>

using namespace std;

int main()
{
    int s, l1, r1, l2, r2;
    setlocale (LC_ALL, "Russian");
    cout << "¬ведите  s,l1,r1,l2,r2: ";
    cin >> s >> l1 >> r1 >> l2 >> r2;
    if ((s >= l1+l2) && (s <= r1+r2))
    {
        if (l1 + r2 - s == 0)
            cout<<l1<<r2;
        else if (l1 + r2 - s < 0)
            cout<<l1 - (l1+r2-s);
        else if (l1 + r2 - s > 0)

            cout<<l1<<"  "<<r2 - (l1+r2-s);
    }
    else {
        cout<< -1;
    }

}


