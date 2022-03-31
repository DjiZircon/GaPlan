#ifndef GAPLAN_TEST_TIPS_H
#define GAPLAN_TEST_TIPS_H

#include "public.h"
#include "params.h"

class Tips{
public:
    Tips(int row, int col, int gap_x, int gap_y):rows_(row), cols_(col), gap_x_(gap_x), gap_y_(gap_y){
        initTips();
    }
    Tip getByIdx(int idx){
        return tips_vec_[idx];
    }
private:
    bool initTips(){
        if(rows_<0 || cols_<0)
            return static_cast<bool>(ERROR);
        for(int r=0; r<rows_; r++){
            for(int c=0; c<cols_; c++){
                int cur_r = gap_y_*r;
                int cur_c = gap_x_*c;
                tips_vec_.push_back(Tip(cur_r, cur_c));
            }
        }
    }
    int rows_;
    int cols_;
    int gap_x_;
    int gap_y_;
    vector<Tip> tips_vec_; 
};

#endif
