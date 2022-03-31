#ifndef GAPLAN_TEST_PTS_H
#define GAPLAN_TEST_PTS_H

#include "public.h"
#include "params.h"

class Pts{
public:
    Pts(int pts_num):pts_num_(pts_num){init_pts();}
    bool init_pts();
    ~Pts(){
        pts_vec_.clear();
    }
    Pt getByIdx(int idx){
        if(idx < 0 || idx>=pts_num_)
            return Pt();
        return pts_vec_[idx];
    }
private:
    int pts_num_;
    vector<Pt> pts_vec_;
};

#endif

