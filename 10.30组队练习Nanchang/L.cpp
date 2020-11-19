
/**
 * @Author: zjt
 * @Date:   30-Oct-2020
 * @Email:  yeschrome@yandex.com
 * @Filename: L.cpp
 * @Last modified by:   zjt
 * @Last modified time: 30-Oct-2020
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define mem(A,X) memset(A,X,sizeof(A))
#define fori(i,l,u) for(LL (i)=(LL)(l);(i)<=(LL)(u);++(i))

int a[110][110];
int score[110];
int n;
int main(){
    //freopen("local.in","r",stdin);
    while(cin>>n){
        fori(i,1,n){
            fori(j,1,n){
                cin>>a[i][j];
            }
        }
        fori(i,1,n){
            score[i] = 0;
            fori(j,1,n){
                if(j!=i){
                    int iscore = a[i][j];
                    int jscore = a[j][i];
                    if(iscore>jscore) score[i]+=3;
                    else if(iscore == jscore) score[i]+=1;
                    else continue;
                }
            }
        }
        int max_score=-1,max_cnt=0;
        std::vector<int> v;
        fori(i,1,n) max_score = max(max_score, score[(int)i]);
        fori(i,1,n) if(score[i] == max_score) { max_cnt++; v.push_back(i);}
        if(max_cnt == 1){
            cout<<v[0]<<endl;
        } else {
            int score_dif[110];
            mem(score_dif,0);
            fori(i,0,(LL)v.size()-1){
                int ti = v[i];
                fori(j,1,n){
                    score_dif[ti] += a[ti][j] - a[j][ti];
                }
            }
            int maxv = -1;
            std::vector<int> vv;
            fori(i,0,(LL)v.size()-1){
                int ti = v[i];
                maxv = max(maxv,score_dif[ti]);
            }
            fori(i,0,(LL)v.size()-1){
                int ti = v[i];
                if(maxv == score_dif[ti]){
                    vv.push_back(ti);
                }
            }
            if(vv.size()>1){
                cout<<"play-offs"<<endl;
            } else {
                cout<<vv[0]<<endl;
            }


        }

    }
    return 0;
}
