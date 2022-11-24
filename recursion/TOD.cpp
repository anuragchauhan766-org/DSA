
#include <iostream>
using namespace std;
void TOH(int disk_no, char source, char dest, char helper)
{
    if (disk_no == 1)
    {
        cout << "move disk " << disk_no << " from " << source << " to " << dest << endl;
        return;
    }
    TOH(disk_no - 1, source, helper, dest);
    cout << "move disk " << disk_no << " from " << source << " to " << dest << endl;
    TOH(disk_no - 1, helper, dest, source);
}
int main()
{
    int n;
    cout << "ENTER NO OF DISK IN TOWER: \n";
    cin >> n;
    TOH(n, 'A', 'C', 'B');
    return 0;
}