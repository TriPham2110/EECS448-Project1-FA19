// -*- C++ -*-
/**
* @file   field.h
* @date   13 September 2019
* @brief  Container for the playing field.
*/

#ifndef FIELD_CONTAINER_H
#define FIELD_CONTAINER_H

#include <gtkmm/box.h>
#include <gtkmm/separator.h>

// Forward Declarations
class Board;

class FieldContainer : public Gtk::Box {

	public:

		/**
		 * @brief Playing field container constructor.
		 */
		FieldContainer();

		/**
		 * @brief Playing field container destructor.
		 */
		virtual ~FieldContainer();

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

#endif // FIELD_CONTAINER_H_
