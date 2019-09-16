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

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		FieldContainer();

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		virtual ~FieldContainer();

	protected:

	private:
		PlayingField* player_field;
		PlayingField* status_field;
};

#endif // FIELD_CONTAINER_H_
