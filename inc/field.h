// -*- C++ -*-
/**
* @file   field.h
* @date   13 September 2019
* @brief  Container for the playing field.
*/

#ifndef FIELD_H
#define FIELD_H

#include <string>

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <board.h>

class PlayingField : public Gtk::Box {

	public:

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		PlayingField(std::string label);

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		virtual ~PlayingField();

	protected:
		//Gtk::Button playing_field_button;
	private:
		void add_playfield_button();
		void add_board():
		Board* the_board;
};

#endif // FIELD_H_
