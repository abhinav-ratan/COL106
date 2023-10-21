#include <bits/stdc++.h>


using namespace std;

class SetOperations {
public:
    SetOperations() {
        lists.resize(10000);
        l1.resize(10000, 0);
    }

    int insertz(int set_num, int data) {
        l1[set_num] = 1;
        if (count(lists[set_num].begin(), lists[set_num].end(), data) > 0) {
            return lists[set_num].size();
        } else {
            lists[set_num].push_back(data);
        }
        sort(lists[set_num].begin(), lists[set_num].end());
        return lists[set_num].size();
    }

    int deletez(int set_num, int data) {
        if (l1[set_num] == 0) {
            l1[set_num] = 1;
            return -1;
        } else if (count(lists[set_num].begin(), lists[set_num].end(), data) == 0) {
            return lists[set_num].size();
        } else {
            lists[set_num].erase(remove(lists[set_num].begin(), lists[set_num].end(), data), lists[set_num].end());
            return lists[set_num].size();
        }
    }

        vector<int> deletezz(int set_num, int data) {
        if (count(lists[set_num].begin(), lists[set_num].end(), data) > 0) {
            lists[set_num].erase(remove(lists[set_num].begin(), lists[set_num].end(), data), lists[set_num].end());
        }
        l1[set_num] = 1;
        return lists[set_num];
    }


    int belongsTo(int set_num, int data) {
        if (l1[set_num] == 0) {
            l1[set_num] = 1;
            return -1;
        } else if (count(lists[set_num].begin(), lists[set_num].end(), data) > 0) {
            return 1;
        } else {
            return 0;
        }
    }

    int unionz(int set_num1, int set_num2) {
        for (int i : lists[set_num2]) {
            if (find(lists[set_num1].begin(), lists[set_num1].end(), i) == lists[set_num1].end()) {
                lists[set_num1].push_back(i);
            }
        }
        sort(lists[set_num1].begin(), lists[set_num1].end());
        l1[set_num1] = 1;
        l1[set_num2] = 1;
        return lists[set_num1].size();
    }

    int intersectionz(int set_num1, int set_num2) {
        vector<int> l;
        for (int i : lists[set_num2]) {
            if (find(lists[set_num1].begin(), lists[set_num1].end(), i) != lists[set_num1].end()) {
                l.push_back(i);
            }
        }
        sort(l.begin(), l.end());
        lists[set_num1] = l;
        l1[set_num2] = 1;
        l1[set_num1] = 1;
        return lists[set_num1].size();
    }

    int sizez(int set_num) {
        l1[set_num] = 1;
        return lists[set_num].size();
    }

    int differencez(int set_num1, int set_num2) {
        for (int i : lists[set_num1]) {
            if (find(lists[set_num2].begin(), lists[set_num2].end(), i) != lists[set_num2].end()) {
                lists[set_num1].erase(remove(lists[set_num1].begin(), lists[set_num1].end(), i), lists[set_num1].end());
            }
        }
        l1[set_num1] = 1;
        l1[set_num2] = 1;
        return lists[set_num1].size();
    }

    int symmetric_differencez(int setnum1, int setnum2) {
        for (int i : lists[setnum2]) {
            auto it = find(lists[setnum1].begin(), lists[setnum1].end(), i);
            if (it == lists[setnum1].end()) {
                lists[setnum1].push_back(i);
            } else {
                lists[setnum1].erase(it);
            }
        }
        sort(lists[setnum1].begin(), lists[setnum1].end());
        l1[setnum1] = 1;
        l1[setnum2] = 1;
        return lists[setnum1].size();
    }

    void printSet(int set_num) {
        string a = "";
        if (l1[set_num] == 0) {
            cout << endl;
        } else {
            for (int i : lists[set_num]) {
                a += to_string(i) + ",";
            }
            cout << a.substr(0, a.length() - 1) << endl;
        }
    }

private:
    vector<vector<int>> lists;
    vector<int> l1;
};

int main() {
    SetOperations setOps;
    // int n=100000;
    int command;
    while(cin>>command){
    // for (int i = 0; i < n; ++i) {
    //     int command;
    //     cin >> command;

        if (command == 1) {
            int set_num, data;
            cin >> set_num >> data;
            cout << setOps.insertz(set_num, data) << endl;
        } else if (command == 2) {
            int set_num, data;
            cin >> set_num >> data;
            cout << setOps.deletez(set_num, data) << endl;
        } else if (command == 3) {
            int set_num, data;
            cin >> set_num >> data;
            cout << setOps.belongsTo(set_num, data) << endl;
        } else if (command == 4) {
            int set_num1, set_num2;
            cin >> set_num1 >> set_num2;
            cout << setOps.unionz(set_num1, set_num2) << endl;
        } else if (command == 5) {
            int set_num1, set_num2;
            cin >> set_num1 >> set_num2;
            cout << setOps.intersectionz(set_num1, set_num2) << endl;
        } else if (command == 6) {
            int set_num;
            cin >> set_num;
            cout << setOps.sizez(set_num) << endl;
        } else if (command == 7) {
            int set_num1, set_num2;
            cin >> set_num1 >> set_num2;
            cout << setOps.differencez(set_num1, set_num2) << endl;
        } else if (command == 8) {
            int set_num1, set_num2;
            cin >> set_num1 >> set_num2;
            cout << setOps.symmetric_differencez(set_num1, set_num2) << endl;
        } else if (command == 9) {
            int set_num;
            cin >> set_num;
            setOps.printSet(set_num);
        }
    }

    return 0;
}
