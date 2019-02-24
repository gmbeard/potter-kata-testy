#include "potter/potter.hpp"
#include "testy/testy.hpp"

using namespace potter;

McTest(should_total_one_book) {
    Basket b;
    b.add(book_a);
    Expect(b.total() == 8.0);
}

McTest(should_total_more_than_one_book) {
    Basket b;
    b.add(book_a);
    b.add(book_a);

    Expect(b.total() == 16.0);
}

McTest(should_apply_discount_on_two_from_set) {
    Basket b;
    b.add(book_a);
    b.add(book_b);

    Expect(b.total() == (16.0 - (16.0 * 0.05)));
}

McTest(should_apply_full_discount_on_set_of_all_books) {
    Basket b;
    b.add(book_a);
    b.add(book_b);
    b.add(book_c);
    b.add(book_d);
    b.add(book_e);

    Expect(b.total() == 30);
}

McTest(kata_test_case) {
    Basket b;
    b.add(book_a);
    b.add(book_a);

    b.add(book_b);
    b.add(book_b);

    b.add(book_c);
    b.add(book_c);

    b.add(book_d);
    b.add(book_e);

    Capture(b);

    Expect(b.size() == 8);
    Expect(b.total() == 51.20);
}
