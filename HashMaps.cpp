#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void frequencyMap(int a[], vector<int> q){
    unordered_map<int, int> hm;

    for (int i = 0; i < 10; i++)
    {
        if(hm[a[i]]){
            int temp = hm[a[i]];
            temp++;
            hm[a[i]] = temp;
        }
        else hm[a[i]] = 1;
    }
    
    cout<<"FREQUENCY MAP:"<<endl;
    for(auto& i : hm){
        cout<<i.first<<"_"<<i.second<<endl;
    }

    cout<<"ANSWER:"<<endl;
    for (int i = 0; i < q.size(); i++)
    {
        if(hm[q[i]]){
            cout<<q[i]<<" - "<<hm[q[i]]<<endl;
        }
        else cout<<q[i]<<" - "<<0<<endl;
    }

}

int main(){
    int arr[10];
    vector<int> queries;
    
    for (int i = 0; i < 10; i++)
    {
        cin>>arr[i];
    }

    for (int i = 0; i < 7; i++)
    {
        int temp;
        cin>>temp;
        queries.push_back(temp);
    }

    frequencyMap(arr, queries);

    return 0;
}