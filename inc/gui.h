// -*- C++ -*-
/**
* @file   gui.h
* @date   14 September 2019
* @brief
*/

#ifndef GUI_H
#define GUI_H

#include <gtkmm/box.h>

// Forward Declaration of Submodules
class PlayingField;
class MainMenu;

class UserInterface : public Gtk::Box {

	public:

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		UserInterface();

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		~UserInterface();


	private:

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		void bootstrap_playing_field();

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		void bootstrap_main_menu();

		PlayingField* the_field;

		MainMenu* main_menu;

};

#endif // GUI_H_
