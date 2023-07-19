/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hex_chess.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <Quincy_Mattor@student.uml.edu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:39:10 by qmattor           #+#    #+#             */
/*   Updated: 2023/07/19 00:09:54 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SFML/Graphics/Drawable.hpp>
#include <iostream>
#include <vector>

#ifndef __HEX_CHESS__
#define __HEX_CHESS__

enum pecies_type { PAWN = 0, KING, QUEEN, ROOK, KNIGHT, BISHUP };

class pecies : sf::Drawable {
private:
  pecies_type piece_type = pecies_type::PAWN;
  // https://www.redblobgames.com/grids/hexagons/
  // using the axial coords system
  uint8_t x;
  uint8_t y;

public:
  pecies();
  pecies(pecies_type);
  pecies(uint8_t, uint8_t);
  pecies(uint8_t, uint8_t, pecies_type);

  inline pecies_type get_type() { return piece_type; }
  inline void set_type(pecies_type p) {
    piece_type = piece_type == pecies_type::PAWN ? p : piece_type;
  }

  inline void set_x(uint8_t x) { this->x = x; }
  inline uint8_t get_x() { return x; }
  inline void set_y(uint8_t y) { this->y = y; }
  inline uint8_t get_y() { return y; }

  void draw(sf::RenderTarget &target, sf::RenderStates states);
};

class Hex_chess : sf::Drawable {
private:
  std::vector<pecies> white;
  std::vector<pecies> black;
  static uint8_t dist_from_center(uint8_t, uint8_t);

public:
  Hex_chess();
  bool move_piece(uint8_t, uint8_t, uint8_t, uint8_t);
  void draw(sf::RenderTarget &target, sf::RenderStates states);
};

#endif // __HEX_CHESS__
