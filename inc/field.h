// -*- C++ -*-
/**
* @file   field.h
* @date   13 September 2019
* @brief  Container for the boards the user monitors/interacts with.
*/

#ifndef FIELD_H
#define FIELD_H

#include <string>

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <board.h>

class PlayingField : public Gtk::Box {

	public:

		/**
		 * @brief Playboard constructor.
		 */
		PlayingField();

		/**
		 * @brief Playboard destructor.
		 */
		virtual ~PlayingField();

	protected:
<<<<<<< HEAD
		//Gtk::Button playing_field_button;
=======
		Gtk::Button playing_field_button;

>>>>>>> 7c04f6d39f876ed6c44ce844715a53d79c591d99
	private:

		/**
		 * @brief Syntactic sugar that allows us to add buttons to the field
		 *        without polluting the constructor.
		 */
		void add_playfield_button();
		void add_board():
		Board* the_board;
};

#endif // FIELD_H_
