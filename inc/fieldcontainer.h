// -*- C++ -*-
/**
* @file   field.h
* @date   13 September 2019
* @brief  Container for the playing field.
*/

#ifndef FIELD_CONTAINER_H
#define FIELD_CONTAINER_H

#include <gtkmm/box.h>

// Forward Declarations
class PlayingField;

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
		 * @brief Syntactic sugar that lets us add the player's status field
		 *        field to the game screen without polluting the constructor with
		 *        calls.
		 */
		void add_the_status_area();

	private:

		PlayingField* player_field;
		PlayingField* status_field;
};

#endif // FIELD_CONTAINER_H_
