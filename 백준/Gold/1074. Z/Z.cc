#include <iostream>
#include <cmath>

using namespace std;

int N, r, c;
int ans;

void solve(int x, int y, int size)
{
    if (x == r && y == c)
    {
        cout << ans << '\n';
        return;
    }

    if (r < x + size && r >= x && c < y + size && c >= y)
    {
        solve(x, y, size / 2);

        solve(x, y + size / 2, size / 2);

        solve(x + size / 2, y, size / 2);

        solve(x + size / 2, y + size / 2, size / 2);
    }
    else
    {
        ans += size * size;
    }
}
int main()
{

    cin >> N >> r >> c;
    solve(0, 0, pow(2,N));
    return 0;
}