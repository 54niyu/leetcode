//
// Created by Bing on 17/4/2.
//

#include "leetcode.h"
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> dis[4] = { matrix, matrix,matrix,matrix};
        int mm = (1<<30) ;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    continue;
                }else{
                    if( i==0 && j ==0){
                        dis[0][i][j] = mm;
                    }else{
                        if( i == 0){
                            dis[0][i][j] = dis[0][i][j-1] + 1;
                        }else if( j == 0){
                            dis[0][i][j] = dis[0][i-1][j] + 1;
                        }else{
                            dis[0][i][j] = min(dis[0][i-1][j], dis[0][i][j-1]) + 1;
                        }
                    }

                }
            }
        }

        for(int i=0;i<matrix.size();i++){
            for(int j=matrix[0].size() -1;j >=0 ;j--){
                if(matrix[i][j] == 0){
                    continue;
                }else{
                    if(i==0&&j== matrix[0].size()-1){
                        dis[1][i][j] = mm;
                    }else{
                        if(i==0){
                            dis[1][i][j] = dis[1][i][j+1] + 1;
                        }else if(j == matrix[0].size()-1){
                            dis[1][i][j] = dis[1][i-1][j] + 1;
                        }else{
                            dis[1][i][j] = min(dis[1][i-1][j], dis[1][i][j+1]) + 1;
                        }
                    }
                }
            }
        }

        for(int i=matrix.size()-1;i>=0;i--){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    continue;
                }else{
                    if(i == matrix.size()-1 && j == 0){
                        dis[2][i][j] = mm;
                    }else{
                        if( i == matrix.size()-1){
                            dis[2][i][j] = dis[2][i][j-1] + 1;
                        }else if( j == 0){
                            dis[2][i][j] = dis[2][i+1][j] + 1;
                        }else{
                            dis[2][i][j] = min(dis[2][i+1][j], dis[2][i][j-1])+ 1;
                        }
                    }
                }
            }
        }

        for(int i=matrix.size()-1;i>=0;i--){
            for(int j=matrix[0].size()-1;j>=0;j--){
                if(matrix[i][j] == 0){
                    continue;
                }else{
                    if( i == (matrix.size()-1) && j == (matrix[0].size()-1)){
                        dis[3][i][j] = mm;
                    }else{
                        if( i== matrix.size() -1 ){
                            dis[3][i][j] = dis[3][i][j+1] + 1;
                        }else if( j == matrix[0].size() -1 ){
                            dis[3][i][j] = dis[3][i+1][j] + 1;
                        }else{
                            dis[3][i][j] = min(dis[3][i+1][j], dis[3][i][j+1])+ 1;
                        }
                    }

                }
            }
        }

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == 1){
                    dis[0][i][j] = min(dis[0][i][j],min(dis[1][i][j],min(dis[2][i][j],dis[3][i][j])));
                }
                if(dis[0][i][j] > matrix.size()+matrix[0].size())
                    dis[0][i][j] = -1;
            }
        }
        return dis[0];
    }
};


