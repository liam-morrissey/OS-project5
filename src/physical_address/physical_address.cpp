/**
 * This file contains implementations for methods in the PhysicalAddress class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "physical_address/physical_address.h"

using namespace std;

string PhysicalAddress::to_string() const {
    std::bitset<ADDRESS_BITS> x((frame << OFFSET_BITS) | offset);
    return x.to_string();
}


ostream& operator <<(ostream& out, const PhysicalAddress& address) {

    out
      << address.to_string()
      << " [frame: " << address.frame
      << "; offset: " << address.offset
      << "]";
    return out;
}
