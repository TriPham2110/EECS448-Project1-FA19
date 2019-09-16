// -*- C++ -*-
/**
* @file   field.h
* @date   13 September 2019
* @brief  Container for the playing field.
*/

#ifndef FIELD_H
#define FIELD_H

#include <string>

#include <gtkmm/table.h>
#include <gtkmm/button.h>

class PlayingField : public Gtk::Table {

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
		Gtk::Button playing_field_button;
	private:
		void add_playfield_button();
};

#endif // FIELD_H_
