/**
 * This file contains implementations for methods in the Process class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "process/process.h"
#include "page/page.h"
#include <vector>

using namespace std;


Process* Process::read_from_input(std::istream& in) {
    size_t bytes = 0;
    vector<Page*> pages; 
    while(!in.eof()){
        pages.push_back(Page::read_from_input(in));
        bytes += pages.back()->size();
    }
    return new Process(bytes, pages);
}


size_t Process::size() const
{
    return this->num_bytes;
}


bool Process::is_valid_page(size_t index) const
{
    if(index < pages.size())
        return true;
    return false;
}


size_t Process::get_rss() const
{
    int count = 0;
    for (int i =0; i<pages.size(); i++){
        if (page_table.rows[i].present)
            count++;
    }
    return count;
}


double Process::get_fault_percent() const
{
    // TODO
    if (memory_accesses == 0)
        return 0.0;
    return 100.0 * page_faults / memory_accesses;
}
