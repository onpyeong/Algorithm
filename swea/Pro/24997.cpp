#include <iostream>
#include <set>
#include <unordered_set>
#include <cmath>
using namespace std;

#define MAX_TAXI 2001
#define BUCKET_SIZE 10

struct Taxi
{
	int x;
	int y;
	int moveDistance;
	int rideDistance;
} taxi[MAX_TAXI];

struct BestTaxi
{
	int rideDistance;
	int taxi_idx;
	bool operator<(const BestTaxi &b) const
	{
		if (rideDistance == b.rideDistance)
		{
			return taxi_idx < b.taxi_idx;
		}
		return rideDistance > b.rideDistance;
	}
};
set<BestTaxi> bestTaxi_set; // 이동거리 크고 택시번호 낮은 순

int n, l;
unordered_set<int> city_map[BUCKET_SIZE][BUCKET_SIZE]; // 버킷 -> taxi_idx 저장

struct Result
{
	int mX, mY;
	int mMoveDistance;
	int mRideDistance;
};

void init(int N, int M, int L, int mXs[], int mYs[])
{
	bestTaxi_set.clear();
	for (int i = 0; i < BUCKET_SIZE; i++)
	{
		for (int j = 0; j < BUCKET_SIZE; j++)
		{
			city_map[i][j].clear();
		}
	}
	n = N;
	l = L;
	for (int i = 1; i <= M; i++)
	{
		taxi[i] = {mXs[i - 1], mYs[i - 1], 0, 0};
		city_map[mXs[i - 1] / L][mYs[i - 1] / L].insert(i);
		bestTaxi_set.insert({0, i});
	}
	return;
}

int pickup(int mSX, int mSY, int mEX, int mEY)
{
	// 출발지의 버킷 인덱스
	int bx = mSX / l;
	int by = mSY / l;

	// 탐색 범위 최대 9칸 -> 한 칸의 길이가 L이므로 주변 9칸만 보면 됨
	int sx = bx - 1;
	if (sx < 0)
		sx = 0;
	int sy = by - 1;
	if (sy < 0)
		sy = 0;
	int ex = bx + 1;
	if (ex >= BUCKET_SIZE)
		ex = BUCKET_SIZE - 1;
	int ey = by + 1;
	if (ey >= BUCKET_SIZE)
		ey = BUCKET_SIZE - 1;

	set<pair<int, int>> call_taxi; // 거리, 번호

	// 거리 계산
	int dist;
	for (int i = sx; i <= ex; i++)
	{
		for (int j = sy; j <= ey; j++)
		{
			for (int idx : city_map[i][j])
			{
				dist = abs(taxi[idx].x - mSX) + abs(taxi[idx].y - mSY);
				if(dist <= l) {
					call_taxi.insert({dist, idx});
				}
			}
		}
	}

	// 택시 없는 경우
	if (call_taxi.empty())
		return -1;

	// 택시 호출
	pair<int, int> picked_taxi = (*call_taxi.begin());
	int taxi_idx = picked_taxi.second;
	Taxi t = taxi[taxi_idx];
	// 이전 거리 정보 삭제
	bestTaxi_set.erase({t.rideDistance, taxi_idx});
	city_map[t.x / l][t.y / l].erase(taxi_idx);

	// 택시 거리 증가
	taxi[taxi_idx].rideDistance += abs(mSX - mEX) + abs(mSY - mEY);
	taxi[taxi_idx].moveDistance += picked_taxi.first + abs(mSX - mEX) + abs(mSY - mEY);
	bestTaxi_set.insert({taxi[taxi_idx].rideDistance, taxi_idx});
	taxi[taxi_idx].x = mEX;
	taxi[taxi_idx].y = mEY;
	city_map[taxi[taxi_idx].x / l][taxi[taxi_idx].y / l].insert(taxi_idx);

	return taxi_idx;
}

Result reset(int mNo)
{
	Result res;
	Taxi t = taxi[mNo];

	// 이전 정보 저장
	res.mX = t.x;
	res.mY = t.y;
	res.mMoveDistance = t.moveDistance;
	res.mRideDistance = t.rideDistance;

	// 초기화
	bestTaxi_set.erase({t.rideDistance, mNo});
	bestTaxi_set.insert({0, mNo});
	taxi[mNo].rideDistance = taxi[mNo].moveDistance = 0;

	return res;
}

{
	int cnt = 0;
	auto it = bestTaxi_set.begin();
	while (cnt < 5 && it != bestTaxi_set.end())
	{
		mNos[cnt++] = (*it).taxi_idx;
		it++;
	}
	return;
}
