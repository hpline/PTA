#include <iostream>
using namespace std;

class Table {
private:
    int MaxSize;
    int *Data;
public:
    Table(int MaxSize){
        this->Data = new int[MaxSize];
        this->MaxSize = MaxSize;
        for(int i = 0; i < MaxSize; i++)
            cin >> this->Data[i];
    }
    int MaxSeqSum() {
        int max = 0;
        for(int i = 0; i < this->MaxSize; i++) {
            if(this->Data[i] <= 0) continue;
            int ans = 0;
            do {
                ans += this->Data[i];
                if(this->Data[i] > 0 && ans > max) max = ans;
                else if(ans <= 0) break;
            } while(++i < this->MaxSize);
        }
        return max;
    }
};

int main()
{
    int K;
    cin >> K;
    Table T(K);
    cout << T.MaxSeqSum() << endl;
    return 0;
}