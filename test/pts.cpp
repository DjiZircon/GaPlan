#include "pts.h"

bool Pts::init_pts(){
    if(pts_num_ < 0) return static_cast<bool>(ERROR);
    pts_vec_.clear();
    for(int i=0; i<pts_num_; i++){
        int cur_x = plate.x+rand()%plate.w;
        int cur_y = plate.y+rand()%plate.h;
        pts_vec_.push_back(Pt(cur_x, cur_y));
    }
}