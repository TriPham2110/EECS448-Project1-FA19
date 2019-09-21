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
class PlayingField;

class FieldContainer : public Gtk::Box {

	public:

		/**
		 * @brief Playing field container constructor.
		 */
		FieldContainer();

		/**
		 * @brief Returns FieldContainer singleton that can be used to change game state parameters.
		 */
		static FieldContainer* get_field_container_object();

		/**
		 * @brief Playing field container destructor.
		 */
		virtual ~FieldContainer();

		/**
		 * @brief
		 */
		PlayingField* get_moves_field();
		PlayingField* get_status_field();
		/**
		 * @brief Hide or show the field
		 */
		void set_field_visibility(PlayingField* field, int visibility);
		void hide_status_field();
		void hide_moves_field();
	protected:

		/**
		 * @brief Syntactic sugar that lets us add the player's 'picking moves'
		 *        field to the game screen without polluting the constructor with
		 *        calls.
		 */
		void add_the_moves_area();

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
		PlayingField* moves_field;
		Gtk::Separator vertical_separator;
		PlayingField* status_field;

};

#endif // FIELD_CONTAINER_H_
