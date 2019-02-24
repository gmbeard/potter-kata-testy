#include "potter/potter.hpp"
#include <algorithm>

using namespace potter;

namespace {

double calc_set_price(std::set<PotterBook> const& set, 
                      double unit_price) noexcept 
{
    double set_price = set.size() * unit_price;
    switch (set.size()) {
        case 2:
            set_price -= (set_price * 0.05);
            break;
        case 3:
            set_price -= (set_price * 0.1);
            break;
        case 4:
            set_price -= (set_price * 0.2);
            break;
        case 5:
            set_price -= (set_price * 0.25);
            break;
    }

    return set_price;
}

template<typename I>
I find_set_with_fewest(I first, I last, PotterBook const& item) noexcept {
    I applicable = last;
    for (I curr = first; curr != last; ++curr) {
        if (curr->find(item) == curr->end() && 
            (applicable == last || curr->size() < applicable->size()))
        {
            applicable = curr;
        }
    }

    return applicable;
}

} // End anonymous

auto potter::operator<(PotterBook const& lhs,
                       PotterBook const& rhs) noexcept -> bool
{
    return lhs.name < rhs.name;
}

auto Basket::add(PotterBook const& item) -> void {

    auto selection = find_set_with_fewest(items_.begin(),
                                          items_.end(),
                                          item);
    if (selection != items_.end()) {
        selection->insert(item);
    }
    else {
        items_.push_back( { item } );
    }
}

auto Basket::size() const noexcept -> size_t {
    size_t n = 0;
    std::for_each(items_.begin(), items_.end(), [&](auto const& s) {
        n += s.size();
    });
    return n;
}

auto Basket::total() const noexcept -> double {
    double t = 0;
    for (auto const& s : items_) {
        t += calc_set_price(s, kBookPrice);
    }

    return t;
}

auto potter::operator<<(std::ostream& os, 
                        Basket const& b) -> std::ostream&
{
    for (auto const& s : b.items_) {
        os << "Set:\n";
        for (auto const& item : s) {
            os << "\t" << item.name << "\n";
        }
    }
    return os;
}
