// -*- C++ -*-
/**
* @file   player.h
* @date   13 September 2019
* @brief  Container for the playing field.
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <gtkmm/box.h>
#include <gtkmm/separator.h>

// Forward Declarations
class Board;

class Player : public Gtk::Box {

	public:

		/**
		 * @brief Playing field container constructor.
		 */
		Player();

		/**
		 * @brief Playing field container destructor.
		 */
		virtual ~Player();

	protected:

		/**
		 * @brief Syntactic sugar that lets us add the player's 'picking moves'
		 *        field to the game screen without polluting the constructor with
		 *        calls.
		 */
		void add_the_players_area();

		/**
		 * @brief Syntactic sugar that lets us add a vertical bar to separate the
		 *        fields to the game screen without polluting the constructor with
		 *        calls.
		 */
		void add_the_vertical_separator();

		/**
		 * @brief Syntactic sugar that lets us add the player's status field
		 *        field to the game screen without polluting the constructor with
		 *        calls.
		 */
		void add_the_status_area();

	private:

		Board* player_field;
		Gtk::Separator vertical_separator;
		Board* status_field;

};

#endif // PLAYER_H_
