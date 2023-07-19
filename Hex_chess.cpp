/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hex_chess.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <Quincy_Mattor@student.uml.edu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:52:39 by qmattor           #+#    #+#             */
/*   Updated: 2023/07/19 00:28:32 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hex_chess.hpp"

pecies::pecies() : piece_type(pecies_type::PAWN), x(0), y(0) {}

pecies::pecies(pecies_type t) : piece_type(t), x(0), y(0) {}

pecies::pecies(uint8_t x, uint8_t y)
    : piece_type(pecies_type::PAWN), x(x), y(y) {}

pecies::pecies(uint8_t x, uint8_t y, pecies_type t)
    : piece_type(t), x(x), y(y) {}

Hex_chess::Hex_chess() {}

uint8_t Hex_chess::dist_from_center(uint8_t x, uint8_t y) {
  return abs(x) + abs(y);
}

bool Hex_chess::move_piece(uint8_t old_x, uint8_t old_y, uint8_t new_x,
                           uint8_t new_y) {
  if (dist_from_center(new_x, new_y) > 5)
    return false;
  for (auto p : this->white) {
    if (p.get_x() == old_x && p.get_y() == old_y) {
      p.set_x(new_x);
      p.set_y(new_y);
      // check for old peices to be removed
      return true;
    }
  }
  for (auto p : this->black) {
    if (p.get_x() == old_x && p.get_y() == old_y) {
      p.set_x(new_x);
      p.set_y(new_y);
      // check for old peices to be removed
      return true;
    }
  }
  return false;
}

// sf functions
void Hex_chess::draw(sf::RenderTarget &target, sf::RenderStates states) const {}

void pecies::draw(sf::RenderTarget &target, sf::RenderStates states) const {}

void board::draw(sf::RenderTarget &target, sf::RenderStates states) const {}
