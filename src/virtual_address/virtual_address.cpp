/**
 * This file contains implementations for methods in the VirtualAddress class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "virtual_address/virtual_address.h"
#include <iostream>

using namespace std;

VirtualAddress VirtualAddress::from_string(int process_id, string address) {
    // TODO: implement me
    size_t full_address;
    size_t page;
    size_t offset;

    full_address = stoi(address,nullptr,2);
    offset = full_address & OFFSET_BITMASK;
    page = (full_address & PAGE_BITMASK) >>OFFSET_BITS;
    return VirtualAddress(process_id, page, offset);
}


string VirtualAddress::to_string() const {
    std::bitset<16> b_page(page);
    std::bitset<16> b_offset(offset);
    b_page = b_page<<OFFSET_BITS;
    std::bitset<16> full_address = b_page | b_offset;
    return full_address.to_string();
}


ostream& operator <<(ostream& out, const VirtualAddress& address) {
    out<<"PID "<<address.process_id
    <<" @ "<<address.to_string()
    <<" [page: "<<address.page
    <<"; offset: "<<address.offset
    << "]";
    return out;
}
