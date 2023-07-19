#include "Hex_chess.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(piece_test) {
  pecies p(pecies_type::PAWN);
  p.set_type(pecies_type::KNIGHT);
}
