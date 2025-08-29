#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <map>
using namespace std;

#define MAX_ORDERS 20001
#define MAX_BEVERAGES 11

unordered_map<int, int> id_to_idx; // mID to index
int m_idx;

struct HurryOrder
{
    int remain_cnt;
    int m_idx;
    bool operator<(const HurryOrder &b) const
    {
        if (remain_cnt == b.remain_cnt)
            return m_idx < b.m_idx;
        return remain_cnt > b.remain_cnt;
    }
};

set<HurryOrder> hurry_orders; // (남은 음료 개수 많은 순, 주문 오래된 순)
struct Order
{
    int mID;
    int remain_beverage_cnt;      // 남은 음료 개수
    int baverages[MAX_BEVERAGES]; // 음료 종류별 개수
    vector<int> finish_baverages; // 공급된 음료
    bool is_cancel;               // 취소 여부
    bool is_finish;               // 완료 여부
};
Order orders[MAX_ORDERS];

map<int, int> waiting_baverages[MAX_BEVERAGES]; // 기다리는 음료들 (m_idx, cnt)

struct RESULT
{
    int cnt;
    int IDs[5];
};

void init(int N)
{
    id_to_idx.clear();
    m_idx = 0;
    hurry_orders.clear();
    for (int i = 1; i < MAX_BEVERAGES; i++)
    {
        waiting_baverages[i].clear();
    }
    return;
}

int order(int mID, int M, int mBeverages[])
{
    id_to_idx[mID] = m_idx;
    orders[m_idx] = {mID, M, {0}, vector<int>(), false, false};

    hurry_orders.insert({M, m_idx});

    for (int i = 0; i < M; i++)
    {
        waiting_baverages[mBeverages[i]][m_idx]++; // 기다리는 주문표에 (m_idx, cnt) 추가
        orders[m_idx].baverages[mBeverages[i]]++;
    }
    m_idx++;
    return hurry_orders.size();
}

int supply(int mBeverage)
{
    if (waiting_baverages[mBeverage].empty())
    { // 필요한 음료 없으면 pass
        return -1;
    }

    int t_idx = waiting_baverages[mBeverage].begin()->first; // 가장 오래된 주문
    waiting_baverages[mBeverage][t_idx]--;
    if (waiting_baverages[mBeverage][t_idx] == 0)  // 해당 주문의 음료 공급 되었으면
        waiting_baverages[mBeverage].erase(t_idx); // 대기표에서 삭제

    // hurry_orders에서 이전 상태 삭제
    hurry_orders.erase({orders[t_idx].remain_beverage_cnt, t_idx});
    orders[t_idx].remain_beverage_cnt--;

    // idx 순서대로 공급 되는것이 아님!!!!!
    orders[t_idx].baverages[mBeverage]--;                // 해당 음료 개수 감소
    orders[t_idx].finish_baverages.push_back(mBeverage); // 완료된 음료에 추가

    // finish 태그!
    if (orders[t_idx].remain_beverage_cnt == 0)
    {
        orders[t_idx].is_finish = true;
        return orders[t_idx].mID;
    }

    // hurry_orders에 현재 상태 추가
    hurry_orders.insert({orders[t_idx].remain_beverage_cnt, t_idx});
    return orders[t_idx].mID;
}

int cancel(int mID)
{
    int t_idx = id_to_idx[mID];
    // bool 여부 판단
    if (orders[t_idx].is_finish)
    {
        return 0;
    }
    if (orders[t_idx].is_cancel)
    {
        return -1;
    }

    // hurry_orders에서 이전 상태 삭제
    hurry_orders.erase({orders[t_idx].remain_beverage_cnt, t_idx});

    Order order = orders[t_idx];
    // 대기표에 있던 음료들 지워주기
    for (int i = 1; i < MAX_BEVERAGES; i++)
    {
        int cnt = order.baverages[i];
        while (cnt > 0 && !waiting_baverages[i].empty())
        {
            waiting_baverages[i].erase(t_idx); // key값으로 전부 삭제
            cnt--;
        }
    }
    // 재배치
    for (int i = 0; i < order.finish_baverages.size(); i++)
    {
        if (waiting_baverages[order.finish_baverages[i]].empty())
        {
            continue;
        }
        supply(order.finish_baverages[i]);
    }

    // 취소 처리
    orders[t_idx].is_cancel = true;
    return orders[t_idx].remain_beverage_cnt;
}

int getStatus(int mID)
{
    int t_idx = id_to_idx[mID];
    if (orders[t_idx].is_finish)
    {
        return 0;
    }
    if (orders[t_idx].is_cancel)
    {
        return -1;
    }
    return orders[t_idx].remain_beverage_cnt;
}

RESULT hurry()
{
    RESULT res;

    int cnt = 0;
    auto it = hurry_orders.begin();
    while (it != hurry_orders.end() && cnt < 5)
    {
        res.IDs[cnt++] = orders[(*it).m_idx].mID;
        it++;
    }

    res.cnt = cnt;
    return res;
}
