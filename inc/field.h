// -*- C++ -*-
/**
* @file   field.h
* @date   13 September 2019
* @brief  Container for the boards the user monitors/interacts with.
*/

#ifndef FIELD_H
#define FIELD_H

#include <string>

#include <gtkmm/table.h>
#include <gtkmm/button.h>

class PlayingField : public Gtk::Table {

	public:

		/**
		 * @brief Playboard constructor.
		 */
		PlayingField(std::string label);

		/**
		 * @brief Playboard destructor.
		 */
		virtual ~PlayingField();

	protected:
		Gtk::Button playing_field_button;

	private:

		/**
		 * @brief Syntactic sugar that allows us to add buttons to the field
		 *        without polluting the constructor.
		 */
		void add_playfield_button();
};

#endif // FIELD_H_
