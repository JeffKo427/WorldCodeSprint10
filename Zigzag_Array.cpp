#include <bits/stdc++.h>

using namespace std;
int streak;

int getStreak(vector<int> a, int i, bool increasing) {
    if (increasing) {
        if (a[i+1] > a[i]) {
            streak++;
            getStreak(a,i,true);
        }
    } else {
        if (a[i+1] < a[i]) {
            streak++;
            getStreak(a,i,false);
        }
    }
}
        



int minimumDeletions(vector < int > a){
    // Complete this function
    int minDel = 0;
    bool increasing;
    for (int i = 0; i < a.size(); i++) {
        streak = 1;
        if (a[i+1] > a[i]) {
            getStreak(a,i,true);
        } else {
            getStreak(a,i,false);
        }
        minDel += streak;
    }
    return minDel;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    // Return the minimum number of elements to delete to make the array zigzag
    int result = minimumDeletions(a);
    cout << result << endl;
    return 0;
}
