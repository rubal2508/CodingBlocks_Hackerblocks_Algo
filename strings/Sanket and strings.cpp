#include <bits/stdc++.h>
using namespace std;



int main(){
    int k; cin>>k;
    string s;
    cin>>s;

    //cout<<k<<endl<<s<<endl;

    deque<char> dq;

    //maximum length of a

    int count_b=0;
    int i=0;

    while(count_b <=k && i<s.length()){
        dq.push_back(s[i]);
        if(s[i] == 'b') count_b++;
        i++;
       // cout<<i<<endl;
    }

    if(i==s.length()){
        cout<<s.length()<<endl;
        return 0;
    }

    dq.pop_back();
    count_b--;
    i--;
    int max_size = dq.size();

    //cout<<max_size<<endl;

    while(i<s.length()){

            while(dq.front() != 'b' && !dq.empty()){
                dq.pop_front();
            }
            dq.pop_front();

            dq.push_back(s[i]);
            i++;

            while (s[i] != 'b' && i<s.length()) {
                dq.push_back(s[i]);
                i++;
            }


            //cout<<dq.size()<<endl;
            if(dq.size() > max_size ) max_size = dq.size();



    }

    //cout << max_size <<endl;

//maximum length of b

    deque<char> dq2;
    int count_a=0;
    i=0;


    while(count_a <=k && i<s.length()){
        dq2.push_back(s[i]);
        if(s[i] == 'a') count_a++;
        i++;
       // cout<<i<<endl;
    }

    if(i==s.length()){
        cout<<s.length()<<endl;
        return 0;
    }

    dq2.pop_back();
    count_a--;
    i--;
    int max_size2 = dq2.size();

    //cout<<max_size2<<endl;

    while(i<s.length()){

            while(dq2.front() != 'a' && !dq2.empty()){
                dq2.pop_front();
            }
            dq2.pop_front();

            dq2.push_back(s[i]);
            i++;

            while (s[i] != 'a' && i<s.length()) {
                dq2.push_back(s[i]);
                i++;
            }


            //cout<<dq.size()<<endl;
            if(dq2.size() > max_size2 ) max_size2 = dq2.size();



    }

    cout << max(max_size, max_size2) <<endl;



}
