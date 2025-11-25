#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <fstream>
#include <climits>

using namespace std;

#define FI "test1.inp"
#define FO "test1.out"

const int MAXN = 105;

int N, M;
int xi, yi, xj, yj; // Tọa độ điểm bắt đầu (xi, yi) và điểm kết thúc (xj, yj)
int A[MAXN][MAXN];
int cost[MAXN][MAXN]; // cost[i][j]: chi phí nhỏ nhất để đi đến ô (i, j)
pair<int, int> trace[MAXN][MAXN];
bool visited[MAXN][MAXN]; // visited[i][j]: đánh dấu ô đã xử lý trong Dijkstra

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool trongBang(int x, int y)
{
    // Trả về true nếu (x, y) nằm trong giới hạn của ma trận
    return x >= 1 && x <= N && y >= 1 && y <= M;
}

void dijkstra()
{
    // Khởi tạo
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cost[i][j] = INT_MAX;

    // Hàng đợi ưu tiên lưu (cost, x, y), sắp xếp theo cost nhỏ nhất
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    // Khởi tạo điểm xuất phát
    cost[xi][yi] = 0;
    pq.emplace(0, xi, yi);

    while (!pq.empty())
    {
        auto [c, x, y] = pq.top();
        pq.pop();

        // Nếu ô này đã được xử lý thì bỏ qua
        if (visited[x][y])
            continue;
        visited[x][y] = true;

        // Duyệt 4 ô kề
        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // Kiểm tra ô hợp lệ và không phải tường (A[nx][ny] != 0)
            if (trongBang(nx, ny) && A[nx][ny] != 0)
            {
                // Nếu là ô đích thì không cộng thêm cost
                int newCost = c + ((nx == xj && ny == yj) ? 0 : A[nx][ny]);

                // Cập nhật nếu tìm được đường tốt hơn
                if (newCost < cost[nx][ny])
                {
                    cost[nx][ny] = newCost;
                    trace[nx][ny] = {x, y}; // Ghi lại đường đi
                    pq.emplace(newCost, nx, ny);
                }
            }
        }
    }
}

int main()
{
    ifstream fi(FI);

    fi >> N >> M >> xi >> yi >> xj >> yj;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            fi >> A[i][j];

    // Nếu ô bắt đầu hoặc ô kết thúc bị chặn (giá trị = 0)
    if (A[xi][yi] == 0 || A[xj][yj] == 0)
    {
        cout << "0\n"; // Không thể đi được
        return 0;
    }

    dijkstra();

    if (cost[xj][yj] == INT_MAX)
    {
        cout << "0\n";
    }
    else
    {
        // Có đường đi
        cout << "1\n";                // In ra 1 để báo có đường
        cout << cost[xj][yj] << "\n"; // In tổng chi phí nhỏ nhất

        // Truy vết đường đi ngược từ đích về đầu
        vector<pair<int, int>> path;
        int x = xj, y = yj;
        while (!(x == xi && y == yi))
        {
            path.emplace_back(x, y);
            tie(x, y) = trace[x][y];
        }
        path.emplace_back(xi, yi);         // Thêm điểm đầu vào cuối
        reverse(path.begin(), path.end()); // Đảo lại theo thứ tự đúng

        // In đường đi (danh sách tọa độ)
        for (auto [x, y] : path)
            cout << x << " " << y << "\n";
    }

    return 0;
}