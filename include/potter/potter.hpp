#ifndef POTTER_KATA_POTTER_HPP_INCLUDED
#define POTTER_KATA_POTTER_HPP_INCLUDED

#include <string>
#include <vector>
#include <set>
#include <ostream>

namespace potter {

struct PotterBook {
    std::string name;
};

auto operator<(PotterBook const& lhs,
               PotterBook const& rhs) noexcept -> bool;

PotterBook const book_a = PotterBook { "Book A" };
PotterBook const book_b = PotterBook { "Book B" };
PotterBook const book_c = PotterBook { "Book C" };
PotterBook const book_d = PotterBook { "Book D" };
PotterBook const book_e = PotterBook { "Book E" };

struct Basket {
    auto add(PotterBook const& item) -> void;
    auto size() const noexcept -> size_t;
    auto total() const noexcept -> double;
    friend auto operator<<(std::ostream& os, 
                           Basket const& b) -> std::ostream&;
private:
    static constexpr double const kBookPrice = 8.0;
    std::vector<std::set<PotterBook>> items_;
};

}

#endif // POTTER_KATA_POTTER_HPP_INCLUDED
