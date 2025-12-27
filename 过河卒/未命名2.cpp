/*#include <iostream>
using namespace std;
#define int long long
int k,j,m,n;
int dx[]={0,-2,-2,2,2,-1,-1,1,1};
int dy[]={0,1,-1,1,-1,2,-2,2,-2};
bool s(int x,int y){
	for(int i=1;i<9;i++){
		if((x==k+dx[i])&&(y==j+dy[i]))return true;
	}
	return false;
}
int func(int x,int y){
	
	if(x < 0 || y < 0)return 0;
	if(s(x,y))return 0;
	if(x == 0 && y == 0)return 1;
	return func(x,y-1)+func(x-1,y);
}

signed main(){
	int m,n,k,j;
	cin >> m >> n >> k >> j;
	int ans = func(m,n);
	if(s(m,n)){
		cout<<0<<endl;
	}
	cout<<ans<<endl;
	return 0;
}*/
/*#include <iostream>
#include <vector>
using namespace std;

int n, m, x_h, y_h;
vector<vector<bool> > block;
vector<vector<long long> > memo;  // 记忆化数组

bool isBlocked(int x, int y) {
    return block[x][y];
}

long long dfs(int x, int y) {
    if (x > n || y > m) return 0;
    if (isBlocked(x, y)) return 0;
    if (x == n && y == m) return 1;
    
    // 如果已经计算过，直接返回结果
    if (memo[x][y] != -1) return memo[x][y];
    
    // 计算并保存结果
    memo[x][y] = dfs(x + 1, y) + dfs(x, y + 1);
    return memo[x][y];
}

int main() {
    cin >> n >> m >> x_h >> y_h;

    int dx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};

    block.resize(n + 1, vector<bool>(m + 1, false));
    memo.resize(n + 1, vector<long long>(m + 1, -1));  // 初始化为-1表示未计算

    for (int k = 0; k < 9; k++) {
        int nx = x_h + dx[k];
        int ny = y_h + dy[k];
        if (nx >= 0 && nx <= n && ny >= 0 && ny <= m) {
            block[nx][ny] = true;
        }
    }

    if (block[0][0] || block[n][m]) {
        cout << 0 << endl;
        return 0;
    }

    long long result = dfs(0, 0);
    cout << result << endl;

    return 0;
}*/
#include <iostream>
using namespace std;
int val[30][30];
int vis[30][30];
int dx[] = {0, -2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {0, -1, 1, -2, 2, -2, 2, -1, 1};

long long func(int x, int y, int horse_x, int horse_y) {
    for(int i = 0; i < 9; i++) {
        if(x == horse_x + dx[i] && y == horse_y + dy[i]) {
            return 0;
        }
    }    
    if(x == 0 && y == 0) {
        return 1;
    }

    if(x < 0 || y < 0) {
        return 0;
    }
    if(vis[x][y])return val[x][y];
    if(x == 0) {
        val[x][y] = func(0, y-1, horse_x, horse_y);
        vis[x][y] = 1;
        return val[x][y];
    }
    if(y == 0) {
        val[x][y] = func(x-1, 0, horse_x, horse_y);
        vis[x][y] = 1;
        return val[x][y];
    }
    val[x][y] =  func(x, y-1, horse_x, horse_y) + func(x-1, y, horse_x, horse_y);
	vis[x][y] = 1;
	return val[x][y];
}

int main() {
    int n, m, horse_x, horse_y;
    cin >> n >> m >> horse_x >> horse_y;
    
    long long ans = func(n, m, horse_x, horse_y);
    cout << ans << endl;
    
    return 0;
}
