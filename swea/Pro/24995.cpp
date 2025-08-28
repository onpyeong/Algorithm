#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <vector>

#define MAX_CATE 5
#define MAX_COMP 5
#define MAX_PROD 50000
using namespace std;

unordered_map<int, int> id_to_idx;
int m_idx;

struct PriceId {
	int price;
	int id;
	bool operator<(const PriceId& b) const {
		if (price == b.price)
			return id < b.id;
		return price < b.price;
	}
};

// 정렬하는 법
set<PriceId> product_set[MAX_CATE + 1][MAX_COMP + 1]; // 품목, 제조사 별 상품목록 (가격, id 낮은 순)
int minus_price[MAX_CATE + 1][MAX_COMP + 1];
int product_cnt[MAX_CATE + 1][MAX_COMP + 1]; // set size

struct Product {
	int m_id;
	int cate;
	int comp;
	int price;
	bool isDel;
};
Product products[MAX_PROD + 1];


struct RESULT
{
	int cnt;
	int IDs[5];
};

void init()
{
	id_to_idx.clear();
	for (int i = 0; i <= MAX_CATE; i++) {
		for (int j = 0; j <= MAX_COMP; j++) {
			product_set[i][j].clear();
			minus_price[i][j] = 0;
			product_cnt[i][j] = 0;
		}
	}
	m_idx = 0;
	return;
}

int sell(int mID, int mCategory, int mCompany, int mPrice)
{
	id_to_idx[mID] = m_idx;

	int new_price = mPrice + minus_price[mCategory][mCompany];
	products[m_idx] = {mID, mCategory, mCompany, new_price, false };
	m_idx++;

	product_set[mCategory][mCompany].insert({ new_price, mID });
	product_cnt[mCategory][mCompany]++;

	return product_cnt[mCategory][mCompany];
}

int closeSale(int mID)
{
	if (id_to_idx.find(mID) == id_to_idx.end() || products[id_to_idx[mID]].isDel) {
		return -1;
	}
	Product p = products[id_to_idx[mID]];

	products[id_to_idx[mID]].isDel = true; // lazy delete
	product_cnt[p.cate][p.comp]--;

	return p.price - minus_price[p.cate][p.comp];
}

int discount(int mCategory, int mCompany, int mAmount)
{
	minus_price[mCategory][mCompany] += mAmount;

	auto it = product_set[mCategory][mCompany].begin();
	while (it != product_set[mCategory][mCompany].end()) {
		if ((*it).price > minus_price[mCategory][mCompany])
			break;
		if (!products[id_to_idx[(*it).id]].isDel) {
			product_cnt[mCategory][mCompany]--;
			products[id_to_idx[(*it).id]].isDel = true;
		}
		it = product_set[mCategory][mCompany].erase(it); // delete
	}
	
	return product_cnt[mCategory][mCompany];
}

RESULT show(int mHow, int mCode)
{
	RESULT res;
	vector<pair<int, int>> temp;

	for (int i = 1; i <= MAX_CATE; i++) {
		if (mHow == 1 && i != mCode)
			continue;
		for (int j = 1; j <= MAX_COMP; j++) {
			if (mHow == 2 && j != mCode)
				continue;

			int cnt = 0;
			auto it = product_set[i][j].begin();
			while(it != product_set[i][j].end()) {
				if (!products[id_to_idx[(*it).id]].isDel) {
					temp.push_back({ (*it).price - minus_price[i][j], (*it).id });
					cnt++;
				}
				it++;
				if (cnt >= 5)
					break;
			}
		}
	}

	sort(temp.begin(), temp.end()); // 5 * 5 * 5

	int cnt = 0;
	auto it = temp.begin();
	while (it != temp.end() && cnt < 5) {
		res.IDs[cnt++] = (*it).second;
		it++;
	}
	res.cnt = cnt;

	return res;
}
