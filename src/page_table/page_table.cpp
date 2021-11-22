/**
 * This file contains implementations for methods in the PageTable class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "page_table/page_table.h"

using namespace std;


size_t PageTable::get_present_page_count() const {
    int tot_count = 0;
    for (int i = 0; i<rows.size(); i++) {
        if(rows.at(i).present)
            tot_count++;
    }
    return tot_count;
}


size_t PageTable::get_oldest_page() const {
    int ind = -1;
    bool hit = false;
    
    for(int i = 0; i< rows.size(); i++){
        if(rows.at(i).present){
            if (!hit){
                hit = true;
                ind = i;
            }
            else if (rows.at(i).loaded_at < rows.at(ind).loaded_at)
                ind = i;
        }
    }
    return ind;
}


size_t PageTable::get_least_recently_used_page() const {
    int ind = -1;
    bool hit = false;
    
    for(int i = 0; i< rows.size(); i++){
        if(rows.at(i).present){
            if (!hit){
                hit = true;
                ind = i;
            }
            else if (rows.at(i).last_accessed_at < rows.at(ind).last_accessed_at)
                ind = i;
        }
    }
    return ind;
}
