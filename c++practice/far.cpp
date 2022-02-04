#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> graph(n+1);
    vector<int> visited(n+1,0);
    queue<int> q;
    
    for(int i=0;i<edge.size();i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    q.push(1);
    visited[1] = 1;
    int visited_element;
    
    while(!q.empty()){
        
        visited_element = q.front();
        q.pop();
       
        for(int i=0;i<graph[visited_element].size();i++){
            
            int adjacent_element;
            adjacent_element = graph[visited_element][i]; // 3,2
            
            if( visited[adjacent_element] == 0){
                q.push(adjacent_element);
                visited[adjacent_element] = visited[visited_element] + 1;
            }
        }
    }
    
    int max = 0 ;
    
    for(int i=0;i<visited.size();i++){
        cout<<visited[i]<<",";
        if(visited[i] > max){
            max = visited[i];
        }
    }
    
   
    for(int i=1;i<=visited.size();i++){
        if(visited[i] == max){
            answer+=1;
        }
    }
    
    return answer;
}