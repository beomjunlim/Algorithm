#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int N;
int food[17][17];
bool visited[17];
int answer = 1e9;

void combination(int start, int idx){
    if(idx==N/2){
        int sum_a = 0;
        int sum_b = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(visited[i]&&visited[j])
                    sum_a += food[i][j];
                if(!visited[i]&&!visited[j])
                    sum_b += food[i][j];
            }
        }

        answer = min(answer, abs(sum_a-sum_b));
        return;
    }

    for(int i=start; i<N; i++){
        visited[i] = true;
        combination(i+1, idx+1);
        visited[i] = false;
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>N;
        memset(visited,false, sizeof(visited));
        answer = 1e9;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>food[i][j];
            }
        }

        // A는 식재료 0번 고정
        visited[0] = true;
        combination(1,1);

        cout<<"#"<<test_case<<" "<<answer<<'\n';


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}